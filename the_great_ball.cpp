#include<bits/stdc++.h>
#define ll long long int
using namespace std;
	int main()
	{
		ll t;
		cin>>t;
		while(t--)
		{
			ll n;
			cin>>n;
		    ll a[2*n+5];
		    ll b[2*n+5];
		    map<ll,ll>mp;
		    ll k=n;
			for(ll i=0;i<n;i++)
			{
				cin>>a[i]>>a[k];
				
				mp[a[i]]+=1;
				mp[a[k]]+=-1;
				k++;
			}
			sort(a,a+2*n);
			
		
			
			ll maxi=mp[a[0]];
			for(int i=1;i<2*n;i++)
			{
				mp[a[i]]+=mp[a[i-1]];
				//cout<<" "<<mp[a[i]]<<" ";
				maxi=max(mp[a[i]],maxi);
			}
			cout<<maxi<<endl;
		}
	}

