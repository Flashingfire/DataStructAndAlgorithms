#pragma once
#ifndef ZYSEQUENCELIST_H_
#define ZYSEQUENCELIST_H_
//顺序表的结构体定义
#include<vector>
namespace zy {
	template<class T>
	class Sqlist {
	public:
		std::vector<T> data;//存放顺序表元素的数组
		int length;//存放顺序表的长度
	public:
		//无参构造，有参构造，拷贝构造，析构
		Sqlist();
		Sqlist(std::vector<T>&, int);
		Sqlist(Sqlist&);
		~Sqlist();
		//顺序表的操作
		//有序插入，顺序表中的元素递增有序排列，插入数字x后依然有序
		void inorderInsert(T x);
		//删除 下标为p的元素，成功返回1，否则返回0，并将被删除元素的值赋值给e
		int deleteElem( int p, int& e);
	};
	//无参构造
	template<class T>
	Sqlist<T>::Sqlist() {
		this->length = 0;
	}
	//有参构造
	template<class T>
	Sqlist<T>::Sqlist(std::vector<T>& v, int x) {
		if (x != v.size())
		{
			printf(" v and x isn't match");
		}
		else {
			this->data = std::move(v);
			this->length = x;
		}
	}
	//拷贝构造
	template<class T>
	Sqlist<T>::Sqlist(Sqlist<T>& sq) {
		this->data = sq.data;
		this->length = sq.length;
	}
	//析构函数
	template<class T>
	Sqlist<T>::~Sqlist() {
		std::vector<T>().swap(this->data);
		this->length = 0;
	}
	/************************/
	//顺序表操作
	template<class T>
	void Sqlist<T>::inorderInsert(T x) {
		//二分查找位置
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
		//直接调用vector的insert函数
		this->data.insert(lindex, x);
	}
	//删除 下标为p的元素，成功返回1，否则返回0，并将被删除元素的值赋值给e
	template<class T>
	int Sqlist<T>::deleteElem(int p, int& e) {
		if (p<0 || p>this->length) {
			printf("p out of range!\n");
			return 0;
		}
		try {
			this->data.erase(p);
		}
		catch (...) {
			e = this->data[p];
			printf("delete fail");
			throw;
		}
		return 1;
	}
}

#endif