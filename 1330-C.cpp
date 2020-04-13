//SOLUTION to https://codeforces.com/contest/1330/problem/C

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
	int n,m;
	cin>>n>>m;

	int l[m];
	for(int i=0;i<m;i++) {
		cin>>l[i];
		if(l[i]+i>n){
			cout<<"-1\n";
			return;
		}
	}
	//cout<<l[0]<<endl;
	//	sort(l,l+m);

	long long summ=0;
	for(int i=0;i<m;i++) summ+=l[i];

	if(summ<n){
		cout<<"-1";
		return;
	}

	ll diff=summ-n;
	int last=1;

	int prin[m]={0};

	for(int i=0;i<m;i++){
		prin[i]=last;
	//	cout<<last<<" ";
		if(diff==0){
		//	cout<<last<<" ";

			last+=l[i];
			continue;
		}
		if(diff<l[i]){
			last+=l[i]-diff;
			diff=0;
			continue;
		}
		if(diff>=l[i]){
			last+=1;
			diff-=l[i]-1;
			continue;
		}

	}

	int fl=1;

	for(int i=0;i<m;i++){
		if(prin[i]+l[i]-1>n){
			fl=0;
			break;
		}
		if(l[i]+i>n){
			fl=0;
			break;
		}
	}

	if(prin[m-1]+l[m-1]-1 != n) fl=0;


	// if(fl==0){
	// 	cout<<"-1";
	// 	return;
	// }

	for(int i=0;i<m;i++){
		cout<<prin[i]<<" ";
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
