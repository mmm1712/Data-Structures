#ifndef VECTORCOMPLETEBINARYTREE_HPP
#define VECTORCOMPLETEBINARYTREE_HPP

#include <vector>
#include <stdexcept>

template <typename E>
class VectorCompleteTree {
public:
    typedef typename std::vector<E>::iterator Position; // Iterator type for positions in the tree

protected:
    std::vector<E> V; // Underlying vector to store tree elements

public:
    VectorCompleteTree() : V(1) {} // Constructor initializes vector with a single element

    int size() const {
        return V.size() - 1; // Return the number of elements in the tree (size of vector minus 1)
    }

    Position left(const Position& p) {
        return V.begin() + 2 * (p - V.begin()); // Calculate and return the position of the left child of p
    }

    Position right(const Position& p) {
        return V.begin() + 2 * (p - V.begin()) + 1; // Calculate and return the position of the right child of p
    }

    Position parent(const Position& p) {
        return V.begin() + (p - V.begin()) / 2; // Calculate and return the position of the parent of p
    }

    bool hasLeft(const Position& p) const {
        return 2 * (p - V.begin()) <= size(); // Check if p has a left child by comparing its position with the tree size
    }

    bool hasRight(const Position& p) const {
        return 2 * (p - V.begin()) + 1 <= size(); // Check if p has a right child by comparing its position with the tree size
    }

    bool isRoot(const Position& p) const {
        return p == V.begin(); // Check if p is the root position by comparing it with the beginning position of the vector
    }

    Position root() {
        return V.begin(); // Return the position of the root element
    }

    Position last() {
        return V.begin() + size(); // Return the position of the last element in the tree
    }

    void addLast(const E& e) {
        V.push_back(e); // Add element e to the end of the vector
    }

    void removeLast() {
        V.pop_back(); // Remove the last element from the vector
    }

    void swap(const Position& p, const Position& q) {
        E e = *q; // Temporarily store the value at position q
        *q = *p; // Replace the value at position q with the value at position p
        *p = e; // Replace the value at position p with the stored value from position q
    }
};

#endif // VECTORCOMPLETEBINARYTREE_HPP
