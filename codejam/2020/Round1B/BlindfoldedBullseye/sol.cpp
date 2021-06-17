// does not pass the 3rd case.
#include <bits/stdc++.h>
using namespace std;

const int L = 1e9;
int t, a, b;
string res;

int query(int x, int y){
	string res;
	cout << x << ' ' << y << endl;
	cin >> res;
	
	if(res[0] == 'M'){
		return 0;
	}
	
	else if(res[0] == 'H'){
		return 1;
	}

	else if(res[0] == 'C'){
		return 2;
	}

	else{
		exit(-1);
	}
}

void solve(){
	int x0, y0;
	int x1, y1;
	int x2, y2;
	int x3, y3;
	int x_min, x_max;
	int y_min, y_max;
	int md;
	int x_hit, y_hit;
	int xc, yc;
	int state;

	for(int i=-1; i<=1; i++){
		for(int j=-1; j<=1; j++){
			state = query(L/2*i, L/2*j);
			if(state == 0){
				// do nothing;
			}
			else if(state == 1){
				x_hit = L/2*i;
				y_hit = L/2*j;
			}
			else{
				return;
			}
		}
	}

	x0 = 0, y0 = 0;
	y_min = y_hit, y_max = L;

	while(true){
		md = (y_min + y_max) / 2;
		if(y_min + 1 >= y_max){
			y0 = y_min;
			break;
		}
		state = query(x0, md);
		if(state == 0){
			y_max = md;
		}
		else if(state == 1){
			y_min = md;
		}
		else{
			return;
		}
	}

	x1 = 0, y1 = 0;
	y_min = -L, y_max = y_hit;

	while(true){
		md = (y_min + y_max) / 2;
		if(y_min + 1 >= y_max){
			y1 = y_min;
			break;
		}
		state = query(x1, md);
		if(state == 0){
			y_min = md;
		}
		else if(state == 1){
			y_max = md;
		}
		else{
			return;
		}
	}

	x2 = 0, y2 = 0;
	x_min = x_hit, x_max = L;

	while(true){
		md = (x_min + x_max) / 2;
		if(x_min + 1 >= x_max){
			x2 = x_min;
			break;
		}
		state = query(md, y2);
		if(state == 0){
			x_max = md;
		}
		else if(state == 1){
			x_min = md;
		}
		else{
			return;
		}
	}

	x3 = 0, y3 = 0;
	x_min = -L, x_max = x_hit;

	while(true){
		md = (x_min + x_max) / 2;
		if(x_min + 1 >= x_max){
			x3 = x_min;
			break;
		}
		state = query(md, y3);
		if(state == 0){
			x_min = md;
		}
		else if(state == 1){
			x_max = md;
		}
		else{
			return;
		}
	}

	// cerr << x0 << ' ' << y0 << endl;
	// cerr << x1 << ' ' << y1 << endl;
	// cerr << x2 << ' ' << y2 << endl;
	// cerr << x3 << ' ' << y3 << endl;
	xc = (x2 + x3) / 2;
	yc = (y0 + y1) / 2;
	for(int i=-2; i<3; i++){
		for(int j=-2; j<3; j++){
			state = query(xc+i, yc+j);
			// cerr << state;
			if(state == 2){
				return;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

  cin >> t >> a >> b;
  for(int i=0; i<t; i++){
		solve();
  }
}