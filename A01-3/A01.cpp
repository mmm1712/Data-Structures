#include <iostream>
#include <string>
#include "Container.hpp"
int main (){
    std::cout << "\n******************* Test 1*******************\n";
    std::cout << "Testing Container <std::string ,5>\n";
    Container <std::string ,5> container_of_strings;
    std::cout << "Testing Container <std::string ,5>:: add_items () {Green , Red , Black}\n";
    try{
        container_of_strings.add_item("Green");
    }
    catch(int element) {
        std::cout << "can not add item\n";
    }
    try{
        container_of_strings.add_item("Red");
    }
    catch(int element) {
        std::cout << "can not add item\n";
    }
    try{
        container_of_strings.add_item("Black");
    }
    catch(int element) {
        std::cout << "can not add item\n";
    }

    try{
        container_of_strings.add_item("Black2");
    }
    catch(int element) {
        std::cout << "can not add item\n";
    }

    try{
        container_of_strings.add_item("Black3");
    }
    catch(int element) {
        std::cout << "can not add item\n";
    }
    try{
        container_of_strings.add_item("Black4");
    }
    catch(int element) {
        std::cout << "can not add item\n";
    }

/*
    try{
        do_smth(x);
    }
    catch(int element) {
        std::cout << "can not add item\n";
    }
  */

    std::cout << "Testing Container <std::string ,5>::range -based -for -loop ()\n";
    for (auto& str : container_of_strings)
        std::cout << str << " ";
    std::cout << "\nTesting Container <std::string ,5>:: remove_item(Red)\n";
    container_of_strings.remove_item("Red");

    std::cout << "\nTesting Container <int ,10>:: get_item (16)\n";
    std::cout << "item(1) = " << container_of_strings.get_item(1) << "\n";

    std::string ss;
    try{
        ss=container_of_strings.get_item(16);
    }
    catch(int element) {
        std::cout << "element is out of bounds\n";
    }
    std::cout << "item(16) = " << ss << "\n";

///////////////////////////////
    //std::cout << "\nTesting Container <int ,10>:: get_item (16)\n";
    //container_of_strings.get_item(0);

    std::cout << "Testing Container <std::string ,5>::range -based -for -loop ()\n";
    for (auto& str : container_of_strings)
        std::cout << str << " ";
    std::cout << "\nTesting Container <std::string ,5>:: size ()\n";
    std::cout << "container_of_strings.size ()=" << container_of_strings.size() << "\n";

    std::cout << "\n******************* Test 2*******************\n";
    std::cout << "Testing Container <int ,10>:: add_item (){0 ,2 ,4 ,... ,64 ,81}\n";
    Container <int ,10> container_of_ints;
    for (int i = 0; i < 10; i++)
        container_of_ints.add_item(i * i);
    std::cout << "Testing Container <int ,10>::range -based -for -loop\n";
    for (auto num : container_of_ints)
        std::cout << num << " ";
    std::cout << "\nTesting Container <int ,10>:: remove_item (16)\n";
    container_of_ints.remove_item (16);

    std::cout << "\nTesting Container <int ,10>:: get_item (16)\n";
    container_of_ints.get_item(2);

    std::cout << "Testing Container <int ,10>::range -based -for -loop\n";
    for (auto num : container_of_ints)
        std::cout << num << " ";
    std::cout << "\nTesting Container <int ,10>:: clear ()\n";
    container_of_ints.clear ();
    std::cout << "Testing Container <int ,10>:: empty ()\n";
    std::cout << "container_of_ints.empty() is "
              << (container_of_ints.empty() ? "True" : "False")<<"\n";
    std::cout << "\n***** Test completed , enter any key to exit *******\n";
    char s; std::cin >> s;
    return 0;
}