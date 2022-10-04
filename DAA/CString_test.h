#pragma once
#include"CString.h"
#include"String_pattern_matching.h"
#include<time.h>
namespace zy {
	namespace CString_test {
		void test() {
			CString str1("it");
			cout << "str1:" << str1 << endl;

			CString str2(str1);
			cout << "str2:" << str2 << endl;

			CString str3 = "constainer";
			cout << "str3:" << str3 << endl;

			cout << "str1=str3?:" << (str1 == str3) << endl;

			CString str4 = str1;
			str4 += str3;
			cout << "str4:" << str4 << endl;
			cout << "str4[1]" << str4[1] << endl;
			cout << "str4.size" << str4.size() << endl;
			cout << "str4.c_str()" << str4.c_str() << endl;


			cout << "简单模式匹配" << endl;
			string str = "ABABCABCACBAB";
			string substr = "ABCAC";
			cout << "主串:" << str << endl;
			cout << "子串(模式串)" << substr << endl;
			clock_t start = clock();
			cout << "匹配位置为:" << simple_pattern_matching(str, substr) << endl;
			cout << "用时：ms" << (double)(clock() - start) << endl;
		}
	}
}