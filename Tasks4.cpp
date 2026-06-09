#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <cmath>    

using namespace std;

struct less_abs {
    bool operator()(const int a, const int b) const {
        return abs(a) < abs(b);
    }
};

int main() {
    int k;
    cin >> k;
    vector<int> V((istream_iterator<int>(cin)), istream_iterator<int>());
    
    using namespace std::placeholders;
    
    auto it = find_if(V.rbegin(), V.rend(), bind(less_abs(), k, _1));

    if (it != V.rend()) {
        cout << *it << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
