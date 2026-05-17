#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    vector<string> V = {"APPLE", "BANANA", "APRICOT", "CHERRY", "BLUEBERRY", "CITRUS"};

    map<char, int> M;

    for_each(V.begin(), V.end(), [&M](const string& s) {
        M[s[0]] += s.size();
    });

    for_each(M.begin(), M.end(), [](const pair<char, int>& p) {
        cout << p.first << " " << p.second << endl;
    });

    return 0;
}