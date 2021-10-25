#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_map>

using namespace std;

// vector<int> twoSum(vector<int>& nums, int target) {
//     vector<int> res(2, 0);

//     for (int i = 0; i <(int) nums.size(); i++) {
//         if (find(nums.begin() + i,nums.end(),target - nums[i]) != nums.end()) {
//             res[0] = i;
//             res[1] = *find(nums.begin() + i, nums.end(), target - nums[i]);
//         }
//     }
//     return res;
// }

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res(2 ,0);
    map<int, int> temp;
    for (int i = 0; i < (int)nums.size(); i++) {
        temp.insert(pair<int, int>(nums[i], i));
    }
    for (int i = 0; i < (int)nums.size(); i++)
    {
        if (temp.find(target - nums[i]) != temp.end())
        {
            res[0] = i;
            res[1] = temp.find(target - nums[i])->second;
            break;
        }
    }
    return res;
}

vector<int> twoSum_2(vector<int>& nums, int target) {
    vector<int> sol = {2, 0};
    unordered_map <int, int> m;
    for (int i = 0; i < (int)nums.size(); i++) {
    //calculate the desired missing number
        int complement = target - nums[i];
        //if we have the missing number already in the map return the solution
        if (m.find(complement) != m.end()) {
            sol[0] = m[complement];
            sol[1] = i;
            return sol;
        }
        else {
        //add each number that is not a complement in the map
            m.emplace(pair<int, int>(nums[i], i));
        }
    }
    //this will never be reached
    return sol;
}

vector<int> twoSum_3(vector<int>& nums, int target) {
    vector<int> res(2, 0);
    unordered_map<int,int> map;
    for(int i = 0; i < (int)nums.size(); i++) {
        int temp = target - nums[i];
        if (map.find(temp) != map.end()) {
            res[0] = i;
            res[1] = map.find(temp)->second;
            return res;
        } else {
            map.insert(pair<int, int>(nums[i], i));
        }
    }
    return res;
}

int main() {
    vector<int> nums = {3, 2, 4};
    vector<int> res = twoSum_3(nums, 6);
    cout << res[0] << res[1];    
}
