#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define pb push_back


int main()
{	
	ll arr[7]={1,8,7,3,9,5,2};
	stack<ll> s;
	s.push(arr[0]);
	for(ll i=1;i<7;i++){

		if(s.empty()) {s.push(arr[i]);continue;}

		ll check= arr[i];
		//elem=s.pop();
		while( s.empty()==false && check<s.top() ){
			cout<<"pair "<<s.top()<<" "<<check<<endl;
			s.pop();
		}

		s.push(check);

	}

	while(!s.empty()) cout<<"pair "<<s.top()<<" "<<-1<<endl,s.pop();
	return 0;
	
}


// 3
// 25769803776z