#ifndef _REVERSE_ITERATOR_HPP
#define _REVERSE_ITERATOR_HPP

template <typename T>
FrankList<T>::reverse_iterator::reverse_iterator (Node* tmp) :
    const_reverse_iterator(tmp) {}


template <typename T>
FrankList<T>::reverse_iterator::reverse_iterator (const base_iterator& rhv) :
    const_reverse_iterator(rhv.ptr) {}

template <typename T>
FrankList<T>::reverse_iterator::reverse_iterator (base_iterator&& rhv) :
    const_reverse_iterator(rhv.ptr)
{
    rhv.ptr = nullptr;
}

template <typename T>
typename FrankList<T>::reference FrankList<T>::reverse_iterator::operator* () {
    return (const_cast<FrankList<T>::reference>(static_cast<FrankList<T>::const_reverse_iterator*>(this)->operator*()));
}

template <typename T>
typename FrankList<T>::pointer FrankList<T>::reverse_iterator::operator-> () {
    return (const_cast<FrankList<T>::pointer>(static_cast<FrankList<T>::const_reverse_iterator*>(this)->operator->()));
}

template <typename T>
const typename FrankList<T>::reverse_iterator& FrankList<T>::reverse_iterator::operator= (const FrankList<T>::base_iterator& rhv) {
    *(static_cast<FrankList<T>::const_reverse_iterator*>(this)) = rhv;
    return (*this);
}

template <typename T>
const typename FrankList<T>::reverse_iterator& FrankList<T>::reverse_iterator::operator= (base_iterator&& rhv) {
    *(static_cast<FrankList<T>::const_reverse_iterator*>(this)) = rhv;
    return (*this);
}

#endif // _REVERSE_ITERATOR_HPP