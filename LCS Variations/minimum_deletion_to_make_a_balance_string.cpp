#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();

    // Frequency map to store the frequency of each character
    unordered_map<char, int> freq;
    for (char c : s)
    {
        freq[c]++;
    }

    // Determine the maximum frequency of any character
    int max_freq = 0;
    for (const auto& entry : freq)
    {
        max_freq = max(max_freq, entry.second);
    }

    // Calculate the total deletions needed to make all characters have the same frequency
    int deletions = 0;
    for (const auto& entry : freq)
    {
        deletions += entry.second - max_freq;
    }

    cout << deletions << endl;

    return 0;
}
