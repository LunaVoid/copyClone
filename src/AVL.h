//
// Created by luna on 2/16/24.
//
#include <string>
using namespace std;
#ifndef PROJECT1_AVL_H
#define PROJECT1_AVL_H


class AVL {
    struct Node{
        int height;
        string ufid;
        string name;
        Node* left;
        Node* right;
        Node(string ufid, string name): ufid(ufid), name(name), left(nullptr), right(nullptr){};

    };

    Node* insertNode
};


#endif //PROJECT1_AVL_H
