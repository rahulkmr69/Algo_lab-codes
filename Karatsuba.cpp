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
#define pii                 pair<ll,ll>
#define all(c)              c.begin(),c.end()
#define mini(c)             min_element(all(c))
#define maxi(c)             max_element(all(c))
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return a * (b / gcd(a, b));
}
ll Max(ll a, ll b)
{
    return a > b ? a : b;
}
ll Min(ll a, ll b)
{
    return a < b ? a : b;
}
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
    for(ll i=3; i<=z; i+=2)
    {
        if(n%i==0) return false;
    }
    return true;
}
string addstrings(string s1,string s2)
{
    reverse(all(s1));
    reverse(all(s2));
    while(s1.size()>s2.size()) s2.pb('0');
    while(s2.size()>s1.size()) s1.pb('0');
    reverse(all(s1));
    reverse(all(s2));
    string s3;
    char c='0';
    ll l1=s1.size();
    while(l1!=0)
    {
        l1--;
        char t=c,z='0';
        if(t=='0')
        {
            if(s1[l1]=='1' && s2[l1]=='1') c='1';
            else if(!(s1[l1]=='0' && s2[l1]=='0')) z='1';
        }
        else
        {
            if(!(s1[l1]=='0' && s2[l1]=='0')) c='1';
            if(s1[l1]==s2[l1])
            {
                z='1';
                if(s1[l1]=='0') c='0';
            }
        }
        s3.pb(z);
    }
    if(c=='1') s3.pb('1');
    while(s3.size()>1 and s3.back()=='0') s3.pop_back();
    reverse(all(s3));
    return s3;
}
string bruteForce(string s1,string s2)
{
    if(s1=="0" || s2=="0") return "0";
    string s3;
    string t1,t2;
    rep(i,s2.size())
    {
        char c=s2[s2.size()-1-i];
        if(c=='1')
        {
            t1=s1;
            rep(j,i) t1.pb('0');
            t2=addstrings(t2,t1);
        }
    }
    s3=t2;
    reverse(all(s3));
    while(s3.size()>1 and s3.back()=='0') s3.pop_back();
    reverse(all(s3));
    return s3;
}
string substractstrings(string s1,string s2)
{
    string ans;
	rep(i,s1.size()) ans.pb('0');
	reverse(all(s1));
	reverse(all(s2));
	while(s1.size()<s2.size()) s1.pb('0');
	while(s2.size()<s1.size()) s2.pb('0');
	rep(i,s1.size())
	{
		if(s1[i]<s2[i])
        {
			s1[i]+=2;
			s1[i+1]-=1;
		}
		ans[i]=(s1[i]-'0')-(s2[i]-'0')+'0';
	}
    while(ans.size()>1 and ans.back()=='0') ans.pop_back();
	reverse(all(ans));
	return ans;
}
string karatsuba(string s1,string s2)
{
    reverse(all(s1));
    reverse(all(s2));
    while(s1.size()>s2.size()) s2.pb('0');
    while(s2.size()>s1.size()) s1.pb('0');
    reverse(all(s1));
    reverse(all(s2));
    if(s1.size()==0) return "0";
    if(s1.size()==1) return bruteForce(s1,s2);
    ll n1=s1.size()/2;
    ll n2=s1.size()-n1;
    string z1=s1.substr(0,n1);
    string z2=s1.substr(n1,n2);
    string y1=s2.substr(0,n1);
    string y2=s2.substr(n1,n2);
    string f1=karatsuba(z1,y1);
    string f2=karatsuba(z2,y2);
    string f3=karatsuba(addstrings(z1,z2),addstrings(y1,y2));
    string mid=addstrings(f1,f2);
    string fmid=substractstrings(f3,mid);
    string x1=f1,x2=fmid;
    rep(i,2*n2) x1.pb('0');
    rep(i,n2) x2.pb('0');
    return addstrings(addstrings(x1,f2),x2);
}
int main()
{
    ll t;
    cin>>t;
    rep(i,t)
    {
        ll type;
        cout<<"1. Brute Force\n2. Karatsuba\n";
        cin>>type;
        if(type==1)
        {
            string s1,s2;
            cin>>s1>>s2;
            string s3=bruteForce(s1,s2);
            cout<<s3<<endl;
        }
        else if(type==2)
        {
            string s1,s2;
            cin>>s1>>s2;
            string s3=karatsuba(s1,s2);
            cout<<s3<<endl;
        }
    }
    return 0;
}
