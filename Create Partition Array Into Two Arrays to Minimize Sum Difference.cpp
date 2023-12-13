//  This code is similar to the next just that i tried to use an unorderd map to remove TLE//

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int negative_sum = 0;       
        int positive_sum = 0; 
        int sum = 0;
        for (int i = 0; i<n ; i++){
            // /*****/ if(nums[i]>=0){
                // /*****/ positive_sum += nums[i];
            // /*****/  }
            // /*****/  else{
                // /*****/ negative_sum += nums[i];
            // /*****/  };
            sum += nums[i];
            
        };
        // /*****/  int sum = positive_sum + negative_sum;
        
       // /*****/  int vsize = positive_sum - negative_sum + 1;
//         cout<<"positive_sum is "<<positive_sum<<endl;
//         cout<<"negative_sum is "<<negative_sum<<endl;
//         cout<<"vsiz is "<<vsize<<endl;
        
        
        // /*****/ vector<int> dpwrite(vsize,-1);
        unordered_map <int,int> mapwrite;  // /*****/
       // /*****/  int zero_pt = abs(negative_sum);
        // /*****/ dpwrite[zero_pt] = 0;
        mapwrite[0] = 1; // /*****/
        
        // cout<<"reached here 1";
        // /*****/ dpwrite[nums[0]+zero_pt] = 1;
        mapwrite[nums[0]] = 2; // /*****/
        // vector<int> dpread(vsize,-1);
        unordered_map <int,int> mapread;  // /*****/
        
        // cout<<"reached here 2";
        // /*****/ dpread[zero_pt] = 0;
        // /*****/ dpread[zero_pt + nums[0]] = 1;
        mapread[nums[0]] = 2; // /*****/
        mapread[0] = 1;  // /*****/
        int mini =  INT_MAX;
        
        
        // cout<<"reached here";
        for(int j = 1; j<n; j++){
            // /*****/ for(int k = 0 ; k<vsize; k++){
            for( auto k = mapread.begin(); k != mapread.end(); k++){ // /*****/
            // /*****/ if(dpread[k]>=0 && (k+nums[j]<vsize)){
                if(k->second>=1){  // /*****/
                
                // /*****/ dpwrite[k+nums[j]] = dpread[k]+1;
                    mapwrite[k->first + nums[j]] = mapread[k->first] + 1; // /*****/
                    
                // /*****/ if(dpwrite[k+nums[j]] == n/2){
                    if(mapwrite[k->first + nums[j]] == n/2 + 1){  // /*****/
                    // /*****/ int possible_sum = k+nums[j] - zero_pt; 
                        int possible_sum = k->first + nums[j];
                        mini = mini<abs(sum-2*possible_sum) ? mini :abs(sum-2*possible_sum);
                }
            }
            };
             // /*****/ dpread = dpwrite; 
            mapread = mapwrite;  
        };
               return mini;   
        };
};
       /*
        test CASES ARE:
        [3,9,7,3]
        [-36,36]
        [2,-1,0,4,-2,-9]
        */
