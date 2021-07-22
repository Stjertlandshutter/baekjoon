#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	while(1){
		int answer = 1;
		int sampledex = 0;
		bool collecting =true;
		string s; cin>>s;
		if(s == ".") return 0;
		string sample;

		sample += s[0];
		
		for(int i = 1; i<s.length();i++){
		    
			if(collecting){
				if(s[i] == sample[0]){
					collecting = false;
					sampledex =1;
					if(sample.length()==1)
					    answer++;
				}
				else
					sample+=s[i];
			}
			
			else{
			    if(sample.length() == 1){
			        if(s[i] == sample[0])
			            answer++;
			        else{
			            collecting = true;
					    answer = 1;
					    sampledex = 0;
					    sample = s.substr(0,i+1);
			        }       
			    }
			    else{
				    if(s[i] != sample[sampledex] ){
					    collecting = true;
				    	answer = 1;
					    sampledex = 0;
					    sample = s.substr(0,i+1);
				    }
				    else{
				    	if(sampledex == sample.length()-1){
						    sampledex = 0;
						    answer++;
					    }
					    else
						    sampledex++;
			    	}
			    }
			}
		}
		cout<<answer<<'\n';
	}
	
	
	return 0;
}