#include <iostream>
#include <string>
#include <fstream>
#include "Algorithm.h"
#include "Graph.h"
#include "file_read.h"
using std::string;
using std::pair;
#include <algorithm>
#include <bits/stdc++.h>


vector<int> distance(int v, Graph& obj1)
{
  vector<int> vertex;
  vertex = obj1.getvertex();
  list<int>* adj = obj1.getAdj();
  vector<int> distance(vertex.size(), -1);
	list<int> queue;
  distance[v] =0;
  int dist = 0;
  queue.push_back(v);
  std::ofstream myfile;
  myfile.open ("/workspaces/cs225/Final_Project/output/BFS_distance");
  list<int>::iterator i;
  while (!queue.empty())
  {

    v = queue.front();
    queue.pop_front();
    dist = dist +1;
    for (i = adj[v].begin(); i != adj[v].end(); ++i){
      if (distance[*i] == -1){
          distance[*i] = dist;
          queue.push_back(*i);
      }
    }
    myfile << v << " at distance " << distance[v] <<'\n';
  }
  myfile.close();
  return distance;
  
}


int count =0;
void fillStack(bool visited[], int v, std::stack<int> & s, Graph& g )
{
    
    visited[v]= true; 
    list<int>::iterator i;
    list<int>* k = g.getAdj();
    for(i = k[v].begin(); i != k[v].end(); ++i)
    {
      if(!visited[*i]){
        fillStack(visited, *i,s, g);
      }
          
    }
    s.push(v);
}

vector<vector<int> > scc(Graph o)
{
  vector<vector< int> > components; 
  int V = o.versize();
  std::stack<int> st; 
  bool *visited = new bool[V];
  for(int i=0; i< V ; i++){
    visited[i]= false;
  }
 
  for(int i = 0; i < V; i++)
  {
        if(visited[i] == false)
        {
            fillStack(visited,i,st, o);
        }
      
  }
  Graph g = o.getTranspose();
 
    // Mark all the vertices as not visited (For second DFS)
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    // Now process all vertices in order defined by Stack
    while (st.empty() == false)
    {
        
        int v = st.top();
        st.pop();
 
        
        if (visited[v] == false)
        {
          
            g.DFSUtil(v, visited);
            components.push_back(g.sscrowget());
            g.sscrowclear();
        }

    }
    return components;
}

vector<pair<int, double> > pageRank(double n, Graph obj){
  vector<vector<int> > adjvect= obj.getadj2();
  vector<int> vertex;
  vertex = obj.getvertex();
  int vertex_c = vertex[vertex.size()-1] +1;

  double dampen= 0.85;
  double alpha = (1 - dampen) / vertex_c; 
  double fraction= 1/(double(vertex_c));
  vector<double> temp(vertex_c, fraction);
  vector<double> rank(vertex_c, 0.0);
  vector<pair<int, double> > finalrank;
  unsigned int size = adjvect.size();
  double old_rank;
  double result;
  
 
  for (int start =0; start< n; start++)
  {
    for(unsigned int z=0 ; z< rank.size(); z++){
            rank[z] = 0;
    }
   for (unsigned int i = 0; i < adjvect.size(); i++)
    {
      old_rank = temp[adjvect[i][0]];
      if(adjvect[i].size()==1)
      {
        double temp_rank = dampen*(old_rank/vertex_c);
       
        for(unsigned int i=0; i<rank.size(); i++){
          rank[i]+= temp_rank;
        }
      }
      for (unsigned int j=1; j< adjvect[i].size(); j++ ){

        result = dampen*(old_rank/(adjvect[i].size()-1));// using pagerank formula
        rank[adjvect[i][j]] += result; 
      }
    }
    for (unsigned int a=0; a< rank.size(); a++ ){
      rank[a] += alpha;
      temp[a] = rank[a];
    } 
  }
  
  for(unsigned int i=0; i<rank.size(); i++){
    finalrank.push_back(std::make_pair(i,rank[i]));
  }
  return finalrank;

}

void print_rank(vector<pair<int, double> > frank ){
    std::sort(frank.begin(), frank.end(), [](const auto& a, const auto& b){return a.second > b.second;} );
    std::ofstream myfile;
    myfile.open ("/workspaces/cs225/Final_Project/output/Product_Rank");
    for (unsigned int v = 0; v < frank.size(); v++)
    {
        myfile <<  v+1;
        myfile << ". ";
        myfile << frank[v].first;
        myfile << std::endl;
    }
    myfile.close();

}
void printscc(Graph& obj){
    std::ofstream myfile;
    myfile.open ("/workspaces/cs225/Final_Project/output/strongly_connected_component");
    vector<vector< int> > abc;
    abc = scc(obj);
    for(unsigned int i =0 ; i< abc.size(); i++){
      for(unsigned int j=0 ; j< abc[i].size(); j++){
        myfile << abc[i][j] << ",";
    }
    myfile << std::endl;
    }
    myfile.close();
}