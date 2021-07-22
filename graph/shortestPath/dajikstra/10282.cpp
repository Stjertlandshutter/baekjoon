#include <bits/stdc++.h>
using namespace std;


typedef pair<int,int> P;




int main(){
	
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	int T; cin>>T;
	while(T--){
		vector<P> child[10001]; 
		bool visited[10001];
		int number = 0,answer = -1;
		int dist[10001];
		priority_queue<P, vector<P>, greater<P>> PQ;
		int n, d, c; 
		
		cin>>n>>d>>c;
		fill(dist,dist+10001,2e9);
		dist[c-1] = 0;
		
		for(int a, b, s, i = 0; i < d; i++){
			cin>>a>>b>>s;
			child[b-1].push_back(P(s,a-1));
		}
		
		PQ.push(P(0,K));
		while(!PQ.empty()){
			int curr;
			do{
				curr = PQ.top().second;
				PQ.pop();
			}while(!PQ.empty() && visited[curr]);
			
			
			if(visited[curr]) break;
			
			visited[curr] = true;
			for(auto &p: child[curr]){
				int next = p.first, d = p.second;
				
				if(dist[next]>dist[curr]+d){
					dist[next] = dist[curr]+d;
					PQ.push(P(dist[next],next));
				}
			}
		}
		
		for(int i = 0; i < 10001 ;i++){
			if(dist[i] != 2e9){
				number ++;
				answer = max(answer,dist[i])
			}
		}
		
		cout<<number<<' '<<answer<<'\n'
		
	}
	
	
	return 0;
}