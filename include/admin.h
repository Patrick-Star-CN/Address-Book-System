//
// Created by 15928 on 2022/4/17.
//

#ifndef PROJECT_ABS_ADMIN_H
#define PROJECT_ABS_ADMIN_H
#include "user.h"
class Admin {
public:
    void addUser();
    void printUser();

private:
    User *userData;
};
#endif //PROJECT_ABS_ADMIN_H
