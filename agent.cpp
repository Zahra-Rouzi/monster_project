#include "agent.h"
#include "player.h"
#include "tile.h"
#include "mainpage.h"
#include <QObject>
#include <QMetaObject>
#include <utility>
#include <QEvent>

Agent* selectedAgent = nullptr;
bool   isPlaying=false;
bool done=true;
Agent::Agent(QWidget *p, int h, int m, int d, int a)
    :QPushButton(p),
    HP(h),
    Mobility(m),
    Damage(d),
    attackRange(a)

{
    setAttribute(Qt::WA_TransparentForMouseEvents, false);
    setFocusPolicy(Qt::NoFocus);
}

void Agent::setConnection(){

    for (int row = 0; row < 5; ++row) {
        for (int col = 0; col < 9; ++col) {
            if(!cell[row][col]) continue;
           // disconnect(cell[row][col], &QPushButton::clicked, this, nullptr);

        }
    }
    if(done){
        connect(this, &QPushButton::clicked, this, [=, this]() {

            if(selectedAgent && selectedAgent!=this && selectedAgent->getOwner()->name!=this->getOwner()->name && canAttack[this->currentCell->s][this->currentCell->r]){
                qDebug() << "ATTACK!";
                selectedAgent->attack(this);
                done=true;
                isPlaying=false;
                selectedAgent->WaitingForTarget=false;
                selectedAgent = nullptr;
                if (currentPlayer == &player1) {
                    currentPlayer = &player2;
                    qDebug() << "Turn: Player 2";
                } else {
                    currentPlayer = &player1;
                    qDebug() << "Turn: Player 1";
                }
                  return;

            }
            if(this->getOwner()->name!=currentPlayer->name){qDebug()<<"not your turn";return;}
            qDebug()<<"agent conection"<<this<<"selected Agent:"<<selectedAgent;
            if(isPlaying){
                qDebug() <<"isPlaying?"<<isPlaying;
                return ;
            }
            if (selectedAgent) selectedAgent->WaitingForTarget = false;

            selectedAgent = this;
            this->WaitingForTarget = true;
            isPlaying=true;
            done=false;

            qDebug() << "agent "<< this <<"clicked"<< this->WaitingForTarget<<"isPlaying?"<<isPlaying;
            for (int i = 0; i < 5; ++i)
                for (int j = 0; j < 9; ++j) {
                    canGo[i][j] = false;
                    canAttack[i][j] = false;
                }

            tile *ti = this->currentCell;
            ti->bfsMove(this->getMobility(), this, canGo);
            ti->bfsAttack(this->getAttackRange(), this, canAttack);
            qDebug() << "=== BOARD STATUS ===";
            int agentCount = 0;
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 9; j++) {
                    if (cell[i][j] && cell[i][j]->agent) {
                        agentCount++;
                        qDebug() << "Agent found at (" << i << "," << j << ")"
                                 << "Type:" << cell[i][j]->agent
                                 << "Owner:" << (cell[i][j]->agent->getOwner() ?
                                                     cell[i][j]->agent->getOwner()->name : "NULL");
                    }
                }
            }
            qDebug() << "Total agents on board:" << agentCount;
            //highlight(m);

            for (int row = 0; row < 5; ++row) {
                for (int col = 0; col < 9; ++col) {
                    if(!cell[row][col]) continue;
                    cell[row][col]->raise();
                }
            }
            QVector<bool> cCanGo;
            int k=0;
            for (int row = 0; row < 5; ++row) {
                for (int col = 0; col < 9; col += 2) {
                    if (col % 2 == 1 && row == 4) continue; // همچنان این شرط رو نگه می‌داریم اگر برای ردیف آخر بخوای ستون فرد حذف بشه
                    cCanGo.push_back(canGo[row][col]);

                    qDebug()<<"ccan go:"<<cCanGo[k++]<<"can go:"<<canGo[row][col];
                }
                for (int col = 1; col < 9; col += 2) {
                    if (col % 2 == 1 && row == 4) continue;
                    cCanGo.push_back(canGo[row][col]);
                    qDebug()<<"ccan go:"<<cCanGo[k++]<<"can go:"<<canGo[row][col];

                }
            }
            int cnt = 0;
            qDebug()<<cCanGo.size();

        });
    }

    /*for(QPushButton *p : vec){

           // qDebug() << "⚙️ Setting up connect for cell[" << row << "][" << col << "]";


            bool ok = connect(p, &QPushButton::clicked, this, [ =, this, &cnt ](){
               qDebug()<<"before for" << this->WaitingForTarget;
               for(Agent *a : player1.playerAgents){
                   if(a != this) a ->WaitingForTarget = false;

               }
               qDebug()<<"after for" << this->WaitingForTarget;
               if(!(this->WaitingForTarget)) return;
               else{
                qDebug()<< "a"<< this->WaitingForTarget;
               for(Agent *a : player1.playerAgents){
                    qDebug()<< "waiting for target"<< a->WaitingForTarget ;
                   if(a == this) qDebug() <<"*";
               }
                qDebug() << "Sender:" << sender();

                this->setGeometry(p->geometry());
             //   this->WaitingForTarget = false;
               }
            });
           //this->WaitingForTarget = false;
            qDebug() << "ok" << ok;
    }*/


}
void Agent::setCell(tile *t) {
    //if(currentCell) currentCell->agent=nullptr;
    currentCell = t;
    t->agent = this;
    qDebug() << "[Agent::setCell] Agent now at tile(" << t->getS() << "," << t->getR() << ")";
}
void Agent::moveToTile(tile* t) {
    if (!t || !t->getW()) return;

    // مختصات جهانی گوشه‌ی بالا-چپ tile
    QPoint globalPos = t->getW()->mapToGlobal(QPoint(0, 0));

    // اگه Agent توی یه parent خاص هست
    if (this->parentWidget()) {
        QPoint localPos = this->parentWidget()->mapFromGlobal(globalPos);
        this->move(localPos);
    } else {
        // اگه top-level هست
        this->move(globalPos);
    }

    // ست کردن وضعیت tile
    if (this->getCell()) this->getCell()->setAgent(nullptr);
    this->setCell(t);
    t->setAgent(this);
}


