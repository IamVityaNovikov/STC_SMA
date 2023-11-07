
#include <iostream>
#include <fstream>
#include <vector>

template<typename T>
std::vector<T> SMA(std::vector<T> data, int n) {
    std::vector<T> results;
    if ((n > data.size())||(n<1))
        return results;
    int resultSize = data.size() - n + 1;
    results.reserve(resultSize);
    int t = n - 1;
    T avg = 0;
    T sum = 0;
    for (int i = t; i > t - n; i--) {
        sum += data[i];
    }
    avg = sum / n;
    results.push_back(avg);
    t++;
    while (t < data.size()) {
        avg = avg + (data[t] - data[t - n]) / n;
        results.push_back(avg);
        t++;
    }
    return results;
}

int main()
{
    std::vector<double> data{ 1, 4, 3, 5, 2, 8, 11 };
    std::vector<double> res = SMA(data,37);
    for (double val : res) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::vector<float> dataFloat;
    std::vector<double> dataDouble;

    std::ifstream floarFile("float1000000.bin", std::ios::binary);
    int sampleSize;
    float floatBuffer;
    floarFile.read(reinterpret_cast<char*>(&sampleSize), sizeof(int));
    for (size_t i = 0; i < sampleSize; i++) {
        floarFile.read(reinterpret_cast<char*>(&floatBuffer), sizeof(float));

        dataFloat.push_back(floatBuffer);
    }
    floarFile.close();

    std::ifstream doubleFile("double1000000.bin", std::ios::binary);
    double doubleBuffer;
    doubleFile.read(reinterpret_cast<char*>(&sampleSize), sizeof(int));
    for (size_t i = 0; i < sampleSize; i++) {
        doubleFile.read(reinterpret_cast<char*>(&doubleBuffer), sizeof(double));

        dataDouble.push_back(doubleBuffer);
    }
    doubleFile.close();

    
    for (int i = 0; i < 50; i++) {
        std::cout << dataFloat[i]  << "\t" << dataDouble[i] << std::endl;
    }
    
}
