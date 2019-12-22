//
// Created by Amogh on 12/13/19.
//

#ifndef FOREST_BST_H
#define FOREST_BST_H

#include <vector>
#include <iostream>
#include <exception>
#include <random>

class bst
{
public:
    bst();
    ~bst();

    bool add(int i);
    bool remove(int i);
    bool is_present(int i);
    size_t size();
    int height();
    int max();
    int min();
    void print();

private:
    struct bnode
    {
        int data;
        bnode* left;
        bnode* right;

        bnode(int i = 0, bnode* l = nullptr, bnode* r = nullptr)
        {
            data = i;
            left = l;
            right = r;
        }

        ~bnode()
        {
            if (left) delete left;
            if (right) delete right;
        }
    };

    bnode* root;
    size_t sz;

    bnode* add_help(bnode* node, int val);
    bnode* remove_help(bnode* n, int val);
    static bool is_present_help(bnode* node, int i);
    static void print_help(bnode* node, int space);
    static int height_help(bnode* n);
    static int max(bnode* n);
    static int min(bnode* n);

    // output formatting
    static const int SPACE = 10;
};

#endif //FOREST_BST_H
