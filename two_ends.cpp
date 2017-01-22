#include<bits/stdc++.h>
using namespace std;
int table[1005][1005];
int finder(int a[],int i,int l,int k);

int finder(int a[],int i,int l,int k)
{
  if(l<=0)
  {
  	return 0;
  }
  else if(table[i][l]==-1)
  {
  	table[i][l]=max(
	  
	  a[i+1]>=a[i+l-1]?a[i]+finder(a,i+2,l-2,k):a[i]+finder(a,i+1,l-2,k),
	  a[i]>=a[i+l-2]?a[i+l-1]+finder(a,i+1,l-2,k):a[i+l-1]+finder(a,i,l-2,k)
	  
	  );
  }
  return table[i][l];
}
int main()
{
	int n;
	cin>>n;
	int t=0;
	while(n)
	{
		t++;
		for(int i=0;i<=1001;i++)
		{
			for(int j=0;j<=1001;j++)
			{
				table[i][j]=-1;
				
			}
		}
		int a[n+1];
			int greedy=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			greedy+=a[i];
		}
		int dynamic=0;
		int k=0;
		dynamic=finder(a,0,n,k);
	//	cout<<dynamic<<" ";
	    greedy=greedy-dynamic;
	    cout<<"In game "<<t<<", the greedy strategy might lose by as many as "<<dynamic-greedy<<" points."<<endl;
		cin>>n;
	}
}
