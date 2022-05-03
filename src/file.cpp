//
// Created by 15928 on 2022/5/3.
//

#include "../include/file.h"

File::File(const std::string path) {
    File::path = path;
}

void File::init(UserList &userList) {
    std::ifstream in;
    in.open(path, std::ios::in);
    if(!in.is_open()) {
        std::cout << "文件打开失败" << std::endl;
        return;
    }
    while(!in.eof()) {
        userList.addNode(in);
    }
    in.close();
}

void File::add(User &user) {
    std::ofstream out;
    out.open(path, std::ios::app);
    if(!out.is_open()) {
        std::cout << "文件打开失败" << std::endl;
        return;
    }
    out << user;
    out.close();
}
