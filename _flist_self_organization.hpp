#ifndef _FLIST_SELF_ORGANIZATION_HPP
#define _FLIST_SELF_ORGANIZATION_HPP

template <typename T>
void FrankList<T>::organize_left(Node* ptr)
{
	
}

template <typename T>
void FrankList<T>::organize_right(Node* ptr)
{
	
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