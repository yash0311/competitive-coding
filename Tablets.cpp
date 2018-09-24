#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define pb push_back


int main()
{	
	FIO;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	ll n;
	cin>>n;
	ll arr[n],dp[n],ans=0;
	for(ll i=0;i<n;i++) cin>>arr[i],dp[i]=1;
	
	
	for(ll i=1;i<n;i++) if(arr[i]>arr[i-1]) dp[i]=dp[i-1]+1;
	for(ll i=n-2;i>=0;i--) if(arr[i]>arr[i+1] && dp[i]<=dp[i+1]) dp[i]=dp[i+1]+1;
	for(auto i:dp) ans+=i;	

	cout<<ans<<endl;
	return 0;
	
}


