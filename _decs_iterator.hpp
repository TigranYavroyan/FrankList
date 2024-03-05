#ifndef _DESC_ITERATOR_HPP
#define _DESC_ITERATOR_HPP

template <typename T>
FrankList<T>::desc_iterator::desc_iterator (Node* ptr) :
    const_desc_iterator(ptr) {}

template <typename T>
FrankList<T>::desc_iterator::desc_iterator (const base_iterator& rhv) :
    const_desc_iterator(rhv.ptr) {}

template <typename T>
FrankList<T>::desc_iterator::desc_iterator (base_iterator&& rhv) :
    const_desc_iterator(rhv.ptr)
{
    rhv.ptr = nullptr;
}

template <typename T>
const typename FrankList<T>::desc_iterator& FrankList<T>::desc_iterator::operator= (const base_iterator& rhv) {
    *(static_cast<const_desc_iterator*>(this)) = rhv.ptr;
    return (*this);
}

template <typename T>
const typename FrankList<T>::desc_iterator& FrankList<T>::desc_iterator::operator= (base_iterator&& rhv) {
    *(static_cast<const_desc_iterator*>(this)) = rhv.ptr;
    return (*this);
}

template <typename T>
typename FrankList<T>::reference FrankList<T>::desc_iterator::operator* () {
    return (const_cast<FrankList<T>::reference>(static_cast<const_desc_iterator*>(this)->operator*()));
}

template <typename T>
typename FrankList<T>::pointer FrankList<T>::desc_iterator::operator-> () {
    return (const_cast<FrankList<T>::pointer>(static_cast<const_desc_iterator*>(this)->operator->()));
}

#endif // _DESC_ITERATOR_HPP