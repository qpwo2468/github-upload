/*
��Ŀ��
����n���������ҳ�������С��K������
��������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4,��

˼·��
 1. ����
 2. ���������
 3. ����ѡ��
*/

#include "head.h"

using namespace std;

//2
vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
    vector<int> vec;
    if (k == 0) return vec;
    if (input.size() < k) return vec;
    priority_queue<int>Q;
    for (int i = 0; i < k; i++) Q.push(input[i]);
    for (int i = k; i < input.size(); i++)
    {
        if (Q.top() > input[i])
        {
            Q.pop();
            Q.push(input[i]);
        }
    }
    for (int i = 0; i < k; i++)
    {
        vec.push_back(Q.top());
        Q.pop();
    }
    return vec;
}



//3
int partition(vector<int>& nums, int l, int r)
{
    int pivot = nums[r];
    int i = l - 1;
    for (int j = l; j <= r - 1; j++)
    {
        if (nums[j] <= pivot)
        {
            i = i + 1;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[r]);
    return i + 1;
}

//��������Ļ���
int randomized_partition(vector<int>& nums, int l, int r)
{
    int i = rand() % (r - 1 + 1) + 1;
    swap(nums[r], nums[i]);
    return partition(nums, l, r);
}
void randomized_selected(vector<int>& arr, int l, int r, int k)
{
    if (l >= r) return;
    int pos = randomized_partition(arr, l, r);
    int num = pos - 1 + 1;
    if (k == num) return;
    else if (k < num) randomized_selected(arr, l, pos - 1, k);
    else randomized_selected(arr, pos + 1, r, k - num);
}

vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
    srand((unsigned)time(NULL));
    randomized_selected(input, 0, input.size() - 1, k);
    vector<int>vec;
    for (int i = 0; i < k; i++) vec.push_back(input[i]);

    return vec;
}
    
