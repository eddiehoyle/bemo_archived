#ifndef BEMO_LOG_HH
#define BEMO_LOG_HH

#include <mutex>
#include <ostream>

namespace bemo {

enum class Level {
    Debug,
    Info,
    Warning,
    Error,
};

class Stream;
class NullStream;

class Log {
public:
    Log( std::ostream* stream, Level level );
private:
    std::mutex m_mutex;
    std::ostream* m_stream;
    Level m_level;

    friend Stream;
    friend NullStream;
};

class Stream {
public:
    explicit Stream( Log& log, const std::string& prefix  );
    ~Stream();

    template< typename T >
    Stream& operator<<( T value );

private:
    Stream( Stream& ) = delete;
    Stream& operator=( Stream& ) = delete;
    Stream& operator=( Stream&& ) = delete;

    Log& m_log;
};

template< typename T >
Stream& Stream::operator<<( T value ) {
    *( m_log.m_stream ) << value;
    return *this;
}

class NullStream {
public:
    explicit NullStream( Log& log, const std::string& prefix );
    ~NullStream() = default;

    template< typename T >
    NullStream& operator<<( T value );

private:
    NullStream( NullStream& ) = delete;
    NullStream& operator=( Stream& ) = delete;
    NullStream& operator=( NullStream&& ) = delete;

    Log& m_log;
};

template< typename T >
NullStream& NullStream::operator<<( T value ) {
    return *this;
}

Log& debug_log();
Log& info_log();
Log& warn_log();
Log& error_log();

} // namespace bemo

#define BMO_INITIALISE_LOG() \
    ::bemo::debug_log();     \
    ::bemo::info_log();      \
    ::bemo::warn_log();      \
    ::bemo::error_log();

#ifdef BMO_LOGGING_ENABLED
#define BMO_DEBUG ::bemo::Stream( ::bemo::debug_log(), "DBG" ) << "[" << __FUNCTION__ << "]: "
#define BMO_INFO ::bemo::Stream( ::bemo::info_log(), "NFO" ) << "[" << __FUNCTION__ << "]: "
#define BMO_WARN ::bemo::Stream( ::bemo::warn_log(), "WRN" ) << "[" << __FUNCTION__ << "]: "
#define BMO_ERROR ::bemo::Stream( ::bemo::error_log(), "ERR" ) << "[" << __FUNCTION__ << "]: "
#else
#define BMO_DEBUG ::bemo::NullStream( ::bemo::debug_log(), "DBG" )
#define BMO_INFO ::bemo::NullStream( ::bemo::info_log(), "NFO" )
#define BMO_WARN ::bemo::NullStream( ::bemo::warn_log(), "WRN" )
#define BMO_ERROR ::bemo::NullStream( ::bemo::error_log(), "ERR" )
#endif

#endif // BEMO_LOG_HH
