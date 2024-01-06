//
// Created by Small Kid on 1/6/24.
//

#include <gtest/gtest.h>
#include <fstream>
#include "../header/save.h"

class SaveTest : public ::testing::Test {
protected:
    std::string tempFilename;
    list addressList;
    Save* saveObj = new Save(addressList);

    void SetUp() override {
        // 为测试创建一个临时文件名
        tempFilename = "temp_test_file.txt";

        // 初始化 addressList
        addressList.l_size = 0;
    }

    void TearDown() override {
        // 删除测试文件
        std::filesystem::remove(tempFilename);
    }

    void createTempFileWithContent(const std::string& content) {
        std::ofstream outFile(tempFilename);
        outFile << content;
        outFile.close();
    }

    contacts readFileContent() {
        std::ifstream inFile(tempFilename);
        string line;

        getline(inFile, line);
        std::istringstream iss(line);
        contacts contact;
        std::getline(iss, contact.c_name, '\t');
        iss >> contact.c_sex;
        iss.ignore(); // 忽略制表符
        iss >> contact.c_age;
        iss.ignore(); // 忽略制表符
        std::getline(iss, contact.c_phoneNumber, '\t');
        std::getline(iss, contact.c_homeAddress);
        return contact;
    }
};

// 测试 SaveToFile 函数
TEST_F(SaveTest, SaveToFile) {
    // 准备一些数据
    contacts contact = {"Alice", 1, 30, "1234567890", "Alice Address"};
    addressList.l_Arr[addressList.l_size++] = contact;

    // 保存到文件
    saveObj->SaveToFile(tempFilename);

    // 验证文件内容
    contacts fileContent = readFileContent();
    EXPECT_EQ(fileContent.c_name, "Alice");
    EXPECT_EQ(fileContent.c_sex, 1);
    EXPECT_EQ(fileContent.c_age, 30);
    EXPECT_EQ(fileContent.c_phoneNumber, "1234567890");
    EXPECT_EQ(fileContent.c_homeAddress, "Alice Address");
}

// 测试 LoadFromFile 函数
TEST_F(SaveTest, LoadFromFile) {
    // 创建带有测试数据的临时文件
    createTempFileWithContent("Bob\t1\t25\t0987654321\tAnother Address\n");

    // 从文件加载
    saveObj->LoadFromFile(tempFilename);

    // 验证加载的数据
    EXPECT_EQ(saveObj->getList().l_size, 1);
    EXPECT_EQ(saveObj->getList().l_Arr[0].c_name, "Bob");

}

// 测试 ifFileExist 函数
TEST_F(SaveTest, IfFileExist) {
    // 确保文件不存在
    std::filesystem::remove(tempFilename);

    // 检查文件是否存在
    saveObj->ifFileExist(tempFilename);

    // 验证文件已创建
    EXPECT_TRUE(std::filesystem::exists(tempFilename));
}

