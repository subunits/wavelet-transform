#ifndef WAVELET_HPP
#define WAVELET_HPP

#include <vector>
#include <cmath>
#include <stdexcept>

template <typename T>
class Haar {
public:
    static void transform(std::vector<T>& data) {
        size_t n = data.size();
        if (n < 2) return;
        std::vector<T> temp(n);
        size_t h = n / 2;
        for (size_t i = 0; i < h; ++i) {
            // Approximation: Average of the pair normalized by sqrt(2)
            temp[i] = (data[2 * i] + data[2 * i + 1]) / std::sqrt(2.0);
            // Detail: Difference of the pair normalized by sqrt(2)
            temp[i + h] = (data[2 * i] - data[2 * i + 1]) / std::sqrt(2.0);
        }
        data = temp;
    }
};
#endif
