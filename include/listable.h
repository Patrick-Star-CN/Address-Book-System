//
// Created by 15928 on 2022/4/28.
//

#ifndef PROJECT_ABS_LISTABLE_H
#define PROJECT_ABS_LISTABLE_H

#include "../include/listNode.h"

template <typename T>
class Listable {
public:
    virtual ListNode<T> &fetchNode(std::string, std::string);

    virtual std::string delNode(std::string, std::string);

    virtual std::string changeNode(std::string, std::string);

    virtual std::string sortNode();
};
#endif //PROJECT_ABS_LISTABLE_H
