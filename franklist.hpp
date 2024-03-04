#ifndef FRANKLIST_HPP
#define FRANKLIST_HPP

#include "node.hpp"
#include "_flist_iterators.hpp"
#include "_base_iterator.hpp"
#include "_const_iterator.hpp"
#include "_iterator.hpp"
#include "_const_reverse_iterator.hpp"
#include "_reverse_iterator.hpp"
#include "_const_asc_iterator.hpp"
#include "_asc_iterator.hpp"
#include "_const_desc_iterator.hpp"
#include "_decs_iterator.hpp"
#include "_const_multi_iterator.hpp"
#include "_multi_iterator.hpp"
#include "_const_multi_reverse_iterator.hpp"
#include "_multi_reverse_iterator.hpp"


using namespace vhuk;
//-----------------------------------------ctors and dtor-----------------------------------
template <typename T>
FrankList<T>::FrankList () :
    head{nullptr},
    tail{nullptr},
    ahead{nullptr},
    atail{nullptr} {}

template <typename T>
FrankList<T>::FrankList (FrankList<T>::size_type size) : 
    head{nullptr},
    tail{nullptr},
    ahead{nullptr},
    atail{nullptr}
{
    if (size == 0)
        throw std::invalid_argument("The size can't be 0");
    
    for (int i = 0; i < size; ++i) {
        push_back(0);
    }
}

template <typename T>
FrankList<T>::FrankList (FrankList<T>::size_type size, FrankList<T>::const_reference init) {
    if (size == 0)
        throw std::invalid_argument("The size can't be 0");
    head = new Node(init);
    Node* tmp = head;
    for (; size > 1; --size, tmp = tmp->next) {
        tmp->next = new Node(init);
        tmp->next->prev = tmp;
    }
    tail = tmp;
}

// do it with iterators later
template <typename T>
FrankList<T>::FrankList (const FrankList<FrankList<T>::value_type>& rhv) :
    head{nullptr},
    tail{nullptr},
    ahead{nullptr},
    atail{nullptr}
{
    if (rhv.empty())
        return;
    for (const_iterator i = rhv.cbegin(); i != rhv.cend(); ++i) {
        push_back(*i);
    }
}

template <typename T>
FrankList<T>::FrankList (FrankList<FrankList<T>::value_type>&& rhv) :
    head{rhv.head},
    tail{rhv.tail},
    ahead{rhv.ahead},
    atail{rhv.atail}
{
    rhv.head = nullptr;
    rhv.tail = nullptr;
    rhv.ahead = nullptr;
    rhv.atail = nullptr;
}

template <typename T>
FrankList<T>::FrankList (std::initializer_list<FrankList<T>::value_type> init) :
    head{nullptr},
    tail{nullptr},
    ahead{nullptr},
    atail{nullptr}
{
    for (auto i : init) {
        push_back(i);
    }
}

template <typename T>
FrankList<T>::~FrankList () noexcept {
    clear();
}
//----------------------------------------member fucntions----------------------------------------------
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
    if (empty()) {
        head = new Node(elem);
        tail = head;
    }
    else {
        Node* tmp = new Node(elem);
        tail->next = tmp;
        tmp->prev = tail;
        tail = tmp;
    }
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
//------------------------------------------------------operators--------------------------------------------
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

#endif // FRANKLIST_HPP