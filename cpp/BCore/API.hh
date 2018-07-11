#ifndef BEMO_API_HH
#define BEMO_API_HH

namespace bemo {

class ContainerManager;
class ObjectManager;

extern ContainerManager* BMO_ContainerManager;
extern ObjectManager* BMO_ObjectManager;

extern void initialize();
extern void terminate();

}

#endif // BEMO_API_HH
