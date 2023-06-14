
// PriorityQueue.hpp
#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include "LinkedList.hpp"
#include <list>
#include <algorithm>

template <class NodeType>
class PriorityQueue {
public:
void insert(NodeType t); // Function to insert an element into the priority queue
    NodeType min(); // Function to retrieve the minimum element from the priority queue
    void remove_min(); // Function to remove the minimum element from the priority queue
    bool is_empty() { return q.empty(); } // Function to check if the priority queue is empty

private:
    LinkedList<NodeType> q;
    //std::list<NodeType> q; // Linked list used as the underlying data structure for the priority queue
};

template <class NodeType>
void PriorityQueue<NodeType>::insert(NodeType t) {// O(1)
    q.insert_back(t);
}


template <class NodeType>
NodeType PriorityQueue<NodeType>::min(){// O(N)
        int n = q.size();
        NodeType min_nd = q.remove_front();
        q.insert_back(min_nd);
        NodeType x;
        for(int i=0; i<n; ++i){
            x = q.remove_front();
            q.insert_back(x);
            if(x < min_nd){min_nd = x;}
        }
        return min_nd;
}

template <class NodeType>
void PriorityQueue<NodeType>::remove_min() {// O(N)

    NodeType min_nd = min();
    int n = q.size();
    NodeType x;
    for(int i=0; i<n; ++i){
        x = q.remove_front();
        if(x == min_nd){
            break;
        }
        q.insert_back(x);
    }

}


#endif // PRIORITYQUEUE_HPP
