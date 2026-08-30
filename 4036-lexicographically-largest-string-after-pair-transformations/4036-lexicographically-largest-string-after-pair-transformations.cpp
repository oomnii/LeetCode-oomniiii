class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        int n = nums.size();
        vector<string> result;
        for(int i=0;i<n;i++){
            int num = nums[i];
            char curr = 'a';
            string temp = "";
            while(num){
                if(num%2==1) temp = string(1,curr)+temp;
                num /= 2;
                curr++;
                if(curr=='z'){
                    while(num--){
                        temp = string(1,curr)+temp; 
                    }
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};