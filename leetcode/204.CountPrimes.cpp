/*

Count the number of prime numbers less than a non-negative number, n.

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Example 2:

Input: n = 0
Output: 0

Example 3:

Input: n = 1
Output: 0

 

Constraints:

    0 <= n <= 5 * 106




*/

class Solution {
public:
    int countPrimes(int n) {
        vector<int> prime(n+2, 1);
        prime[0]=prime[1]=0;
        for(int i=2; i*i<(n+1); i++){
            if(prime[i]){
                for(int j=i*i; j<n+1; j+=i){
                    prime[j]=0;
                }
            }
        }
        vector<int> cntPrime;
        for(int i=0;i<n; i++){
            if(prime[i]){
                cntPrime.push_back(i);
            }
        }
        return cntPrime.size();
    }
};
