//
// Created by 15928 on 2022/4/22.
//

#ifndef PROJECT_ABS_LIST_H
#define PROJECT_ABS_LIST_H

#include "../include/listNode.h"
template <typename T>
class List {
public:
    List();

    ~List();

    int getSize();

    void addNode();

    void delNode(int);

    ListNode<T> &operator[](int);

    //virtual void delNode(std::string) = 0;

    //virtual ListNode<T> &fetchNode(std::string) = 0;

protected:
    int size;
    ListNode<T> *head;
    ListNode<T> *tail;
};

template<typename T>
void List<T>::addNode() {
    ListNode<T> *newNode = new ListNode<T>();
    T newData;
    std::cin >> newData;
    newNode->setData(newData);
    newNode->setNext(nullptr);
    newNode->setPrior(tail);
    if(tail) {
        tail->setNext(newNode);
    }
    tail = newNode;
    if(head == nullptr) {
        head = newNode;
        head->setPrior(nullptr);
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
    if(index >= size) {
        index = size - 1;
    }
    while(size_ < index) {
        ptr = ptr->getNext();
        ++ size_;
    }
    return *ptr;
}

template<typename T>
void List<T>::delNode(int index) {
    ListNode<T> *ptr = head;
    ListNode<T> *ptr_ = nullptr;
    int size_ = 0;
    if(index >= size) {
        index = size - 1;
    }
    while(size_ < index) {
        ptr_ = ptr;
        ptr = ptr->getNext();
        ++ size_;
    }
    if(ptr_ && ptr->getNext()) {
        ptr_->setNext(ptr->getNext());
        ptr->getNext()->setPrior(ptr_);
    } else if(ptr_) {
        ptr_->setNext(nullptr);
        tail = ptr_;
    } else if(ptr->getNext()) {
        ptr->getNext()->setPrior(nullptr);
        head = ptr->getNext();
    } else {
        tail = nullptr;
        head = nullptr;
    }
    -- size;
    delete ptr;
    ptr = nullptr;
}

template<typename T>
int List<T>::getSize() {
    return size;
}


#endif //PROJECT_ABS_LIST_H
