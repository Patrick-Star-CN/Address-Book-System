//
// �û������������ʵ���ļ�
// Created by 15928 on 2022/4/28.
//

#include "../include/userList.h"

static ListNode<User> empty(User("empty"));  // �ն���

ListNode<User> &UserList::fetchNode(std::string context, std::string type) {
    // ��ѯ����
    ListNode<User> *ptr = head;
    while(ptr->getNext()) {
        if(type == "name" && ptr->getData().getName() == context
           || type == "phoneNum" && ptr->getData().getPhoneNum() == context) {
            return *ptr;
        }
        ptr = ptr->getNext();
    }

    //���Ľڵ�Ϊ����ڵ�
    if(type == "name" && ptr->getData().getName() == context
       || type == "phoneNum" && ptr->getData().getPhoneNum() == context) {
        return *ptr;
    }
    return empty;
}

std::string UserList::delNode(std::string context, std::string type) {
    // ɾ�����ܣ�type���Ʋ�ѯ�ķ�����֧�����������ֻ��Ų�ѯ
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

    //���Ľڵ�Ϊ����ڵ�
    if(type == "name" && ptr->getData().getName() != context && !ptr->getNext()
       || type == "phoneNum" && ptr->getData().getPhoneNum() != context && !ptr->getNext()) {
        return "USER_ERROR";
    }

    if(ptr_ && ptr->getNext()) {
        ptr_->setNext(ptr->getNext());
        ptr->getNext()->setPrior(ptr_);
    } else if(ptr_) {
        //ɾβ�ڵ�
        ptr_->setNext(nullptr);
        tail = ptr_;
    } else if(ptr->getNext()) {
        //ɾͷ�ڵ�
        ptr->getNext()->setPrior(nullptr);
        head = ptr->getNext();
    } else {
        //ɾ����Ψһ�ڵ�
        tail = nullptr;
        head = nullptr;
    }

    -- size;
    delete ptr;
    ptr = nullptr;
    return "OK";
}

std::string UserList::changeNode(std::string context, std::string type) {
    // �޸Ĺ��ܣ�type���Ʋ�ѯ�ķ�����֧�����������ֻ����޸�
    if(type == "name" && fetchNode(context, "name").getData().getPhoneNum() != empty.getData().getPhoneNum()
       || type == "phoneNum" && fetchNode(context, "phoneNum").getData().getPhoneNum() != empty.getData().getPhoneNum()) {
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
                    if(type == "name") {
                        fetchNode(context, "name").getData().setName(temp);
                        context = temp;
                    } else if(type == "phoneNum") {
                        fetchNode(context, "phoneNum").getData().setName(temp);
                    }
                    break;
                }
                case 2: {
                    std::cout << "�������µ��Ա�:";
                    while(std::cin >> temp) {
                        if (temp == "��" || temp == "Ů" || temp == "male" || temp == "female") {
                            if(type == "name") {
                                fetchNode(context, "name").getData().setSex(temp);
                            } else if(type == "phoneNum") {
                                fetchNode(context, "phoneNum").getData().setSex(temp);
                            }
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
                            if(type == "name") {
                                fetchNode(context, "name").getData().setPhoneNum(temp);
                            } else if(type == "phoneNum") {
                                fetchNode(context, "phoneNum").getData().setPhoneNum(temp);
                                context = temp;
                            }
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
                        if(type == "name") {
                            fetchNode(context, "name").getData().setAddress("");
                        } else if(type == "phoneNum") {
                            fetchNode(context, "phoneNum").getData().setAddress("");
                        }
                    } else {
                        if(type == "name") {
                            fetchNode(context, "name").getData().setAddress(temp);
                        } else if(type == "phoneNum") {
                            fetchNode(context, "phoneNum").getData().setAddress(temp);
                        }
                    }
                    break;
                }
                case 5: {
                    std::cout << "�������µ��ʱ�:";
                    while (std::cin >> temp) {
                        if (regex_match(temp, std::regex("^[0-9]{6}"))) {
                            if(type == "name") {
                                fetchNode(context, "name").getData().setPostalCode(temp);
                            } else if(type == "phoneNum") {
                                fetchNode(context, "phoneNum").getData().setPostalCode(temp);
                            }
                            break;
                        } else if(temp == "0") {
                            if(type == "name") {
                                fetchNode(context, "name").getData().setPostalCode("");
                            } else if(type == "phoneNum") {
                                fetchNode(context, "phoneNum").getData().setPostalCode("");
                            }
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
                            if(type == "name") {
                                fetchNode(context, "name").getData().setEMail(temp);
                            } else if(type == "phoneNum") {
                                fetchNode(context, "phoneNum").getData().setEMail(temp);
                            }
                            break;
                        } else if (temp == "0") {
                            if(type == "name") {
                                fetchNode(context, "name").getData().setEMail("");
                            } else if(type == "phoneNum") {
                                fetchNode(context, "phoneNum").getData().setEMail("");
                            }
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
                            if(type == "name") {
                                fetchNode(context, "name").getData().setQqNum(temp);
                            } else if(type == "phoneNum") {
                                fetchNode(context, "phoneNum").getData().setQqNum(temp);
                            }
                            break;
                        } else if (temp == "0") {
                            if(type == "name") {
                                fetchNode(context, "name").getData().setQqNum("");
                            } else if(type == "phoneNum") {
                                fetchNode(context, "phoneNum").getData().setQqNum("");
                            }
                            break;
                        } else {
                            std::cout << "�����QQ�Ÿ�ʽ�Ƿ�������������:";
                        }
                    }
                }
                case 8: {
                    std::cout << "�������µ�����:";
                    std::cin >> temp;
                    if(type == "name") {
                        fetchNode(context, "name").getData().setType("");
                    } else if(type == "phoneNum") {
                        fetchNode(context, "phoneNum").getData().setType("");
                    }
                    break;
                }
            }
            std::cout << "��������Ҫ�ı�����������" << std::endl;
        }
        return "OK";
    } else {
        // ��ѯ���ݳ�������
        return "ERROR";
    }
}

void UserList::sortNode() {
    // ������
    std::cout << "����������ؼ��ʵı��" << std::endl
              << "1: ����" << std::endl
              << "2: �Ա�" << std::endl
              << "3: �绰" << std::endl
              << "4: ��ַ" << std::endl
              << "5: �ʱ�" << std::endl
              << "6: ����" << std::endl
              << "7: QQ��" << std::endl
              << "8: ���" << std::endl;
    int type;
    std::cin >> type;
    switch(type) {
        case 1: {
            sort([](const ListNode<User> &left, const ListNode<User> &right) -> bool {
                return left.getData().getName() < right.getData().getName();
            });
            display();
            break;
        }
        case 2: {
            sort([](const ListNode<User> &left, const ListNode<User> &right) -> bool {
                return left.getData().getSex() < right.getData().getSex();
            });
            display();
            break;
        }
        case 3: {
            sort([](const ListNode<User> &left, const ListNode<User> &right) -> bool {
                return left.getData().getPhoneNum() < right.getData().getPhoneNum();
            });
            display();
            break;
        }
        case 4: {
            sort([](const ListNode<User> &left, const ListNode<User> &right) -> bool {
                return left.getData().getAddress() < right.getData().getAddress();
            });
            display();
            break;
        }
        case 5: {
            sort([](const ListNode<User> &left, const ListNode<User> &right) -> bool {
                return left.getData().getPostalCode() < right.getData().getPostalCode();
            });
            display();
            break;
        }
        case 6: {
            sort([](const ListNode<User> &left, const ListNode<User> &right) -> bool {
                return left.getData().getEMail() < right.getData().getEMail();
            });
            display();
            break;
        }
        case 7: {
            sort([](const ListNode<User> &left, const ListNode<User> &right) -> bool {
                return left.getData().getQqNum() < right.getData().getQqNum();
            });
            display();
            break;
        }
        case 8: {
            sort([](const ListNode<User> &left, const ListNode<User> &right) -> bool {
                return left.getData().getType() < right.getData().getType();
            });
            display();
            break;
        }
    }
}

void UserList::sort(bool (*cmp)(const ListNode<User>&, const ListNode<User>&)) {
    // ����ʵ�֣��ֽ׶����ò�������
    ListNode<User> *ptr = head;
    ListNode<User> *ptr_ = nullptr;
    ListNode<User> *ptr_tmp = nullptr;

    for(int i = 0; i < getSize() - 1; i ++) {
        ptr_ = ptr->getNext();
        ptr_tmp = ptr;

        for(int j = i + 1; j < getSize(); j ++) {
            if(cmp(*ptr_, *ptr_tmp)) {
                ptr_tmp = ptr_;
            }
            ptr_ = ptr_->getNext();
        }

        if(ptr != ptr_tmp) {
            swap(ptr, ptr_tmp);
            ptr = ptr_tmp;
            /* ���׵�ʵ�ַ���
            User tmp = ptr->getData();
            ptr->setData(ptr_tmp->getData());
            ptr_tmp->setData(tmp);
            */
        }

        ptr = ptr->getNext();
    }
}

void UserList::swap(ListNode<User> *left, ListNode<User> *right) {
    // ���������ڵ��ǰ�����
    head = left == head ? right: head;
    tail = right == tail ? left: tail;

    if(left->getNext() == right) {
        // �����Ľڵ�����
        ListNode<User> *prior = left->getPrior();
        ListNode<User> *next = right->getNext();

        left->setNext(next);
        if(next) {
            next->setPrior(left);
        }
        left->setPrior(right);

        right->setPrior(prior);
        if(prior) {
            prior->setNext(right);
        }
        right->setNext(left);
    } else {
        // �����Ľڵ㲻����
        if(left->getPrior()) {
            left->getPrior()->setNext(right);
        }
        ListNode<User> *prior = right->getPrior();
        prior->setNext(left);
        right->setPrior(left->getPrior());
        left->setPrior(prior);
        prior = nullptr;

        if(left->getNext()) {
            left->getNext()->setPrior(right);
        }
        ListNode<User> *next = right->getNext();
        next->setPrior(left);
        right->setNext(left->getNext());
        left->setNext(next);
        next = nullptr;
    }
}

void UserList::fetchNode() {
    // ͨ����ַʵ��ģ����ѯ
    std::cout << "�밴��ʽ����Ҫ��ѯ�ĵ�ַ��%��ʾ���ɸ��ַ���_��ʾ�����ַ���" << std::endl;
    std::string address;
    std::cin >> address;
    bool flag = true;
    ListNode<User> *ptr = head;
    while(ptr) {
        if(ptr->getData().getAddress().find(address) != std::string::npos) {
            std::cout << *ptr;
            flag = false;
        }
        ptr = ptr->getNext();
    }
    if(flag) {
        std::cout << "δ�ܲ鵽�й�����" << std::endl;
    }
}
