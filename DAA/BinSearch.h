#pragma once
//折半查找(二分查找）
//注意：二分查找要求线性表一定要是有序的。
//在边界为[low,high]的R数组中查找k
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