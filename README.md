# CS 225 SPRING 2022 Final Project
**Team:** Divyam Arora, Krish Patel, Shreya Sharma 


Our project uses the dataset which is retieved from http://snap.stanford.edu/data/amazon0302.html 

## YOUTUBE LINK - https://youtu.be/rfwqpG2OFBs

## BUILD
1.To build the code you need to first make a build directory using the commank mkdir build 
2.Then you can go to the build directory using cd build in the terminal 
3.Use 'cmake ..' in the terminal to import all the cmake files 
4.Use 'make' to compile the code 

## RUNNING THE CODE
1.In the main function there are 4 boolean variables mark whhichever algorthm you want to use as 'true' 
2.The terminal will ouput where the file is saved 
3.To run the test case we use command './tes/ in the build directory on the terminal 

## TROUBLESHOOTING 
1.To change the path of the input data for test cases use the variables defined in the tests/tests.cpp
and change the variables by copying the particular test data path to that variable
2.In the main function change the variables in a similar way to update the paths of the input data 

## FILES USED FOR EACH FUNCTION
**-BFS Distance Algorithm** 
  - main.cpp: function amazon test data 
  - tests.cpp: testpr2,testpr3, test_data
  
**-Strongly Connected Algorithm**
  - main.cpp: test_data 
  - tests.cpp: testpr2,testpr3, test_data 
  
**-Pagerank Algorithm** 
  - main.cpp: function amazon test data 
  - tests.cpp: testpr1,testpr2, testpr3 
  
**-Adjacency List** 
  - main.cpp: function amazon test data 
  - tests.cpp: testpr1, test_data 
