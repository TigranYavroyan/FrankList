#ifndef _CONST_REVERSE_ITERATOR_HPP
#define _CONST_REVERSE_ITERATOR_HPP

#include "franklist.h"

template <typename T>
FrankList<T>::const_reverse_iterator::const_reverse_iterator (Node* tmp) :
    base_iterator(tmp) {}

template <typename T>
FrankList<T>::const_reverse_iterator::const_reverse_iterator (const base_iterator& rhv) :
    base_iterator(rhv.ptr) {}

template <typename T>
FrankList<T>::const_reverse_iterator::const_reverse_iterator (base_iterator&& rhv) :
    base_iterator(rhv.ptr)
{
    rhv.ptr = nullptr;
}

template <typename T>
const typename FrankList<T>::const_reverse_iterator& FrankList<T>::const_reverse_iterator::operator= (const base_iterator& rhv) {
    this->ptr = rhv.ptr;
    return (*this);
}

template <typename T>
const typename FrankList<T>::const_reverse_iterator& FrankList<T>::const_reverse_iterator::operator= (base_iterator&& rhv) {
    this->ptr = rhv.ptr;
    rhv.ptr = nullptr;
    return (*this);
}

template <typename T>
typename FrankList<T>::const_reference FrankList<T>::const_reverse_iterator::operator* () const {
    return (this->ptr->val);
}

template <typename T>
typename FrankList<T>::const_pointer FrankList<T>::const_reverse_iterator::operator-> () const {
    return &(this->ptr->val);
}

template <typename T>
const typename FrankList<T>::const_reverse_iterator& FrankList<T>::const_reverse_iterator::operator++ () {
    this->ptr = this->ptr->prev;
    return (*this);
}

template <typename T>
const typename FrankList<T>::const_reverse_iterator FrankList<T>::const_reverse_iterator::operator++ (FrankList<T>::value_type) {
    Node* tmp = this->ptr;
    ++(*this);
    return base_iterator(tmp);
}

template <typename T>
const typename FrankList<T>::const_reverse_iterator& FrankList<T>::const_reverse_iterator::operator-- () {
    this->ptr = this->ptr->next;
    return (*this);
}

template <typename T>
const typename FrankList<T>::const_reverse_iterator FrankList<T>::const_reverse_iterator::operator-- (FrankList<T>::value_type) {
    Node* tmp = this->ptr;
    --(*this);
    return base_iterator(tmp);
}

#endif // _CONST_REVERSE_ITERATOR_HPP