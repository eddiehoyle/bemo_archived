#ifndef BEMO_DAGVERTEX_HH
#define BEMO_DAGVERTEX_HH

namespace bemo {


class Vertex {
public:
    explicit Vertex( ObjectID value ) : m_value( value ), m_deps() {}
    Vertex( const Vertex& vtx ) = delete;
    Vertex& operator=( const Vertex& vtx ) = delete;
    ObjectID value() const { return m_value; }
    void add( Vertex* vtx ) { m_deps.insert( vtx ); }
    bool has( Vertex* vtx ) const { return m_deps.find( vtx ) != m_deps.end(); }
    void remove( Vertex* vtx ) { m_deps.erase( vtx ); }
    const std::set< Vertex* >& get() const { return m_deps; }

private:
    ObjectID m_value;
    std::set< Vertex* > m_deps;
};


}

#endif // BEMO_DAGVERTEX_HH
