//
// Created by 15928 on 2022/4/17.
//

#include "../include/admin.h"

void Admin::addUser() {
    userData = new User();
    cin >> *userData;
}

void Admin::printUser() {
    cout << "����" << '\t' << "�Ա�" << '\t' << "�绰����" << "     " << "��ַ" << '\t' << "��������" << '\t'
         << "����" << '\t' << "QQ��" << '\t' << "���" << endl;
    cout << *userData;
}

