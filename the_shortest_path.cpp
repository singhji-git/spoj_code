#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sf(x) scanf("%lld",&x)
#define pp pair<ll,ll>
#define INF LONG_LONG_MAX
int main()
{
	ll t,n,p,x,c,m1;
	sf(t);
	while(t--)
	{
		char s[15];
		unordered_map<string,ll> m;
		sf(n);
		vector<pp> v[n+1];
		ll i=1,n1=n;
		while(n1--)
		{
			scanf("%s",s);
			m.insert(make_pair(s,i));
			sf(p);
			while(p--)
			{
				sf(x);sf(c);
				v[i].push_back(make_pair(x,c));
			}
			i++;
		}
		char s1[15];
		char s2[15];
		sf(m1);
		while(m1--)
		{
			scanf("%s",s1);
			scanf("%s",s2);
			ll s=m[s1];
			ll d=m[s2];
			priority_queue< pp,vector<pp>,greater<pp> > q;
			bool mark[n+1];
			memset(mark,false,sizeof mark);
			vector<ll> dis(n+1,INF);
			dis[s]=0;
			q.push(make_pair(0,s));
			while(!q.empty())
			{
				ll y2=q.top().second;
				mark[y2]=true;
				q.pop();
				for(i=0;i<v[y2].size();i++)
				{
					ll x1=v[y2][i].first;
					ll x2=v[y2][i].second;
					if(!mark[x1]&&(dis[x1]>dis[y2]+x2))
					{
					dis[x1]=dis[y2]+x2;
					q.push(make_pair(dis[x1],x1));
				   }
				}
				if(y2==d)
				break;
			}
			cout<<dis[d]<<endl;
		}
		cout<<endl;
	}
} 
