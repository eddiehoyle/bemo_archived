#include <cmath>
#include "Variant.hh"
#include <BCore/util/Log.hh>

namespace bemo {

Variant Variant::invalid() {
    static Variant var;
    return var;
}

Variant::Variant()
    : m_type( VariantType::Null ),
      m_data( nullptr ) {}

Variant::Variant( int value )
    : m_type( VariantType::Int ),
      m_data( nullptr ) {
    m_data = static_cast< void* >( new int( value ) );
}

Variant::Variant( float value )
        : m_type( VariantType::Float ),
          m_data( nullptr ) {
    m_data = static_cast< float* >( new float( value ) );
}

Variant::Variant( const std::string& value )
        : m_type( VariantType::String ),
          m_data( nullptr ) {
    m_data = static_cast< std::string* >( new std::string( value ) );
}

Variant::Variant( const Variant& var ) {

    if ( this == &var ) {
        return;
    }

    bool result;
    switch ( var.type() ) {
        case VariantType::Int:
            m_data = static_cast< void* >( new int( var.toInt( &result ) ) );
            m_type = var.type();
            break;
        case VariantType::Float:
            m_data = static_cast< void* >( new float( var.toFloat( &result ) ) );
            m_type = var.type();
            break;
        case VariantType::String:
            m_data = static_cast< void* >( new std::string( var.toString( &result ) ) );
            m_type = var.type();
            break;
        case VariantType::Null:
        default:
            m_type = VariantType::Null;
            break;
    }
}

Variant& Variant::operator=( const Variant& var ) {

    if ( this == &var ) {
        return *this;
    }

    bool result;
    switch ( var.type() ) {
        case VariantType::Int:
            m_data = static_cast< void* >( new int( var.toInt( &result ) ) );
            m_type = var.type();
            break;
        case VariantType::Float:
            m_data = static_cast< void* >( new float( var.toFloat( &result ) ) );
            m_type = var.type();
            break;
        case VariantType::String:
            m_data = static_cast< void* >( new std::string( var.toString( &result ) ) );
            m_type = var.type();
            break;
        case VariantType::Null:
        default:
            m_type = VariantType::Null;
            break;
    }
    return *this;
}

Variant::~Variant() {
    clear();
}

void Variant::clear() {

    switch ( m_type ) {
        case VariantType::Int:
            delete static_cast< int* >( m_data );
            m_data = nullptr;
            break;
        case VariantType::Float:
            delete static_cast< float* >( m_data );
            m_data = nullptr;
            break;
        case VariantType::String:
            delete static_cast< std::string* >( m_data );
            m_data = nullptr;
            break;
        case VariantType::Null:
        default:
            ;
    }

    if ( m_data == nullptr ) {
        m_type = VariantType::Null;
    }
}

void Variant::reset( const Variant& var ) {

    clear();

    bool result;
    switch( var.type() ) {
        case VariantType::Int:
            m_data = new int( var.toInt( &result ) );
            break;
        case VariantType::Float:
            m_data = new float( var.toFloat( &result ) );
            break;
        case VariantType::String:
            m_data = new std::string( var.toString( &result ) );
            break;
        case VariantType::Null:
        default:
            ;
    }

    m_type = var.m_type;
}

VariantType Variant::type() const {
    return m_type;
}

int Variant::toInt( bool* result ) const {
    int value = 0;
    switch ( m_type ) {
        case VariantType::Int:
        case VariantType::Float:
            value = *static_cast< int* >( m_data );
            *result = true;
            break;
        case VariantType::String:
            try {
                value = std::stoi( ( *static_cast< std::string* >( m_data ) ) );
                *result = true;
            } catch ( ... ) {}
            break;
        case VariantType::Null:
        default:
            ;
    }
    return value;
}

float Variant::toFloat( bool* result ) const {
    float value = 0;
    switch ( m_type ) {
        case VariantType::Int:
        case VariantType::Float:
            value = *static_cast< float* >( m_data );
            *result = true;
            break;
        case VariantType::String:
            try {
                value = std::stof( ( *static_cast< std::string* >( m_data ) ) );
                *result = true;
            } catch ( ... ) {}
            break;
        case VariantType::Null:
        default:
            ;
    }
    return value;
}

std::string Variant::toString( bool* result ) const {
    std::string value;
    switch ( m_type ) {
        case VariantType::Int:
            value = std::to_string( *static_cast< int* >( m_data ) );
            *result = true;
        case VariantType::Float:
            value = std::to_string( *static_cast< float* >( m_data ) );
            *result = true;
            break;
        case VariantType::String:
            value = *static_cast< std::string* >( m_data );
            break;
        case VariantType::Null:
        default:
            ;
    }
    return value;
}


}