class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> digits;
        string validRange = "123456789";
        int sz = to_string(low).size();
        for(int i=0;i<9;i++){
            for(int j=i+sz-1;j<9;j++){
                string temp = validRange.substr(i,j-i+1);
                int num = stoi(temp);
                if(num>=low && num<=high) digits.push_back(num); 
            }
        }
        sort(digits.begin(),digits.end());
        return digits;
    }
};