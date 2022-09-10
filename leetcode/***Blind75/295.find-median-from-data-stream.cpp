#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> minheap; // ascending
    priority_queue<int> maxheap;    // descending
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if (maxheap.empty() || num < maxheap.top())
            maxheap.push(num);
        else
            minheap.push(num);
        arrange();
    }
    void arrange(){
        if (maxheap.size() > 1 + minheap.size()){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        if (minheap.size() > 1 + maxheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        if (maxheap.size() != minheap.size()){
            if (maxheap.size() > minheap.size())
                return maxheap.top()/1.0;
            else
                return minheap.top()/1.0;
        } 
        return (maxheap.top() + minheap.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
//
//
//
// 1,3,4,7,9, 12,16,17,20
// ---------  -----------
//         ^  ^
//   maxheap  minheap
// if num < maxheap.top push into maxheap
// else push into minheap