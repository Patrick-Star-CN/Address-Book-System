//
// Created by 15928 on 2022/4/28.
//

#ifndef PROJECT_ABS_LISTABLE_H
#define PROJECT_ABS_LISTABLE_H

#include "../include/listNode.h"

template <typename T>
class Listable {
public:
    virtual void delNode(std::string) = 0;

    virtual ListNode<T> &fetchNode(std::string) = 0;
};
#endif //PROJECT_ABS_LISTABLE_H
