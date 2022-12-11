#include <iostream>
#include <string>
#include<fstream>
#include <cmath>
#include <limits>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
std::string to_binary_string(unsigned long long n)
{
    std::string buffer; // символы ответа в обратном порядке
    // выделим память заранее по максимуму
    buffer.reserve(std::numeric_limits<unsigned int>::digits);
    do
    {
        buffer += char('0' + n % 2); // добавляем в конец
        n = n / 2;
    } while (n > 0);
    return std::string(buffer.crbegin(), buffer.crend()); // разворачиваем результат
}

int main() {

    unsigned long long n;
    std::cin >> n;
  

   // string res = to_binary_string(n);
    string res = to_binary_string(n);
    cout << res;
    int size = res.length();
    while (size > 0) {
        if (res[size - 1] == '1') {
            cout << res.length() - size << endl;
            size--;
        }
        else size--;
    }
}
