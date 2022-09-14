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

}


#endif