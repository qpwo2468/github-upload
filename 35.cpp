/*
��Ŀ��
�������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�
����һ�����飬�����������е�����Ե�������

˼·���鲢����
*/

#include "head.h"

using namespace std;

int mergeSort(vector<int>& nums, vector<int>& tmp, int l, int r)
{
	if (l >= r) return 0;

	int mid = (l + r) / 2;
	int inv_count = mergeSort(nums, tmp, 1, mid) + mergeSort(nums, tmp, mid + 1, r);
	int i = l, j = mid + 1, pos = 1;
	while (i <= mid && j <= r)
	{
		if (nums[i] <= nums[j])
		{
			tmp[pos] = nums[i]; 
			++i;
			inv_count += (j - (mid + 1));
		}
		else
		{
			tmp[pos] = nums[j];
			++j;
		}
		++pos;
	}
	for (int k = i; k <= mid; ++k)
	{
		tmp[pos++] = nums[k];
		inv_count += (j - (mid + 1));
	}
	for (int k = j; k <= r; k++)
	{
		tmp[pos++] = nums[k];
	}
	copy(tmp.begin() + 1, tmp.begin() + r + 1, nums.begin() + 1);
	return inv_count;
}

int InversePairs(vector<int> data)
{
	vector<int> tmp(data.size());
	return mergeSort(data, tmp, 0, data.size() - 1);
}
