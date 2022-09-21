#pragma once
#ifndef ZYDOUBLELINKEDLIST_H_
#define ZYDOUBLELINKEDLIST_H_
namespace zy {


	//双链表表的结构体定义
	template<class T>
	class double_linked_list {
	public:
		T data;//data中存放节点数据域 默认是int
		double_linked_list* prior;//指向前驱节点的指针
		double_linked_list* next;//指向后继结点的指针

		double_linked_list() {
			data = 0;
			prior = nullptr;
			next = nullptr;
		}
		double_linked_list(const T& x) {
			data = x;
			prior = nullptr;
			next = nullptr;
		}

		void print() {
			//默认带头指针
			double_linked_list<T>* p = this;
			if (p == nullptr) {
				std::cout << "双链表为空" << std::endl;
				return;
			}
			p = p->next;
			while (p != nullptr)
			{
				std::cout << p->data << " ";
				p = p->next;
			}
			std::cout << std::endl;
		}
	};

	//采用尾插法建立双链表
	//默认带头指针
	template<class T>
	void createDlistR(double_linked_list<T>*& L, T a[], int n)//对于指针的引用传递
	{
		double_linked_list<T>* s, * r;
		L = (double_linked_list<T>*)malloc(sizeof(double_linked_list<T>));
		L->prior = nullptr;//前驱指针
		L->next = nullptr;
		r = L;//和单链表一样，r始终指向终端节点，开始头节点也是尾结点
		for (int i = 0; i < n; ++i)
		{
			s = (double_linked_list<T>*)malloc(sizeof(double_linked_list<T>));
			s->data = a[i];
			r->next = s;
			s->prior = r;
			r = s;
		}
		r->next = nullptr;
	}

	//查找节点的算法,在双链表中查找第一个值为x的结点
	template<class T>
	double_linked_list<T>* findNode(double_linked_list<T>* c, T x)
	{
		double_linked_list<T>* p = c->next;//默认有头节点
		while (p != nullptr) {
			if (p->data == x)
				break;
			p = p->next;
		}
		return p;
	}

	//逆置问题
	//逆置整个链表
	template<class T>
	void reverse(double_linked_list<T>** p)
	{
		//默认带有头节点
		double_linked_list<T>* temp = nullptr;
		double_linked_list<T>* current = *p;
		//把默认头节点消除掉
		current = current->next;
		current->prior = nullptr;
		while (current != nullptr)
		{
			temp = current->prior;
			current->prior = current->next;
			current->next = temp;
			current = current->prior;
		}

		//修改头指针之前，先检测链表是否为空链表，或者只有一个节点的情况
		if (temp != nullptr)
			(*p)->next = temp->prior;
	}


}

#endif