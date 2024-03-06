#ifndef _FLIST_CTORS_DTOR_HPP
#define _FLIST_CTORS_DTOR_HPP

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
FrankList<T>::FrankList (FrankList<T>::size_type size, FrankList<T>::const_reference init) :
    head{nullptr},
    tail{nullptr},
    ahead{nullptr},
    atail{nullptr}
{
    if (size == 0)
        throw std::invalid_argument("The size can't be 0");

    for (int i = 0; i < size; ++i) {
        push_back(init);
    }
}

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
template <typename input_iterator>
FrankList<T>::FrankList(input_iterator f, input_iterator l) {
    
}

template <typename T>
FrankList<T>::~FrankList () noexcept {
    clear();
}

#endif // _FLIST_CTORS_DTOR_HPP