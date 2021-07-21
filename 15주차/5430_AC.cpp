// reverse -> O(N)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int t, n;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--)
    {
        string str, func, tmp;
        deque<int> v;
        bool flag = true;
        cin >> func;
        cin >> n;
        cin >> str;
        if (n != 0)
        {
            for (int i = 1; i < str.size(); i++)
            {
                if (str[i] == ',' || str[i] == ']')
                {
                    v.push_back(stoi(tmp));
                    tmp.clear();
                }
                else
                {
                    tmp.push_back(str[i]);
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < func.size(); i++)
        {
            if (func[i] == 'D')
            {
                if (v.size() == 0)
                {
                    flag = false;
                    cout << "error\n";
                    break;
                }
                if (cnt % 2 == 0)
                    v.pop_front();
                else
                    v.pop_back();
            }
            else
            {
                cnt++;
            }
        }
        if (!flag)
            continue;
        else
        {
            int size = v.size();
            cout << '[';
            if (cnt % 2 == 0)
            {
                for (int i = 0; i < size; i++)
                {
                    cout << v[i];
                    if (i != size - 1)
                        cout << ',';
                }
            }
            else
            {
                for (int i = size - 1; i >= 0; i--)
                {
                    cout << v[i];
                    if (i != 0)
                        cout << ',';
                }
            }
            cout << "]\n";
        }
    }
}