//
// �û��������ʵ���ļ�
// Created by 15928 on 2022/4/17.
//

#include "../include/user.h"

#include <utility>

const std::string &User::getName() const {
    return name;
}

void User::setName(const std::string &name) {
    User::name = name;
}

const std::string &User::getSex() const {
    return sex;
}

void User::setSex(const std::string &sex) {
    User::sex = sex;
}

const std::string &User::getPhoneNum() const {
    return phoneNum;
}

void User::setPhoneNum(const std::string &phoneNum) {
    User::phoneNum = phoneNum;
}

const Address &User::getAddress() const {
    return address;
}

void User::setAddress(const Address &address) {
    User::address = address;
}

const std::string &User::getPostalCode() const {
    return postalCode;
}

void User::setPostalCode(const std::string &postalCode) {
    User::postalCode = postalCode;
}

const std::string &User::getEMail() const {
    return eMail;
}

void User::setEMail(const std::string &eMail) {
    User::eMail = eMail;
}

const std::string &User::getQqNum() const {
    return QQNum;
}

void User::setQqNum(const std::string &qqNum) {
    QQNum = qqNum;
}

const std::string &User::getType() const {
    return type;
}

void User::setType(const std::string &type) {
    User::type = type;
}

User::User() = default;

User::~User() = default;

std::istream &operator>>(std::istream &in, User &right) {
    std::cout << "��������û���������";
    std::cin >> right.name;

    std::string sex;
    std::cout << "������" << right.name << "���Ա�";
    while (std::cin >> sex) {
        if (sex == "��" || sex == "Ů" || sex == "male" || sex == "female") {
            right.setSex(sex);
            break;
        } else {
            std::cout << "������Ա��ʽ�Ƿ������������룺";
        }
    }

    std::string phoneNum;
    std::cout << "������" << right.name << "�ĵ绰���룺";
    while (std::cin >> phoneNum) {
        if (regex_match(phoneNum, std::regex("[0-9]{11}"))) {
            right.setPhoneNum(phoneNum);
            break;
        } else {
            std::cout << "����ĵ绰�����ʽ�Ƿ������������룺";
        }
    }

    std::cout << "������" << right.name << "��סַ";
    std::cin >> right.address;

    std::string postalCode;
    std::cout << "������" << right.name << "���������루����0����Ϊ���գ���";
    while (std::cin >> postalCode) {
        if (regex_match(postalCode, std::regex("^[0-9]{6}"))) {
            right.setPostalCode(postalCode);
            break;
        } else if(postalCode == "0") {
            right.setPostalCode("");
            break;
        } else {
            std::cout << "��������������ʽ�Ƿ������������룺";
        }
    }

    std::string eMail;
    std::cout << "������" << right.name << "�ĵ������䣨����0����Ϊ���գ���";
    while (std::cin >> eMail) {
        if (regex_match(eMail, std::regex(R"(^\w+([-+.]\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*$)"))) {
            right.setEMail(eMail);
            break;
        } else if (eMail == "0") {
            right.setEMail("");
            break;
        } else {
            std::cout << "����������ַ��ʽ�Ƿ������������룺";
        }
    }

    std::string QQNum;
    std::cout << "������" << right.name << "��QQ�ţ�����0����Ϊ���գ���";
    while (std::cin >> QQNum) {
        if (regex_match(QQNum, std::regex("[1-9][0-9]{4,}"))) {
            right.setQqNum(QQNum);
            break;
        } else if (QQNum == "0") {
            right.setQqNum("");
            break;
        } else {
            std::cout << "�����QQ�Ÿ�ʽ�Ƿ������������룺";
        }
    }

    std::string type;
    std::cout << "������" << right.name << "�����ͣ�";
    std::cin >> right.type;
    return in;
}

std::ostream &operator<<(std::ostream &out, const User &right) {
    out << "����:" << right.getName() << '\n'
        << "�Ա�:" << right.getSex() << '\n'
        << "�绰:" << right.getPhoneNum() << "\n"
        << "��ַ:" << right.getAddress() << '\n'
        << "�ʱ�:" << right.getPostalCode() << '\n'
        << "����:" << right.getEMail() << '\n'
        << "QQ��:" << right.getQqNum() << '\n'
        << "����:" << right.getType() << std::endl;
    return out;
}

User::User(std::string phoneNum) : phoneNum(std::move(phoneNum)) {}
