#pragma once
#include"double_linked_list.h"

namespace zy {
	namespace dblinked_list {
		namespace test {
			void dblinked_list_test()
			{
				double_linked_list<int>* p1;
				int a[]{ 1,2,3,4 };
				createDlistR(p1, a, 4);
				p1->print();

				double_linked_list<int>* p2 = findNode(p1, 3);
				std::cout << p2->data << std::endl;
			}














		}
	}
}