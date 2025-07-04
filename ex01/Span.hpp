#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <iterator>

class Span
{
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);

    template<typename Iterator>
    void addNumbers(Iterator begin, Iterator end);

    int shortestSpan() const;
    int longestSpan() const;

    unsigned int getSize() const;
    unsigned int getMaxSize() const;

    class FullSpanException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return "Span is already full";
        }
    };

    class NoSpanException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return "Cannot find span: need at least 2 numbers";
        }
    };
};

// Template function implementation
template<typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end)
{
    size_t distance = std::distance(begin, end);

    if (_numbers.size() + distance > _maxSize)
        throw FullSpanException();

    _numbers.insert(_numbers.end(), begin, end);
}

#endif
