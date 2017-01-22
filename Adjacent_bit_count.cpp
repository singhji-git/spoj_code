#include<bits/stdc++.h>
using namespace std;
long long int table[2][102][102];
long long int table1[100];
long long int find(int n,int k,int p)
{
	
	if(table[p][n][k]==-1)
	{
		if(n==0 && k==0)
		{
			table[p][n][k]= 1;
		}
		else if(n==0)
		{
		table[p][n][k]=  0;
		}
		else if(k==0)
		{
			if(n==1)
			{
				table[p][n][k]=  1;
			}
			else
			{
			
				if(p==0)
			table[p][n][k]=  table1[n];
				else
			table[p][n][k]=  table1[n-1];
			}
		}
		else
		{
			int x=find(n-1,k,0);
			int y=find(n-1,k,1);
		    int z=find(n-1,k-1,1);
		if(p==0)
			table[0][n][k]=x+y;
		else
			table[1][n][k]=x+z;
		}	
	}
    return table[p][n][k];
}
int main()
{
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<=100;j++)
		{
			for(int k=0;k<=100;k++)
			{
				table[i][j][k]=-1;
			}
		}
	}
	int a0=1;
	int a1=1;
	table1[0]=0;
	table1[1]=2;
	
	for(int i=2;i<=100;i++)
	{
		int temp=a1;
		a1=a0;
		a0=temp+a0;
		table1[i]=a0+a1;
	}
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,x;
		cin>>x>>n>>k;
		long long int ans=find(n,k,0);
		cout<<x<<" "<<ans<<endl;
	}
}
