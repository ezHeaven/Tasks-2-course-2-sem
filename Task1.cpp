#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <string>
#include <functional>

using namespace std;

int main() {
    string name1 = "file1.txt";
    string name2 = "file2.txt";

    ifstream f1(name1);
    ifstream f2(name2);

    if (!f1.is_open() || !f2.is_open()) {
        cerr << "Ошибка чтения файла!" << endl;
        return 1;
    }

    istream_iterator<double> start1(f1), end1;
    istream_iterator<double> start2(f2);

    transform(start1, end1, start2, 
              ostream_iterator<double>(cout, " "), 
              [](double a, double b) {
                  return b - a;
              });

    cout << endl;

    f1.close();
    f2.close();

    return 0;
}