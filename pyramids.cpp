#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sf(x) scanf("%lf",&x)
#define pp pair<ll,ll>
#define mp make_pair
vector<ll> v,v1;
double cosine(double a,double b,double c)
{
	double ty=(a*a+b*b-c*c)/(2.0*a*b);
	return ty;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		double a,b,c,d,e,f;
		sf(a);sf(b);sf(c);sf(d);sf(e);sf(f);
		double c1,c2,c3;
		c1=cosine(c,e,a);
		c2=cosine(e,f,d);
		c3=cosine(f,c,b);
	//	cout<<c1<<" "<<c2<<" "<<c3<<endl;
		double tr=sqrt(1+2*c1*c2*c3-c1*c1-c2*c2-c3*c3);
		double ans=(c*e*f*tr)/6;
		printf("%.4lf\n",ans);
	}
} 
