//
// Created by Small Kid on 1/5/24.
//
#include <iostream>
#include "../header/contact.h"
#include "../header/do.h"

void showMenu(list addressList){
    string select;//创建用户输入变量

    while (true){
        //清空终端
        system("clear");
        //菜单界面
        cout << "\t******************************" << endl;
        cout << "\t*******   1.添加联系人   *******" << endl;
        cout << "\t*******   2.显示联系人   *******" << endl;
        cout << "\t*******   3.删除联系人   *******" << endl;
        cout << "\t*******   4.查找联系人   *******" << endl;
        cout << "\t*******   5.修改联系人   *******" << endl;
        cout << "\t*******   6.清空联系人   *******" << endl;
        cout << "\t****   0.退出通讯录(默认)   ****" << endl;
        cout << "\t*****输入数字选择欲使用的功能*****" << endl;
        cout << "\t******************************" << endl;
        cin  >> select;

        string A = whatDo(addressList, select);


        //菜单选择
        switch (stoi(A)) {
            case 1:         //1.add
                addContact(&addressList);
                break;
            case 2:         //2.show
                showContacts(&addressList);
                break;
            case 3:         //3.delete
                deleteContact(&addressList);
                break;
            case 4:         //4.find
                findContact(&addressList);
                break;
            case 5:         //5.change
                modifyContact(&addressList);
                break;
            case 6:         //6.clear
                cleanList(&addressList);
                break;
            case 9:
                showMenu(addressList);
            case 0:         //7.exit
                writeContact(&addressList);
                cout << "欢迎下次使用！";
                exit(0);
            default:
                cout << "非法请求！" << endl;
                showMenu(addressList);
        }

    }

}