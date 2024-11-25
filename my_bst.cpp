#include <iostream>
#include "my_bst.h"
using namespace std;


// creazione nodo ricorsivo
node*  node::insert_r(node *root, int k){
    if(root==nullptr){
        return new node(k);
    }
    if(root->data==k){
        root->weight++;
        return root;
    }
    if(root->data>k){
        root->lchild=insert_r(root->lchild, k);
    }else{
        root->rchild=insert_r(root->rchild, k);
    }
}

// creazione nodo iterativo
node* node::insert_i(node* root, int k){
    bool check{true};
    node*current=root;
    node*father=nullptr;
    do{
        if(current==nullptr){
            if(father->data>k){
                father->lchild=new node(k);
                check=false;
                return root;
            }else{
                father->rchild=new node(k);
                check=false;
                return root;
            }
        }
        if(current->data==k){
            check=false;
            current->weight++;
            return root;
        }
        if(current->data>k){
            father=current;
            current=current->lchild;
        }else{
            father=current;
            current=current->rchild;
        }
    }while(check);
    return root;
}

//cerco nodo con ricorsione
node* node::search_r(node *root, int k){
    if(root==nullptr){
        cout << "nodo non trovato";
        return root;
    }
    if(root->data==k){
        cout << "nodo trovato";
        return root;
    }
    if(root->data>k){
        search_r(root->lchild, k);
    }else{
        search_r(root->rchild, k);
    }
    return root;
}

//cerca nodo con iterazione NON HO USATO FATHER E CURRENT
node* node::search_i(node* root, int k){
    bool check{true};
    do{
    if(root==nullptr){
        cout << "nodo non trovato";
        check=false;
        return root;
    }
    if(root->data==k){
        cout << "nodo trovato";
        check=false;
        return root;
    }
    if(root->data>k){
        root=root->lchild;
    } else {
        root=root->rchild;
    }
    }while(check);
    return root;
}

//cancellazione nodo con ricorsione 
node* node::cancel_r(node *root, int k){
    if(root==nullptr){
        cout << "nodo non trovato";
        return root;
    }
    if(root->data==k){
        if(root->rchild==nullptr && root->lchild==nullptr){
            delete root;
            return root;
        }
        if(root->rchild!=nullptr){
            node* temp=root;
            root->data=root->rchild->data;
            root->rchild->data=temp->data;
            root->rchild->data=0;
            delete root->rchild;
            return root;
        }
        if(root->lchild!=nullptr){
            node* temp=root;
            root->data=root->lchild->data;
            root->lchild->data=temp->data;
            root->lchild->data=0;
            delete root->lchild;
            return root;
        }
    }
    if(root->data>k){
        cancel_r(root->lchild, k);
    } else{
        cancel_r(root->rchild, k);
    }
}

//cancellazione nodo con iterazione
node* node::cancel_i(node* root, int k){
    bool check{true};
    do{
    if(root==nullptr){
        cout << "nodo non trovato";
    }
    if(root->data==k){
        if(root->rchild!=nullptr && root->lchild!=nullptr){
            root->data=0;
            delete root;
        }
        if(root->rchild!=nullptr){
            node*temp=root;
            root->data = root->rchild->data;
            root->rchild->data=temp->data;
            root->rchild->data=0;
            delete root->rchild;
            check=false;
            return root;
        }
        if(root->lchild!=nullptr){
            node*temp=root;
            root->data = root->lchild->data;
            root->lchild->data=temp->data;
            root->lchild->data=0;
            delete root->lchild;
            check=false;
            return root;
        }
    }
    }while(check);
}

// scorrimento ricorsivo Inorder_Traversal
node* node::Inorder_Traversal(node*r){
    if(r==NULL){
        cout<<"L'albero è vuoto"<<endl;
    }else{
        if(r->lchild!=NULL){
            Inorder_Traversal(r->lchild );
        }
        cout<<r->data<<" ";
        if(r->rchild!=NULL){
            Inorder_Traversal(r->rchild );
        }
    }
    return r;
}

// scorrimento ricorsivo Preorder traversal
node* node::Preorder_Traversal(node*r){
    if(r==NULL){
        cout<<"L'albero è vuoto"<<endl;
    } else{
        cout<<r->data<<" ";
        if(r->lchild!=NULL){
            Preorder_Traversal(r->lchild );
        }
        if(r->rchild!=NULL){
            Preorder_Traversal(r->rchild );
        }
    }
    return r;
}

// scorrimento ricorsivo Postorder traversal
node* node::Postorder_Traversal(node*r){
    if(r==NULL){
        cout<<"L'albero è vuoto"<<endl;
    } else{
        if(r->lchild!=NULL){
            Postorder_Traversal(r->lchild );
        }
        if(r->rchild!=NULL){
            Postorder_Traversal(r->rchild );
        }
        cout<<r->data<<" ";
    }
    return r;
}

// calcolo dei livelli
int node::max(int sl,int sr){
    if (sl>sr){
        return sl;
    } else
    return sr;
}
int node::height(node *r){
    if(r==NULL){
        return 0;
    }
    int sl=height(r->lchild);
    int sr=height(r->rchild);
    return max(sl,sr)+1;
}

//verifica di un albero se e un BST
node* node::Preorder_Traversal_Test(node* root){
    if(root==NULL){
        cout << "l'albero e vuoto";
        return root;
    }
    cout << root->data << " ";
    if(root->lchild!=NULL && root->lchild->data<root->data){
        Preorder_Traversal_Test(root->lchild);
    }else if(root->lchild!=NULL && root->lchild->data>root->data){
        cout << "non e un BST";
    }
    if(root->rchild!=NULL && root->rchild->data>root->data){
        Preorder_Traversal_Test(root->rchild);
    }else if(root->rchild!=NULL && root->rchild->data<root->data){
        cout << "non e un BST";
    }
    return root;
}

node* node::insertR(int k){
    if (k==this->data){
        this->weight++;
        return this;
    }
    if (k<this->data){
        if (this->lchild == NULL){
            this->lchild= new node (k);
        } else{
            this->lchild= this->lchild->insertR(k);
        }
    } else if (this->rchild== NULL){
        this->rchild= new node(k);
    } else {
        this->rchild= this->rchild->insertR(k);
    }
    return this;

}

void node::inOrder(){
     if(this->lchild!=NULL){
        this->lchild->inOrder();
    }
    cout<<this->data<<" ";
    if(this->rchild!=NULL){
        this->rchild->inOrder();
    }
}


