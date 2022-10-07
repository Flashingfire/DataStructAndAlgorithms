#pragma once
//顺序查找
//最简单的一种查找方法
//在数组a有n个整数，查找元素k
int Search(int a[], int n, int k)
{
	for (int i = 0; i < n; ++i) {
		if (a[i] == k) {
			return i+1;//因为从0开始计数
		}
	}
	return 0;
}
//时间复杂度o(n)

