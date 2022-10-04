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


			cout << "��ģʽƥ��" << endl;
			string str = "ABABCABCACBAB";
			string substr = "ABCAC";
			cout << "����:" << str << endl;
			cout << "�Ӵ�(ģʽ��)" << substr << endl;
			clock_t start = clock();
			cout << "ƥ��λ��Ϊ:" << simple_pattern_matching(str, substr) << endl;
			cout << "��ʱ��ms" << (double)(clock() - start) << endl;
		}
	}
}