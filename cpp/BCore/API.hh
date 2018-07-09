#ifndef BEMO_API_HH
#define BEMO_API_HH

namespace bemo {

class ContainerManager;

extern ContainerManager* BMO_ContainerManager;

extern void initialize();
extern void terminate();

}

#endif // BEMO_API_HH
