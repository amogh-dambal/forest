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

    // testing remove
    std::cout << tree->remove(2) << std::endl;
    std::cout << tree->remove(-4) << std::endl;

    tree->print();
    delete tree;
}
