/*
题目：
	大家都知道斐波那契数列，现在要求输入一个整数n，
	请你输出斐波那契数列的第n项（从0开始，第0项为0，第1项是1）。
     n<=39 
*/

#include <iostream>
//f 当前n层， g  n-1层
int Fibonacci(int n)
{
	int f = 0, g = 1;
	while (n--)
	{
		g += f;
		f = g - f;
	}
	return f;
}