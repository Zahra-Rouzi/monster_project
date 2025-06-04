#ifndef WATERWALKING_H
#define WATERWALKING_H

#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>

class waterWalkingData;

class waterWalking
{
    Q_OBJECT
    QML_ELEMENT
public:
    waterWalking();
    waterWalking(const waterWalking &);
    waterWalking(waterWalking &&);
    waterWalking &operator=(const waterWalking &);
    waterWalking &operator=(waterWalking &&);
    ~waterWalking();

private:
    QSharedDataPointer<waterWalkingData> data;
};

#endif // WATERWALKING_H
