#ifndef _IENGINE_MAKER_HPP_
#define _IENGINE_MAKER_HPP_

#include "IMaker.hpp"
#include "Engine.hpp"

class IEngineMaker : public IMaker
{
public:

   IEngineMaker()
   {
      product = new Engine;
   }

protected:

   virtual void makeProduct() override
   {
      ((Engine *) product)->state = getState();
      ((Engine *) product)->jumping = getJumping();
      ((Engine *) product)->machineData.reset(getMachineData());
      ((Engine *) product)->dataProvider.reset(getWheelData());
   }

   virtual IState * getState() = 0;

   virtual IState * getJumping() = 0;

   virtual std::shared_ptr<MachineDataProvider *> getMachineData() = 0;

   virtual std::shared_ptr<EngineDataProvider *> getWheelData() = 0;

};

#endif // _IENGINE_MAKER_HPP_