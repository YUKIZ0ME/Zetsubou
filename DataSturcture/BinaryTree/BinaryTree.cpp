//二叉树的建立及前、中、后序遍历
#include<iostream>
using std::cout;
using std::endl;
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
    // 请在下面实现类 Node 的先序遍历方法 preorder
    void preorder(){
        cout<<data<<" ";
        if(lchild != NULL){
            lchild->preorder();
        }
        if(rchild != NULL){
            rchild->preorder();
        }
    }
    // 请在下面实现类 Node 的中序遍历方法 inorder
    void inorder(){
        if(lchild != NULL){
            lchild->inorder();
        }
        cout<<data<<" ";
        if(rchild != NULL){
            rchild->inorder();
        }
    }
    // 请在下面实现类 Node 的后序遍历方法 postorder
    void postorder(){
        if(lchild != NULL){
            lchild->postorder();
        }
        if(rchild != NULL){
            rchild->postorder();
        }
        cout<<data<<" ";
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
    void build_demo() {
        root = new Node(1);
        root->lchild = new Node(2);
        root->rchild = new Node(3);
        root->lchild->lchild = new Node(4);
        root->lchild->rchild = new Node(5);
        root->rchild->rchild = new Node(6);
    }
    // 请在下面实现类 BinaryTree 的先序遍历方法 preorder
    void preorder(){
        root->preorder();
    }
    // 请在下面实现类 BinaryTree 的中序遍历方法
    void inorder(){
        root->inorder();
    }
    // 请在下面实现类 BinaryTree 的后序遍历方法 postorder
    void postorder(){
        root->postorder();
    }
};
int main() {
    BinaryTree binarytree;
    binarytree.build_demo();
    binarytree.preorder();
    cout<<endl;
    return 0;
}
