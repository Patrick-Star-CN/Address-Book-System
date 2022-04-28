#include "../include/admin.h"
#include "../include/userList.h"

int main() {
    UserList list;
    list.addNode();
    //list.addNode();

    list.changeNode("1");
    //std::cin >> list[1];
    for(int i = 0; i < list.getSize(); ++ i) {
        std::cout << list[i] << std::endl;
    }
    system("pause");
    return 0;
}
