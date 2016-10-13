//栈的各种基本操作（程序中实现了输入数据翻转）
#include<iostream>
#include<string>
#include<cassert>
using std::cin;
using std::cout;
template<class Type> class Stack {
private:
    Type *urls;
    int max_size, top_index;
public:
    Stack(int length_input) {
        urls = new Type[length_input];
        max_size = length_input;
        top_index = -1;
    }
    ~Stack() {
        delete[] urls;
    }
    bool push(const Type &element) {
        if (top_index >= max_size - 1) {
            return false;
        }
        top_index++;
        urls[top_index] = element;
        return true;
    }
    bool pop() {
        if (top_index < 0) {
            return false;
        }
        top_index--;
        return true;
    }
    Type top() {
        assert(top_index >= 0);
        return urls[top_index];
    }
    // 请在下面实现判断栈是否为空的方法 empty
    bool empty(){
        if(top_index < 0){
            return true;
        }
        else{
            return false;
        }
    }
};
int main() {
    int n,num;
    cin>>n;
    Stack<int> stack(n);
    for(int i = 1; i <= n; i++){
        cin>>num;
        stack.push(num);
    }
    while(!stack.empty()){
        cout<<stack.top()<<" ";
        stack.pop();
    }
    return 0;
}
