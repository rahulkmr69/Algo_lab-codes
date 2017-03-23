#include<bits/stdc++.h>
#include<graphics.h>
#include<windows.h>
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
ll root(vi &dsu,ll x)
{
    while(dsu[x]!=x)
    {
        dsu[x]=dsu[dsu[x]];
        x=dsu[x];
    }
    return x;
}
void union1(vi &dsu,ll x,ll y)
{
    ll x1=root(dsu,x);
    ll y1=root(dsu,y);
    dsu[x1]=dsu[y1];
    return;
}
vector< vector< pii > > prim(vector< vector< pii > > &g,ll n,ll x)
{
    vector< vector< pii > > ans(n);
    vi vis(n,0);
    priority_queue< pair<ll,pair<ll,ll> >,vector< pair<ll,pair<ll,ll> > >,greater< pair<ll,pair<ll,ll> > > > q;
    q.push(mp(0,mp(0,0)));
    while(!q.empty())
    {
        pair<ll,pair<ll,ll> > z=q.top();
        q.pop();
        if(vis[z.se.se]==0)
        {
            vis[z.se.se]=1;
            if(z.se.fi!=z.se.se) ans[z.se.fi].pb(mp(z.fi,z.se.se));
            if(z.se.fi!=z.se.se) ans[z.se.se].pb(mp(z.fi,z.se.fi));
            rep(i,sz(g[z.se.se]))
            {
                if(vis[g[z.se.se][i].se]==0)
                {
                    q.push(mp(g[z.se.se][i].fi,mp(z.se.se,g[z.se.se][i].se)));
                }
            }
        }
    }
    return ans;
}
vector< vector< pii > > kruskal(vector< vector< pii > > &g,ll n,ll m)
{
    vector< pair<ll,pair<ll,ll> > > edges(2*m);
    ll in=0;
    rep(i,n)
    {
        rep(j,sz(g[i]))
        {
            edges[in]=mp(g[i][j].fi,mp(i,g[i][j].se));
            in++;
        }
    }
    sort(all(edges));
    vi dsu(n);
    rep(i,n) dsu[i]=i;
    vector< vector< pii > > ans(n);
    rep(i,2*m)
    {
        pair<ll,pair<ll,ll> > z=edges[i];
        if(root(dsu,z.se.fi)!=root(dsu,z.se.se))
        {
            union1(dsu,z.se.fi,z.se.se);
            ans[z.se.fi].pb(mp(z.fi,z.se.se));
            ans[z.se.se].pb(mp(z.fi,z.se.fi));
        }
    }
    return ans;
}
ll input(ll x,ll y)
{
    string s;
    char ss[200],ch;
    ll j=0;
    while(true)
    {
        ch=getch();
        if((ll)ch==13 || ch==' ') break;
        s.pb(ch);
        ss[j++]=ch;
        ss[j]='\0';
        outtextxy(x,y,ss);
    }
    ll n=0,c=1;
    reverse(all(s));
    rep(i,sz(s))
    {
        n+=(c*(s[i]-'0'));
        c*=10;
    }
    return n;
}
string convert(ll n)
{
    string ans;
    while(n>0)
    {
        ans.pb((n%10)+'0');
        n/=10;
    }
    reverse(all(ans));
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    initwindow(1500,1000,"Minimum Spanning Tree");
    settextstyle(6,0,2);
    setcolor(BLUE);
    outtextxy(100,100,"Enter no. of Nodes: ");
    ll n,m;
    //cin>>n>>m;
    n=input(550,100);
    outtextxy(100,150,"Enter no. of Edges: ");
    m=input(550,150);
    vector< pair<ll,pii > > arr(n);
    ll in=0;
    while(true)
    {
        POINT P;
        GetCursorPos(&P);
        if(GetAsyncKeyState(VK_LBUTTON))
        {
            arr[in]=mp(in,mp(P.x,P.y));
            in++;
            setcolor(YELLOW);
            circle(P.x,P.y,6);
            char z[5];
            string Z=convert(in);
            rep(i,sz(Z)) z[i]=Z[i];
            z[sz(Z)]='\0';
            outtextxy(P.x+8,P.y+8,z);
            if(in==n) break;
            delay(200);
        }
    }
    vector< vector< pii > > g(n),ans;
    outtextxy(100,200,"Enter Edges: ");
    setcolor(RED);
    rep(i,m)
    {
        ll x,y,w,t=-1;
        //x=input(550,200+i*20);
        //y=input(600,200+i*20);
        //w=input(550,200+i*20);
        //cin>>x>>y>>w;
        while(true)
        {
            POINT P;
            GetCursorPos(&P);
            if(GetAsyncKeyState(VK_LBUTTON))
            {
                ll d=LLONG_MAX;
                rep(j,n)
                {
                    ll z=(arr[j].se.fi-P.x)*(arr[j].se.fi-P.x)+(arr[j].se.se-P.y)*(arr[j].se.se-P.y);
                    if(z<d)
                    {
                        t=j;
                        d=z;
                    }
                }
                delay(200);
                break;
            }
        }
        x=t;
        circle(arr[x].se.fi,arr[x].se.se,6);
        while(true)
        {
            POINT Q;
            GetCursorPos(&Q);
            if(GetAsyncKeyState(VK_LBUTTON))
            {
                ll d=LLONG_MAX;
                rep(j,n)
                {
                    ll z=(arr[j].se.fi-Q.x)*(arr[j].se.fi-Q.x)+(arr[j].se.se-Q.y)*(arr[j].se.se-Q.y);
                    if(z<d)
                    {
                        t=j;
                        d=z;
                    }
                }
                delay(200);
                break;
            }
        }
        y=t;
        circle(arr[y].se.fi,arr[y].se.se,6);
        line(arr[x].se.fi,arr[x].se.se,arr[y].se.fi,arr[y].se.se);
        w=(arr[y].se.fi-arr[x].se.fi)*(arr[y].se.fi-arr[x].se.fi)+(arr[y].se.se-arr[x].se.se)*(arr[y].se.se-arr[x].se.se);
        g[x].pb(mp(w,y));
        g[y].pb(mp(w,x));
    }
    closegraph();
    initwindow(1500,1000,"Result");
    settextstyle(6,0,2);
    setcolor(BLUE);
    ll flag;
    //cin>>flag;
    outtextxy(100,100,"Enter 0 for Prim's and 1 for Kruskal's: ");
    flag=input(500,100);
    if(flag) ans=prim(g,n,0);
    else ans=kruskal(g,n,m);
    rep(i,n)
    {
        circle(arr[i].se.fi,arr[i].se.se,6);
        char z[5];
        string Z=convert(i+1);
        rep(j,sz(Z)) z[j]=Z[j];
        z[sz(Z)]='\0';
        outtextxy(arr[i].se.fi+8,arr[i].se.se+8,z);
    }
    rep(i,n)
    {
        rep(j,sz(g[i]))
        {
            //cout<<arr[i].se.fi<<" "<<arr[i].se.se<<" "<<arr[g[i][j].se].se.fi<<" "<<arr[g[i][j].se].se.se<<endl;
            line(arr[i].se.fi,arr[i].se.se,arr[g[i][j].se].se.fi,arr[g[i][j].se].se.se);
        }
    }
    setcolor(YELLOW);
    rep(i,n)
    {
        rep(j,sz(ans[i]))
        {
            line(arr[i].se.fi,arr[i].se.se,arr[ans[i][j].se].se.fi,arr[ans[i][j].se].se.se);
        }
    }
    getch();
    closegraph();
    return 0;
}
