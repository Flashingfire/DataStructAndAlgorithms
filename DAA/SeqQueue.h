#pragma once
#include"Queue.h"
//顺序循环队列
#include<assert.h>
#include<iostream>
using namespace std;

template<class T>
class SeqQueue :public  Queue<T> {
public:
	SeqQueue(int sz = 10);
	~SeqQueue() { delete[] elements; }
	bool EnQueue(const T& x);
	bool DeQueue(T& x);
	bool getFront(T& x)const;
	void makeEmpty() { front = rear = 0; }
	bool IsEmpty()const{ 
		return (front == rear) ? true : false;
	}
	bool IsFull()const{
		return ((rear + 1) % maxSize == front) ? true : false;
	}
	//求得队列元素个数
	int getSize()const {
		return (rear - front + maxSize) % maxSize;
	}
	template<class T2>
	friend ostream& operator<<(ostream& os, SeqQueue<T2>& Q);
private:
	int rear;
	int front;
	T* elements;
	int maxSize;
};

template<class T>
SeqQueue<T>::SeqQueue(int sz) :front(0), rear(0), maxSize(sz) {
	//创建一个最大具有maxSize个元素的空队列
	elements = new T[maxSize];//分配空间
	assert(elements != nullptr);//断言：动态存储分配成功
}

template<class T>
bool SeqQueue<T>::EnQueue(const T& x) {
	//入队，先判断队列是否满
	if (IsFull() == true)return false;
	elements[rear] = x;
	rear = (rear + 1) % maxSize;
	return true;
}

template<class T>
bool SeqQueue<T>::DeQueue(T& x) {
	//出队，先判断是否空队
	if (IsEmpty() == true)return false;
	x = elements[front];
	front = (front + 1) % maxSize;
	return true;
}

template<class T>
bool SeqQueue<T>::getFront(T& x)const {
	//如果队列不空，就返回队头元素
	if (IsEmpty() == true)return false;
	x = elements[front];
	return true;
}

template<class T>
ostream& operator<< (ostream & os, SeqQueue<T>&Q) {
	os << "front=" << Q.front << ",rear=" << Q.rear << endl;
	for (int i = Q.front; i != Q.rear; i = (i + 1) % maxSize)
		os << i << ":" << Q.elements[i] << endl;
	return os;
}