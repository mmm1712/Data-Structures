// Name:  Marina  Zhdanova
// Student ID : #1718807
// Assignment number : Assignemnt #4
// Submission date : 05/11/2023
// Implementations of templated doubly LinkedLists, Stacks and Queue


#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <set>

template <class NodeType>
struct Node {
    NodeType data; // data stored in Node
    Node<NodeType>* next = nullptr; // pointer to the next node in the list
    Node<NodeType>* prev = nullptr; // pointer to the previous node in the list
};

template <class NodeType>
class LinkedList { // friend declaration not shown
// or ise a getter : <NodeType>* Head();
public:

    template <class nodeType>
    friend LinkedList<nodeType> list_union(const LinkedList<nodeType> &u, const LinkedList<nodeType> &v);
    
    template <class nodeType>
    friend LinkedList<nodeType> list_intersection(const LinkedList<nodeType>& u, const LinkedList<nodeType>& v);
    
    template <class nodeType>
    friend class QueueList;
    
    template <class nodeType>
    friend class StackList;

    LinkedList()  { // construct an empty list
        // copy constructor and assignment
        head = nullptr;
        tail = nullptr;
        n = 0;} // default constructor to construct an empty list
    LinkedList < NodeType >( const LinkedList < NodeType >& that ) {// copy constructor
        head = nullptr;
        tail = nullptr;
        n = 0;

        Node<NodeType>* ptr = that.head; // create a pointer to the head of the other linked list
        while (ptr != nullptr) { // iterate through other linked list
            insert_back(ptr->data); // insert the current node's data into the back of this linked list
            ptr = ptr->next; // move pointer to next node in other linked list
        }
    }

    LinkedList<NodeType>& operator=(const LinkedList<NodeType>& that) { // copy assignment operator
        if (this != &that) { // Check if the object is not being assigned to itself
            clear();// Clear the current list
            Node<NodeType>* p = that.head;// Copy the elements from the list to be copied from
            while (p != nullptr) {
                insert_back(p->data);// Insert each element to the back of the current list
                p = p->next;
            }
        }
        return *this; // Return a reference to the updated list
    }



    virtual ~LinkedList() { // destructor to delete all nodes
        clear();
    }
    int size() { // function to return the number of nodes in the list
        return n;
    }
    bool empty() { // function to check if the list is empty
        return head == nullptr;
    }

    void insert_front(const NodeType& item) { // function to insert a node at the front of the list
        Node<NodeType>* p = new Node<NodeType>{item, head, nullptr}; // allocate new node with item and set its next to head
        if (head != nullptr) { // if list is not empty
            head->prev = p; // set the previous pointer of the current head to the new node
        } else { // if list is empty
            tail = p; // set tail to the new node
        }
        head = p; // set head to the new node
        n++; // increment the size of the list
    }

    NodeType remove_front() { // function to remove the first node from the list and return its data
        if (empty()) { // if the list is empty, throw an error
            throw std::runtime_error("remove_front() called on empty list");
        }
        Node<NodeType>* p = head; // create a pointer to the first node
        NodeType data = p->data; // store the data of the first node in a variable
        head = head->next; // set the head to point to the next node in the list
        delete p; // delete the node pointed to by p
        n--; // decrement the size of the list
        return data; // return the data of the deleted node
    }


    void insert_back(const NodeType& item) { // function to insert a node at the back of the list
        Node<NodeType>* p = new Node<NodeType>{item, nullptr, tail}; // allocate a new node and initialize its data to item and prev pointer to tail
        if (tail != nullptr) { // if the list is not empty
            tail->next = p; // set the next pointer of tail to p
        } else { // if the list is empty
            head = p; // set head to p
        }
        tail = p; // set tail to p
        n++; // increment the size of the list
    }

    NodeType remove_back() { // function to remove the last node from the list and return its data
        if (empty()) { // check if the list is empty
            throw std::runtime_error("remove_back() called on empty list"); // throw an exception if the list is empty
        }
        Node<NodeType>* p = tail; // create a pointer to the last node in the list
        NodeType data = p->data; // get the data from the last node
        tail = p->prev; // update the tail to point to the previous node in the list
        if (tail != nullptr) { // if the list is not empty
            tail->next = nullptr; // set the next pointer of the new last node to null
        } else {
            head = nullptr; // if the list is empty, set the head to null
        }
        delete p; // delete the last node
        n--; // decrement the number of nodes in the list
        return data; // return the data from the last node
    }

    void clear() { // function to remove all nodes from the list
        while (head != nullptr) {
            Node<NodeType>* p = head;
            head = p->next;
            delete p;
        }
        tail = nullptr;
        n = 0;
    }

    bool find(const NodeType& type) const { // searching a linked list
        for (Node<NodeType>* current = head; current != nullptr; current = current->next) {
            if (current->data == type) {
                return true;
            }
        }
        return false;
    }

private:
    Node<NodeType>* head = nullptr;
    // pointer to the first node in the list
    Node<NodeType>* tail = nullptr; // optional tail , useful for back operations
    int n;
};

#endif // LINKEDLIST_HPP
