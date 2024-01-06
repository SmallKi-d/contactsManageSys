cmake_minimum_required(VERSION 3.20)
project(contactsManageSys)

set(CMAKE_CXX_STANDARD 17)

add_executable(contactsManageSys main.cpp
        header/contact.h
        source/contact.cpp
        header/menu.h
        source/menu.cpp
        header/save.h
        source/save.cpp
        header/isPhone.h
        source/isPhone.cpp
        header/do.h
        source/do.cpp
        header/structure.h
        header/clear.h
        source/clear.cpp
)

add_subdirectory(test)