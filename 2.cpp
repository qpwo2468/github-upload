/*
��Ŀ��
��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20����
���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��

˼·��
  1. ������ո������
  2. �Ӻ���ǰ�滻��һ��λ��Ϊ 2 * count(�ո�����)�� ����һ���ո�count--��
     2��ԭ����%20Ϊ3λ���ո���һλ���滻��Ҫ�����λ
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