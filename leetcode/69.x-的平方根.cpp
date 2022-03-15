/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 *
 * https://leetcode-cn.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (38.88%)
 * Likes:    920
 * Dislikes: 0
 * Total Accepted:    477K
 * Total Submissions: 1.2M
 * Testcase Example:  '4'
 *
 * 给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
 * 
 * 由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
 * 
 * 注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：x = 4
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：x = 8
 * 输出：2
 * 解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= x <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        if(x == 1) return 1;
        
        int left = 1;
        int right = x/2;
        while (left < right)
        {
            //right + 1 指的是，对于去mid的时候，向上多取一位，
            //避免陷入只有两个数时的死循环
            int mid = left + (right  + 1 -left) /2 ;
            //避免乘法溢出，改用作除法，
            if(mid > x / mid) right = mid -1;
            else{
                left = mid;
            }

            // int mid = left + (right + 1 -left) /2 ;
            // //避免乘法溢出，改用作除法，
            // if(mid > x / mid) right = mid;
            // else{
            //     left = mid + 1;
            // }
        }
        //返回的是最大的 整数的平方 严格小于 输入整数 的最大整数
        return left;
    }
};
// @lc code=end

