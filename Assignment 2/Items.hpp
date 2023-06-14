//
// Name : Marina Zhdanova
// SSID : 1718807
// Assignment #: 2
// Submission Date : 03/17/2023
//


# ifndef _ITEMS_HPP
# define _ITEMS_HPP
# include <iostream>
# include "BaseItems.hpp"
template < class T >
class Items : public BaseItems <T >{
public :
    Items <T >() : _number_of_items (0) , _items ( nullptr ) {} // default

    Items <T>( int n , std::initializer_list <T> il ) : _number_of_items(n), _items(new T[n]) {
        std::copy(il.begin(), il.end(), _items);
} // constructor with initializer list

    Items(const Items<T>& items) : _number_of_items(items._number_of_items), _items(new T[items._number_of_items]) {
        std::copy(items.begin(), items.end(), _items);
    } // copy constructor

    ~ Items <T>() {
    delete [] _items;
} // destructor


//
// TODO A2 : override all BaseItems virtual functions
//


    bool update_number_of_items(int n) override {
        if (n < 0) {
            return false;
        }

        T* ar_items = new T[n];
        if (_number_of_items > 0) { // if there are elements in array
            std::copy(_items, _items + std::min(n, _number_of_items), ar_items); //copy from previous to new
            delete[] _items; // old memory array is deleted
        }

        _items = ar_items; // assigned to a new array
        _number_of_items = n; // update n
        return true;
    }

    bool empty() override { // check the array is empty
        if (_number_of_items == 0) {
            return true;
        }
        return false;
    }

    int number_of_items() override { // returns the number of items
        return _number_of_items;
    }


    T* begin() override { // returns a pointer to the first element in the array
        return _items;// address
    }


    T* end() override { // returns a pointer to the last element in the array
        return _items + _number_of_items;
    }

    T& front() override {
        return _items[0]; // returns a reference to the first element
    }

    T& back() override {
        return _items[_number_of_items-1]; // returns a reference to the last element
    }

    T& at(int position) override { //  returns a reference to the element at the specified index
        if (position >= number_of_items()) {
            throw std::out_of_range("Error : out of range");
        }
        return _items[position];
    }


    T* items() override { //returns a pointer to the beginning of the array
        return _items;
    }

    T& operator[](int position) override { // overloaded index operator
        return _items[position];
    }
    const T* items() const override { //returns a pointer to the first element of the array
        return _items;
    }

private :
    int _number_of_items = 0;
    T * _items = nullptr ;
};

#endif
