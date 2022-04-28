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
                    fetchNode(name).getData().setName(temp);
                    name = temp;
                    break;
                }
                case 2: {
                    std::cout << "�������µ��Ա�:";
                    while(std::cin >> temp) {
                        if (temp == "��" || temp == "Ů" || temp == "male" || temp == "female") {
                            fetchNode(name).getData().setSex(temp);
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
                            fetchNode(name).getData().setPhoneNum(temp);
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
                        fetchNode(name).getData().setAddress("");
                    } else {
                        fetchNode(name).getData().setAddress(temp);
                    }
                    break;
                }
                case 5: {
                    std::cout << "�������µ��ʱ�:";
                    while (std::cin >> temp) {
                        if (regex_match(temp, std::regex("^[0-9]{6}"))) {
                            fetchNode(name).getData().setPostalCode(temp);
                            break;
                        } else if(temp == "0") {
                            fetchNode(name).getData().setPostalCode("");
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
                            fetchNode(name).getData().setEMail(temp);
                            break;
                        } else if (temp == "0") {
                            fetchNode(name).getData().setEMail("");
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
                            fetchNode(name).getData().setQqNum(temp);
                            break;
                        } else if (temp == "0") {
                            fetchNode(name).getData().setQqNum("");
                            break;
                        } else {
                            std::cout << "�����QQ�Ÿ�ʽ�Ƿ�������������:";
                        }
                    }
                }
                case 8: {
                    std::cout << "�������µ�����:";
                    std::cin >> temp;
                    fetchNode(name).getData().setType(temp);
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
