#pragma once
#include"sequence_list.h"
#include<iostream>
namespace zy {
	namespace sequence_list {
		namespace test {
			void test() {
				std::cout << "Sqlist test" << std::endl;
				std::cout << "�޲ι���" << std::endl;
				Sqlist<int>v1;
				std::cout <<"Sqlist length:"<< v1.length << std::endl;
				std::cout << "�вι���" << std::endl;
				std::vector<int>vc{ 1,2,4,6 };
				Sqlist<int>v2(vc, 4);
				std::cout << "Sqlist data" << std::endl;
				v2.print();
				std::cout << "Sqlist length:" << v1.length << std::endl;
				std::cout << "��������" << std::endl;
				Sqlist<int>v3(v2);
				std::cout << "Sqlist data" << std::endl;
				v3.print();
				std::cout << "Sqlist length:" << v1.length << std::endl;
				
				std::cout << "Sqlist ����" << std::endl;
				std::cout << "�������������˲�����ǰ����˳��������������" << std::endl;
				v3.inorderInsert(5);
				std::cout << v3.length << std::endl;
				std::cout << "result:" << std::endl;
				v3.print();
				std::cout << "ɾ�� �±�Ϊp��Ԫ�أ��ɹ�����1�����򷵻�0��������ɾ��Ԫ�ص�ֵ��ֵ��e" << std::endl;
				int e = 0;
				v3.deleteElem(2,e);
				v3.print();
			}
		}
	}
}