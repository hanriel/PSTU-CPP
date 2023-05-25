#include <iostream>

int max(int k, ...);

int main() {
    std::cout << "Max is: " << max(5, 20, 4, 3, 25, 11) << std::endl;
    std::cout << "Max is: " << max(10, 20, 10, 3, 10, 11, 3, 4, 5, 6, 7) << std::endl;
    std::cout << "Max is: " << max(12, 20, 10, 3, 10, 11, 44, 4, 5, 6, 7, 44, 10) << std::endl;
    return 0;
}

int max(int k, ...) {
    int *p = &k;
    int max = *(p + 2);
    for (; k != 0; k--) {
        p += 2;
        if (*p > max) max = *p;
    }

    return max;
}