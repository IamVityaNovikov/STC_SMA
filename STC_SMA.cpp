
#include <iostream>
#include <vector>

//простая реализация
void SMA(std::vector<float> data, int n) {
    if (n > data.size()) {
        return;
    }
    int t = n - 1;
    while (t < data.size()) {
        float sum = 0;
        for (int i = t; i > t - n; i--) {
            sum += data[i];
        }
        std::cout << sum / n << std::endl;
        t++;
    }
}

int main()
{
    std::vector<float> data{ 1, 4, 3, 5, 2, 8, 11 };
    SMA(data, 3);
}
