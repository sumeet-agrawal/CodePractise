/* Enter your macros here */
#define io(a) cin>>a
#define INF 100000001
#define toStr(a) "Result =" 
#define foreach(a, b) for(int b=0;b<n;b++)
#define FUNCTION(a,b) void a(int &c,int &d){if(d b c){c = d;}}

#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
	int n; cin >> n;
	vector<int> v(n);
	foreach(v, i) {
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	cout << toStr(Result =) <<' '<< ans;
	return 0;

}
