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

	ll n,q;
	cin>>n>>q;

	ll a[n],b[n],pref_a[n]={0},pref_b[n]={0};

	
	for(ll i=0;i<n;i++) cin>>a[i];
	for(ll i=0;i<n;i++) cin>>b[i];
	
	pref_a[0]=a[0];pref_b[0]=b[0];
	for(ll i=1;i<n;i++) {
		(i%2==1) ? pref_a[i]=pref_a[i-1]+b[i] : pref_a[i]=pref_a[i-1]+a[i];
		(i%2==1) ? pref_b[i]=pref_b[i-1]+a[i] : pref_b[i]=pref_b[i-1]+b[i];
	}

	
	
	// for(ll i=0;i<n;i++) cout<<pref_a[i]<<" ";
	// cout<<endl;
	// for(ll i=0;i<n;i++) cout<<pref_b[i]<<" ";
	// cout<<endl;

	while(q--){
		ll t,l,r;
		cin>>t>>l>>r;
		l--;r--;
		if(t==1){
			if(l%2==0)
			(l!=0) ? cout<<pref_a[r]-pref_a[l-1]<<"\n" : cout<<pref_a[r]<<"\n";
			else
			(l!=0) ? cout<<pref_b[r]-pref_b[l-1]<<"\n" : cout<<pref_b[r]<<"\n";
		}
		else{
			if(l%2==0)
			(l!=0) ? cout<<pref_b[r]-pref_b[l-1]<<"\n" : cout<<pref_b[r]<<"\n";	
			else
			(l!=0) ? cout<<pref_a[r]-pref_a[l-1]<<"\n" : cout<<pref_a[r]<<"\n";
		}
	}
	return 0;
	
}