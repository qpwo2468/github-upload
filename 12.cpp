/*
��Ŀ��
����һ��double���͵ĸ�����base��int���͵�����exponent��
��base��exponent�η���
��֤base��exponent��ͬʱΪ0

˼·�����ӣ�https://www.nowcoder.com/questionTerminal/1a834e5e3e1a4b7ba251417554e07c00?f=discussion
��һ�ַ�����ʹ�õݹ飬ʱ�临�Ӷ�O(logn)
    ��nΪż����a^n =��a^n/2��*��a^n/2��
    ��nΪ������a^n = a^[(n-1)/2] * a^[(n-1)/2] * a 

������
    2^11 = 2^1 * 2^2 * 2^8
    2^1011 = 2^0001 * 2^0010 * 2^1000 


�ڶ��ַ������۳ˣ�ʱ�临�Ӷ�ΪO(n)
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
