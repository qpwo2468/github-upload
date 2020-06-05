/*
��Ŀ��
����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣����磬�����������4 X 4���� 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 �����δ�ӡ������
1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> printMatrix(vector<vector<int> > matrix)
{
	vector<int> result;
	if (matrix.size() == 0)
		return result;
	int l = 0, r = matrix[0].size() - 1, t = 0, b = matrix.size() - 1;
	int x = 0;
	result.resize((r + 1) * (b + 1));
	while (1)
	{
		for (int i = l; i <= r; i++) result[x++] = matrix[t][i];
		if (++t > b) break;
		for (int i = t; i <= b; i++) result[x++] = matrix[i][r];
		if (l > --r) break;
		for (int i = r; i >= l; i--) result[x++] = matrix[b][i];
		if (t > --b) break;
		for (int i = b; i >= t; i--) result[x++] = matrix[i][l];
		if (++l > r) break;
	}
	return result;
}