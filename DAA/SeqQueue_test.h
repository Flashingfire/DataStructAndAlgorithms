#pragma once
#include"SeqQueue.h"

namespace zy {
	namespace SeqQueue_test {
		void test() {
			int i, j;
			SeqQueue<int>queue(10);
			queue.EnQueue(3);
			queue.EnQueue(5);
			queue.EnQueue(10);
			queue.DeQueue(j);
			queue.getFront(i);
			cout << "��ͷԪ�ص�ֵ��:" << i << endl;
			cout << j << endl;
		}
	}
}