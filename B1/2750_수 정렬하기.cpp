#include <vector>
#include <iostream>
using namespace std;
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
    FAST;
    int n, i;
    cin >> n;
    vector<int> vec(n);
    for (i = 0; i < vec.size(); i++)
        cin >> vec[i];
    while (1)
    {
        int flag = 0;
        for (i = 0; i < vec.size() - 1; i++)
        {
            if (vec[i] > vec[i + 1])
            {
                int temp = vec[i + 1];
                vec[i + 1] = vec[i];
                vec[i] = temp;
                flag = 1;
            }
        }
        if (!flag)
            break;
    }
    for (i = 0; i < vec.size(); i++)
        cout << vec[i] << "\n";
    // sort함수 사용(algorithm헤더)
    // int n, i;
    // int arr[1000];
    // cin >> n;
    // for (i = 0; i < n; i++)
    // 	cin >> arr[i];
    // sort(arr, arr + n);
    // for (i = 0; i < n; i++)
    // 	cout << arr[i] << "\n";
    return 0;
}