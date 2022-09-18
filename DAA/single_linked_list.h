#pragma once
#ifndef ZYSINGLELINKEDLIST_H_
#define ZYSINGLELINKEDLIST_H_
#include<iostream>
namespace zy {
	//�������Ľṹ�嶨��
	//������ڵ�ṹ
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
		T data;//data�д�Žڵ������� 
		SgNode* next;//ָ���̽���ָ��
		
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

	//�ϲ��������������ϲ�����Ȼ�ǵݼ�
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

	//β�巨����������
	//n��Ԫ���Ѿ���������A��
	template<class T>
	void createlistR(SgNode<T>*& c, T a[], int n) {//ע��ʹ��ָ�������
		SgNode<T>* s, * r;//sָ��������Ľڵ㣬rʼ��ָ�� c���ն˽ڵ�
		int i = 0;
		c = new SgNode<T>();
		r = c;//rָ��ͷ��㣬Ҳ���Ǵ�ʱ���ն˽ڵ�
		for (i = 0; i < n; i++) {//ѭ������n���������������a�е�����
			s = new SgNode<T>(a[i]);
			s->data = a[i];
			r->next = s;
			r = r->next;
		}
		r->next = NULL;//����Ԫ�ض�װ�������
	}

	//ͷ�巨����������
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