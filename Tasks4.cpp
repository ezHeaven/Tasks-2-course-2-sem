#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <cmath>    

using namespace std;

/**
 * @brief сравнивает два числа по абсолютному значению
 * @param a - первое число для сравнения
 * @param b - второе число для сравнения
 * @return - возращает булево значение
 */
struct less_abs {
    bool operator()(const int a, const int b) const;
};

int main() {
    int k = 0;
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

struct less_abs {
    bool operator()(int a, int b) const {
        return abs(a) < abs(b);
    }
};
