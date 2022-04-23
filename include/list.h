//
// Created by 15928 on 2022/4/22.
//

#ifndef PROJECT_ABS_LIST_H
#define PROJECT_ABS_LIST_H

#include "../include/listNode.h"
using namespace std;
template <typename T>
class List {
public:
    List();

    ~List();

    void addNode();

    ListNode<T> &operator[](int index);

private:
    int size;
    ListNode<T> *head;
    ListNode<T> *tail;
};

template<typename T>
void List<T>::addNode() {
    ListNode<T> *newNode = new ListNode<T>();
    T newData;
    cin >> newData;
    newNode->setData(newData);
    newNode->setNext(nullptr);
    newNode->setPrior(tail);
    tail->setNext(newNode);
    tail = newNode;
    if(head == nullptr) {
        head = newNode;
    }
    ++ size;
}

template<typename T>
List<T>::List() {
    size = 0;
    head = nullptr;
}

template<typename T>
List<T>::~List() {
    ListNode<T> *ptr = tail;
    ListNode<T> *ptr_ = nullptr;
    while(ptr->getPrior() != nullptr) {
        ptr_ = ptr->getPrior();
        delete ptr;
        ptr = ptr_;
    }
    delete ptr;
    size = 0;
    ptr = nullptr;
    ptr_ = nullptr;
}

template<typename T>
ListNode<T> &List<T>::operator[](int index) {
    ListNode<T> *ptr = head;
    int size_ = 0;
    while(size_ < index) {
        ptr = ptr->getNext();
        ++ size_;
    }
    return *ptr;
}

#endif //PROJECT_ABS_LIST_H
