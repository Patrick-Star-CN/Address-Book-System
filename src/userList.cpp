//
// �û������������ʵ���ļ�
// Created by 15928 on 2022/4/28.
//

#include "../include/userList.h"

static ListNode<User> empty(User("empty"));  // �ն���

ListNode<User> &UserList::fetchNode(const std::string& context, const std::string& type) {
    // ��ѯ����,type���Ʋ�ѯ�ķ�����֧�����������ֻ��š����Ͳ�ѯ
    ListNode<User> *ptr = head;

    if(type == "phoneNum") {
        while(ptr) {
            if(ptr->getData().getPhoneNum() == context) {
                return *ptr;
            }
            ptr = ptr->getNext();
        }
    } else if(type == "name") {
        // �����������
        int num = 0;
        ListNode<User> *ptr_[getSize()];
        while(ptr) {
            if(ptr->getData().getName() == context) {
                ptr_[num] = ptr;
                if(num == 1) {
                    std::cout << "��ѯ������û����������Ӧ�û�ǰ�ı�Ž���ѡ��" << std::endl;
                    std::cout << "NO.1" << std::endl << *ptr_[0];
                    std::cout << "NO.2" << std::endl << *ptr;
                } else {
                    std::cout << "NO." << (num + 1) << std::endl << *ptr;
                }
                num ++;
            }
            ptr = ptr->getNext();
        }
        if(num > 1) {
            int val;
            std::cin >> val;
            if(val <= num) {
                return *ptr_[val - 1];
            } else {
                return *ptr_[num - 1];
            }
        } else {
            return *ptr_[0];
        }
    } else if(type == "type") {
        while(ptr) {
            if(ptr->getData().getType() == context) {
                std::cout << *ptr;
            }
            ptr = ptr->getNext();
        }
    }
    return empty;
}

void UserList::delNode(const std::string& context, const std::string& type) {
    // ɾ�����ܣ�type���Ʋ�ѯ�ķ�����֧�����������ֻ��Ų�ѯ
    ListNode<User> *ptr = &fetchNode(context, type);
    if(ptr->getData().getPhoneNum() == "empty") {
        std::cout << "�����ڸ��û�" << std::endl;std::cout << "�����ڸ��û�" << std::endl;
        return;
    }
    ListNode<User> *ptr_ = ptr->getPrior();

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
}

void UserList::changeNode(std::string context, const std::string& type) {
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
                    Address address;
                    std::cin >> address;
                    if(type == "name") {
                        fetchNode(context, "name").getData().setAddress(address);
                    } else if(type == "phoneNum") {
                        fetchNode(context, "phoneNum").getData().setAddress(address);
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
                        if (regex_match(temp, std::regex(R"(^\w+([-+.]\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*$)"))) {
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
                default: {
                    std::cout << "������������������:";
                    break;
                }
            }
            std::cout << "��������Ҫ�ı�����������" << std::endl;
        }
    } else {
        // ��ѯ���ݳ�������
        std::cout << "δ���ҵ����û�" << std::endl;
    }
}

void UserList::sortNode() {
    // ������
    std::cout << "����������ؼ��ʵı��" << std::endl
              << "1: ����" << std::endl
              << "2: �Ա�" << std::endl
              << "3: �绰" << std::endl
              << "4: �ʱ�" << std::endl
              << "5: ����" << std::endl
              << "6: QQ��" << std::endl
              << "7: ���" << std::endl;
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
                return left.getData().getPostalCode() < right.getData().getPostalCode();
            });
            display();
            break;
        }
        case 5: {
            sort([](const ListNode<User> &left, const ListNode<User> &right) -> bool {
                return left.getData().getEMail() < right.getData().getEMail();
            });
            display();
            break;
        }
        case 6: {
            sort([](const ListNode<User> &left, const ListNode<User> &right) -> bool {
                return left.getData().getQqNum() < right.getData().getQqNum();
            });
            display();
            break;
        }
        case 7: {
            sort([](const ListNode<User> &left, const ListNode<User> &right) -> bool {
                return left.getData().getType() < right.getData().getType();
            });
            display();
            break;
        }
        default: {
            std::cout << "��������" << std::endl;
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
    Address address;
    ListNode<User> *ptr = head;
    bool flag = true;

    std::cout << "������Ŀ���ַ�����ձ�ʾ��λ�õ��κ����������" << std::endl;
    std::cin >> address;
    while(ptr) {
        if (address.getTown().empty()) {
            if ((address.getProvince().empty() || address.getProvince() == ptr->getData().getAddress().getProvince())
                && (address.getCity().empty() || address.getCity() == ptr->getData().getAddress().getCity())
                &&
                (address.getDistrict().empty() || address.getDistrict() == ptr->getData().getAddress().getDistrict())) {
                std::cout << *ptr;
                flag = false;
            }
        } else {
            if ((address.getProvince().empty() || address.getProvince() == ptr->getData().getAddress().getProvince())
                && (address.getCity().empty() || address.getCity() == ptr->getData().getAddress().getCity())
                && (address.getDistrict().empty() || address.getDistrict() == ptr->getData().getAddress().getDistrict())
                && address.getTown() == ptr->getData().getAddress().getTown()) {
                std::cout << *ptr;
                flag = false;
            }
        }
        ptr = ptr->getNext();
    }
    if(flag) {
        std::cout << "δ�ܲ�ѯ������Ҫ����û�" << std::endl;
    }
}
