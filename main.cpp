#include <iostream>
#include "DynamicArray.h"

int main() {
    std::cout << "=== Тест 1: std::invalid_argument ===" << std::endl;
    try {
        DynamicArray arr(3);
        arr.set(0, 150); //исключение
        std::cout << "Эта строка не напечатается" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Поймано исключение: " << e.what() << std::endl;
    }

    std::cout << "\n=== Тест 2: std::out_of_range ===" << std::endl;
    try {
        DynamicArray arr(3);
        arr.get(10); // Индекс 10 не существует в массиве размера 3
        std::cout << "Эта строка не напечатается" << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Поймано исключение: " << e.what() << std::endl;
    }

    std::cout << "\n=== Тест 3: std::bad_alloc ===" << std::endl;
    try {
        std::cout << "Попытка создать массив огромного размера..." << std::endl;
        // выброс std::bad_alloc
        DynamicArray hugeArray(2000000000); 
        std::cout << "Эта строка не напечатается" << std::endl;
    } catch (const std::bad_alloc& e) {
        std::cout << "Поймано исключение: нехватка памяти (bad_alloc)" << std::endl;
    }

    std::cout << "\n=== Все тесты пройдены успешно! ===" << std::endl;
    return 0;
}