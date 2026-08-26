class Solution {
public:
    string to_binary(int num){
        string temp = "";
        while(num){
            temp += (num%2+'0');
            num /= 2;
        }
        reverse(temp.begin(), temp.end());
        int sz = temp.size();
        int diff = 8-sz;
        while(diff--){
            temp = "0"+temp;
        } 
        return temp;
    }

    bool check(string s1, string s2){
        reverse(s2.begin(),s2.end());
        for(int i=0;i<8;i++){
            if(s1[i]!=s2[i]) return false;
        }
        return true;
    }

    bool isPalindromic(string s) {
        int n = s.length();
        int i=0;
        int j=n-1;
        while(i<=j){
            string temp1 = to_binary(int(s[i]));
            string temp2 = to_binary(int(s[j]));
            if(check(temp1,temp2)){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
};