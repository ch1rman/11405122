#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastIndex;

       
        for (int i = 0; i < s.size(); ++i) {
            lastIndex[s[i]] = i;
        }

        vector<int> partitions;
        int start = 0, end = 0;

        
        for (int i = 0; i < s.size(); ++i) {
            end = max(end, lastIndex[s[i]]);
            if (i == end) {
                partitions.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return partitions;
    }
};

int main() {
    Solution solution;

 
    string s = "ababcbacadefegdehijhklij";

   
    vector<int> result = solution.partitionLabels(s);

    
    cout << "Partition sizes: ";
    for (int size : result) {
        cout << size << " ";
    }
    cout << endl;

    return 0;
}
