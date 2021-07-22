#include <bits/stdc++.h>
using namespace std;

int p[300001];

int find(int a){
	if(p[a]!=-1)
		return find(p[a]);
	return a;
}

int merge(int a, int b){
	int A = find(a), B = find(b);
	if(A==B) return A;
	p[B] = A;
	return A;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	memset(p,-1,sizeof(p));	
	
	int N;cin>>N;
	for(int i = 0,a,b;i<N;i++){
		cin>>a>>b;
		merge(a,b);
	}
	
	for(int i = 1;i<N;i++){
		if(find(0)!=find(i)){
			cout<<0<<' '<<i;
			return 0;
		}
	}
	
	return 0;
}