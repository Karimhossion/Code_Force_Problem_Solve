#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;
int n, v;
struct node
{
	int i;
	int type;
	int capacity;
	double capacity_per_cubic;
	node(int i, int t, int c):i(i), type(t), capacity(c), capacity_per_cubic((c * 1.0)/(t * 1.0)){}
};
vector<node> vec[2];

bool cmp(node &n1, node &n2)
{
	return n1.capacity_per_cubic > n2.capacity_per_cubic;
}
int main()
{
//	fstream cin("a.txt");
	cin>>n>>v;
	int a, b;
	for(int i = 0; i < n; i++)
	{
		cin>>a>>b;
		node tmp(i + 1, a, b);
		if(a == 1)
			vec[0].push_back(tmp);
		else
			vec[1].push_back(tmp);
	}
	sort(vec[0].begin(), vec[0].end(), cmp);
	sort(vec[1].begin(), vec[1].end(), cmp);
	int la = 0, lb = 0;
	vector<int> result;
	int total = 0;
	while (la < vec[0].size() && lb < vec[1].size() && v >= 2)
	{
		if(vec[0][la].capacity_per_cubic > vec[1][lb].capacity_per_cubic)
		{
			if(la == vec[0].size() - 1 && v % 2 != 1)
			{
				int tmp1 = 0, tmp2 = 0;
				int tmp = v;
				for(int j = lb; j < vec[1].size(); j++)
				{
					if(tmp >= 2) tmp1 += vec[1][j].capacity;
					else break;
					tmp -= 2;
				}
				tmp2 += vec[0][la].capacity;
				tmp = v;
				tmp--;
				for(int j = lb; j < vec[1].size(); j++)
				{
					if(tmp >= 2) tmp2 += vec[1][j].capacity;
					else break;
					tmp -= 2;
				}
				if(tmp1 < tmp2)
				{
					total += vec[0][la].capacity;
					v -= vec[0][la].type;
					result.push_back(vec[0][la].i);
					la++;
				}
				else
				{
					total += vec[1][lb].capacity;
					v -= vec[1][lb].type;
					result.push_back(vec[1][lb].i);
					lb++;
					la++;
				}
			}
			else
			{
				total += vec[0][la].capacity;
				v -= vec[0][la].type;
				result.push_back(vec[0][la].i);
				la++;
			}
		}
		else
		{
			total += vec[1][lb].capacity;
			v -= vec[1][lb].type;
			result.push_back(vec[1][lb].i);
			lb++;
		}
	}
	for(int j = lb; j < vec[1].size(); j++)
	{
		if(v >= 2) 
		{
			total += vec[1][j].capacity;
			result.push_back(vec[1][j].i);
		}
		else break;
		v -= 2;
	}
	for(int j = la; j < vec[0].size(); j++)
	{
		if(v >= 1) 
		{
			total += vec[0][j].capacity;
			result.push_back(vec[0][j].i);
		}
		else break;
		v -= 1;
	}
	cout<<total<<endl;
	if(result.empty()) return 0;
	for(int i = 0; i < result.size() - 1; i++)
		cout<<result[i]<<" ";
	cout<<result[result.size() - 1]<<endl;
}