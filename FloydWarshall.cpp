#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ld                  long double
#define rep(i,n)            for(ll i=0;i<n;i++)
#define hell                1000000007LL
#define vi                  vector<ll>
#define vii                 vector< vi >
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pii                 pair<ll,ll>
#define all(c)              c.begin(),c.end()
#define sz(c)               c.size()
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin>>n>>m;
    vii g(n,vi(n,1e15));
    rep(i,n) g[i][i]=0;
    rep(i,m)
    {
        ll x,y,w;
        cin>>x>>y>>w;
        x--;
        y--;
        g[x][y]=w;
        g[y][x]=w;
    }
    ll dp[n][n];
    rep(i,n) rep(j,n) dp[i][j]=g[i][j];
    rep(k,n)
    {
        rep(i,n)
        {
            rep(j,n)
            {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    rep(i,n)
    {
        rep(j,n)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
