/*
��Ŀ��
	��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
    ����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء�
    ��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1��
    NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��

˼·��
    1.���������ж��ҳ���Сֵ
    2.�����Ƿǵ��������ǰnλ�Ƶ��˺��棬���ԴӺ��������ֱ������һ��Ԫ�ر�����һ��Ԫ��Сʱ��
      ˵��������ƶ������Ҳ������Сֵ
    3.ʹ�ö��ַ���С���ҷ�Χ���ҵ�left < right
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
        //ȷ�������Ƿ�Ϊ�ǵݼ��������� 1 1 2 3
        if (rotateArray[left] < rotateArray[right])
            return rotateArray[left];
        int mid = left + (right - left) / 2;
        //�����������������
        if (rotateArray[left] < rotateArray[mid])
            left = mid + 1;
        else if (rotateArray[right] > rotateArray[mid])
            right = mid;
        else
            ++left;
    }
    return rotateArray[left];
}