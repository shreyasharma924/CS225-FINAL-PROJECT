#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <cassert>
#include <fstream>
#include <sstream>
#include <fenv.h>
#include <signal.h>
#include "file_read.h"
#include "Graph.h"
#include "Algorithm.h"
using std::list;
using std::vector;
using std::string;

int main(){

    bool adjprint = false;
    bool edgeprint = false;
    bool sccb = false;
    bool distanceb = false;
    bool pagerankb = false;
    int x;
    string amazondata = file_to_string("/workspaces/cs225/Final_Project/amazon0302 (1).txt");
    Graph obj(amazondata);
    std::cout << "Graph created of " << obj.versize() << " Nodes." << std::endl;
    if(distanceb){
    std::cout << "Please input the vertex you want to find the distance to other vertices" << std::endl;
    std::cin >> x;
    while(x >= obj.versize()){
        std::cout << "Input outside of vertex range. Please input again" << std::endl;
        std::cin >> x;
    }
    distance(x,obj);
    std::cout << "Distance is printed in the BFS_distance file" << std::endl;
    }
    if(pagerankb){
    std::cout << "Input the number of iteration for pagerank" << std::endl;
    std::cin >> x;
    print_rank(pageRank(x,obj));
    std::cout << "page rank is printed in the Product importance file" << std::endl;
    }
    if(sccb){
    string test_data = file_to_string("/workspaces/cs225/Final_Project/test_data.txt");
    Graph obj2(test_data);
    printscc(obj2);
    std::cout << "SCC printed the Strongly connected component file" << std::endl;
    }
    if(adjprint){
    obj.printadj();}
    if(edgeprint){
    obj.printedge();}

    return 0;

}
