#ifndef BEMO_EVENTS_HH
#define BEMO_EVENTS_HH

#include <BCore/internal/Object.hh>

namespace bemo {

class AbstractEvent {
public:
    virtual ~AbstractEvent() {}
};

class NodeCreatedEvent : public AbstractEvent {
public:
    explicit NodeCreatedEvent( ObjectID id ) : m_id( id ) {}
    ObjectID getNodeID() const { return m_id; }
private:
    ObjectID m_id;
};

class NodeRemovedEvent : public AbstractEvent {
public:
    explicit NodeRemovedEvent( ObjectID id ) : m_id( id ) {}
    ObjectID getNodeID() const { return m_id; }
private:
    ObjectID m_id;
};

class NodeConnectedEvent : public AbstractEvent {
public:
    explicit NodeConnectedEvent( ObjectID source, ObjectID target )
        : m_source( source ),
          m_target( target ) {}
    ObjectID getSourceNodeID() const { return m_source; }
    ObjectID getTargetNodeID() const { return m_target; }
private:
    ObjectID m_source;
    ObjectID m_target;
};


class NodeDisconnectedEvent : public AbstractEvent {
public:
    explicit NodeDisconnectedEvent( ObjectID source, ObjectID target )
            : m_source( source ),
              m_target( target ) {}
    ObjectID getSourceNodeID() const { return m_source; }
    ObjectID getTargetNodeID() const { return m_target; }
private:
    ObjectID m_source;
    ObjectID m_target;
};

}

#endif // BEMO_EVENTS_HH
