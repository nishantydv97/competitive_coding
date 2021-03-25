/*

Design a HashMap without using any built-in hash table libraries.

Implement the MyHashMap class:

MyHashMap() initializes the object with an empty map.
void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.
 

Example 1:

Input
["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
Output
[null, null, null, 1, -1, null, 1, null, -1]

Explanation
MyHashMap myHashMap = new MyHashMap();
myHashMap.put(1, 1); // The map is now [[1,1]]
myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]
 

Constraints:

0 <= key, value <= 106
At most 104 calls will be made to put, get, and remove.
 

Follow up: Please do not use the built-in HashMap library.



*/


class Node{
    public:
    int key;
    int val;
    Node* next;
    Node(int key, int val){
        this->key=key;
        this->val=val;
        this->next=NULL;
    }
};

class MyHashMap {
public:
    /** Initialize your data structure here. */
    //vector<Node*> hashMap(1000007, NULL);
    Node* hashMap[1000007];
    MyHashMap() {
        for(int i=0; i<1000007; i++) hashMap[i]=NULL;
    }
    
    /** value will always be non-negative. */
    int hashCode(int k){
        return k%1000007;
    }
    void put(int key, int value) {
        int hashCodeVal=hashCode(key);
        Node* tmp=new Node(key, value);
        if(hashMap[hashCodeVal]!=NULL){
            Node* p=hashMap[hashCodeVal];
            cout<<"hello";
            Node* q;
            while(p){
                if(p->key==key){
                    p->val=value;
                    return;
                }
                q=p;
                p=p->next;
            }
            q->next=tmp;
        }else{
            hashMap[hashCodeVal]=tmp;
        }
        
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hashCodeVal=hashCode(key);
        if(!hashMap[hashCodeVal]) return -1;
        Node* p=hashMap[hashCodeVal];
        while(p){
            if(p->key==key) return p->val;
            p=p->next;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int hashCodeVal=hashCode(key);
        if(!hashMap[hashCodeVal]) return;
        Node* p=hashMap[hashCodeVal];
        if(p->key==key){
            hashMap[hashCodeVal]=p->next;
            return;
        }
        while(p->next and p->next->key!=key){
            p=p->next;
        }
        if(p->next){
            p=p->next->next;
            return;
        }else{
            return;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
