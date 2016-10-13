/*蒜头君想把计算机专业相关的课程都写一遍，放到计蒜客上面帮助同学们学习。但是蒜头君意识到要写的课程有很多很多，蒜头君实在忙不过来，于是他想招几位实习生帮助
一块写课程。招聘广告一发，吸引了好多大牛前来应聘，于是蒜头君每天都要安排面试。有一天，结束了一天面试后，boss 跑来问蒜头君：“小蒜，你觉得今天面试的同学
里面，谁最优秀呀，谁最适合写课程呀？”蒜头君递给 boss 一沓简历，回答到：“这里有 N 份简历，boss 你猜猜哪位同学最优秀。”每份简历都有一个对应的 id，编号
从 1 开始，依次从第一份简历到最后一份简历。boss 会从简历里抽掉 MM 份简历，每次他随机念一个数字 num_i，然后从第一份简历开始数，数到第 num_i份时，就会
把对应的简历抽掉，接着念下一个数字。抽掉 M份简历后，boss 从剩余的简历中，取出最中间的一份简历，然后点点头念道：“我相信这位同学一定最优秀，哈哈”。

现在蒜头君想知道这份简历的 id是多少，聪明的你能帮他算出来吗？

输入格式

第一行输入两个正整数 N 和 M。第二行输入 M 个整数 num_i，表示 boss 依次念出来的数字。

保证 N - M 是奇数，输入的 num_i 小于等于当前剩余简历数量。

输出格式

输出为一行，输出 boss 认为最优秀的同学的 id是多少。*/

#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        Node(int _data){
            data = _data;
            next = NULL;
        }
};

class Linkedlist{
    private:
        Node *head;
    public:
        Linkedlist(){
            head = NULL;
        }
    
        ~Linkedlist(){
            Node *current_node = head;
            while(current_node != NULL){
                Node *delete_node = current_node;
                current_node = current_node->next;
                delete delete_node;
            }
        }
    
        void insert(Node *node,int index){
            if(head == NULL){
                if(index != 0)
                return;
                head = node;
                return;
            }
            
            if(index == 0){
                node->next = head;
                head = node;
                return;
            }
            
            Node *current_node = head;
            int count = 0;
            while(current_node->next != NULL && count < index - 1){
                current_node = current_node->next;
                count++;
            }
            
            if(count == index - 1){
                node->next = current_node->next;
                current_node->next = node;
            }
        }
    
        void delete_node(int index){
            if(head == NULL){
                return;
            }
            Node *current_node = head;
            int count = 0;
            if(index == 0){
                head = head->next;
                delete current_node;
                return;
            }
            
            while(current_node->next != NULL && count < index - 1){
                current_node = current_node->next;
                count++;
            }
            
            if(count == index - 1 && current_node->next != NULL){
                Node *delete_node = current_node->next;
                current_node->next = delete_node->next;
                delete delete_node;
            }
        }
    
        void output(int index){
            if(head == NULL){
                return;
            }
            
            Node *current_node = head;
            int count = 0;
            if(index == 0){
                cout<<current_node->data;
                return;
            }
            while(current_node->next != NULL && count < index - 1){
                current_node = current_node->next;
                count++;
            }
            if(count == index - 1){
                cout<<current_node->data;
            }
            
        }
};


int main(){
    Linkedlist linkedlist;
    int n,m;
    cin>>n>>m;
    for (int i = 1; i <= n; i++){
        Node *node = new Node(i);
        linkedlist.insert(node,i - 1);
    }
    
    int *a = new int[m];
    for(int i = 0; i < m; i++){
        cin>>a[i];
    }
    for(int i = 0; i < m; i++){
        linkedlist.delete_node(a[i] - 1);
    }
    int k = (n - m + 1) / 2;
    linkedlist.output(k);
    return 0;
}
