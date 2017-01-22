#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
         ll x=k-1;
         int p=0;
         while(x>=2)
         {
         	ll z=log2(x);
         	ll y=pow(2,z);
            // cout<<x<<" "<<y<<endl;
         	x=x-y;
         	if(p==0)
         		p=1;
         	else
         		p=0;
         }
         if(p==0)
         {
         	if(x==0)
         		cout<<"Male"<<endl;
         	else
         		cout<<"Female"<<endl;
         }
         else
         {
         	if(x==0)
         		cout<<"Female"<<endl;
         	else
         		cout<<"Male"<<endl;
         		
         }
	}
}
