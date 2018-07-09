#ifndef BEMO_ABSTRACTCONTAINER_HH
#define BEMO_ABSTRACTCONTAINER_HH

#include <BCore/Platform.hh>

namespace bemo {

class AbstractContainer;
class ContainerManager;

using ContainerID = ObjectID;
using ContainerTypeID = TypeID;
using ContainerIDs = std::vector< ContainerID >;
using AbstractContainers = std::list< AbstractContainer* >;

class AbstractContainer {

    friend class ContainerManager;

public:
    ContainerID id() const { return m_id; }
    AbstractContainer* getParent() const;
    AbstractContainers getChildren() const;
    void setParent( AbstractContainer* parent );

protected:
    AbstractContainer() = default;
    virtual ~AbstractContainer() = default;
    virtual int _execute() = 0;

protected:
    ContainerID m_id;
    ContainerManager* m_manager;

    ContainerID m_parent;
    ContainerIDs m_children;
};

} // namespace bemo

#endif // BEMO_ABSTRACTCONTAINER_HH
