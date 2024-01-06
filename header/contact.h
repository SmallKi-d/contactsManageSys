//
// Created by Small Kid on 1/5/24.
//

#ifndef UNTITLED1_CONTACT_H
#define UNTITLED1_CONTACT_H

#endif //UNTITLED1_CONTACT_H

#include <string>
#include "structure.h"

using namespace std;

// 读取通讯录
void readContact(list *addressList);

// 写入通讯录
void writeContact(list *addressList);

//1.添加联系人函数
void addContact(list *addressList);

//2.显示联系人函数
void showContacts(list *addressList);

//通过姓名检测联系人是否存在,若存在，返回位置，不存在返回0
int ifExist(list *addressList, const std::string &name);

//3.删除联系人函数
void deleteContact(list *addressList);

//4.查找联系人函数
void findContact(list *addressList);

//5.修改联系人函数
void modifyContact(list *addressList);

//6.清空通讯录函数
void cleanList(list *addressList);