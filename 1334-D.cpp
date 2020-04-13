//  SOLUTION to https://codeforces.com/contest/1334/problem/D

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

ll power(ll x,  ll y, ll p)  
{  
    ll res = 1;     // Initialize result  
  
    x = x % p; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) % p;  
  
        // y must be even now  
        y = y>>1; // y = y/2  
        x = (x*x) % p;  
    }  
    return res;  
}  


void solve()
{
	ll n,l,r;
	cin>>n>>l>>r;

	ll ctr=0;

	ll lt=l;

	if(l==n*(n-1)+1){
		cout<<1<<endl;
		return;
	}

	while(lt>0){
		ctr++;
		lt-= 2*(n-ctr);
	}

	lt+=2*(n-ctr);
	ll val = (r-l+1);

//	cout<<ctr<<" "<<lt<<" "<<val<<endl;

	while(val){
		val--;
		if(ctr==n){
			cout<<"1"<<" "<<endl;
			return;
		}

		if(lt%2==1)cout<<ctr;
		else cout<<ctr+lt/2;

		cout<<" ";
		if(lt<2*(n-ctr))lt++;
		else {
			ctr++;
			lt=1;
		}
	}
	cout<<endl;

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
    cin>>t;
    
    while(t--)
    {
        solve();    
    } 
}
