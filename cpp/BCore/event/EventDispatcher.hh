#ifndef BEMO_EVENTDISPATCHER_HH
#define BEMO_EVENTDISPATCHER_HH

#include <list>
#include <BCore/event/EventDelegate.hh>

namespace bemo {

class AbstractEvent;
class AbstractEventDelegate;

class AbstractEventDispatcher {
public:
    virtual ~AbstractEventDispatcher() = default;
    virtual void dispatch( AbstractEvent* event ) = 0;
    virtual void addEventDelegate( AbstractEventDelegate* delegate ) = 0;
    virtual void removeEventDelegate( AbstractEventDelegate* delegate ) = 0;
};

template< typename E >
class EventDispatcher : public AbstractEventDispatcher {
public:
    void dispatch( AbstractEvent* event ) override {
        for ( AbstractEventDelegate* delegate : m_delegates ) {
            delegate->invoke( event );
        }
    }
    void addEventDelegate( AbstractEventDelegate* delegate ) override {
        m_delegates.push_back( delegate );
    }
    void removeEventDelegate( AbstractEventDelegate* delegate ) override {
        auto iter = std::find( m_delegates.begin(), m_delegates.end(), delegate );
        if ( iter != m_delegates.end() ) {
            m_delegates.erase( iter );
        }
    }
private:
    std::list< AbstractEventDelegate* > m_delegates;
};

}

#endif // BEMO_EVENTDISPATCHER_HH
