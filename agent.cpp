#include "agent.h"

#include <utility>


Agent::Agent(QWidget *p, int h, int m, int d, int a)
    :QPushButton(p),
    HP(h),
    Mobility(m),
    Damage(d),
    attackRange(a)
{}



