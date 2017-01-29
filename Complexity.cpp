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
#define mini(c)             min_element(all(c))
#define maxi(c)             max_element(all(c))
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
