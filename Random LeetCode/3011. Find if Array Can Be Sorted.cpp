// class Solution {
// public:
//     int setBits(int n){
//         int cnt=0;
//         while(n!=0){
//             if(n&1){
//                 cnt++;
//             }
//             n=n>>1;
//         }
//         return cnt;

//     }
//     bool canSortArray(vector<int>& nums) {
//         for(int i=0;i<nums.size();i++){
//             for(int j=0;j<nums.size()-1;j++){
//                 if(nums[j]>nums[j+1] && setBits(nums[j])==setBits(nums[j+1])){
//                         // swap(nums[j]>nums[j+1]);
//                         int tmp=nums[j];
//                         nums[j]=nums[j+1];
//                         nums[j+1]=tmp;
//                 }
//             }
//         }

//         for(int i=0;i<nums.size()-1;i++){
//             if(nums[i]>nums[i+1]) return false;
//         }
//         return true;
//     }
// };




class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size() - i - 1; j++) {
                int setCount = countSetBit(nums[j]);
                int setCount1 = countSetBit(nums[j + 1]);
                if (setCount == setCount1 && nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
        return isSorted(nums);
    }

private:
    int countSetBit(int n) {
        int count = 0;
        while (n > 0) {
            count++;
            n = n & (n - 1);
        }
        return count;
    }

    bool isSorted(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1])
                return false;
        }
        return true;
    }
};