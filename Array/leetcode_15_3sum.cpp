#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<set>
// #include<map>

using namespace std;
//先排序，然后遍历
// vector<vector<int>> threeSum(vector<int>& nums) {
//      sort(nums.begin(), nums.end());
//      int len = (int)nums.size();
//      int l = 0, r = len - 1;
//      int mid = 0;
//      vector<vector<int>> res;
//      while(l <= r - 2) {
//         cout << "before" << " l: " << l << " r: " << r << " mid: " << mid << endl;
//         vector<int> tempRes;
//         int temp = nums[l] + nums[r];
//         mid = 0;
//         cout << temp << endl;
//         if (temp <= 0) {
//             mid = r - 1;
//             while (mid > l) {
//                 if (nums[mid] + temp == 0) {
//                     tempRes.push_back(nums[l]);
//                     tempRes.push_back(nums[mid]);
//                     tempRes.push_back(nums[r]);      
//                     res.push_back(tempRes);
//                     r--;
//                     mid = 0;
//                     for (int num : tempRes) {
//                         cout << num << " ";
//                     }
//                     cout << endl;
//                     break;
//                 }
//                 mid--;
//             }
//             if(nums[mid] < 0) {
//                 l++;
//                 mid = 0;
//             }
//             mid = 0;
//         } else {
//             mid = l + 1;
//             while (mid < r) {
//                 if (nums[mid] + temp == 0) {
//                     tempRes.push_back(nums[l]);
//                     tempRes.push_back(nums[mid]);
//                     tempRes.push_back(nums[r]);   
//                     res.push_back(tempRes);              
//                     res.push_back(tempRes);
//                     l++;
//                     mid = 0;
//                     for (int num : tempRes) {
//                         cout << num << " ";
//                     }
//                     cout << endl;
//                     break;
//                 }
//                 mid++;
//             }
//             if(nums[mid] >= 0) {
//                 r--;
//                 mid = 0;
//             }
//             mid = 0;
//         }
//         cout << "after" << " l: " << l << " r: " << r << " mid: " << mid << endl;
//      }
//      sort(res.begin(), res.end());
//      res.erase(unique(res.begin(), res.end()), res.end());
//      return res;
// }
//无法得到所有的三元组
// vector<vector<int>> threeSum_2(vector<int>& nums) {
//     sort(nums.begin(), nums.end());
//     int len = (int)nums.size();
//     int l = 0, r = len - 1;
//     vector<vector<int>> res;
//     while(l <= r - 2) {
//         int temp = nums[l] + nums[r];
//         int i = l + 1;
//         while(i < r) {
//             if(nums[i] + temp == 0) {
//                 vector<int> temp;
//                 temp.push_back(nums[l]);
//                 temp.push_back(nums[i]);
//                 temp.push_back(nums[r]);
//                 res.push_back(temp);
//                 break;
//             }
//             i++;
//         }
//         if((i - l) > (r - i)) {
//             l++;
//         } else {
//             r--;
//         }
//     }
//    sort(res.begin(), res.end());
//    res.erase(unique(res.begin(), res.end()), res.end());
//    return res;
// }

// vector<int> twoSum(vector<int>& nums, int begin, int target) {
//     vector<int> res(2, 0);
//     unordered_map<int,int> map;
//     for(int i = 0; i < (int)nums.size(); i++) {
//         if (i == begin) continue;
//         int temp = target - nums[i];
//         if (map.find(temp) != map.end()) {
//             res[0] = i;
//             res[1] = map.find(temp)->second;
//             return res;
//         } else {
//             map.insert(pair<int, int>(nums[i], i));
//         }
//     }
//     sort(res.begin(), res.end());
//     res.erase(unique(res.begin(), res.end()), res.end());
//     return res;
// }

// void two_sum(vector<int>& nums,int i,int target,vector<vector<int>> &result){
//     int j = (int)nums.size()-1;
//     int b = i-1;
//     while(i<j){
//         if(nums[i]+nums[j] == target){
//             result.push_back(vector<int>{nums[b],nums[i],nums[j]});
//             //处理重复的情况
//             i++;
//             j--;
//             while(i<j && nums[i] == nums[i-1]) i++;
//             while(i<j && nums[j+1] == nums[j]) j--;
//         }else{
//             if(nums[i]+nums[j] < target)
//                 i++;
//             else
//                 j--;
//         }
//     }
//     return;
// }
// vector<vector<int>> threeSum(vector<int>& nums) {
//     // set<vector<int>> result;
//     vector<vector<int>> result2;
//     sort(nums.begin(),nums.end());
//     for(int i=0;i<(int)nums.size();i++)
//         if(i>0&&nums[i-1]== nums[i])
//             continue;
//         else
//             two_sum(nums,i+1,-nums[i],result2);

//     return result2;
// }

void two_sum2(vector<int>& nums, int beg, int target, vector<vector<int>>& res) {
    int j = (int)nums.size() - 1;
    int i = beg - 1;
    while (beg < j) {
        if(nums[beg] + nums[j] == target) {
            res.push_back(vector<int>{nums[i], nums[beg], nums[j]});
            beg++;
            j--;
            while(beg < j && nums[beg] == nums[beg + 1]) {
                beg++;
            }
            while(beg < j && nums[j] == nums[j - 1]) {
                j--;
            }
        } else {
            if(nums[beg] + nums[j] < target) {
                beg++;
            } else {
                j--;
            }
        }
    }
}

vector<vector<int>> threesum2(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < (int)nums.size(); i++) {
        if(i > 0 && nums[i - 1] == nums[i]) {
            continue;
        } else {
            two_sum2(nums, i + 1, -nums[i], res);
        }
    }
    return res;
}

// vector<vector<int>> threeSum_2(vector<int>& nums) {
//     sort(nums.begin(), nums.end());
//     int len = (int) nums.size();
//     int target = 0;
//     vector<vector<int>> res;
//     vector<int> temp(3,0);
//     while(target < len) {
//        vector<int> temp2 = twoSum(nums, target + 1, -nums[target]);
//        if(temp2[0] != temp2[1]) {
//            temp[0] = nums[target];
//            temp[1] = nums[temp2[0]];
//            temp[2] = nums[temp2[1]];
//            res.push_back(temp);
//        }
//        target++; 
//     }
//     return res;
// }

int main() {
    // vector<int> nums = {-2,0,1,1,2};
    // vector<int> nums = {-4, -1, -1, 0, 1, 2};
    vector<int> nums = {-1,0,1,2,-1,-4,-2,-3,3,0,4};
    // vector<int> nums = {-4, -3, -2, -1, -1, 0, 0, 1, 2, 3, 4};
    // vector<vector<int>> test = {{0, 0, 0}, {0, 0, 0}};
    // sort(test.begin(), test.end());
    // test.erase(unique(test.begin(), test.end()), test.end());
    // for(vector<int> temp: test) {
    //     for (int i : temp) {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }
    vector<vector<int>> res;
    res = threesum2(nums);
    for(vector<int> temp: res) {
        for (int i : temp) {
            cout << i << " ";
        }
        cout << endl;
    }
}