//
// Created by Amogh on 12/13/19.
//

#include "../include/bst.h"

#include <random>
#include <chrono>

using namespace std;

int main(int argc, char** argv)
{
    bst tree;
    const int N = 10000;

    // add 100 random numbers to tree
    random_device rd;
    mt19937 eng(rd());
    uniform_int_distribution<> uid(0, 1000);

    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++)
    {
        int k = uid(eng);
        tree.add(k);
    }
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> time = (end - start);
    cout << "time for " << N << " add operations (naive algorithm): " << time.count() << endl;

    cout << "max of tree: " << tree.max() << endl;
    cout << "min of tree: " << tree.min() << endl;
    cout << "height of tree: " << tree.height() << endl;
    cout << "size of tree: " << tree.size() << endl;

    tree.print();
}
