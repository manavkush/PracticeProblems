// https://leetcode.com/problems/reverse-words-in-a-string-iii

class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        arr = s.split(" ")
        ans = ""
        for x in arr:
            ans = ans + (x[::-1]) + " ";
        return ans[:-1]