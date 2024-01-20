#pragma once
#include <iostream>
#include <string>
using std::pair;
#include "Graph.h"
using std::string;

/* Intput - the from which the distance is to be found.
*         - Graph on which the nodes are
*  Output - a vertor of distances.
*/ 
vector<int> distance(int v, Graph& obj1);

/* Intput - Graph on which the nodes are
*  Output - a 2D vector with all the strongly connected components
*           in each row.
*/ 
vector<vector<int> >  scc(Graph o);


/* Intput - number of iteration to calculate the rank.
*         - Graph on which the nodes are
*  Output - a vertor of pair of key and value (the probability of its importance)
*/ 
vector<pair<int, double> > pageRank(double n, Graph obj);


/* Intput - the 
*  Output - void
*  Prints the rank of the graph in a file
*/ 
void print_rank(vector<pair<int, double> > frank );


/* Intput - the from which the distance is to be found.
*         - stack to be filled for DFS.
*         - Graph on which the nodes are
*  Output - void
*  helpper function for the strongly connected component. 
*  Fills the stack.
*/ 
void fillStack(bool visited[], int v, std::stack<int> & s, Graph& g );


/* Intput - Graph on which the nodes are.
*  Output - void
*  This function prints the strongly connected compnents of the graph in a file.
*/ 
void printscc(Graph& obj);