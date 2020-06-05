/*
��Ŀ��
	����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ������ĺ�벿�֣�����֤������������
	ż����ż��֮������λ�ò��䡣

˼·����Ҫ��ʵ���ȶ���
      1. ʹ���ȶ��������㷨�� ���롢ð�ݡ��鲢
	  2. �½�һ��vector�� ��push��������pushż��
*/

#include <iostream>
#include <vector>
using namespace std;

//����ֻ�ܷ��൫���ܱ�֤�ȶ���
void reOrderArray(vector<int> &nums)
{
	int left = 0, right = nums.size() - 1;
	while (left < right)
	{
		while (left < right && nums[left] % 2 != 0)
			left++;
		while (left < right && nums[right] % 2 == 0)
			right--;
		int temp;
		temp = nums[left];
		nums[left] = nums[right];
		nums[right] = temp;
	}
}
// 1. ð������
void reOrderArray(vector<int>& nums)
{
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = nums.size() - 1; j > i; j--)
		{
			if (nums[j] % 2 == 1 && nums[j - 1] % 2 == 0)
				swap(nums[j], nums[j - 1]);
		}

	}
}
int main(void)
{
	vector<int> nums = { 1, 2, 3, 4, 5};
	reOrderArray(nums);
	for (auto it : nums)
	{
		cout << it << " ";
	}
	return 0;
}