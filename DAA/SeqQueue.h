#pragma once
#include"Queue.h"
//˳��ѭ������
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
	//��ö���Ԫ�ظ���
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
	//����һ��������maxSize��Ԫ�صĿն���
	elements = new T[maxSize];//����ռ�
	assert(elements != nullptr);//���ԣ���̬�洢����ɹ�
}

template<class T>
bool SeqQueue<T>::EnQueue(const T& x) {
	//��ӣ����ж϶����Ƿ���
	if (IsFull() == true)return false;
	elements[rear] = x;
	rear = (rear + 1) % maxSize;
	return true;
}

template<class T>
bool SeqQueue<T>::DeQueue(T& x) {
	//���ӣ����ж��Ƿ�ն�
	if (IsEmpty() == true)return false;
	x = elements[front];
	front = (front + 1) % maxSize;
	return true;
}

template<class T>
bool SeqQueue<T>::getFront(T& x)const {
	//������в��գ��ͷ��ض�ͷԪ��
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