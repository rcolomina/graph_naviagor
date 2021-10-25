#include "node.h"
#include "scene.h"

#include <iostream>
#include <list>
#include <queue>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

template<typename T>
void appendNeigbors(list<string> places,Node<T> *basePlace){    
    for(list<string>::iterator it=places.begin();
        it!=places.end();
        ++it)        
        basePlace->addNode(new Node<T>(*it));        
}

template<typename T>
void addNodesQueue(queue<Node<T>*> &queueNodes,list<Node<T>*> nodes){
    for(typename list<Node<T>*>::iterator it=nodes.begin();
        it!=nodes.end();
        ++it){
        cout<<"I can go to "<<(*it)->getName()<<endl;
        queueNodes.push(*it);
    }
}

bool visited(vector<string> nodesVisited,string item){
    return find(nodesVisited.begin(),nodesVisited.end(),item) != nodesVisited.end();
}

// Walk All Nodes using Best First Search strategy
template<typename T>
void walkNodes(Node<T> *basepNode){
    cout<<"Walk nodes in Best First Search strategy"<<endl;
    queue<Node<T> *> queueNodes;
    vector<string> nodesVisited;
    
    list<Node<T>*> nodes=basepNode->getListNodes();
    cout<<"From "<<basepNode->getName()<<endl;
    nodesVisited.push_back(basepNode->getName());
    addNodesQueue(queueNodes,nodes);
    
    while(!queueNodes.empty()){
        Node<T>* node=queueNodes.front();        
        queueNodes.pop();
        
        list<Node<T>*> newListNodes=node->getListNodes();
        if(newListNodes.size()>0 and !visited(nodesVisited,node->getName())){
            cout<<"From "<<node->getName()<<endl;            
            addNodesQueue(queueNodes,newListNodes);
        }
        nodesVisited.push_back(node->getName());                    
    }
    cout<<" "<<endl;
    cout<<"Printing Visited Nodes"<<endl;
    for(auto it=nodesVisited.begin();
        it!=nodesVisited.end();
        ++it)
        cout<<*it<<endl;    
}        

class Connection {
    public:
        Connection(string o,string d,string c,bool v,bool op):
            origin_id(o),destiny_id(d),cardinal(c),visible(v),open(op){}
        string origin_id;
        string destiny_id;
        string cardinal;
        bool visible;
        bool open;
};

int main(){

    pIntNode nodeBase = new intNode("home");

    list<string> placesToGo = {"tesco","office","mall"};;
    appendNeigbors(placesToGo,nodeBase);

    pIntNode tescoNode = nodeBase->getNeighbourName("tesco");
    pIntNode officeNode = nodeBase->getNeighbourName("office");
    pIntNode mallNode = nodeBase->getNeighbourName("mall");
    
    appendNeigbors({"bakery","beberages","meats"},tescoNode);    
    appendNeigbors({"desktop","kitchen","cantine","toilet"},officeNode);    
    appendNeigbors({"McDonals","Cafe","Wilko"},mallNode);

    pIntNode wilkoNode = mallNode->getNeighbourName("Wilko");
    appendNeigbors({"electricity","painting","cars"},wilkoNode);
    
    walkNodes<int>(nodeBase);

    //// Test NodeScene
    cout<<" "<<endl;
    cout<<"Testing NodeScene"<<endl;
    map<string,NodeScene*> myWorld;

    // TODO: Load scenes names and ids from somewhere
    list<pair<string,string> > mySceneNamesIds = {{"Entry to Great Cave!",
                                                "great_cave_node"},
                                               {"Interior of Great Cave!",
                                                "int_great_cave"},
                                               {"Entry tunnels into the dark deep.",
                                                "entry_tunnels_dark_deep"}};

    for(auto it=mySceneNamesIds.begin();
        it!=mySceneNamesIds.end();
        ++it){
        Scene newScene(it->first);  // TODO: Scene build can be as complex as you want
        myWorld[it->second] = new NodeScene(it->second,newScene); 
    }

    // TODO: Load connections from somewhere    
    Connection connect1("great_cave_node","int_great_cave","north",true,true);
    Connection connect2("int_great_cave","entry_tunnels_dark_deep","east",true,true);
    
    list<Connection> listConnections;
    listConnections.push_back(connect1);
    listConnections.push_back(connect2);
    
    for(auto it=listConnections.begin();
        it!=listConnections.end();
        ++it){
        string origin=(*it).origin_id; 
        string destiny=(*it).destiny_id;
        string cardinal=(*it).cardinal;
        bool visible=(*it).visible;
        bool open=(*it).open;
        //cout<<"origin"<<origin<<endl;
        NodeScene *myNodeSceneOrigin  = myWorld[origin];
        NodeScene *myNodeSceneDestiny = myWorld[destiny];
        
        myNodeSceneOrigin->setExit(myNodeSceneDestiny,cardinal,visible,open);
    }
    
    walkNodes(myWorld["great_cave_node"]);
    
}
    
