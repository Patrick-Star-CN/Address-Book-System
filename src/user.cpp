//
// Created by 15928 on 2022/4/17.
//

#include "../include/user.h"

const string &User::getName() const {
    return name;
}

void User::setName(const string &name) {
    User::name = name;
}

const string &User::getSex() const {
    return sex;
}

void User::setSex(const string &sex) {
    User::sex = sex;
}

const string &User::getPhoneNum() const {
    return phoneNum;
}

void User::setPhoneNum(const string &phoneNum) {
    User::phoneNum = phoneNum;
}

const string &User::getAddress() const {
    return address;
}

void User::setAddress(const string &address) {
    User::address = address;
}

const string &User::getPostalCode() const {
    return postalCode;
}

void User::setPostalCode(const string &postalCode) {
    User::postalCode = postalCode;
}

const string &User::getEMail() const {
    return eMail;
}

void User::setEMail(const string &eMail) {
    User::eMail = eMail;
}

const string &User::getQqNum() const {
    return QQNum;
}

void User::setQqNum(const string &qqNum) {
    QQNum = qqNum;
}

const string &User::getType() const {
    return type;
}

void User::setType(const string &type) {
    User::type = type;
}

User::User(const string &name, const string &sex, const string &phoneNum, const string &address, const string &postalCode,
           const string &eMail, const string &qqNum, const string &type) : name(name), sex(sex), phoneNum(phoneNum),
                                                                           address(address), postalCode(postalCode),
                                                                           eMail(eMail), QQNum(qqNum), type(type) {}

User::User() {}

User::~User() {}

istream &operator>>(istream &in, User &right) {
    cout << "请输入该用户的姓名：";
    cin >> right.name;

    string sex;
    cout << "请输入" << right.name << "的性别：";
    while (cin >> sex) {
        if (sex == "男" || sex == "女" || sex == "male" || sex == "female") {
            right.setSex(sex);
            break;
        } else {
            cout << "输入的性别格式非法，请重新输入：";
        }
    }

    string phoneNum;
    cout << "请输入" << right.name << "的电话号码：";
    while (cin >> phoneNum) {
        if (regex_match(phoneNum, regex("[0-9]{11}"))) {
            right.setPhoneNum(phoneNum);
            break;
        } else {
            cout << "输入的电话号码格式非法，请重新输入：";
        }
    }

    string address;
    cout << "请输入" << right.name << "的住址（输入0代表为留空）：";
    cin >> address;
    if(address == "0") {
        right.setAddress("");
    } else {
        right.setAddress(address);
    }

    string postalCode;
    cout << "请输入" << right.name << "的邮政编码（输入0代表为留空）：";
    while (cin >> postalCode) {
        if (regex_match(postalCode, regex("^[0-9]{6}"))) {
            right.setPostalCode(postalCode);
            break;
        } else if(postalCode == "0") {
            right.setPostalCode("");
            break;
        } else {
                cout << "输入的邮政编码格式非法，请重新输入：";
            }
        }

    string eMail;
    cout << "请输入" << right.name << "的电子邮箱（输入0代表为留空）：";
    while (cin >> eMail) {
        if (regex_match(eMail, regex("^\\w+([-+.]\\w+)*@\\w+([-.]\\w+)*\\.\\w+([-.]\\w+)*$"))) {
            right.setEMail(eMail);
            break;
        } else if (eMail == "0") {
            right.setEMail("");
            break;
        } else {
            cout << "输入的邮箱地址格式非法，请重新输入：";
        }
    }

    string QQNum;
    cout << "请输入" << right.name << "的QQ号（输入0代表为留空）：";
    while (cin >> QQNum) {
        if (regex_match(QQNum, regex("[1-9][0-9]{4,}")) || QQNum == "") {
            right.setQqNum(QQNum);
            break;
        } else if (QQNum == "0") {
            right.setQqNum("");
            break;
        } else {
                cout << "输入的QQ号格式非法，请重新输入：";
            }
        }

    string type;
    cout << "请输入" << right.name << "的类型：";
    cin >> right.type;
    return in;
}

ostream &operator<<(ostream &out, User &right) {
    out << right.name << '\t' << right.sex << '\t' << right.phoneNum << "  " << right.address
        << '\t' << right.postalCode << '\t' << right.eMail << '\t' << right.QQNum << '\t' << right.type;
    return out;
}
