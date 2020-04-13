
// SOLUTION: to https://codeforces.com/contest/1339/problem/D

#include <bits/stdc++.h>
#include <map>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <string.h>
 
#define rep(i,n)    for(ll i=0;i<n;i++)
#define repu(i,k,n) for(ll i=k;i<=n;i++)
#define repd(i,k,n) for(ll i=k;i>=n;i--)
#define se second
#define fi first
#define pb push_back
#define mp make_pair
#define endl "\n"
#define INF (ll)ll_MAX
 
typedef long long ll;
typedef long double ld;
typedef std::pair<ll, ll> pii;
typedef std::vector<ll> vi;
typedef std::vector< pii > vii;
typedef std::vector< ll > vll;
typedef std::vector< std::pair < pii, ll > > vpp;
 
const ll N = 3*1e5 +5 ;
const long long MOD = 1000000007;
const long long MOD2 = 998244353;
const long long inf = 1e18;
 
using namespace std;
 
 
 
 
void multiply(ll a[3][3], ll b[3][3]) 
{ 
    // Creating an auxiliary matrix to store elements  
    // of the multiplication matrix 
    ll mul[3][3]; 
    for (ll i = 0; i < 3; i++) 
    { 
        for (ll j = 0; j < 3; j++) 
        { 
            mul[i][j] = 0; 
            for (ll k = 0; k < 3; k++) 
                mul[i][j] += a[i][k]*b[k][j]; 
        } 
    } 
  
    // storing the multiplication result in a[][] 
    for (ll i=0; i<3; i++) 
        for (ll j=0; j<3; j++) 
            a[i][j] = mul[i][j];  // Updating our matrix 
} 
  
// Function to compute F raise to power n-2. 
ll power(ll F[3][3], ll n) 
{ 
    ll M[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}}; 
  
    // Multiply it with initial values i.e with 
    // F(0) = 0, F(1) = 1, F(2) = 1 
    if (n==1) 
        return F[0][0] + F[0][1]; 
  
    power(F, n/2); 
  
    multiply(F, F); 
  
    if (n%2 != 0) 
        multiply(F, M); 
  
    // Multiply it with initial values i.e with 
    // F(0) = 0, F(1) = 1, F(2) = 1 
    return F[0][0] + F[0][1] ; 
} 
  
// Return n'th term of a series defined using below 
// recurrence relation. 
// f(n) is defined as 
//    f(n) = f(n-1) + f(n-2) + f(n-3), n>=3 
// Base Cases : 
//    f(0) = 0, f(1) = 1, f(2) = 1 
ll findNthTerm(ll n) 
{ 
  
    ll F[3][3] = {{1,1,0}, {1,0,0}, {0,1,0}} ; 
  
    //Base cases 
    if(n==0) 
        return 0; 
    if(n==1 || n==2) 
        return 1; 
  
    return power(F, n-2); 
} 
 
 
ll ans;
ll fl1,fl2;
ll flag;
ll color[100005];
vector <ll> v[100005];
 
void dfs1(ll u, ll depth){
    if(color[u]==1) return;
    color[u]=1;
    if(v[u].size()==1){
        if(depth%2==0){
            fl2=1;
 //           cout<<u<<"yo";
        }
        else{
            fl1=1;
 //           cout<<u<<"yuoo";
 
        }
    }
    if(fl1==1 && fl2==1) {
   //     cout<<"back";
        return;
    }
 
    for(int k=0;k<v[u].size();k++){
        dfs1(v[u][k],depth+1);
    }
 
}
 
ll dfs2(ll u){
    if(color[u]==1) return 0;
    color[u]=1;
    
    ll tempans=0;
    ll leaf=0,nleaf=0;
 
    for(int k=0;k<v[u].size();k++){
        if(color[v[u][k]]==1) continue;
        tempans+=dfs2(v[u][k]);
        if(v[v[u][k]].size()==1) leaf++;
        else nleaf++;
    }
    tempans+=nleaf;
    if(leaf>=1) tempans++;
  //  cout<<tempans<<" ";
 
    return tempans;
 
}
 
 
 
void solve()
{	
    ll n;
    cin>>n;
 //   cout<<n;
    
    
 
    for(int i=0;i<n-1;i++){
        ll t1,t2;
        cin>>t1>>t2;
        t1--;
        t2--;
        v[t1].pb(t2);
        v[t2].pb(t1);
    }
    flag=1;
    ans=0;
    fl1=0;
    fl2=0;
    for(int i=0;i<n;i++){
        color[i]=0;
    }
 
 
    dfs1(0,0);
 
    if(fl1==1 && fl2==1){
        cout<<"3 ";
    }
    else{
        cout<<"1 ";
    }
 
    ll utemp=0;
 
    for(int i=0;i<n;i++){
        if(v[i].size()>1){
            utemp=i;
            break;
        }
    }
    for(int i=0;i<n;i++){
        color[i]=0;
    }
 
    cout<<dfs2(utemp);
 
 
}
     
int main() {
    #ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif
    //cout<<"helo";
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ll t = 1;
  //  cin>>t;
    
    while(t--)
    {
        solve();    
    } 
}
