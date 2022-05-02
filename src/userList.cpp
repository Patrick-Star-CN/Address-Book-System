//
// 用户数据链表类的实现文件
// Created by 15928 on 2022/4/28.
//

#include "../include/userList.h"

static ListNode<User> empty(User("empty"));  // 空对象

ListNode<User> &UserList::fetchNode(std::string context, std::string type) {
    // 查询功能
    ListNode<User> *ptr = head;
    while(ptr->getNext()) {
        if(type == "name" && ptr->getData().getName() == context
           || type == "phoneNum" && ptr->getData().getPhoneNum() == context) {
            return *ptr;
        }
        ptr = ptr->getNext();
    }

    //最后的节点为所需节点
    if(type == "name" && ptr->getData().getName() == context
       || type == "phoneNum" && ptr->getData().getPhoneNum() == context) {
        return *ptr;
    }
    return empty;
}

std::string UserList::delNode(std::string context, std::string type) {
    // 删除功能，type控制查询的方法，支持用姓名与手机号查询
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

    //最后的节点为所需节点
    if(type == "name" && ptr->getData().getName() != context && !ptr->getNext()
       || type == "phoneNum" && ptr->getData().getPhoneNum() != context && !ptr->getNext()) {
        return "USER_ERROR";
    }

    if(ptr_ && ptr->getNext()) {
        ptr_->setNext(ptr->getNext());
        ptr->getNext()->setPrior(ptr_);
    } else if(ptr_) {
        //删尾节点
        ptr_->setNext(nullptr);
        tail = ptr_;
    } else if(ptr->getNext()) {
        //删头节点
        ptr->getNext()->setPrior(nullptr);
        head = ptr->getNext();
    } else {
        //删链表唯一节点
        tail = nullptr;
        head = nullptr;
    }

    -- size;
    delete ptr;
    ptr = nullptr;
    return "OK";
}

std::string UserList::changeNode(std::string context, std::string type) {
    // 修改功能，type控制查询的方法，支持用姓名与手机号修改
    if(type == "name" && fetchNode(context, "name").getData().getPhoneNum() != empty.getData().getPhoneNum()
       || type == "phoneNum" && fetchNode(context, "phoneNum").getData().getPhoneNum() != empty.getData().getPhoneNum()) {
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
                    if(type == "name") {
                        fetchNode(context, "name").getData().setName(temp);
                        context = temp;
                    } else if(type == "phoneNum") {
                        fetchNode(context, "phoneNum").getData().setName(temp);
                    }
                    break;
                }
                case 2: {
                    std::cout << "请输入新的性别:";
                    while(std::cin >> temp) {
                        if (temp == "男" || temp == "女" || temp == "male" || temp == "female") {
                            if(type == "name") {
                                fetchNode(context, "name").getData().setSex(temp);
                            } else if(type == "phoneNum") {
                                fetchNode(context, "phoneNum").getData().setSex(temp);
                            }
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
                            if(type == "name") {
                                fetchNode(context, "name").getData().setPhoneNum(temp);
                            } else if(type == "phoneNum") {
                                fetchNode(context, "phoneNum").getData().setPhoneNum(temp);
                                context = temp;
                            }
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
                    std::cout << "请输入新的邮编:";
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
                            std::cout << "输入的邮政编码格式非法，请重新输入:";
                        }
                    }
                }
                case 6: {
                    std::cout << "请输入新的邮箱:";
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
                            std::cout << "输入的邮箱地址格式非法，请重新输入:";
                        }
                    }
                }
                case 7: {
                    std::cout << "请输入新的QQ号:";
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
                            std::cout << "输入的QQ号格式非法，请重新输入:";
                        }
                    }
                }
                case 8: {
                    std::cout << "请输入新的类型:";
                    std::cin >> temp;
                    if(type == "name") {
                        fetchNode(context, "name").getData().setType("");
                    } else if(type == "phoneNum") {
                        fetchNode(context, "phoneNum").getData().setType("");
                    }
                    break;
                }
            }
            std::cout << "请输入需要改变的数据名编号" << std::endl;
        }
        return "OK";
    } else {
        // 查询数据出错的情况
        return "ERROR";
    }
}

void UserList::sortNode() {
    // 排序功能
    std::cout << "请输入排序关键词的编号" << std::endl
              << "1: 姓名" << std::endl
              << "2: 性别" << std::endl
              << "3: 电话" << std::endl
              << "4: 地址" << std::endl
              << "5: 邮编" << std::endl
              << "6: 邮箱" << std::endl
              << "7: QQ号" << std::endl
              << "8: 类别" << std::endl;
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
    // 排序实现，现阶段利用插入排序
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
            /* 简易的实现方法
            User tmp = ptr->getData();
            ptr->setData(ptr_tmp->getData());
            ptr_tmp->setData(tmp);
            */
        }

        ptr = ptr->getNext();
    }
}

void UserList::swap(ListNode<User> *left, ListNode<User> *right) {
    // 交换两个节点的前后关联
    head = left == head ? right: head;
    tail = right == tail ? left: tail;

    if(left->getNext() == right) {
        // 交换的节点相邻
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
        // 交换的节点不相邻
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
    // 通过地址实现模糊查询
    std::cout << "请按格式输入要查询的地址，%表示若干个字符，_表示单个字符：" << std::endl;
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
        std::cout << "未能查到有关数据" << std::endl;
    }
}
