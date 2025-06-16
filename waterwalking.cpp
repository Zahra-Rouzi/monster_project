#include "waterwalking.h"

#include <utility>
//waterWalking::waterWalking(QWidget* parent)
    //: Agent(parent) {}
bool waterWalking:: canMoveT0(int type) const {
    if(type == 0 || type == 1 || type == 2 || type == 3)
        return 1;
    return 0;
}
bool waterWalking:: canStandOn(int type) const {
    if(type == 0 || type == 1 || type == 2 || type == 3)
        return 1;
    return 0;
}
