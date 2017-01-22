#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pp pair<ll,ll>
#define jj pair<pp,ll>
#define mp make_pair
#define sf(x) scanf("%lld",&x)
bool mark[1002][1002];
char s[1002][1002];
int main()
{
	ll t,r,c,i,j;
	sf(t);
	while(t--)
	{
		ll max1=-1;
		sf(c);sf(r);
		for(i=1;i<=r;i++)
		{
			for(j=1;j<=c;j++)
			cin>>s[i][j];
		}
		for(i=0;i<=r;i++)
		{
			for(j=0;j<=c;j++)
			mark[i][j]=false;
		}
		int temp=0;
		ll x1,y1;
		for(i=1;i<=r;i++)
		{
			for(j=1;j<=c;j++)
			{
				if(s[i][j]=='.'&&mark[i][j]==false)
				{
					temp=1;
					stack<jj> s1;
					s1.push(mp(mp(i,j),0));
					while(!s1.empty())
					{
						ll x=s1.top().first.first;
						ll y=s1.top().first.second;
						ll sd=s1.top().second;
						mark[x][y]=true;
						s1.pop();
						ll c1=0,dis;
						if((x+1)<=r&&s[x+1][y]=='.'&&mark[x+1][y]==false)
						{
							dis=sd+1;
						s1.push(mp(mp(x+1,y),dis));
						c1++;
					    }
						if((x-1)>=0&&s[x-1][y]=='.'&&mark[x-1][y]==false)
						{
							dis=sd+1;
						s1.push(mp(mp(x-1,y),dis));
						c1++;
					     }
						if((y+1)<=c&&s[x][y+1]=='.'&&mark[x][y+1]==false)
						{
							dis=sd+1;
						s1.push(mp(mp(x,y+1),dis));
						c1++;
					     }
						if((y-1)>=0&&s[x][y-1]=='.'&&mark[x][y-1]==false)
						{
							dis=sd+1;
						s1.push(mp(mp(x,y-1),dis));
						c1++;
					     }
					     if(c1==0)
					     {
					     	if(sd>max1)
					     	{
					     	max1=sd;
					     	x1=x;
					     	y1=y;
					        }
					     }
					}
					break;
				}
			}
			if(temp==1)
			break;
		}
		for(i=0;i<=r;i++)
		{
			for(j=0;j<=c;j++)
			mark[i][j]=false;
		}
		ll max2=-1;
		if(max1!=-1)
		{
		stack<jj> s2;
		s2.push(mp(mp(x1,y1),0));
		          while(!s2.empty())
					{
						ll x=s2.top().first.first;
						ll y=s2.top().first.second;
						ll sd=s2.top().second;
						mark[x][y]=true;
						s2.pop();
						ll c1=0,dis;
						if((x+1)<=r&&s[x+1][y]=='.'&&mark[x+1][y]==false)
						{
							dis=sd+1;
						s2.push(mp(mp(x+1,y),dis));
						c1++;
					    }
						if((x-1)>=0&&s[x-1][y]=='.'&&mark[x-1][y]==false)
						{
							dis=sd+1;
						s2.push(mp(mp(x-1,y),dis));
						c1++;
					     }
						if((y+1)<=c&&s[x][y+1]=='.'&&mark[x][y+1]==false)
						{
							dis=sd+1;
						s2.push(mp(mp(x,y+1),dis));
						c1++;
					     }
						if((y-1)>=0&&s[x][y-1]=='.'&&mark[x][y-1]==false)
						{
							dis=sd+1;
						s2.push(mp(mp(x,y-1),dis));
						c1++;
					     }
					     if(c1==0)
					     {
					     	if(sd>max2)
					     	{
					     	max2=sd;
					        }
					     }
					}
				}
		if(max1==-1)
		printf("Maximum rope length is 0.\n");
		else
		printf("Maximum rope length is %lld.\n",max2);
	}
} 

