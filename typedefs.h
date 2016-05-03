#ifndef TYPEDEFS
#define TYPEDEFS

struct Position2D
{
    float x;
    float y;

    //***PRZECIAZANIE OPERATOROW***
    Position2D operator-(const Position2D& pos) {
        Position2D position;
        position.x = this->x - pos.x;
        position.y = this->y - pos.y;
        return position;
    }

    Position2D operator*(const float& pos) {
        Position2D position;
        position.x = this->x * pos;
        position.y = this->y * pos;
        return position;
    }
    //***KONIEC PRZECIAZANIA***
};

struct Velocity2D
{
    float xVelocity;
    float yVelocity;

    //***PRZECIAZANIE OPERATOROW***
    Velocity2D operator+(const Velocity2D& vel) {
        Velocity2D velocity;
        velocity.xVelocity = this->xVelocity + vel.xVelocity;
        velocity.yVelocity = this->yVelocity + vel.yVelocity;
        return velocity;
    }

    Velocity2D operator-(const Velocity2D& vel) {
        Velocity2D velocity;
        velocity.xVelocity = this->xVelocity - vel.xVelocity;
        velocity.yVelocity = this->yVelocity - vel.yVelocity;
        return velocity;
    }

    Velocity2D operator*(const float& vel) {
        Velocity2D velocity;
        velocity.xVelocity = this->xVelocity * vel;
        velocity.yVelocity = this->yVelocity * vel;
        return velocity;
    }

    Velocity2D operator/(const float& flo) {
        Velocity2D velocity;
        velocity.xVelocity = this->xVelocity / flo;
        velocity.yVelocity = this->yVelocity / flo;
        return velocity;
    }

    Velocity2D operator+=(const Velocity2D& vel) {
        xVelocity += vel.xVelocity;
        yVelocity += vel.yVelocity;
        return *this;
    }

    Velocity2D operator+=(const Position2D& pos) {
        xVelocity += pos.x;
        yVelocity += pos.y;
        return *this;
    }

    Velocity2D operator-=(const Position2D& pos) {
        xVelocity -= pos.x;
        yVelocity -= pos.y;
        return *this;
    }

    Velocity2D operator=(const float& flo) {
        xVelocity = flo;
        yVelocity = flo;
        return *this;
    }

    //***KONIEC PRZECIAZANIA***
};

struct Size2D
{
    float xSize;
    float ySize;
};

#endif // TYPEDEFS

