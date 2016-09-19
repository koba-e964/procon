#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<unordered_map>
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#include<cassert>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
    os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
    template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
    template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
    template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
    const ll MOD=1e9+7;

    int n,m;
    int u[222];
    vector<int> dp[222];

    void dfs(vv<pii> &g,int v,int p){
        dp[v]={u[v]};
        dp[v].resize(m+1);
        for(pii w:g[v])
            if(w.X!=p){
                dfs(g,w.X,v);
                auto tmp=dp[v];
                rep(i,tmp.size())rep(j,dp[w.X].size()){
                    if(i+j+w.Y>m) break;
                    MX(dp[v][i+j+w.Y],dp[w.X][j]+tmp[i]);
                }
            }
    }

int main(){
    ios_base::sync_with_stdio(false);
    cout<<fixed<<setprecision(0);
    cin>>n>>m;
    m/=2;
    rep(i,n) cin>>u[i];
    vv<pii> g(n);
    rep(i,n-1){
        int x,y,z;
        cin>>x>>y>>z;
        g[x].eb(y,z);
        g[y].eb(x,z);
    }
    dfs(g,0,-1);
    //rep(i,n) cout<<dp[i];
    cout<<*max_element(all(dp[0]))<<endl;
    return 0;
}

