class Solution(object):
    def lengthOfLongestSubstring(self, s):
        if s == '':
            return 0
        result = [1]
        last = s[0]
        for i in range(1, len(s)):
            if s[i] in last:
                result.append(result[i - 1])
                last = last[last.index(s[i]) + 1 : ] + s[i]
            else:
                result.append(max(len(last) + 1, result[i - 1]))
                last += s[i]
    
        return result[len(result) - 1]
        