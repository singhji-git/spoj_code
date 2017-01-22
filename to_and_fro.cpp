#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t)
	{
		string s;
		cin>>s;
		int len=s.length();
		int x=2*t-1;
		int y=1;
		string s1;
		for(int i=0;i<t;i++)
		{
			int index=i;
			int p=0;
			while(index<len)
			{
				s1+=s[index];
				//cout<<s[index];
				if(p==0)
				{
					index+=x;
					p=1;
				}
				else
				{
					index+=y;
					p=0;
				}
			}
			x=x-2;
			y=y+2;
		}
		cout<<s1<<endl;
		cin>>t;
	}
}
