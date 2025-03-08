#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
        bool backspaceCompare(string s, string t) {
            int i = s.size() - 1, j = t.size() - 1;  // 从后往前遍历
            int skipS = 0, skipT = 0; // 记录各自的空格数
    
            // 从后往前开始统计s,t
            while(i >= 0 || j >= 0) {
                // 统计 s
                while(i >= 0) {
                    if(s[i] == '#') {
                        skipS++;
                        i--;  //回退
                    }
                    else if(skipS > 0) {
                        skipS--;
                        i--; //回退键生效
                    }
                    else {
                        break; //该字母为有效字母
                    }
                }
    
                // 统计 t
                while(j >= 0) {
                    if(t[j] == '#') {
                        skipT++;
                        j--;
                    }
                    else if(skipT > 0) {
                        skipT--;
                        j--;
                    }
                    else {
                        break;
                    }
                }
    
                // 此时是有效字母
                if(i >= 0 && j >= 0) {
                    if(s[i] != t[j]) {
                        return false;
                    }
                }
                else { //其中一个已经越界
                    if(i >= 0 || j >= 0) {
                        return false; 
                    }
                }
                i--;
                j--;
                // 继续遍历
            }
            // 所有都遍历完，且i,j同时为 -1 ，即 长度相同
            return true;
        }
    };

int main() {
    Solution case1,case2,case3;
    string s1_1 = "ab#c", s1_2 = "ad#c";
    string s2_1 = "ab##", s2_2 = "c#d#";
    string s3_1 = "a#c" , s3_2 = "b";

    if(case1.backspaceCompare(s1_1,s1_2)) {
        cout << "case1 is true!" << endl;
    }
    else {
        cout << "case1 is false!" <<endl;
    }
    
    if(case2.backspaceCompare(s2_1,s2_2)) {
        cout << "case2 is true!" << endl;
    }
    else {
        cout << "case2 is false!" <<endl;
    }

    if(case1.backspaceCompare(s3_1,s3_2)) {
        cout << "case3 is true!" << endl;
    }
    else {
        cout << "case3 is false!" <<endl;
    }
}