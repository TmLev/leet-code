#include <algorithm>
#include <vector>

int maxArea(std::vector<int>& height) {
    auto result = 0;

    auto left = 0;
    auto right = static_cast<int>(height.size()) - 1;

    while (left < right) {
        auto area = std::min(height[left], height[right]) * (right - left);
        result = std::max(result, area);

        if (height[left] < height[right]) {
            ++left;
        } else {
            --right;
        }
    }

    return result;
}

