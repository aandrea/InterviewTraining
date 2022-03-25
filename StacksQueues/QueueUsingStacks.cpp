#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;

class Queue
{
    public:
        Queue()
        {
        }
        
        void enqueue(int x)
        {
            inStack.push(x);
        }
        
        void dequeue()
        {
            if(outStack.empty())
            {
                while(!inStack.empty())
                {
                    outStack.push((int)inStack.top());
                    inStack.pop();
                }
            }
            outStack.pop();
        }
        
        int front()
        {
            if(outStack.empty())
            {
                while(!inStack.empty())
                {
                    outStack.push((int)inStack.top());
                    inStack.pop();
                }
            }
            return outStack.top();
        }
    
    private:
        stack<int> inStack;
        stack<int> outStack;
    
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    Queue myQueue;
    int orders;
    cin >> orders;
    
    for (int i=0; i < orders; ++i)
    {
        int order, value;
        cin >> order;
        if(order == 1)
        {
            cin >> value;
        }
        
        switch (order)
        {
        case 1:
            myQueue.enqueue(value);
            break;
        case 2: 
            myQueue.dequeue();
            break;
        case 3:
            printf("%d\n",myQueue.front()); break;
        default: break;
        }
        
    }
    return 0;
}

