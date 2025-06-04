#include "waterwalking.h"

#include <utility>

class waterWalkingData : public QSharedData
{
public:
};

waterWalking::waterWalking()
    : data(new waterWalkingData)
{}

waterWalking::waterWalking(const waterWalking &rhs)
    : data{rhs.data}
{}

waterWalking::waterWalking(waterWalking &&rhs)
    : data{std::move(rhs.data)}
{}

waterWalking &waterWalking::operator=(const waterWalking &rhs)
{
    if (this != &rhs)
        data = rhs.data;
    return *this;
}

waterWalking &waterWalking::operator=(waterWalking &&rhs)
{
    if (this != &rhs)
        data = std::move(rhs.data);
    return *this;
}

waterWalking::~waterWalking() {}
