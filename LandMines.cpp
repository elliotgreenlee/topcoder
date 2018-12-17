#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Node {
   public:
      int index;
      int visited;
      vector <Node *> adj;
};

class LandMines {
   public:
      vector <Node *> nodes;
      int numClear(vector <string> layout);
      void DFS(int index, int &cn);
};




int LandMines::numClear(vector <string> layout) {
   
   Node * newNode;
   int cn = 0;
   bool mine;
   
   //create all the nodes
   
   for (int i = 0; i < layout.size(); i++) {
      for (int j = 0; j < layout[i].length(); j++) {
         newNode = new Node;
         newNode->index = (i * layout[i].length() + j);
         newNode->visited = 0;
         nodes.push_back(newNode);
      }
   }

   for (int i = 0; i < layout.size(); i++) {
      for (int j = 0; j < layout[i].length(); j++) {
      if (j != layout[i].length()-1) {
         mine = false;
         for (int k = j+1; k < layout[i].length(); k++) {
            //check ones to the right for a mine
            if (layout[i][k] == 'M') {
               mine = true;
            }
         }
         if (mine) {
         }
         else {
            nodes[i * layout[i].length() + j]->adj.push_back(nodes[i*layout[i].length() + j + 1]);
         }         
      }
      if (j != 0) {
         mine = false;
         for (int k = j-1; k >= 0; k--) {
            //check ones to the left for a mine
            if (layout[i][k] == 'M') {
               //no edge
               mine = true;
            }
           
         }
         if (mine) {
         }
         else {
            nodes[i * layout[i].length() + j]->adj.push_back(nodes[i*layout[i].length() + j - 1]);
         }
      }
      if (i != layout.size()-1) {
         mine = false;
         for (int k = i+1; k < layout.size(); k++) {
            //check ones below for a mine
            if (layout[k][j] == 'M') {
               mine = true;
            }
                     
         }
         if (mine) {
         }
         else {
            nodes[i*layout[i].length() + j]->adj.push_back(nodes[(i+1)*layout[i].length() + j]);
         }   
      }
      if (i != 0) {
         mine = false;
         for (int k = i-1; k >= 0; k--) {
            //check ones above for a mine
            if (layout[k][j] == 'M') {
               mine = true;
            }
            
         }
         if (mine) {
         }
         else {
            nodes[i*layout[i].length() + j]->adj.push_back(nodes[(i-1)*layout[i].length() + j]);            
         }
      }
      }
   }
   
   DFS(0, cn);

   return cn;
}

void LandMines::DFS(int index, int &cn) {

   Node *n;
   int i;
   
   n = nodes[index];
   if (n->visited == 1) {
      return;
   }
   
   cn++;
   n->visited = 1;
   
   for (i = 0; i < n->adj.size(); i++) {
      DFS(n->adj[i]->index, cn);
   }

   return;
}