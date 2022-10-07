#pragma once
//�۰����(���ֲ��ң�
//ע�⣺���ֲ���Ҫ�����Ա�һ��Ҫ������ġ�
//�ڱ߽�Ϊ[low,high]��R�����в���k
int BinSearch(int R[], int low, int high, int k) {
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (R[mid] < k) {
			low = mid + 1;
		}
		else if (R[mid] > k) {
			high = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return 0;
}