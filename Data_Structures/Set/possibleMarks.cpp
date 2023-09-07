#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n, p, q;
    cin >> n >> p >> q;
    set<int> st;

    for (int i = 0; i <= n; i++)
    // 0 1 2 3
    {
        for (int j = 0; j <= n - i; j++) //  0   1   2   3               0   1   2       0   1       0
        {
            // int nCorrect = i;1
            // int nIncorrect = j;
            int nUnanswered = n - (i + j);
            cout << i << " " << j << " " << nUnanswered << endl;
            // if (nUnanswered >= 0)
            // {
            int ans = (i * p) + (j * q);
            st.insert(ans);
            // }
            // else
            // {
            //     break;
            // }
        }
    }

    cout << "ANS" << st.size();

    return 0;
}