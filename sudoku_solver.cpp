#include <bits/stdc++.h>

using namespace std;

/**
In this function, we are checking if the val can be inserted at a given position (row, column) of our board...
This is gatekeeping function to see if we should carry on with our recursive function...
*/
bool isSafe(int val, int row, int col, vector<vector<int>> sud, int n) {
    //Checking if val is already present in given row and given column
    for(int i=0;i<n;i++) {
        if(sud[row][i]==val) return false;
        if(sud[i][col]==val) return false;
    }
    
    //This part of the function checks if the smaller grid already contains the val...
    int s = sqrt(n);
    
    //Starting row and column indice of smaller grid having current position
    int rs = row - row%s;
    int cs = col - col%s;
    
    for(int i=0;i<s;i++) {
        for(int j=0;j<s;j++) {
            if(sud[i+rs][j+cs]==val) return false;
        }
    }
    
    return true;
}

/**
This is our main function which checks if there is any possible solution to our sudoku...
If solution doesn't exist it returns false...
*/
bool solveSudoku(vector<vector<int>> &sud, int n) {
    int i=0, j=0;
    //In this part of the code, we are finding the first empty cell of our board
    for(i=0;i<n;i++){
        for(j=0;j<n;j++) {
            if(sud[i][j]==0) break;
        }
        if(j!=n) break;
    }
    
    //If the board doesn't contain any empty cell, we return our board as solution (Here we assume that user is giving us a valid sudoku as input)
    if(i==n && j==n) return true;
    
    //Now, insert values from 1-n in our empty cell, and check if any of the value is feasible
    for(int k=1;k<=n;k++) {
        if(isSafe(k, i, j, sud, n)) {
            sud[i][j]=k;
            //If the value is feasible, we fill rest of the cells of our sudoku and if result exist, we return our sudoku
            if(solveSudoku(sud, n)) return true;
            sud[i][j]=0;
        }
    }
    
    //If none of the values cud satisfy sudoku, we return false...
    return false;
}

/**
In this function  we are simply printing our sudoku, if solution exists
*/
void printSudoku(vector<vector<int>> sud, int n){
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << sud[i][j] << " ";
        }
        cout << endl;
    }
}


int main()
{
    //Size of our sudoku
    int n = 4;
    
    //Sample Input, here 0 indicates empty position
    vector<vector<int>> sudoku={
        {1,0,3,0},
        {0,0,2,1},
        {0,1,0,2},
        {2,4,0,0}
    };
    
    if(solveSudoku(sudoku,4)) {
        cout << "Solution to Sudoku is Possible:\n";
        printSudoku(sudoku, n);
    } else {
        cout << "Solution to Sudoku is Not Possible";
    }

    return 0;
}
