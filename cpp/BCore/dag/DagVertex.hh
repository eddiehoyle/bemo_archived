#ifndef BEMO_DAGVERTEX_HH
#define BEMO_DAGVERTEX_HH

namespace bemo {


class Vertex {
public:
    explicit Vertex( ObjectID value ) : m_value( value ), m_deps() {}
    ObjectID value() const { return m_value; }
    void add( Vertex* vtx ) { m_deps.insert( vtx ); }
    bool has( Vertex* vtx ) const { return m_deps.find( vtx ) != m_deps.end(); }
    bool has( ObjectID id ) const {
        return std::find_if( m_deps.begin(),
                             m_deps.end(),
                             [&]( Vertex* vertex ) {
                                 return vertex->value() == id;
                             } ) != m_deps.end();
    }
    void remove( Vertex* vtx ) { m_deps.erase( vtx ); }
    const std::set< Vertex* >& get() const { return m_deps; }

private:
    ObjectID m_value;
    std::set< Vertex* > m_deps;
};


}

#endif // BEMO_DAGVERTEX_HH
