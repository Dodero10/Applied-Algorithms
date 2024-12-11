## https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/description/?envType=daily-question&envId=2024-12-11

class Solution(object):
    def maximumBeauty(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums.sort()
        max_beauty = 0

        for i, num in enumerate(nums):
            upper_bound = self._find_upper_bound(nums, num + 2*k)
            max_beauty = max(max_beauty, upper_bound - i + 1)
        return max_beauty

    def _find_upper_bound(self, arr: list[int], val: int) -> int:
        low, high, rs = 0, len(arr) - 1, 0

        while low <= high:
            mid = low + (high-low)//2

            if arr[mid] <= val:
                rs = mid
                low = mid + 1
            else:
                high = mid -1
        return rs

        