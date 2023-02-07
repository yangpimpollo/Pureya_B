#pragma once
#ifndef MATH_H_INCLUDED
#define MATH_H_INCLUDED

#include <SFML/Graphics.hpp>

class math {
    public:
        inline sf::Vector2f normalize(sf::Vector2f vector);
        inline void swap(std::pair <float, int>& arg0, std::pair <float, int>& arg1);
        inline int partition(std::vector<std::pair <float, int>>& array, int init, int end);
        inline void quickSort(std::vector<std::pair <float, short>>& array, int init, int end);
};

inline sf::Vector2f normalize(sf::Vector2f vector) {

    float modulus = std::sqrt((vector.x * vector.x) + (vector.y * vector.y));

    if (!modulus == 0) {
        float vecX = vector.x / modulus;
        float vecY = vector.y / modulus;
        return sf::Vector2f(vecX, vecY);
    }
    else {
        return sf::Vector2f(0.f, 0.f);
    }
}

inline void swap(std::pair <float, int>& arg0, std::pair <float, int>& arg1) {
    std::pair <float, short> aux = arg0;
    arg0 = arg1;
    arg1 = aux;
}

inline int partition(std::vector<std::pair <float, int>>& array, int init, int end) {
    int pivot = array[init].first;
    int i = init + 1;
    for (int j = i; j <= end; j++) {
        if (array[j].first < pivot) {
            swap(array[i], array[j]);
            i++;
        }
    }
    swap(array[init], array[i - 1]);
    return i - 1;
}

inline void quickSort(std::vector<std::pair <float, int>>& array, int init, int end) {
    if (init < end) {
        int pivot = partition(array, init, end);
        quickSort(array, init, pivot - 1);
        quickSort(array, pivot + 1, end);
    }
}


#endif

