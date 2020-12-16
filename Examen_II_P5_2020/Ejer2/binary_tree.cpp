#include "binary_tree.h"

template<typename TElem>
void BinarySearchTree<TElem>::insert(TElem data)
{
    if(root==nullptr)
    {
        root= new Node(data);
        return;
    }

    Node *n=root;
    do
    {
        if(n->data==data)
        {
            std::cout<<"Found element: "<<data<<"\n";
             break;
        }
        

        if(data< n->data)
        {
            if(n->left == nullptr)
            {
                n->left= new Node(data);
                break;
            }else
                n= n->left;
        }
        else
        {
            if(n->right == nullptr)
            {
                n->right =new Node(data);
                break;
            }else
                n= n->right;
          }
        
    } while (true);
    
}

template<typename TElem>
void BinarySearchTree<TElem>::Node::inorder(std::list<TElem> &l) const
{
      if(left!=nullptr)
    {
        left->inorder(l);
    }
        
    l.push_back(data);
    
    if(right!=nullptr)
    {
        right->inorder(l);
    }
        
}

template<typename TElem>
void BinarySearchTree<TElem>::print()
{
    if(root!=nullptr)
        root->print();
}