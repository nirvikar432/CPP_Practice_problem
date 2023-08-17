#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    char a[n + 1];

    cin.getline(a, n + 1);
    // cin.ignore();

    int i = 0;
    int cLen = 0, maxlen = 0;
    int startWordId = 0;
    int maxWordId = 0;

    while (1)
    {
        if (a[i] == ' ' || a[i] == '\0')
        {
            if (cLen > maxlen)
            {
                maxlen = cLen;
                maxWordId = startWordId;
            }
            cLen = 0;
            startWordId = i + 1;
        }
        else
        {
            cLen++;
        }

        if (a[i] == '\0')
        {
            break;
        }

        i++;
    }
    cout << maxlen << endl;

    for (int i = 0; i < maxlen; i++)
    {
        cout << a[i + maxWordId];
    }

    return 0;
}