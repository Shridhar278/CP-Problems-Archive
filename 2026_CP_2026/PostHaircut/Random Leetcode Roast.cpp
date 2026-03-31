#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int prev=nums[0];
        vector<int> arr={nums[0]};
        int block=0;
        int ans=0;
        for (int i=1;i<nums.size();i++) {
            if (nums[i]>prev+1) {
                if (block==1) {
                    // dp
                    vector<int>dp((int)arr.size(), 0);
                    dp[0]=arr[0];
                    if (arr.size()>1) {
                        dp[1]=max(arr[0], arr[1]);
                    }
                    for (int i=2;i<(int)arr.size();i++) {
                        dp[i]=dp[i-2]+arr[i];
                    }
                    ans+=dp[(int)arr.size()-1];
                    arr.clear();
                    arr.push_back(nums[i]);
                    prev=nums[i];
                    block=0;
                } else {
                    ans+=arr.back();
                    arr.back()=nums[i];
                    prev=nums[i];
                }
            } else if (nums[i]==prev+1) {
                block=1;
                arr.push_back(nums[i]);
                prev=nums[i];
            } else {
                arr.back()+=prev;
            }
        }
        if (block) {
            vector<int>dp((int)arr.size(), 0);
            dp[0]=arr[0];
            if (arr.size()>1) {
                dp[1]=max(arr[0], arr[1]);
            }
            for (int i=2;i<(int)arr.size();i++) {
                dp[i]=dp[i-2]+arr[i];
            }
            ans+=dp[(int)arr.size()-1];
        } else {
            ans+=arr.back();
        }
        return ans;
    }
};