/*
��Ŀ��
HZż������Щרҵ������������Щ�Ǽ����רҵ��ͬѧ��
��������鿪����,���ַ�����:�ڹ��ϵ�һάģʽʶ����,
������Ҫ��������������������,������ȫΪ������ʱ��,
����ܺý��������,��������а�������,�Ƿ�Ӧ�ð���ĳ������,
�������Աߵ��������ֲ����أ�����:{6,-3,-2,7,-15,1,2,2},
����������������Ϊ8(�ӵ�0����ʼ,����3��Ϊֹ)����һ�����飬
��������������������еĺͣ�
��᲻�ᱻ������ס��(�������ĳ���������1)


˼·��
  ��̬�滮
  https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/solution/mian-shi-ti-42-lian-xu-zi-shu-zu-de-zui-da-he-do-2/
*/

#include "head.h"

using namespace std;

int FindGreatestSumOfSubArray(vector<int> array)
{
	int res = array[0];
	for (int i = 1; i < array.size(); i++)
	{
		array[i] += max(array[i - 1], 0);
		res = max(res, array[i]);
	}
	return res;
}