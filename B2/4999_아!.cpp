#include <string>
#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
	FAST;
	string myAh, doctorAh;
	cin >> myAh;
	cin >> doctorAh;
	if (myAh.length() >= doctorAh.length())
		cout << "go";
	else cout << "no";

	return 0;
}