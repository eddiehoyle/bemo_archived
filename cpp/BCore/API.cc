#include "API.hh"
#include <BCore/util/Log.hh>

#include <BCore/managers/NodeManager.hh>
#include <BCore/managers/PlugManager.hh>
#include <BCore/managers/PluginManager.hh>
#include <BCore/managers/ObjectManager.hh>
#include <BCore/managers/DataBlockManager.hh>
#include <BCore/managers/ConnectionManager.hh>

#include <BCore/system/PluginSystem.hh>
#include <BCore/system/NodeSystem.hh>

namespace bemo {

NodeManager* BMO_NodeManager = nullptr;
PlugManager* BMO_PlugManager = nullptr;
PluginManager* BMO_PluginManager = nullptr;
ObjectManager* BMO_ObjectManager = nullptr;
DataBlockManager* BMO_DataBlockManager = nullptr;
ConnectionManager* BMO_ConnectionManager = nullptr;

class CppNode : public AbstractNode {
public:
    int execute() override {
        BMO_ERROR << "Executing CppNode!";
        return 77;
    }
};

using CppFnCreate = std::function< AbstractNode*() >;
using CppFnLayout = std::function< void( ObjectID ) >;

CppFnCreate a = [](){ return new CppNode(); };
CppFnLayout b = [](ObjectID id ){
    NodeSystem sys( id );
    sys.setHeader("Some description", "icons/PyNode.png");
    sys.addPlug("cpp_valueA", PlugDirection::Input, VariantType::Int, false, false);
    sys.addPlug("cpp_valueB", PlugDirection::Input, VariantType::Int, false, false);
};

void initialize() {

    BMO_INITIALISE_LOG()

    if ( BMO_ObjectManager == nullptr ) {
        BMO_ObjectManager = new ObjectManager();
    }
    if ( BMO_DataBlockManager == nullptr ) {
        BMO_DataBlockManager = new DataBlockManager();
    }
    if ( BMO_NodeManager == nullptr ) {
        BMO_NodeManager = new NodeManager();
    }
    if ( BMO_PlugManager == nullptr ) {
        BMO_PlugManager = new PlugManager();
    }
    if ( BMO_ConnectionManager == nullptr ) {
        BMO_ConnectionManager = new ConnectionManager();
    }
    if ( BMO_PluginManager == nullptr ) {
        BMO_PluginManager = new PluginManager();
        BMO_NodeManager->addBlueprint( "cpp",
                                       new CreateFuncWrapper< CppFnCreate >( a ),
                                       new LayoutFuncWrapper< CppFnLayout >( b ) );
    }

}

void terminate() {

    if ( BMO_ObjectManager != nullptr ) {
        delete BMO_ObjectManager;
        BMO_ObjectManager = nullptr;
    }

    if ( BMO_NodeManager != nullptr ) {
        delete BMO_NodeManager;
        BMO_NodeManager = nullptr;
    }

    if ( BMO_PlugManager != nullptr ) {
        delete BMO_PlugManager;
        BMO_PlugManager = nullptr;
    }

}

void send( const std::string& message ) {}

} // namespace bemo
