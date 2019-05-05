class Solution {
public:
    bool isValid(string s) {
        string left = "([{";
        string right = ")]}";
        stack<char> stk;

        for(auto c : s){
            if(left.find(c) != string::npos){       //find未找到返回npos
                stk.push(c);
            }else{
                if(stk.empty() || stk.top()!=left[right.find(c)])       //未匹配完或匹配错误
                    return false;
                else
                    stk.pop();
            }
        }
        return stk.empty();
    }
};
