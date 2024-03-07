#ifndef _FLIST_SELF_ORGANIZATION_HPP
#define _FLIST_SELF_ORGANIZATION_HPP

template <typename T>
void FrankList<T>::organize_left(Node* ptr) {
    Node* _prev = ptr->prev;

	if (_prev == head)
		head = ptr;
	else
		_prev->prev->next = ptr;

	_prev->next = ptr->next;
	ptr->next = _prev;
	ptr->prev = _prev->prev;
	_prev->prev = ptr;

	if (ptr == tail)
		tail = _prev;
	else
		_prev->next->prev = _prev;
    
}

template <typename T>
void FrankList<T>::organize_right(Node* ptr) {
	Node* _next = ptr->next;

	if (_next == tail)
		tail = ptr;
	else
		_next->next->prev = ptr;

	_next->prev = ptr->prev;
	ptr->prev = _next;
	ptr->next = _next->next;
	_next->next = ptr;

	if (ptr == head)
		head = _next;
	else
		_next->prev->next = _next;
    
}

template <typename T>
void FrankList<T>::put_in_sorted_order (Node* ptr) {
    if (ahead == nullptr && atail == nullptr) {
        ahead = ptr;
        atail = ptr;
    }
    else if (ptr->val < ahead->val) {
        ptr->asc = ahead;
        ahead->desc = ptr;
        ahead = ptr;
    }
    else if (ptr->val > atail->val) {
        ptr->desc = atail;
        atail->asc = ptr;
        atail = ptr;
    }
    else {
        for (asc_iterator i = abegin(); i != aend() && i.ptr->asc != nullptr; ++i) {
            if (ptr->val > *i && i.ptr->asc->val >= ptr->val) {
                ptr->asc = i.ptr->asc;
                ptr->desc = i.ptr;
                i.ptr->asc->desc = ptr;
                i.ptr->asc = ptr;
                break;
            }
        }
    }
}

#endif // _FLIST_SELF_ORGANIZATION_HPP