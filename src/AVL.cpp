// Created by Josh on 2/16/24.
//
#include <iostream>
#include "AVL.h"
#include <vector>
#include <algorithm>
#include <queue>
//Private

AVL::Node* AVL::search(Node* root, const string& ufid){
    if(root == nullptr){
        return nullptr;
    }

    else if(ufid == root->ufid){
        //Value already entered
        return nullptr;
    }
    //Left tree
    else if(ufid<root->ufid){
        cout<<"Left"<<endl;
        return search(root->left,ufid);
    }

    else if(ufid>root->ufid){
        cout<<"Right"<<endl;
        return search(root->right,ufid);
    }
    else{
        return root;
    }
}

AVL::Node* AVL::insertNode(AVL::Node *root, const std::string& name, std::string ufid) {
   if(root == nullptr && mainRoot == nullptr){
       root = new Node(name,ufid);
       //zero indexed
       root->height = 0;
       mainRoot = root;
       return root;
   }
   else if(root == nullptr){
       root = new Node(name, ufid);
       return root;
   }
   else if(ufid.compare(root->ufid)<0){
       root->left = insertNode(root->left,name,ufid);
   }
   else if(ufid.compare(root->ufid)>0){
       root->right = insertNode(root->right,name,ufid);
   }
   //cout<<ufid.compare(root->ufid)<<endl;
   //cout<<"test"<<endl;
   else
       return root;
   //We need to update heights now
   root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));
   //We have 4 different cases for rotations now, left, right, left-right and right-left
   //If the balance at the current node is >1 (2) and if the ufid is less than
   if(pullBalance(root)>1){
       //Left heavy
       cout<<"Left alone Case!"<<endl;
        //+2 -1 case is Left right
       if(pullBalance(root)<0){

       }

   }
   else if(pullBalance(root)<-1){
       //Right heavy
       cout<<"Right alone Case!"<<endl;
       //-2 +1 case is Right-Left
       if(pullBalance(root->right)>0){
           //Right-Left case!
           cout<<"Right-Left Case!"<<endl;
       }
   }

   return root;
}

int AVL::pullBalance(AVL::Node* node){
    if(node == nullptr){
        return 0;
    }
    //returns the balance
    return ((getHeight(node->left))-(getHeight(node->right)));
}
//Deals with nullptr/0 height
int AVL::getHeight(AVL::Node* node){
    if(node == nullptr){
        return 0;
    }
    else{
        return node->height;
    }
}


AVL::Node* AVL::getRoot(){
    return mainRoot;
}



void AVL::inorderTraversal(Node* root, vector<string>& result){
    if(root== nullptr){
        return;
    }
    inorderTraversal(root->left,result);

    result.push_back(root->ufid);

    inorderTraversal(root->right,result);

}

vector<string> AVL::levelOrderTraversal(queue<AVL::Node*>&test,vector<string>&traverse){
    if(test.front()!=nullptr){
        traverse.push_back(test.front()->ufid);
        if(test.front()->left!= nullptr){
            test.push(test.front()->left);
        }
        if(test.front()->right!= nullptr){
            test.push(test.front()->right);
        }

        //pop the front
        test.pop();
        //We go again to the next level
        levelOrderTraversal(test,traverse);

    }
    else{
        return traverse;
    }


    return traverse;
}





//------


//Public

AVL* AVL::mainTree = nullptr;

AVL* AVL::getInstance(){
    if(mainTree == nullptr){
        mainTree = new AVL();
        return mainTree;
    }
    else{
        return mainTree;
    }
}
//I'm using the singlton pattern but for tests I just create a new tree but just in case we can reset the tree
//This is a debug method and should NOT be used doesn't properly destruct previous tree
void AVL::resetTree(){
    mainTree = nullptr;
}

bool AVL::insertWrapper(const std::string &name, const std::string &ufid) {
    vector<string> transversal = traverseWrapper();
    int counter = count(transversal.begin(),transversal.end(),ufid);
    if(counter>0){
        return false;
    }
    AVL::Node* inserted = insertNode(mainRoot,name,ufid);

    if(inserted){
        return true;
    }
    else{
        return false;
    }
}

vector<string> AVL::traverseWrapper(){
    vector<string>traverse;
    inorderTraversal(getRoot(),traverse);
    return traverse;
}

vector<string> AVL::levelOrderWrapper(){
    vector<string>order;
    queue<Node*>queue;
    //Push the first node into the queue
    queue.push(getRoot());
    vector<string>levelOrder = levelOrderTraversal(queue,order);
    return levelOrder;
}

string AVL::returnName(const string& ufid){
   Node* nodeFound = search(mainRoot,ufid);
   if(nodeFound == nullptr){
       return "unsuccessful";
   }
   else{
       return nodeFound->name;
   }
}




