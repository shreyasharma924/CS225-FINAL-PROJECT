//#include <catch2/catch_test_macros.hpp>
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
#include <utility>
#include <cmath>
#include <catch2/catch_test_macros.hpp>
using std::pair;
using std::list;

const string test1path = "/workspaces/cs225/Final_Project/testpr1";
const string test2path = "/workspaces/cs225/Final_Project/testpr2";
const string test3path = "/workspaces/cs225/Final_Project/testpr3";
const string testdatapath = "/workspaces/cs225/Final_Project/test_data.txt";
const string amazondatapath = "/workspaces/cs225/Final_Project/amazon0302 (1).txt";

TEST_CASE("Adjcancey list small", "[weight=2]") {
    string data = file_to_string(test1path);
    Graph t(data);
    list<int>* a;
    a = t.getAdj();
    int test_count = 1;
    list<int>::iterator i;
    for (i = a[0].begin(); i != a[0].end(); ++i){
        REQUIRE( (*i) == test_count++);
    }
}

TEST_CASE("Adjcancey list large", "[weight=2]") {
    string data = file_to_string(testdatapath);
    Graph t(data);
    list<int>* a;
    int test_large[5] = {63, 97, 99, 307, 430};
    a = t.getAdj();
    int ct = 0;
    list<int>::iterator i;
    for (i = a[100].begin(); i != a[100].end(); ++i){
        REQUIRE( (*i) == test_large[ct++]);
    }
}


TEST_CASE("BFS small test", "[weight=2]") {
    string data = file_to_string(test3path);
    Graph t(data);
    vector<int> test_dis;
    test_dis = distance(4,t);
    int test[5] = {2,3,4,1,0};
    REQUIRE( test_dis[0] == test[0] );
    REQUIRE( test_dis[1] == test[1] );
    REQUIRE( test_dis[2] == test[2] );
    REQUIRE( test_dis[3] == test[3] );
    REQUIRE( test_dis[4] == test[4] );
}


TEST_CASE("BFS on cycle", "[weight=1]") {
    string data = file_to_string(test2path);
    Graph t(data);
    vector<int> test_dis;
    test_dis = distance(0,t);
    int test[3] = {0,1,2};
    REQUIRE( test_dis[0] == test[0] );
    REQUIRE( test_dis[1] == test[1] );
    REQUIRE( test_dis[2] == test[2] );
}

TEST_CASE("BFS no path test", "[weight=2]") {
    string data = file_to_string(test3path);
    Graph t(data);
    vector<int> test_dis;
    test_dis = distance(2,t);
    int test[5] = {-1,-1,0,-1,-1};
    REQUIRE( test_dis[0] == test[0] );
    REQUIRE( test_dis[1] == test[1] );
    REQUIRE( test_dis[2] == test[2] );
    REQUIRE( test_dis[3] == test[3] );
    REQUIRE( test_dis[4] == test[4] );
}


TEST_CASE("BFS big data test", "[weight=2]") {
    string data = file_to_string(amazondatapath);
    Graph t(data);
    vector<int> test_dis;
    test_dis = distance(8,t);
    REQUIRE( test_dis[22]  == 1 );
    REQUIRE( test_dis[38]  == 4 );
    REQUIRE( test_dis[87]  == 15 );
}

TEST_CASE("PageRank works with simple data and small n") {
    string d = file_to_string(test1path);
    Graph obj(d);
    vector<pair<int, double> > finalrank = pageRank(4, obj);
    REQUIRE((int)((finalrank[0].second * 100000)/10) == 3598);
    REQUIRE((int)((finalrank[1].second * 100000)/10) == 2133);
    REQUIRE((int)((finalrank[2].second * 100000)/10) == 2133);
    REQUIRE((int)((finalrank[3].second * 100000)/10) == 2133);
}

TEST_CASE("PageRank works with simple data and large n") {
    
    string d = file_to_string(test1path);
    Graph obj(d);
    vector<pair<int, double> > finalrank = pageRank(100, obj);
    REQUIRE((int)((finalrank[0].second * 100000)/10) == 4797);
    REQUIRE((int)((finalrank[1].second * 100000)/10) == 1734);
    REQUIRE((int)((finalrank[2].second * 100000)/10) == 1734);
    REQUIRE((int)((finalrank[3].second * 100000)/10) == 1734);
}

TEST_CASE("PageRank works with cycles in the graph") {
       string d = file_to_string(test2path);
    Graph obj(d);
    vector<pair<int, double> > finalrank = pageRank(4, obj);
    REQUIRE((int)((finalrank[0].second * 100000)/10) == 3333);
    REQUIRE((int)((finalrank[1].second * 100000)/10) == 3333);
    REQUIRE((int)((finalrank[2].second * 100000)/10) == 3333);
}

TEST_CASE("PageRank works with complex data and small n") {
    
    string d = file_to_string(test3path);
    Graph obj(d);
    vector<pair<int, double> > finalrank = pageRank(3, obj);
    REQUIRE((int)((finalrank[0].second * 100000)/10) == 2818);
    REQUIRE((int)((finalrank[1].second * 100000)/10) == 2196);
    REQUIRE((int)((finalrank[2].second * 100000)/10) == 1159);
    REQUIRE((int)((finalrank[3].second * 100000)/10) == 3324);
    REQUIRE((int)((finalrank[4].second * 100000)/10) == 501);
}

TEST_CASE("PageRank works with complex data and large n") {
    
    string d = file_to_string(test3path);
    Graph obj(d);
    vector<pair<int, double> > finalrank = pageRank(100, obj);
    REQUIRE((int)((finalrank[0].second * 100000)/10) == 3170);
    REQUIRE((int)((finalrank[1].second * 100000)/10) == 1871);
    REQUIRE((int)((finalrank[2].second * 100000)/10) == 1319);
    REQUIRE((int)((finalrank[3].second * 100000)/10) == 3113);
    REQUIRE((int)((finalrank[4].second * 100000)/10) == 524);
}

TEST_CASE("Strongly Connected Component works with simple isolated vertices") {
    Graph obj(7);
    obj.insertEdge(0,1);
    obj.insertEdge(1,2);
    obj.insertEdge(2,3);
    obj.insertEdge(3,4);
    obj.insertEdge(4,5);
    obj.insertEdge(5,6);
    vector<vector<int> > ssc;
    ssc = scc(obj);
    REQUIRE(ssc[0][0] == 0);
    REQUIRE(ssc[1][0] == 1);
    REQUIRE(ssc[2][0] == 2);
    REQUIRE(ssc[3][0] == 3);
    REQUIRE(ssc[4][0] == 4);
    REQUIRE(ssc[5][0] == 5);
    REQUIRE(ssc[6][0] == 6);
   
}

TEST_CASE("Strongly Connected Component on complex multiple cycles") {
    Graph obj(9);
    obj.insertEdge(0,1);
    obj.insertEdge(1,2);
    obj.insertEdge(2,3);
    obj.insertEdge(2,4);
    obj.insertEdge(3,0);
    obj.insertEdge(4,5);
    obj.insertEdge(5,6);
    obj.insertEdge(6,4);
    obj.insertEdge(7,6);
    obj.insertEdge(7,8);
    vector<vector<int> > ssc;
    ssc = scc(obj);
    int s[4] = {0,3,2,1};
    int row[3] = {4,6,5};
    REQUIRE(ssc[0][0] == 7);
    REQUIRE(ssc[1][0] == 8);
    for(unsigned int i =0; i<ssc[2].size(); i++ ){
        REQUIRE(ssc[2][i]==s[i]);
    }
    
    for(unsigned int i =0 ; i<ssc[3].size(); i++){
        REQUIRE(ssc[3][i]==row[i]);
    }
   
}

TEST_CASE("Strongly Connected Component on compplex large data") {
    string data = file_to_string(testdatapath);
    Graph obj(data);
    vector<vector<int> > ssc;
    ssc = scc(obj);
    vector<int> scc_count;
    int count = 1 ;
    for(unsigned int i=0; i <ssc.size(); i++){
        for(unsigned int j=0; j<ssc[i].size(); j++){
            count++;
        }
        scc_count.push_back(count);
        count =0;
    }

    REQUIRE(scc_count[77915]==3);
    REQUIRE(scc_count[77916]==1);
    REQUIRE(scc_count[77917]==147166);
   
}