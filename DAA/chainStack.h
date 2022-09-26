#pragma once
#ifndef CHAINSTACK_H_
#define CHAINSTACK_H_
//��ջ
//��㶨��
template<class T>
struct chainStackNode {
	T data;
	chainStackNode* next;
};

template<class T>
class chainStack {
public:
	chainStack();
	~chainStack();
	bool IsEmpty();
	bool Push(T x);
	bool Pop(T& x);
	bool getTop(T& x);
private:
	chainStackNode<T>* head;
};

template<class T>
chainStack<T>::chainStack()
{
	head = new chainStackNode<T>;
	head->next = nullptr;
}

template<class T>
chainStack<T>::~chainStack()
{
	chainStackNode<T>* pre, * p;
	pre = head;
	p = pre->next;
	while (p != nullptr)
	{
		delete pre;
		pre = p;
		p = p->next;
	}
	delete pre;
}

template<class T>
bool chainStack<T>::IsEmpty() {
	if (head->next == nullptr)
	{
		return true;
	}
	return false;
}

//ѹջ
template<class T>
bool chainStack<T>::Push(T x)
{
	chainStackNode<T>* s = new chainStackNode<T>;
	s->data = x;
	s->next = head->next;
	head->next = s;//�����Ƚ��ȳ�
	return true;
}

//��ջ
template<class T>
bool chainStack<T>::Pop(T& x)
{
	if (IsEmpty() == true)return false;
	x = head->next->data;
	chainStackNode<T>* p = head->next;
	delete p;
	return true;
}

//ȡջ��Ԫ��
template<class T>
bool chainStack<T>::getTop(T& x)
{
	if (IsEmpty() == true)return false;
	x = head->next->data;
	return true;
}


#endif