#include "Graph.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "file_read.h"
#include <fstream>
using std::list;
using std::vector;
using std::string;


Graph::Graph(const string& d){
    readVertex(d);
    data = d;
    adj = new list<int>[vertex[vertex.size()-1]+1];
    vertex_c = vertex[vertex.size()-1]+1;
    makeadj2(d);
    readEdge(d);
    
}


void Graph::copy(const Graph& other)
{
    data = other.data;
    vertex_c = other.vertex_c;
    adj = new list<int>[vertex_c];
    for ( int v = 0; v < vertex_c; v++){
        adj[v] = other.adj[v];
    }
    vertex.assign(other.vertex.begin(),other.vertex.end());

}

Graph& Graph::operator=(const Graph& other)
{
    if (this != &other) {
        clear();
        copy(other);
    }
    return *this;
}

Graph::Graph(int v){
    vertex_c = v;
    for( int i =0; i <vertex_c; i++){
        vertex.push_back(i);
    }
    adj = new list<int>[v];
}
    
Graph::Graph(){
}

void Graph::clear(){
    if ((adj->empty())){
        delete[] adj;
    }
    adj = NULL;
}
Graph::~Graph() { 
     clear();

}


void Graph::printadj(){
    std::ofstream myfile;
    myfile.open ("/workspaces/cs225/Final_Project/output/tpep");
    list<int>::iterator i;
    for (unsigned int v = 0; v < vertex.size(); v++)
    {
       std::cout << v << std::endl;
       myfile << v << " -> ";
       std::cout << vertex[v] << " -> ";
        for (i = adj[vertex[v]].begin(); i != adj[vertex[v]].end(); ++i){
            std::cout<< ' ' << *i;
            myfile << ' ' << *i;
        }
            std::cout<< std::endl;
            myfile << std::endl;
    }
    myfile.close();
}

void Graph::printedge(){
    std::ofstream myfile;
    myfile.open ("/workspaces/cs225/Final_Project/output/edges_output");
    for(int i= 0; i<vertex_c; i++){
        myfile << adjvect[i][0];
        myfile <<  " -> ";
        myfile <<  adjvect[i][1] << std::endl;
    
    }
    myfile.close();
}

void Graph::insertVertex(int k){
    vertex.push_back(k);
}

void Graph::insertEdge(int v, int w){
    adj[v].push_back(w);
}

Graph Graph::getTranspose()
{
	Graph g(vertex.size());
	for (unsigned int v = 0; v < vertex.size(); v++)
	{
		list<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); ++i)
			g.adj[*i].push_back(v);
	}
	return g;
}


void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    sscrow.push_back(v);
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
      if (!visited[*i])
        DFSUtil(*i, visited);
}
void Graph::sscrowclear(){
    sscrow.clear();
}
vector<int> Graph::sscrowget(){
    return sscrow;
}

void Graph::makeadj2(const string& data){
    string t;
    string first;
    string adjtemp = "";
    list<int> ab;
    vector<int> row;
    for (unsigned int i=0; i<= data.size() ; i++){
        if (data[i] == '\t'){
           break;}
        first = first+ data[i];
     }

    adjtemp = first;
    int beta = stoi(adjtemp);
    row.push_back(beta);
    for (unsigned int i=0; i< data.size() ; i++){
        if (data[i]!='\t' && data[i]!='\n'){
            t = t+ data[i];
        }
        else if(data[i]== '\t' ){
            if(adjtemp != t){
                int oldtem = stoi(adjtemp);
                int newtem = stoi(t);
                adjvect.push_back(row);
                row.clear();
                if(newtem > oldtem + 1){
                    for(int i = oldtem+1; i < newtem; i++){
                        row.push_back(i);
                        adjvect.push_back(row);
                        row.clear();
                        
                    }
                }
                row.push_back(newtem);
                adjtemp = t;
            }
            t = "";
        }
        else if(data[i]== '\n'){
            int verint = stoi(adjtemp);
            int edgeint = stoi(t);
            
            insertEdge(verint, edgeint);
            row.push_back(edgeint);
            t="";
        }

    }
    adjvect.push_back(row);
}


void Graph::readVertex(const string& data){
    string t = "";
    string adjtemp;

    for (unsigned int i=0; i< data.size(); i++){
        if (data[i]!='\t' && data[i]!='\n'){
            t = t+ data[i];
        }
        else if(data[i]== '\t'){
            adjtemp = t;
            t = "";
        }
        else if(data[i] == '\n'){
            t = "";
        }
    }
    int size = stoi(adjtemp);
    vertex.clear();
    for(int i =0 ; i<size+1; i++){
        vertex.push_back(i);
    }
}

void Graph::readEdge(const string& data){
    
    string temp = "";
    string t = "";
    for (unsigned int i=0; i< data.size(); i++){
        if (data[i]!='\t' && data[i]!='\n'){
            t = t+ data[i];

        }
        else if(data[i]== '\t'){
            row.push_back(t);
            temp = t;
            t = "";
        }
        else if(data[i]== '\n'){
     
            row.push_back(t);
            row.push_back(temp + "_" + t);
            edges.push_back(row);
            row.clear();
            t="";
            temp ="";
        }
    }

}   

vector<vector<string> >  Graph::getEdges(){
    return edges;}

list<int>* Graph::getAdj(){ 
    return adj;}

vector<int>  Graph::getvertex(){
    return vertex;}

vector<vector<int> > Graph::getadj2(){
    return adjvect;}
    
int Graph::versize(){
    return vertex[vertex.size()-1]+1 ;}