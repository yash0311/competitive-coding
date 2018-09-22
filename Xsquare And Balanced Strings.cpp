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

	T(){
		string s;
		cin>>s;
		ll arr[26]={0};

		for(ll i=0;i<s.size();i++) arr[s[i]-'a']++;
		ll ans=1;
		for(auto i:arr){
			if(i & 1) ans=-1;
		}
		cout<<ans<<endl;
	}

	return 0;
	
}