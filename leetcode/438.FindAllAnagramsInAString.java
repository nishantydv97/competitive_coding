/*


Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 

Constraints:

1 <= s.length, p.length <= 3 * 104
s and p consist of lowercase English letters.
Accepted
472,430
Submissions
992,253


*/

class Solution {
    public static boolean checkList(List<Integer> first, List<Integer> second) {
        for(int i = 0; i < first.size(); i++) {
            if(!Objects.equals(first.get(i), second.get(i))){
                return false;
            }
        }
        return true;
    }
    public static List<Integer> allAnagram(String a, String b) {
        List<Integer> res = new ArrayList<>();
        List<Integer> alpha1 = Stream.generate(() -> 0).limit(26).collect(Collectors.toList());
        List<Integer> alpha2 = Stream.generate(() -> 0).limit(26).collect(Collectors.toList());
        for(int i = 0; i<a.length(); i++){
            alpha1.set(a.charAt(i)-97, alpha1.get(a.charAt(i)-97)+1);
            alpha2.set(b.charAt(i)-97, alpha2.get(b.charAt(i)-97)+1);
        }
        if(checkList(alpha1, alpha2)){
            res.add(0);
        }
        int i=0; int j=a.length();
        while(j < b.length()) {
            alpha2.set(b.charAt(i)-97, alpha2.get(b.charAt(i)-97)-1);
            i++;
            alpha2.set(b.charAt(j)-97, alpha2.get(b.charAt(j)-97)+1);
            if(checkList(alpha1, alpha2)){
                res.add(i);
            }
            j++;
        }
        return res;
    }
    
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> res = new ArrayList<>();
        if(s.length()<p.length()) return res;
        return allAnagram(p, s);
    }
}
