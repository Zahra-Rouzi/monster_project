#include "grounded.h"
#include "agent.h"

#include <utility>

class GroundedData : public Agent
{
public:
};

/*Grounded::Grounded()
    : data(new GroundedData)
{}

Grounded::Grounded(const Grounded &rhs)
    : data{rhs.data}
{}

Grounded::Grounded(Grounded &&rhs)
    : data{std::move(rhs.data)}
{}

Grounded &Grounded::operator=(const Grounded &rhs)
{
    if (this != &rhs)
        data = rhs.data;
    return *this;
}

Grounded &Grounded::operator=(Grounded &&rhs)
{
    if (this != &rhs)
        data = std::move(rhs.data);
    return *this;
}

Grounded::~Grounded() {}
*/
