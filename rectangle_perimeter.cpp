#include<bits/stdc++.h>
#define x first
#define y second
#define ll long long int
using namespace std;
int table[1001][2];
int find(pair<int,int>arr[],int index,int n,int p,int v)
{

  	if(index == n)
		 return 0;
  if(table[index][v]==0){
			
	int x1=arr[index].x;
	int y1=arr[index].y;
    int ans1=y1+find(arr,index+1,n,x1,0);
    int ans2=x1+find(arr,index+1,n,y1,1);
    if(index>0){
    	 table[index][v]=max(abs(x1-p)+ans1,abs(y1-p)+ans2);
    }
   
    else
     table[index][v]= max(ans1,ans2);
}
  return table[index][v];
}

int main()
{
	int n;
	cin>>n;
	pair<int,int>arr[n+1];
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		arr[i]=make_pair(a,b);
	}
	cout<<find(arr,0,n,0,0);

}
