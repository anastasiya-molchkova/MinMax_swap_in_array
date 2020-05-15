/* Целочисленный массив заполняется 9-тью рандомными элементами. Поменять
местами максимальный и минимальный элементы массива. */

#include <iostream>
#include <array>
#include <cstdlib>   // для функций выбора случайного числа srand() и rand()
#include <ctime>     // чтобы в randomize опираться на время запуска программы
#include <algorithm> // для подключения алгоритмов STL: swap, min_element и max_element

int main()
{
    setlocale(LC_CTYPE, "rus");

    //аналог randomize с привязкой ко времени запуска:
    srand(static_cast<unsigned int>(time(0)));

    const unsigned size_of_array{ 9 };

    std::cout << "Генерируем массив из случайных чисел до 100: \n";
    std::array<int, size_of_array> random_array{};
    for (unsigned i = 0; i < size_of_array; i++)
    {
        random_array[i] = rand()%100;
        std::cout << random_array[i] << " ";
    }

    std::cout << "\nМеняем минимум и максимум местами: \n";
    // т.к. swap работает со значениями, разыменовываем итераторы min_element и max_element:
    std::swap(*min_element(random_array.begin(), random_array.end()), *max_element(random_array.begin(), random_array.end()));
    for (unsigned i = 0; i < size_of_array; i++)
        std::cout << random_array[i] << " ";
    std::cout << std::endl;

    return 0;
}