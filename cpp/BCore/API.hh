#ifndef BEMO_API_HH
#define BEMO_API_HH

namespace bemo {

class GraphManager;
class ObjectManager;

extern GraphManager* BMO_GraphManager;
extern ObjectManager* BMO_ObjectManager;

extern void initialize();
extern void terminate();

}

#endif // BEMO_API_HH
