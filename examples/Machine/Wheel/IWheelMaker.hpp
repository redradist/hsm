#ifndef _IWHEEL_MAKER_HPP_
#define _IWHEEL_MAKER_HPP_

#include "IMaker.hpp"
#include "Wheel.hpp"

class IWheelMaker : public IMaker
{
public:

   IWheelMaker()
   {
      product = new Wheel;
   }

protected:

   virtual void makeProduct() override
   {
      ((Wheel *) product)->state = getState();
      ((Wheel *) product)->jumping = getJumping();
      ((Wheel *) product)->dataProvider.reset(getWheelData());
   }

   virtual IState * getState() = 0;

   virtual IState * getJumping() = 0;

   virtual std::shared_ptr<WheelDataProvider *> getWheelData() = 0;

};

#endif // _IWHEEL_MAKER_HPP_