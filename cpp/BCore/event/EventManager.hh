#ifndef BEMO_EVENTMANAGER_HH
#define BEMO_EVENTMANAGER_HH

#include <vector>
#include <functional>

#include "Event.hh"
#include "Delegate.hh"
#include <BCore/util/Log.hh>
#include <BCore/util/Assert.hh>


namespace bemo {

class EventManager {
public:
    EventManager() = default;

    template< typename T, typename E >
    void subscribe( T* instance, void(T::*callback)( E* ) ) {
        BMO_ERROR << "Subscribing!";
        AbstractEventDelegate* delegate = new EventDelegate< T, E >( instance,
                                                                     callback );
        m_delegates.push_back( delegate );
    }

    template< typename T, typename E >
    void unsubscribe( T* instance ) {}

    template< typename E, typename... Args >
    void send( Args... args ) {
        BMO_ERROR << "Sending event! Delegates=" << m_delegates.size();
        for ( AbstractEventDelegate* delegate : m_delegates ) {
            delegate->invoke( new E( args... ) );
        }
    }

private:
    std::vector< AbstractEventDelegate* > m_delegates;

};

}

#endif // BEMO_EVENTMANAGER_HH
