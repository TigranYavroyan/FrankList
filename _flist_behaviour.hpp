#ifndef _FLIST_BEHAVIOUR_HPP
#define _FLIST_BEHAVIOUR_HPP

template <typename T>
void FrankList<T>::swap (FrankList<FrankList::value_type>& rhv ) {
    FrankList<T> tmp = std::move(rhv);
    rhv = std::move(*this);
    this = std::move(tmp);
}

template <typename T>
typename FrankList<T>::size_type FrankList<T>::size () const {
    Node* tmp = head;
    FrankList<T>::size_type count = 0;
    while (tmp != nullptr) {
        tmp = tmp->next;
        ++count;
    }
    return count;
}

template <typename T>
void FrankList<T>::clear () noexcept {
    if (empty())
        return;
    Node* tmp = 0;
    while (head != nullptr) {
        tmp = head->next;
        delete head;
        head = tmp;
    }
    head = nullptr;
    tail = nullptr;
}

template <typename T>
void FrankList<T>::resize (FrankList<T>::size_type c, FrankList<T>::const_reference init) {
    if (c == 0)
        throw std::invalid_argument("The size can't be 0");
    this->clear();
    head = new Node(init);
    Node* tmp = head;
    for (; c > 1; --c, tmp = tmp->next) {
        tmp->next = new Node(init);
        tmp->next->prev = tmp;
    }
    tail = tmp;
}

template <typename T>
void FrankList<T>::push_back (FrankList<T>::const_reference elem) {
    Node* tmp = nullptr;
    if (empty()) {
        tmp = new Node(elem);
        head = tmp;
        tail = head;
    }
    else {
        tmp = new Node(elem);
        tail->next = tmp;
        tmp->prev = tail;
        tail = tmp;
    }
    put_in_sorted_order(tmp);
}

template <typename T>
void FrankList<T>::pop_back () {
    if (empty())
        return;
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }
}

template <typename T>
void FrankList<T>::push_front (FrankList<T>::const_reference elem) {
    if (empty()) {
        head = new Node(elem);
        tail = head;
    }
    else {
        Node* tmp = new Node(elem);
        head->prev = tmp;
        tmp->next = head;
        head = tmp;
    }
}

template <typename T>
void FrankList<T>::pop_front () {
    if (empty())
        return;
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else {
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
    }
}

template <typename T>
void FrankList<T>::print (bool sorted, bool reversed) {
    if (empty())
        std::cout << "The list is empty" << std::endl;
    else if (sorted) {
        for (const_asc_iterator i = this->cabegin(); i != this->caend(); ++i) {
            std::cout << *i << ' ';
        }
    }
    else if (reversed) {
        for (const_reverse_iterator i = this->crbegin(); i != this->crend(); ++i) {
            std::cout << *i << ' ';
        }
        std::cout << std::endl;
    }
    else {
        for (const_iterator i = this->cbegin(); i != this->cend(); ++i) {
            std::cout << *i << ' ';
        }
        std::cout << std::endl;
    }
}

template <typename T>
bool FrankList<T>::empty () const {
    return !head;
}

template <typename T>
typename FrankList<T>::const_reference FrankList<T>::front() const {
    return (this->head->val);
}

template <typename T>
typename FrankList<T>::reference FrankList<T>::front() {
    return (const_cast<FrankList<T>::reference>(static_cast<const FrankList<T>*>(this)->front()));
}

template <typename T>
typename FrankList<T>::const_reference FrankList<T>::back() const {
    return (this->tail->val);
}

template <typename T>
typename FrankList<T>::reference FrankList<T>::back() {
    return (const_cast<FrankList<T>::reference>(static_cast<const FrankList<T>*>(this)->front()));
}

template <typename T>
typename FrankList<T>::const_reference FrankList<T>::min() const {
    return (this->ahead->val);
}

template <typename T>
typename FrankList<T>::reference FrankList<T>::min() {
    return (const_cast<FrankList<T>::reference>(static_cast<const FrankList<T>*>(this)->front()));
}

template <typename T>
typename FrankList<T>::const_reference FrankList<T>::max() const {
    return (this->atail->val);
}

template <typename T>
typename FrankList<T>::reference FrankList<T>::max() {
    return (const_cast<FrankList<T>::reference>(static_cast<const FrankList<T>*>(this)->front()));
}

#endif // _FLIST_BEHAVIOUR_HPP