#include "tile.h"
#include "mainpage.h"
#include "agent.h"
#include <QQueue>

#include <vector>
tile::tile(double x, double y, QWidget *parent, int t,int s ,int r): type(t),s(s),r(r){
    w = new QPushButton(parent);
    w->setGeometry(x, y, 100, 86);
    vec.push_back(w);
    //neighbors={};
}

void tile::pic(int c) {
    if (c == 0 || c == 1 || c == 2)
        w->setStyleSheet("image: url(:/new/prefix3/d.png); background-color: transparent");
    else if (c == 3)
        w->setStyleSheet("image: url(:/new/prefix4/water.png); background-color: transparent");
    else
        w->setStyleSheet("image: url(:/new/prefix5/rock.png); background-color: transparent");

    w->show();
}

void tile::bfsMove(int d,Agent* a,bool canGo[5][9]){
    QQueue<tile*> q;
    bool visited[5][9];
    int depth[5][9];
    for(int i=0;i<5;i++){
        for(int j=0;j<9;j++){
            visited[i][j]=0;
            depth[i][j]=0;
            canGo[i][j]=0;
        }
    }
    visited[this->s][this->r]=1;
    depth[this->s][this->r] = 0;
    q.push_front(this);
    while(!q.empty()){
        tile* cur_tile=q.front();
        int curDepth = depth[cur_tile->s][cur_tile->r];
        q.pop_front();

        if (curDepth >= d) continue; //?
        for(tile*neighbor:cur_tile->neighbors){
            if(!visited[neighbor->s][neighbor->r]&& a->canMoveT0(neighbor->type)){
                visited[neighbor->s][neighbor->r]=true;
                canGo[neighbor->s][neighbor->r]=true;//?
                depth[neighbor->s][neighbor->r] = curDepth + 1;
                q.push_back(neighbor);

            }
        }
    }

    for(int i=0;i<5;i++){

            for(int j=0;j<9;j++){
                qDebug() << "canGo[" << i << "][" << j << "] = " << canGo[i][j];
            }
    }



}

void tile::bfsAttack(int d,Agent* a,bool canAttack[5][9]){
    QQueue<tile*> q;
    bool visited[5][9];
    int depth[5][9];
    for(int i=0;i<5;i++){
        for(int j=0;j<9;j++){
            visited[i][j]=0;
            depth[i][j]=0;
            canAttack[i][j]=0;
        }
    }
    visited[this->s][this->r]=1;
    depth[this->s][this->r] = 0;
    q.push_front(this);
    while(!q.empty()){
        tile* cur_tile=q.front();
        int curDepth = depth[cur_tile->s][cur_tile->r];
        q.pop_front();

        if (curDepth >= d) continue;
        for(tile*neighbor:cur_tile->neighbors){
            if(!visited[neighbor->s][neighbor->r]){/////?true???
                visited[neighbor->s][neighbor->r]=true;
                if (neighbor->agent != nullptr && neighbor->agent->getOwner() != a->getOwner()) {
                    canAttack[neighbor->s][neighbor->r] = true;
                }

                depth[neighbor->s][neighbor->r] = curDepth + 1;
                q.push_back(neighbor);

            }
        }
    }
    for(int i=0;i<5;i++){

        for(int j=0;j<9;j++){
            qDebug() << "canAttack[" << i << "][" << j << "] = " << canAttack[i][j];
        }
    }

}

bool tile::isOccupiedByAlly(Agent* a) {
    return (this->agent != nullptr && this->agent->getOwner()== a->getOwner());
}


/*
void highlightTiles(bool canGo[5][9], bool canAttack[5][9], tile* grid[5][9]) {

    QPolygon hexagon;
    int size = 20;  // شعاع
    float height = sqrt(3) * size;

    int cnt = 0;
    for (int row = 0; row < 5; ++row) {
        for (int col = 0; col < 9; col+=2) {
            double x = (size * 3.0/2 + 55.0) * col;
            double y = (height + 55.0) * (row + 0.5 * (col % 2));
            if(col % 2 && row == 4) continue;
            hexagon << QPoint(x + 280, y + 150);
            if(col == 8) col = -1;

        }
    }

    QRegion hexRegion(hexagon);
    for (int row = 0; row < 5; ++row) {
        for (int col = 0; col < 9; col+=2) {
            tile *button = grid[row][col];
            button->setMask(hexRegion);
            if(col == 8) col = -1;

        }
    }

}
*/
/*/

/*
void tile::  get_hex_neighbors(int r, int c, int rows, int cols) {
    //vector<tile> neighbors;
    // Define neighbor offsets for even and odd rows
    int even_row_dr[] = {-1, -1, 0, 1, 1, 0};
    int even_row_dc[] = {0, 1, 1, 1, 0, -1};
    int odd_row_dr[] = {-1, -1, 0, 1, 1, 0};
    int odd_row_dc[] = {0, -1, 1, 0, -1, -1};

    for (int i = 0; i < 6; ++i) {
        int nr, nc;
        if (r % 2 == 0) { // Even row
            nr = r + even_row_dr[i];
            nc = c + even_row_dc[i];
        } else { // Odd row
            nr = r + odd_row_dr[i];
            nc = c + odd_row_dc[i];
        }

        // Check bounds
        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
            neighbors.push_back(*cell[nr][nc]);
        }
    }
    return neighbors;
}
*/
/*
std::vector<Hex> get_neighbors(const Hex& current_hex) {
    std::vector<Hex> neighbors;
    // Axial directions
    int dq[] = {1, -1, 0, 0, 1, -1};
    int dr[] = {0, 0, 1, -1, -1, 1};

    for (int i = 0; i < 6; ++i) {
        neighbors.push_back({current_hex.q + dq[i], current_hex.r + dr[i]});
    }
    return neighbors;
}
*/
/*
std::vector<tile> get_hex_neighbors(int r, int c, int rows, int cols) {
    std::vector<tile> neighbors;
    // Define neighbor offsets for even and odd rows
    int even_row_dr[] = {-1, -1, 0, 1, 1, 0};
    int even_row_dc[] = {0, 1, 1, 1, 0, -1};
    int odd_row_dr[] = {-1, -1, 0, 1, 1, 0};
    int odd_row_dc[] = {0, -1, 1, 0, -1, -1};

    for (int i = 0; i < 6; ++i) {
        int nr, nc;
        if (r % 2 == 0) { // Even row
            nr = r + even_row_dr[i];
            nc = c + even_row_dc[i];
        } else { // Odd row
            nr = r + odd_row_dr[i];
            nc = c + odd_row_dc[i];
        }

        // Check bounds
        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
            neighbors.push_back({nr, nc});
        }
    }
    return neighbors;
}
*/
/*
void tile::bfs(int sx,int sy,int ex,int ey,int n ,int m,int attackRange,int mobility){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j]=0;
        }
    }
    visited[sx][sy]=1;

    frount=back=0;
    Distance[sx][sy]=0;
    pushq({sx,sy});
    while(back!=frount){
        point p =popq();
        for (int i = 0; i < 4; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                !visited[nx][ny] && grid[nx][ny] != '#') {
                visited[nx][ny] = true;
                Distance[nx][ny] = Distance[p.x][p.y] + 1;
                pushq({nx, ny});
            }
        }
        if (visited[ex][ey]){
            return(Distance[ex][ey]);
        }
    }
    return -1;
}

*/
