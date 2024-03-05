#ifndef _CONST_MULTI_ITERATOR_HPP
#define _CONST_MULTI_ITERATOR_HPP

template <typename T>
FrankList<T>::const_multi_iterator::const_multi_iterator (Node *ptr) :
    base_iterator(ptr) {}

template <typename T>
FrankList<T>::const_multi_iterator::const_multi_iterator (const base_iterator& rhv) :
    base_iterator(rhv.ptr) {}

template <typename T>
FrankList<T>::const_multi_iterator::const_multi_iterator (base_iterator&& rhv) :
    base_iterator(rhv.ptr)
{
    rhv.ptr = nullptr;
}

template <typename T>
const typename FrankList<T>::const_multi_iterator& FrankList<T>::const_multi_iterator::operator= (const base_iterator& rhv) {
    this->ptr = rhv.ptr;
    return (*this);
}

template <typename T>
const typename FrankList<T>::const_multi_iterator& FrankList<T>::const_multi_iterator::operator= (base_iterator&& rhv) {
    this->ptr = rhv.ptr;
    rhv.ptr = nullptr;
    return (*this);
}

template <typename T>
typename FrankList<T>::const_reference FrankList<T>::const_multi_iterator::operator* () const {
    return (this->ptr->val);
}

template <typename T>
typename FrankList<T>::const_pointer FrankList<T>::const_multi_iterator::operator-> () const {
    return &(this->ptr->val);
}

template <typename T>
const typename FrankList<T>::const_multi_iterator& FrankList<T>::const_multi_iterator::operator++ () {
    if (mode == true)
        this->ptr = this->ptr->next;
    else
        this->ptr = this->ptr->asc;
    return (*this);
}

template <typename T>
const typename FrankList<T>::const_multi_iterator FrankList<T>::const_multi_iterator::operator++ (FrankList<T>::value_type) {
    Node *tmp = this->ptr;
    ++(*this);
    return (base_iterator(tmp));
}

template <typename T>
const typename FrankList<T>::const_multi_iterator& FrankList<T>::const_multi_iterator::operator-- () {
    if (mode == true)
        this->ptr = this->ptr->prev;
    else
        this->ptr = this->ptr->desc;
    return (*this);
}

template <typename T>
const typename FrankList<T>::const_multi_iterator FrankList<T>::const_multi_iterator::operator-- (FrankList<T>::value_type) {
    Node *tmp = this->ptr;
    --(*this);
    return (base_iterator(tmp));
}

template <typename T>
void FrankList<T>::const_multi_iterator::chmod () {
    (mode) ? mode = false : mode = true;
}

#endif // _CONST_MULTI_ITERATOR_HPP