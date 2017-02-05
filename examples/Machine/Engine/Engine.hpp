#ifndef _ENGINE_HPP_
#define _ENGINE_HPP_

#include "IState.hpp"
#include <memory>

class IEngineMaker;
class EngineDataProvider;

class Engine : public IState
{
public:

   Engine() = default;

   virtual void enter() override;

   virtual void exit() override;

   virtual IEvent * messageHandler(IEvent *) override;

private:

   friend class IEngineMaker;

   using ActionRun = void (*)(int, int, double);
   ActionRun run;

   IState * state;
   IState * jumping;

   std::shared_ptr<MachineDataProvider *> machineData;
   std::shared_ptr<EngineDataProvider *> dataProvider;

};

#endif // _ENGINE_HPP_