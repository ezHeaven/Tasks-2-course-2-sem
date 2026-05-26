#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
    list<int> L;
    int n;

    cout << "Введите количество элементов в списке: ";
    if (!(cin >> n) || n < 0) {
        cout << "Ошибка: введено некорректное число." << endl;
        return 1;
    }

    cout << "Введите " << n << " чисел(ла): ";
    for (int i = 0; i < n; ++i) {
        int element;
        cin >> element;
        L.push_back(element);
    }

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