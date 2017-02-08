#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define rep(i,n)            for(ll i=0;i<n;i++)
#define hell                1000000007LL
#define vi                  vector<ll>
#define vii                 vector< vi >
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pii                 pair<int,int>
#define all(c)              c.begin(),c.end()
#define sz(c)               c.size()
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll Max(ll a, ll b) { return a > b ? a : b; }
ll Min(ll a, ll b) { return a < b ? a : b; }
ll power(ll x, ll y,ll p)
{
    ll res=1;
    x=x%p;
    while(y>0)
    {
        if(y&1)
            res=((res%p)*(x%p))%p;
        y=y>>1;
        x=((x%p)*(x%p))%p;
    }
    return res;
}
bool isprime(ll n)
{
    ll z=sqrt(n);
	if(n==2) return true;
	if(n%2==0) return false;
	for(ll i=3;i<=z;i+=2)
    {
		if(n%i==0) return false;
	}
	return true;
}
vi mergeSort(vi arr)
{
    ll n=sz(arr);
    queue< pii > q;
    rep(i,n) q.push(mp(i,i));
    while(sz(q)>1)
    {
        pii x=q.front();
        q.pop();
        pii y=q.front();
        q.pop();
        if((x.se-x.fi+1)+(y.se-y.fi+1)!=Max(x.se,y.se)-Min(x.fi,y.fi)+1)
        {
            q.push(x);
            x=y;
            y=q.front();
            q.pop();
        }
        queue<ll> xa,ya,za;
        rep(j,x.se-x.fi+1) xa.push(arr[x.fi+j]);
        rep(j,y.se-y.fi+1) ya.push(arr[y.fi+j]);
        while(!xa.empty() && !ya.empty())
        {
            za.push(Min(xa.front(),ya.front()));
            if(xa.front()<ya.front())  xa.pop();
            else ya.pop();
        }
        while(!xa.empty())
        {
            za.push(xa.front());
            xa.pop();
        }
        while(!ya.empty())
        {
            za.push(ya.front());
            ya.pop();
        }
        ll st=Min(x.fi,y.fi);
        while(!za.empty())
        {
            arr[st++]=za.front();
            za.pop();
        }
        q.push(mp(Min(x.fi,y.fi),Max(x.se,y.se)));
    }
    return arr;
}
vi quickSort(vi arr)
{
    ll n=sz(arr);
    stack< pii > s;
    s.push(mp(0,n-1));
    while(!s.empty())
    {
        pii z=s.top();
        s.pop();
        ll p=arr[z.fi],c=0;
        rep(i,z.se-z.fi) if(arr[z.fi+i+1]<=p) c++;
        swap(arr[z.fi],arr[z.fi+c]);
        ll in=z.fi+c+1;
        for(ll i=z.fi;i<z.fi+c;i++)
        {
            if(arr[i]>p)
            {
                for(ll j=in;j<=z.se;j++)
                {
                    if(arr[j]<=p)
                    {
                        swap(arr[i],arr[j]);
                        in=j+1;
                        break;
                    }
                }
            }
        }
        if(c-1>0) s.push(mp(z.fi,z.fi+c-1));
        if(z.fi+c+1<z.se) s.push(mp(z.fi+c+1,z.se));
    }
    return arr;
}
int main()
{
    ll t;
    cin>>t;
    rep(i,t)
    {
        ll n;
        cin>>n;
        vi arr(n);
        rep(j,n) cin>>arr[j];
        vi x=mergeSort(arr);
        vi y=quickSort(arr);
        rep(j,n) cout<<x[j]<<" ";
        cout<<endl;
        rep(j,n) cout<<y[j]<<" ";
        cout<<endl;
    }
    return 0;
}
