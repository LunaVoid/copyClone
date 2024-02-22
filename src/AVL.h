//
// Created by Josh on 2/16/24. //

#include <string>
#include <queue>
using namespace std;
#ifndef PROJECT1_AVL_H
#define PROJECT1_AVL_H


class AVL {
    private:
        static AVL* mainTree;

        struct Node{
            int height;
            string ufid;
            string name;
            Node* left;
            Node* right;
            Node(string name, string ufid): ufid(ufid), name(name), left(nullptr), right(nullptr){};
            //tests
        };
        Node* mainRoot = nullptr;
        Node* search(Node* root,const string& ufid);
        AVL::Node* insertNode(Node* root, const string& name, string ufid);
        Node* getRoot();
        void inorderTraversal(Node* root,vector<string>& result);
        int getHeight(AVL::Node* node);
        vector<string> levelOrderTraversal(queue<Node*>& test,vector<string>&traverse);

    public:

        static AVL* getInstance();
        vector<string> traverseWrapper();
        vector<string> levelOrderWrapper();
        void resetTree();
        string returnName(const string& ufid);
        bool insertWrapper(const string &name, const string &ufid);

    int pullBalance(Node *node);
};


#endif //PROJECT1_AVL_H
