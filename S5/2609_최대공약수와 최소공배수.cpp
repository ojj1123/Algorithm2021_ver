#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int GCD(int a, int b) {
	if (b == 0) return a;
	else return GCD(b, a%b);
}
int LCM(int a, int b) {
	return a * b / GCD(a, b);
}
int main()
{
	FAST;
	int a, b;
	cin >> a >> b;
	int gcd = a > b ? GCD(a, b) : GCD(b, a);
	int lcm = a > b ? LCM(a, b) : LCM(b, a);
	cout << gcd << "\n" << lcm;
	return 0;
}