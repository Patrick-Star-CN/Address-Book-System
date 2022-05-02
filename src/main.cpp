#include "../include/userList.h"

int main() {
    UserList list;
    list.addNode();
    list.addNode();
    list.addNode();
    list.addNode();
    //list.fetchNode("1", "name");
    list.delNode("1", "name");
    list.display();
    system("pause");
    return 0;
}
