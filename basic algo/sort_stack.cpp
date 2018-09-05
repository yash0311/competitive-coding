#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define pb push_back

void act_sort(stack<ll> *s,ll elem){
	
	if(s->empty()) {
		//cout<<" empty= "<<elem<<endl;
		s->push(elem);
		return ;
	}
	

	ll top=s->top();
	//cout<<"top= "<< top<<" elem= "<<elem<<endl;
	if(elem>=top){
		s->push(elem);
		return ;
	}
	else{
		s->pop();
		act_sort(s,elem);
		s->push(top);
		return ;
	}
}

void srt(stack<ll> *s){
	
	if(s->empty()) return ;
	
	ll x=s->top();
	
	s->pop();
	//cout<<x<<" "<<endl;
	srt(s);
	//cout<<"after srt "<<x<<" "<<endl;
	if(s->empty()) {
		s->push(x);
		//cout<<x<<endl;
		return;
	}

	act_sort(s,x);

}

int main()
{	
	stack<ll> s;
	s.push(30);
	s.push(-5);
	s.push(18);
	s.push(14);
	s.push(-3);
	srt(&s);

	while(!s.empty()){
		ll x=s.top();
		cout<<x<<endl;
		s.pop();
	}
	return 0;
}

