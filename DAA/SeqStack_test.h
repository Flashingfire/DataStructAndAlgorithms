#pragma once
#ifndef SEQSTACK_TEST_H_
#define SEQSTACK_TEST_H_

#include"SeqStack.h"
namespace zy {
	namespace SeqStack_test {
		void test()
		{
			SeqStack<int> seqstack(3);//初始化一个空间为3的栈
			int m, j;
			seqstack.Push(3);
			seqstack.Push(10);
			seqstack.Push(8);
			seqstack.Push(4);
			seqstack.Push(7);
			seqstack.Pop(m);
			seqstack.getTop(j);
			cout << "弹出的元素是：" << m << endl;
			cout << "栈顶的元素是" << j << endl;
			cout << seqstack << endl;
		}
	}
}

#endif