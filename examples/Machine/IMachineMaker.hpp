#ifndef _IMACHINE_MAKER_HPP_
#define _IMACHINE_MAKER_HPP_

#include "IMaker.hpp"
#include "Machine.hpp"

class IMachineMaker : public IMaker
{
public:

   IMachineMaker()
   {
      product = new Machine;
   }

protected:

   virtual void makeProduct() override
   {
      (static_cast<Machine *>(product))->state = getState();
      setParent((static_cast<Machine *>(product))->state);
      (static_cast<Machine *>(product))->jumping = getJumping();
      setParent((static_cast<Machine *>(product))->jumping);
      (static_cast<Machine *>(product))->dataProvider.reset(getWheelData());
   }

   virtual IState * getState() = 0;

   virtual IState * getJumping() = 0;

   virtual std::shared_ptr<WheelDataProvider *> getWheelData() = 0;

};

#endif // _IMACHINE_MAKER_HPP_