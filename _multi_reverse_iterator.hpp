#ifndef _MULTI_REVERSE_ITERATOR_HPP
#define _MULTI_REVERSE_ITERATOR_HPP

template <typename T>
FrankList<T>::multi_reverse_iterator::multi_reverse_iterator (Node* ptr) : const_multi_reverse_iterator(ptr) {}

template <typename T>
FrankList<T>::multi_reverse_iterator::multi_reverse_iterator (const base_iterator& rhv) : const_multi_reverse_iterator(rhv.ptr) {}

template <typename T>
FrankList<T>::multi_reverse_iterator::multi_reverse_iterator (base_iterator&& rhv) : const_multi_reverse_iterator(rhv.ptr) {
    rhv.ptr = nullptr;
}

template <typename T>
typename FrankList<T>::reference FrankList<T>::multi_reverse_iterator::operator* () {
    return (const_cast<FrankList<T>::reference>(static_cast<FrankList<T>::const_multi_reverse_iterator*>(this)->operator*()));
}

template <typename T>
typename FrankList<T>::pointer FrankList<T>::multi_reverse_iterator::operator-> () {
    return (const_cast<FrankList<T>::pointer>(static_cast<FrankList<T>::const_multi_reverse_iterator*>(this)->operator->()));
}

template <typename T>
const typename FrankList<T>::multi_reverse_iterator& FrankList<T>::multi_reverse_iterator::operator= (const base_iterator& rhv) {
    *(static_cast<FrankList<T>::const_multi_reverse_iterator*>(this)) = rhv;
    return (*this);
}

template <typename T>
const typename FrankList<T>::multi_reverse_iterator& FrankList<T>::multi_reverse_iterator::operator= (base_iterator&& rhv) {
    *(static_cast<FrankList<T>::const_multi_reverse_iterator*>(this)) = rhv;
    return (*this);
}

#endif // _MULTI_REVERSE_ITERATOR_HPP