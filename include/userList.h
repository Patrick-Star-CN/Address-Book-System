//
// Created by 15928 on 2022/4/26.
//

#ifndef PROJECT_ABS_USERLIST_H
#define PROJECT_ABS_USERLIST_H
#include "list.h"
#include "user.h"
static ListNode<User> empty(User("empty"));

class UserList : public List<User> {
public:
    ListNode<User> &fetchNode(std::string, std::string);

    std::string delNode(std::string, std::string);

    std::string changeNode(std::string);

};

ListNode<User> &UserList::fetchNode(std::string context, std::string type) {
    ListNode<User> *ptr = head;
    while(ptr->getNext()) {
        if(type == "name" && ptr->getData().getName() == context
        || type == "phoneNum" && ptr->getData().getPhoneNum() == context) {
            return *ptr;
        }
        ptr = ptr->getNext();
    }
    if(type == "name" && ptr->getData().getName() == context
    || type == "phoneNum" && ptr->getData().getPhoneNum() == context) {
        return *ptr;
    }
    return empty;
}

std::string UserList::delNode(std::string context, std::string type) {
    ListNode<User> *ptr = head;
    ListNode<User> *ptr_ = nullptr;
    while(ptr->getNext()) {
        if(type == "name" && ptr->getData().getName() == context
        || type == "phoneNum" && ptr->getData().getPhoneNum() == context) {
            break;
        }
        ptr_ = ptr;
        ptr = ptr->getNext();
    }
    if(type == "name" && ptr->getData().getName() != context && !ptr->getNext()
    || type == "phoneNum" && ptr->getData().getPhoneNum() != context && !ptr->getNext()) {
        return "USER_ERROR";
    }
    if(ptr_ && ptr->getNext()) {
        ptr_->setNext(ptr->getNext());
        ptr->getNext()->setPrior(ptr_);
    } else if(ptr_) {
        ptr_->setNext(nullptr);
        tail = ptr_;
    } else if(ptr->getNext()) {
        ptr->getNext()->setPrior(nullptr);
        head = ptr->getNext();
    } else {
        tail = nullptr;
        head = nullptr;
    }
    -- size;
    delete ptr;
    ptr = nullptr;
    return "OK";
}

std::string UserList::changeNode(std::string name) {
    if(fetchNode(name, "name").getData().getPhoneNum() != empty.getData().getPhoneNum()) {
        std::cout << "请输入需要改变的数据名编号" << std::endl
                  << "1: 姓名" << std::endl
                  << "2: 性别" << std::endl
                  << "3: 电话" << std::endl
                  << "4: 地址" << std::endl
                  << "5: 邮编" << std::endl
                  << "6: 邮箱" << std::endl
                  << "7: QQ号" << std::endl
                  << "8: 类别" << std::endl
                  << "0: 退出" << std::endl;
        int typeNum;
        std::string temp;
        while (std::cin >> typeNum && typeNum) {
            switch (typeNum) {
                case 1: {
                    std::cout << "请输入新的姓名:";
                    std::cin >> temp;
                    fetchNode(name, "name").getData().setName(temp);
                    name = temp;
                    break;
                }
                case 2: {
                    std::cout << "请输入新的性别:";
                    while(std::cin >> temp) {
                        if (temp == "男" || temp == "女" || temp == "male" || temp == "female") {
                            fetchNode(name, "name").getData().setSex(temp);
                            break;
                        } else {
                            std::cout << "输入的性别格式非法，请重新输入:";
                        }
                    }
                    break;
                }
                case 3: {
                    std::cout << "请输入新的电话号码:";
                    while(std::cin >> temp) {
                        if (regex_match(temp, std::regex("[0-9]{11}"))) {
                            fetchNode(name, "name").getData().setPhoneNum(temp);
                            break;
                        } else {
                            std::cout << "输入的电话格式非法，请重新输入:";
                        }
                    }
                    break;
                }
                case 4: {
                    std::cout << "请输入新的地址:";
                    std::cin >> temp;
                    if(temp == "0") {
                        fetchNode(name, "name").getData().setAddress("");
                    } else {
                        fetchNode(name, "name").getData().setAddress(temp);
                    }
                    break;
                }
                case 5: {
                    std::cout << "请输入新的邮编:";
                    while (std::cin >> temp) {
                        if (regex_match(temp, std::regex("^[0-9]{6}"))) {
                            fetchNode(name, "name").getData().setPostalCode(temp);
                            break;
                        } else if(temp == "0") {
                            fetchNode(name, "name").getData().setPostalCode("");
                            break;
                        } else {
                            std::cout << "输入的邮政编码格式非法，请重新输入:";
                        }
                    }
                }
                case 6: {
                    std::cout << "请输入新的邮箱:";
                    while (std::cin >> temp) {
                        if (regex_match(temp, std::regex("^\\w+([-+.]\\w+)*@\\w+([-.]\\w+)*\\.\\w+([-.]\\w+)*$"))) {
                            fetchNode(name, "name").getData().setEMail(temp);
                            break;
                        } else if (temp == "0") {
                            fetchNode(name, "name").getData().setEMail("");
                            break;
                        } else {
                            std::cout << "输入的邮箱地址格式非法，请重新输入:";
                        }
                    }
                }
                case 7: {
                    std::cout << "请输入新的QQ号:";
                    while (std::cin >> temp) {
                        if (regex_match(temp, std::regex("[1-9][0-9]{4,}"))) {
                            fetchNode(name, "name").getData().setQqNum(temp);
                            break;
                        } else if (temp == "0") {
                            fetchNode(name, "name").getData().setQqNum("");
                            break;
                        } else {
                            std::cout << "输入的QQ号格式非法，请重新输入:";
                        }
                    }
                }
                case 8: {
                    std::cout << "请输入新的类型:";
                    std::cin >> temp;
                    fetchNode(name, "name").getData().setType(temp);
                    break;
                }
            }
            std::cout << "请输入需要改变的数据名编号" << std::endl;
        }
        return "OK";
    } else {
        return "USERNAME_ERROR";
    }
}

#endif //PROJECT_ABS_USERLIST_H
