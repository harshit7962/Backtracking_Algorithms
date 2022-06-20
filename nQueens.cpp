 #include <bits/stdc++.h>

using namespace std;

/**
To check of underlying board satisfies the problem statement
Here we need not check for different columns, coz we are anyways adding our new queen to unvisited column...
Also, we need to only check for upper left diagonal and lower left diagonal, coz at any instance our right side of board is not filled...
*/
bool isSafe(int row, int col, int n, vector<vector<int>> board) {
    //Row Check
    for(int i=0;i<col;i++) {
        if(board[row][i]) return false;
    }
    
    //Upper Left Diagonal
    int i=row, j=col;
    while(i>=0 && j>=0) {
        if(board[i][j]) return false;
        i--;
        j--;
    }
    
    //Lower Left Diagonal
    i=row, j=col;
    while(i<n && j>=0) {
        if(board[i][j]) return false;
        i++;
        j--;
    }
    return true;
}

/**
Helper function to check if board can be formed using given set of queens
*/
bool isPossible(int n, int col, vector<vector<int>> &board) {
    if(col==n) return true;
    
    for(int i=0;i<n;i++) {
        if(isSafe(i, col, n, board)) {
            board[i][col]=1;
            if(isPossible(n, col+1, board)) return true;
            board[i][col]=0;
        }
    }
    
    return false;
}

/**
Function to print our board if it is possible to generate one...
*/
void printMat(vector<vector<int>> board) {
    for(int i=0;i<board.size();i++) {
        for(int j=0;j<board.size();j++) {
            cout << board[i][j] << "  ";
        }
        
        cout << endl;
    }
}

/**
Main function call
*/
bool nQueens(int n, vector<vector<int>> &board) {
    if(isPossible(n, 0, board)) {
        printMat(board);
        return true;
    }
    
    return false;
}

int main()
{
    //Size of the board
    int n=4;
    
    //Initializing the board of size nXn with all 0's
    vector<vector<int>> board(n, vector<int>(n, 0));
    
    cout << (nQueens(n, board)?"Solution Possible":"Solution Not Possible") << endl;
    
    return 0;
}
