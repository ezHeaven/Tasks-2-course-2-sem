#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
    list<int> L((istream_iterator<int>(cin)), istream_iterator<int>());

    if (L.empty()) {
        return 0;
    }

    auto half_size = L.size() / 2;
    auto i = L.begin();
    advance(i, half_size); 
    
    while (i != L.begin()) {
        L.insert(i--, -1);
    }

    for_each(L.begin(), L.end(), [](const int n) {
        cout << n << " ";
    });

    return 0;
}
