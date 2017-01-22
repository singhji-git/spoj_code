
#include<bits/stdc++.h>
using namespace std;
 

int getSum(int BITree[], int index)
{
    int sum = 0; 
 
    while (index > 0)
    {
        
        sum += BITree[index];
 
      
        index -= index & (-index);
    }
    return sum;
}
 

void updateBIT(int BITree[], int n, int index, int val)
{
    
    while (index <= n)
    {
       BITree[index] += val;
 

       index += index & (-index);
    }
}
 

int getInvCount(int arr[], int n)
{
    int invcount = 0; 
 
  
    int maxElement = 0;
    for (int i=0; i<n; i++)
        if (maxElement < arr[i])
            maxElement = arr[i];

    int BIT[maxElement+1];
    for (int i=1; i<=maxElement; i++)
        BIT[i] = 0;
 

    for (int i=n-1; i>=0; i--)
    {

        invcount += getSum(BIT, arr[i]-1);
 

        updateBIT(BIT, maxElement, arr[i], 1);
    }
 
    return invcount;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	   int n;
	   scanf("%d",&n);
	   map<string,int>mp;
	   string s[n+5],s1[n+5];
	   for(int i=0;i<n;i++)
	   {
	     cin>>s[i];
	   }
	   for(int i=0;i<n;i++)
	   {
	      cin>>s1[i];
	      mp[s1[i]]=i+1;
	   }
	   int arr[n+1];
	   for(int i=0;i<n;i++)
	   {
	      arr[i]=mp[s[i]];
	   }
	   
	   int count=getInvCount(arr,n);
	   
	   printf("%d\n",count);
	}
}
