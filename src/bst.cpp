//
// Created by Amogh on 12/13/19.
//

#include "../include/bst.h"

bst::bst()
{
    this->root = nullptr;
    this->sz = 0;
}

bst::~bst()
{
    this->sz = 0;
    if (root) delete root;
}

bool bst::add(int i)
{
    size_t oldsize = this->sz;
    root = addhelp(root, i);
    return oldsize != this->sz;
}

bst::bnode* bst::addhelp(bst::bnode *node, int val)
{
    if (!node)
    {
        this->sz++;
        return new bnode(val);
    }

    if (node->data > val)
    {
        node->left = addhelp(node->left, val);
    }
    else if (node->data < val)
    {
        node->right = addhelp(node->right, val);
    }
    return node;
}

bool bst::remove(int i)
{
    size_t oldsz = this->sz;
    this->root = remove_help(this->root, i);
    return oldsz != this->sz;
}

bst::bnode* bst::remove_help(bst::bnode* n, int val)
{
    if (n)
    {
        if (n->data < val)      n->right = remove_help(n->right, val);
        else if (n->data > val) n->left = remove_help(n->left, val);
        else
        {
            this->sz--;

            if (n->left == nullptr && n->right == nullptr)  n = nullptr;
            else if (n->left == nullptr)                    n = n->right;
            else if (n->right == nullptr)                   n = n->left;
            else
            {
                
            }
        }
    }
    return n;

}

bool bst::is_present(int i)
{
    return is_present_help(this->root, i);
}

bool bst::is_present_help(bst::bnode *node, int i)
{
    if (!node) return false;

    if (node->data == i) return true;
    else if (node->data < i) return is_present_help(node->left, i);
    else return is_present_help(node->right, i);
}

size_t bst::size()
{
    return this->sz;
}

int bst::max()
{
    if (this->root == nullptr) throw std::invalid_argument("cannot call max() on empty tree");

    bnode* ptr = this->root;
    while (ptr->right != nullptr) ptr = ptr->right;

    return ptr->data;
}

int bst::min()
{
    if (this->root == nullptr) throw std::invalid_argument("cannot call min() on an empty tree");

    bnode* ptr = this->root;
    while (ptr->left != nullptr) ptr = ptr->left;

    return ptr->data;
}

int bst::height()
{
    return height_help(this->root);
}

int bst::height_help(bnode* n)
{
    if (!n) return -1;

    int l = height_help(n->left);
    int r = height_help(n->right);

    return 1 + (l < r ? r : l);
}

// code adapted from geeks for geeks - only
// used internally for testing purposes
// not to be included in usage
void bst::print()
{
    printutil(this->root, 0);
}

void bst::printutil(bst::bnode *node, int space)
{
    if (node)
    {
        space += SPACE;
        printutil(node->right, space);

        std::cout << std::endl;
        for (int i = SPACE; i < space; i++)
            std::cout << " ";
        std::cout << node->data << std::endl;

        printutil(node->left, space);
    }
}
