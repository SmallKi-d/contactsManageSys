//
// Created by Small Kid on 1/5/24.
//

#ifndef UNTITLED1_STRUCTURE_H
#define UNTITLED1_STRUCTURE_H

#endif //UNTITLED1_STRUCTURE_H
#pragma once

#include <string>

#define MAX 1000

using namespace std;

//联系人结构体,前缀 c_
struct contacts{
    string c_name;          //姓名
    int c_sex{};              //性别
    int c_age{};              //年龄
    string c_phoneNumber;   //联系电话
    string c_homeAddress;   //家庭住址
};

//通讯录结构体, 前缀 l_
struct list{
    struct contacts l_Arr[MAX];//通讯录保存的联系人
    int l_size{};
};