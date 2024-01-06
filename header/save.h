//
// Created by Small Kid on 1/5/24.
//

#ifndef UNTITLED1_SAVE_H
#define UNTITLED1_SAVE_H

#endif //UNTITLED1_SAVE_H

#include <string>
#include "structure.h"

using namespace std;

// 用户数据文件操作
class Save{
public:
    // 防止隐式转换
    explicit Save(const list& l): l_(l){}

    // 保存到文件
    void SaveToFile(const string& filename);
    // 从文件读取
    void LoadFromFile(const string& filename, list *addressList);
    // 生成文件
    void ifFileExist(const string& filename);
private:
    list l_;
};