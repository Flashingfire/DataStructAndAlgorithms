#pragma once
#ifndef ZYDOUBLELINKEDLIST_H_
#define ZYDOUBLELINKEDLIST_H_
namespace zy {


	//˫�����Ľṹ�嶨��
	template<class T>
	class double_linked_list {
	public:
		T data;//data�д�Žڵ������� Ĭ����int
		double_linked_list* prior;//ָ��ǰ���ڵ��ָ��
		double_linked_list* next;//ָ���̽���ָ��

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
			//Ĭ�ϴ�ͷָ��
			double_linked_list<T>* p = this;
			if (p == nullptr) {
				std::cout << "˫����Ϊ��" << std::endl;
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

	//����β�巨����˫����
	//Ĭ�ϴ�ͷָ��
	template<class T>
	void createDlistR(double_linked_list<T>*& L, T a[], int n)//����ָ������ô���
	{
		double_linked_list<T>* s, * r;
		L = (double_linked_list<T>*)malloc(sizeof(double_linked_list<T>));
		L->prior = nullptr;//ǰ��ָ��
		L->next = nullptr;
		r = L;//�͵�����һ����rʼ��ָ���ն˽ڵ㣬��ʼͷ�ڵ�Ҳ��β���
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

	//���ҽڵ���㷨,��˫�����в��ҵ�һ��ֵΪx�Ľ��
	template<class T>
	double_linked_list<T>* findNode(double_linked_list<T>* c, T x)
	{
		double_linked_list<T>* p = c->next;//Ĭ����ͷ�ڵ�
		while (p != nullptr) {
			if (p->data == x)
				break;
			p = p->next;
		}
		return p;
	}

	//��������
	//������������
	template<class T>
	void reverse(double_linked_list<T>** p)
	{
		//Ĭ�ϴ���ͷ�ڵ�
		double_linked_list<T>* temp = nullptr;
		double_linked_list<T>* current = *p;
		//��Ĭ��ͷ�ڵ�������
		current = current->next;
		current->prior = nullptr;
		while (current != nullptr)
		{
			temp = current->prior;
			current->prior = current->next;
			current->next = temp;
			current = current->prior;
		}

		//�޸�ͷָ��֮ǰ���ȼ�������Ƿ�Ϊ����������ֻ��һ���ڵ�����
		if (temp != nullptr)
			(*p)->next = temp->prior;
	}


}

#endif