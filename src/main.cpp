#include "../include/admin.h"
#include "../include/list.h"



int main() {
    Admin admin;
    List<User> list;
    list.addNode();
    list.addNode();
    cout << list[0];
    cout << list[1];
    system("pause");
    return 0;
}
