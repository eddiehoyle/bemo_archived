#ifndef BEMO_WORKSPACEMANAGER_HH
#define BEMO_WORKSPACEMANAGER_HH

#include <vector>

#include <BCore/object/ObjectID.hh>

#include <pybind11/stl.h>
#include <pybind11/eval.h>
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>

namespace bemo {

class Workspace;

class WorkspaceManager {
public:
    static WorkspaceManager& instance();
public:
    WorkspaceManager(WorkspaceManager const&) = delete;
    void operator=(WorkspaceManager const&) = delete;
public:
    ObjectID create(const std::string& type, const std::string& name);
    Workspace* find(ObjectID id) const;
private:
    WorkspaceManager() {}
    std::vector<Workspace*> m_workspaces;
};

}

#endif // BEMO_WORKSPACEMANAGER_HH
