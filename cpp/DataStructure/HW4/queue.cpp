// LeetCode, Implement Queue using Stacks
// 两个栈, 一个只负责压栈, 另一个只负责出栈
// 若负责出栈的栈为空, 且要进行出栈操作, 则将压栈的栈中元素倒到出栈的栈中

// #define LOCAL
#ifdef LOCAL
#include <vector>

using namespace std;
#endif

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        dt[0].push_back(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
		int tmp;
        if (dt[1].empty())
			while(!dt[0].empty())
			{
				tmp = *(dt[0].end() - 1);
				dt[1].push_back(tmp);
				dt[0].pop_back();
			}
		tmp = *(dt[1].end() - 1);
		dt[1].pop_back();
		return tmp;
    }
    
    /** Get the front element. */
    int peek() {
		if (dt[1].empty())
			return dt[0][0];
		else
        	return *(dt[1].end() - 1);
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return dt[0].empty() && dt[1].empty();
    }
private:
	vector<int> dt[2];
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */