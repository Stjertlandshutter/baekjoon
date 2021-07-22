#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
const long long INF = 1e18; 

vector<P> adj[500];
long long dist[500];
bool negcycle = false;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	int N,M; cin>>N>>M;
	fill(dist,dist+N,INF);
	dist[0] = 0;
	for(int A,B,C,i = 0; i<M;i++){
		cin>>A>>B>>C;
		adj[A-1].push_back(P(B-1,C));
	}
	
	for(int i = 0; i<N;i++){
		for(int j = 0; j<N;j++){
			for(auto &E: adj[j]){
				if( dist[j] != INF && dist[E.first] > dist[j]+E.second){
					dist[E.first] = dist[j]+E.second;
					if(i == N-1){
						negcycle = true;
					}
				}
			}
		}
	}
	
	if(negcycle) puts("-1");
	else{
		for(int i = 1; i<N;i++){
			long long result =dist[i] == INF ? -1 : dist[i] ;
			cout<< result<<'\n'
		}
	}
	
	return 0;
}