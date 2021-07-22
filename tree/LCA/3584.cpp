#include <bits/stdc++.h>
using namespace std;


typedef pair<int,int> P;

int parent[10001][14];
int depth[10001];
vector<int> child[10001];

void dfs(int curr,int d){
	depth[curr] = d;
	for(auto a: child[curr]){
		dfs(a,d+1);
	}
}

int main(){
	
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	int T; cin>>T;
	while(T--){
		
		memset(parent,-1,sizeof(parent));
		memset(depth,-1,sizeof(depth));
		
		
		int root;
		int N; cin>>N;
		for(int i = 0,a,b; i<N-1;i++){
			cin>>a>>b;
			parent[b][0] = a;
			child[a].push_back(b);
		}
		for(int i = 1; i<=N;i++){
			if(parent[i][0] ==-1)
				root = i;
		}
		
		dfs(root,0);
		
		for(int i = 0; i<13; i++){
			for(int j = 1; j<=N; j++){
				if(parent[j][i] != -1)
					parent[j][i+1] = parent[parent[j][i]][i];
			}
		}
		
		int u,v; cin>>u>>v;
		
		if(depth[u] < depth[v]) swap(u,v);
		int diff = depth[u] - depth[v];
		
		for(int i = 0; diff;i++){
			if(diff%2) u = parent[u][i];
			diff/=2;
		}
		
		if(u!=v){
			for(int i = 13; i>=0;i-- ){
				if(parent[u][i] != -1 && parent[u][i] != parent[v][i]){
					u = parent[u][i];
					v = parent[v][i];
				}
			}
			
			u = parent[u][0];
		}
		cout<<u<<'\n';
		for(int i = 1; i<=N;i++){
		    child[i].clear();
		}
	}
	
	
	return 0;
}