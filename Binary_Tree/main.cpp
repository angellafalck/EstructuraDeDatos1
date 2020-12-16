#include <iostream>
#include "binary_tree.h"
#include "arith_expr.h"

int main()
{
    /*
    BinarySearchTree<int> bti;

    bti.insert(67);
    bti.insert(35);
    bti.insert(73);
    bti.insert(23);
    bti.insert(87);
    bti.insert(17);
    bti.insert(73);
    bti.insert(38);
    bti.insert(45);
    bti.insert(35);

    //bti.print();
    std::cout<<"Inorder: ";
    bti.inorder();
    std::cout<<"\n";
    std::cout<<"Preorder: ";
    bti.preorder();
    std::cout<<"\n";
    std::cout<<"Postorder: ";
    bti.postorder();
    std::cout<<"\n";
    */

    BinarySearchTree<ExprData> exprt;
    ExprData plus;

    plus.kind = DataKind::Operator;
    plus.oper= Operator::Add;

    ExprData num1, num2;
    num1.kind= DataKind::Number;
    num1.number=10;

    num2.kind= DataKind::Number;
    num2.number=20;

    BinarySearchTree<ExprData>::Node *root = new BinarySearchTree<ExprData>::Node(plus);
    BinarySearchTree<ExprData>::Node *nnum1= new BinarySearchTree<ExprData>::Node(num1);
    BinarySearchTree<ExprData>::Node *nnum2= new BinarySearchTree<ExprData>::Node(num2);

    root->left = nnum1;
    root->right =nnum2;
}
