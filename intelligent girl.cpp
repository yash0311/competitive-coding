#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define pb push_back



int main()
{	
	FIO;
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	string s;
	cin>>s;
	ll suffix[s.size()]={0};
	if((ll)(s[s.size()-1]-'0') % 2 == 0) suffix[s.size()-1]=1;
	//cout<<suffix[s.size()-1]<<endl;
	for(ll i=s.size()-2;i>=0;i--){
		((ll)(s[i]-'0') %  2 == 0) ? suffix[i] = suffix[i+1] + 1 : suffix[i] = suffix[i+1];
	}

	for(ll i=0;i<s.size();i++) cout<<suffix[i]<<" "; 
	return 0;
}