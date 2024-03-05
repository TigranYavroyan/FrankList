#ifndef _ASC_ITERATOR_HPP
#define _ASC_ITERATOR_HPP

template <typename T>
FrankList<T>::asc_iterator::asc_iterator (Node* ptr) :
    const_asc_iterator(ptr) {}

template <typename T>
FrankList<T>::asc_iterator::asc_iterator (const base_iterator& rhv) :
    const_asc_iterator(rhv.ptr) {}

template <typename T>
FrankList<T>::asc_iterator::asc_iterator (base_iterator&& rhv) :
    const_asc_iterator(rhv.ptr)
{
    rhv.ptr = nullptr;
}

template <typename T>
const typename FrankList<T>::asc_iterator& FrankList<T>::asc_iterator::operator= (const base_iterator& rhv) {
    *(static_cast<const_asc_iterator*>(this)) = rhv.ptr;
    return (*this);
}

template <typename T>
const typename FrankList<T>::asc_iterator& FrankList<T>::asc_iterator::operator= (base_iterator&& rhv) {
    *(static_cast<const_asc_iterator*>(this)) = rhv.ptr;
    return (*this);
}

template <typename T>
typename FrankList<T>::reference FrankList<T>::asc_iterator::operator* () {
    return (const_cast<FrankList<T>::reference>(static_cast<const_asc_iterator*>(this)->operator*()));
}

template <typename T>
typename FrankList<T>::pointer FrankList<T>::asc_iterator::operator-> () {
    return (const_cast<FrankList<T>::pointer>(static_cast<const_asc_iterator*>(this)->operator->()));
}

#endif // _ASC_ITERATOR_HPP