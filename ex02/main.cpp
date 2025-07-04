#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include "MutantStack.hpp"

void testBasicFunctionality()
{
    std::cout << "\n=== Basic MutantStack Test ===" << std::endl;

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top element: " << mstack.top() << std::endl;  // 17

    mstack.pop();

    std::cout << "Size after pop: " << mstack.size() << std::endl;  // 1

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Final size: " << mstack.size() << std::endl;  // 5
}

void testIterators()
{
    std::cout << "\n=== Iterator Test ===" << std::endl;

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Iterating through MutantStack:" << std::endl;

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
}

void testWithStdList()
{
    std::cout << "\n=== Comparison with std::list ===" << std::endl;

    std::list<int> lst;

    lst.push_back(5);
    lst.push_back(17);

    std::cout << "List back element: " << lst.back() << std::endl;  // 17

    lst.pop_back();

    std::cout << "List size after pop: " << lst.size() << std::endl;  // 1

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::cout << "Iterating through std::list:" << std::endl;

    std::list<int>::iterator it = lst.begin();
    std::list<int>::iterator ite = lst.end();

    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
}

void testCopyConstructor()
{
    std::cout << "\n=== Copy Constructor Test ===" << std::endl;

    MutantStack<int> original;
    original.push(1);
    original.push(2);
    original.push(3);

    // Test copy constructor
    MutantStack<int> copied(original);

    std::cout << "Original stack size: " << original.size() << std::endl;
    std::cout << "Copied stack size: " << copied.size() << std::endl;

    std::cout << "Original top: " << original.top() << std::endl;
    std::cout << "Copied top: " << copied.top() << std::endl;

    // Modify original
    original.push(4);

    std::cout << "After modifying original:" << std::endl;
    std::cout << "Original size: " << original.size() << std::endl;
    std::cout << "Copied size: " << copied.size() << std::endl;
}

void testAssignmentOperator()
{
    std::cout << "\n=== Assignment Operator Test ===" << std::endl;

    MutantStack<int> stack1;
    stack1.push(10);
    stack1.push(20);

    MutantStack<int> stack2;
    stack2.push(100);

    std::cout << "Before assignment:" << std::endl;
    std::cout << "Stack1 size: " << stack1.size() << std::endl;
    std::cout << "Stack2 size: " << stack2.size() << std::endl;

    // Assignment
    stack2 = stack1;

    std::cout << "After assignment:" << std::endl;
    std::cout << "Stack1 size: " << stack1.size() << std::endl;
    std::cout << "Stack2 size: " << stack2.size() << std::endl;
    std::cout << "Stack2 top: " << stack2.top() << std::endl;
}

void testReverseIterators()
{
    std::cout << "\n=== Reverse Iterator Test ===" << std::endl;

    MutantStack<int> mstack;

    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    mstack.push(4);
    mstack.push(5);

    std::cout << "Forward iteration:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Reverse iteration:" << std::endl;
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
    {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;
}

void testConversionToStdStack()
{
    std::cout << "\n=== Conversion to std::stack Test ===" << std::endl;

    MutantStack<int> mstack;
    mstack.push(42);
    mstack.push(21);
    mstack.push(84);

    // Convert to std::stack
    std::stack<int> s(mstack);

    std::cout << "MutantStack size: " << mstack.size() << std::endl;
    std::cout << "std::stack size: " << s.size() << std::endl;
    std::cout << "std::stack top: " << s.top() << std::endl;
}

void testSubjectExample()
{
    std::cout << "\n=== Subject Example Test ===" << std::endl;

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);
}

int main()
{
    std::cout << "=== MutantStack Testing ===" << std::endl;

    testSubjectExample();
    testBasicFunctionality();
    testIterators();
    testWithStdList();
    testCopyConstructor();
    testAssignmentOperator();
    testReverseIterators();
    testConversionToStdStack();

    std::cout << "\n=== All tests completed! ===" << std::endl;

    return 0;
}
