
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

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
    /*
    std::vector<double> data{ 1, 4, 3, 5, 2, 8, 11 };
    std::vector<double> res = SMA(data,37);
    for (double val : res) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    */

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

    std::vector<float> tempFloat;
    tempFloat = dataFloat;
    for (int i = 0; i < 99; i++) {
        dataFloat.insert(dataFloat.end(), tempFloat.begin(), tempFloat.end());
    }
    std::cout<<"float data size: " << dataFloat.size() << std::endl;

    std::ifstream doubleFile("double1000000.bin", std::ios::binary);
    double doubleBuffer;
    doubleFile.read(reinterpret_cast<char*>(&sampleSize), sizeof(int));
    for (size_t i = 0; i < sampleSize; i++) {
        doubleFile.read(reinterpret_cast<char*>(&doubleBuffer), sizeof(double));

        dataDouble.push_back(doubleBuffer);
    }
    doubleFile.close();


    std::vector<double> tempDouble;
    tempDouble = dataDouble;
    for (int i = 0; i < 99; i++) {
        dataDouble.insert(dataDouble.end(), tempDouble.begin(), tempDouble.end());
    }
    std::cout << "double data size: " << dataDouble.size() << std::endl;


    auto start_time = std::chrono::high_resolution_clock::now();
    std::vector<float> float4SMA = SMA(dataFloat, 4);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto time = end_time - start_time;
    std::cout << "float n=4: " << time / std::chrono::milliseconds(1)<<std::endl;
    start_time = std::chrono::high_resolution_clock::now();
    std::vector<float> float8SMA = SMA(dataFloat, 8);
    end_time = std::chrono::high_resolution_clock::now();
    std::cout << "float n=8: " << time / std::chrono::milliseconds(1) << std::endl;
    start_time = std::chrono::high_resolution_clock::now();
    std::vector<float> float16SMA = SMA(dataFloat, 16);
    end_time = std::chrono::high_resolution_clock::now();
    std::cout << "float n=16: " << time / std::chrono::milliseconds(1) << std::endl;
    start_time = std::chrono::high_resolution_clock::now();
    std::vector<float> float32SMA = SMA(dataFloat, 32);
    end_time = std::chrono::high_resolution_clock::now();
    std::cout << "float n=32: " << time / std::chrono::milliseconds(1) << std::endl;
    start_time = std::chrono::high_resolution_clock::now();
    std::vector<float> float64SMA = SMA(dataFloat, 64);
    end_time = std::chrono::high_resolution_clock::now();
    std::cout << "float n=64: " << time / std::chrono::milliseconds(1) << std::endl;
    start_time = std::chrono::high_resolution_clock::now();
    std::vector<float> float128SMA = SMA(dataFloat, 128); end_time = std::chrono::high_resolution_clock::now();
    std::cout << "float n=128: " << time / std::chrono::milliseconds(1) << std::endl;
    std::cout << std::endl;

    start_time = std::chrono::high_resolution_clock::now();
    std::vector<double> double4SMA = SMA(dataDouble, 4);
    end_time = std::chrono::high_resolution_clock::now();
    time = end_time - start_time;
    std::cout << "double n=4: " << time / std::chrono::milliseconds(1)<<std::endl;
    start_time = std::chrono::high_resolution_clock::now();
    std::vector<double> double8SMA = SMA(dataDouble, 8);
    end_time = std::chrono::high_resolution_clock::now();
    std::cout << "double n=8: " << time / std::chrono::milliseconds(1) << std::endl;
    start_time = std::chrono::high_resolution_clock::now();
    std::vector<double> double16SMA = SMA(dataDouble, 16);
    end_time = std::chrono::high_resolution_clock::now();
    std::cout << "double n=16: " << time / std::chrono::milliseconds(1) << std::endl;
    start_time = std::chrono::high_resolution_clock::now();
    std::vector<double> double32SMA = SMA(dataDouble, 32);
    end_time = std::chrono::high_resolution_clock::now();
    std::cout << "double n=32: " << time / std::chrono::milliseconds(1) << std::endl;
    start_time = std::chrono::high_resolution_clock::now();
    std::vector<double> double64SMA = SMA(dataDouble, 64);
    end_time = std::chrono::high_resolution_clock::now();
    std::cout << "double n=64: " << time / std::chrono::milliseconds(1) << std::endl;
    start_time = std::chrono::high_resolution_clock::now();
    std::vector<double> double128SMA = SMA(dataDouble, 128); end_time = std::chrono::high_resolution_clock::now();
    std::cout << "double n=128: " << time / std::chrono::milliseconds(1) << std::endl;

}
