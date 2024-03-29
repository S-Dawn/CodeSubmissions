/*
Chef is given an array A consisting of N positive integers. Chef shuffles the array A and creates a new array B of length N, where Bi=(Ai+i)mod2, for each i(1≤i≤N).

Find the maximum possible sum of integers of the array B, if Chef shuffles the array A optimally.

Input Format
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
Each test case contains two lines of input.
The first line of each test case contains an integer N.
The second line of each test case contains N space-separated integers A1,A2,…,AN.
Output Format
For each test case, print a single line containing one integer - the maximum sum of integers of the array B.

Constraints
1≤T≤104
1≤N≤105
1≤Ai≤109
Sum of N over all test cases does not exceed 3⋅105.
Subtasks
Subtask #1 (100 points): Original constraints

Sample Input 1 
3
3
1 2 3
3
2 4 5
2
2 4
Sample Output 1 
2
3
1
Explanation
Test case 1: One of the optimal ways to shuffle the array A is [2,1,3]. Then the array B=[(2+1)mod2,(1+2)mod2,(3+3)mod2]=[1,1,0]. So the sum of integers of array B is 2. There is no other possible way to shuffle array A such that the sum of integers of array B becomes greater than 2.

Test case 2: One of the optimal ways to shuffle the array A is [2,5,4]. Then the array B=[(2+1)mod2,(5+2)mod2,(4+3)mod2]=[1,1,1]. So the sum of integers of array B is 3 .
*/


#include <iostream>
#include<cmath>
using namespace std;

#define alloc_int(n) (int *) calloc (n, sizeof(int))
#define rep(i,a,b) for(int i=a; i<b; i++)

int main() {
	// your code goes here
	int T;
	cin >> T;
	
	int N, *arr, even_count, odd_count, temp;
	int *output = alloc_int(T);
	
	rep(k,0,T) {
	    even_count = odd_count = 0;
	    cin >> N;
	    arr = alloc_int(N);
	    rep(i,0,N) cin>> arr[i];
	    
	    rep(i,0,N) {
	        if(arr[i]%2) ++odd_count;
	        else ++even_count;
	    }
	    
	    temp = ceil((float)N/2);
	    output[k] += temp > even_count? even_count: temp;
	    temp = floor(N/2);
	    output[k] += temp > odd_count? odd_count: temp;
	}
	
	rep(k,0, T) {
	    std::cout << output[k] << std::endl;
	}
	
	return 0;
}
