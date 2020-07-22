#include <algorithm>
#include <utility>
#include <vector>

double findMedianSortedArrays(const std::vector<int>& nums1, const std::vector<int>& nums2) {
    auto [first, second] = [&]() -> std::tuple<const std::vector<int>&, const std::vector<int>&> {
        if (nums1.size() > nums2.size()) {
            return {nums2, nums1};
        } else {
            return {nums1, nums2};
        }
    }();
    
    auto median = 0.0;
    
    auto len1 = first.size();
    auto len2 = second.size();
    
    auto min_index = 0;
    auto max_index = len1;
    
    auto left  = 0;
    auto right = 0;
    
    while (min_index <= max_index) {
        left  = (min_index + max_index) / 2;
        right = (len1 + len2 + 1) / 2 - left;
        
        if (left < len1 && right > 0 && second[right - 1] > first[left]) {
            min_index = left + 1;
            continue;
        }            
        
        if (left > 0 && right < len2 && second[right] < first[left - 1]) {
            max_index = left - 1;
            continue;
        }

        if (left == 0) {
            median = second[right - 1];
            break;
        }

        if (right == 0) {
            median = first[left - 1];
            break;
        }

        median = std::max(first[left - 1], second[right - 1]);
        break;
    }
    
    if ((len1 + len2) % 2 == 1) {
        return median;
    }

    if (left == len1) {
        return (median + second[right]) / 2.0;
    }

    if (right == len2) {
        return (median + first[left]) / 2.0;
    }

    return (median + std::min(first[left], second[right])) / 2.0;
}

