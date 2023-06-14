// Name:  Marina  Zhdanova
// Student ID : #1718807
// Assignment number : Assignemnt #4
// Submission date : 05/11/2023
// Implementations of templated doubly LinkedLists, Stacks and Queue

#include "LinkedList.hpp"

#ifndef UNTITLED2_QUEUELIST_HPP
#define UNTITLED2_QUEUELIST_HPP

template <class NodeType>
class QueueList {
public:
    QueueList() : n(0) {}

    void enqueue(NodeType data) { //add an element to the back of the queue
        list.insert_back(data);
        n++;
    }

    void dequeue() { // remove the front element from the queue
        if (!empty()) {
            list.remove_front();
            n--;
        }
    }

    NodeType front() { //return the value of the front element in the queue
        if (empty()) {
            throw std::runtime_error("Queue is empty");
        }
        return list.head->data;
    }

    bool empty() { //check if the queue is empty
        return n == 0;
    }


private:
    LinkedList<NodeType> list;
    int n; // queue counter
};

#endif //UNTITLED2_QUEUELIST_HPP
