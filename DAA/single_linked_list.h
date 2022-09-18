#pragma once
#ifndef ZYSINGLELINKEDLIST_H_
#define ZYSINGLELINKEDLIST_H_
#include<iostream>
namespace zy {
	//单链表表的结构体定义
	//单链表节点结构
	template<class T>
	class SgNode {
	public:
		SgNode() {
			data = 0;
			next = nullptr;
		}
		SgNode(T x) {
			data = x;
			next = nullptr;
		}
		SgNode(SgNode<T>& a) {
			SgNode<T>* p = *a;
			SgNode<T>* q = this;
			while (p != nullptr) {
				q->next = new SgNode<T>(p->data);
				q = q->next;
				p = p->next;
			}
		}
	public:
		T data;//data中存放节点数据域 
		SgNode* next;//指向后继结点的指针
		
		void print() {
			SgNode<T>* p = this;
			p = p->next;
			while (p != nullptr) {
				std::cout << p->data << " ";
				p = p->next;
			}
			std::cout << std::endl;
		}
	};

	//合并两个递增链表，合并后依然非递减
	template<class T>
	SgNode<T>* mergeList(SgNode<T>* a, SgNode<T>* b) 
	{
		SgNode<T>* p1 = a->next;
		SgNode<T>* p2 = b->next;
		SgNode<T>* res = new SgNode<T>();
		SgNode<T>* r = res;
		while (p1 != nullptr && p2 != nullptr) {
			if (p1->data <= p2->data) {
				r->next = p1;
				r = r->next;
				p1 = p1->next;
			}
			else {
				r->next = p2;
				r = r->next;
				p2 = p2->next;
			}
		}
		if (p2 != nullptr)
		{
			r->next = p2;
		}
		if (p1 != nullptr)
		{
			r->next = p1;
		}
		return res;
	}

	//尾插法建立单链表
	//n个元素已经存在数组A中
	template<class T>
	void createlistR(SgNode<T>*& c, T a[], int n) {//注意使用指针的引用
		SgNode<T>* s, * r;//s指向新申请的节点，r始终指向 c的终端节点
		int i = 0;
		c = new SgNode<T>();
		r = c;//r指向头结点，也就是此时的终端节点
		for (i = 0; i < n; i++) {//循环申请n个结点来接受数组a中的数据
			s = new SgNode<T>(a[i]);
			s->data = a[i];
			r->next = s;
			r = r->next;
		}
		r->next = NULL;//所有元素都装入链表后
	}

	//头插法建立单链表
	template<class T>
	void createlistF(SgNode<T>*& c,T a[],int n)
	{
			SgNode<T>* s=nullptr;
			int i = 0;
			c = new SgNode<T>();
			for (int i = 0; i < n; i++) {
				s = new SgNode<T>(a[i]);
				s->next = c->next;
				c->next = s;
			}
	}
}


#endif