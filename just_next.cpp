#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int>vec;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			vec.push_back(x);
		}
		int i=vec.size()-1;
		int maxi=INT_MIN;
		
		while(i>=0)
		{
			if(vec[i]<maxi)
			{
				break;
			}
			else
			{
				maxi=vec[i];
				i--;
			}
		}
		if(i==-1)
		{
			cout<<-1<<endl;
			continue;
		}
		int mini=INT_MAX;
		int index;
		
		for(int j=i+1;j<n;j++)
		{
			if(vec[j]>vec[i])
			{
				mini=min(mini,vec[j]);
				index=j;
			}
		}
		
		vec[index]=INT_MAX;
		sort(vec.begin()+i,vec.end());
		for(int j=0;j<i;j++)
		{
			cout<<vec[j];
		}
		cout<<mini;
		for(int j=i;j<n-1;j++)
		{
			cout<<vec[j];
		}
		cout<<endl;
		
	}
}
