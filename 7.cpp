/*
��Ŀ��
	��Ҷ�֪��쳲��������У�����Ҫ������һ������n��
	�������쳲��������еĵ�n���0��ʼ����0��Ϊ0����1����1����
     n<=39 
*/

#include <iostream>
//f ��ǰn�㣬 g  n-1��
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