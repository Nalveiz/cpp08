#include "Span.hpp"
#include <climits>

Span::Span(unsigned int N) : _maxSize(N), _numbers()
{
}
Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers)
{
}
Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}
Span::~Span()
{
}

void Span::addNumber(int number)
{
    if (_numbers.size() >= _maxSize)
        throw FullSpanException();

    _numbers.push_back(number);
}

int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw NoSpanException();

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    std::vector<int>::const_iterator current = sorted.begin() + 1;
    std::vector<int>::const_iterator previous = sorted.begin();



    int minSpan = INT_MAX;
    for (; current != sorted.end(); previous++, current++)
    {
        int span = *current - *previous;
        if (span < minSpan)
            minSpan = span;
    }

    return minSpan;
}


int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw NoSpanException();

    std::vector<int>::const_iterator minIt = std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator maxIt = std::max_element(_numbers.begin(), _numbers.end());

    return *maxIt - *minIt;
}

unsigned int Span::getSize() const
{
    return _numbers.size();
}

unsigned int Span::getMaxSize() const
{
    return _maxSize;
}
