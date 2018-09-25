#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define pb push_back

std::map<ll, ll> mp;

ll cal(ll n){
	if(n==0) return 0;
	auto iter = mp.find(n);
	
	if(iter!=mp.end())  return mp[n];

	mp[n]=max(n,cal(n/2)+cal(n/3)+cal(n/4));
	return mp[n];
}

int main()
{	
	FIO;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll n;

	while(scanf("%lld",&n)==1){
		//cout<<n<<endl;
		cout<<cal(n)<<endl;
	}


	return 0;
	
}

