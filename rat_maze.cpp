//Given a maze, we need to find if a rat can reach the end of given maze, if it does, also find the possible paths

bool isReachable(vector<vector<int>> maze, int i, int j, vector<vector<int>> &res) {
    if(i>=maze.size() || j>=maze[0].size()) return false;
    if(i==maze.size()-1 && j==maze[0].size()-1) {
        res[i][j]=1;
        return true;
    }
    
    bool flag1=false, flag2=false;
    if(i!=maze.size()-1 && maze[i+1][j]==1) {
        flag1 = isReachable(maze, i+1, j, res);
    }
    if(j!=maze.size()-1 && maze[i][j+1]==1) {
        flag2 = isReachable(maze, i, j+1, res);
    }
    
    if(flag1 || flag2) {res[i][j]=1; return true;}
    
    return false;
}
