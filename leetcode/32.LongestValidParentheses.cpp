/*


Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"


*/

class Solution {
public:
    int longestValidParentheses(string s) {
        	stack<char> stk1;
	stack<int> stk2;
	//cout<<s<<endl;
	
	//cout<<"size of the string is "<<s.size()<<endl;
	for(int i=0;i<s.size();i++){
        if(stk1.empty()){
            stk1.push(s[i]);
            stk2.push(i);
        }
		else if(s[i]==')' && stk1.top()=='('){
			stk1.pop();
			stk2.pop();
		}else{
			stk1.push(s[i]);
			stk2.push(i);
		}
	}
	//cout<<"size of the stk2 is "<<stk1.size()<<endl;
	vector<int> v;
    v.push_back(s.size());
	if(stk2.empty()){
		return s.size();
	}else{
		while(!stk2.empty()){
			int tmp=stk2.top();
			stk2.pop();
			v.push_back(tmp);
		}
	}
        v.push_back(-1);
	/*
	for(auto i : v){
		cout<<i<<" ";
	}
	*/
	//cout<<"\n";
	int ans=0;
	pair<int,int> p;
	for(int i=1;i<v.size();i++){
		if(abs(v[i-1]-v[i])-1>ans){
			p=make_pair(v[i-1],v[i]+1);
            ans=abs(v[i-1]-v[i])-1;
		}
	}
	//cout<<p.first<<" "<<p.second<<" "<<endl;
	//cout<<"length is "<<abs(p.first-p.second)<<endl;
	string balance="";
	for(int i=p.second;i<p.first;i++){
		//cout<<s[i];
		balance+=s[i];
	}
	//cout<<"\n";
	return abs(p.first-p.second);
    }
};
