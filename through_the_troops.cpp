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
		int a[n+1][4];
		int table[n+1][4];
		for(int i=0;i<n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			table[i][0]=a[i][0];table[i][1]=a[i][1];table[i][2]=a[i][2];
		}
		
		for(int i=n-2;i>=0;i--)
		{
			table[i][0]=min(table[i][0]+table[i+1][1],table[i][0]+table[i+1][2]);
			table[i][1]=min(table[i][1]+table[i+1][0],table[i][1]+table[i+1][2]);
			table[i][2]=min(table[i][2]+table[i+1][1],table[i][2]+table[i+1][0]);
		}
		int ans=min(table[0][0],table[0][1]);
		ans=min(ans,table[0][2]);
		cout<<ans<<endl;
	}
	return 0;
}
