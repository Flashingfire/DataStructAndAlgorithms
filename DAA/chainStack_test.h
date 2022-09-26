#pragma once
#include"chainStack.h"
#include<iostream>
namespace zy {
	namespace chainStack_test {
		void test() {
			chainStack<int>stack;
			stack.Push(3);
			stack.Push(4);
			stack.Push(5);
			int top;
			stack.getTop(top);
			std::cout << top << std::endl;
		}
	}
}