/*蒜头君最近在学习二叉树，可是心不在焉的他一会儿就学累了，于是他想休息会儿。蒜头君拿出镜子，对着镜子中的自己各种卖萌。蒜头君无意间看见镜子中出现了

一棵二叉树，这不是他刚画的那棵二叉树么，在镜子里怎么左右颠倒了呀。蒜头君觉得好神奇，于是他又随手画了一棵二叉树，他想知道这棵二叉树在镜子里是长什么

样的。为了将问题简单，现在蒜头君告诉你这棵二叉树的先序遍历结果和中序遍历结果，求原始二叉树的后序遍历结果，以及镜子里的二叉树的后序遍历结果。*/

/*镜子里的二叉树的后序遍历为原始二叉树的前序遍历结果倒序输出*/

#include<iostream>
#include<string>
using namespace std;
class Node {
public:
    int data;
    Node *lchild, *rchild;
    Node(int _data) {
        data = _data;
        lchild = NULL;
        rchild = NULL;
    }
    ~Node() {
        if (lchild != NULL) {
            delete lchild;
        }
        if (rchild != NULL) {
            delete rchild;
        }
    }
    void postorder() {
        if (lchild != NULL) {
            lchild->postorder();
        }
        if (rchild != NULL) {
            rchild->postorder();
        }
        char data_char = data + '0';
        cout << data_char;
    }
    // 请在下面实现建立二叉树的方法 build
    Node *build(const string &pre_str, const string &in_str, int len){
        Node *p = new Node(pre_str[0] - '0');
        int pos  = in_str.find(pre_str[0]);
        if(pos > 0){
            p->lchild = build(pre_str.substr(1,pos),in_str.substr(0,pos),pos);
        }
        if(len - pos - 1 > 0){
            p->rchild = build(pre_str.substr(pos + 1),in_str.substr(pos + 1),len - pos -1);
        }
        return p;
    }
};
class BinaryTree {
private:
    Node *root;
public:
    BinaryTree() {
        root = NULL;
    }
    ~BinaryTree() {
        if (root != NULL) {
            delete root;
        }
    }
    // 请在下面实现构造函数
    BinaryTree(const string &pre_str, const string &in_str, int len){
        root = root->build(pre_str,in_str,len);
    }
    void postorder() {
        root->postorder();
    }
};
int main() {
    string pre_str,in_str;
    cin>>pre_str;
    cin>>in_str;
    int len = in_str.length();
    BinaryTree binarytree(pre_str, in_str, len);
    binarytree.postorder();
    cout<<endl;
    for(int i = 0; i < len; i++){
        cout<<pre_str.substr(len - i - 1,1);
    }
    //cout<<endl;
    return 0;
}
