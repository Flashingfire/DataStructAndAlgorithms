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
	SeqStack(int sz=50);//����  �����Ĭ�ϲ�����Ϊ�˿���maxSize
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
	T* elements;//���ջ��Ԫ�ص�����
	int top;//ջ��ָ��
	int maxSize;//ջ���������
	void overflowProcess();//����ջ���
};

template<class T>
SeqStack<T>::SeqStack(int sz) :top(-1), maxSize(sz) {
	//���γ�ʼ���������ߴ�Ϊsz��ջ
	elements = new T[maxSize];//new[]
	assert(elements != nullptr);//����:�ж϶�̬�洢�����Ƿ�ɹ�
}

const int stackIncreament = 20;
template<class T>
void SeqStack<T>::overflowProcess() {
	//��������Ϊ����չջ�Ĵ洢�ռ�
	cout << "�������" << endl;
	T* newArray = new T[maxSize + stackIncreament];
	if (newArray == nullptr) {
		cerr << "�洢����ʧ��" << endl;
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
	cout << "�������" << endl;
}

template<class T>
void SeqStack<T>::Push(const T& x)
{
	//��ջ ���ж��Ƿ�ջ��
	if (IsFull() == true)
		overflowProcess();
	elements[++top] = x;
}

template<class T>
bool SeqStack<T>::Pop(T& x)
{
	//��ջ�����ж��Ƿ�Ϊ��
	if (IsEmpty() == true)return false;
	x = elements[top--];
	return true;
}

template<class T>
bool SeqStack<T>::getTop(T& x)const {
	//��ȡջ�� 
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