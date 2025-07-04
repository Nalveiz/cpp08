#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
    // Constructor
    MutantStack();

    // Copy constructor
    MutantStack(const MutantStack& other);

    // Assignment operator
    MutantStack& operator=(const MutantStack& other);

    // Destructor
    ~MutantStack();

    // Iterator typedef - std::stack uses std::deque by default
    // We access the underlying container through std::stack::c
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    // Iterator functions
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    reverse_iterator rbegin();
    reverse_iterator rend();
    const_reverse_iterator rbegin() const;
    const_reverse_iterator rend() const;
};

#include "MutantStack.tpp"

#endif
