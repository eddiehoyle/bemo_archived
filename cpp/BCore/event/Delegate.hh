#ifndef BEMO_DELEGATE_HH
#define BEMO_DELEGATE_HH

#include <BCore/event/Event.hh>

namespace bemo {

class AbstractEventDelegate {
public:
    virtual void invoke( AbstractEvent* event ) = 0;
    virtual ~AbstractEventDelegate() {}
};

template< typename T, typename E >
class EventDelegate : public AbstractEventDelegate {

    typedef void(T::*Callback)( E* );
    T* m_receiver;
    Callback m_callback;

public:
    EventDelegate( T* receiver, Callback& func) :
            m_receiver( receiver ),
            m_callback( func )
    {}

    void invoke( AbstractEvent* event ) {
        (m_receiver->*m_callback)( reinterpret_cast< E* >( event ) );
    }
};

}
#endif // BEMO_DELEGATE_HH
