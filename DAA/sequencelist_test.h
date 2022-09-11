#pragma once
#include"sequence_list.h"
#include<iostream>
namespace zy {
	namespace sequence_list {
		namespace test {
			void test() {
				Sqlist<int>a1;
				std::vector<int>vc{ 1,2,3,4 };
				Sqlist<int>a2(vc, 4);
				Sqlist<int>a3(a2);
				for (int i = 0; i < a3.length; i++) {
					std::cout << a3.data[i] << " ";
				}
				std::cout << std::endl;
			}
		}
	}
}