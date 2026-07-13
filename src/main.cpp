#include <iostream>
#include <vector>
#include "Wavelet.hpp"

int main() {
    std::vector<double> signal = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
    
    // Apply Transform
    Haar<double>::transform(signal);
    
    for (const auto& val : signal) {
        std::cout << val << " ";
    }
    return 0;
}