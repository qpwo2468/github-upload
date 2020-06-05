/*
题目：
给定一个double类型的浮点数base和int类型的整数exponent。
求base的exponent次方。
保证base和exponent不同时为0

思路：链接：https://www.nowcoder.com/questionTerminal/1a834e5e3e1a4b7ba251417554e07c00?f=discussion
第一种方法：使用递归，时间复杂度O(logn)
    当n为偶数，a^n =（a^n/2）*（a^n/2）
    当n为奇数，a^n = a^[(n-1)/2] * a^[(n-1)/2] * a 

举例：
    2^11 = 2^1 * 2^2 * 2^8
    2^1011 = 2^0001 * 2^0010 * 2^1000 


第二种方法：累乘，时间复杂度为O(n)
*/

double Power(double base, int exponent)
{
    if (base == 1 || exponent == 0)
        return 1;
    double ans = 1;
    long num = exponent;
    if (exponent < 0)
    {
        num = -num;
        base = 1 / base;
    }
    while (num)
    {
        if (num & 1)
            ans *= base;
        base *= base;
        num >>= 1;
    }
    return ans;
}
