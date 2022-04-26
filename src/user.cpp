//
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

const std::string &User::getAddress() const {
    return address;
}

void User::setAddress(const std::string &address) {
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

User::User(std::string name, std::string sex, std::string phoneNum, std::string address, std::string postalCode,
           std::string eMail, std::string qqNum, std::string type) : name(std::move(name)), sex(std::move(sex)), phoneNum(std::move(phoneNum)),
                                                                     address(std::move(address)), postalCode(std::move(postalCode)),
                                                                     eMail(std::move(eMail)), QQNum(std::move(qqNum)), type(std::move(type)) {}

User::User() {}

User::~User() {}

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

    std::string address;
    std::cout << "������" << right.name << "��סַ������0����Ϊ���գ���";
    std::cin >> address;
    if(address == "0") {
        right.setAddress("");
    } else {
        right.setAddress(address);
    }

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
        if (regex_match(eMail, std::regex("^\\w+([-+.]\\w+)*@\\w+([-.]\\w+)*\\.\\w+([-.]\\w+)*$"))) {
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
    out << right.getName() << '\t' << right.getSex() << '\t' << right.getPhoneNum() << "  " << right.getAddress()
        << '\t' << right.getPostalCode() << '\t' << right.getEMail() << '\t' << right.getQqNum() << '\t' << right.getType();
    out << std::endl;
    return out;
}

User::User(const std::string &phoneNum) : phoneNum(phoneNum) {}
