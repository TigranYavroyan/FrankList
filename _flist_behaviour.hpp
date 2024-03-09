#ifndef _FLIST_BEHAVIOUR_HPP
#define _FLIST_BEHAVIOUR_HPP

template <typename T>
void FrankList<T>::_poping_asc_desc (Node* edge) {
    if (edge == nullptr)
        throw std::out_of_range("");
    if (edge->desc != nullptr && edge->asc != nullptr) {
            edge->asc->desc = edge->desc;
            edge->desc->asc = edge->asc;
    }
    else if (edge->asc == nullptr) {
        atail = atail->desc;
        atail->asc = nullptr;
    }
    else if (edge->desc == nullptr) {
        ahead = ahead->asc;
        ahead->desc = nullptr;
    }
}

template <typename T>
void FrankList<T>::swap (FrankList<FrankList::value_type>& rhv ) {
    FrankList<T> tmp = std::move(rhv);
    rhv = std::move(*this);
    *this = std::move(tmp);
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
    erase(begin(), end());
}

template <typename T>
void FrankList<T>::resize (FrankList<T>::size_type c, FrankList<T>::const_reference init) {
    if (c == 0)
        throw std::invalid_argument("The size can't be 0");
    if (c > size()) {
        size_type len = size();
        for (; c > len; --c) {
            push_back(init);
        }
    }
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
        _poping_asc_desc(tail);
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }
}

template <typename T>
void FrankList<T>::push_front (FrankList<T>::const_reference elem) {
    Node* tmp = nullptr;
    if (empty()) {
        head = new Node(elem);
        tail = head;
    }
    else {
        tmp = new Node(elem);
        head->prev = tmp;
        tmp->next = head;
        head = tmp;
    }
    put_in_sorted_order(tmp);
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
        _poping_asc_desc(head);
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
    }
}

template <typename T>
void FrankList<T>::print (bool sorted, bool reversed) {
    if (empty())
        std::cout << "The list is empty";
    else
        traverse([](value_type i){std::cout << i << ' ';}, sorted, reversed);
    std::cout << std::endl;
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

template <typename T>
template <typename iter>
iter FrankList<T>::erase (iter pos) {
    if (pos == iter(nullptr))
        return pos;
    else if (pos == iter(tail))
        pop_back();
	else if (pos == iter(head))
		pop_front();
    else {
        _poping_asc_desc(pos.ptr);
        Node* tmp = pos.ptr;
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        delete tmp;
    }
    return pos;
}

template <typename T>
template <typename iter>
iter FrankList<T>::erase (iter f, iter l) {
    for (iter i = f; i != l; ) {
		iter j = i++;
		erase(j);
	}
	return f;
}

template <typename T>
typename FrankList<T>::size_type FrankList<T>::remove (FrankList<T>::const_reference val) {
    FrankList<T>::size_type count = 0;
    const_iterator i = cbegin();
    while (i != cend()) {
        if (*i == val) {
            const_iterator j = i++;
            erase(j);
            ++count;
            continue;
        }
        ++i;
    }
    return count;
}

template <typename T>
template <typename unary_predicate>
typename FrankList<T>::size_type FrankList<T>::remove_if (unary_predicate func) {
    FrankList<T>::size_type count = 0;
    const_iterator i = cbegin();
    while (i != cend()) {
        if (func(*i)) {
            const_iterator j = i++;
            erase(j);
            ++count;
            continue;
        }
        ++i;
    }
    return count;
}

template <typename T>
void FrankList<T>::reverse () {
    Node* t_tail = tail;

	while (tail != nullptr)
	{
		std::swap(tail->next, tail->prev);
		if (tail->next == nullptr)
			break;
		tail = tail->next;
	}
	tail->next = nullptr;
	
	head = t_tail;
	head->prev = nullptr;
}

template <typename T>
void FrankList<T>::sort (bool reversed) {
    if (reversed)
		reverse();
	else {
		head = ahead;
		tail = head;
		head->prev = nullptr;

		for (auto i = abegin(); i != aend(); i++)
		{
			tail->next = i.ptr->asc;
			if (tail->next == nullptr)
				break;
			tail->next->prev = tail;
			tail = tail->next;

		}
	}
}

template <typename T>
typename FrankList<T>::iterator FrankList<T>::find (FrankList<T>::const_reference elem) {
    for (iterator it = begin(); it != end(); ++it) {
        if (*it == elem) {
            if (it != begin())
                organize_left(it.ptr);
            return it;
        }
    }
    return iterator(nullptr);
}

template <typename T>
typename FrankList<T>::iterator FrankList<T>::rfind (FrankList<T>::const_reference elem) {
    for (reverse_iterator it = rbegin(); it != rend(); ++it) {
        if (*it == elem) {
            if (it != rbegin())
                organize_right(it.ptr);
            return it;
        }
    }
    return iterator(nullptr);
}

template <typename T>
template <typename unary_predicate>
void FrankList<T>::traverse (unary_predicate func, bool sorted, bool reversed) {
    if (!sorted && !reversed) {
        for (iterator i = begin(); i != end(); ++i) {
            func(*i);
        }
    }
    else if (sorted && !reversed) {
        for (asc_iterator i = abegin(); i != aend(); ++i) {
            func(*i);
        }
    }
    else if (!sorted && reversed) {
        for (reverse_iterator i = rbegin(); i != rend(); ++i) {
            func(*i);
        }
    }
    else {
        for (desc_iterator i = dbegin(); i != dend(); ++i) {
            func(*i);
        }
    }
}


template <typename T>
template <typename iter>
iter FrankList<T>::insert (iter pos, size_type size, const_reference val) {
    if (pos == end()) {
        while (size) {
            push_back(val);
            --size;
        }
        return end();
    }
    else if (pos == begin()) {
        while (size) {
            push_front(val);
            --size;
        }

    }
    else {
        while (size) {
            Node* tmp = new Node(val);

            tmp->next = pos.ptr;
            tmp->prev = pos.ptr->prev;
            pos.ptr->prev = tmp;
            tmp->prev->next = tmp;
            put_in_sorted_order(tmp);
            --size;
        }
    }
    return pos;
}

template <typename T>
template <typename iter>
iter FrankList<T>::insert_def (iter pos, const_reference val) {
    size_type size = 1;
    insert(pos, size, val);
    return pos;
}

template <typename T>
template <typename iter>
iter FrankList<T>::insert_rev (iter pos, const_reference val) {
    size_type size = 1;
    insert(pos, size, val);
    if (pos != begin())
        return (--pos);
    return pos;
}

template <typename T>
template <typename iter>
iter FrankList<T>::insert (iter pos, std::initializer_list<FrankList<T>::value_type> init) {
    insert (pos, init.begin(), init.end());
}

template <typename T>
template <typename iter, typename input_iterator>
iter FrankList<T>::insert (iter pos, input_iterator f, input_iterator l) {
    while (f != l) {
        insert(pos, *f);
        ++f;
    }
    return pos;
}

#endif // _FLIST_BEHAVIOUR_HPP