#ifndef BEMO_MULTIPLYNODE_HH
#define BEMO_MULTIPLYNODE_HH

#include <BCore/util/Log.hh>
#include <BCore/object/AbstractNode.hh>
#include <BCore/system/NodeSystem.hh>
#include <BCore/system/PlugSystem.hh>


namespace bemo {

class MultiplyNode : public AbstractNode {
public:
    int execute() override {
        bool result;
        PlugSystem fnPlug( getID() );
        long valueA = fnPlug.getInput( "valueA" ).toLong( &result );
        long valueB = fnPlug.getInput( "valueB" ).toLong( &result );
        fnPlug.setOutput( "result", Variant( valueA * valueB ) );
        return 0;
    }
};

AbstractNode* multiplyCreate() {
    return new MultiplyNode();
}

void multiplyLayout( ObjectID nodeID ) {
    NodeSystem sys( nodeID );
    sys.setHeader( "Multiply two numbers and set the result.",
                   "icons/mult16px.png" );
    sys.addPlug( "valueA",
                 PlugDirectionPolicy::Input,
                 PlugAccessPolicy::Single,
                 PlugCastPolicy::Anything,
                 VariantType::Long,
                 false );
    sys.addPlug( "valueB",
                 PlugDirectionPolicy::Input,
                 PlugAccessPolicy::Single,
                 PlugCastPolicy::Anything,
                 VariantType::Long,
                 false );
    sys.addPlug( "result",
                 PlugDirectionPolicy::Output,
                 PlugAccessPolicy::Single,
                 PlugCastPolicy::Anything,
                 VariantType::Long,
                 false );

}

}

#endif // BEMO_SUM_HH
