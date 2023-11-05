
#include <iostream>
#include <vector>

template<typename T>
void SMA(std::vector<T> data, int n) {
    if (n > data.size())
        return;
    int t = n - 1;
    T avg = 0;
    T sum = 0;
    for (int i = t; i > t - n; i--) {
        sum += data[i];
    }
    avg = sum / n;
    std::cout << avg << std::endl;
    t++;
    while (t < data.size()) {
        avg = avg + (data[t] - data[t - n]) / n;
        std::cout << avg << std::endl;
        t++;
    }
}

int main()
{
    std::vector<double> data{ 1, 4, 3, 5, 2, 8, 11 };
    SMA(data, 3);
}
