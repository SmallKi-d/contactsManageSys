//
// Created by Small Kid on 1/5/24.
//
#include <iostream>
#include <string>
#include "../header/contact.h"
#include "../header/menu.h"
#include "../header/clear.h"
using namespace std;

//定义判断用户行为函数
string whatDo(list addressList,const string& uDo){

    string exitNow = ":q";  //退出
    string backMenu = ":b";  //返回菜单
    string version = ":v";
    string help = ":h";

    if (uDo == exitNow){
        writeContact(&addressList);
        cout << "欢迎下次使用！";
        exit(0);
    } else if (uDo == backMenu){
        showMenu(std::move(addressList));
    } else if (uDo == version){
        cout << "v0.0.1" << endl;
        clear();
        return to_string(9);
    } else if (uDo == help){
        cout << "\t主菜单输入数字选择欲使用的功能" << endl;
        cout << ":b\t" << "返回主菜单" << endl;
        cout << ":v\t" << "显示版本号" << endl;
        cout << ":h\t" << "显示帮助" << endl;
        cout << ":q\t" << "退出系统" << endl;
        clear();
        return to_string(9);
    }

    return uDo;
}
