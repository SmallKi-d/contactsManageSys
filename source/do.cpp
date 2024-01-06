//
// Created by Small Kid on 1/5/24.
//
#include <iostream>
#include <string>
#include "../header/contact.h"
#include "../header/menu.h"
using namespace std;

//定义判断用户行为函数
void whatDo(list addressList,const string& uDo){

    string exitNow = ":q";  //退出
    string backMenu = ":b";  //返回菜单
    if (uDo == exitNow){
        cout << "欢迎下次使用！";
        exit(0);
    }else if (uDo == backMenu){
        showMenu(std::move(addressList));
    }
}
