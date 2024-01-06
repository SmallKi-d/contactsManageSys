//
// Created by Small Kid on 1/6/24.
//
#include <cstdlib>
#include "../header/clear.h"

void clear() {
#if defined(_WIN32) || defined(_WIN64)
    // Windows 系统
    std::system("pause");
    std::system("cls");

#elif defined(__APPLE__) || defined(__linux__) || defined(__unix__)
    // macOS 和 Linux 系统
    std::system("read -p '按任意键继续...' var");
    std::system("clear");

#else
    // 不支持的操作系统
    std::cerr << "WARNING: Unsupported operating system" << std::endl;
#endif

}

