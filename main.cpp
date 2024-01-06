#include "header/contact.h"
#include "header/menu.h"

using namespace std;

int main() {
    //创建通讯录结构体变量
    struct list addressList;

    //初始化通讯录中当前人员个数
    addressList.l_size = 0;

    //读取文件通讯录
    loadContact(&addressList);

    //菜单调用
    showMenu(addressList);

    return 0;
}

