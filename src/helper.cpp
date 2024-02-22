//Citations: https://stackoverflow.com/questions/5888022/split-string-by-single-spaces (string splits)
//https://www.onlinegdb.com/fork/x9xvFQIcG regex code examples.
//https://stackoverflow.com/questions/25020129/cin-ignorenumeric-limitsstreamsizemax-n
#include <iostream>
#include "AVL.h"
#include "helper.h"
#include "sstream"
#include <regex>
using namespace std;


bool validateName(string name){
    std::regex obj = std::regex("^[a-z\\s]+$",std::regex_constants::icase);
    bool isValid = std::regex_search(name, obj);
    return isValid;
}

bool validateUFID(string ufid){
    std::regex obj = std::regex("^\\d{8}$",std::regex_constants::icase);
    bool isValid = std::regex_search(ufid, obj);
    return isValid;
}


bool insertInto(string name, string ufid){
    if(!validateName(name)||!validateUFID(ufid)){
        cout<<"unsuccessful"<<endl;
        return false;
    }
    else{
        //Insert Here
        AVL* tree = AVL::getInstance();
        auto value = tree->insertWrapper(name,ufid);
        cout<<value<<" value"<<endl;
        return true;
    }

}

void printName(string ufid){
   AVL* tree = AVL::getInstance();
   cout<<tree->returnName(ufid)<<endl;
   //auto pointer = tree->(ufid);
}

void startUp(){
        int totalCommands = 1;
        try{
            cin>>totalCommands;
            if(!cin)
                throw "error";
        }
        catch(...){
            cout<<"Invalid Number Error"<<endl;
        }
//insert "Brandon" 45679999
    while(totalCommands!=0){
        string fullLine;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin,fullLine);
        istringstream in(fullLine);

        string command;
        in>>command;

        if(command == "insert"){

            string name;
            getline(in,name,'"');
            in>>name;

            string ufid;
            getline(in,ufid,'"');
            in>>ufid;

            //Remove the trailing "
            name.pop_back();
            //Remove begining space
            if(ufid[0] == ' '){
                ufid.erase(0,1);
            }
            insertInto(name,ufid);

        }

        totalCommands-=1;

    }
}

