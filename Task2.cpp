#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
    list<int> L = {10, 20, 30, 40, 50, 60};

    auto half_size = L.size() / 2;

    auto i = L.begin();
    advance(i, half_size); 
    
    while (i != L.begin()) {
        L.insert(i--, -1);
    }

    for_each(L.begin(), L.end(), [](int n) {
        cout << n << " ";
    });

    return 0;
}