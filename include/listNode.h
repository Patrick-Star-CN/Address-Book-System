//
// Created by 15928 on 2022/4/22.
//

#ifndef PROJECT_ABS_LISTNODE_H
#define PROJECT_ABS_LISTNODE_H

#include <iostream>
using namespace std;
template <typename T>
class ListNode {
public:
    T getData() const;

    void setData(T data);

    ListNode *getNext() const;

    void setNext(ListNode *next);

    ListNode *getPrior() const;

    void setPrior(ListNode *prior);

    friend istream &operator>>(istream &in, ListNode<T> &right);

    friend ostream &operator<<(ostream &out, ListNode<T> &right);

private:
    T data;
    ListNode *next;
    ListNode *prior;
};

template<typename T>
T ListNode<T>::getData() const {
    return data;
}

template<typename T>
void ListNode<T>::setData(T data) {
    ListNode::data = data;
}

template<typename T>
ListNode<T> *ListNode<T>::getNext() const {
    return next;
}

template<typename T>
void ListNode<T>::setNext(ListNode *next) {
    ListNode::next = next;
}

template<typename T>
ListNode<T> *ListNode<T>::getPrior() const {
    return prior;
}

template<typename T>
void ListNode<T>::setPrior(ListNode *prior) {
    ListNode::prior = prior;
}

template<typename T>
istream &operator>>(istream &in, ListNode<T> &right) {
    return in >> right.getData();
}

template<typename T>
ostream &operator<<(ostream &out, ListNode<T> &right) {
    return out << right.getData();
}

#endif //PROJECT_ABS_LISTNODE_H
