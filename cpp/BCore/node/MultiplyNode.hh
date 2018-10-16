#ifndef BEMO_MULTIPLYNODE_HH
#define BEMO_MULTIPLYNODE_HH

#include <BCore/object/Node.hh>
#include <BCore/plugin/PluginManager.hh>
#include <BCore/plugin/PluginSystem.hh>


namespace bemo {

class MultiplyNode : public BDagNode {
public:
//    using BDagNode::BDagNode;
    MultiplyNode() { BMO_ERROR << "ctor=" << (void*)this; }
    ~MultiplyNode() override { BMO_ERROR << "dtor=" << (void*)this; }
    int execute() override {
//        bool result;
//        PlugSystem fnPlug( getID() );
//        long valueA = fnPlug.getInput( "valueA" ).toLong( &result );
//        long valueB = fnPlug.getInput( "valueB" ).toLong( &result );
//        fnPlug.setOutput( "result", Variant( valueA * valueB ) );
//        BMO_ERROR << "setting result=" << fnPlug.getOutput( "result" ).toLong( &result );
        BMO_ERROR << "executing";
        return 0;
    }
};

Object* multiplyCreate() {
    return new MultiplyNode();
}


//void multiplyLayout( ObjectID nodeID ) {
//    NodeSystem sys( nodeID );
//    sys.setHeader( "Multiply two numbers and set the result.",
//                   "icons/mult16px.png" );
//    sys.addPlug( "valueA",
//                 PlugDirectionPolicy::Input,
//                 PlugAccessPolicy::Single,
//                 PlugCastPolicy::Anything,
//                 VariantType::Long,
//                 false );
//    sys.addPlug( "valueB",
//                 PlugDirectionPolicy::Input,
//                 PlugAccessPolicy::Single,
//                 PlugCastPolicy::Anything,
//                 VariantType::Long,
//                 false );
//    sys.addPlug( "result",
//                 PlugDirectionPolicy::Output,
//                 PlugAccessPolicy::Single,
//                 PlugCastPolicy::Anything,
//                 VariantType::Long,
//                 false );
//
//}

}

#endif // BEMO_SUM_HH
