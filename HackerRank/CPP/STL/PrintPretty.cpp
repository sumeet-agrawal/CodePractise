#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
        cout<<setw(0)<<nouppercase<<showbase<<hex<<(long)A<<endl;
        cout<<fixed<<setprecision(2)<<right<<setw(0xf)<<setfill('_')<<showpos<<B<<endl;
        cout<<noshowpos<<uppercase<<scientific<<setprecision(9)<<C<<endl;
		/* Enter your code here */

	}
	return 0;

}
