#pragma once
#include"single_linked_list.h"

namespace zy {
	namespace single_linked_list {
		namespace test {
			void single_linked_list_test() {
				SgNode<int>* v1 = new SgNode<int>();
				SgNode<int>* p = v1;
				for (int i = 0; i < 10; i += 2) {
					p->next = new SgNode<int>(i);
					p = p->next;
				}
				v1->print();
				SgNode<int>* v2 = new SgNode<int>();
				SgNode<int>* q = v2;
				for (int i = 1; i < 10; i += 2) {
					q->next = new SgNode<int>(i);
					q = q->next;
				}
				v2->print();
				SgNode<int>* v3 = mergeList<int>(v1, v2);
				v3->print();

				std::cout << "β�巨����������" << std::endl;
				int a[]{ 1,2,3,4 };
				SgNode<int>* v4 = nullptr;
				createlistR(v4, a, sizeof(a) / sizeof(a[1]));
				//C++��û��ֱ�ӵõ������С�ĺ���
				v4->print();

				std::cout << "ͷ�巨����������" << std::endl;
				int b[]{ 1,2,3,4 };
				SgNode<int>* v5 = nullptr;
				createlistF(v5, b, sizeof(b) / sizeof(b[1]));
				//C++��û��ֱ�ӵõ������С�ĺ���
				v5->print();

			}
		}
	}
}