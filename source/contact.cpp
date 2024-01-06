//
// Created by Small Kid on 1/5/24.
//
#include <iostream>
#include <string>
#include "../header/contact.h"
#include "../header/isPhone.h"
#include "../header/do.h"
#include "../header/save.h"


using namespace std;

// 读取通讯录
void loadContact(list *addressList){
    Save* save = new Save(*addressList);
    save -> ifFileExist("contact.txt");
    save -> LoadFromFile("contact.txt", addressList);
    delete save;
}

//1.添加联系人函数
void addContacts(list *addressList){
    //判断通讯录是否已满
    if (addressList->l_size == MAX){
        //返回通讯录已满提示并回到菜单
        cout << "通讯录已满！";
        cout << "请按任意键继续。" << endl;
        system("read");
        system("clear");
        return;
    } else{
        //添加具体联系人

        //姓名
        string name;
        cout << "请输入姓名: ";
        cin >> name;
        whatDo(*addressList,name);
        addressList -> l_Arr[addressList->l_size].c_name = name;

        //性别
        cout << "请输入性别：" << endl;
        cout << "1 --- 男" << endl;
        cout << "2 --- 女" << endl;
        int sex = 0;
        while (true){           //输入正确跳出循环
            cin >> sex;
            whatDo(*addressList, to_string(sex));
            if (sex == 1 || sex == 2){
                addressList -> l_Arr[addressList->l_size].c_sex = sex;
                break;
            } else {
                cin.clear();
                cin.ignore();
            }
            cout << "输入有误，请重新输入！" << endl;
        }

        //年龄
        cout << "请输入年龄：";
        int age = -1;
        while (true){
            cin >> age;
            whatDo(*addressList, to_string(age));
            if (age > 0 && age < 100){
                addressList ->l_Arr[addressList->l_size].c_age = age;
                break;
            }
            cout << "输入有误，请重新输入！" << endl;
        }

        //电话
        cout << "请输入11位联系电话(+86)：";
        string phoneNumber;
        while (true){
            cin >> phoneNumber;
            whatDo(*addressList, phoneNumber);
            if (isPhoneNum(phoneNumber)){
                addressList ->l_Arr[addressList->l_size].c_phoneNumber = phoneNumber;
                break;
            } else{
                cout << "输入有误，请检查手机号码是否正确！" << endl;
            }
        }

        //住址
        cout << "请输入家庭住址： " << endl;
        string homeAddress;
        cin >> homeAddress;
        whatDo(*addressList, homeAddress);
        addressList -> l_Arr[addressList -> l_size].c_homeAddress = homeAddress;

        //写入文件
        Save* save = new Save(*addressList);
        save->SaveToFile("contact.txt");
        delete save;

        //更新通讯录人数
        addressList -> l_size++;

        cout << "添加成功！请按任意键继续。" << endl;
        system("read");
        system("clear");
    }
}

//2.显示联系人函数
void showContacts(list *addressList){
    //判断通讯录中人数是否为0，若为0提示为空
    if (addressList -> l_size == 0){
        cout << "当前的记录为空，请返回主页添加联系人" << endl;
        cout << "请按任意键继续。" << endl;
        system("read");
        system("clear");
    } else{
        for (int i = 0; i < addressList -> l_size; ++i) {
            cout << "姓名：" << addressList -> l_Arr[i].c_name << "\t";
            cout << "年龄：" << addressList -> l_Arr[i].c_age << "\t";
            cout << "姓别：" << (addressList -> l_Arr[i].c_sex == 1 ? "男":"女") << "\t";
            cout << "手机号码：" << addressList -> l_Arr[i].c_phoneNumber << "\t";
            cout << "地址：" << addressList -> l_Arr[i].c_homeAddress << endl;
        }
        cout << "请按任意键继续。" << endl;
        system("read");
        system("clear");
    }
}

//通过姓名检测联系人是否存在,若存在，返回位置，不存在返回-1
int ifExist (list *addressList,const string& name){
    for (int i = 0; i < addressList->l_size; i++) {
        if (addressList->l_Arr[i].c_name == name){
            return i;
        }
    }
    return -1;
}

//3.删除联系人函数
void deleteContact(list *addressList){
    cout << "请输入您要删除的联系人姓名" << endl;

    //请求用户输入联系人姓名
    string name;
    cin >> name;
    whatDo(*addressList,name);

    //使用 ifExist 判断联系人是否存在
    int ret = ifExist(addressList,name);
    if (ret != -1){

        //查到此人，并进行删除
        for (int i = ret; i < addressList -> l_size; ++i) {
            //数据前移
            addressList -> l_Arr[i] = addressList -> l_Arr[ i + 1];
        }

        //更新通讯录中人数
        addressList ->l_size--;

        cout << "删除成功！" << endl;
    } else{
        cout << "未找到该联系人，请检查您的输入！" << endl;
    }
    cout << "请按任意键继续。" << endl;
    system("read");
    system("clear");
}

//4.查找联系人函数
void findContact(list *addressList){
    cout << "请输入您要查找的联系人姓名：";
    string name;
    cin >> name;
    whatDo(*addressList,name);

    //判断是否存在
    int ret = ifExist(addressList,name);

    if (ret != -1){
        cout << "姓名：" << addressList->l_Arr[ret].c_name << "\t";
        cout << "年龄：" << addressList->l_Arr[ret].c_sex << "\t";
        cout << "姓别：" << (addressList -> l_Arr[ret].c_sex == 1 ? "男":"女")  << "\t";
        cout << "电话号码：" << addressList->l_Arr[ret].c_phoneNumber << "\t";
        cout << "家庭住址：" << addressList->l_Arr[ret].c_homeAddress << endl;
    } else{
        cout << "查无此人";
    }
    cout << "请按任意键继续。";
    system("read");
    system("clear");
}

//5.修改联系人函数
void modifyContact(list *addressList){
    while (true){
        cout << "请输入您要修改的联系人姓名:" << endl;
        cout << ":b.回到主菜单（:为英文字符）" << endl;
        string name;
        cin >> name;
        whatDo(*addressList,name);

        //判断是否存在
        int ret = ifExist(addressList,name);

        //若存在，请求用户修改对应信息
        if(ret != -1){
            cout << "1.姓名：" << addressList->l_Arr[ret].c_name << endl;
            cout << "2.年龄：" << addressList->l_Arr[ret].c_sex << endl;
            cout << "3.姓别：" << (addressList -> l_Arr[ret].c_sex == 1 ? "男":"女")  << endl;
            cout << "4.电话号码：" << addressList->l_Arr[ret].c_phoneNumber << endl;
            cout << "5.家庭住址：" << addressList->l_Arr[ret].c_homeAddress << endl;
            cout << "0.退出" << endl;
            cout << "请输入您要修改的内容编号（默认为0）：";
            int select = 0;
            cin >> select;
            whatDo(*addressList, to_string(select));
            switch (select) {
                case 1:     //姓名
                {
                    string fixedName;
                    cout << "请输入姓名：";
                    cin >> fixedName;
                    whatDo(*addressList,fixedName);
                    addressList->l_Arr[ret].c_name = fixedName;
                    break;
                }
                case 2:     //年龄
                {
                    cout << "请输入年龄：";
                    int age = -1;
                    while (true){
                        cin >> age;
                        whatDo(*addressList, to_string(age));
                        if (age > 0 && age < 100){
                            addressList ->l_Arr[ret].c_age = age;
                            break;
                        }
                        cout << "输入有误，请重新输入！" << endl;
                    }
                    break;
                }
                case 3:     //性别
                {
                    int sex = 0;
                    cout << "请输入性别代号：";
                    cout << "1 --- 男" << endl;
                    cout << "2 --- 女" << endl;
                    while (true){           //输入正确跳出循环
                        cin >> sex;
                        whatDo(*addressList, to_string(sex));
                        if (sex == 1 || sex == 2){
                            addressList -> l_Arr[ret].c_sex = sex;
                            break;
                        } else {
                            cin.clear();
                            cin.ignore();
                        }
                        cout << "输入有误，请重新输入！" << endl;
                    }
                    break;
                }
                case 4:     //电话号码
                {
                    cout << "请输入11位联系电话(+86)：";
                    string phoneNumber;
                    while (true){
                        cin >> phoneNumber;
                        whatDo(*addressList, phoneNumber);
                        if (isPhoneNum(phoneNumber)){
                            addressList ->l_Arr[ret].c_phoneNumber = phoneNumber;
                            break;
                        } else{
                            cout << "输入有误，请检查手机号码是否正确！" << endl;
                        }
                    }
                    break;
                }
                case 5:     //住址
                {
                    cout << "请输入家庭住址： " << endl;
                    string homeAddress;
                    cin >> homeAddress;
                    whatDo(*addressList, homeAddress);
                    addressList -> l_Arr[ret].c_homeAddress = homeAddress;
                    break;
                }
                case 0:
                {
                    break;
                }
                default:
                {
                    cout << "非法请求！" << endl;
                    continue;
                }
            }
            break;
        }else{
            cout << "查无此人，请按任意键继续" << endl;
            system("read");
            system("clear");
        }
    }

    cout << "按任意键退回主菜单。" << endl;
    system("read");
    system("clear");
}

//6.清空通讯录函数
void cleanList(list *addressList){
    addressList->l_size = 0;
    system("read");
    system("clean");
}