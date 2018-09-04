#ifndef BEMO_EVENTS_HH
#define BEMO_EVENTS_HH

#include <BCore/internal/Object.hh>

namespace bemo {

int increment();

class AbstractEvent {
public:
    explicit AbstractEvent( int typeID ) : m_eventTypeID( typeID ) {}
    virtual ~AbstractEvent() {}
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
    explicit NodeCreatedEvent( ObjectID id );
    ObjectID getNodeID() const;
private:
    ObjectID m_id;
};

class NodeRemovedEvent : public Event< NodeRemovedEvent > {
public:
    explicit NodeRemovedEvent( ObjectID id );
    ObjectID getNodeID() const;
private:
    ObjectID m_id;
};

class NodeConnectedEvent : public Event< NodeConnectedEvent > {
public:
    explicit NodeConnectedEvent( ObjectID source, ObjectID target );
    ObjectID getSourceNodeID() const;
    ObjectID getTargetNodeID() const;
private:
    ObjectID m_source;
    ObjectID m_target;
};


class NodeDisconnectedEvent : public Event< NodeDisconnectedEvent > {
public:
    explicit NodeDisconnectedEvent( ObjectID source, ObjectID target );
    ObjectID getSourceNodeID() const;
    ObjectID getTargetNodeID() const;
private:
    ObjectID m_source;
    ObjectID m_target;
};

}

#endif // BEMO_EVENTS_HH
