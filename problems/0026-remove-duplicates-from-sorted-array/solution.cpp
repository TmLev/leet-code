#include <algorithm>
#include <vector>

int removeDuplicates(std::vector<int>& nums) {
    nums.erase(
        std::unique(nums.begin(), nums.end()),
        nums.end()
    );
    return nums.size();
}

