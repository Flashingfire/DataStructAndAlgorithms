#pragma once
//˳�����
//��򵥵�һ�ֲ��ҷ���
//������a��n������������Ԫ��k
int Search(int a[], int n, int k)
{
	for (int i = 0; i < n; ++i) {
		if (a[i] == k) {
			return i+1;//��Ϊ��0��ʼ����
		}
	}
	return 0;
}
//ʱ�临�Ӷ�o(n)

