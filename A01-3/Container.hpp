//
// Name: Marina Zhdanova
// SSID: 1718807
// Assignment #: 1
// Submission Date: 3/3/23
// Program description:
// the program implements an interface for a simple Abstract Data Type (ADT)
// called Container that acts like an array
//

#ifndef _CONTAINER_HPP
#define _CONTAINER_HPP
#include <iostream>
#include <string>
#include <cstdlib>

template <class T, int N>
class Container
{
public:
    using value_type = T;
    void add_item(T item); // output container full , if add_item cannot add
    T get_item(int index ); //throw a string if index out of bounds
    void remove_item(T item); // remove first occurrence of item
    bool empty (); // check if Container is empty
    void clear (); // clear all contents , assign value_type
    constexpr int size (); // return current number of elements in container
    T* begin ();
    T* end();
private:
    int _size = 0;
    T container[N];
};// Container interface

/* Sample Template member function definitions */
template <class T, int N>
constexpr int Container <T, N>:: size (){ return _size ;}

template <class T, int N>
void Container <T, N>:: clear (){
    for (int i = 0; i < _size; i++)
    container[i] = T(); //or value_type ();
    _size = 0;
}

template <class T, int N>
T* Container <T, N>:: begin (){ return _size ? &container [0] : nullptr ;}

template <class T, int N>
T* Container <T, N>::end(){ return begin () + _size ;}

//.....

template <class T, int N >
void Container <T, N>:: add_item (T item) {
    if(_size >= N ){
        throw (_size);
    }
    container[_size] = item;
    _size++;
}

template <class T, int N >
T Container <T,N>::get_item(int index) {
    if (index>=_size) {
        throw (index);
    }
    return container[index];
}

template <class T, int N >
void Container <T,N>::remove_item(T item) {
    for (int i=0; i< _size ; i++) {
        if (container[i]==item) {
            for ( int j = i; j < (_size-1); j++)
                container[j] = container[j+1];
            _size--;
            return;
            //break;
        }
    }
}

template <class T, int N >
bool Container <T,N> :: empty () {
    if (_size == 0) {
        return true;
    }
    else {
        return false;
    }
}
#endif