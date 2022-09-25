#pragma once
#ifndef SEQSTACK_H_
#define SEQSTACK_H_

#include"stack.h"
#include<iostream>
#include<assert.h>
using namespace std;
template<class T>
class SeqStack :public Stack<T> {
public:
	SeqStack(int sz=50);//含参  这里带默认参数是为了控制maxSize
	~SeqStack() { delete[] elements; }
	void Push(const T& x);
	bool Pop(T& x);
	bool getTop(T& x)const;
	bool IsEmpty()const { return (top) == -1 ? true : false; };
	bool IsFull()const { return (top == maxSize - 1) ? true : false; };
	int getSize()const { return top + 1; };
	void MakeEmpty() { top = -1; };
	template<class T1>
	friend ostream& operator<<(ostream& os, SeqStack<T1>& s);
private:
	T* elements;//存放栈中元素的数组
	int top;//栈顶指针
	int maxSize;//栈中最大容量
	void overflowProcess();//处理栈溢出
};

template<class T>
SeqStack<T>::SeqStack(int sz) :top(-1), maxSize(sz) {
	//含参初始化，建立尺寸为sz的栈
	elements = new T[maxSize];//new[]
	assert(elements != nullptr);//断言:判断动态存储分配是否成功
}

const int stackIncreament = 20;
template<class T>
void SeqStack<T>::overflowProcess() {
	//函数作用为：扩展栈的存储空间
	cout << "溢出处理" << endl;
	T* newArray = new T[maxSize + stackIncreament];
	if (newArray == nullptr) {
		cerr << "存储分配失败" << endl;
		exit(1);
	}
	for (int i = 0; i <= top; i++)
	{
		newArray[i] = elements[i];
	}
	maxSize = maxSize + stackIncreament;
	delete[]  elements;
	elements = newArray;
	newArray = nullptr;
	cout << "处理完毕" << endl;
}

template<class T>
void SeqStack<T>::Push(const T& x)
{
	//入栈 先判断是否栈满
	if (IsFull() == true)
		overflowProcess();
	elements[++top] = x;
}

template<class T>
bool SeqStack<T>::Pop(T& x)
{
	//出栈，先判断是否为空
	if (IsEmpty() == true)return false;
	x = elements[top--];
	return true;
}

template<class T>
bool SeqStack<T>::getTop(T& x)const {
	//读取栈顶 
	if (IsEmpty() == true)return false;
	x = elements[top];
	return true;
}

template<class T>
ostream& operator<<(ostream& os, SeqStack<T>& s)
{
	os << "top=" << s.top<< endl;
	for (int i = 0; i <= s.top; ++i)
		os << i << ":" << s.elements[i] <<endl;
	return os;
}

#endif