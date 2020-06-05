/*
题目:
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

思路:
1. Map遍历  O(N)
2. 排序，找到长度一半的位置， O(NLogN)
3. 摩尔投票法: 正负抵消  O(N)  空间O(1)
票数和： 由于众数出现的次数超过数组长度的一半；若记 众数 的票数为 +1+1+1 ，非众数 的票数为 −1-1−1 ，则一定有所有数字的 票数和 >0> 0>0 。
票数正负抵消： 设数组 nums 中的众数为 xxx ，数组长度为 nnn 。若 nums 的前 aaa 个数字的 票数和 =0= 0=0 ，则 数组后 (n−a)(n-a)(n−a) 个数字的 票数和一定仍 >0>0>0 （即后 (n−a)(n-a)(n−a) 个数字的 众数仍为 xxx ）。
作者：jyd
链接：https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/solution/mian-shi-ti-39-shu-zu-zhong-chu-xian-ci-shu-chao-3/
。
 */

#include "head.h"

using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers)
{
    int x = 0, votes = 0, count = 0;
    for (int n : numbers)
    {
        if (votes == 0) x = n;
        votes += n == x ? 1 : -1;
    }
    for (int n : numbers)
    {
        count += n == x ? 1 : 0;
    }
    return count > numbers.size() / 2 ? x : 0;
}

