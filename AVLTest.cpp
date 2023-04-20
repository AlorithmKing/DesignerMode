//
// Created by 24091 on 2023-04-20.
//
#include <iostream>

#include "AVLTree.h"

using namespace std;

static int arr[] = {3, 2, 1, 4, 5, 6, 7, 16, 15, 14, 13, 12, 11, 10, 8, 9};
#define TBL_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )

int main() {
    int i, ilen;
    auto *tree = new AVLTree<int>();

    cout << "== add one by one: ";
    ilen = TBL_SIZE(arr);
    for (i = 0; i < ilen; i++) {
        cout << arr[i] << " ";
        tree->insert(i,arr[i]);
    }

    cout << "\n== PreOrder: ";
    tree->preOrder();

    cout << "\n== InOrder: ";
    tree->inOrder();

    cout << "\n== PostOrder: ";
    tree->postOrder();
    cout << endl;

    cout << "== height: " << tree->height() << endl;
    cout << "== minvalue: " << tree->minimum() << endl;
    cout << "== maxvalue: " << tree->maximum() << endl;
    cout << "== TreeInfo: " << endl;
    tree->print();

    i = 8;
    cout << "\n== deleteRoot: " << i;
    tree->remove(i);

    cout << "\n== height: " << tree->height();
    cout << "\n== InOrder: ";
    tree->inOrder();
    cout << "\n== TreeInfo: " << endl;
    tree->print();

    // 销毁二叉树
    tree->destroy();

    return 0;
}