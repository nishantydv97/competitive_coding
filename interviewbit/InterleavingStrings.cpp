/*

Given A, B, C, find whether C is formed by the interleaving of A and B.

Input Format:*

The first argument of input contains a string, A.
The second argument of input contains a string, B.
The third argument of input contains a string, C.
Output Format:

Return an integer, 0 or 1:
    => 0 : False
    => 1 : True
Constraints:

1 <= length(A), length(B), length(C) <= 150
Examples:

Input 1:
    A = "aabcc"
    B = "dbbca"
    C = "aadbbcbcac"

Output 1:
    1
    
Explanation 1:
    "aa" (from A) + "dbbc" (from B) + "bc" (from A) + "a" (from B) + "c" (from A)

Input 2:
    A = "aabcc"
    B = "dbbca"
    C = "aadbbbaccc"

Output 2:
    0

Explanation 2:
    It is not possible to get C by interleaving A and B.

*/

int Solution::isInterleave(string s1, string s2, string s3) {
    int l1=s1.length(), l2=s2.length(), l3=s3.length();
        if (l3!=l1+l2) return false;
        bool** result = new bool*[l1+1];
        for (int i=0; i<=l1; i++){
            result[i] = new bool[l2+1];
        }
        result[0][0] = true;
        for (int i=1; i<=l1; i++){
            result[i][0] = result[i-1][0] && s3[i-1]==s1[i-1];
        }
        for (int i=1; i<=l2; i++){
            result[0][i] = result[0][i-1] && s3[i-1]==s2[i-1];
        }
        for (int i=1; i<=l1; i++){
            for (int j=1; j<=l2; j++){
                result[i][j] =
                    (result[i-1][j] && s1[i-1]==s3[i+j-1]) ||
                    (result[i][j-1] && s2[j-1]==s3[i+j-1]);
            }
        }
        return result[l1][l2];
    }


