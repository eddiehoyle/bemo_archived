#include "MultiplyNode.hh"

namespace bemo {

MultiplyNode::MultiplyNode() {
    BMO_ERROR << "ctor=" << (void*)this;
}

MultiplyNode::~MultiplyNode() {
    BMO_ERROR << "dtor=" << (void*)this;
}

int MultiplyNode::execute() {
    bool result;
//        PlugSystem fnPlug( getID() );
//        long valueA = fnPlug.getInput( "valueA" ).toLong( &result );
//        long valueB = fnPlug.getInput( "valueB" ).toLong( &result );
//        fnPlug.setOutput( "result", Variant( valueA * valueB ) );
//        BMO_ERROR << "setting result=" << fnPlug.getOutput( "result" ).toLong( &result );
    BMO_ERROR << "executing";
    return 0;
}

pybind11::object multiplyCreate() {
    BDagNode* node = new MultiplyNode();
    return pybind11::cast( node );
}

void multiplyLayout( ObjectID nodeID ) {
    NodeSystem sys( nodeID );
    sys.setHeader( "Multiply",
                   "Multiply two numbers and set the result.",
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

//void REGISTER_NODE("multiply", multiplyCreate, multiplyLayout)
//NodeRegistry::instance().add("multiply", multiplyCreate, multiplyLayout);

}
