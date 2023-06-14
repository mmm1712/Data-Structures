// Name:  Marina  Zhdanova
// Student ID : #1718807
// Assignment number : Assignemnt #4
// Submission date : 05/11/2023
// Implementations of templated doubly LinkedLists, Stacks and Queue

#include "LinkedList.hpp"
#ifndef STACKLIST_HPP
#define STACKLIST_HPP


template <class NodeType>
class StackList{
public:
    StackList() : n(0) {}

    void push(NodeType data) { // add an element to the top of the stack
        list.insert_front(data);
        n++;
    }

    void pop() { //remove the top element from the stack
        if (!empty()) {
            list.remove_front();
            n--;
        }
    }

    NodeType top() { //return the value of the top element in the stack
        if (empty()) {
            throw std::runtime_error("Stack is empty");
        }
        return list.head->data;
    }

    bool empty() { // check if the stack is empty
        return n == 0;
    }

    int size() { //return the number of elements in the stack
        return n;
    }

private:
    LinkedList<NodeType> list;
    int n; // stack counter
};


#endif // STACKLIST_HPP
