/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 *
 * https://leetcode-cn.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (45.93%)
 * Likes:    1405
 * Dislikes: 0
 * Total Accepted:    696.9K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 * 
 * 请必须使用时间复杂度为 O(log n) 的算法。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [1,3,5,6], target = 5
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [1,3,5,6], target = 2
 * 输出: 1
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: nums = [1,3,5,6], target = 7
 * 输出: 4
 * 
 * 
 * 示例 4:
 * 
 * 
 * 输入: nums = [1,3,5,6], target = 0
 * 输出: 0
 * 
 * 
 * 示例 5:
 * 
 * 
 * 输入: nums = [1], target = 0
 * 输出: 0
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 
 * -10^4 
 * nums 为无重复元素的升序排列数组
 * -10^4 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // //暴力解法：
        // for (int i = 0; i< nums.size(); i++)
        // {
        //     if(nums[i] >= target){
        //         return i;
        //     }
        // }
        // return nums.size();
        // 二分查找法
        int left, right, mid;
        left = 0;
        right = nums.size() -1;
        while(left <= right){
            mid =left +  (( right - left)/2);
            // mid = left + ((right - left) >> 1); //右移运算符
            if(nums[mid] > target) right = mid -1;
            else if(nums[mid] < target) left = mid+1;
            else return mid;
        }
        return right + 1;

        // int n = nums.size();
        // int left = 0;
        // int right = n; // 定义target在左闭右开的区间里，[left, right)  target
        // while (left < right) { // 因为left == right的时候，在[left, right)是无效的空间
            // int middle = left + ((right - left) >> 1);
        //     if (nums[middle] > target) {
        //         right = middle; // target 在左区间，在[left, middle)中
        //     } else if (nums[middle] < target) {
        //         left = middle + 1; // target 在右区间，在 [middle+1, right)中
        //     } else { // nums[middle] == target
        //         return middle; // 数组中找到目标值的情况，直接返回下标
        //     }
        // }
        // // 分别处理如下四种情况
        // // 目标值在数组所有元素之前 [0,0)
        // // 目标值等于数组中某一个元素 return middle
        // // 目标值插入数组中的位置 [left, right) ，return right 即可
        // // 目标值在数组所有元素之后的情况 [left, right)，return right 即可
        // return right;


    }
};
// @lc code=end

