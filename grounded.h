#ifndef GROUNDED_H
#define GROUNDED_H

#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>
#include "agent.h"



class Grounded : public Agent
{
    Q_OBJECT
    QML_ELEMENT
public:
    Grounded();


private:

};

#endif // GROUNDED_H
