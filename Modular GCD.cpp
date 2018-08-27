#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define pb push_back

ll fast_mul(ll a,ll b,ll m){
	ll res=0;
	while(b>0){
		if(b%2==1) res= (res%m+a%m)%m;

		b= b>>1;
		a= (a%m+a%m)%m;
	}
	return res;
}


ll mod_exp(ll a,ll n,ll m){
	ll res=1;
	//if(m==0) return 0;
	while(n>0){
		if(n%2==1) res=fast_mul(res,a,m);// res=(res*a)%m

		n= n>>1;
		a=fast_mul(a,a,m); // a=(a*a)%m
	}

	return res;
}


int main()
{	
	FIO;
	T(){
		ll a,b,n,x,y;
		cin>>a>>b>>n;
		if(a==b) {
			 x=mod_exp(a,n,1000000007);
			 y=mod_exp(b,n,1000000007);	
		}
		else{
			 x=mod_exp(a,n,abs(a-b));
			 y=mod_exp(b,n,abs(a-b));	
		}
		

		cout<<(__gcd((x+y),abs(a-b)))%1000000007<<endl;
	}
	return 0;
	
}


// 3
// 25769803776