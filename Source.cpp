#include <vector>;
#include <stdio.h>;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums.at(i) == nums.at(i + 1))
            {
                nums.erase(nums.begin() + i + 1);
            }
        }
        k = nums.size();
        return k;
    }
};

int main()
{
    int nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]; // Input array
    int expectedNums = [0, 1, 2, 3, 4]; // The expected answer with correct length

    int k = removeDuplicates(nums); // Calls your implementation

    assert k == expectedNums.length;
    for (int i = 0; i < k; i++) {
        assert nums[i] == expectedNums[i];
    }

    return 0;
}