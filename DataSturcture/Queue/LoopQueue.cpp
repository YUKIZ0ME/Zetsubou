//循环队列的各种操作
#include <iostream>
#include <cassert>
using std::cout;
using std::endl;
class Queue {
private:
    int *data;
    int head, tail, length, count;
public:
    Queue(int length_input) {
        data = new int[length_input];
        length = length_input;
        head = 0;
        tail = -1;
        count = 0;
    }
    ~Queue() {
        delete[] data;
    }
    void push(int element) {
        if (count < length) {
            tail = (tail + 1) % length;
            data[tail] = element;
            count++;
        }
    }
    void output() {
        int i = head;
        do {
            cout << data[i] << " ";
            i = (i + 1) % length;
        } while(i != (tail + 1) % length);
        cout << endl;
    }
    int front() {
        assert(count > 0);
        return data[head];
    }
    void pop() {
        assert(count > 0);
        head = (head + 1) % length;
    }
};
int main() {
    Queue queue(100);   
    for (int i = 1; i <= 10; i++) {
        queue.push(i);
    }
    queue.output();
    cout << queue.front() << endl;
    queue.pop();    
    queue.output();
    return 0;
}
