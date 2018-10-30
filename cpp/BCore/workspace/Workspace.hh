#ifndef BEMO_WORKSPACE_HH
#define BEMO_WORKSPACE_HH

#include <vector>
#include <BCore/object/ObjectID.hh>

namespace bemo {

class Workspace {
public:
    Workspace() = default;
    ~Workspace() = default;

    bool isValid() const;

    inline ObjectID getObjectID() const { return m_objectID; }
    inline std::string getType() const { return m_type; }

    ObjectID createTask( const std::string& type, const std::string& name );
    bool removeTask( ObjectID taskId );

private:
    std::vector< ObjectID > m_tasks;
    ObjectID m_id;

    ObjectID m_objectID;
    std::string m_type;
};

}

#endif // BEMO_WORKSPACE_HH
