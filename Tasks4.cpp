#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

struct less_abs {
    bool operator()(int a, int b) const {
        return abs(a) < abs(b);
    }
};

int main() {
    int K = 5;
    vector<int> V = {1, -2, 10, 3, -8, 4};
    
    using namespace std::placeholders;
    
    auto it = find_if(V.rbegin(), V.rend(), bind(less_abs(), K, _1));

    if (it != V.rend()) {
        cout << *it << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}