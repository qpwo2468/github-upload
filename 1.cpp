/*
��Ŀ��
��һ����ά�����У�ÿ��һά����ĳ�����ͬ����
ÿһ�ж����մ����ҵ�����˳������
ÿһ�ж����մ��ϵ��µ�����˳������
�����һ������������������һ����ά�����һ��������
�ж��������Ƿ��и�������

˼·��
    �Խ���·��
*/

#include <iostream>
#include <vector>

using namespace std;

//answer
bool find(int target, vector<vector<int>>& matrix)
{
    //�����Ͻǿ�ʼ
	int i = matrix.size() - 1, j = 0;
	while (i >= 0 && j < matrix[0].size())
	{
		if (matrix[i][j] == target)
			return true;
		else if (matrix[i][j] > target)
			i--;
		else
			j++;
	}
	return false;

}

//error
/*
bool find(int target, vector<vector<int>>& matrix)
{
    if (matrix.size() == 0)
        return false;
    for (int row = 0; row < matrix.size(); row++)
    {
        //��������ݵ�vector,�����Խ������
        //if (matrix[row][0] <= target && matrix[row][matrix[row].size() - 1] >= target)
        {

           // if (matrix[row][0] == target || matrix[row][matrix[row].size() - 1] == target)
            //    return true;
            int left = 0, right = matrix[row].size() - 1;
            int centre = (left + right) / 2;
            while (left <= right)
            {
                if (matrix[row][centre] == target)
                    return true;
                if (matrix[row][centre] > target)
                {
                    right = centre - 1;
                }
                if (matrix[row][centre] < target)
                {
                    left = centre + 1;
                }
                centre = (left + right) / 2;
            }
        }
    }
    return false;
}
*/

int main(void)
{
    vector<vector<int>> array = {
        {1},
        {6},
        //{11, 12, 13, 14, 15},
        //{16, 17, 18, 19, 20},
       // {21, 22, 23, 24, 25}
    };
    /*
	for (int i = 0; i < 5; i++)
	{
		vector<int> num;
		for (int j = 0; j < 5; j++)
		{
			int n;
			cin >> n;
			num.push_back(n);
		}
		array.push_back(num);
	}
    */
	int target;
	cin >> target;
	if (find(target, array))
		cout << "Found it!" << endl;
	else
		cout << "Not found!" << endl;

	return 0;
}