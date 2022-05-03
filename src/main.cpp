#include "../include/file.h"

int main() {
    UserList list;
    File file("../data/data", ".txt");
    file.init(list);
    //file.add(list.addNode(std::cin));
    //list.addNode(std::cin);
    //list.addNode(std::cin);
    //list.addNode(std::cin);
    //list.fetchNode("1", "name");
    //list.delNode("1", "name");
    list.sortNode();
    file.change(list);
    list.display();
    system("pause");
    return 0;
}
