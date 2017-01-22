#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		string s;
		
		while(n)
		{
			if(n==1)
			{
				s+="5";
				break;
			}
			else if(n==2)
			{
				s+="6";
				break;
			}
		   else
		   {
		   
			if(n%2==1)
			{
				s+="5";
			}
			else
		    {
		    	s+="6";
		    }
		     n=(n-1)/2;
		  }
		}
		for(int i=s.length()-1;i>=0;i--)
		{
			cout<<s[i];
		}
		cout<<endl;
	}
}
