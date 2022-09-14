#pragma once
#ifndef ZYSEQUENCELIST_H_
#define ZYSEQUENCELIST_H_
//˳���Ľṹ�嶨��
#include<vector>
#include<iostream>
namespace zy {
	template<class T>
	class Sqlist {
	public:
		std::vector<T> data;//���˳���Ԫ�ص�����
		int length;//���˳���ĳ���
	public:
		//�޲ι��죬�вι��죬�������죬����
		Sqlist();
		Sqlist(std::vector<T>&, int);
		Sqlist(Sqlist&);
		~Sqlist();
		//˳���Ĳ���
		void print();
		//������룬˳����е�Ԫ�ص����������У���������x����Ȼ����
		void inorderInsert(T x);
		//ɾ�� �±�Ϊp��Ԫ�أ��ɹ�����1�����򷵻�0��������ɾ��Ԫ�ص�ֵ��ֵ��e
		int deleteElem( int p, int& e);
	};
	//�޲ι���
	template<class T>
	Sqlist<T>::Sqlist() {
		this->length = 0;
	}
	//�вι���
	template<class T>
	Sqlist<T>::Sqlist(std::vector<T>& v, int x) {
		if (x != v.size())
		{
			printf(" v and x isn't match");
			exit(1);
		}
		
			this->data = std::move(v);
			this->length = x;
		
	}
	//��������
	template<class T>
	Sqlist<T>::Sqlist(Sqlist<T>& sq) {
		this->data = sq.data;
		this->length = sq.length;
	}
	//��������
	template<class T>
	Sqlist<T>::~Sqlist() {
		std::vector<T>().swap(this->data);
		this->length = 0;
	}
	/************************/
	//˳������
	template<class T>
	void Sqlist<T>::inorderInsert(T x) {
		//���ֲ���λ��
		int lindex = 0;
		int rindex = this->length;
		while (lindex < rindex) {
			int mid = lindex + (rindex - lindex) / 2;
			if (this->data[mid] < x) {
				lindex++;
			}
			else if (this->data[mid] > x) {
				rindex--;
			}
			else {
				lindex = mid;
				break;
			}
		}
		//ֱ�ӵ���vector��insert����
		this->length++;
		this->data.insert(this->data.begin()+lindex, x);
	}
	//ɾ�� �±�Ϊp��Ԫ�أ��ɹ�����1�����򷵻�0��������ɾ��Ԫ�ص�ֵ��ֵ��e
	template<class T>
	int Sqlist<T>::deleteElem(int p, int& e) {
		if (p<0 || p>this->length) {
			printf("p out of range!\n");
			return 0;
		}
		try {
			this->data.erase(this->data.begin()+p);
		}
		catch (...) {
			e = this->data[p];
			printf("delete fail");
			throw;
		}
		this->length--;
		return 1;
	}

	template<class T>
	void Sqlist<T>::print() {
		for (int i = 0; i < this->length; ++i)
			std::cout << this->data[i] << ' ';
		std::cout << std::endl;
	}
}

#endif