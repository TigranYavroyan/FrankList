#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
FrankList<T>::Node::Node () :
    val{},
    next{nullptr},
    prev{nullptr},
    asc{nullptr},
    desc{nullptr} {}

template <typename T>
FrankList<T>::Node::Node (T _val) :
    val{_val},
    next{nullptr},
    prev{nullptr},
    asc{nullptr},
    desc{nullptr} {}


#endif // NODE_HPP