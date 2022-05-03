#include "../include/file.h"
#include "../include/menu.h"

int main() {
    Menu menu;
    UserList list;
    int typeNum;
    File file("../data/data", ".txt");
    file.init(list);

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "��ӭʹ��ͨѶ¼����ϵͳ" << std::endl;
    if(list[0].getData().getName().empty()) {
        std::cout << "�������һ���û���Ϣ�Գ�ʼ��ͨѶ¼ϵͳ" << std::endl;
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
                menu.displayFetchMenu();
                int typeNum_;
                std::cin >> typeNum_;
                switch (typeNum_) {
                    case 1: {
                        std::cout << "----------------------------------------" << std::endl;
                        std::cout << "���������ѯ�û���������";
                        std::string name;
                        std::cin >> name;
                        auto user = list.fetchNode(name, "name");
                        if(user) {
                            std::cout << user;
                        } else {
                            std::cout << "���û�������" << std::endl;
                        }
                        break;
                    }
                    case 2: {
                        std::cout << "----------------------------------------" << std::endl;
                        std::cout << "���������ѯ�û��ĵ绰��";
                        std::string phoneNum;
                        std::cin >> phoneNum;
                        auto user = list.fetchNode(phoneNum, "phoneNum");
                        if(user) {
                            std::cout << user;
                        } else {
                            std::cout << "���û�������" << std::endl;
                        }
                        break;
                    }
                    case 3: {
                        std::cout << "----------------------------------------" << std::endl;
                        list.fetchNode();
                        break;
                    }
                    case 4: {
                        std::cout << "----------------------------------------" << std::endl;
                        std::cout << "������Ŀ�����ͣ�";
                        std::string type;
                        std::cin >> type;
                        list.fetchNode(type, "type");
                        break;
                    }
                    case 0: {
                        break;
                    }
                    default: {
                        std::cout << "���������Զ������ϼ��˵�";
                        break;
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
                menu.displayChangeMenu();
                int typeNum_;
                std::cin >> typeNum_;
                switch (typeNum_) {
                    case 1: {
                        std::cout << "----------------------------------------" << std::endl;
                        std::cout << "���������޸��û���������";
                        std::string name;
                        std::cin >> name;
                        list.changeNode(name, "name");
                        std::cout << "----------------------------------------" << std::endl;
                        file.change(list);
                        break;
                    }
                    case 2: {
                        std::cout << "----------------------------------------" << std::endl;
                        std::cout << "���������޸��û��ĵ绰��";
                        std::string phoneNum;
                        std::cin >> phoneNum;
                        std::cout << "----------------------------------------" << std::endl;
                        list.changeNode(phoneNum, "phoneNum");
                        file.change(list);
                        break;
                    }
                    case 0: {
                        break;
                    }
                    default: {
                        std::cout << "���������Զ������ϼ��˵�";
                        break;
                    }
                }
                break;
            }
            case 5: {
                menu.displayDeleteMenu();
                int typeNum_;
                std::cin >> typeNum_;
                switch (typeNum_) {
                    case 1: {
                        std::cout << "----------------------------------------" << std::endl;
                        std::cout << "��������ɾ���û���������";
                        std::string name;
                        std::cin >> name;
                        list.delNode(name, "name");
                        file.change(list);
                        break;
                    }
                    case 2: {
                        std::cout << "----------------------------------------" << std::endl;
                        std::cout << "��������ɾ���û��ĵ绰��";
                        std::string phoneNum;
                        std::cin >> phoneNum;
                        std::cout << "----------------------------------------" << std::endl;
                        list.delNode(phoneNum, "phoneNum");
                        list.display();
                        file.change(list);
                        break;
                    }
                    case 0: {
                        break;
                    }
                    default: {
                        std::cout << "���������Զ������ϼ��˵�";
                        break;
                    }
                }
                break;
            }
            case 6: {
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
