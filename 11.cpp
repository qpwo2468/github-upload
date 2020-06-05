/*
题目：
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
思路：
	1.对数字的每一位进行与操作，判断是否为1
	2.如果一个整数不为0，那么这个整数至少有一位是1。如果我们把这个整数减1，
	那么原来处在整数最右边的1就会变为0，原来在1后面的所有的0都会变成1(如果最右边的1
	后面还有0的话)。其余所有位将不会受到影响。
*/

#include <iostream>
using namespace std;

/*
	* 该解法如果输入时负数会陷入死循环，
	* 因为负数右移时，在最高位补得是1
	* 二本题最终目的是求1的个数，那么会有无数个
	* 1了。
*/
int NumberOf1(int n)
{
	int flag = 1;
	int count = 0;
	while (n != 0)
	{
		if (flag & n)
			count++;
		n = n >> 1;
	}
	return count;
}


//正解
int NumberOf1(int n)
{
	int flag = 1;
	int count = 0;
	while (flag != 0)
	{
		if (flag & n)
			count++;
		flag = flag << 1;
	}
	return count;
}

//最优解
int NumberOf1(int n)
{
	int count = 0;
	while (n != 0)
	{
		count++;
		//n-1 会使最右边的1变为0，1后面的0变为1，
		//两个相与不为0，代表前面两个至少还有一个1
		n = (n - 1) & n;
	}
	return count;
}
int main(void)
{
	cout << NumberOf1(20);
	return 0;
}