
#include <iostream>
#include <vector>

//простая реализация
void SMA(std::vector<float> data, int n) {
    if (n > data.size())
        return;
    int t = n - 1;
    float avg = 0;
    float sum = 0;
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
    std::vector<float> data{ 1, 4, 3, 5, 2, 8, 11 };
    SMA(data, 3);
}
