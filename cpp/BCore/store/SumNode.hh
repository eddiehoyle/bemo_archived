#ifndef BEMO_ADDNODE_HH
#define BEMO_ADDNODE_HH

#include <BCore/object/Node.hh>

namespace bemo {
//
//class Header;
//class Layout;
//
//class AddNode;
//class AddHeader;
//class AddLayout;
//
//class AbstractBlueprint;
//
////typedef void* (*BCreatorFunction)();
////void* creator() { return BMO_NodeManager->create< AddNode >(); }
////void* header() { return BMO_HeaderManager->create< AddHeader >(); }
////void* layout() { return BMO_LayoutManager->create< AddLayout >(); }
//
//class AddHeader : public AbstractObject {
//public:
//    explicit AddHeader( ObjectHandle id )
//            : AbstractObject( id ),
//              m_name( "Add" ),
//              m_icon( "add.png" ),
//              m_description( "Add two values together." ) {}
//private:
//    std::string m_name;
//    std::string m_icon;
//    std::string m_description;
//};
//
//
//
//class AddLayout : public AbstractObject {
//public:
//    explicit AddLayout( ObjectHandle id )
//            : AbstractObject( id ) {
//        BMO_PlugManager->create( "valueA", Plug.Direction.Input, Plug.Type.Int, objectID() );
//        BMO_PlugManager->create( "valueB", Plug.Direction.Input, Plug.Type.Int, objectID() );
//        BMO_PlugManager->create( "result", Plug.Direction.Output, Plug.Type.Int, objectID() );
//    }
//
//};

class SumNode : public Node< NodeType::Sum > {
public:
    int execute() override { return 3; }
};

} // namespace bemo

#endif // BEMO_ADDNODE_HH
