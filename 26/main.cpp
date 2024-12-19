#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // Дек для хранения индексов элементов окна
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            // Удаляем элементы, которые вышли за пределы окна
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // Удаляем элементы, которые меньше текущего
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Добавляем текущий элемент в дек
            dq.push_back(i);

            // Добавляем максимум окна в результат (начиная с момента, когда окно заполнено)
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};

int main() {
    Solution solution;

    // Ввод данных
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    // Решение задачи
    vector<int> result = solution.maxSlidingWindow(nums, k);

    // Вывод результата
    cout << "Max sliding window: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

