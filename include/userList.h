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
        std::cout << "��������Ҫ�ı�����������" << std::endl
                  << "1: ����" << std::endl
                  << "2: �Ա�" << std::endl
                  << "3: �绰" << std::endl
                  << "4: ��ַ" << std::endl
                  << "5: �ʱ�" << std::endl
                  << "6: ����" << std::endl
                  << "7: QQ��" << std::endl
                  << "8: ���" << std::endl
                  << "0: �˳�" << std::endl;
        int typeNum;
        std::string temp;
        while (std::cin >> typeNum && typeNum) {
            switch (typeNum) {
                case 1: {
                    std::cout << "�������µ�����:";
                    std::cin >> temp;
                    fetchNode(name, "name").getData().setName(temp);
                    name = temp;
                    break;
                }
                case 2: {
                    std::cout << "�������µ��Ա�:";
                    while(std::cin >> temp) {
                        if (temp == "��" || temp == "Ů" || temp == "male" || temp == "female") {
                            fetchNode(name, "name").getData().setSex(temp);
                            break;
                        } else {
                            std::cout << "������Ա��ʽ�Ƿ�������������:";
                        }
                    }
                    break;
                }
                case 3: {
                    std::cout << "�������µĵ绰����:";
                    while(std::cin >> temp) {
                        if (regex_match(temp, std::regex("[0-9]{11}"))) {
                            fetchNode(name, "name").getData().setPhoneNum(temp);
                            break;
                        } else {
                            std::cout << "����ĵ绰��ʽ�Ƿ�������������:";
                        }
                    }
                    break;
                }
                case 4: {
                    std::cout << "�������µĵ�ַ:";
                    std::cin >> temp;
                    if(temp == "0") {
                        fetchNode(name, "name").getData().setAddress("");
                    } else {
                        fetchNode(name, "name").getData().setAddress(temp);
                    }
                    break;
                }
                case 5: {
                    std::cout << "�������µ��ʱ�:";
                    while (std::cin >> temp) {
                        if (regex_match(temp, std::regex("^[0-9]{6}"))) {
                            fetchNode(name, "name").getData().setPostalCode(temp);
                            break;
                        } else if(temp == "0") {
                            fetchNode(name, "name").getData().setPostalCode("");
                            break;
                        } else {
                            std::cout << "��������������ʽ�Ƿ�������������:";
                        }
                    }
                }
                case 6: {
                    std::cout << "�������µ�����:";
                    while (std::cin >> temp) {
                        if (regex_match(temp, std::regex("^\\w+([-+.]\\w+)*@\\w+([-.]\\w+)*\\.\\w+([-.]\\w+)*$"))) {
                            fetchNode(name, "name").getData().setEMail(temp);
                            break;
                        } else if (temp == "0") {
                            fetchNode(name, "name").getData().setEMail("");
                            break;
                        } else {
                            std::cout << "����������ַ��ʽ�Ƿ�������������:";
                        }
                    }
                }
                case 7: {
                    std::cout << "�������µ�QQ��:";
                    while (std::cin >> temp) {
                        if (regex_match(temp, std::regex("[1-9][0-9]{4,}"))) {
                            fetchNode(name, "name").getData().setQqNum(temp);
                            break;
                        } else if (temp == "0") {
                            fetchNode(name, "name").getData().setQqNum("");
                            break;
                        } else {
                            std::cout << "�����QQ�Ÿ�ʽ�Ƿ�������������:";
                        }
                    }
                }
                case 8: {
                    std::cout << "�������µ�����:";
                    std::cin >> temp;
                    fetchNode(name, "name").getData().setType(temp);
                    break;
                }
            }
            std::cout << "��������Ҫ�ı�����������" << std::endl;
        }
        return "OK";
    } else {
        return "USERNAME_ERROR";
    }
}

#endif //PROJECT_ABS_USERLIST_H
