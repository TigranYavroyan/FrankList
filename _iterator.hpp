#ifndef _ITERATOR_HPP
#define _ITERATOR_HPP

#include "franklist.h"

using namespace vhuk;

template <typename T>
FrankList<T>::iterator::iterator (Node* ptr) : const_iterator(ptr) {}

template <typename T>
FrankList<T>::iterator::iterator (const base_iterator& rhv) : const_iterator(rhv.ptr) {}

template <typename T>
FrankList<T>::iterator::iterator (base_iterator&& rhv) : const_iterator(rhv.ptr) {
    rhv.ptr = nullptr;
}

template <typename T>
typename FrankList<T>::reference FrankList<T>::iterator::operator* () {
    return (const_cast<FrankList<T>::reference>(static_cast<FrankList<T>::const_iterator*>(this)->operator*()));
}

template <typename T>
typename FrankList<T>::pointer FrankList<T>::iterator::operator-> () {
    return (const_cast<FrankList<T>::pointer>(static_cast<FrankList<T>::const_iterator*>(this)->operator->()));
}

template <typename T>
const typename FrankList<T>::iterator& FrankList<T>::iterator::operator= (const base_iterator& rhv) {
    *(static_cast<FrankList<T>::const_iterator*>(this)) = rhv;
    return (*this);
}

template <typename T>
const typename FrankList<T>::iterator& FrankList<T>::iterator::operator= (base_iterator&& rhv) {
    *(static_cast<FrankList<T>::const_iterator*>(this)) = rhv;
    return (*this);
}

#endif // _ITERATOR_HPP