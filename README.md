# WaveletEngine

A high-performance C++ library for wavelet transforms with support for the Haar wavelet basis.

## Features

- **Haar Wavelet Transform**: Fast, efficient wavelet decomposition
- **Template-based Design**: Works with any numeric type (float, double, etc.)
- **Header-only Components**: Easy integration into C++ projects
- **C++17 Standard**: Modern C++ practices and features
- **Zero Dependencies**: Only requires a C++17 compatible compiler

## Building

### Requirements

- CMake 3.10 or higher
- C++17 compiler (GCC, Clang, MSVC)

### Build Instructions

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

The compiled executable will be available in the `build/` directory.

## Usage

### Basic Example

```cpp
#include <iostream>
#include <vector>
#include "Wavelet.hpp"

int main() {
    // Create a signal
    std::vector<double> signal = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
    
    // Apply Haar wavelet transform
    Haar<double>::transform(signal);
    
    // Output the transformed coefficients
    for (const auto& val : signal) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
```

## API Reference

### Haar Transform

```cpp
template <typename T>
class Haar {
public:
    static void transform(std::vector<T>& data);
};
```

#### Parameters

- `data`: Input signal vector (size must be a power of 2 or ≥ 2). The transform is applied in-place, modifying the input vector.

#### Description

Performs a single-level Haar wavelet decomposition on the input signal. The output contains:
- First half: Approximation coefficients (averages)
- Second half: Detail coefficients (differences)

Both are normalized by √2.

## Project Structure

```
WaveletEngine/
├── CMakeLists.txt          # Build configuration
├── include/
│   └── Wavelet.hpp         # Wavelet transform implementations
└── src/
    └── main.cpp            # Example usage
```

## How It Works

The Haar wavelet transform performs a multi-resolution analysis by:
1. Pairing consecutive signal values
2. Computing averages (approximation coefficients)
3. Computing differences (detail coefficients)
4. Normalizing by √2 for orthonormality

This decomposition is useful for:
- Signal compression
- Noise reduction
- Feature extraction
- Time-frequency analysis

## Performance Notes

- Transform complexity: O(n)
- In-place operation: Minimal memory overhead
- Requires input size ≥ 2

## Future Enhancements

Potential additions for future versions:
- Additional wavelets (Daubechies, Symlets, Coiflets)
- Multi-level decomposition
- Inverse transforms
- 2D wavelet support for image processing
- SIMD optimization

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

### MIT License Summary

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

## Contributing

Contributions are welcome! Please ensure:
- Code follows C++17 standards
- Templates are properly documented
- Examples are included for new features

## References

- Daubechies, I. (1992). *Ten Lectures on Wavelets*
- Mallat, S. (2008). *A Wavelet Tour of Signal Processing*
