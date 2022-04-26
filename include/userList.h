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
    ListNode<User> &fetchNode(std::string);

    ListNode<User> &fetchNodeByPhoneNum(std::string);

    std::string delNode(std::string);

    std::string delNodeByPhoneNum(std::string);

    std::string changeNode(std::string);
};

ListNode<User> &UserList::fetchNode(std::string name) {
    ListNode<User> *ptr = head;
    while(ptr->getNext()) {
        if(ptr->getData().getName() == name) {
            return *ptr;
        }
        ptr = ptr->getNext();
    }
    if(ptr->getData().getName() == name) {
        return *ptr;
    }
    return empty;
}

std::string UserList::delNode(std::string name) {
    ListNode<User> *ptr = head;
    ListNode<User> *ptr_ = nullptr;
    while(ptr->getNext()) {
        if(ptr->getData().getName() == name) {
            break;
        }
        ptr_ = ptr;
        ptr = ptr->getNext();
    }
    if(ptr->getData().getName() != name && !ptr->getNext()) {
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

ListNode<User> &UserList::fetchNodeByPhoneNum(std::string phoneNum) {
    ListNode<User> *ptr = head;
    while(ptr->getNext()) {
        if(ptr->getData().getPhoneNum() == phoneNum) {
            return *ptr;
        }
        ptr = ptr->getNext();
    }
    if(ptr->getData().getPhoneNum() == phoneNum) {
        return *ptr;
    }
    return empty;
}

std::string UserList::delNodeByPhoneNum(std::string phoneNum) {
    ListNode<User> *ptr = head;
    ListNode<User> *ptr_ = nullptr;
    while(ptr->getNext()) {
        if(ptr->getData().getPhoneNum() == phoneNum) {
            break;
        }
        ptr_ = ptr;
        ptr = ptr->getNext();
    }
    if(ptr->getData().getPhoneNum() != phoneNum && !ptr->getNext()) {
        return "PHONE_NUM_ERROR";
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
    if(fetchNode(name).getData().getPhoneNum() != empty.getData().getPhoneNum()) {
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
                    fetchNode(name).getData().setName(temp);
                    break;
                }
                case 2: {
                    std::cout << "请输入新的性别:";
                    while(std::cin >> temp) {
                        if (temp == "男" || temp == "女" || temp == "male" || temp == "female") {
                            fetchNode(name).getData().setSex(temp);
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
                            fetchNode(name).getData().setPhoneNum(temp);
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
                        fetchNode(name).getData().setAddress("");
                    } else {
                        fetchNode(name).getData().setAddress(temp);
                    }
                    break;
                }
                case 5: {
                    std::cout << "请输入新的邮编:";
                    while (std::cin >> temp) {
                        if (regex_match(temp, std::regex("^[0-9]{6}"))) {
                            fetchNode(name).getData().setPostalCode(temp);
                            break;
                        } else if(temp == "0") {
                            fetchNode(name).getData().setPostalCode("");
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
                            fetchNode(name).getData().setEMail(temp);
                            break;
                        } else if (temp == "0") {
                            fetchNode(name).getData().setEMail("");
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
                            fetchNode(name).getData().setQqNum(temp);
                            break;
                        } else if (temp == "0") {
                            fetchNode(name).getData().setQqNum("");
                            break;
                        } else {
                            std::cout << "输入的QQ号格式非法，请重新输入:";
                        }
                    }
                }
                case 8: {
                    std::cout << "请输入新的类型:";
                    std::cin >> temp;
                    fetchNode(name).getData().setType(temp);
                    break;
                }
            }
        }
        return "OK";
    } else {
        return "USERNAME_ERROR";
    }
}

#endif //PROJECT_ABS_USERLIST_H
