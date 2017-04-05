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
struct Node
{
    ll k;
    char c;
    struct Node* l;
    struct Node* r;
};
typedef struct Node node;
struct cmp
{
    bool operator()(node* x,node* y)
    {
        return (x->k > y->k);
    }
};
void show(node* x,string s)
{
    if(x->l==NULL || x->r==NULL) cout<<x->c<<" "<<s<<endl;
    else
    {
        show(x->l,s+'0');
        show(x->r,s+'1');
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    vector< pair<char,ll> > arr(n);
    rep(i,n) cin>>arr[i].fi>>arr[i].se;
    priority_queue<node*,vector<node*>,cmp > q;
    rep(i,n)
    {
        node* z;
        z=new node;
        z->k=arr[i].se;
        z->l=NULL;
        z->r=NULL;
        z->c=arr[i].fi;
        q.push(z);
    }
    while(sz(q)>1)
    {
        node* a=q.top();
        q.pop();
        node* b=q.top();
        q.pop();
        node* z;
        z=new node;
        z->k=a->k+b->k;
        z->l=a;
        z->r=b;
        z->c='$';
        q.push(z);
    }
    node *x=q.top();
    q.pop();
    show(x,"");
    return 0;
}
