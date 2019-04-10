class Solution {
public:
    int lengthOfLongestSubstring(string s) {
	const int ASCII_MAX = 255;
	int last[ASCII_MAX];	// 记录字符上一次出现的位置
	int start = 0;		// 记录当前字串开始位置	

	fill(last, last+ASCII_MAX, -1);		// 注意此种初始化方式
	int max_len = 0;
	for(int i=0; i<s.size(); ++i){
		if(last[s[i]] >= start){	// 出现重复字符
			max_len = max(i-start, max_len);
			start = last[s[i]]+1;	// 更新重复字符最近出现的位置
		}
		last[s[i]] = i;			// 更新所有字符上一次出现的位置
	}
	return max((int)s.size()-start, max_len);		// 最后一次未出现重复字符，字串长度为(int)s.size()-start
    }
};

