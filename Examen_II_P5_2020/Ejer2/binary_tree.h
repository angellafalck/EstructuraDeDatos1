#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_
#include <list>

template<typename TElem>
class BinarySearchTree
{
public:
    class Node
    {
        public:
        Node(TElem data):data(data), left(nullptr), right(nullptr)
        {}


        TElem data;
        Node* left;
        Node* right;
        void inorder(std::list<TElem> &l) const;
    };

    BinarySearchTree():root(nullptr)
    {}
    ~BinarySearchTree()
    {}

    void insert(TElem data);
    void print();
     
    // Returns a list of the elements of the tree
    // in ascending order.
    void inorder(std::list<TElem> &l) const
    {
        root->inorder();
        std::cout<<"\n";
    }


private:
    Node* root;


};

#include "binary_tree.cpp"
#endif