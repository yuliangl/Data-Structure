#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <memory>

//template <typename T>
struct treeNode {
    typedef std::shared_ptr<treeNode> ptr;
    int data;
    treeNode* rchild;
    treeNode* lchild;

    treeNode(int val_):data(val_)
                        ,rchild(nullptr)
                        ,lchild(nullptr){
    }
    void leftNode(treeNode *l_node){
        lchild = l_node;
    }
    void rightNode(treeNode *r_node){
        rchild = r_node;
    }

    void preorder(){
        std::cout << this->data <<std::endl;
        if(lchild){
            lchild->preorder();
        }
        if(rchild){
            rchild->preorder();
        }
    }

    void midorder(){
        if(lchild){
            lchild->midorder();
        }
        std::cout << this->data <<std::endl;

        if(rchild){
            rchild->midorder();
        }

    }

    void afterorder(){
        if(lchild){
            lchild->afterorder();
        }
        if(rchild){
            rchild->afterorder();
        }

        std::cout << this->data <<std::endl;
    }

    void addNode(treeNode* node_){
        if (node_->data < this->data){
            if(lchild){
                lchild->addNode(node_);
            }else{
                lchild = node_;
            }
        }else{
            if(rchild){
                rchild->addNode(node_);
            }else {
                rchild = node_;
            }
        }
    }
};

//template<typename T>
class BinaryTree{
public:
    BinaryTree();
    BinaryTree(int);
    virtual ~BinaryTree() {
        delete m_root;
    }

    treeNode* addLeftNode(treeNode *parent_node, int data_);
    treeNode* addRightNode(treeNode *parent_node, int data_);
    treeNode* getRoot() const {return m_root;}

    void preOrder();
    void midOrder();
    void afterOrder();
protected:
    treeNode *m_root;
};

class BinarySortTree: public BinaryTree{
public:
    BinarySortTree():BinaryTree(0) {}
    BinarySortTree(int data): BinaryTree(data) {
    }

    virtual ~BinarySortTree() {
    }
    void add(treeNode*);

};

#endif // BINARYTREE_H
