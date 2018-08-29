#include <gtest/gtest.h>
#include <utility>

#include "../Common.hh"

#include <BCore/Bemo.hh>
#include <BCore/util/Log.hh>
//#include <BCore/managers/PluginManager.hh>
//#include <BCore/managers/NodeManager.hh>
#include <BCore/object/AbstractNode.hh>
#include <BCore/object/Node.hh>
#include <BCore/store/SumNode.hh>
#include <BCore/store/SnippetNode.hh>

using namespace bemo;

TEST_F( BemoAPI, PluginManager_ctro ) {
    SumNode* nodeA = new SumNode();
    AbstractNode* nodeB = new SumNode();
    BMO_ERROR << "nodeA=" << nodeA->nodeTypeID();
    BMO_ERROR << "nodeB=" << nodeB->nodeTypeID();
    BMO_ERROR << "id=" << SumNode::NODE_TYPE_ID;

    SnippetNode* nodeC = new SnippetNode();
    AbstractNode* nodeD = new SnippetNode();
    BMO_ERROR << "nodeC=" << nodeC->nodeTypeID();
    BMO_ERROR << "nodeD=" << nodeD->nodeTypeID();
    BMO_ERROR << "id=" << SnippetNode::NODE_TYPE_ID;
}
