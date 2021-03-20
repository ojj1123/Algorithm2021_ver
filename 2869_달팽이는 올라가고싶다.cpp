#include <iostream>
using namespace std;

int main()
{
	int A, B, V, num;
	cin >> A >> B >> V;
	int temp = V - A;
	if (temp % (A - B) == 0) {
		num = (temp / (A - B)) + 1;
	}
	else {
		num = (temp / (A - B)) + 2;
	}
	cout << num;
	return 0;
}