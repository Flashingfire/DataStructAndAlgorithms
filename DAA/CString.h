#pragma once
//串 数据类型
#ifndef _CSTRING_H_
#define CSTRING_H_
#include<assert.h>
#include<iostream>
using namespace std;
//采用动态长度串 最后一位为结束符\0
class CString {
public:
	CString(const char* val = nullptr);//普通构造函数
	CString(const CString& val);//拷贝
	~CString();

	CString& operator=(const CString& val);//赋值运算
	CString operator+ (const CString & val);
	CString& operator +=(const CString& val);
	char& operator[](int n)const;//下标操作符
	bool operator==(const CString& val)const;
	int size()const;
	const char* c_str()const;//string 转 const char*
	//重载输出运算符
	friend  ostream& operator<<(ostream& os, const CString& str);

private:
	char* data;//字符指针
	int length;//字符串实际长度
};

CString::CString(const char* val)
{
	if (val != nullptr) {
		length = strlen(val);
		data = new char[length + 1];//申请内存空间
		assert(nullptr != data);
		strcpy(data, val);
	}
	else {
		length = 0;
		data = new char[1];
		assert(nullptr != data);
		data[0] = '\0';
	}
}

CString::CString(const CString& val) {
	delete[] data;
	length = val.size();
	data = new char[length + 1];
	assert(nullptr != data);
	strcpy(data, val.c_str());
}

CString::~CString() {
	delete[] data;
	data = nullptr;
}

CString& CString::operator=(const CString& val) {
	if (this == &val)
		return *this;//自身赋值
	delete[]  data;
	length = val.size();
	data = new char[length + 1];
	assert(nullptr != data);
	strcpy(data, val.c_str());
	return *this;
}

CString CString::operator+(const CString& val) {
	CString tmpString;
	tmpString.length = length + val.size();
	tmpString.data = new char[tmpString.length + 1];
	strcpy(tmpString.data, data);//字符串拷贝
	strcat(tmpString.data, val.c_str());//字符串拼接
	return tmpString;
}

CString& CString::operator+=(const CString& val) {
	length += val.size();
	char* tmpdata = new char[length + 1];
	strcpy(tmpdata, data);
	strcat(tmpdata, val.c_str());
	delete[] data;
	data = tmpdata;
	return *this;
}

char& CString::operator[](int i)const {
	if (i >= length)
		return data[length - 1];
	else
		return data[i];
}

bool CString::operator==(const CString& val)const {
	if (length != val.size())
		return false;
	return strcmp(data, val.c_str()) ? false : true;
}

int CString::size()const
{
	return length;
}

const  char* CString::c_str()const
{
	return data;
}

ostream& operator<<(ostream& out, CString& str) {
	out << str.c_str();
	return out;
}

#endif