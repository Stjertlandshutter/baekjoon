#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>P;


int candidate[100];
bool possible[2001];

// needs to be washed!
int dist1[2001];
int dist2[2001];
int dist3[2001];
int visited[2001];
int prevv[2001];

void dajikstra(int K, int dist[2001],vector<P> adj[2001]){
	priority_queue<P, vector<P>,greater<P>> PQ;
	PQ.push(P(0,K));
	while(!PQ.empty()){
		int curr;
		do{
			curr = PQ.top().second;
			PQ.pop();
		}while(!PQ.empty() && visited[curr]);
		
		if(visited[curr]) break;
		
		visited[curr] = true;
		for(auto &p: adj[curr]){
			int d = p.first, next = p.second;
			
			if(dist[next]>dist[curr]+d){
				dist[next] = dist[curr]+d;
				PQ.push(P(dist[next],next));
				prevv[next] =curr;
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	int T; cin>>T;
	while(T--){
		int n,m,t; cin>>n>>m>>t;
		int s,g,h; cin>>s>>g>>h;
		int theroad;
		vector<int> answer;
		vector<P> adj [2001];
		
		for(int i = 0, a,b,d;i<m;i++){
			cin>>a>>b>>d;
			adj[a].push_back(P(d,b));
			adj[b].push_back(P(d,a));
			if((a == g && b == h) || a== h && b==g)
			    theroad =d;
		}
		
		for(int i = 0; i<t;i++){
			cin>>candidate[i];
		}
		fill(possible,possible+2001,1);
		
		//1. s 에서 각 지점까지의 최단거리를 구하자
		fill(visited,visited+2001,0);
		fill(dist1,dist1+2001,2e9);
		dist1[s] = 0;
		dajikstra(s,dist1,adj);
		
		//2. h 에서 각 후보 교차로들의 최단거리를 구하자. 
		fill(visited,visited+2001,0);
		fill(dist2,dist2+2001,2e9);
		dist2[h] = 0;
		dajikstra(h,dist2,adj);
		
		for(int i = 0; i < t; i++){
		    //s->g->h->end?
			if(possible[candidate[i]] && dist1[candidate[i]] ==  dist1[g] + theroad + dist2[candidate[i]] ){
				answer.push_back(candidate[i]);
			}
		}
		//3. g에서 각 후보 교차로들의 최단거리를 구하자
		fill(visited,visited+2001,0);
		fill(dist2,dist2+2001,2e9);
		dist2[g] = 0;
		dajikstra(g,dist2,adj);
		
		for(int i = 0; i < t; i++){
		    //s->h->g->end?
			if(possible[candidate[i]] && dist1[candidate[i]] ==  dist1[h] + theroad + dist2[candidate[i]] ){
				answer.push_back(candidate[i]);
			}
		}
		answer.erase(unique(answer.begin(),answer.end()),answer.end());
		sort(answer.begin(),answer.end());
		for(auto a: answer)
		    cout<<a<<' ';
		cout<<'\n';
	}
	
	return 0;
}