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
vii add(vii A,vii B,ll n)
{
    vii C(n);
    rep(i,n) rep(j,n) C[i].pb(0);
    rep(i,n) rep(j,n) C[i][j]=(A[i][j]+B[i][j]);
    return C;
}
vii sub(vii A,vii B,ll n)
{
    vii C(n);
    rep(i,n) rep(j,n) C[i].pb(0);
    rep(i,n) rep(j,n) C[i][j]=(A[i][j]-B[i][j]);
    return C;
}
vii multiply(vii A,vii B,ll n)
{
    vii ans(n,vi(n,0));
    if(n==1) ans[0][0]=A[0][0]*B[0][0];
    else
    {
        vii a(n/2,vi(n/2,0)),b(n/2,vi(n/2,0)),c(n/2,vi(n/2,0)),d(n/2,vi(n/2,0));
        vii e(n/2,vi(n/2,0)),f(n/2,vi(n/2,0)),g(n/2,vi(n/2,0)),h(n/2,vi(n/2,0));
        rep(i,n/2) rep(j,n/2) a[i][j]=A[i][j];
        rep(i,n/2) rep(j,n/2) b[i][j]=A[i][j+n/2];
        rep(i,n/2) rep(j,n/2) c[i][j]=A[i+n/2][j];
        rep(i,n/2) rep(j,n/2) d[i][j]=A[i+n/2][j+n/2];
        rep(i,n/2) rep(j,n/2) e[i][j]=B[i][j];
        rep(i,n/2) rep(j,n/2) f[i][j]=B[i][j+n/2];
        rep(i,n/2) rep(j,n/2) g[i][j]=B[i+n/2][j];
        rep(i,n/2) rep(j,n/2) h[i][j]=B[i+n/2][j+n/2];
        vii p1=multiply(a,sub(f,h,n/2),n/2),p2=multiply(add(a,b,n/2),h,n/2),p3=multiply(add(c,d,n/2),e,n/2),p4=multiply(d,sub(g,e,n/2),n/2);
        vii p5=multiply(add(a,d,n/2),add(e,h,n/2),n/2),p6=multiply(sub(b,d,n/2),add(g,h,n/2),n/2),p7=multiply(sub(a,c,n/2),add(e,f,n/2),n/2);
        rep(i,n/2)
        {
            rep(j,n/2)
            {
                ans[i][j]=p5[i][j]+p4[i][j]-p2[i][j]+p6[i][j];
                ans[i][j+n/2]=p1[i][j]+p2[i][j];
                ans[i+n/2][j]=p3[i][j]+p4[i][j];
                ans[i+n/2][j+n/2]=p1[i][j]+p5[i][j]-p3[i][j]-p7[i][j];
            }
        }
    }
    return ans;
}
int main()
{
    ll n,it=0;
    cin>>n;
    while((1<<it)<n) it++;
    ll N=1<<it;
    vii A(N),B(N),C(N);
    rep(i,N) rep(j,N) A[i].pb(0);
    rep(i,N) rep(j,N) B[i].pb(0);
    rep(i,N) rep(j,N) C[i].pb(0);
    rep(i,n) rep(j,n) cin>>A[i][j];
    rep(i,n) rep(j,n) cin>>B[i][j];
    C=multiply(A,B,N);
    rep(i,n)
    {
        rep(j,n)
        {
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
