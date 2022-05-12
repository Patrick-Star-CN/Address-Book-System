#include "../include/file.h"
#include "../include/menu.h"

int main() {
    Menu menu;
    UserList list;
    int typeNum;
    File file("../data/data", ".txt");
    file.init(list);

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "欢迎使用通讯录管理系统" << std::endl;
    if(list[0].getData().getName().empty()) {
        std::cout << "请输入第一个用户信息以初始化通讯录系统" << std::endl;
        std::cin >> list[0];
        file.change(list);
    }

    menu.displayMainMenu();
    while(std::cin >> typeNum && typeNum) {
        switch (typeNum) {
            case 1: {
                std::cout << "----------------------------------------" << std::endl;
                file.add(list.addNode(std::cin));
                break;
            }
            case 2: {
                if(!list.getSize()) {
                    std::cout << "----------------------------------------" << std::endl;
                    std::cout << "当前链表为空" << std::endl;
                    break;
                }
                menu.displayFetchMenu();
                int typeNum_;
                bool flag = true;
                while(flag && std::cin >> typeNum_ && typeNum_) {
                    switch (typeNum_) {
                        case 1: {
                            std::cout << "----------------------------------------" << std::endl;
                            std::cout << "请输入想查询用户的姓名：";
                            std::string name;
                            std::cin >> name;
                            auto user = list.fetchNode(name, "name");
                            if (user) {
                                std::cout << user;
                            } else {
                                std::cout << "该用户不存在" << std::endl;
                            }
                            flag = false;
                            break;
                        }
                        case 2: {
                            std::cout << "----------------------------------------" << std::endl;
                            std::cout << "请输入想查询用户的电话：";
                            std::string phoneNum;
                            std::cin >> phoneNum;
                            auto user = list.fetchNode(phoneNum, "phoneNum");
                            if (user) {
                                std::cout << user;
                            } else {
                                std::cout << "该用户不存在" << std::endl;
                            }
                            flag = false;
                            break;
                        }
                        case 3: {
                            std::cout << "----------------------------------------" << std::endl;
                            list.fetchNode();
                            flag = false;
                            break;
                        }
                        case 4: {
                            std::cout << "----------------------------------------" << std::endl;
                            std::cout << "请输入目标类型：";
                            std::string type;
                            std::cin >> type;
                            list.fetchNode(type, "type");
                            flag = false;
                            break;
                        }
                        default: {
                            std::cout << "输入有误，请重新输入\n>";
                            break;
                        }
                    }
                }
                break;
            }
            case 3: {
                std::cout << "----------------------------------------" << std::endl;
                list.display();
                break;
            }
            case 4: {
                if(!list.getSize()) {
                    std::cout << "----------------------------------------" << std::endl;
                    std::cout << "当前链表为空" << std::endl;
                    break;
                }
                menu.displayChangeMenu();
                int typeNum_;
                bool flag = true;
                while(flag && std::cin >> typeNum_ && typeNum_) {
                    switch (typeNum_) {
                        case 1: {
                            std::cout << "----------------------------------------" << std::endl;
                            std::cout << "请输入想修改用户的姓名：";
                            std::string name;
                            std::cin >> name;
                            std::cout << "----------------------------------------" << std::endl;
                            list.changeNode(name, "name");
                            file.change(list);
                            flag = false;
                            break;
                        }
                        case 2: {
                            std::cout << "----------------------------------------" << std::endl;
                            std::cout << "请输入想修改用户的电话：";
                            std::string phoneNum;
                            std::cin >> phoneNum;
                            std::cout << "----------------------------------------" << std::endl;
                            list.changeNode(phoneNum, "phoneNum");
                            file.change(list);
                            flag = false;
                            break;
                        }
                        default: {
                            std::cout << "输入有误，请重新输入\n>";
                            break;
                        }
                    }
                }
                break;
            }
            case 5: {
                if(!list.getSize()) {
                    std::cout << "----------------------------------------" << std::endl;
                    std::cout << "当前链表为空" << std::endl;
                    break;
                }
                menu.displayDeleteMenu();
                int typeNum_;
                bool flag = true;
                while(flag && std::cin >> typeNum_ && typeNum_) {
                    switch (typeNum_) {
                        case 1: {
                            std::cout << "----------------------------------------" << std::endl;
                            std::cout << "请输入想删除用户的姓名：";
                            std::string name;
                            std::cin >> name;
                            list.delNode(name, "name");
                            file.change(list);
                            flag = false;
                            break;
                        }
                        case 2: {
                            std::cout << "----------------------------------------" << std::endl;
                            std::cout << "请输入想删除用户的电话：";
                            std::string phoneNum;
                            std::cin >> phoneNum;
                            std::cout << "----------------------------------------" << std::endl;
                            list.delNode(phoneNum, "phoneNum");
                            list.display();
                            file.change(list);
                            flag = false;
                            break;
                        }
                        default: {
                            std::cout << "输入有误，请重新输入\n>";
                            break;
                        }
                    }
                }
                break;
            }
            case 6: {
                if(!list.getSize()) {
                    std::cout << "----------------------------------------" << std::endl;
                    std::cout << "当前链表为空" << std::endl;
                    break;
                }
                std::cout << "----------------------------------------" << std::endl;
                list.sortNode();
                file.change(list);
                break;
            }
        }
        menu.displayMainMenu();
    }

    file.change(list);
    system("pause");
    return 0;
}
