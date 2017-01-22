#include<bits/stdc++.h>
using namespace std;
struct data
{
	int value;
	int pos;
};
struct query
{
	int i;
	int j;
	int k;
	int pos;
};
void update(int seg[],int pos,int n){
    while(pos<=n){
        seg[pos]+=1;
        pos += (pos & -pos);
    }
}
int query_(int seg[],int pos){
    int result = 0;
    while(pos){
        result += seg[pos];
        pos -= (pos & -pos);
    }
    return result;
}
bool cmp( const data &a, const data &b)
{
	return a.value>b.value;
}
bool compare( const query &a, const query &b)
{
	return a.k > b.k;
}
int main()
{
	int  n;
	cin>>n;
	data a[n+5];
	int seg[n+6];
    for(int i=0;i<=n+5;i++)
    {
    	seg[i]=0;
    }
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i].value),a[i].pos=i+1;
	}
	sort(a,a+n,cmp);

	
	int  q_no;
	scanf("%d",&q_no);
	query q[q_no+5];
	for(int i=0;i<q_no;i++)
	{
		scanf("%d %d %d",&q[i].i,&q[i].j,&q[i].k),q[i].pos=i;
	}

	sort(q,q+q_no,compare);

	int ans[q_no+5];
    	int pos=0;
	for(int i=0;i<q_no;i++)
	{
		while(pos<n && a[pos].value > q[i].k)
		{
			update(seg,a[pos].pos,n);
			pos++;
		}
		ans[q[i].pos]=query_(seg,q[i].j)-query_(seg,q[i].i-1);
	}
	for(int i=0;i<q_no;i++)
	{
		printf("%d\n",ans[i]);
	}
}
