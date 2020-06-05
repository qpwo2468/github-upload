/*
��Ŀ��
����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С�
���������ַ���abc,���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba��

*/

#include "head.h"

using namespace std;

vector<string> ans;
vector<char> c_char;

bool comp(string a, string b)
{
	return a < b;
}
vector<string> Permutation(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		c_char.push_back(str[i]);
	}
	dfs(0);
	sort(ans.begin(), ans.end(), comp);
	return ans;
}

void dfs(int x)
{
	if (x == c_char.size() - 1)
	{
		string res(c_char.begin(), c_char.end());
		ans.push_back(res);
		return;
	}

	set<char> st;
	for (int i = x; i < c_char.size(); i++)
	{
		if (st.count(c_char[i]))  continue;
		st.insert(c_char[i]);
		swap(c_char[i], c_char[x]);
		dfs(x + 1);
		swap(c_char[i], c_char[x]);
	}
}

