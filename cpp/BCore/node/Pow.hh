#ifndef BEMO_SUM_HH
#define BEMO_SUM_HH

#include <BCore/util/Log.hh>
#include <BCore/object/AbstractNode.hh>
#include <BCore/system/NodeSystem.hh>


namespace bemo {

class PowNode : public AbstractNode {
public:
    int execute() override {
        bool result;
        int value = getInput( "value" ).toInt( &result );
        int base = getInput( "base" ).toInt( &result );
        return 0;
    }
};

using CppFnCreate = std::function< AbstractNode*() >;
using CppFnLayout = std::function< void( ObjectID ) >;

AbstractNode* powCreate() {
    return new PowNode();
}

void powLayout( ObjectID nodeID ) {
    NodeSystem sys( nodeID );
    sys.setHeader( "Computer the power of two values and set result.", "icons/pow16px.png" );
    sys.addPlug( "value",
                 PlugDirectionPolicy::Input,
                 PlugAccessPolicy::Single,
                 PlugCastPolicy::Anything,
                 VariantType::Int,
                 false );
    sys.addPlug("base",
                PlugDirectionPolicy::Input,
                PlugAccessPolicy::Single,
                PlugCastPolicy::Anything,
                VariantType::Int,
                false );
    sys.addPlug("result",
                PlugDirectionPolicy::Output,
                PlugAccessPolicy::Single,
                PlugCastPolicy::Anything,
                VariantType::Int,
                false );

}

//CppFnCreate a = [](){ return new CppNode(); };
//CppFnLayout b = [](ObjectID id ){
//    NodeSystem sys( id );
//    sys.setHeader( "Some description", "icons/PyNode.png" );
//    sys.addPlug( "cpp_valueA",
//                 PlugDirectionPolicy::Input,
//                 PlugAccessPolicy::Single,
//                 PlugCastPolicy::Anything,
//                 VariantType::Int,
//                 false );
//    sys.addPlug("cpp_valueB",
//                PlugDirectionPolicy::Input,
//                PlugAccessPolicy::Single,
//                PlugCastPolicy::Anything,
//                VariantType::Int,
//                false );
//};

}

#endif // BEMO_SUM_HH
