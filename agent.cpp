#include "agent.h"
#include "player.h"
#include "tile.h"
#include "mainpage.h"
#include <QObject>
#include <QMetaObject>
#include <utility>
#include <QEvent>


Agent::Agent(QWidget *p, int h, int m, int d, int a)
    :QPushButton(p),
    HP(h),
    Mobility(m),
    Damage(d),
    attackRange(a)

{

}

void Agent::setConnection(){

    for (int row = 0; row < 5; ++row) {
        for (int col = 0; col < 9; ++col) {
            if(!cell[row][col]) continue;
           // disconnect(cell[row][col], &QPushButton::clicked, this, nullptr);

        }
    }
    connect(this, &QPushButton::clicked, this, [=, this]() {
        this->WaitingForTarget=true;


        qDebug() << "agent "<< this <<"clicked"<< this->WaitingForTarget;
        for (int i = 0; i < 5; ++i)
            for (int j = 0; j < 9; ++j) {
                canGo[i][j] = false;
                canAttack[i][j] = false;
            }

        tile *ti = this->currentCell;
        //ti->bfsAttack(this->getAttackRange(), this, canAttack);
        ti->bfsMove(this->getMobility(), this, canGo);
        //highlight(m);

        for (int row = 0; row < 5; ++row) {
            for (int col = 0; col < 9; ++col) {
                if(!cell[row][col]) continue;
                cell[row][col]->raise();
            }
        }
        for(QPushButton *p : vec){
            p->raise();
        }
    });

    QVector<bool> cCanGo;
    for (int row = 0; row < 5; ++row) {
        for (int col = 0; col < 9; col += 2) {
            if (col % 2 == 1 && row == 4) continue; // همچنان این شرط رو نگه می‌داریم اگر برای ردیف آخر بخوای ستون فرد حذف بشه
            cCanGo.push_back(canGo[row][col]);
        }
        for (int col = 1; col < 9; col += 2) {
            if (col % 2 == 1 && row == 4) continue;
            cCanGo.push_back(canGo[row][col]);
        }
    }
    int cnt = 0;
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
void Agent::setCell(tile &t) {
    currentCell = &t;
    t.agent = this;
    qDebug() << "[Agent::setCell] Agent now at tile(" << t.getS() << "," << t.getR() << ")";
}
