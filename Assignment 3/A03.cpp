#include <iostream>  //io streams
#include<fstream>    //file streams
#include<iomanip>    //setprecision
#include <iterator>  //isstream::iterator
#include <string>    //std::string
#include <vector>    //std::vector
#include <numeric>   //std:: accumulate
#include <algorithm> //std::sort
#include <ctime>     //std::time
#include <random>    //srand(),rand()
#include <chrono>    //high_resolution clock
#include<utility>    //std::pair

#include "IntArray.h"

#define SAMPLE_SIZE 10 //size of array used to test remove


int main() {

    std::srand(std::time(nullptr)); // use current time as seed for random generator
    int random_variable = std::rand();

    IntArray arr;
    //test insert
    for (int i = 0; i < SAMPLE_SIZE; i++)
        arr.insert(std::rand() % 500 + 1);

    for (auto i : arr)
        std::cout << i << " ";

    //test remove front
    int rand_num = arr[0];
    std::cout << "\n\nremove front =" << rand_num << std::endl;
    arr.remove(rand_num);

    for (auto i : arr)
        std::cout << i << " ";

    //test remove back
    rand_num = arr[arr.size() - 1];
    std::cout << "\n\nremove back=" << rand_num <<
              std::endl; arr.remove(rand_num);

    for (auto i : arr)
        std::cout << i << " ";

    //test remove middle
    rand_num = arr[arr.size() / 2];
    std::cout << "\n\nremove middle=" << rand_num << std::endl;

    arr.remove(rand_num);
    for (auto i : arr)
        std::cout << i << " ";

    //test reverse
    std::cout << "\n\nrecursive reverse()" << std::endl;
    arr.reverse();
    for (auto i : arr)
        std::cout << i << " ";

    std::cout << std::endl;

    //Example sorting algorithm timing
    IntArray unsorted(false);

    //time bubble sort
    for (int i = 0; i < SAMPLE_SIZE * 1000; i++)
        unsorted.insert(std::rand() % 500 + 1);

    auto start = std::chrono::high_resolution_clock::now();
    unsorted.sort();
    auto stop = std::chrono::high_resolution_clock::now();

    std::cout << "An n^2 sorting algorithm took "
              << std::fixed << std::setprecision(2)
              << std::chrono::duration_cast<std::chrono::microseconds>
                         (stop - start).count() / 1000. << " milliseconds.\n";

    //time quicksort STL
    unsorted.clear();
    for (int i = 0; i < SAMPLE_SIZE * 1000; i++)
        unsorted.insert(std::rand() % 500 + 1);

    start = std::chrono::high_resolution_clock::now();
    std::sort(unsorted.begin(), unsorted.end());
    stop = std::chrono::high_resolution_clock::now();

    std::cout << "\nSTL's n log n sorting algorithm took "
              << std::fixed << std::setprecision(2)
              << std::chrono::duration_cast<std::chrono::microseconds>
                         (stop - start).count() / 1000. << " milliseconds.\n";

    std::cout << "\n*****Tests completed, enter any key to exit*******\n";
    char pause; std::cin >> pause;
    return 0;
}