//
// 用户数据的链表类
// Created by 15928 on 2022/4/26.
//

#ifndef PROJECT_ABS_USERLIST_H
#define PROJECT_ABS_USERLIST_H
#include "list.h"
#include "user.h"
#include "listable.h"

class UserList : public List<User>/*, public Listable<User>*/ {
public:
    ListNode<User> &fetchNode(std::string, std::string);

    void fetchNode();

    std::string delNode(std::string, std::string);

    std::string changeNode(std::string, std::string);

    void sortNode();

private:
    void sort(bool (*cmp)(const ListNode<User>&, const ListNode<User>&));

    void swap(ListNode<User>*, ListNode<User>*);
};

#endif //PROJECT_ABS_USERLIST_H
