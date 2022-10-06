#pragma once
#include<string.h>
using namespace std;
//��ģʽƥ��
int simple_pattern_matching(string& str, string& substr)
{
	int i = 0, j = 0, k = 0;
	while (i < str.length() && j < substr.length())
	{
		if (str[i] == substr[j])
		{
			++i;
			++j;
		}
		else
		{
			//ƥ��ʧ��
			j = 0;
			i = ++k;//k��¼����һ��ƥ�����ʼλ��
		}
	}
	if (j >= substr.length())
		return k;
	return 0;
}


//KMP�㷨
//KMP�㷨��Ҫ�Ĳ���:������ģʽ�����Լ�һ��next����
//next��������ã�next�����м�¼��ÿ��ƥ��ʧ��ʱӦ�ô��ĸ��ڵ����¿�ʼƥ��
//���ȼ����next����
void getNext(string str,int next[]) {
	next[0] = 0;
	int i = 1;
	int prefix_len = 0;//��ǰ����ǰ��׺����
	while (i < str.length()) {
		if (str[prefix_len] == str[i]) {
			prefix_len += 1;
			next[i] = prefix_len;
			i += 1;
		}
		else {
			if (prefix_len == 0) {
				next[i] = 0;
				i += 1;
			}
			else {
				prefix_len = next[prefix_len - 1];
			}
		}
	}
	cout << "next����Ϊ" << endl;
	for (int i = 0; i < str.length(); ++i) {
		cout << next[i] << ",";
	}
	cout << endl;
}
int KMP(string str, string substr, int next[]) {
	getNext( substr, next);
	
	int i = 0, j = 0;
	//KMP��ֻ��Ҫ����һ������������Ҫ����
	while (i < str.length()&&j<substr.length()) {
		if (str[i] == substr[j])
		{
			i += 1;
			j += 1;
		} 
		else {
			if (j > 0)//�ַ�ƥ��ʧ�ܣ�ʹ��next����
				j = next[j-1];
			else//��һ���ַ��Ͳ�ƥ��
				i += 1;
		}
	}
	cout << i << "," << j;
	return i - j;
}