// Name:  Marina  Zhdanova
// Student ID : #1718807
// Assignment number : Assignemnt #4
// Submission date : 05/11/2023
// Implementations of templated doubly LinkedLists, Stacks and Queue

#include <iostream>
#include "LinkedList.hpp"
#include "StackList.hpp"
#include "QueueList.hpp"

using namespace std;

template <class NodeType>
LinkedList<NodeType> list_union(const LinkedList<NodeType>& u, const LinkedList<NodeType>& v) {
    LinkedList<NodeType> result = u; // copy u
    Node<NodeType>* current = v.head;
    while (current != nullptr) {
        if (!result.find(current->data)) { // add only if not already in list
            result.insert_back(current->data);
        }
        current = current->next;
    }
    return result;
}

template <class NodeType>
LinkedList<NodeType> list_intersection(const LinkedList<NodeType>& u, const LinkedList<NodeType>& v) {
    LinkedList<NodeType> result;
    Node<NodeType>* current = u.head;
    while (current != nullptr) {
        if (v.find(current->data) && !result.find(current->data)) { // add only if in both lists and not already in the intersection list
            result.insert_back(current->data);
        }
        current = current->next;
    }
    return result;
}

#include <sstream>

using namespace std;

void postfix_calculator() {
    StackList<double> stack;
    string input;
    double operand, op1, op2, result;

    cout << "Enter a postfix expression : ";
    getline(cin, input);

    if (input.empty() || input.back() != '=') {
        cout << "Please ensure that the input expression ends with the '='"  << endl;
        return;
    }

    input.pop_back();

    istringstream iss(input);
    string token;
    while (iss >> token) {
        if (isdigit(token[0])) { // Token is a number
            operand = atof(token.c_str());
            stack.push(operand);
        } else { // Token is an operator
            try {
                if (stack.size() < 2) {
                    throw runtime_error("Insufficient operands.");
                }
                op2 = stack.top();
                stack.pop();
                op1 = stack.top();
                stack.pop();
                switch (token[0]) {
                    case '+':
                        result = op1 + op2;
                        break;
                    case '-':
                        result = op1 - op2;
                        break;
                    case '*':
                        result = op1 * op2;
                        break;
                    case '/':
                        result = op1 / op2;
                        break;
                    default:
                        throw runtime_error("Invalid operator: " + string(1, token[0]));
                }
                stack.push(result);
            } catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
                return;
            }
        }
    }

    if (!stack.empty()) {
        cout << "Result: " << stack.top() << endl;
    } else {
        cout << "No result to display" << endl;
    }
}




bool palindrome_checker(const string& str) {
    StackList<char> stack;
    QueueList<char> queue;

    // Push each character onto the stack and enqueue it
    for (char c : str) {
        stack.push(c);
        queue.enqueue(c);
    }

    // Pop from stack and dequeue from queue, comparing each character
    while (!stack.empty() && !queue.empty()) {
        char s = stack.top();
        stack.pop();
        char q = queue.front();
        queue.dequeue();

        if (s != q) {
            return false;
        }
    }

    // If both stack and queue are empty, the string is a palindrome
    return stack.empty() && queue.empty();
}

int main() {
    LinkedList<int> list1;
    list1.insert_back(1);
    list1.insert_back(2);
    list1.insert_back(3);
    list1.insert_back(4);

    LinkedList<int> list2;
    list2.insert_back(3);
    list2.insert_back(4);
    list2.insert_back(5);
    list2.insert_back(6);

    LinkedList<int> union_list = list_union(list1, list2);
    LinkedList<int> intersection_list = list_intersection(list1, list2);

    cout << "List 1: ";

    while (!list1.empty()) {
        cout << list1.remove_front() << " ";
    }    
    cout << endl;

    cout << "List 2: ";

    while (!list2.empty()) {
        cout << list2.remove_front() << " ";
    }
    cout << endl;

    cout << "Union: ";

    while (!union_list.empty()) {
        cout << union_list.remove_front() << " ";
    }        
    cout << endl;

    cout << "Intersection: ";

    while (!intersection_list.empty()) {
        cout << intersection_list.remove_front() << " ";
    }        
    cout << endl;

    postfix_calculator();

    string word;
    cout << "Check if palindrome : ";
    getline(cin, word);

    if (palindrome_checker(word)) {
        cout << " true" << endl;
    } else {
        cout << " false" << endl;
    }
    return 0;
}
