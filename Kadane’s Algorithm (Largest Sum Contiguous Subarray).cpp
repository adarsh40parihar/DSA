int maxSubArray(vector<int>& nums) {
    int maxsum=nums[0], sum=0;                                //If we want atleast one element as a answer from the all negative array(in sort return minimum
    //for minimum sub array sum is zero use maxsum=0;         // negative element)
    for(int i=0;i<nums.size();i++){                
        sum+=nums[i];
        maxsum=max(maxsum,sum);
        if(sum<0) sum=0;
    }
        return maxsum;
}

