#pragma once
#include<string.h>
using namespace std;
//简单模式匹配
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
			//匹配失败
			j = 0;
			i = ++k;//k记录了上一次匹配的起始位置
		}
	}
	if (j >= substr.length())
		return k;
	return 0;
}


//KMP算法
//KMP算法需要的部件:主串，模式串，以及一个next数组
//next数组的作用：next数组中记录了每当匹配失败时应该从哪个节点重新开始匹配
//首先计算出next数组
void getNext(string str,int next[]) {
	next[0] = 0;
	int i = 1;
	int prefix_len = 0;//当前公共前后缀长度
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
	cout << "next数组为" << endl;
	for (int i = 0; i < str.length(); ++i) {
		cout << next[i] << ",";
	}
	cout << endl;
}
int KMP(string str, string substr, int next[]) {
	getNext( substr, next);
	
	int i = 0, j = 0;
	//KMP中只需要遍历一次主串，不需要回溯
	while (i < str.length()&&j<substr.length()) {
		if (str[i] == substr[j])
		{
			i += 1;
			j += 1;
		} 
		else {
			if (j > 0)//字符匹配失败，使用next数组
				j = next[j-1];
			else//第一个字符就不匹配
				i += 1;
		}
	}
	cout << i << "," << j;
	return i - j;
}