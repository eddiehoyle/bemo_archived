#ifndef BEMO_GRAPH_HH
#define BEMO_GRAPH_HH

#include <vector>
#include <Node.hh>

namespace bemo {

class Graph {
public:
    void add( NodePtr node );
    void remove( NodePtr node );
    std::size_t get_count() const;
    int execute() {
        for ( NodePtr node : m_nodes ) {
            int rc = node->execute();
            if ( rc != 0 ) {
                break;
            }
        }
        return 0;
    }
private:
    std::vector< NodePtr > m_nodes;
};

}

#endif // BEMO_GRAPH_HH