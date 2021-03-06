#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define T() int t; cin>>t; while(t--)                      
#define pb push_back

ll n,m,k,count1;
const ll MAX=1e3+3;
ll matrix[MAX][MAX];
ll visited[MAX][MAX];
ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};


ll validate(ll row,ll col){
 	if (row>=0 && row<n && col>=0 && col<m) return 1;
 	else return 0;
}

void bfs(ll row,ll col,ll val){

	//cout<<row<<" "<<col<<endl;
	visited[row][col]=1;
	queue<pair<ll,ll> > q;
	q.push({row,col});
	count1++;
	while(!q.empty()){
		pair<ll ,ll> p=q.front();
		q.pop();
		ll x=p.first;
		ll y=p.second;

		for(ll i=0;i<4;i++){
			if(validate(x+dx[i],y+dy[i]) && !visited[x+dx[i]][y+dy[i]] && matrix[x+dx[i]][y+dy[i]]>=val){
				visited[x+dx[i]][y+dy[i]]=1;
				q.push({x+dx[i],y+dy[i]});
				count1++;
			}
		}
	}
}

void bfs2(ll row,ll col,ll val,ll limit){
	
	visited[row][col]=1;
	//completed[row][col]=1;
	queue<pair<ll,ll> > q;
	q.push({row,col});
	count1++;
	if(count1==limit) return ;
	//cout<<limit<<endl;
	while(!q.empty()){
		pair<ll ,ll> p=q.front();
		q.pop();
		ll x=p.first;
		ll y=p.second;

		for(ll i=0;i<4;i++){
			if(validate(x+dx[i],y+dy[i]) && !visited[x+dx[i]][y+dy[i]] && matrix[x+dx[i]][y+dy[i]]>=val){
				matrix[x+dx[i]][y+dy[i]]=val;
				visited[x+dx[i]][y+dy[i]]=1;
				//cout<<x+dx[i]<<" "<<y+dy[i]<<endl;
				//completed[x+dx[i]][y+dy[i]]=1;
				q.push({x+dx[i],y+dy[i]});
				count1++;
				if(count1==limit) return ;
			}
		}
	}
}

int main()
{	
	FIO;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin>>n>>m>>k;
	set<ll> st;
	map<ll,vector<pair<ll,ll> > > mp;
	for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++){
			cin>>matrix[i][j];
			st.insert(matrix[i][j]);
			mp[matrix[i][j]].pb({i,j});
		}
	}
	//cout<<"yes"<<endl;

	auto it=st.begin();
	ll ans=0,final_row,final_col;
	for(it=st.begin();it!=st.end();it++){
		count1=0;
		ll x=(*it);
		if(k%x!=0) continue;
		if(k/x > n*m) continue;

		//cout<<x<<endl;
		vector<pair<ll,ll> > var;
		var=mp[x];
		
		//p= mp[x];
		for(auto i:var){
			//pair<ll,ll> p;
			count1=0;
			ll row=i.first;
			ll col=i.second;
			if(!visited[row][col]) {
				memset(visited,0,sizeof(visited));
				bfs(row,col,x);
			}
			if(count1>= k/x) {
			ans=x;
			//cout<<ans<<endl;
			final_row=row;
			final_col=col;
			break;
		}
		}	

		
		//cout<<row<<" "<<col<<endl;
		
		//memset(visited,0,sizeof(visited));
		

	}
	memset(visited,0,sizeof(visited));
	if(!ans) cout<<"NO"<<endl,exit(0);
	count1=0;
	//cout<<final_row<<" "<<final_col<<endl;

	bfs2(final_row,final_col,ans,k/ans);
	cout<<"YES"<<endl;

	for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++){
			if(!visited[i][j]) matrix[i][j]=0;
		}
	}

	for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++){
			if(matrix[i][j]!=ans) cout<<0<<" ";
			else
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
	
}