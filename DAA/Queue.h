#pragma once
//队列抽象基类
const int maxSize = 50;
template<class T>
class Queue {
public:
	Queue() {};
	~Queue() {};
	virtual  bool EnQueue(const T& x) = 0;//入队
	virtual bool DeQueue(T& x) = 0;//出队列
	virtual bool getFront(T& x)const = 0;//读取队头元素
	virtual bool IsEmpty()const = 0;
	virtual bool IsFull()const = 0;
	virtual int getSize()const = 0;
};