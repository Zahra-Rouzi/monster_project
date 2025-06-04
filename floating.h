#ifndef FLOATING_H
#define FLOATING_H

#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>

class floatingData;

class floating
{
    Q_OBJECT
    QML_ELEMENT
public:
    floating();
    floating(const floating &);
    floating(floating &&);
    floating &operator=(const floating &);
    floating &operator=(floating &&);
    ~floating();

private:
    QSharedDataPointer<floatingData> data;
};

#endif // FLOATING_H
