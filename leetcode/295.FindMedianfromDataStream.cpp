/*

Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

For example,
[2,3,4], the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
 

Example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
 

Follow up:

If all integer numbers from the stream are between 0 and 100, how would you optimize it?
If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?


*/


class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<>> min_heap;
    MedianFinder() {
        
        
    }
    
    void addNum(int num) {
        if(max_heap.empty())
            max_heap.push(num);
        else{
            if(num>max_heap.top())
                min_heap.push(num);
            else
                max_heap.push(num);
            
            while(max_heap.size()>min_heap.size()+1){
                int top=max_heap.top();
                max_heap.pop();
                min_heap.push(top);
            }
            
            while(max_heap.size()<min_heap.size()){
                int top=min_heap.top();
                min_heap.pop();
                max_heap.push(top);
            }
        } 
    }
    
    double findMedian() {
        if(max_heap.size()==min_heap.size()){
            
            double result=((max_heap.top()+min_heap.top()));
            result/=2;
            return result;
        }
        
        return max_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
