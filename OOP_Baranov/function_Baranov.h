#pragma once
#include <iostream>
#include <string>

template <typename T>
T readNumber(T min, T max) {
    T x;
    while (true) {
        if (!(std::wcin >> x)) {
            std::wcin.clear();
            std::wcin.ignore(10000, L'\n');
            std::wcout << L"Ошибка! Введите число от " << min << L" до " << max << L"." << std::endl;
            continue;
        }
        std::wcin.ignore(10000, L'\n');
        if (x < min || x > max) {
            std::wcout << L"Число вне диапазона! Попробуйте снова." << std::endl;
            continue;
        }
        return x;
    }
}
