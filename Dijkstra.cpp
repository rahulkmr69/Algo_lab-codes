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
vi dijkstra(vector< vector< pii > > &g,ll n,ll st)
{
    vi ans(n,1e15);
    ans[st]=0;
    priority_queue< pii,vector< pii >,greater< pii > > q;
    q.push(mp(0,st));
    while(!q.empty())
    {
        pii z=q.top();
        q.pop();
        if(z.fi>ans[z.se]) continue;
        else
        {
            rep(i,sz(g[z.se]))
            {
                if(ans[z.se]+g[z.se][i].fi<ans[g[z.se][i].se])
                {
                    ans[g[z.se][i].se]=ans[z.se]+g[z.se][i].fi;
                    q.push(mp(ans[g[z.se][i].se],g[z.se][i].se));
                }
            }
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin>>n>>m;
    vector< vector< pii > > g(n);
    rep(i,m)
    {
        ll x,y,w;
        cin>>x>>y>>w;
        x--;
        y--;
        g[x].pb(mp(w,y));
        //g[y].pb(mp(w,x));
    }
    ll st;
    cin>>st;
    st--;
    vi ans=dijkstra(g,n,st);
    return 0;
}
