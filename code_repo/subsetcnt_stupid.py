
# Python3 implementation of above approach - stupid constraints
from functools import lru_cache
import numpy as np
import pdb
 
# maxSum = 13
# arrSize = 6
 

# To find the number of subsets
# with sum equal to 0.
# Since S can be negative,
# we will maxSum to it
# to make it positive

def maxSumofArr():
    suma = 0
    for i in arr:
        if i > 0:
            suma += i

    return suma+1

#See if the cache decorator speeds up the process 
@lru_cache(maxSize=None)
def SubsetCnt(i, s) :
    
    # pdb.set_trace()
    # Base cases
    if (i == len(arr)) :
        if (s == 0) :
            return 1;
        else :
            return 0;
     
    # Returns the value
    # if a state is already solved
    if (visit[i][s]) :
        return dp[i][s];
 
    # If the state is not visited,
    # then continue
    visit[i][s] = 1;
 
    # Recurrence relation
    dp[i][s] = (SubsetCnt(i + 1, s + arr[i]) +
                           SubsetCnt(i + 1, s));
 
    # Returning the value
    return dp[i][s];
 
'''
i s v v d 
0 0 0 1  
1 2 0 1 
2 4 0 1
3 6 0 1   // done // return 0 to 2 4 
4 2 0 1 0 //done // return 0 to 3 6
5-2 0     // return 0
5 2       // return 0
4 6 0 1   //done // return 0 to 3 6 
5 2       //return 0
5 6       //return 0
3 4 0 1 
4 0 0 1   
'''

# Driver Code
if __name__ == "__main__" :
        

    # arr = [ 14, 12, -9, - 13, 2, 2, 3, -3, -4 , -5, -6 , 10];
    arr = [ 2, 2, 2, -4, -4];

    arrSize = len(arr)
    maxSum  = maxSumofArr()
    # variable to store
    # states of dp
    dp = np.zeros((arrSize, maxSum));
    visit = np.zeros((arrSize, maxSum));
    # n = len(arr);
 
    print(SubsetCnt(0, 0));
    print(SubsetLists(0, 0));
 

