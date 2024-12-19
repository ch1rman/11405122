#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Считаем частоты элементов массива
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }

        // Создаём очередь с приоритетом (max-heap)
        priority_queue<pair<int, int>> maxHeap;
        for (auto& pair : freqMap) {
            maxHeap.push({pair.second, pair.first});
        }

        // Извлекаем k самых частых элементов
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};

int main() {
    Solution solution;

    // Ввод массива и параметра k
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    // Вызываем функцию topKFrequent
    vector<int> result = solution.topKFrequent(nums, k);

    // Вывод результата
    cout << "The " << k << " most frequent elements are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}


