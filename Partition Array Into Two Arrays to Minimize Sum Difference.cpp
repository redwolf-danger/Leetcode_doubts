//dp problem with dp array

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int negative_sum = 0;       
        int positive_sum = 0; 
        for (int i = 0; i<n ; i++){
            if(nums[i]>=0){
                positive_sum += nums[i];
            }
            else{
                negative_sum += nums[i];
            };
        };
        int sum = positive_sum + negative_sum;
        
        int vsize = positive_sum - negative_sum + 1;
//         cout<<"positive_sum is "<<positive_sum<<endl;
//         cout<<"negative_sum is "<<negative_sum<<endl;
//         cout<<"vsiz is "<<vsize<<endl;
        
        
        vector<int> dpwrite(vsize,-1);
        int zero_pt = abs(negative_sum);
        dpwrite[zero_pt] = 0;
        
        // cout<<"reached here 1";
        dpwrite[nums[0]+zero_pt] = 1;
        vector<int> dpread(vsize,-1);
        
        // cout<<"reached here 2";
        dpread[zero_pt] = 0;
        dpread[zero_pt + nums[0]] = 1;
        int mini =  INT_MAX;
        
        
        // cout<<"reached here";
        for(int j = 1; j<n; j++){
            for(int k = 0 ; k<vsize; k++){
            if(dpread[k]>=0 && (k+nums[j]<vsize)){
                dpwrite[k+nums[j]] = dpread[k]+1;
                if(dpwrite[k+nums[j]] == n/2){
                    int possible_sum = k+nums[j] - zero_pt; 
                    mini = mini<abs(sum-2*possible_sum) ? mini :abs(sum-                                 2*possible_sum);
                }
            }
            };
             dpread = dpwrite;   
        };
               return mini;   
        };
};
