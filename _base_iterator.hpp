#ifndef _BASE_ITERATOR_HPP
#define _BASE_ITERATOR_HPP

template <typename T>
FrankList<T>::base_iterator::base_iterator(Node* ptr) : ptr{ptr} {}

template <typename T>
FrankList<T>::base_iterator::~base_iterator() = default;

template <typename T>
bool FrankList<T>::base_iterator::operator== (const FrankList<T>::base_iterator& rhv) const {
    return (ptr == rhv.ptr);
}

template <typename T>
bool FrankList<T>::base_iterator::operator!= (const FrankList<T>::base_iterator& rhv) const {
    return !(ptr == rhv.ptr);
}

#endif // _BASE_ITERATOR_HPP