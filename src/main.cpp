#include "../include/admin.h"
#include "../include/userList.h"

int main() {
    UserList list;
    list.addNode();
    cout << list[0];
    cout << list.fetchNode("1");
    system("pause");
    return 0;
}
