#ifndef _MACHINE_HPP_
#define _MACHINE_HPP_

#include "IState.hpp"
#include <memory>

class IMachineMaker;
class MachineDataProvider;

class Machine : public IState
{
public:

   Machine() = default;

   virtual void enter() override;

   virtual void exit() override;

   virtual IEvent * messageHandler(IEvent *) override;

private:

   friend class IMachineMaker;

   using ActionRun = void (*)(int, int, double);
   ActionRun run;

   IState * engine;
   IState * wheel;

   std::shared_ptr<MachineDataProvider *> dataProvider;

};

#endif // _MACHINE_HPP_