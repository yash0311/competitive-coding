#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define pb push_back
std::vector<ll> v;
ll dp[100005];

/*
ll cond(ll i,ll flag){
	if(v[i]!=flag) return 1 ;
	else return 0;
}

ll repeat(ll i, ll flag){

	if(i>=v.size()) return 0;
	//cout<<i<<endl;
	if(!cond(i,flag)) return 0;

	
	if(dp[i]!=-1) return dp[i];
	cout<<i<<endl;
	dp[i]= 1 + repeat(i+1,v[i]) ;
	
	repeat(i+1,v[i]);
	
	return dp[i];

}
*/

int main()
{	
	FIO;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	T(){
		ll n;
		cin>>n;
		for(ll i=0;i<n;i++) dp[i]=1;
		v.clear();
		for(ll i=0,x;i<n;i++) {
			cin>>x;
			
			if(x>0) v.pb(1);
			else v.pb(-1);
		}


		for(ll i=n-2;i>=0;i--){
			if(v[i]!=v[i+1]) dp[i]+= dp[i+1];
			
		}

		for(ll i=0;i<n;i++) cout<<dp[i]<<" ";
		cout<<endl;
	}
	return 0;
	
}