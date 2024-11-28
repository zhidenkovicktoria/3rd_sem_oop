#include "binary_representation.h"

std::string intToBinaryString(int n) {
    std::string binaryString(32, '0'); // Создаем строку из 32 нулей
    for (int i = 0; i < 32; ++i) {
        if (n & (1 << i)) {
            binaryString[31 - i] = '1';
        }
    }
    return binaryString;
}
