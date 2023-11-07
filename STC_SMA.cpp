
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

/**
*Simple Moving Average
* data - вектор исходных данных
* n - размер окна
**/
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
    std::vector<float> dataFloat;
    std::vector<double> dataDouble;

    // Чтение значений double из файла
    std::ifstream floarFile("float1000000.bin", std::ios::binary);
    int sampleSize;
    float floatBuffer;
    floarFile.read(reinterpret_cast<char*>(&sampleSize), sizeof(int));
    for (size_t i = 0; i < sampleSize; i++) {
        floarFile.read(reinterpret_cast<char*>(&floatBuffer), sizeof(float));

        dataFloat.push_back(floatBuffer);
    }
    floarFile.close();

    //увеличение размера исходных данных float в 100 раз
    std::vector<float> tempFloat;
    tempFloat = dataFloat;
    for (int i = 0; i < 99; i++) {
        dataFloat.insert(dataFloat.end(), tempFloat.begin(), tempFloat.end());
    }

    // Чтение значений double из файла
    std::ifstream doubleFile("double1000000.bin", std::ios::binary);
    double doubleBuffer;
    doubleFile.read(reinterpret_cast<char*>(&sampleSize), sizeof(int));
    for (size_t i = 0; i < sampleSize; i++) {
        doubleFile.read(reinterpret_cast<char*>(&doubleBuffer), sizeof(double));

        dataDouble.push_back(doubleBuffer);
    }
    doubleFile.close();

    //увеличение размера исходных данных double в 100 раз
    std::vector<double> tempDouble;
    tempDouble = dataDouble;
    for (int i = 0; i < 99; i++) {
        dataDouble.insert(dataDouble.end(), tempDouble.begin(), tempDouble.end());
    }

    //Замеры времени исполнения
    //float
    auto start_time = std::chrono::high_resolution_clock::now();
    std::vector<float> float4SMA = SMA(dataFloat, 4);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto float4res = (end_time - start_time) / std::chrono::milliseconds(1);

    start_time = std::chrono::high_resolution_clock::now();
    std::vector<float> float8SMA = SMA(dataFloat, 8);
    end_time = std::chrono::high_resolution_clock::now();
    auto float8res = (end_time - start_time) / std::chrono::milliseconds(1);
    
    start_time = std::chrono::high_resolution_clock::now();
    std::vector<float> float16SMA = SMA(dataFloat, 16);
    end_time = std::chrono::high_resolution_clock::now();
    auto float16res = (end_time - start_time) / std::chrono::milliseconds(1);
    
    start_time = std::chrono::high_resolution_clock::now();
    std::vector<float> float32SMA = SMA(dataFloat, 32);
    end_time = std::chrono::high_resolution_clock::now();
    auto float32res = (end_time - start_time) / std::chrono::milliseconds(1);
    
    start_time = std::chrono::high_resolution_clock::now();
    std::vector<float> float64SMA = SMA(dataFloat, 64);
    end_time = std::chrono::high_resolution_clock::now();
    auto float64res = (end_time - start_time) / std::chrono::milliseconds(1);
    
    start_time = std::chrono::high_resolution_clock::now();
    std::vector<float> float128SMA = SMA(dataFloat, 128); end_time = std::chrono::high_resolution_clock::now();
    auto float128res = (end_time - start_time) / std::chrono::milliseconds(1);
    std::cout << std::endl;

    //Замеры с double
    start_time = std::chrono::high_resolution_clock::now();
    std::vector<double> double4SMA = SMA(dataDouble, 4);
    end_time = std::chrono::high_resolution_clock::now();
    auto double4res = (end_time - start_time) / std::chrono::milliseconds(1);
    
    start_time = std::chrono::high_resolution_clock::now();
    std::vector<double> double8SMA = SMA(dataDouble, 8);
    end_time = std::chrono::high_resolution_clock::now();
    auto double8res = (end_time - start_time) / std::chrono::milliseconds(1);
    
    start_time = std::chrono::high_resolution_clock::now();
    std::vector<double> double16SMA = SMA(dataDouble, 16);
    end_time = std::chrono::high_resolution_clock::now();
    auto double16res = (end_time - start_time) / std::chrono::milliseconds(1);
    
    start_time = std::chrono::high_resolution_clock::now();
    std::vector<double> double32SMA = SMA(dataDouble, 32);
    end_time = std::chrono::high_resolution_clock::now();
    auto double32res = (end_time - start_time) / std::chrono::milliseconds(1);
    
    start_time = std::chrono::high_resolution_clock::now();
    std::vector<double> double64SMA = SMA(dataDouble, 64);
    end_time = std::chrono::high_resolution_clock::now();
    auto double64res = (end_time - start_time) / std::chrono::milliseconds(1);
    
    start_time = std::chrono::high_resolution_clock::now();
    std::vector<double> double128SMA = SMA(dataDouble, 128); end_time = std::chrono::high_resolution_clock::now();
    auto double128res = (end_time - start_time) / std::chrono::milliseconds(1);

    std::cout << "Perfomance:" << std::endl;
    std::cout << "float n  = 4\t" << float4res << std::endl;
    std::cout << "float n  = 8\t" << float8res << std::endl;
    std::cout << "float n  = 16\t" << float16res << std::endl;
    std::cout << "float n  = 32\t" << float32res << std::endl;
    std::cout << "float n  = 64\t" << float64res << std::endl;
    std::cout << "float n  = 128\t" << float128res << std::endl;
    std::cout << std::endl;
    std::cout << "double n  = 4\t" << double4res << std::endl;
    std::cout << "double n  = 8\t" << double8res << std::endl;
    std::cout << "double n  = 16\t" << double16res << std::endl;
    std::cout << "double n  = 32\t" << double32res << std::endl;
    std::cout << "double n  = 64\t" << double64res << std::endl;
    std::cout << "double n  = 128\t" << double128res << std::endl;

}
