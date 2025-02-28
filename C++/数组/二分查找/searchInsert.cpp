#include <iostream>
#include <vector>
using namespace std;

// (https://leetcode.cn/problems/search-insert-position/)
class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int low = 0, high = nums.size() - 1;
            while ( low <= high ) {
                int mid = ( low + high ) / 2;
                if( nums[mid] == target ) {
                    return mid;   //能查找到则直接返回
                }
    
                if( nums[mid] < target ) {
                    low = mid + 1;
                }
    
                else {
                    high = mid -1;
                }
            }
    
            return low;  //不能查找到则返回 low
        }
    };


int main()
{
    Solution case1, case2;
    vector<int> nums = {1, 3, 5, 6};
    int target1 = 5, target2 = 7;
    
    cout<<"case1: "<<"target1 = "<< target1 << endl << case1.searchInsert(nums, target1)<< endl;
    cout<<"case2: "<<"target2 = "<< target2 << endl << case2.searchInsert(nums, target2)<< endl;
}