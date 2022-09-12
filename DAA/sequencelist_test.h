#pragma once
#include"sequence_list.h"
#include<iostream>
namespace zy {
	namespace sequence_list {
		namespace test {
			void test() {
				std::cout << "Sqlist test" << std::endl;
				std::cout << "无参构造" << std::endl;
				Sqlist<int>v1;
				std::cout <<"Sqlist length:"<< v1.length << std::endl;
				std::cout << "有参构造" << std::endl;
				std::vector<int>vc{ 1,2,4,6 };
				Sqlist<int>v2(vc, 4);
				std::cout << "Sqlist data" << std::endl;
				v2.print();
				std::cout << "Sqlist length:" << v1.length << std::endl;
				std::cout << "拷贝构造" << std::endl;
				Sqlist<int>v3(v2);
				std::cout << "Sqlist data" << std::endl;
				v3.print();
				std::cout << "Sqlist length:" << v1.length << std::endl;
				
				std::cout << "Sqlist 操作" << std::endl;
				std::cout << "有序插入操作：此操作的前提是顺序表是有序增大的" << std::endl;
				v3.inorderInsert(5);
				std::cout << v3.length << std::endl;
				std::cout << "result:" << std::endl;
				v3.print();
				std::cout << "删除 下标为p的元素，成功返回1，否则返回0，并将被删除元素的值赋值给e" << std::endl;
				int e = 0;
				v3.deleteElem(2,e);
				v3.print();
			}
		}
	}
}