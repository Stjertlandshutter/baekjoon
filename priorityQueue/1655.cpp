#include <bits/stdc++.h>
using namespace std;

int main(){
	
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int N, num; cin>>N;
	priority_queue<int> gQ; //숫자가 큰게 Top 3 2 1
	priority_queue<int, vector<int>, greater<int> > lQ; // 숫자가 작은게 Top 4 5 6
	
	for(int i = 0; i<N;i++){
		cin >>num;
		if(i%2)
			lQ.push(num);
		else
			gQ.push(num);
		
		if(!lQ.empty() && lQ.top() < gQ.top()){
			int temp = lQ.top();
			lQ.pop();
			lQ.push(gQ.top());
			gQ.pop();
			gQ.push(temp);
		}		
		
		cout<<gQ.top()<<'\n';
	}
	return 0;
}