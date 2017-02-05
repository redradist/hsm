#ifndef _WHEEL_HPP_
#define _WHEEL_HPP_

#include "IState.hpp"
#include <memory>

class IWheelMaker;
class WheelDataProvider;

class Wheel : public IState
{
public:

   Wheel() = default;

   virtual void enter() override;

   virtual void exit() override;

   virtual IEvent * messageHandler(IEvent *) override;

private:

   friend class IWheelMaker;

   using ActionRun = void (*)(int, int, double);
   ActionRun run;

   IState * state;
   IState * jumping;

   std::shared_ptr<WheelDataProvider *> dataProvider;

};

#endif // _WHEEL_HPP_