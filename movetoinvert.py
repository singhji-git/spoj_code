
def func(n,i):
    ans=0
    if((n-i)%2==1):
        k=n-i
        ans= ((k+1)*(k+1)/4) + (i-1)*(i)/2
    else:
        k=n-i
        ans=k*(k/2+1)/2+(i-1)*(i)/2
    return ans

t=int(raw_input())
while (t):
    n=int(raw_input())
    i=n/3
    ans=min(func(n,i),func(n,i-1))
    ans=min(ans,func(n,i+1))
    print ans
    t=t-1
    
    
	
