// Solution to https://codeforces.com/contest/1334/problem/C

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

long long func(int k,int n){
	if(k>n) return 0;
	if(k==n) return 1;
	if(k==1) return 1;

	return (func(k-1,n-1) + func(k,n-k)) % 1000000007;

}

void solve()
{
	ll n;
	cin>>n;

	ll a[n],b[n];

	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}

	ll diff[n];

	for(int i=0;i<n;i++){
		diff[i]=a[i] - b[(i-1+n)%n];
		if(diff[i]<0) diff[i]=0;
	}

	ll minsum=0;
	ll sum=0;

	for(int i=0;i<n;i++){
		sum+=diff[i];
	}
	minsum=sum-diff[0]+a[0];

	for(int i=0;i<n;i++){
		if(minsum > sum-diff[i]+a[i]){
			minsum = sum-diff[i]+a[i];
		}
	}

	cout<<minsum<<endl;


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
