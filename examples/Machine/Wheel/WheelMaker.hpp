#ifndef _WHEEL_MAKER_HPP_
#define _WHEEL_MAKER_HPP_

#include "IWheelMaker.hpp"

class WheelMaker : public IWheelMaker
{
public:

   WheelMaker(std::shared_ptr<WheelDataProvider *> dataProvider_, 
              IMaker * state_, 
              IMaker * jumping_)
   {
      dataProvider = dataProvider_;
      state = state_;
      jumping = jumping_;
   }

protected:

   virtual IState * getState() override 
   {
      return state->getProduct();
   }

   virtual IState * getJumping() override 
   {
      return jumping->getProduct();
   }

   virtual std::shared_ptr<WheelDataProvider *> getWheelData() override 
   {
      return dataProvider;
   }

private:

   IMaker * state;
   IMaker * jumping;

   std::shared_ptr<WheelDataProvider *> dataProvider;

};

#endif // _WHEEL_MAKER_HPP_