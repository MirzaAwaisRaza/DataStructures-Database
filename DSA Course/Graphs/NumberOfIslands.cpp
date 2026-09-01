#include<vector>
using namespace std;
class Graph{
    void dfs(int i,int j,vector<vector<bool>> visit,vector<vector<char>> grid,int n,int m){

        if(i<=0||j<=0||i>n||i>m||visit[i][j]||grid[i][j]!='1'){
            return;
        }

        visit[i][j]=true;
        dfs(i+1,j,visit,grid,n,m);
        dfs(i,j+1,visit,grid,n,m);
        dfs(i-1,j,visit,grid,n,m);
        dfs(i,j-1,visit,grid,n,m);
    }

    int numberOfIslands(vector<vector<char>> grid){
        int n=grid.size();
        int m=grid[0].size();
        int islands=0;

        vector<vector<bool>> visit(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]='1'&&!visit[i][j]){
                    dfs(i,j,visit,grid,n,m);
                    islands++;
                }
            }
        }
        return islands;
    }
};
int main(){
    return 0;
}