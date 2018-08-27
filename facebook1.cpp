#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define fr(n) for(int i=0;i<n;i++)
#define fr1(n) for(int i=1;i<=n;i++)
#define pb push_back

bool sortby2(const pair<string,ll> &a, const pair<string,ll> &b){
	return ( a.second < b.second );
}

int main()
{
	 freopen("tourist.txt", "r", stdin);
	 freopen("output.txt", "w", stdout);
	FIO;

	ll check=1;
	T(){
		ll n,k,v;
		string inp;
		cin>>n>>k>>v;
		std::vector< pair<string,ll> > vt;
		std::map<string, ll> mp;
		fr(n)  cin>>inp, vt.pb({inp,0}),mp[inp]=i;

		ll loop= v%n;

		// auto it=mp.begin();
		// for(it=mp.begin();it!=mp.end();it++) cout<<it->first<<" "<<it->second<<endl;


		//cout<<"loop= "<<loop<<endl;
		std::vector< pair<ll,string> > ans[n];
		for(ll i=1;i<n;i++){
			string c="";
			for(ll j=0;j<k;j++) ans[i].pb({mp[vt[j].first],vt[j].first}),vt[j].second+=1;
			sort(ans[i].begin(),ans[i].end());
			sort(vt.begin(),vt.end(),sortby2);
		}

		//cout<<"xxx"<<endl;

		string c="";

		

		fr(k) ans[0].pb({mp[vt[i].first],vt[i].first});
		sort(ans[0].begin(),ans[0].end());

		cout<<"Case #"<<check<<": ";

		fr(ans[loop].size()) cout<<ans[loop][i].second<<" ";

		cout<<"\n";
		check++;
	}	
	return 0;
	
}