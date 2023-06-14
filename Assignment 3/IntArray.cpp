#include "IntArray.h"
#include <algorithm>
#include <iostream>  //io streams


// constructors and destructor
IntArray::IntArray(bool sorted) : _sorted(sorted), _memsize(0), _size(0), _data(nullptr) {}

IntArray::IntArray(int item, bool sorted) : _sorted(sorted), _memsize(1), _size(0), _data(new int[1]) {
    insert(item);
}

IntArray::IntArray(const IntArray& arr) : _sorted(arr._sorted), _memsize(arr._memsize), _size(arr._size), _data(new int[arr._memsize]) {
    std::copy(arr._data, arr._data + arr._size, _data);
}

IntArray::~IntArray() {
    clear();
}

// Member functions

void IntArray::clear() {
    delete[] _data;
    _data = nullptr;
    _size = 0;
    _memsize = 0;
}

// // insert an item
void IntArray::insert(int item) {
    if (_size == _memsize) {
        int new_memsize = (_memsize == 0) ? 1 : _memsize * 2;
        int* new_data = new int[new_memsize];
        std::copy(_data, _data + _size, new_data);
        delete[] _data;
        _data = new_data;
        _memsize = new_memsize;
    }
    if (_sorted && _size>0) {
        int index = binary_search_place(item,0,_size-1);
        std::copy_backward(_data + index, _data + _size, _data + _size + 1);
        _data[index] = item;
    }else{
        _data[_size] = item;
    }
    _size++;
}

//recursive array reverse
void IntArray::reverse() {//recursive
    reverse(0, _size - 1);
}

void IntArray::reverse(int l, int r) {//reverse array using recursion
    if(l>=r) return;
    std::swap(_data[l], _data[r]);
    reverse(l + 1, r - 1);
}

//implement a n^2 sorting algorithm
void IntArray::sort(bool asc) {
    if (_size <= 1) {
        return;
    }


    insertion_sort(asc);
}



int& IntArray::operator[](int position) {
    return _data[position];
}
const int& IntArray::operator[](int position) const {
    return _data[position];
}

// iterative linear search
int IntArray::search(int key)  {
    for (int i = 0; i < _size; i++) {
        if (_data[i] == key) {
            return i;
        }
    }
    return -1;
}

//delete an item, create a new array _memsize-1
void IntArray::remove(int item) {
    if (_sorted) {
        int index = binary_search(item);
        if (index >= 0) {
            std::copy(_data + index + 1, _data + _size, _data + index);
            _size--;
        }
    } else {
        for (int i = 0; i < _size; i++) {
            if (_data[i] == item) {
                std::copy(_data + i + 1, _data + _size, _data + i);
                _size--;
                break;
            }
        }
    }
}

int IntArray::size()  {
    return _size;
}

int* IntArray::begin()  {
    return _data;
}

int* IntArray::end()  {
    return _data + _size;
}

int& IntArray::front() {
    return _data[0];
}

int& IntArray::back()  {
    return _data[_size - 1];
}

//sorting algorithm
void IntArray::insertion_sort(bool asc) {
    for (int i = 1; i < _size; i++) {
        int j = i;
        while (j > 0 && (_data[j - 1] > _data[j] == asc)) {
            std::swap(_data[j], _data[j - 1]);
            j--;
        }
    }
}


int IntArray::binary_search(int key) {
    return binary_search(key, 0, _size - 1);
}

// will return index if item is found (recursive technique )
int IntArray::binary_search(int key, int left, int right) const
{
    if (left > right) return -1;
    int mid = (left + right) / 2;
    if (_data[mid] == key) return mid;
    if (_data[mid] > key) return binary_search(key, left, mid - 1);
    return binary_search(key, mid + 1, right);
}

// will return index even if item is not found
int IntArray::binary_search_place(int key, int left, int right) const
{//  0 1 2 3 4 5 6
    //  1 3 5 6 7 8 9  ?=4
    if ( right<left) return left;
    int mid = (left + right) / 2; // find the mid element (находим средний элемент)
    if (_data[mid] == key) return mid; // return index if found (если найден, возвращаем индекс)
    //if mid > key, check the left part (ищем в левой половине массива)
    if (_data[mid] > key) return binary_search_place(key, left, mid - 1);
    // otherwise search in the right part
    return binary_search_place(key, mid+1, right);
}
