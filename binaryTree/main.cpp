#include <iostream>
#include <vector>
#include "binarytree.h"


using namespace std;

int main()
{
//    BinaryTree tree(1);
//    treeNode* node2 = tree.addLeftNode(tree.getRoot(), 2);
//    treeNode* node3 = tree.addRightNode(tree.getRoot(), 3);
//    treeNode* node4 = tree.addLeftNode(node2, 4);
//    treeNode* node5 = tree.addRightNode(node2, 5);
//    treeNode* node6 = tree.addLeftNode(node3, 6);
//    treeNode* node7 = tree.addRightNode(node3, 7);

//    tree.preOrder();
//    tree.midOrder();
//    tree.afterOrder();
    typedef treeNode* nodeptr;
    BinarySortTree bst;
    std::vector<int> values{7, 2, 4, 5, 6, 10, 12};
    std::vector<nodeptr> nodes;
    for(auto i : values){
        nodes.push_back(nodeptr(new treeNode(i)));
    }

    for(auto i : nodes){
        bst.add(i);
    }
    bst.midOrder();
    cout << "Hello World!" << endl;
    return 0;
}
