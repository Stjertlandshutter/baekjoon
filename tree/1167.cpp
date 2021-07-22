// 왜 이게 되는지는 증명해야함


#include <bits/stdc++.h>
using namespace std;

typedef pair<int,long long> P;

long long dist[100001];
bool visited[100001];
vector<P> adj[100001];


long long X, Xdist = -1;

void dfs(int curr,long long d){
	for(auto next:adj[curr]){
		if(!visited[next.first]){
			visited[next.first] = true;
			dist[next.first] = d + next.second;
			dfs(next.first, d + next.second);
			
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	int V; cin>>V;
	
	for(int i = 0; i <V ;i++){
		int a,b,c; cin>>a;
		while(1){
			cin>>b; if(b==-1) break;
			cin>>c;
			adj[a-1].push_back(P(b-1,c));
		}
	}
	visited[0] = true;
	dfs(0,0);

	for(int i = 0; i < V; i++){
		if(Xdist < dist[i]){
			Xdist = dist[i];
			X = i;
			visited[i] = false;
		}
	}
	
	cout<<X<<'\n';
	visited[X] = true;
	dfs(X,0);
	
	for(int i = 0; i < V; i++){
		if(Xdist < dist[i]){
			Xdist = dist[i];
			X = i;
		}
	}
		cout<<X<<'\n';
	cout<<Xdist;
	return 0;
}