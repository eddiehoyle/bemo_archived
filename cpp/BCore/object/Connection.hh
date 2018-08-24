#ifndef BEMO_CONNECTION_HH
#define BEMO_CONNECTION_HH

#include <vector>
#include <BCore/internal/Object.hh>
#include <BCore/Variant.hh>

namespace bemo {


class Connection {

    friend class ConnectionManager;

public:
    explicit Connection( const ObjectID& sourceID,
                         const ObjectID& targetID )
            : m_id(),
              m_sourceID( sourceID ),
              m_targetID( targetID ) {}

    inline ObjectID getID() const { return m_id; }
    inline ObjectID getSourceID() const { return m_sourceID; }
    inline ObjectID getTargetID() const { return m_targetID; }

private:
    ObjectID m_id;
    ObjectID m_sourceID;
    ObjectID m_targetID;
};

}

#endif // BEMO_CONNECTION_HH
