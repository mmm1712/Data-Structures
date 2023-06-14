#include <iostream>
#include <queue>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <functional>
#include "PriorityQueue.hpp"
#include "HeapPriorityQueue.hpp"
#include "BinarySearchTree.hpp"

template <typename T>
struct Compare {
    bool operator()(const T& a, const T& b) const {
        return a < b;
    }
};

int main() {
    int SAMPLES = 1000;
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed the random number generator
    std::vector<int> sorted; // Create an empty vector to store sorted elements
    PriorityQueue<int> pq;
    auto start = std::chrono::high_resolution_clock::now();

    // Insert random numbers into the PriorityQueue
    for (int i = 0; i < SAMPLES; i++) {
        pq.insert(std::rand() % 1000 + 1);
    }

    // Sort the elements in the PriorityQueue and store them in the sorted vector
    while (!pq.is_empty()) {
        sorted.push_back(pq.min());
        pq.remove_min();
    }
    auto stop = std::chrono::high_resolution_clock::now();
    std::cout << "Unsorted linked list priority queue sequence sorting took: "
              << std::fixed << std::setprecision(2)
              << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() / 1000. << " milliseconds.\n";

    std::priority_queue<int, std::deque<int> > stl_priority_queue;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    sorted.clear();
    start = std::chrono::high_resolution_clock::now();

    // Insert random numbers into the STL priority queue
    for (int i = 0; i < SAMPLES; i++) {
        stl_priority_queue.push(std::rand() % 1000 + 1);
    }

    // Sort the elements in the STL priority queue and store them in the sorted vector
    while (!stl_priority_queue.empty()) {
        sorted.push_back(stl_priority_queue.top());
        stl_priority_queue.pop();
    }
    stop = std::chrono::high_resolution_clock::now();
    std::cout << "STL priority queue time: "
              << std::fixed << std::setprecision(2)
              << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() / 1000. << " milliseconds.\n";

    HeapPriorityQueue<int, Compare<int> > heap_priority_queue;

    sorted.clear();
    start = std::chrono::high_resolution_clock::now();

    // Insert random numbers into the heap priority queue
    for (int i = 0; i < SAMPLES; i++) {
        heap_priority_queue.insert(std::rand() % 1000 + 1);
    }

    // Sort the elements in the heap priority queue and store them in the sorted vector
    while (!heap_priority_queue.empty()) {//O(N)
        sorted.push_back(heap_priority_queue.min());// O(log N)
        heap_priority_queue.removeMin();// O(log N)
    }
    //O(N log N)

    stop = std::chrono::high_resolution_clock::now();
    std::cout << "Heap priority queue sequence sorting took: "
              << std::fixed << std::setprecision(2)
              << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() / 1000. << " milliseconds.\n";

    std::vector<int> stl_heap;
    for (int i = 0; i < SAMPLES; i++)
        stl_heap.push_back(std::rand() % 1000 + 1);
    std::make_heap(stl_heap.begin(), stl_heap.end());
    sorted.clear();
    start = std::chrono::high_resolution_clock::now();
    // created sorted vector
    while (!stl_heap.empty()) {
        sorted.push_back(stl_heap.front());
        std::pop_heap(stl_heap.begin(), stl_heap.end());
        stl_heap.pop_back();
    }
    stop = std::chrono::high_resolution_clock::now();
    std::cout << "std::make_heap from vector sorting took: "
              << std::fixed << std::setprecision(2)
              << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() / 1000. << " milliseconds.\n";

    int n = 100;
    std::pair<double, double> times;
    std::vector<std::pair<double, double> > trials;
    BinarySearchTree<int, std::string> bst;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        bst.insert(std::rand() % n + 1, "random tree structure");
    }
    stop = std::chrono::high_resolution_clock::now();
    times.first = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

    BinarySearchTree<int, std::string> bst_inserted_bad;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        bst_inserted_bad.insert(i, "linear tree structure");
    }
    stop = std::chrono::high_resolution_clock::now();
    times.second = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

    trials.push_back(times);

    // Output the results
    // Print the insertion times for different tree structures
    std::cout << "Insertion time for a random tree structure in the Binary Search Tree: " << trials.back().first / 1000. << " milliseconds.\n";
    std::cout << "Insertion time for a linear tree structure in the Binary Search Tree: " << trials.back().second / 1000. << " milliseconds.\n";

    // Retrieve and display the minimum and maximum keys in the Binary Search Tree
    std::cout << "Minimum key in the Binary Search Tree: " << bst.min_key() << std::endl;
    std::cout << "Maximum key in the Binary Search Tree: " << bst.max_key() << std::endl;

    // Search for a specific key in the Binary Search Tree
    int keyToSearch = 15;
    bool found = bst.search(keyToSearch);
    std::cout << "Key " << keyToSearch << " found in the Binary Search Tree: " << (found ? "Yes" : "No") << std::endl;

    // Perform in-order traversal of the Binary Search Tree
    std::cout << "In-order traversal of the Binary Search Tree: ";
    bst.print_inorder();

    // Perform post-order traversal of the Binary Search Tree
    std::cout << "Post-order traversal of the Binary Search Tree: ";
    bst.print_postorder();

    // Perform pre-order traversal of the Binary Search Tree
    std::cout << "Pre-order traversal of the Binary Search Tree: ";
    bst.print_preorder();

    char end_of_tests;
    std::cin >> end_of_tests;

    return 0;
}


