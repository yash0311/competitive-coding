#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define pb push_back
ll mod=1e9+7;

void multiply(ll F[2][2], ll M[2][2]); 
  
void power(ll F[2][2], ll n); 
  
/* function that returns nth Fibonacci number */
ll fib(ll n) 
{ 
  ll F[2][2] = {{1,1},{1,0}}; 
  if (n == 0) 
    return 0; 
  power(F, n-1); 
  return F[0][0]; 
} 
  
/* Optimized version of power() in method 4 */
void power(ll F[2][2], ll n) 
{ 
  if( n == 0 || n == 1) 
      return; 
  ll M[2][2] = {{1,1},{1,0}}; 
  
  power(F, n/2); 
  multiply(F, F); 
  
  if (n%2 != 0) 
     multiply(F, M); 
} 
  
void multiply(ll F[2][2], ll M[2][2]) 
{ 
  	ll x =  (((F[0][0]%mod)*(M[0][0]%mod))%mod + ((F[0][1]%mod)*(M[1][0]%mod))%mod)%mod;
	ll y =  (((F[0][0]%mod)*(M[0][1]%mod))%mod + ((F[0][1]%mod)*(M[1][1]%mod))%mod)%mod;
	ll z =  (((F[1][0]%mod)*(M[0][0]%mod))%mod + ((F[1][1]%mod)*(M[1][0]%mod))%mod)%mod;
	ll w =  (((F[1][0]%mod)*(M[0][1]%mod))%mod + ((F[1][1]%mod)*(M[1][1]%mod))%mod)%mod;
  
  F[0][0] = x; 
  F[0][1] = y; 
  F[1][0] = z; 
  F[1][1] = w; 
} 



int main(int argc, char const *argv[])
{
	T(){
		ll n;
		cin>>n;
		cout<<fib(n+2)<<"\n";
	}
	return 0;
}