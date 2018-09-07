#ifndef BEMO_EVENTMANAGER_HH
#define BEMO_EVENTMANAGER_HH

#include <map>
#include <vector>
#include <functional>

#include "Event.hh"
#include "EventDelegate.hh"
#include "EventDispatcher.hh"
#include <BCore/util/Log.hh>
#include <BCore/util/Assert.hh>


namespace bemo {

class EventHandler {
public:
    template< typename T, typename E >
    void subscribeEvent( T* instance, void(T::*callback)( E* ) ) {
        auto iter = m_dispatchers.find( E::EVENT_TYPE_ID );
        if ( iter == m_dispatchers.end() ) {
            m_dispatchers.insert( std::make_pair( E::EVENT_TYPE_ID, new EventDispatcher< E >() ) );
        }
        AbstractEventDispatcher* dispatcher = m_dispatchers.at( E::EVENT_TYPE_ID );
        dispatcher->addEventDelegate( new EventDelegate< T, E >( instance, callback ) );
    }

    template< typename T, typename E >
    void unsubscribeEvent( T* instance ) {}

    template< typename E, typename... Args >
    void sendEvent( Args... args ) {
        auto iter = m_dispatchers.find( E::EVENT_TYPE_ID );
        if ( iter != m_dispatchers.end() ) {
            AbstractEvent* event = new E( std::forward< Args >( args )... );
            iter->second->dispatch( event );
            delete event;
        }
    }

private:
    std::map< int, AbstractEventDispatcher* > m_dispatchers;
};

}

#endif // BEMO_EVENTMANAGER_HH
