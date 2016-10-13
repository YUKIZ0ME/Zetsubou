//队列的基本操作及队首元素 输出、删除队首元素
#include <iostream>
#include <cassert>
using std::cout;
using std::endl;
class Queue {
private:
    int *data;
    int head, tail, length;
public:
    Queue(int length_input) {
        data = new int[length_input];
        length = length_input;
        head = 0;
        tail = -1;
    }
    ~Queue() {
        delete[] data;
    }
    void push(int element) {
        if (tail + 1 < length) {
            tail++;
            data[tail] = element;
        }
    }
    void output() {
        for (int i = head; i <= tail; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    // 请在下面实现 front 函数
    int front(){
        assert(head <= tail);
        return data[head];
    }
    // 请在下面实现 pop 函数
    void pop(){
        assert(head <= tail);
        head++;
    }
};
int main() {
    Queue queue(100);
    for (int i = 1; i <= 10; i++) {
        queue.push(i);
    }
    queue.output();
    cout<<queue.front()<<endl;
    queue.pop();
    queue.output();
    return 0;
}
