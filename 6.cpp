/*
题目：
	把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
    输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
    例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
    NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

思路：
    1.暴力挨个判断找出最小值
    2.由于是非递增数组的前n位移到了后面，所以从后面遍历，直到发现一个元素比它下一个元素小时，
      说明这个是移动的起点也就是最小值
    3.使用二分法缩小查找范围，找到left < right
*/

#include <iostream>
#include <vector>

using namespace std;

//2
int minRotateArray(vector<int> rotateArray)
{
    if (rotateArray.size() == 0)
        return 0;
    if (rotateArray.size() == 1)
        return rotateArray[0];
    int result = rotateArray.back();
    for (int i = rotateArray.size() - 1; i >= 0; i--)
    {
        if (rotateArray[i] < rotateArray[i - 1])
            result = rotateArray[i];
    }
    return result;
}

int minRotateArray(vector<int> rotateArray)
{
    if (rotateArray.empty())
        return 0;
    int left = 0, right = rotateArray.size() - 1;
    while (left < right)
    {
        //确认数组是否为非递减数组例如 1 1 2 3
        if (rotateArray[left] < rotateArray[right])
            return rotateArray[left];
        int mid = left + (right - left) / 2;
        //如果左半边是有序数组
        if (rotateArray[left] < rotateArray[mid])
            left = mid + 1;
        else if (rotateArray[right] > rotateArray[mid])
            right = mid;
        else
            ++left;
    }
    return rotateArray[left];
}