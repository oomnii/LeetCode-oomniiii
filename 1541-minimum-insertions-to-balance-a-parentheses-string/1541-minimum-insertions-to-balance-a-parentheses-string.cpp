class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int oper = 0;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') cnt++;
            else{
                if(cnt>0){
                    if(i+1<n && s[i+1]==')'){
                        i++;
                        cnt--;
                    }
                    else{
                        oper++;
                        cnt--;
                    }
                }
                else{
                    oper++;
                    if(i+1<n && s[i+1]==')'){
                        i++;
                    }
                    else{
                        oper++;
                    }
                }
            }
        }
        if(cnt!=0) oper += (2*cnt);
        return oper;
    }
};