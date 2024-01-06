#include <gtest/gtest.h>
#include "../header/contact.h"
#include "../header/isPhone.h"
#include "../header/clear.h"
#include "../header/do.h"
#include "../header/menu.h"

#define MAX 1000

// 创建测试模型
class ContactsTest : public ::testing::Test {
protected:
    list addressList;

    void SetUp() override {
        addressList.l_size = 0;
    }

    void addDummyContact() {
        if (addressList.l_size < MAX) {
            // 添加一个虚拟的联系人
            addressList.l_Arr[addressList.l_size++] = {"Dummy", 1, 30, "1234567890", "Dummy Address"};
        }
    }
};

// 测试添加新联系人
TEST_F(ContactsTest, AddNewContact) {
    bool result = ContactLogic(&addressList, addressList.l_size, "Alice", 1, 30, "1234567890", "Alice Address");
    ASSERT_TRUE(result); // 应该成功添加
    ASSERT_EQ(addressList.l_size, 1); // 通讯录中应该有一个联系人
    ASSERT_EQ(addressList.l_Arr[0].c_name, "Alice"); // 检查联系人信息
    ASSERT_EQ(addressList.l_Arr[0].c_sex, 1);
    ASSERT_EQ(addressList.l_Arr[0].c_age, 30);
    ASSERT_EQ(addressList.l_Arr[0].c_phoneNumber, "1234567890");
    ASSERT_EQ(addressList.l_Arr[0].c_homeAddress, "Alice Address");
}

// 测试通讯录已满时的情况
TEST_F(ContactsTest, AddContactWhenFull) {
    // 填满通讯录
    for (int i = 0; i < MAX; ++i) {
        addressList.l_Arr[i] = {"Person" + std::to_string(i), 1, 30, "1234567890", "Address"};
        addressList.l_size++;
    }

    bool result = ContactLogic(&addressList, addressList.l_size, "Bob", 1, 25, "0987654321", "Another Address");
    ASSERT_FALSE(result); // 应该返回失败
    ASSERT_EQ(addressList.l_size, MAX); // 通讯录大小不应该变化
}

// 测试清空通讯录
TEST_F(ContactsTest, CleanAddressBook) {
    // 先添加一些虚拟联系人
    addDummyContact();
    addDummyContact();
    ASSERT_EQ(addressList.l_size, 2); // 确保通讯录不为空

    // 清空通讯录
    cleanList(&addressList);
    ASSERT_EQ(addressList.l_size, 0); // 验证通讯录是否被清空
}

// 手机号测试
TEST(IsPhoneNumTest, ValidNumbers) {
    // 随机生成手机号
    EXPECT_TRUE(isPhoneNum("13800138000")); // 有效的移动号码
    EXPECT_TRUE(isPhoneNum("15612345678")); // 有效的联通号码
    EXPECT_TRUE(isPhoneNum("13312345678")); // 有效的电信号码
    EXPECT_TRUE(isPhoneNum("17001234567")); // 有效的虚拟运营商号码
}

TEST(IsPhoneNumTest, InvalidNumbers) {
    EXPECT_FALSE(isPhoneNum("12345678900")); // 无效号码
    EXPECT_FALSE(isPhoneNum("abcdefghijk")); // 非数字字符串
    EXPECT_FALSE(isPhoneNum("1380013800"));  // 长度不足的号码
}

TEST(IsPhoneNumTest, EmptyString) {
    EXPECT_FALSE(isPhoneNum("")); // 空字符串
}

