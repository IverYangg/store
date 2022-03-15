/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (42.26%)
 * Likes:    1518
 * Dislikes: 0
 * Total Accepted:    461.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 * 
 * 如果数组中不存在目标值 target，返回 [-1, -1]。
 * 
 * 进阶：
 * 
 * 
 * 你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [5,7,7,8,8,10], target = 8
 * 输出：[3,4]
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [5,7,7,8,8,10], target = 6
 * 输出：[-1,-1]
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [], target = 0
 * 输出：[-1,-1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^9 
 * nums 是一个非递减数组
 * -10^9 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    /*
    寻找target在数组里的左右边界，有如下三种情况：
    情况一：target 在数组范围的右边或者左边，例如数组{3, 4, 5}，target为2或者数组{3, 4, 5},target为6，此时应该返回{-1, -1}
    情况二：target 在数组范围中，且数组中不存在target，例如数组{3,6,7},target为5，此时应该返回{-1, -1}
    情况三：target 在数组范围中，且数组中存在target，例如数组{3,6,7},target为6，此时应该返回{1, 1}
    */
    int leftBorder = getLeftBorder(nums, target);
    int rightBorder = getRightBorder(nums, target);
    //情况一
    if(leftBorder == -2 || rightBorder == -2) return {-1, -1};

    //情况三
    if((rightBorder - leftBorder) > 1) return {leftBorder + 1, rightBorder - 1};
    //情况二
    return {-1,-1};



    }
private:
    //寻找右边界，不包括target
    //如果rightBorder没有被赋值（（即target在数组范围的左边，例如数组[3,3]，target为2），为了处理情况一）
    int getRightBorder(vector<int> nums, int target){
        int left = 0;
        int right = nums.size() -1;
        int rightBorder = -2;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] > target) right = mid - 1;
            else{ 
                //nums[mid]<=target 条件就是这样，小于和等于target左边界都要往后挪
                //找右边界，就从左边不断逼近
                // 当nums[middle] == target的时候，更新left，这样才能得到target的右边界
                left = mid+1;
                rightBorder = left;       //寻找右边界，
            }
        }
        return rightBorder;
    }

    int getLeftBorder(vector<int> nums, int target){
        int left = 0;
        int right = nums.size() -1;
        int leftBorder = -2;
        while(left <= right){
            int mid = left +(right - left)/2;
            if(nums[mid] >= target) {
                // 当nums[mid] > = target, 右边界就要一直往前挪，
                //找左边界，就要从右往左不断逼近，就算找到了值，也是在该if判断语句内，一直往前移动
                right = mid - 1;
                leftBorder = right;
            }
            else{
                //仅仅是nums[mid]<target的情况
                left = mid+1;     
            }

        }
        return leftBorder;

}






};
// @lc code=end

