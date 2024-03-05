#ifndef _FLIST_ITERATORS_HPP
#define _FLIST_ITERATORS_HPP

//--------------------------------const---------------------------------------------
template <typename T>
typename FrankList<T>::const_iterator FrankList<T>::cbegin () const {
    return const_iterator(head);
}

template <typename T>
typename FrankList<T>::const_iterator FrankList<T>::cend () const {
    if (!tail)
        throw std::invalid_argument("there is no tail");
    return const_iterator(tail->next);
}

template <typename T>
typename FrankList<T>::const_reverse_iterator FrankList<T>::crbegin () const {
    return const_reverse_iterator(tail);
}

template <typename T>
typename FrankList<T>::const_reverse_iterator FrankList<T>::crend () const {
    if (!head)
        throw std::invalid_argument("there is no head");
    return const_reverse_iterator(head->prev);
}

template <typename T>
typename FrankList<T>::const_asc_iterator FrankList<T>::cabegin () const {
    return const_asc_iterator(ahead);
}

template <typename T>
typename FrankList<T>::const_asc_iterator FrankList<T>::caend () const {
    if (!atail)
        throw std::invalid_argument("there is no tail");
    return const_asc_iterator(atail->asc);
}

template <typename T>
typename FrankList<T>::const_desc_iterator FrankList<T>::cdbegin () const {
    return const_desc_iterator(ahead);
}

template <typename T>
typename FrankList<T>::const_desc_iterator FrankList<T>::cdend () const {
    if (!atail)
        throw std::invalid_argument("there is no tail");
    return const_desc_iterator(atail->desc);
}

template <typename T>
typename FrankList<T>::const_multi_iterator FrankList<T>::cmbegin () const {
    return const_multi_iterator(head);
}

template <typename T>
typename FrankList<T>::const_multi_iterator FrankList<T>::cmend () const {
    if (!tail)
        throw std::invalid_argument("there is no tail");
    return const_multi_iterator(tail->next);
}

template <typename T>
typename FrankList<T>::const_multi_iterator FrankList<T>::cmabegin () const {
    return const_multi_iterator(ahead);
}

template <typename T>
typename FrankList<T>::const_multi_iterator FrankList<T>::cmaend () const {
    if (!tail)
        throw std::invalid_argument("there is no tail");
    return const_multi_iterator(atail->asc);
}

template <typename T>
typename FrankList<T>::const_multi_reverse_iterator FrankList<T>::cmrbegin () const {
    return const_multi_reverse_iterator(tail);
}

template <typename T>
typename FrankList<T>::const_multi_reverse_iterator FrankList<T>::cmrend () const {
    if (!head)
        throw std::invalid_argument("there is no head");
    return const_multi_iterator(head->prev);
}

template <typename T>
typename FrankList<T>::const_multi_reverse_iterator FrankList<T>::cmrdbegin () const {
    return const_multi_iterator(atail);
}

template <typename T>
typename FrankList<T>::const_multi_reverse_iterator FrankList<T>::cmrdend () const {
    if (!head)
        throw std::invalid_argument("there is no head");
    return const_multi_iterator(ahead->desc);
}

//----------------------------------non const-------------------------------------
template <typename T>
typename FrankList<T>::iterator FrankList<T>::begin () {
    return iterator(head);
}

template <typename T>
typename FrankList<T>::iterator FrankList<T>::end () {
    if (!tail)
        throw std::invalid_argument("the is no tail");
    return iterator(tail->next);
}

template <typename T>
typename FrankList<T>::reverse_iterator FrankList<T>::rbegin () {
    return reverse_iterator(tail);
}

template <typename T>
typename FrankList<T>::reverse_iterator FrankList<T>::rend () {
    if (!head)
        throw std::invalid_argument("there is no head");
    return reverse_iterator(head->prev);
}

template <typename T>
typename FrankList<T>::asc_iterator FrankList<T>::abegin () {
    return asc_iterator(ahead);
}

template <typename T>
typename FrankList<T>::asc_iterator FrankList<T>::aend () {
    if (!atail)
        throw std::invalid_argument("there is no tail");
    return asc_iterator(atail->asc);
}

template <typename T>
typename FrankList<T>::desc_iterator FrankList<T>::dbegin () {
    return desc_iterator(ahead);
}

template <typename T>
typename FrankList<T>::desc_iterator FrankList<T>::dend () {
    if (!atail)
        throw std::invalid_argument("there is no tail");
    return desc_iterator(atail->desc);
}

template <typename T>
typename FrankList<T>::multi_iterator FrankList<T>::mbegin () {
    return multi_iterator(head);
}

template <typename T>
typename FrankList<T>::multi_iterator FrankList<T>::mend () {
    if (!tail)
        throw std::invalid_argument("there is no tail");
    return multi_iterator(tail->next);
}

template <typename T>
typename FrankList<T>::multi_iterator FrankList<T>::mabegin () {
    return multi_iterator(ahead);
}

template <typename T>
typename FrankList<T>::multi_iterator FrankList<T>::maend () {
    if (!atail)
        throw std::invalid_argument("there is no tail");
    return multi_iterator(atail->asc);
}

template <typename T>
typename FrankList<T>::multi_reverse_iterator FrankList<T>::mrbegin () {
    return multi_reverse_iterator(tail);
}

template <typename T>
typename FrankList<T>::multi_reverse_iterator FrankList<T>::mrend () {
    if (!head)
        throw std::invalid_argument("there is no head");
    return multi_iterator(head->prev);
}

template <typename T>
typename FrankList<T>::multi_reverse_iterator FrankList<T>::mrdbegin () {
    return multi_iterator(atail);
}

template <typename T>
typename FrankList<T>::multi_reverse_iterator FrankList<T>::mrdend () {
    if (!ahead)
        throw std::invalid_argument("there is no head");
    return multi_iterator(ahead->desc);
}

#endif // _FLIST_ITERATORS_HPP