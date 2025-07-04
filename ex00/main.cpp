#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

void testVector()
{
    std::cout << "\n=== Testing with std::vector ===" << std::endl;

    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    try {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found value 3 at position: " << std::distance(vec.begin(), it) << std::endl;
        std::cout << "Value at iterator: " << *it << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(vec, 10);
        std::cout << "Found value 10 at position: " << std::distance(vec.begin(), it) << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void testList()
{
    std::cout << "\n=== Testing with std::list ===" << std::endl;

    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);

    try {
        std::list<int>::iterator it = easyfind(lst, 30);
        std::cout << "Found value 3 at position: " << std::distance(lst.begin(), it) << std::endl;
        std::cout << "Value at iterator: " << *it << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        std::list<int>::iterator it = easyfind(lst, 100);
        std::cout << "Found value 100 in list" << std::endl;
        std::cout << "Value at iterator: " << *it << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void testDeque()
{
    std::cout << "\n=== Testing with std::deque ===" << std::endl;

    std::deque<int> dq;
    dq.push_back(7);
    dq.push_back(14);
    dq.push_back(21);
    dq.push_back(28);

    try {
        std::deque<int>::iterator it = easyfind(dq, 14);
        std::cout << "Found value 14 at position: " << std::distance(dq.begin(), it) << std::endl;
        std::cout << "Value at iterator: " << *it << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        std::deque<int>::iterator it = easyfind(dq, 42);
        std::cout << "Found value 42 in deque" << std::endl;
        std::cout << "Value at iterator: " << *it << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void testEmptyContainer()
{
    std::cout << "\n=== Testing with empty container ===" << std::endl;

    std::vector<int> empty_vec;

    try {
        std::vector<int>::iterator it = easyfind(empty_vec, 1);
        std::cout << "Found value 1 in empty vector" << std::endl;
        std::cout << "Value at iterator: " << *it << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void testDuplicates()
{
    std::cout << "\n=== Testing with duplicates (first occurrence) ===" << std::endl;

    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(4);

    try {
        std::vector<int>::iterator it = easyfind(vec, 2);
        std::cout << "Found first occurrence of value 2 at position: " << std::distance(vec.begin(), it) << std::endl;
        std::cout << "Value at iterator: " << *it << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

int main()
{
    std::cout << "Testing easyfind function template" << std::endl;

    testVector();
    testList();
    testDeque();
    testEmptyContainer();
    testDuplicates();




    std::cout << "\nAll tests completed!" << std::endl;

    return 0;
}
