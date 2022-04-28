//
// Created by 15928 on 2022/4/17.
//

#ifndef PROJECT_ABS_USER_H
#define PROJECT_ABS_USER_H
#include <string>
#include <iostream>
#include <regex>
class User {
public:
    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getSex() const;

    void setSex(const std::string &sex);

    const std::string &getPhoneNum() const;

    void setPhoneNum(const std::string &phoneNum);

    const std::string &getAddress() const;

    void setAddress(const std::string &address);

    const std::string &getPostalCode() const;

    void setPostalCode(const std::string &postalCode);

    const std::string &getEMail() const;

    void setEMail(const std::string &eMail);

    const std::string &getQqNum() const;

    void setQqNum(const std::string &qqNum);

    const std::string &getType() const;

    void setType(const std::string &type);

    User();

    User(const std::string &phoneNum);

    virtual ~User();

    friend std::istream &operator>>(std::istream &in, User &right);

    friend std::ostream &operator<<(std::ostream &out, const User &right);

private:
    std::string name;
    std::string sex;
    std::string phoneNum;
    std::string address;
    std::string postalCode;
    std::string eMail;
    std::string QQNum;
    std::string type;
};
#endif //PROJECT_ABS_USER_H
