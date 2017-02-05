#ifndef _IEVENT_HPP_
#define _IEVENT_HPP_

struct IEvent
{
   virtual operator int() = 0;

   virtual ~IEvent() = 0;
};

IEvent::~IEvent()
{

}

#endif // _IEVENT_HPP_