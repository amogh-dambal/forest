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
    size_t oldsz = this->sz;
    root = add_help(root, i);
    return oldsz != this->sz;
}

bst::bnode* bst::add_help(bst::bnode *node, int val)
{
    if (!node)
    {
        this->sz++;
        return new bnode(val);
    }

    if (node->data > val)
    {
        node->left = add_help(node->left, val);
    }
    else if (node->data < val)
    {
        node->right = add_help(node->right, val);
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

            if (n->left == nullptr && n->right == nullptr)
            {
                delete n;
                return nullptr;
            }
            else if (n->left == nullptr)
            {
                bnode* ptr = n->right;
                delete n;
                return ptr;
            }
            else if (n->right == nullptr)
            {
                bnode* ptr = n->left;
                delete n;
                return ptr;
            }
            else
            {
                std::random_device rd;
                std::mt19937 eng(rd());
                std::uniform_int_distribution<> uid(0, 1);

                int choice = uid(eng);
                int r = choice == 0 ? max(n->left) : min(n->right);

                n->data = r;
                if (choice == 0)    n->left = remove_help(n->left, r);
                else                n->right = remove_help(n->right, r);

                // offset size increment made by remove_help calls
                this->sz++;
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

    return max(this->root);
}

int bst::min()
{
    if (this->root == nullptr) throw std::invalid_argument("cannot call min() on an empty tree");

    return min(this->root);
}

int bst::max(bst::bnode* n)
{
    bnode* ptr = n;
    while (n->right != nullptr) n = n->right;
    return n->data;

}

int bst::min(bst::bnode* n)
{
    bnode* ptr = n;
    while (n->left != nullptr) n = n->left;
    return n->data;
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
    print_help(this->root, 0);
}

void bst::print_help(bst::bnode *node, int space)
{
    if (node)
    {
        space += SPACE;
        print_help(node->right, space);

        std::cout << std::endl;
        for (int i = SPACE; i < space; i++)
            std::cout << " ";
        std::cout << node->data << std::endl;

        print_help(node->left, space);
    }
}
