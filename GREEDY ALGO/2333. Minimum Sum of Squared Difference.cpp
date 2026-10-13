class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int>countDiff(1e5+1,0);
        int n=nums1.size();
        for(int i=0;i<n;i++){
            int diff=abs(nums1[i]-nums2[i]);
            countDiff[diff]++;
        }

        int k=k1+k2;
        for(int i=1e5;i>0 && k>0 ;i--){
            int countops=min(countDiff[i],k);
            countDiff[i]-=countops;
            countDiff[i-1]+=countops;
            k-=countops;
        }
        long long ans=0;
        for(long long i=1e5;i>0;i--){
            ans+=countDiff[i]*i*i;
        }
        return ans;
    }
};
