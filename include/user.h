//
// Created by 15928 on 2022/4/17.
//

#ifndef PROJECT_ABS_USER_H
#define PROJECT_ABS_USER_H
#include <string>
#include <iostream>
#include <regex>
using namespace std;
class User {
public:
    const string &getName() const;

    void setName(const string &name);

    const string &getSex() const;

    void setSex(const string &sex);

    const string &getPhoneNum() const;

    void setPhoneNum(const string &phoneNum);

    const string &getAddress() const;

    void setAddress(const string &address);

    const string &getPostalCode() const;

    void setPostalCode(const string &postalCode);

    const string &getEMail() const;

    void setEMail(const string &eMail);

    const string &getQqNum() const;

    void setQqNum(const string &qqNum);

    const string &getType() const;

    void setType(const string &type);

    User(const string &name, const string &sex, const string &phoneNum, const string &address, const string &zipCode,
         const string &eMail, const string &qqNum, const string &type);

    User();

    virtual ~User();

    friend istream &operator>>(istream &in, User &right);

    friend ostream &operator<<(ostream &out, const User &right);

private:
    string name;
    string sex;
    string phoneNum;
    string address;
    string postalCode;
    string eMail;
    string QQNum;
    string type;
};
#endif //PROJECT_ABS_USER_H
