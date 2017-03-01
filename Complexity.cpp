#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define rep(i,n)            for(ll i=0;i<n;i++)
#define hell                1000000007LL
#define vi                  vector<int>
#define vii                 vector< vi >
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pii                 pair<int,int>
#define all(c)              c.begin(),c.end()
ll Max(ll a, ll b) { return a > b ? a : b; }
ll Min(ll a, ll b) { return a < b ? a : b; }
void N()
{
    ll z=1000000,n=1000000;
    rep(i,n) rep(k,100) z++;
}
void NN()
{
    ll z=1000000,n=100000;
    rep(i,n) rep(j,n) z++;
}
void Nlog()
{
    ll z=1000000,n=10000000;
    ll x=log2(n);
    rep(i,n) rep(j,x) z++;
}
int main()
{
    clock_t start;
    double duration;
    start=clock();
    //N();
    //NN();
    //Nlog();
    duration=(100000.0*(clock()-start))/(double)CLOCKS_PER_SEC;
    printf("%lf",duration);
}
