//
// Created by Small Kid on 1/5/24.
//
#include <regex>
#include "../header/isPhone.h"


bool isPhoneNum(const string& phoneNum) {
    //判断是否为数字
    for (unsigned char i : phoneNum) {
        int tmp = (int) i;
        if (tmp >= 48 && tmp <= 57) {
            continue;
        } else {
            return false;
        }
    }
    //正则判断是否为联通运营商号码
    regex patternUnicom("(^1(3[0-2]|4[05]|5[56]|6[67]|7[0156]|8[56]|96)\\d{8}$)|(^170[7-9]\\d{7}$)");
    sregex_iterator posUnicom(phoneNum.cbegin(), phoneNum.cend(), patternUnicom);
    decltype(posUnicom) endUnicom;
    for (; posUnicom != endUnicom; ++posUnicom) {
        //判断长度
        string str = posUnicom->str();
        if (str.length() >= 11) {
            return true;
        } else {
            break;
        }
    }

    //正则判断是否为移动运营商号码
    regex patternCMobile("^134[0-8]\\d{7}$|^(?:13[5-9]|147|15[0-27-9]|178|1703|1705|1706|18[2-478])\\d{7,8}$");
    sregex_iterator posCMobile(phoneNum.cbegin(), phoneNum.cend(), patternCMobile);
    decltype(posCMobile) endCMobile;
    for (; posCMobile != endCMobile; ++posCMobile) {
        //判断长度
        string str = posCMobile->str();
        if (str.length() >= 11) {
            return true;
        } else {
            break;
        }
    }

    //正则判断是否为电信运营商号码
    regex patternTelcom("^(?:133|153|1700|1701|1702|177|173|18[019])\\d{7,8}$");
    sregex_iterator posTelcom(phoneNum.cbegin(), phoneNum.cend(), patternTelcom);
    decltype(posTelcom) endTelcom;
    for (; posTelcom != endTelcom; ++posTelcom) {
        //判断长度
        string str = posTelcom->str();
        if (str.length() >= 11) {
            return true;
        } else {
            break;
        }
    }
    return false;
}