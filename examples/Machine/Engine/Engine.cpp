#include "Engine.hpp"
#include "EngineDataProvider.hpp"

void Engine::enter()
{

}

void Engine::exit()
{

}

IEvent * Engine::messageHandler(IEvent * msg_ptr)
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
      run(1, dataProvider->parameterValue[0], 2.0f);
      trigger(jumping);
   }
      return nullptr;
   default:
      return msg_ptr;
   }
}