#ifndef BEMO_EVENTS_HH
#define BEMO_EVENTS_HH

#include <old/BCore/internal/Object.hh>

namespace bemo {

int increment();

class AbstractEvent {
public:
    explicit AbstractEvent( int typeID ) : m_eventTypeID( typeID ) {}
    virtual ~AbstractEvent() = default;
    virtual int getEventTypeID() const { return m_eventTypeID; }
private:
    int m_eventTypeID;
};

template< typename E >
class Event : public AbstractEvent {
public:
    static const int EVENT_TYPE_ID;
public:
    Event() : AbstractEvent( EVENT_TYPE_ID ) {}
};

template< typename E >
const int Event< E >::EVENT_TYPE_ID = { increment() };

class NodeCreatedEvent : public Event< NodeCreatedEvent > {
public:
    explicit NodeCreatedEvent( ObjectID nodeID );
    ObjectID getNodeID() const;
private:
    ObjectID m_nodeID;
};

class NodeRemovedEvent : public Event< NodeRemovedEvent > {
public:
    explicit NodeRemovedEvent( ObjectID nodeID );
    ObjectID getNodeID() const;
private:
    ObjectID m_nodeID;
};

class PlugConnectedEvent : public Event< PlugConnectedEvent > {
public:
    explicit PlugConnectedEvent( ObjectID sourcePlugID, ObjectID targetPlugID );
    ObjectID getSourcePlugID() const;
    ObjectID getTargetPlugID() const;
private:
    ObjectID m_sourcePlugID;
    ObjectID m_targetPlugID;
};


class PlugDisconnectedEvent : public Event< PlugDisconnectedEvent > {
public:
    explicit PlugDisconnectedEvent( ObjectID sourcePlugID, ObjectID targetPlugID );
    ObjectID getSourcePlugID() const;
    ObjectID getTargetPlugID() const;
private:
    ObjectID m_sourcePlugID;
    ObjectID m_targetPlugID;
};

}

#endif // BEMO_EVENTS_HH
