/*
题目：
	输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，
	偶数和偶数之间的相对位置不变。

思路：主要是实现稳定性
      1. 使用稳定性排序算法， 插入、冒泡、归并
	  2. 新建一个vector， 先push奇数，后push偶数
*/

#include <iostream>
#include <vector>
using namespace std;

//错误，只能分类但不能保证稳定性
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
// 1. 冒泡排序
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