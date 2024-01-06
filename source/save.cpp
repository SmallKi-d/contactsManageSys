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
    ofstream outFile(filename);

    //格式化
    outFile << "\t" << l_.l_Arr[l_.l_size].c_name << "\t" <<  l_.l_Arr[l_.l_size].c_sex << "\t" << l_.l_Arr[l_.l_size].c_age
        << "\t" << l_.l_Arr[l_.l_size].c_phoneNumber << "\t" << l_.l_Arr[l_.l_size].c_homeAddress << endl;

    outFile.close();
}

void Save::LoadFromFile(const std::string &filename, list *addressList) {
//    ifstream inFile(filename);
//    string line;
//
//    // 判断是否能打开文件
//    if (!inFile.is_open()) {
//        std::cerr << "无法打开文件" << std::endl;
//        return;
//    }
//
//    // 循环读文件的每一行
//    while (getline(inFile, line)) {
//        std::istringstream iss(line);
//        // 拆分整行字符串
//        if (!(iss >> addressList -> l_Arr[addressList->l_size].c_name)) {
//            break;
//        }
//
//    }
//
//    inFile.close();
}

void Save::ifFileExist(const std::string &filename) {
    bool exists = __fs::filesystem::exists(filename);
    if (!exists){
        cerr << "文件不存在, 正在生成通讯录文件..." << endl;
        // 等待 3s ，防止程序跑得过快
        this_thread::sleep_for(chrono::seconds(3));

        ofstream outFile(filename);
    }
}

