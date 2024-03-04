#ifndef _FLIST_ITERATORS_HPP
#define _FLIST_ITERATORS_HPP

#include "franklist.h"

using namespace vhuk;
//--------------------------------const---------------------------------------------
template <typename T>
typename FrankList<T>::const_iterator FrankList<T>::cbegin () const {
    return const_iterator(head);
}

template <typename T>
typename FrankList<T>::const_iterator FrankList<T>::cend () const {
    return const_iterator(tail->next);
}

template <typename T>
typename FrankList<T>::const_reverse_iterator FrankList<T>::crbegin () const {
    return const_reverse_iterator(tail);
}

template <typename T>
typename FrankList<T>::const_reverse_iterator FrankList<T>::crend () const {
    return const_reverse_iterator(head->prev);
}
//----------------------------------non const-------------------------------------
template <typename T>
typename FrankList<T>::iterator FrankList<T>::begin () {
    return iterator(head);
}

template <typename T>
typename FrankList<T>::iterator FrankList<T>::end () {
    return iterator(tail->next);
}

template <typename T>
typename FrankList<T>::reverse_iterator FrankList<T>::rbegin () {
    return reverse_iterator(tail);
}

template <typename T>
typename FrankList<T>::reverse_iterator FrankList<T>::rend () {
    return reverse_iterator(head->prev);
}

#endif // _FLIST_ITERATORS_HPP