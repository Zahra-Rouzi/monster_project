#include "flying.h"

#include <utility>

class flyingData : public QSharedData
{
public:
};

flying::flying()
    : data(new flyingData)
{}

flying::flying(const flying &rhs)
    : data{rhs.data}
{}

flying::flying(flying &&rhs)
    : data{std::move(rhs.data)}
{}

flying &flying::operator=(const flying &rhs)
{
    if (this != &rhs)
        data = rhs.data;
    return *this;
}

flying &flying::operator=(flying &&rhs)
{
    if (this != &rhs)
        data = std::move(rhs.data);
    return *this;
}

flying::~flying() {}
