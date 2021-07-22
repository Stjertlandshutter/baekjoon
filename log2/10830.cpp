#include <bits/stdc++.h>
using namespace std;




int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	long long N,B,in=0;
	long long answer[5][5];
	
	cin>>N>>B;
	
	for(int i = 0; i<N;i++)
		answer[i][i] = 1;
	long long matrixes [37][5][5];
    memset(matrixes,0,sizeof(matrixes));
	
	bool binary[37];
	
	for(int i= 0; i<N;i++){
		for(int j = 0; j<N;j++){
			cin>>matrixes[0][i][j];
		}
	}
	
	binary[in] = B%2;
	B/=2;
	in++;
	
	while(B>0){
		
		
		for(int i = 0; i<N; i++)
			for(int j = 0; j<N; j++)
				for(int k = 0; k<N; k++){
					matrixes[in][i][j] = (matrixes[in][i][j]%1000 + (matrixes[in-1][i][k] %1000 * matrixes[in-1][k][j]%1000) % 1000)%1000;
				}
		binary[in] = B%2;
		B/=2;
		in++;
		
	}
	
	for(int p= 0; p<in;p++){
	    if(binary[in-p-1]){
    		long long temp[5][5];
    		
    		for(int i = 0; i<N; i++)
    			for(int j = 0; j<N; j++){
    				temp[i][j] = answer[i][j];
    				answer[i][j] = 0;
    			}	
    		for(int i = 0; i<N; i++){
    			for(int j = 0; j<N; j++){
    				for(int k = 0; k<N; k++){
    					answer[i][j] = (answer[i][j]%1000 + (temp[i][k]%1000 * matrixes[in - p - 1][k][j]%1000) %1000)%1000;
    				}
    			}
    		}
	    }
	}
	
	
	for(int i = 0; i<N; i++){
		for(int j = 0; j<N; j++){
			cout<<answer[i][j]%1000<<' ';
		}
		cout<<'\n';
	}


	return 0;
}