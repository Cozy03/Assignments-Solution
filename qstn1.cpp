#include <iostream>
#include <vector>
#include<cassert>
using namespace std;

//Function to search for an integer in an array and return a vector of indices/positions
vector<int> search(int A[], int n, int x) {
   vector<int> indices; // Creating a vector to store the indices/positions of x in A
   
   for (int i = 0; i < n; i++) {
      if (A[i] == x) {
         indices.push_back(i); // Adding the index/position of x in A to the vector
      }
   }
   
   return indices; // Returns the vector of indices/positions of x in A
}

int main() {

   //Test 1: Checking for element index which is present only once in the array. 
   int A[] = {2, 4, 6, 8, 4, 7, 2};
   int n1 = sizeof(A)/sizeof(A[0]); 
   int x = 6; 
   vector<int> indices1=search(A, n1, x);
   assert(indices1[0]==2);
   cout << "Test 1 is passed. "<< endl;

   //Test 2: Checking for element indices which is present more than once in the array. 
   int B[] = {7, 4, 6, 8, 4, 7, 2, 8, 0, -8, 7, 8, 9, 7};
   int n2 = sizeof(B)/sizeof(B[0]); 
   int y = 7; 
   vector<int> indices2=search(B, n2, y);
   assert(indices2[0]==0);
   assert(indices2[1]==5);
   assert(indices2[2]==10);
   assert(indices2[3]==13);
   cout << "Test 2 is passed. "<< endl;

   //Test 3: Checking for element which is absent in the array. 
   int C[] = {2, 4, 6, 8, 4, 7, 2};
   int n3 = sizeof(C)/sizeof(C[0]); 
   int z = 1; 
   vector<int> indices3=search(C, n3, z);
   assert(indices3.empty());
   cout << "Test 3 is passed. "<< endl;
   
   return 0; 
}
