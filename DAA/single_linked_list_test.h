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







			}
		}
	}
}