#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int x,y;
	cin>>x>>y;
	int a[n+1][m+1];
	int table[n+1][n+1];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int c;
			cin>>c;
			a[i][j]=c;
			table[i][j]=c;
		}
	}
	
	for(int i=n-1;i>=1;i--)
	{
		table[n][i]=table[n][i+1]+table[n][i];
		table[i][n]+=table[i+1][n];
	}
	for(int i=n-1;i>=1;i--)
	{
		for(int j=n-1;j>=1;j--)
		{
			table[i][j]=min(table[i][j]+table[i+1][j],table[i][j]+table[i][j+1]);
		}
	}
	
	int ans=table[x][y]-a[x][y];

	ans=a[x][y]-ans;

	if(ans>=0)
	{
		cout<<"Y"<<" "<<ans<<endl;
	}
	else
	{
		cout<<"N"<<endl;
	}
	
	
	return 0;
}
