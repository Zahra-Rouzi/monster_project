#ifndef FLYING_H
#define FLYING_H

#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>

class flyingData;

class flying
{
    Q_OBJECT
    QML_ELEMENT
public:
    flying();
    flying(const flying &);
    flying(flying &&);
    flying &operator=(const flying &);
    flying &operator=(flying &&);
    ~flying();

private:
    QSharedDataPointer<flyingData> data;
};

#endif // FLYING_H
