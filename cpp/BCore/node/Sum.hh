#ifndef BEMO_SUM_HH
#define BEMO_SUM_HH

#include <BCore/util/Log.hh>
#include <BCore/object/AbstractNode.hh>
#include <BCore/system/NodeSystem.hh>


namespace bemo {

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
    sys.setHeader( "Some description", "icons/PyNode.png" );
    sys.addPlug( "cpp_valueA",
                 PlugDirectionPolicy::Input,
                 PlugAccessPolicy::Single,
                 PlugCastPolicy::Anything,
                 VariantType::Int,
                 false );
    sys.addPlug("cpp_valueB",
                PlugDirectionPolicy::Input,
                PlugAccessPolicy::Single,
                PlugCastPolicy::Anything,
                VariantType::Int,
                false );
};

}

#endif // BEMO_SUM_HH
