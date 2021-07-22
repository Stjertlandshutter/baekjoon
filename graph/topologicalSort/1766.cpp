#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	int N,M; cin>>N>>M;
	vector<int> adj[32001];
	vector<int> answer;
	int indeg[32'001];
	
	
	priority_queue<int,vector<int>,greater<int> > pq;
	
	for(int i = 0,a,b; i<M;i++){
		cin>>a>>b;
		adj[a].push_back(b);
		indeg[b]++;
	}
	
	for(int i = 1; i<=N;i++){
		if(indeg[i]==0){
			pq.push(i);
			indeg[i]=-1e9;
		}
	}
	while(!pq.empty()){
		
		int temp = pq.top();
		pq.pop();
		
		answer.push_back(temp);
		for(auto a: adj[temp]){
			if(!(--indeg[a])){
			    pq.push(a);
			    indeg[a]=-1e9;
			}
		}
		
	}
	
	for(auto a: answer){
		cout<<a<<' ';
	}
	
	return 0;
}