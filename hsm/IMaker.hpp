#ifndef _IMAKER_HPP_
#define _IMAKER_HPP_

#include "IState.hpp"

class IMaker
{
public:

   IState * getProduct()
   {
      makeProduct();
      return product;
   }

   virtual ~IMaker() = 0;

protected:

   void setParent(IState * child)
   {
      child->parent = product;
   }

   virtual void makeProduct() = 0;

   IState * product;

};

IMaker::~IMaker()
{

}

#endif // _IMAKER_HPP_