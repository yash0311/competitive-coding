#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define pb push_back
string s;
ll dp[1000003];

ll satisfy(ll i){
	if(s[i]==s[i-1] && s[i-1]==s[i-2]) return 0;
	else return 1;
}

ll repeat(ll i,ll flag){
	
	if(i<2) return 0;
	if(flag && !satisfy(i)) return 0;
	if(dp[i]!=-1) return dp[i];
	if(satisfy(i)){
		dp[i]= repeat(i-3,1) + 1;
	}
	else dp[i]=0;
	repeat(i-1,0);
	return dp[i];
}


int main()
{	
	FIO;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	T(){
		
		cin>>s;
		for(ll i=0;i<s.size();i++) dp[i]=-1;
		if(s.size()<3){
			cout<<s.size()<<endl;
			continue;
		}
		repeat(s.size()-1,0);
		ll ans=0;
		//for(ll i=0;i<s.size();i++) cout<<dp[i]<<" ";
		for(ll i=0;i<s.size();i++) ans=max(ans,dp[i]);
		cout<<s.size()-3*ans<<endl;
	}
	return 0;
}


