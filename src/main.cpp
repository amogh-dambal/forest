//
// Created by Amogh on 12/13/19.
//

#include <iostream>
#include "../include/bst.h"

int main(int argc, char** argv)
{
    bst* tree = new bst();
    std::cout << "Hello, world!" << std::endl;

    tree->add(2);
    tree->add(6);
    tree->add(-1);

    std::cout << tree->is_present(4) << " "
    << tree->is_present(2) << std::endl;

    delete tree;
}
