class Solution {
public:
    int reverse(int x) {
        long long r = 0;
        long long t = x;
        t = t>0 ? t:-t;
        for(; t; t/=10)
            r = r*10 + t%10;
        int sign = x>0 ? 1:-1;
        if(r>INT32_MAX || r<INT32_MIN){
            return 0;
        }else{
            return sign*r;
        }
    }
};
