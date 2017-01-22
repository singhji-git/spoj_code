#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t)
	{
		int n=t;
        long long int ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=(n-i+1)*(n-i+1);
		}
		cout<<ans<<endl;
		cin>>t;
	}
}
