#include "Node.hh"
#include "ObjectManager.hh"

namespace bemo {

BDagNode::BDagNode() : Object( ObjectManager::instance().acquire() ) {}

}