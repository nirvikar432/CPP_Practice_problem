#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s = "sdnjsadasjhryrhweiurncewiohraaaaa";
    int freq[26] = {0};

    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i] - 'a']++;
    }

    int maxFreq = 0;
    char ans;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > maxFreq)
        {
            maxFreq = freq[i];
            ans = i + 'a';
        }
        // maxFreq = max(maxFreq,freq[i]);
    }
    cout << ans << " " << maxFreq << " times";

    return 0;
}