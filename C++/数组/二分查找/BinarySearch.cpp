#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.cn/problems/binary-search/
class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int low = 0, high = nums.size() - 1;
            while(low <= high)
            {
                int mid = (low + high) / 2;
                if(nums[mid] == target){
                    return mid;
                }
    
                if(nums[mid] < target ) {
                    low = mid + 1;
                }
    
                else {
                    high = mid - 1;
                }
            }
    
            return -1;
        }
    };

int main()
{
    Solution case1,case2;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target1 = 9, target2 = 2;
    cout<<" case1: "<< "target1 = "<< target1 << endl << case1.search(nums, target1)<< endl;
    cout<<" case2: "<< "target2 = "<< target2 << endl << case2.search(nums, target2)<< endl;

    return 0;
}