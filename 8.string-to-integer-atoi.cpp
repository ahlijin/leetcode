class Solution {
public:
    int myAtoi(string str) {
        int64_t num  = 0;
        int sign = 1;
        const int n = str.length();
        int i = 0;
        while(str[i]==' ' && i<n) ++i;       //  跳过开头的空格
        
        if(str[i] == '+'){
            ++i;
        }else if(str[i] == '-'){
            sign = -1;
            ++i;
        }

        for(; i<n; ++i){
            if(str[i]<'0' || str[i]>'9')
                break;
            if(num>INT32_MAX/10 || 
                    (num==INT32_MAX/10 && (str[i]-'0')>INT32_MAX%10)){      //  处理最后一位数
                return sign == -1 ? INT32_MIN:INT32_MAX;
            }
            num = num*10 + str[i]-'0';
        }
        return sign*num;
    }
};
