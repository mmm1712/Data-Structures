#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>

// Forward declaration of PriorityQueue
template <class NodeType>
class PriorityQueue;

template <class NodeType>
struct Node {
    NodeType data;
    Node<NodeType>* next = nullptr; // pointer to the next node in the list
    Node<NodeType>* prev = nullptr; // pointer to the previous node in the list

    Node(const NodeType& d, Node<NodeType>* n = nullptr, Node<NodeType>* p = nullptr)
            : data(d), next(n), prev(p) {}
};

template <class NodeType>
class LinkedList {
private:
    Node<NodeType>* head = nullptr;
    // pointer to the first node in the list
    Node<NodeType>* tail = nullptr; // optional tail , useful for back operations
    int n;
public:
    // friend declaration for PriorityQueue
    friend class PriorityQueue<NodeType>;

    LinkedList()
            : head(nullptr), tail(nullptr), n(0) {}

    LinkedList(const LinkedList<NodeType>& that)
            : head(nullptr), tail(nullptr), n(0) {
        Node<NodeType>* ptr = that.head;
        while (ptr != nullptr) {
            insert_back(ptr->data);
            ptr = ptr->next;
        }
    }

    LinkedList<NodeType>& operator=(const LinkedList<NodeType>& that) {
        if (this != &that) {
            clear();
            Node<NodeType>* p = that.head;
            while (p != nullptr) {
                insert_back(p->data);
                p = p->next;
            }
        }
        return *this;
    }

    virtual ~LinkedList() {
        clear();
    }

    bool empty() const {
        return head == nullptr;
    }
    
    int size(){return n;}

    void insert_front(const NodeType& item) {
        Node<NodeType>* p = new Node<NodeType>(item, head, nullptr);
        if (head != nullptr) {
            head->prev = p;
        } else {
            tail = p;
        }
        head = p;
        n++;
    }

    NodeType remove_front() {
        if (empty()) {
            throw std::runtime_error("remove_front() called on empty list");
        }
        Node<NodeType>* p = head;
        NodeType data = p->data;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete p;
        n--;
        return data;
    }

    void insert_back(const NodeType& item) {
        Node<NodeType>* p = new Node<NodeType>(item, nullptr, tail);
        if (tail != nullptr) {
            tail->next = p;
        } else {
            head = p;
        }
        tail = p;
        n++;
    }

    NodeType remove_back() {
        if (empty()) {
            throw std::runtime_error("remove_back() called on empty list");
        }
        Node<NodeType>* p = tail;
        NodeType data = p->data;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete p;
        n--;
        return data;
    }

    void clear() {
        while (head != nullptr) {
            Node<NodeType>* p = head;
            head = p->next;
            delete p;
        }
        tail = nullptr;
        n = 0;
    }
};

#endif // LINKEDLIST_HPP
