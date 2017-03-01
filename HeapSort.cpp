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
ll N=100000,siz=0;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll Max(ll a, ll b) { return a > b ? a : b; }
ll Min(ll a, ll b) { return a < b ? a : b; }
void Add(ll x,vi &minheap)
{
    minheap[siz]=x;
    ll c=siz;
    while(c!=0)
    {
        if(minheap[(c-1)/2]>minheap[c])
        {
            swap(minheap[c],minheap[(c-1)/2]);
            c=(c-1)/2;
        }
        else break;
    }
    siz++;
    return;
}
void Del(vi &minheap)
{
    swap(minheap[0],minheap[siz-1]);
    ll c=0;
    siz--;
    while(c<siz)
    {
        if(2*c+1>=siz || (Min(minheap[2*c+1],minheap[2*c+2])>=minheap[c] && 2*c+2<siz) || (2*c+1==siz-1 && minheap[2*c+1]>=minheap[c])) break;
        else if((minheap[2*c+1]<minheap[2*c+2] && 2*c+2<=siz-1) || (2*c+1==siz-1 && minheap[2*c+1]<minheap[c]))
        {
            swap(minheap[c],minheap[2*c+1]);
            c=2*c+1;
        }
        else if(2*c+2<=siz-1 && minheap[2*c+2]<minheap[c])
        {
            swap(minheap[c],minheap[2*c+2]);
            c=2*c+2;
        }
    }
    return;
}
vi Sort(vi &minheap)
{
    vi ans;
    vi tempheap=minheap;
    ll tempsiz=siz;
    while(siz>0)
    {
        ans.pb(minheap[0]);
        Del(minheap);
    }
    minheap=tempheap;
    siz=tempsiz;
    return ans;
}
int main()
{
    vi minheap(N,hell);
    while(true)
    {
        cout<<"1. Insert\n2. Delete\n3. Sort\n4. Exit\n";
        ll t;
        cin>>t;
        if(t==1)
        {
            cout<<"Enter Element\n";
            ll x;
            cin>>x;
            Add(x,minheap);
        }
        else if(t==2)
        {
            if(siz==0) cout<<"Heap is Empty"<<endl;
            else Del(minheap);
        }
        else if(t==3)
        {
            vi z=Sort(minheap);
            rep(i,z.size()) cout<<z[i]<<" ";
            cout<<endl;
        }
        else break;
    }
    return 0;
}
