class Solution {
public:
    static bool cmp(int a,int b){
        return abs(a)<abs(b);
    } 
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);

        int s=0;
        int n=nums.size();
        int e=n-1;
        long long sum=0;
        bool add=true;
        while(s<=e){
            if (add){
                sum+=nums[e]*nums[e];
                e--;
            }
            else{
                sum-=nums[s]*nums[s];
                s++;
            }
            add=!add;
        }
        return sum;
    }
};
