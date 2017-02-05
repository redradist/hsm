#ifndef _MACHINE_MAKER_HPP_
#define _MACHINE_MAKER_HPP_

#include "IMachineMaker.hpp"

class MachineMaker : public IMachineMaker
{
public:

   MachineMaker(std::shared_ptr<WheelDataProvider *> dataProvider_, 
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

#endif // _MACHINE_MAKER_HPP_