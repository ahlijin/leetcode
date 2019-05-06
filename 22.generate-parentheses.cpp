class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string path;
        if(n>0) generate(n, path, result, 0, 0);
        return result;
    }
    void generate(int n, string &path, vector<string> &result, int left, int right){
        if(left==n){        //左括号满
            string s(path);
            result.push_back(s.append(n-right, ')'));
            return;
        }

        path.push_back('(');
        generate(n, path, result, left+1, right);
        path.pop_back();    //左括号数量-1

        if(left>right){
            path.push_back(')');    //右括号+1
            generate(n, path, result, left, right+1);
            path.pop_back();
        }
    }
};
