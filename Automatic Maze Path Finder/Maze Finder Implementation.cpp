//
//  Maze Finder Implementation.cpp
//  Automatic Maze Path Finder
//
//  Created by Patrick M. Bush on 10/26/15.
//  Copyright © 2015 Lead Development Co. All rights reserved.
//

#include "Maze Finder Interface.hpp"

/**
-------------------------------------------------------------------
                  Node Class Implementation
-------------------------------------------------------------------
*/


Node::Node() {
    
}

Node::Node(string newName) {
    name = newName;
}

string Node::getNodeName() {
    return name;
}

void Node::setNodeName(string newName) {
    name = newName;
}

bool Node::attachNewNode(Node *newNode, int direction) {
    attachedNodes[direction] = newNode;
    if (attachedNodes[direction] != NULL) {
        return true;
    }
    
    return false;
}

Node* Node::getAttachedNode(int direction) {
    return attachedNodes[direction];
}

/**
 -------------------------------------------------------------------
                     Graph Class Implementation
 -------------------------------------------------------------------
 */

Graph::Graph() {
    
}

Graph::Graph(int graphSize) {
    size = graphSize;
    graph = new Node[graphSize];
    graphIndex = 0;
}

void Graph::addNode(Node *nodeToAdd) {
    graph[graphIndex] = *nodeToAdd;
    graphIndex++;
}

vector<Node*> Graph::getNeighbors(Node *current) {
    vector<Node*> neighbors;
    for (unsigned long i = 0; i < 4; i++) {
        neighbors[i] = current->getAttachedNode(i);
    }
    
    return neighbors;
}


/**
 -------------------------------------------------------------------
                      Menu Class Implementation
 -------------------------------------------------------------------
 */

void Menu::printHeader() {
    cout << "======================================================\n";
    cout << "|      Welcome to the Automatic Maze Path Finder!     |\n";
    cout << "======================================================\n";
}

string Menu::printFileMenu() {
    string fileName;
    cout << "\nEnter the name of the Maze configuration file: ";
    getline(cin, fileName);
    return fileName;
}

void Menu::printNodeInformation(Node *startNode, Node *endNode) {
    cout << "The start node is: " << startNode->getNodeName() << "\n";
    cout << "The destination node is: " << endNode->getNodeName() << "\n";
    cout << "Finding a path from the Start to the Destination node...\n";
}

void Menu::printNodePath(deque<Node> *nodePath) {
    cout << "Congratulations, found a path successfully\n";
    cout << "The path is: ";
    for (deque<Node>::iterator it = nodePath->begin(); it != nodePath->end(); ++it) {
        cout << it->getNodeName();
    }
}

void Menu::printFooter() {
    cout << "======================================================\n";
    cout << "| Thank you for using the Automatic Maze Path Finder! |\n";
    cout << "======================================================\n";}
