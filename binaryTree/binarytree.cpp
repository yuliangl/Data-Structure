#include "binarytree.h"

BinaryTree::BinaryTree(){

}
BinaryTree::BinaryTree(int data){

    m_root = new treeNode(data);
}

treeNode* BinaryTree::addLeftNode(treeNode *parent_node, int data_){
    treeNode *node = new treeNode(data_);
    parent_node->leftNode(node);
    return node;
}
treeNode* BinaryTree::addRightNode(treeNode *parent_node, int data_){
    treeNode *node = new treeNode(data_);
    parent_node->rightNode(node);
    return node;
}

void BinaryTree::preOrder(){
   if(m_root){
       m_root->preorder();
   }
}

void BinaryTree::midOrder(){
    if(m_root){
        m_root->midorder();
    }
}
void BinaryTree::afterOrder(){
    if(m_root){
        m_root->afterorder();
    }

}

void BinarySortTree::add(treeNode* node_){
    if(m_root){
        m_root->addNode(node_);
    }else {
        m_root = node_;
    }
}
