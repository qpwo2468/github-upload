/*
题目：
请实现一个函数，将一个字符串中的每个空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

思路：
  1. 先算出空格的数量
  2. 从后往前替换，一定位置为 2 * count(空格数量)， 碰到一个空格count--；
     2的原因是%20为3位，空格是一位，替换后要多出两位
*/

#include <iostream>


using namespace std;

void replaceSpace(char* str, int length)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (str[i] == ' ')
            count++;
    }

    for (int i = length - 1; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            count--;
            str[i + 2*count] = '%';
            str[i + 2*count + 1] = '2';
            str[i + 2*count + 2] = '0';
        }
        else
        {
            str[i + 2 * count] = str[i];
        }
    }
}
int main(void)
{
    char str[15] = "We are lucky.";
    replaceSpace(str, strlen(str));
    cout << str << endl;

    return 0;
}