#ifndef BEMO_ABSTRACTCONTAINER_HH
#define BEMO_ABSTRACTCONTAINER_HH

#include <BCore/Platform.hh>

namespace bemo {

class ContainerManager;

using ContainerID = ObjectID;
using ContainerTypeID = TypeID;

class AbstractContainer {

    friend class ContainerManager;

public:
    ContainerID id() const { return m_id; }

protected:
    explicit AbstractContainer( ContainerID id ) : m_id( id ), m_manager( nullptr ) {}
    virtual ~AbstractContainer() = default;
    virtual int execute() = 0;
protected:
    ContainerID m_id;
private:
    ContainerManager* m_manager;
};

} // namespace bemo

#endif // BEMO_ABSTRACTCONTAINER_HH
