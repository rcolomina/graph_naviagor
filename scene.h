#ifndef _scene_
#define _scene_

#include "node.h"

// Text for something, can be configured in different languages
class Text{
public:
    Text(){}
    Text(string text){}
    Text(string lang,string text){}    
private:    
    map<string,string> langText; // TODO: Define enumerate for languages e.g. en,es,fr,pr
};

// Item on a scene
class Item {
public:
    Item(string name){}
    // TODO: Start to create a hieratchy of items
private:
    int id;
    Text name;
    Text description;
};

class Scene {
public:
    Scene(){}
    Scene(string name):name(name){}
    Scene(int id,Text introtext):id(id),introtext(introtext){}

    string getName(){return name;}
public:    
    int id;
    string name;
    Text introtext;
    list<Item*> itemsScene;
};

class Cardinal{
public:
    Cardinal(int id,string name,Text textname){}
private:
    int id;         // TODO: Define enumerate 
    string name;    // English default: North, Sourth, East, West,...
    Text textname;  // different languages for a cardinal
    bool open;
    bool visible;
};

class NodeScene: public Node<Scene> {
public:
    NodeScene(string name,Scene scene):Node<Scene>(name){
        this->value = scene;
    }

    // TODO: Cardinal/Connection should store information on how is the relationship between NodeScenes
    void setExitWithCardinal(NodeScene *nodeScene,Cardinal cardinal){
        this->addNode(nodeScene);
    }

    // This is a simples version to create connections between NodeScenes
    void setExit(NodeScene *nodeScene,string direction,bool visible,bool open){
        this->addNode(nodeScene);
        directions[direction]=nodeScene;
        visibleDirections[direction]=visible;
        openDirections[direction]=open;        
    }

private:
    // Store directions for each connection
    map<string,NodeScene*> directions;    
    map<string,bool> openDirections;
    map<string,bool> visibleDirections;

    // TODO: Simplified this using a connections/cardinal class
    // list<Cardinal> cardinals;
};

#endif
