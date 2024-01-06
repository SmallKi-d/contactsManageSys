//
// Created by Small Kid on 1/5/24.
// 用户数据文件操作的实现
// 1. 保存到文件
// 2. 从文件读取
// 3. 生成文件
//
#include <iostream>
#include <fstream>
#include <ostream>
#include <filesystem>
#include <sstream>
#include <vector>
#include <thread>
#include <chrono>
#include "../header/save.h"

using namespace std;

void Save::SaveToFile(const std::string &filename) {

    // 默认模式清空文件内容
    ofstream outFile(filename);

    // 从内存中写入通讯录
    for(int index = 0;index != l_.l_size; index++){
        //格式化
        outFile << l_.l_Arr[index].c_name << "\t"
            <<  l_.l_Arr[index].c_sex << "\t"
            << l_.l_Arr[index].c_age<< "\t"
            << l_.l_Arr[index].c_phoneNumber << "\t"
            << l_.l_Arr[index].c_homeAddress << endl;
    }

    outFile.close();
}

void Save::LoadFromFile(const std::string &filename) {
    int index = 0;
    ifstream inFile(filename);
    string line;

    // 判断是否能打开文件
    if (!inFile.is_open()) {
        std::cerr << "无法打开文件: " << filename << std::endl;
        return;
    }

    // 循环读文件的每一行
    while (getline(inFile, line) && index < MAX) {
        std::istringstream iss(line);
        contacts contact;
        std::getline(iss, contact.c_name, '\t');
        iss >> contact.c_sex;
        iss.ignore(); // 忽略制表符
        iss >> contact.c_age;
        iss.ignore(); // 忽略制表符
        std::getline(iss, contact.c_phoneNumber, '\t');
        std::getline(iss, contact.c_homeAddress);
        l_.l_Arr[index++] = contact;
    }
    l_.l_size = index;

    inFile.close();
}

void Save::ifFileExist(const std::string &filename) {
    bool exists = filesystem::exists(filename);
    if (!exists){
        cerr << "文件不存在, 正在生成通讯录文件..." << endl;
        // 等待 3s ，防止程序跑得过快
        this_thread::sleep_for(chrono::seconds(3));

        ofstream outFile(filename);
    }
}

