 #include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;

int R,C; 
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
char mapp[100][100];


bool cmp(P a, P b){
	return a.first > b.first;;
}

int drop(vector<P> cluster){
	int flor = -1;
	sort(cluster.begin(),cluster.end(),cmp);
	
	// check if this cluster will fall
	
	for(auto a: cluster){
		flor = max(flor,a.first); 
	}
	
	if(flor == R-1) return 0;
	
	// calculate the fall
	
	int minfall = 2e9;
	bool hasflor[100];
    vector<P> flors;
	
	for(auto a:cluster){
	    if(!hasflor[a.second]){
	        flors.push_back(a);
	        hasflor[a.second] = true;
	    }
	}
	
	for(auto a: flors){
			for(int i = a.first+1; i <= R; i++){
				if(i == R || mapp[i][a.second] == 'x' ){
					minfall = min( minfall, i-a.first-1);
					break;
				}
			}
	}
	
	// execute the fall
	
	
	for(auto a: cluster){
		mapp[a.first][a.second] = '.';
		mapp[a.first+minfall][a.second] = 'x';
	}
	
	
	return 1;
}


vector<P> bfs(int r, int c ){
	queue<P> Q;
	Q.push(P(r,c));
	
	vector<P> rtn;
	int level = 0;
	rtn.push_back(P(r,c));
	
	bool visited[100][100];
	memset(visited,0,sizeof(visited));
	
	while(!Q.empty()){
		int qSize = Q.size();
		for(int i = 0; i< qSize; i++){
			P curr = Q.front();
			Q.pop();
			
			for(int i = 0; i < 4; i++){
				int nx = curr.first + dx[i];
				int ny = curr.second + dy[i];
				
				if(nx < R && nx > -1 && ny < C && ny > -1 &&!visited[nx][ny] && mapp[nx][ny] == 'x'){
					visited[nx][ny] = true;
					Q.push(P(nx,ny));
					rtn.push_back(P(nx,ny));
				}
			}
		}
	}
	
	return rtn;
}


int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	cin>>R>>C;
	
	for(int i = 0; i<R;i++){
		string temp; 
		cin>>temp;
		for(int j = 0; j<C; j++){
			mapp[i][j] = temp.at(j);
		}
	}
	
	int N; cin>>N;
	int throws[100];
	for(int i = 0; i<N;i++){
		cin>>throws[i];
		throws[i] = R - throws[i];
	}
	
	for(int t = 0; t<N;t++){
		//1. throw stick
	//	cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaa\n";
		for(int i = 0; i<C;i++){
			int r =  throws[t];
			int c = (t%2) ? C-1-i : i;	
			// 2. if there's mineral..
			if(mapp[r][c] == 'x'){
			 //   cout<<"hit! at:"<<r<<','<<c<<'\n';
			 //   cout<<"t is "<<t<<'\n';
			    
			  
				mapp[r][c] ='.';
				for(int j = 0; j<4;j++){
					int nr = r + dx[j];
					int nc = c + dy[j];
					if( nr < R && nr > -1 && nc < C && nc > -1 && mapp[nr][nc] == 'x'){
						// 3. check clusters
						vector<P> cluster = bfs(nr,nc);
						// 4. ...drop it!
						if(drop(cluster)) break;;
					}
				}
				break;
			}
			
		}
		//  for(int i = 0; i<R;i++){
		//for(int j = 0; j<C; j++){
		//	cout<<mapp[i][j];
		//}
		//cout<<'\n';
	//}
	}
	for(int i = 0; i<R;i++){
		for(int j = 0; j<C; j++){
			cout<<mapp[i][j];
		}
		cout<<'\n';
	}
	return 0;
}