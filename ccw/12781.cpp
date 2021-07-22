#include <iostream>
using namespace std;

int cross(int x1, int y1, int x2, int y2){
    return x1*y2-x2*y1;
}
int ccw(int x1, int y1,int x2, int y2,int x3, int y3){
	int r = cross(x2-x1, y2-y1, x3-x1, y3-y1);
	if(r>0) return 1;
	if(r<0) return -1;
	else return 0;
}

int main(){
	int x1, y1, x2, y2, x3, y3, x4, y4;
	cin>> x1>> y1>> x2>> y2>> x3>> y3>> x4>> y4;
	
	
	cout<<(ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4) < 0
	  && ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2) < 0);
	return 0;
}

