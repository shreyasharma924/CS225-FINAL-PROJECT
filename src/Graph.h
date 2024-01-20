
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
using std::stack;
using std::list;
using std::vector;
using std::string;

class Graph{
    public:
    /* 
    * Default constructor
    */
    Graph(); 
    /* 
    * constructor which inputs the meta deta with string d
    * */
    Graph(const string& d);
    /* 
    * constructor which inputs the number of verteices.
    * */
    Graph(int v);
    /* 
    * clear, deletes the data
    * */
    void clear();
    /* 
    * operator overloader for Graph function (rule of three)
    * */
    Graph& operator=(const Graph& other);
    /* 
    * copy operator
    * */
    void copy(const Graph& other);
    /* 
    * inserts vertex in the vertex vector
    * */
    void insertVertex(int k);
    /* 
    * returns the number of vertices of the graph
    * */
    int versize();
    /* 
    * A read function which takes the data and reads all the vertex to fill the vertex vector.
    * */
    void readVertex(const string& data);
    /* 
    * A read function which takes the data and reads all the edges to fill the edge 2D vector.
    * */
    void readEdge(const string& data);
    /* 
    * prints all the edges of the graph into a file.
    * */
    void printedge();
    /* 
    * prints all the edges of the graph into a file.
    * */
    void printadj();
   /* 
    * inserts the adjecent edges in the adjcency list
    * */
    void insertEdge(int v, int w);
    /* 
    * A read function which takes the data and reads all the adjecenct nodes to fill the adj array of list.
    * */
    void makeadj2(const string& data);
    /* 
    * DFS function for the strongly connected component
    * */
    void DFSUtil(int v, bool visited[]);
    /* 
    * Transpose function for strongly connected component
    * */
    Graph getTranspose();

    ///////////////////////////////////////////////////////
    /* 
    * Getter function to return 2D vector of edges.
    * */
    vector<vector<string> >  getEdges();
    /* 
    * Getter function to return array of list of adjcency.
    * */
    list<int>* getAdj();
    /* 
    * cGetter function to return vector of vertex.
    * */
    vector<int> getvertex();
    /* 
    * Getter function to return 2D vector of adjcency.
    * */
    vector<vector<int> > getadj2();
    /* 
    * Getter function to get the single row of the stringly connected component after DFS
    * */
    vector<int> sscrowget();
    /* 
    * a clear function which clears the sscrow vector;
    * */
    void sscrowclear();
    /* 
    * destructor
    * */   
    ~Graph();

    private:
    
    vector<int> vertex;                 // 1-D vetor for storing vertex
    vector<vector<string> > edges;      // 2-D vector for edges
    vector<vector<int> > adjvect;       // 2-D implementation of adjcency matrix
    list<int> *adj;                     // array of list for adjcecny
    string data;                        // raw data
    vector<string> row;                 // for printing the rows in adjmatrix
    int vertex_c;                       // vertex count
    vector<int> sscrow;                 // for printing the rows in scc
};

