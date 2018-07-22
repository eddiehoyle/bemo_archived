#include <gtest/gtest.h>
#include <utility>

#include "../Common.hh"

#include <BCore/API.hh>
#include <BCore/util/Log.hh>
#include <BCore/managers/PluginManager.hh>
#include <BCore/managers/NodeManager.hh>
#include <BCore/object/Node.hh>

using namespace bemo;


class SumNode : public Node {
public:
    explicit SumNode( ObjectID id ) : Node( id ) {}

    int execute() override {
        int valueA = getInput( "valueA" );
        int valueB = getInput( "valueB" );
        setOutput( "valueB", valueA + valueB );
        BMO_ERROR << "valueA=" << valueA
                  << ", valueB=" << valueB
                  << ", result=" << ( valueA + valueB );
        return 0;
    }
public:
    const static TypeID m_nodeTypeID = 0x00;
};

static SumNode create() {
    return BMO_NodeManager->createNode< SumNode >();
}

TEST_F( BemoAPI, PluginManager_ctro ) {
    PluginManager manager;
    manager.registerNode< SumNode >( "Sum", 13,
                                     &create,
                                     &create,
                                     &create );
}
