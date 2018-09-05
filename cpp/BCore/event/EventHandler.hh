#ifndef BEMO_EVENTMANAGER_HH
#define BEMO_EVENTMANAGER_HH

#include <vector>
#include <functional>

#include "Event.hh"
#include "EventDelegate.hh"
#include <BCore/util/Log.hh>
#include <BCore/util/Assert.hh>


namespace bemo {

class EventHandler {
public:
    template< typename T, typename E >
    void subscribeEvent( T* instance, void(T::*callback)( E* ) ) {
        AbstractEventDelegate* delegate = new EventDelegate< T, E >( instance, callback );
        m_delegates.push_back( delegate );
    }

    template< typename T, typename E >
    void unsubscribeEvent( T* instance ) {}

    template< typename E, typename... Args >
    void sendEvent( Args... args ) {
        for ( AbstractEventDelegate* delegate : m_delegates ) {
            if ( E::EVENT_TYPE_ID == delegate->getEventTypeID() ) {
                delegate->invoke( new E( std::forward< Args >( args )... ) );
            }
        }
    }

private:
    std::vector< AbstractEventDelegate* > m_delegates;

};

}

#endif // BEMO_EVENTMANAGER_HH
