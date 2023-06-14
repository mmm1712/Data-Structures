#pragma once
#ifndef INT_ARRAY_H
#define INT_ARRAY_H
//
// Name:         Marina Zhdanova & 1718807
// Assignment #: 3  Submission Date: 4/20/23
//


//
// A3 Interface to Implement, can reuse code from A1 & A2
//

class IntArray {
public:
    //constructors and destructors
    IntArray(bool sorted = true);            //overloaded
    IntArray(int item, bool sorted = true);//overloaded
    IntArray(const IntArray& arr);        //copy
    ~IntArray();                           //destructor

    //Member functions

    //delete all elements, set _memsize to 0
    void clear();

    // insert an item
    void insert(int item);// removed -> bool sorted = true);

    //recursive array reverse
    void reverse();

    //implement a n^2 sorting algorithm     //Ch 3.1 Goodrich
    //optional: allow descending sort
    void sort(bool asc = true);//ascending by default

    // Binary search: either recursive or iterative
    // input: requires a sorted array
    int binary_search(int key);            //page 395 Goodrich

    // iterative linear search
    // input: sorted or unsorted array
    int search(int key);

    //delete an item, create a new array _memsize-1
    //if sorted use binary search, otherwise use linear search
    void remove(int item);

    //A1 & A2 member functions
    int size();
    int* begin(); int* end();
    int& front(); int& back();
    int* data();
    const int* data() const;

    int& at(int position);

    int& operator[](int position);
    const int& operator[](int position) const;//new A3

    //copy assignment
    IntArray& operator=(const IntArray& rhs);



private:
    bool _sorted;
    int _memsize;
    int _size;
    int* _data;

    int binary_search(int key, int left, int right) const;
    void reverse(int l, int r);
    void insertion_sort(bool asc); // ??
    int binary_search_place(int key, int left, int right) const;
    void selection_sort(bool asc);
};

#endif // INTARRAY_H