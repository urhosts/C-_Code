/*************************************************************************
	> File Name: Strings.h
	> Author: hosts
	> Mail: hosts@gsxio.com
	> Created Time: Wed 28 Jun 2017 11:13:50 AM CST
 ************************************************************************/

#ifndef _STRINGS_H
#define _STRINGS_H

#include <iostream>
#include <string.h>

using namespace std;

class String
{
public:
    //构造函数
    //为什么要+1,这与strlen函数求长度有关，+1存放结束符\0
    String(const char* str)
        :_str(new char[strlen(str) + 1])
    {
        strcpy(_str, str);
    }

    //拷贝构造函数
    String(const String& s)
        :_str(new char[strlen(s._str) + 1])
    {
        strcpy(_str, s._str);
    }

    //赋值运算符的重载，现代写法
    String& operator=(String& s)
    {
        std:swap(s._str, this->_str);
        return *this;
    }

    //析构函数
    ~String()
    {
        if(_str == NULL)
        {
            delete[] _str;
            _str = NULL;
        }
    }

    char *c_str()
    {
        return _str;
    }

    size_t Size()
    {
        return strlen(_str);
    }
private:
    char* _str;
};

#endif
