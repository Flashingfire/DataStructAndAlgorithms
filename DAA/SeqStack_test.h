#pragma once
#ifndef SEQSTACK_TEST_H_
#define SEQSTACK_TEST_H_

#include"SeqStack.h"
namespace zy {
	namespace SeqStack_test {
		void test()
		{
			SeqStack<int> seqstack(3);//��ʼ��һ���ռ�Ϊ3��ջ
			int m, j;
			seqstack.Push(3);
			seqstack.Push(10);
			seqstack.Push(8);
			seqstack.Push(4);
			seqstack.Push(7);
			seqstack.Pop(m);
			seqstack.getTop(j);
			cout << "������Ԫ���ǣ�" << m << endl;
			cout << "ջ����Ԫ����" << j << endl;
			cout << seqstack << endl;
		}
	}
}

#endif