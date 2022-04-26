//
// Created by 15928 on 2022/4/17.
//

#include "../include/admin.h"

void Admin::addUser() {
    userData = new User();
    std::cin >> *userData;
}

void Admin::printUser() {
    std::cout << "姓名" << '\t' << "性别" << '\t' << "电话号码" << "     " << "地址" << '\t' << "邮政编码" << '\t'
         << "邮箱" << '\t' << "QQ号" << '\t' << "类别" << std::endl;
    std::cout << *userData;
}

