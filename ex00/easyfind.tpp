#ifndef EASYFIND_TPP
#define EASYFIND_TPP

template<typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);

    if (it == container.end())
        throw NotFoundException();

    return it;
}

#endif
