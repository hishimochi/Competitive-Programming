//デバッグ
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif

#include<bits/stdc++.h>
using namespace std;

//atcoder
/*
#include<atcoder/all>
*/

//boost
/*
#include<boost/multiprecision/cpp_int.hpp>
using lint=boost::multiprecision::cpp_int;
using int128=boost::multiprecision::int128_t;
using int256=boost::multiprecision::int256_t;
using int512=boost::multiprecision::int512_t;
using int1024=boost::multiprecision::int1024_t;
*/

//入出力
template<class T>istream& operator>>(istream& s,vector<T>& a){
    for(size_t i=0;i<a.size();i++)s>>a[i];
    return s;
}
template<class T,class U>istream& operator>>(istream& s,pair<T,U>& p){
    s>>p.first>>p.second;
    return s;
}
template<class T,class U,class V>istream& operator>>(istream& s,tuple<T,U,V>& t){
    s>>get<0>(t)>>get<1>(t)>>get<2>(t);
    return s;
}

template<class T>ostream& operator<<(ostream& o,const vector<T>& a){
    for(size_t i=0;i<a.size();i++)o<<a[i]<<((i+1!=a.size())?" ":"");
    return o;
}
template<class T,class U>ostream& operator<<(ostream& o,const pair<T,U>& p){
    o<<p.first<<" "<<p.second;
    return o;
}
template<class T,class U,class V>ostream& operator<<(ostream& o,const tuple<T,U,V>& t){
    o<<get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t);
    return o;
}

void cintogetline(){cin.ignore();}
void linescan(string& a){getline(cin,a);}

void setfloat(int x){cout<<fixed<<setprecision(x);}

#define INT(...) int __VA_ARGS__;IN(__VA_ARGS__)
#define LL(...) long long __VA_ARGS__;IN(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;IN(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;IN(__VA_ARGS__)
#define LD(...) long double __VA_ARGS__;IN(__VA_ARGS__)
#define VEC(T,name,size) vector<T>name(size);IN(name)
#define VVEC(T,name,h,w) vector<vector<T>>name(h,vector<T>(w));IN(name)

void scan(int& a){cin>>a;}
void scan(long long& a){cin>>a;}
void scan(string& a){cin>>a;}
void scan(char& a){cin>>a;}
void scan(long double& a){cin>>a;}
template<class T,class L>void scan(pair<T,L>& a){cin>>a.first>>a.second;}
template<class T,class U,class V>void scan(tuple<T,U,V>& t){cin>>get<0>(t)>>get<1>(t)>>get<2>(t);}
template<class T>void scan(vector<T>& a){for(size_t i=0;i<a.size();i++)cin>>a[i];}
void IN(){}
template<class H,class... T>void IN(H& h,T&... t){scan(h);IN(t...);}

template<class T>void out(T x){cout<<x<<'\n';}
template<class T>void vout(vector<T> x){for(size_t i=0;i<x.size();i++)cout<<x[i]<<'\n';}
void Yes(bool a){cout<<(a?"Yes\n":"No\n");}
void YES(bool a){cout<<(a?"YES\n":"NO\n");}
void possible(bool a){cout<<(a?"possible\n":"impossible\n");}
void Possible(bool a){cout<<(a?"Possible\n":"Impossible\n");}
void First(bool a){cout<<(a?"First\n":"Second\n");}
void first(bool a){cout<<(a?"first\n":"second\n");}

//型の省略
using ll=long long;
using ld=long double;
using pll=pair<ll,ll>;
using tll=tuple<ll,ll,ll>;
using vl=vector<ll>;
using vvl=vector<vl>;
using vvvl=vector<vvl>;
using vc=vector<char>;
using vvc=vector<vc>;
using vs=vector<string>;
using vb=vector<bool>;
using vvb=vector<vb>;
template<class T>using vt=vector<T>;
template<class T>using vvt=vector<vt<T>>;
template<class T>using vvvt=vector<vvt<T>>;
template<class T>using SQ=priority_queue<T,vector<T>,greater<T>>;
template<class T>using LQ=priority_queue<T>;

//定数
const int MOD1=1000000007;
const int MOD2=998244353;
const long double PI=3.1415926535897932;
const long long MAXLL=9223372036854775807;
const int MAXI=2147483647;
const long long INF=2305843009213693951;
const int inf=1073741789;
const long double EPS=0.000000001;
const int DX[]={0,1,0,-1,1,-1,1,-1};
const int DY[]={1,0,-1,0,1,1,-1,-1};

//マクロ
#define overload3(_1,_2,_3,name,...) name
#define overload4(_1,_2,_3,_4,name,...) name
#define rep1(n) for(ll i=0;i<(n);i++)
#define rep2(i,n) for(ll i=0;i<(n);i++)
#define rep3(i,s,n) for(ll i=(s);i<(n);i++)
#define rep(...) overload3(__VA_ARGS__,rep3,rep2,rep1)(__VA_ARGS__)
#define bitrep1(n) for(ll i=0;i<(1LL<<(n));i++)
#define bitrep2(i,n) for(ll i=0;i<(1LL<<(n));i++)
#define bitrep3(i,s,n) for(ll i=(s);i<(1LL<<(n));i++)
#define bitrep(...) overload3(__VA_ARGS__,bitrep3,bitrep2,bitrep1)(__VA_ARGS__)
#define rrep1(n) for(ll i=(n)-1;i>=0;i--)
#define rrep2(i,n) for(ll i=(n)-1;i>=0;i--)
#define rrep3(i,s,n) for(ll i=(n)-1;i>=(s);i--)
#define rrep(...) overload3(__VA_ARGS__,rrep3,rrep2,rrep1)(__VA_ARGS__)
#define rbf1(a,x) for(auto&&a:(x))
#define rbf2(a,b,x) for(auto&&[a,b]:(x))
#define rbf3(a,b,c,x) for(auto&&[a,b,c]:(x))
#define rbf(...) overload4(__VA_ARGS__,rbf3,rbf2,rbf1)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define Maxe(x) *max_element(all(x))
#define Mine(x) *min_element(all(x))
#define Sume(x) accumulate(all(x),0LL)
#define Size(x) (ll)((x).size())
#define Sort(x) sort(all(x))
#define rSort(x) sort(rall(x))
#define Rev(x) reverse(all(x))

//省略
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define eb emplace_back

//数学
long long cutup(ll a,ll b){return (a+b-1)/b;}
template<class T,class U>auto max(T a,U b){return (a>b)?a:b;}
template<class T,class U>auto min(T a,U b){return (a>b)?b:a;}
template<class T,class U>bool chmin(T& a,U b){if(a>b){a=b;return true;}return false;}
template<class T,class U>bool chmax(T& a,U b){if(a<b){a=b;return true;}return false;}
template<class T>T pow_(T x,ll n){T res=1;while(n>0){if(n&1){res=res*x;}x=x*x;n>>=1;}return res;}
ll modpow(ll x,ll n,ll m){ll res=1;x=(x%m+m)%m;while(n>0){if(n&1){res=res*x;res=res%m;}x=x*x;x=x%m;n>>=1;}return res;}
ll modinv(ll a,ll m){ll b=m,u=1,v=0;while(b){ll t=a/b;a-=t*b;swap(a,b);u-=t*v;swap(u,v);}u%=m;if(u<0)u+=m;return u;}
ll digitsum(string s){ll res=0;for(size_t i=0;i<s.size();i++){res+=s[i]-'0';}return res;}
ll digitsum(ll x){if(x<10)return x;return x%10+digitsum(x/10);}
ll getDigitSize(ll x){if(x<0)x*=-1;if(x<10)return 1;return getDigitSize(x/10)+1;}

//配列
template<class T>void makeunique(vector<T>& v){sort(all(v));v.erase(unique(all(v)),v.end());}
template<class T>void makeabs(vector<T>& v){for(size_t i=0;i<v.size();i++)v[i]=abs(v[i]);}
template<class T>void vdelete(vector<T> &v,ll pos){swap(v[pos],v[v.size()-1]);v.pop_back();}

//bit
inline int popcnt(int x){return __builtin_popcount(x);}
inline int popcntll(long long x){return __builtin_popcountll(x);}
inline bool bitcheck(long long bit,int i){return bit&(1LL<<i);}
void biton(long long& bit,int i){bit|=(1LL<<i);}
void bitoff(long long& bit,int i){bit&=~(1LL<<i);}

/*---------------------------------------------------------------------------------------------------------------------*/

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
}