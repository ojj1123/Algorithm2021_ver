#include <iostream>
using namespace std;
int main()
{
	double N;
	scanf_s("%lf", &N);
	printf_s("%d %d", (int)(N * 0.78), (int)(N - N * 0.2*0.22));
	return 0;
}