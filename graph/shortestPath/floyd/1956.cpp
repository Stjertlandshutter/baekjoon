#include <bits/stdc++.h>
using namespace std;

int main(){
	
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	const int INF =1e9;
	int answer = INF;
	int dist[400][400];
	
	int V ,E; cin>>V>>E;
	
	for(int i = 0; i<V;i++){
		for(int j = 0; j<V;j++){
			dist[i][j] = INF;
		}
	}
	
	for(int a,b,c,i = 0; i<E;i++){
		cin>>a>>b>>c;
		if(dist[a-1][b-1] != 0)
		    dist[a-1][b-1] = min(dist[a-1][b-1],c);
		else
		    dist[a-1][b-1] = c;
		    
	}
	
	for(int i = 0; i<V;i++)
		for(int j = 0; j<V;j++)
			for(int k = 0; k<V;k++)
				dist[i][j] = min(dist[i][j],dist[i][k]+ dist[k][j]);
	
	for(int i = 0; i<V;i++){
		answer = min(answer, dist[i][i]);
	}
	
	if(answer == INF) cout<<-1;
	else cout<<answer;
	
	return 0;
}
