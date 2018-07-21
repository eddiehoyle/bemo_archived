#ifndef BEMO_ADDNODE_HH
#define BEMO_ADDNODE_HH

#include <BCore/object/Node.hh>

namespace bemo {

class AddNode : public Node {
public:
    explicit AddNode( ObjectID id ) : Node( id ) {}
    int execute() override {
        int valueA = getInput( "valueA" );
        int valueB = getInput( "valueB" );
        setOutput( "valueB", valueA + valueB );
        BMO_ERROR << "valueA=" << valueA
                  << ", valueB=" << valueB
                  << ", result=" << ( valueA + valueB );
    }
};

}

#endif // BEMO_ADDNODE_HH
