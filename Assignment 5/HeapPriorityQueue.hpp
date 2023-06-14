#ifndef HEAPPRIORITYQUEUE_HPP
#define HEAPPRIORITYQUEUE_HPP

#include "VectorCompleteBinaryTree.hpp"
#include <functional>

template <typename E, typename C>
class HeapPriorityQueue {
public:
    int size() const; // number of elements
    bool empty() const; // is the queue empty?
    void insert(const E& e); // insert element
    const E& min(); // minimum element
    void removeMin(); // remove minimum

private:
    VectorCompleteTree<E> T; // priority queue contents
    C isLess; // less-than comparator
    // shortcut for tree position
    typedef typename VectorCompleteTree<E>::Position Position;

    void swap(Position p, Position q) {
        E temp = *p;
        *p = *q;
        *q = temp;
    }
};

template <typename E, typename C> // number of elements
int HeapPriorityQueue<E,C>::size() const { return T.size(); }

template <typename E, typename C> // is the queue empty?
bool HeapPriorityQueue<E,C>::empty() const { return size() == 0; }

template <typename E, typename C> // minimum element
const E& HeapPriorityQueue<E,C>::min() {return *(T.root()); } // O(1) return reference to root element

template <typename E, typename C> // insert element
void HeapPriorityQueue<E,C>::insert(const E& e) {// O(log N)
/*
                3
           4         6
        6    7    7

[3],[4,6],[6,7],[7,..]

add 1
[3],[4,6],[6,7],[7,1]

                3
           4         6
        6    7    7      1

                3
           4         1
        6    7    7      6

                1
           4         3
        6    7    7      6

O(log N)

 */
    T.addLast(e); // add e to heap
    Position v = T.last(); // e’s position
    while (!T.isRoot(v)) { // up-heap bubbling
        Position u = T.parent(v);
        if (!isLess(*v, *u)) break; // if v in order, we’re done
        T.swap(v, u); // . . .else swap with parent
        v = u;
    }
}

template <typename E, typename C> // remove minimum
void HeapPriorityQueue<E,C>::removeMin() {
/*

O(log N)
 */
    if (size() == 1) // only one node?
    {T.removeLast();} // . . .remove it
    else {
        Position u = T.root(); // root position
        T.swap(u, T.last()); // swap last with root
        T.removeLast(); // . . .and remove last
        while (T.hasLeft(u)) { // down-heap bubbling
            Position v = T.left(u);
            if (T.hasRight(u) && isLess(*(T.right(u)), *v))
                v = T.right(u); // v is u’s smaller child
            if (isLess(*v, *u)) { // is u out of order?
                T.swap(u, v); // . . .then swap
                u = v;
            }else break; // else we’re done
        }
    }
}
#endif // HEAPPRIORITYQUEUE_HPP