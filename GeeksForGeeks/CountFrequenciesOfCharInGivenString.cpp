/*
Given a string ypu have tp count the frequencies of the char in the string.

apping for the char in the string to the actuall char is given below.
1     ->    a
2     ->    b
      .
      .
      .
      .
      .
10#   ->     j
11#   ->     k
      .
      .
      .
      .
26#   ->     z


given input "1(4)23(6)410#(15)15#3"

respactive output


d -> 1
b -> 1
c -> 7
j -> 15
a -> 4
o -> 1

*/




#include<bits/stdc++.h>
using namespace std;

unordered_map<char, int> solve(string str){
    unordered_map<char, int> ans;
    int len=str.size();
    vector<bool> vis(len, 0);
    // for solving number greater then 9
    int i=0;
    for(int i=0;i<len;i++){
        if(str[i]=='#'){
            int num=stoi(str.substr(i-2,2));
            vis[i]=vis[i-1]=vis[i-2]=1;
            if(i==len-1){
                ans[num-1+'a']++;
            }else if(str[i+1]!='('){
                ans[num-1+'a']++;
            }else{
                int j=i+2;
                string tmp;
                while(str[j]!=')'){
                    vis[j]=1;
                    tmp+=str[j];
                    j++;
                }
                ans[num-1+'a']+=stoi(tmp);
                vis[i]=vis[i+1]=1;
                vis[j]=1;
            }
        }
    }
    // for number between 1-9;
    for(int i=0;i<len;i++){
        if(vis[i]) continue;
        vis[i]=1;
        if(i==len-1){
            ans[stoi(str.substr(i,1))-1+'a']++;
        }else if(str[i+1]!='('){
            ans[stoi(str.substr(i,1))-1+'a']++;
        }else{
            vis[i]=vis[i+1]=1;
                int j=i+2;
                string tmp;
                while(str[j]!=')'){
                    vis[j]=1;
                    tmp+=str[j];
                    j++;
                }
                vis[j]=1;
                ans[stoi(str.substr(i,1))-1+'a']+=stoi(tmp);
        }
        
    }
    
    return ans;
}

int main(){
    string str="1(4)23(6)410#(15)15#3";
    str="51220#24#(14455)56410#14#355(87)122#32";
    unordered_map<char, int> ans=solve(str);
    for(auto i : ans){
        cout<<i.first<<" -> "<<i.second<<"\n";
    }
    return 0;
}
