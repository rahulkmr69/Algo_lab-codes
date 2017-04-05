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
    ll n,w;
    cin>>n>>w;
    vi value(n),weight(n);
    rep(i,n) cin>>value[i];
    rep(i,n) cin>>weight[i];
    ll dp[n+1][w+1];
    rep(j,w+1) dp[0][j]=0;
    rep(i,n+1) dp[i][0]=0;
    rep(i,n)
    {
        rep(j,w)
        {
            dp[i+1][j+1]=dp[i][j+1];
            if(j+1-weight[i]>=0) dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j+1-weight[i]]+value[i]);
        }
    }
    cout<<dp[n][w];
    return 0;
}
