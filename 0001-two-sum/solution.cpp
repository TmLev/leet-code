#include <unordered_map>
#include <vector>

auto twoSum(const std::vector<int>& nums, int target) -> std::vector<int> {
    std::unordered_map<int, int> met;

    for (int i = 0; i < nums.size(); ++i) {
        auto diff = target - nums[i];

        if (met.find(diff) != met.end()) {
            return {met[diff], i};
        }

        met[nums[i]] = i;
    }

    throw std::runtime_error("No solution found");
}

