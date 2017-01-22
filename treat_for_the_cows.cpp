#include<bits/stdc++.h>
using namespace std;
int table[2001][2001];
int finder(int a[],int i,int l,int k)
{
	if(l<=0)
	{
		return 0;
	}
	else if(table[i][l]==0)
	{
		table[i][l]=max(
		a[i]*k+finder(a,i+1,l-1,k+1),a[i+l-1]*k+finder(a,i,l-1,k+1)
		);
	}
	return table[i][l];
}
int main()
{
	int n;
	cin>>n;
	int a[n+1];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<=n;i++)
	{
	   for(int j=0;j<=n;j++)
	   {
		table[i][j]=0;
	   }
    }
    int k=0;
    int ans=finder(a,0,n,k+1);
    cout<<ans<<endl;
}
