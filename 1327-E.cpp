//SOLUTION to https://codeforces.com/contest/1327/problem/E

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
 
#define rep(i,n)    for(int i=0;i<n;i++)
#define repu(i,k,n) for(int i=k;i<=n;i++)
#define repd(i,k,n) for(int i=k;i>=n;i--)
#define se second
#define fi first
#define pb push_back
#define mp make_pair
#define endl "\n"
#define INF (int)INT_MAX
 
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;
typedef std::vector<int> vi;
typedef std::vector< pii > vii;
typedef std::vector< ll > vll;
typedef std::vector< std::pair < pii, int > > vpp;
 
const int N = 3*1e5 +5 ;
const long long MOD = 1000000007;
const long long inf = 1e18;
 
using namespace std;




void solve()
{
	ll n;
	cin>>n;
 
   	long long ans[n+5]={0};

   	long long pow9 = 90;

   	if(n==1){
   		cout<<"10";
   		return;
   	}
   	if(n==2){
   		cout<<"180 10";
   		return;
   	}

   	ans[n]=10;
   	ans[n-1] = 180;

   	for(int i=n-2;i>=1;i--){
   		ans[i] = 10 * (2) * pow9;
   		ans[i] = ans[i] % 998244353;

   		ans[i]+= 9 * (n - 1 - i) * pow9;
   		ans[i] = ans[i] % 998244353;


   		
   		pow9 *=10;
   		pow9 = pow9 % 998244353; 

   	}

   	for(int i=1;i<=n;i++){
   		cout<<ans[i]<<" ";
   	} 

}
     
int main() {
    #ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif
    
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t = 1;
//    cin>>t;
    
    while(t--)
    {
        solve();    
    } 
}
