#include <iostream>
#include <vector>

bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) {
        return false; // Проверка на пустую матрицу
    }

    int m = matrix.size();      // Количество строк
    int n = matrix[0].size();   // Количество столбцов
    int left = 0, right = m * n - 1; // Начальные границы для бинарного поиска

    while (left <= right) {
        int mid = left + (right - left) / 2; // Находим середину
        int mid_value = matrix[mid / n][mid % n]; // Преобразуем индекс mid в координаты матрицы

        if (mid_value == target) {
            return true; // Найдено значение
        } else if (mid_value < target) {
            left = mid + 1; // Ищем в правой части
        } else {
            right = mid - 1; // Ищем в левой части
        }
    }

    return false; // Значение не найдено
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    
    int target1 = 3;
    std::cout << "Input: target = " << target1 << ", Output: " << (searchMatrix(matrix, target1) ? "true" : "false") << std::endl;

    int target2 = 13;
    std::cout << "Input: target = " << target2 << ", Output: " << (searchMatrix(matrix, target2) ? "true" : "false") << std::endl;

    return 0;
}
