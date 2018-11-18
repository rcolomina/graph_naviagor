#ifndef _node_
#define _node_

#include <string>
#include <list>
#include <map>
#include <iostream>

using namespace std;

template<class T>
class Node;
typedef Node<int> intNode;
typedef intNode* pIntNode;
typedef list<pIntNode> listpNodesInt;

template<class T>
class Node {
public:
    Node(){}
    Node(string name):name(name){}
    Node(string name,T value):
        name(name),value(value){}
    
    void addNode(Node<T> *node);
    string getName(){return name;}
    list<Node<T>*> getListNodes(){return listNodes;}
    Node<T>* getNeighbourName(string name);    
    T getValue(){return value;}    
protected:
    list<Node<T>*> listNodes;  // list of neighbours
    map<string,Node<T>*> mapNodes; // access via name to neighbours
    string name;
    T value;
};

template<typename U>
void Node<U>::addNode(Node<U> *node){
    listNodes.push_back(node);
    string name=node->getName();
    this->mapNodes[name]=node;
}

template<typename U>
Node<U>* Node<U>::getNeighbourName(string name){
    // Get neighbour by name
    try{
        if(mapNodes[name] != NULL)
            return mapNodes[name];
        else
            throw "Error accessing map of nodes. "+name+" key was not found";
    }
    catch(string e)
    {
        cout<<e<<endl;
    }
    return NULL;
}



#endif

