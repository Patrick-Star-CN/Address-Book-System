//
// Created by 15928 on 2022/4/26.
//

#ifndef PROJECT_ABS_USERLIST_H
#define PROJECT_ABS_USERLIST_H
#include "list.h"
#include "user.h"
class UserList : public List<User> {
public:
    ListNode<User> fetchNode(string);
};

ListNode<User> UserList::fetchNode(string index) {
    ListNode<User> *ptr = head;
    while(ptr->getNext()) {
        if(ptr->getData().getName() == index) {
            return *ptr;
        }
        ptr = ptr->getNext();
    }
    if(ptr->getData().getName() == index) {
        return *ptr;
    }
    return ListNode<User>(User(0));
}

#endif //PROJECT_ABS_USERLIST_H
