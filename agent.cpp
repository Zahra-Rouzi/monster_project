#include "agent.h"
#include "tile.h"
#include <utility>


Agent::Agent(QWidget *p, int h, int m, int d, int a)
    :QPushButton(p),
    HP(h),
    Mobility(m),
    Damage(d),
    attackRange(a)

{}


void Agent::setCell(tile &t) {
    currentCell = &t;
    t.agent = this;
    qDebug() << "[Agent::setCell] Agent now at tile(" << t.getS() << "," << t.getR() << ")";
}
