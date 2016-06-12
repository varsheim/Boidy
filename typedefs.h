#ifndef TYPEDEFS
#define TYPEDEFS
/*!
 * \brief The Size2D struct, used to describe size of an element
 */
struct Size2D
{
    /*!
     * \brief float value representing X size
     */
    float xSize;
    /*!
     * \brief float value representing Y size
     */
    float ySize;
};

/*!
 * \brief The Position2D struct, used to describe position of an element. Also contains a few operator overloaders
 */
struct Position2D
{
    /*!
     * \brief float value representing X position
     */
    float x;
    /*!
     * \brief float value representing Y position
     */
    float y;

    //***PRZECIAZANIE OPERATOROW***
    /*!
     * \brief Operator + overload, allows to add Position2D struct to Size2D struct
     * \param size Size2D sruct
     * \return Position2D type, containing added X & Y values of Position2D and Size2D structs
     */
    Position2D operator+(const Size2D& size) {
        Position2D position;
        position.x = this->x + size.xSize;
        position.y = this->y + size.ySize;
        return position;
    }
    /*!
     * \brief Operator - overload, allows to substract Position2D structs
     * \param pos Position2D struct
     * \return Position2D type, containing substracted X & Y values of Position2D structs
     */
    Position2D operator-(const Position2D& pos) {
        Position2D position;
        position.x = this->x - pos.x;
        position.y = this->y - pos.y;
        return position;
    }
    /*!
     * \brief Operator - overload, allows to substract Size2D structs from Position2D structs
     * \param size Size2D struct
     * \return Position2D type, containing substracted X & Y values of both structs
     */
    Position2D operator-(const Size2D& size) {
        Position2D position;
        position.x = this->x - size.xSize;
        position.y = this->y - size.ySize;
        return position;
    }
    /*!
     * \brief Operator * overload, allows to multiply Position2D struct with float value
     * \param pos float value
     * \return Position2D type, multiplied both X & Y members by float value
     */
    Position2D operator*(const float& pos) {
        Position2D position;
        position.x = this->x * pos;
        position.y = this->y * pos;
        return position;
    }
    //***KONIEC PRZECIAZANIA***
};
/*!
 * \brief The Velocity2D struct, used to describe velocity of an element. Also contains a few oprator overloaders
 */
struct Velocity2D
{
    /*!
     * \brief float value representing X velocity
     */
    float xVelocity;
    /*!
     * \brief float value representing Y velocity
     */
    float yVelocity;

    //***PRZECIAZANIE OPERATOROW***
    /*!
     * \brief Operator + overload, allows to add Velocity2D structs
     * \param vel Velocity2D struct
     * \return Velocity2D type, added X & Y members of Velocity2D structs
     */
    Velocity2D operator+(const Velocity2D& vel) {
        Velocity2D velocity;
        velocity.xVelocity = this->xVelocity + vel.xVelocity;
        velocity.yVelocity = this->yVelocity + vel.yVelocity;
        return velocity;
    }
    /*!
     * \brief Operator - overload, allows to substract Velocity2D structs
     * \param vel Velocity2D struct
     * \return Velocity2D type, contains difference of X & Y members of Velocity2D structs
     */
    Velocity2D operator-(const Velocity2D& vel) {
        Velocity2D velocity;
        velocity.xVelocity = this->xVelocity - vel.xVelocity;
        velocity.yVelocity = this->yVelocity - vel.yVelocity;
        return velocity;
    }
    /*!
     * \brief Operator * overload, allows to multiply Velocity2D struct with float value
     * \param vel float value
     * \return Velocity2D type, contains X & Y members multipled by the float value
     */
    Velocity2D operator*(const float& vel) {
        Velocity2D velocity;
        velocity.xVelocity = this->xVelocity * vel;
        velocity.yVelocity = this->yVelocity * vel;
        return velocity;
    }
    /*!
     * \brief Operator / overload, allows to divide Velocity2D struct by float value
     * \param flo float value
     * \return Velocity2D type, contains X & Y members divided by the float value
     */
    Velocity2D operator/(const float& flo) {
        Velocity2D velocity;
        velocity.xVelocity = this->xVelocity / flo;
        velocity.yVelocity = this->yVelocity / flo;
        return velocity;
    }
    /*!
     * \brief Operator += overload, allows to assign Velocity2D structs
     * \param vel Velocity2D struct
     * \return Velocity2D struct, its X & Y members are assigned by operator += with members of another Velocity2D struct
     */
    Velocity2D operator+=(const Velocity2D& vel) {
        xVelocity += vel.xVelocity;
        yVelocity += vel.yVelocity;
        return *this;
    }
    /*!
     * \brief Operator += overload, allows to assign Velocity2D struct with Position2D struct
     * \param vel Velocity2D struct
     * \return Velocity2D struct, its X & Y members are assigned by operator += with members of Position2D struct
     */
    Velocity2D operator+=(const Position2D& pos) {
        xVelocity += pos.x;
        yVelocity += pos.y;
        return *this;
    }
    /*!
     * \brief Operator -= overload, allows to assign Velocity2D struct with Position2D struct
     * \param vel Velocity2D struct
     * \return Velocity2D struct, its X & Y members are assigned by operator -= with members of Position2D struct
     */
    Velocity2D operator-=(const Position2D& pos) {
        xVelocity -= pos.x;
        yVelocity -= pos.y;
        return *this;
    }
    /*!
     * \brief Operator = overload, allows to assign float value to Velocity2D struct
     * \param flo float value
     * \return Velocity2D struct, the float value is assigned by = operator to X & Y members of the struct
     */
    Velocity2D operator=(const float& flo) {
        xVelocity = flo;
        yVelocity = flo;
        return *this;
    }

    //***KONIEC PRZECIAZANIA***
};


#endif // TYPEDEFS

