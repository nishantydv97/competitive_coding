/*

A palindrome is a string of letters that is equal to itself when reversed. Given an input string, not necessarily a palindrome, compute the number of times you need to swap to transform the string into a palindrome. By swap we mean reversing the order of two adjacent symbols. For example, the string "mamad" may be transformed into the palindrome "madam" with 3 swaps:
swap "ad" to get "mamda"
swap "md" to get "madma"
swap "ma" to get "madam"
Input
The Input will have number of test cases. For each test case, one line of input containing a string of up to 100 lowercase letters will be there. Terminate the input with a 0(zero).

Output
Output consists of one line. This line will contain the number of swaps, or "Impossible" if it is not possible to transform the input string to a palindrome.

Example
Input:
mamad
asflkj
aabb
0
Output:
3
Impossible
2



*/


#include <bits/stdc++.h>
using namespace std;

bool is_shuffled_palindrome(const string & s) {
    vector<int> occurrence(26, 0);
    int odd_count = 0;
    for(char i : s) { occurrence[i - 'a']++; }
    for (int value : occurrence) { 
        if (value % 2 != 0) { 
            odd_count++; 
        } 
    }
    return odd_count <= 1;
}


int solution(string s) {
    int s_size = s.size();
    int result = 0;
    int start = 0, end = s_size - 1;
    if ((s_size == 0) || (!is_shuffled_palindrome(s))) {
        return -1;
    }

    while (end > start) {
        if (s[start] != s[end]) {
            int i = end; 

            while (i > start && s[i] != s[start]) { --i; }
            if (i == start) {
                swap(s[start], s[start + 1]);
                ++result;
            }
            else {
                while (i < end) {
                    swap(s[i], s[i + 1]);
                    ++result;
                    ++i;
                }
                ++start; --end;
            }
        }
        else {
            ++start; --end;
        }
    }
    return result;
}
int main() {
	string s;
	while(cin>>s){
	    if(s=="0"){
	        break;
	    } 
	    else{
	        int ans=solution(s);
	    if(ans==-1){
	        cout<<"Impossible"<<endl;
	    }else{
	        cout<<ans<<endl;
	    }
	    }
	    
	}
	return 0;
}
