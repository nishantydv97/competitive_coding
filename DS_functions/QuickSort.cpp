#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int l, int r){
    int i=l;
    int pivit=v[r];
    for(int j=l;j<r;j++){
        if(v[j]<=pivit){
            swap(v[j],v[i]);
            i++;
        }
    }
    swap(v[i],v[r]);
    return i;
}

void quicksort(vector<int> &v, int l, int r){
    if(l<r){
        int part=partition(v,l,r);
        quicksort(v,l,part-1);
        quicksort(v,part+1,r);
    }
}

int main(){
    vector<int> v;
    for(int i=10;i>0;i--){
        v.push_back(rand()%10);
    }
    for(auto i : v){
        cout<<i<<" ";
    }
    cout<<"\n";
    quicksort(v,0,9);
    for(auto i : v){
        cout<<i<<" ";
    }
    cout<<"\n";
}
