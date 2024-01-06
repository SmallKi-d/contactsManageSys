#include "../header/contact.h" // 替换为你的通讯录头文件
#include <gtest/gtest.h>

// 测试夹具，用于设置测试环境
class AddressBookTest : public ::testing::Test {
protected:
    list addressList;

    void SetUp() override {
        // 初始化通讯录
        addressList.l_size = 0;
    }

    void TearDown() override {
        // 清理工作
        cleanList(&addressList);
    }

    std::string getUserInput() {
        std::string input;
        std::getline(std::cin, input);
        return input;
    }
};

// 测试添加联系人
TEST_F(AddressBookTest, AddContact) {
    addContact(&addressList);

    // 创建一个 stringstream 对象用于模拟输入
    std::stringstream ss;
    ss.str("Name");

    // 保存原来的 cin buffer
    std::streambuf* orig_cin = std::cin.rdbuf();

    // 将 cin 的 buffer 指向 stringstream
    std::cin.rdbuf(ss.rdbuf());

    // 调用函数并检查结果
    std::string input = getUserInput();
    EXPECT_EQ(input, "");

    // 恢复原来的 cin buffer
    std::cin.rdbuf(orig_cin);
}

// 测试显示联系人
TEST_F(AddressBookTest, ShowContacts) {
    addContact(&addressList);
    // 这里假设 showContacts 只是打印输出，可能需要更复杂的方式来测试
    showContacts(&addressList);
    // 由于 showContacts 可能不返回任何东西，这里可能难以断言
}

// 测试联系人是否存在
TEST_F(AddressBookTest, CheckIfContactExists) {
    std::string name = "Alice";
    addContact(&addressList); // 假设添加了名为 Alice 的联系人
    int position = ifExist(&addressList, name);
    EXPECT_NE(0, position); // 如果存在，返回值不应该为0
}

// 测试删除联系人
TEST_F(AddressBookTest, DeleteContact) {
    addContact(&addressList);
    deleteContact(&addressList); // 假设删除了一个联系人
    EXPECT_EQ(0, addressList.l_size);
}

// 测试清空通讯录
TEST_F(AddressBookTest, ClearAddressBook) {
    addContact(&addressList);
    cleanList(&addressList);
    EXPECT_EQ(0, addressList.l_size);
}

