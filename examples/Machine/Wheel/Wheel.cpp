#include "Wheel.hpp"
#include "WheelDataProvider.hpp"

void Wheel::enter()
{

}

void Wheel::exit()
{

}

IEvent * Wheel::messageHandler(IEvent * msg_ptr)
{
   switch (*msg_ptr)
   {
   case INIT:
   {
      trigger(state);
      dataProvider->asd;
   }
      return nullptr;
   case MIDDLE:
   {
      run(1, dataProvider->bytes[0], 2.0f);
      trigger(jumping);
   }
      return nullptr;
   default:
      return msg_ptr;
   }
}