#ifndef _FLIST_OPERATORS_HPP
#define _FLIST_OPERATORS_HPP

template <typename T>
const FrankList<T>& FrankList<T>::operator= (const FrankList<T>& rhv) {
    *this = FrankList<T>(rhv);
    return (*this);
}

template <typename T>
const FrankList<T>& FrankList<T>::operator= (FrankList<T>&& rhv) {
    this->clear();
    head = rhv.head;
    tail = rhv.tail;
    ahead = rhv.ahead;
    atail = rhv.atail;

    rhv.head = nullptr;
    rhv.tail = nullptr;
    rhv.ahead = nullptr;
    rhv.atail = nullptr;

    return (*this);
}

template <typename T>
const FrankList<T>& FrankList<T>::operator= (std::initializer_list<T> init) {
    *this = FrankList<T>(init);
    return (*this);
}

template <typename T>
bool FrankList<T>::operator== (const FrankList<T>& rhv) const {
    if (this->size() != rhv.size())
        return false;
    const_iterator i_this = cbegin();
    const_iterator i = rhv.cbegin();
    for (; i_this != this->cend() && i != rhv.cend()) {
        if (*i != *i_this)
            return false;
    }
    return true;
}

template <typename T>
bool FrankList<T>::operator!= (const FrankList<T>& rhv) const {
    return !(*this == rhv);
}

template <typename T>
bool FrankList<T>::operator< (const FrankList<T>& rhv) const {
    const_iterator i_this = cbegin();
    const_iterator i = rhv.cbegin();
    for (; i_this != this->cend() && i != rhv.cend()) {
        if (*i_this < *i)
            return true;
        else if (*i_this > *i)
            return false;
    }
    return (this->size() < rhv.size()) ? true : false;
}

template <typename T>
bool FrankList<T>::operator<= (const FrankList<T>& rhv) const {
    const_iterator i_this = cbegin();
    const_iterator i = rhv.cbegin();
    for (; i_this != this->cend() && i != rhv.cend()) {
        if (*i_this < *i)
            return true;
        else if (*i_this > *i)
            return false;
    }
    return (this->size() <= rhv.size()) ? true : false;
}

template <typename T>
bool FrankList<T>::operator> (const FrankList<T>& rhv) const {
    const_iterator i_this = cbegin();
    const_iterator i = rhv.cbegin();
    for (; i_this != this->cend() && i != rhv.cend()) {
        if (*i_this > *i)
            return true;
        else if (*i_this < *i)
            return false;
    }
    return (this->size() > rhv.size()) ? true : false;
}

template <typename T>
bool FrankList<T>::operator>= (const FrankList<T>& rhv) const {
    const_iterator i_this = cbegin();
    const_iterator i = rhv.cbegin();
    for (; i_this != this->cend() && i != rhv.cend()) {
        if (*i_this > *i)
            return true;
        else if (*i_this < *i)
            return false;
    }
    return (this->size() >= rhv.size()) ? true : false;
}

#endif // _FLIST_OPERATORS_HPP