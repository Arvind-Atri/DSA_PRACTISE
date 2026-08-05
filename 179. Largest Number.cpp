#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



bool compare(int a, int b) {
    string sa = to_string(a);
    string sb = to_string(b);

    cout<<"SA"<<sa<<endl;
    cout<<"SB"<<sb<<endl;

    cout<<"SA+SB"<<sa+sb<<endl;
    cout<<"SB+SA"<<sb+sa<<endl;

    // Custom comparison to check which concatenation is larger
    if((sa + sb )> (sb + sa)){
        return true;
    }
    return false;
}


    string largestNumber(vector<int>& nums) {
        // Sort using the custom comparator
        sort(nums.begin(), nums.end(), compare);

        // If the largest number after sorting is '0', the result is "0"
        if (nums[0] == 0) {
            return "0";
        }

        cout<<"AFTER"<<endl;
        for(auto num:nums){
            cout<<num<<"-";
        }
        cout<<endl;

        string ans = "";
        for (int num : nums) {
            ans += to_string(num);
        }

        return ans;
    }



int main(){

    vector<int>nums={10,2,5,20};
    
    string ans=largestNumber(nums);
    cout<<ans;
}