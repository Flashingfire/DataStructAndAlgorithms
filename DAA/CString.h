#pragma once
//�� ��������
#ifndef _CSTRING_H_
#define CSTRING_H_
#include<assert.h>
#include<iostream>
using namespace std;
//���ö�̬���ȴ� ���һλΪ������\0
class CString {
public:
	CString(const char* val = nullptr);//��ͨ���캯��
	CString(const CString& val);//����
	~CString();

	CString& operator=(const CString& val);//��ֵ����
	CString operator+ (const CString & val);
	CString& operator +=(const CString& val);
	char& operator[](int n)const;//�±������
	bool operator==(const CString& val)const;
	int size()const;
	const char* c_str()const;//string ת const char*
	//������������
	friend  ostream& operator<<(ostream& os, const CString& str);

private:
	char* data;//�ַ�ָ��
	int length;//�ַ���ʵ�ʳ���
};

CString::CString(const char* val)
{
	if (val != nullptr) {
		length = strlen(val);
		data = new char[length + 1];//�����ڴ�ռ�
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
		return *this;//����ֵ
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
	strcpy(tmpString.data, data);//�ַ�������
	strcat(tmpString.data, val.c_str());//�ַ���ƴ��
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