#pragma once
//˳��ջ�ĳ������stack.h
#ifndef _STACK_H_
#define _STACK_H_
//�������ֻ�ṩ�ӿ�
template<class T>
class Stack {
public:
	Stack() {};
	virtual void Push(const T& x) = 0;//��ջ
	virtual bool Pop(T& x) = 0;//��ջ
	virtual bool getTop(T& x)const = 0;//��ȡջ��Ԫ��
	virtual bool IsEmpty()const = 0;
	virtual int getSize()const = 0;
};



#endif