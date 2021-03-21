#include <iostream>
#include <string>
#include <string.h>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
	FAST;
	string kda;
	char str[9] = {'\0', };
	int score[3], i;
	getline(cin, kda);
	for (i = 0; i < (int)kda.size(); i++) {
		str[i] = kda[i];
	}
	char *ptr = strtok(str, "/");
	i = 0;
	while (ptr != NULL) {
		score[i] = atoi(ptr);
		ptr = strtok(NULL, "/");
		i++;
	}
	if (score[0] + score[2] < score[1] || score[1] == 0)
		cout << "hasu";
	else cout << "gosu";

	return 0;
}