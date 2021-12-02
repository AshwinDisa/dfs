#include <iostream>

using namespace std;

int X[] = {0, -1, 1, 0};
int Y[] = {1, 0, 0, -1};

const int m = 10;
const int n = 10;

// check if current cell is valid or not
bool validator(int i, int j, int m, int n){

    return (i>=0 && i<m && j>=0 && j<n);
}

// recurcive dfs algorithm
void dfs(int i, int j, int grid[m][n], int m, int n){

    int dx;
    int dy;

    // for visualization
    // cout << (i*60)+30 << "," << (j*60)+30 << endl;
    
    grid[i][j] = 1;

    for(int k=0; k<4; k++){

        dx = i+X[k];
        dy = j+Y[k];
        
        if(validator(dx, dy, m, n) && grid[dx][dy] == 0){

            dfs(dx, dy, grid, m, n);
        }    
    }
}

int main(){

    int x;
    int y;

    cout << "Enter X " << endl;
    cin >> x;
    cout << "Enter Y " << endl;
    cin >> y;

    cout << "Unvisited cells - 0 " << endl;
    cout << "Obstacle/visited cells -1 " << endl;
    cout << endl;

    // assign cells as unvisited
    int grid[m][n];
    for(int i=0;i<m;i++){

        for(int j=0;j<n;j++){
            grid[i][j] = 0;
        }
    }

    //obstacle
     grid[5][5] = 1;
     grid[5][6] = 1;
     grid[6][5] = 1;
     grid[5][4] = 1;
     grid[4][5] = 1;
     grid[4][6] = 1;
     grid[6][4] = 1;
     grid[6][6] = 1;
     grid[4][4] = 1;

    for(int i=0;i<m;i++){

        for(int j=0;j<n;j++){
            cout << grid[i][j] << " "; 
        }
        cout << endl;
    }
    cout << endl;
     
    dfs(x, y, grid, m, n);

    // print the final grid
    for(int i=0;i<m;i++){

        for(int j=0;j<n;j++){
            cout << (grid[i][j]) << " ";
        }
        cout << endl;
    }

    return 0;
}