class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }
        
vector<vector<int>> freqCount(nums.size() + 1);
 for (auto& [num, count] : freq) {
  freqCount[count].push_back(num);
    }
        
vector<int> result;
for (int i = nums.size(); i >= 1 && result.size() < k; i--) {
      for (int num : freqCount[i]) {
             result.push_back(num);
        if (result.size() == k) break;
     }
 }
        
     return result;
    }
};