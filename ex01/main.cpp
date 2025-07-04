#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

void testBasicFunctionality()
{
    std::cout << "\n=== Basic Functionality Test ===" << std::endl;

    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void testExceptions()
{
    std::cout << "\n=== Exception Tests ===" << std::endl;

    try {
        Span sp(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4);
    }
    catch (const std::exception& e) {
        std::cout << "FullSpan Exception: " << e.what() << std::endl;
    }

    try {
        Span sp(5);
        sp.shortestSpan();
    }
    catch (const std::exception& e) {
        std::cout << "NoSpan Exception (empty): " << e.what() << std::endl;
    }

    try {
        Span sp(5);
        sp.addNumber(42);

        sp.longestSpan();
    }
    catch (const std::exception& e) {
        std::cout << "NoSpan Exception (single element): " << e.what() << std::endl;
    }
}

void testRangeOfIterators()
{
    std::cout << "\n=== Range of Iterators Test ===" << std::endl;

    try {

        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);

        Span sp(10);
        sp.addNumbers(vec.begin(), vec.end());

        std::cout << "Added " << sp.getSize() << " numbers from vector" << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;


        std::list<int> lst;
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);

        sp.addNumbers(lst.begin(), lst.end());
        std::cout << "After adding list, size: " << sp.getSize() << std::endl;
        std::cout << "New longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void testLargeSpan()
{
    std::cout << "\n=== Large Span Test (10,000 numbers) ===" << std::endl;

    try {
        const unsigned int size = 10000;
        Span sp(size);

        std::srand(std::time(NULL));
        std::vector<int> numbers;

        for (unsigned int i = 0; i < size; ++i) {
            numbers.push_back(std::rand() % 100000);
        }

        sp.addNumbers(numbers.begin(), numbers.end());

        std::cout << "Added " << sp.getSize() << " random numbers" << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void testEdgeCases()
{
    std::cout << "\n=== Edge Cases Test ===" << std::endl;

    try {
        Span sp(5);
        sp.addNumber(5);
        sp.addNumber(5);
        sp.addNumber(5);

        std::cout << "Shortest span with duplicates: " << sp.shortestSpan() << std::endl; // Should be 0
        std::cout << "Longest span with duplicates: " << sp.longestSpan() << std::endl;   // Should be 0

        Span sp2(4);
        sp2.addNumber(-10);
        sp2.addNumber(-5);
        sp2.addNumber(0);
        sp2.addNumber(15);

        std::cout << "Shortest span with negatives: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span with negatives: " << sp2.longestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void testCopyAndAssignment()
{
    std::cout << "\n=== Copy Constructor and Assignment Test ===" << std::endl;

    try {
        Span sp1(5);
        sp1.addNumber(1);
        sp1.addNumber(10);
        sp1.addNumber(100);

        Span sp2(sp1);
        std::cout << "Copied span size: " << sp2.getSize() << std::endl;
        std::cout << "Copied span longest: " << sp2.longestSpan() << std::endl;

        Span sp3(10);
        sp3 = sp1;
        std::cout << "Assigned span size: " << sp3.getSize() << std::endl;
        std::cout << "Assigned span longest: " << sp3.longestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

int main()
{
    std::cout << "=== Span Class Testing ===" << std::endl;

    testBasicFunctionality();
    testExceptions();
    testRangeOfIterators();
    testLargeSpan();
    testEdgeCases();
    testCopyAndAssignment();

    std::cout << "\n=== All tests completed! ===" << std::endl;

    return 0;
}
