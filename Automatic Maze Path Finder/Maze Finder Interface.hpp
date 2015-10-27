//
//  Maze Finder Interface.hpp
//  Automatic Maze Path Finder
//
//  Created by Patrick M. Bush on 10/26/15.
//  Copyright © 2015 Lead Development Co. All rights reserved.
//

#ifndef Maze_Finder_Interface_hpp
#define Maze_Finder_Interface_hpp

#include <stdio.h>
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

class Node {
public:
    Node(string newName);
    Node();
    string getNodeName();
    void setNodeName(string newName);
    bool attachNewNode(Node * newNode, int direction);
    Node *getAttachedNode(int direction);
    bool visited;
private:
    string name;
    Node *attachedNodes[4];
    
};

class Graph {
public:
    Graph();
    Graph(int graphSize);
    void addNode(Node *nodeToAdd);
    vector<Node*> getNeighbors(Node *current);
    void createGraph();
private:
    size_t size;
    Node* graph;
    size_t graphIndex;
};

class Menu {
public:
    void printHeader();
    string printFileMenu();
    void printNodeInformation(Node *startNode, Node *endNode);
    void printNodePath(deque<Node> *nodePath);
    void printFooter();
};

class System {
public:
    deque<Node>* searchMaze(Graph *currentGraph, Node *startNode, Node *endNode);
    bool readMazeFile(string fileName);
    bool constructGraph();
private:
    deque<Node>* mazeChain;
    Node* startNode;
    Node* endNode;
    Graph *currentGraph;
    
};



#endif /* Maze_Finder_Interface_hpp */
