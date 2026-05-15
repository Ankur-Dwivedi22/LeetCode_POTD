class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (nums[lo] <= nums[mid] && nums[mid] <= nums[hi])
            {
                hi = mid - 1;
            }
            else if (nums[mid] > nums[hi])
            {
                lo = mid + 1;
            }
            else if (nums[lo] > nums[mid])
            {
                hi = mid;
            }
        }

        return nums[lo];
    }
};