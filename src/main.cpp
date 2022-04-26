#include "../include/admin.h"
#include "../include/userList.h"

int main() {
    UserList list;
    list.addNode();
    list.addNode();
    list.addNode();
    std::cout << list.fetchNode("1") << std::endl;
    list.delNodeByPhoneNum("12345678901");
    std::cout << list.fetchNodeByPhoneNum("23456789012") << std::endl;
    //std::cin >> list[1];
    for(int i = 0; i < list.getSize(); ++ i) {
        std::cout << list[i] << std::endl;
    }
    system("pause");
    return 0;
}
