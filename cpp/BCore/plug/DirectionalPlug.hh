#ifndef BEMO_INPUTPLUG_HH
#define BEMO_INPUTPLUG_HH

#include "Plug.hh"

namespace bemo {

enum class Direction {
    Input,
    Output,
};

class DirectionalPlug : public Plug< DirectionalPlug > {
public:
    explicit DirectionalPlug( PlugID id, Direction direction )
            : Plug( id ),
              m_direction( direction ) {}
    ~DirectionalPlug() override = default;
protected:
    Direction m_direction;
};

class InputPlug : public DirectionalPlug {
public:
    explicit InputPlug( PlugID id ) : DirectionalPlug( id, Direction::Input ) {}
    ~InputPlug() override = default;
};

class OutputPlug : public DirectionalPlug {
public:
    explicit OutputPlug( PlugID id ) : DirectionalPlug( id, Direction::Output ) {}
    ~OutputPlug() override = default;
};

}


#endif // BEMO_INPUTPLUG_HH
