#ifndef BEMO_GROUP_HH
#define BEMO_GROUP_HH

#include <memory>
#include "Container.hh"

namespace bemo {

class Group;
using GroupPtr = std::shared_ptr< Group >;

/// Dynamic container that exposes children node's plugs
class Group : public Container< Group > {
};

/*
 * Graph0
 *  Node0
 *  Node1
 *   Group0
 *    Node2
 *    Node3
 *  Node4
 */

}

#endif // BEMO_GROUP_HH
