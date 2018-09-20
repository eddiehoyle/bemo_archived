#ifndef BEMO_PLUGSYSTEM_HH
#define BEMO_PLUGSYSTEM_HH

#include <vector>
#include <BCore/internal/Object.hh>
#include <BCore/Bemo.hh>
#include <BCore/object/Plug.hh>

namespace bemo {

class PlugSystem {
public:
    explicit PlugSystem( const ObjectID& id ) : m_id( id ) {}

    std::vector< PlugName > getInputs() const;
    std::vector< PlugName > getOutputs() const;

    void setInput( const std::string& name, const Variant& var );
    void setOutput( const std::string& name, const Variant& var );

    Variant getInput( const PlugName& name );
    Variant getOutput( const PlugName& name );

    bool hasInput( const PlugName& name ) const;
    bool hasOutput( const PlugName& name ) const;
private:
    ObjectID m_id;
};

}

#endif // BEMO_PLUGSYSTEM_HH
