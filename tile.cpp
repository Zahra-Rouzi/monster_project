#include "tile.h"
#include "mainpage.h"
#include "ui_mainpage.h"
#include "agent.h"
#include "player.h"
#include <queue>
#include <QMessageBox>

#include <vector>


tile::tile(MainPage *m, double x, double y, QWidget *parent, int t,int s ,int r): type(t),s(s),r(r){
    w = new QPushButton(parent);
    w->setGeometry(x, y, 100, 86);
    vec.push_back(w);
    //neighbors={};
    connect(w, &QPushButton::clicked, w, [=](){

        qDebug() << "tile click at (" << s << "," << r << ")";
        qDebug() << "=== CRITICAL DEBUG ===";
        qDebug() << "cell[" << s << "][" << r << "] pointer:" << cell[s][r];
        if (cell[s][r]) {
            qDebug() << "cell[" << s << "][" << r << "]->agent:" << cell[s][r]->agent;
        }
        qDebug() << "this tile pointer:" << this;
        qDebug() << "this->s:" << this->s << ", this->r:" << this->r;
        qDebug() << "this->agent:" << this->agent;
        Agent* a = selectedAgent;
        if (!a || !a->WaitingForTarget) {
            qDebug() << "No selected agent or not waiting.";
            return;
        }

        // کلیک روی همون خانه‌ی خودش؟ نادیده بگیر.
        if (a->getCell() == this) {
            qDebug() << "Clicked on own tile -> ignore";
            return;
        }

        qDebug() << "=== DETAILED TILE CLICK DEBUG ===";
        qDebug() << "Clicked tile (" << s << "," << r << ")";
        qDebug() << "this->agent:" << this->agent;
        qDebug() << "canGo[" << s << "][" << r << "]:" << canGo[s][r];
        qDebug() << "canAttack[" << s << "][" << r << "]:" << canAttack[s][r];

        if (this->agent) {
            qDebug() << "✅ Target agent exists!";
            qDebug() << "Target owner:" << (this->agent->getOwner() ?
                                                this->agent->getOwner()->name : "NULL");
            qDebug() << "Current agent owner:" << (a->getOwner() ?
                                                       a->getOwner()->name : "NULL");
        } else {
            qDebug() << "❌ NO AGENT ON THIS TILE!";
        }

        // دیباگ وضعیت
        qDebug() << "tile.agent?" << (this->agent != nullptr)
                 << "canGo?" << canGo[s][r]
                 << "canAttack?" << canAttack[s][r];

        // اول حمله، بعد حرکت (tile نمی‌تونه همزمان پر و خالی باشه، ولی این ترتیب منطقی‌تره)
        bool didSomething = false;

        if (this->agent) {
            // دشمن بودن
            bool enemy = false;
            if (this->agent != a && this->agent->getOwner() && a->getOwner())
                enemy = (this->agent->getOwner()->name != a->getOwner()->name); // ترجیحاً با id

            qDebug() << "enemy?" << enemy;
            //bool newCanAttack[5][9];
            //a->getCell()->bfsAttack(a->attackRange, a, canAttack);
            if (enemy && canAttack[this->s][this->r]) {
                qDebug() << "ATTACK!";
                a->attack(this->agent);
                didSomething = true;
                done=true;
                isPlaying=false;

            }
        } else {
            if (canGo[s][r] && a->canStandOn(type)) {
                qDebug() << "MOVE!";
                a->setGeometry(w->geometry());
                if(a->currentCell)a->currentCell->agent=nullptr ;
                qDebug() << "cell has agent?old"<<a->currentCell->agent;
                a->setCell(this);
                qDebug() << "cell has agent?now"<<this->agent;

                //this->agent=a;
                /*for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 9; j++) {
                        if (cell[i][j] && cell[i][j]->agent) {
                            Agent* target = cell[i][j]->agent;
                            if (target->getOwner() && a->getOwner() &&
                                target->getOwner()->name != a->getOwner()->name) {
                                // محاسبه فاصله
                                double distance = sqrt(pow(i - s, 2) + pow(j - r, 2));
                                if (distance <= a->attackRange) {
                                    qDebug() << "IMMEDIATE ATTACK AFTER MOVE!"<<target->getHP();;
                                    a->attack(target);
                                    qDebug() << "HP"<<target->getHP();

                                    break;
                                }
                            }
                        }
                    }
                }*/
                qDebug() << "After setCell - this->agent:" << this->agent;
                qDebug() << "After setCell - agent position:" << a->getCell()->getS() << "," << a->getCell()->getR();
                didSomething = true;
                done=true;
                isPlaying=false;
                a->WaitingForTarget = false;
                selectedAgent = nullptr;
                m->changeBack();
                if (currentPlayer == &player1) {
                    m->ui->lineEdit->setText("Player2");
                    currentPlayer = &player2;
                    qDebug() << "Turn: Player 2";
                } else {
                    currentPlayer = &player1;
                    m->ui->lineEdit->setText("Player1");
                    qDebug() << "Turn: Player 1";
                }
            }
        }

        if (!didSomething) {
            qDebug() << "No action: reason ->"
                     << (this->agent ? "ally or out of range" : "blocked/out of range");
            return; // اگر کاری انجام نشد، نوبت عوض نکن
        }

        // پایان اکشن: خروج از حالت انتخاب و تعویض نوبت


    });

}

tile::tile(tile & o){
    setParent(o.parentWidget());
    styleSheet() = o.styleSheet();
    text() = "HI";
    setGeometry(o.geometry());
    type = o.type;
    s = o.s;
    r = o.r;
    neighbors = o.neighbors;

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

void tile::bfsMove(int d, Agent* a, bool canGo[5][9]) {
    if (!a) return;

    std::queue<tile*> q;
    bool visited[5][9] = {};
    int depth[5][9] = {};

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 9; j++)
            canGo[i][j] = false;

    // چک موقعیت شروع
    if (s < 0 || s >= 5 || r < 0 || r >= 9) return;
    if (cell[s][r] == nullptr) return;

    visited[s][r] = true;
    depth[s][r] = 0;
    q.push(this);

    int loopCounter = 0;

    while (!q.empty()) {
        tile* cur_tile = q.front();
        q.pop();
        if (!cur_tile) continue;

        int cs = cur_tile->s;
        int cr = cur_tile->r;
        int curDepth = depth[cs][cr];

        if (++loopCounter > 500) break;

        if (cur_tile->neighbors.isEmpty()) continue;

        for (tile* neighbor : cur_tile->neighbors) {
            if (!neighbor) continue;
            if (neighbor == cur_tile) continue;

            int ns = neighbor->s;
            int nr = neighbor->r;

            // ✅ اصلاح محدوده‌ها
            if (ns < 0 || ns >= 5 || nr < 0 || nr >= 9) continue;

            if (visited[ns][nr]) continue;
            if (!a->canMoveT0(neighbor->type)) continue;

            visited[ns][nr] = true;
            depth[ns][nr] = curDepth + 1;
            q.push(neighbor);
        }
    }

    // ✅ حلقه‌ی پرکردن canGo رو آوردیم بیرون
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            if (visited[i][j] && depth[i][j] <= d && cell[i][j] != nullptr) {
                canGo[i][j] = (cell[i][j]->agent == nullptr);
            }
        }
    }
}
void tile::bfsAttack(int d, Agent* a, bool canAttack[5][9]) {
    if (!a) return;

    std::queue<tile*> q;
    bool visited[5][9] = {};
    int depth[5][9] = {};

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 9; j++)
            canAttack[i][j] = false;

    // چک موقعیت شروع
    if (s < 0 || s >= 5 || r < 0 || r >= 9) return;
    if (cell[s][r] == nullptr) return;

    visited[s][r] = true;
    depth[s][r] = 0;
    q.push(this);

    int loopCounter = 0;

    while (!q.empty()) {
        tile* cur_tile = q.front();
        q.pop();
        if (!cur_tile) continue;

        int cs = cur_tile->s;
        int cr = cur_tile->r;
        int curDepth = depth[cs][cr];

        if (++loopCounter > 500) break;

        if (cur_tile->neighbors.isEmpty()) continue;

        for (tile* neighbor : cur_tile->neighbors) {
            if (!neighbor) continue;
            if (neighbor == cur_tile) continue;

            int ns = neighbor->s;
            int nr = neighbor->r;

            // ✅ اصلاح محدوده‌ها
            if (ns < 0 || ns >= 5 || nr < 0 || nr >= 9) continue;

            if (visited[ns][nr]) continue;
            //if (!a->canMoveT0(neighbor->type)) continue;


            visited[ns][nr] = true;
            depth[ns][nr] = curDepth + 1;
            q.push(neighbor);
        }
    }

    // ✅ حلقه‌ی پرکردن canGo رو آوردیم بیرون
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            if (visited[i][j] && depth[i][j] <= d && cell[i][j] != nullptr) {
                Agent* target = cell[i][j]->agent;
                if (target && target->getOwner() && a->getOwner() &&
                    target->getOwner()->name == a->getOwner()->name) {
                    canAttack[i][j] = false;  // متحد است
                } else {
                    canAttack[i][j] = true;
                }
            }

        }
    }

}
/*if(player1.getPlayerAgents().size()==0){
                        qDebug() << "game finished!"<<player2.name<<"won the game !";

                        QMessageBox msgBox(QMessageBox::Warning,
                                           "game finished",
                                           "player2 won the game!",
                                           QMessageBox::Ok,
                                           parent);
                        msgBox.setStyleSheet(
                            "QMessageBox {"
                            "background-color: #FFC07C;"
                            "color: #000000;"
                            "font-size: 12px;"
                            "padding: 10px;"
                            "}"
                            "QLabel {"
                            "color: #000000;"
                            "font-size: 12px;"
                            "}"
                            "QPushButton {"
                            "background-color: #FFF;"
                            "color: #000000;"
                            "border: 1px solid #FFC07C;"
                            "border-radius: 5px;"
                            "padding: 5px;"
                            "}"
                            );
                        msgBox.exec();)
                        //MainPage.close();
                        }
                    }
*/

/*
void tile::bfsMove(int d, Agent* a, bool canGo[][9]) {
    QQueue<tile*> q;
    bool visited[5][9] = {};
    int depth[5][9] = {};

    // ریست وضعیت
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 9; ++j) {
            visited[i][j] = false;
            depth[i][j] = 0;
            canGo[i][j] = false;
        }

    visited[this->s][this->r] = true;
    q.push_front(this);

    while (!q.empty()) {
        tile* cur_tile = q.front();
        q.pop_front();

        int curDepth = depth[cur_tile->s][cur_tile->r];
        //if (curDepth >= d) continue;

        for (tile* neighbor : cur_tile->neighbors) {
            if (!neighbor) continue;

            int ns = neighbor->s;
            int nr = neighbor->r;

            if (ns < 0 || ns >= 5 || nr < 0 || nr >= 9) continue;
            if (visited[ns][nr]) continue;
            if (!a->canMoveT0(neighbor->type)) continue;

            visited[ns][nr] = true;
            depth[ns][nr] = curDepth + 1;
            q.push_back(neighbor);
        }
    }

    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 9; ++j)
            if (depth[i][j] <= d && cell[i][j] != nullptr)
                canGo[i][j] = true;

}
*/
/*
void tile::bfsMove(int d, Agent* a, bool canGo[5][9]) {
   // qDebug() << "in bfs";
    if (!a) return;

    std::queue<tile*> q;
    bool visited[5][9] = {};
    int depth[5][9] = {};

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 9; j++)
            canGo[i][j] = false;

    // چک موقعیت شروع
    if (s < 0 || s >= 5 || r < 0 || r >= 9)    {

     //   qDebug() << "out index";
        return;
    }
    if (cell[s][r] == nullptr) {
      //  qDebug() << "[bfsMove] Starting cell is null!";
        return;
    }

    visited[s][r] = true;
    depth[s][r] = 0;
    q.push(this);

    int loopCounter = 0;
    //qDebug() << "while";
    while (!q.empty()) {
        tile* cur_tile = q.front();
        q.pop();
        if (!cur_tile) {
      //      qDebug() << " !cur_tile";
            continue;
        }


        int cs = cur_tile->s;
        int cr = cur_tile->r;
        int curDepth = depth[cs][cr];

        if (++loopCounter > 500) {
        //    qDebug() << "[bfsMove] Aborting: loop too long!";
            break;
        }

        //if (curDepth >= d) continue;

        if (cur_tile->neighbors.isEmpty()) {
          //  qDebug() << "[bfsMove] Empty neighbors at tile:" << cs << cr;
            continue;
        }
        for (tile* neighbor : cur_tile->neighbors) {
            //qDebug() << "[bfsMove]  neighbor :" << cs << cr;

            if (!neighbor) {
              //  qDebug() << "[bfsMove] Null neighbor at:" << cs << cr;
                continue;
            }

            if (neighbor == cur_tile) {
                //qDebug() << "[bfsMove] Neighbor same as self at:" << cs << cr;
                continue;
            }

            int ns = neighbor->s;
            int nr = neighbor->r;


            if (ns < 0 || ns >= 5 || nr < 0 || nr >= 9) {
                continue;
            }


            if (visited[ns][nr]) continue;
           // qDebug() << "1";
            if (!a->canMoveT0(neighbor->type)) {
             //   qDebug() << "[bfsMove] Cannot move to type" << neighbor->type << "at" << ns << nr;
                continue;
            }
            /*
            if (neighbor->agent) {
                auto owner = neighbor->agent->getOwner();
                if (!owner) {
                    qDebug() << "[bfsMove] Agent with null owner at" << ns << nr;
                    continue;
                }
                if (owner == a->getOwner()) {
                    qDebug() << "[bfsMove] Ally at" << ns << nr << ", skipping.";
                    continue;
                }
            }

            visited[ns][nr] = true;
            depth[ns][nr] = curDepth + 1;
            q.push(neighbor);
        }




}
    for (int i = 0; i < 5; i++)
    for (int j = 0; j < 9; j++)
        if (visited[i][j] && depth[i][j] <= d && cell[i][j] != nullptr){

            canGo[i][j] = true;
            if(cell[i][j]&&cell[i][j]->agent)
                canGo[i][j]=false;
        }
}
*/
/*
void tile::bfsAttack(int d, Agent* a, bool canAttack[5][9]) {
    qDebug() << "in bfsAttack";
    if (!a) return;

    std::queue<tile*> q;
    bool visited[5][9] = {};
    int depth[5][9] = {};

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 9; j++)
            canAttack[i][j] = false;

    // چک موقعیت شروع
    if (s < 0 || s >= 5 || r < 0 || r >= 9)    {

        qDebug() << "out index";
        return;
    }
    if (cell[s][r] == nullptr) {
        qDebug() << "[bfsAttack] Starting cell is null!";
        return;
    }

    visited[s][r] = true;
    depth[s][r] = 0;
    q.push(this);

    int loopCounter = 0;
    qDebug() << "while";
    while (!q.empty()) {
        tile* cur_tile = q.front();
        q.pop();
        if (!cur_tile) {
            qDebug() << " !cur_tile";
            continue;
        }


        int cs = cur_tile->s;
        int cr = cur_tile->r;
        int curDepth = depth[cs][cr];

        if (++loopCounter > 500) {
            qDebug() << "[bfsAttack] Aborting: loop too long!";
            break;
        }

        //if (curDepth >= d) continue;

        if (cur_tile->neighbors.isEmpty()) {
            qDebug() << "[bfsAttack] Empty neighbors at tile:" << cs << cr;
            continue;
        }
        for (tile* neighbor : cur_tile->neighbors) {
            qDebug() << "[bfsAttack]  neighbor :" << cs << cr;

            if (!neighbor) {
                qDebug() << "[bfsAttack] Null neighbor at:" << cs << cr;
                continue;
            }

            if (neighbor == cur_tile) {
                qDebug() << "[bfsAttack] Neighbor same as self at:" << cs << cr;
                continue;
            }

            int ns = neighbor->s;
            int nr = neighbor->r;

            if (ns < 0 || ns >= 9 || nr < 0 || nr >= 5) {
                qDebug() << "[bfsAttack] Neighbor out of bounds:" << ns << nr;
                continue;
            }

            if (visited[ns][nr]) continue;
            qDebug() << "1";
            if (!a->canMoveT0(neighbor->type)) {
                qDebug() << "[bfsAttack] Cannot move to type" << neighbor->type << "at" << ns << nr;
                continue;
            }
            /*
            if (neighbor->agent) {
                auto owner = neighbor->agent->getOwner();
                if (!owner) {
                    qDebug() << "[bfsMove] Agent with null owner at" << ns << nr;
                    continue;
                }
                if (owner == a->getOwner()) {
                    qDebug() << "[bfsMove] Ally at" << ns << nr << ", skipping.";
                    continue;
                }
            }

            visited[ns][nr] = true;
            depth[ns][nr] = curDepth + 1;
            q.push(neighbor);
        }


        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 9; j++)
                if (visited[i][j] && depth[i][j] <= d && cell[i][j] != nullptr) {
                    canAttack[i][j] = true;
                    Agent* enemy = cell[i][j]->agent;
                    if (enemy && enemy->getOwner() && a->getOwner() &&
                        enemy->getOwner() == a->getOwner()) {
                        canAttack[i][j] = false;
                    }
                }

    }
}
*/

/*
void tile::bfsAttack(int d, Agent* a, bool canAttack[9][9]) { // Fixed size
    if (!a) return;

    QQueue<tile*> q;
    bool visited[9][9] = {}; // Initialize to false
    int depth[9][9] = {};    // Initialize to 0

    // Initialize canAttack array
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            canAttack[i][j] = false;
        }
    }

    // Bounds check
    if (this->s < 0 || this->s >= 9 || this->r < 0 || this->r >= 9) return;

    visited[this->s][this->r] = true;
    depth[this->s][this->r] = 0;
    q.enqueue(this);

    while (!q.empty()) {
        tile* cur_tile = q.dequeue();
        int curDepth = depth[cur_tile->s][cur_tile->r];

        if (curDepth >= d) continue;

        if (cur_tile->neighbors.empty()) continue;

        for (tile* neighbor : cur_tile->neighbors) {
            if (!neighbor) continue;

            int ns = neighbor->s;
            int nr = neighbor->r;

            // Fixed bounds check
            if (ns < 0 || ns >= 9 || nr < 0 || nr >= 9) continue;
            if (visited[ns][nr]) continue;

            visited[ns][nr] = true;
            depth[ns][nr] = curDepth + 1;

            // Check if there's an enemy agent to attack
            if (neighbor->agent != nullptr &&
                neighbor->agent->getOwner() != a->getOwner()) {
                canAttack[ns][nr] = true;
                // Continue BFS even after finding enemy (for range calculation)
            }

            // Only continue BFS through passable terrain
            if (a->canMoveT0(neighbor->type)) {
                q.enqueue(neighbor);
            }
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
