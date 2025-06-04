#include "floating.h"

#include <utility>

class floatingData : public QSharedData
{
public:
};

floating::floating()
    : data(new floatingData)
{}

floating::floating(const floating &rhs)
    : data{rhs.data}
{}

floating::floating(floating &&rhs)
    : data{std::move(rhs.data)}
{}

floating &floating::operator=(const floating &rhs)
{
    if (this != &rhs)
        data = rhs.data;
    return *this;
}

floating &floating::operator=(floating &&rhs)
{
    if (this != &rhs)
        data = std::move(rhs.data);
    return *this;
}

floating::~floating() {}
