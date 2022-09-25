#pragma once
//顺序栈的抽象基类stack.h
#ifndef _STACK_H_
#define _STACK_H_
//这个基类只提供接口
template<class T>
class Stack {
public:
	Stack() {};
	virtual void Push(const T& x) = 0;//入栈
	virtual bool Pop(T& x) = 0;//出栈
	virtual bool getTop(T& x)const = 0;//读取栈顶元素
	virtual bool IsEmpty()const = 0;
	virtual int getSize()const = 0;
};



#endif