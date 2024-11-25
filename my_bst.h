#ifndef _MY_BST.H_
#define _MY_BST.H_

class node{
    private:

    public:
    int data;
    int weigth;
    node *lchild;
    node *rchild;
    node(int k){
        data=k;
        weigth=1;
        lchild=nullptr;
        rchild=nullptr;
    }

    node* insert_r(node *root, int k);
    node* insert_i(node* root, int k);
    node* search_r(node *root, int k);
    node* search_i(node* root, int k);
    node* cancel_r(node *root, int k);
    node* cancel_i(node* root, int k);
    node* Inorder_Traversal(node*r);
    node* Preorder_Traversal(node*r);
    node* Postorder_Traversal(node*r);
    int max(int sl,int sr);
    int height(node *r);
    node* Preorder_Traversal_Test(node* root);
};


#endif