#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define pb push_back

int main()
{	
	FIO;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	ll n;
	cin>>n;

	ll arr[n];
	for(ll i=0;i<n;i++) cin>>arr[i];

	std::map<ll, ll> mp;
	
	mp[0]=1;
	ll o_cnt=0,e_cnt=0;
	//cout<<"yes\n";
	for(ll i=0;i<n;i++){
		if(arr[i] & 1) o_cnt++;
		else e_cnt++;
		mp[e_cnt - o_cnt]++;
	}
	ll ans=0;
	auto it=mp.begin();

	for(it=mp.begin();it!=mp.end();it++){
		pair<ll,ll> p = (*it);
		ll x=p.second;
		ans+= (x*(x-1))/2;
	}
	cout<<ans<<endl;

	return 0;
	
}