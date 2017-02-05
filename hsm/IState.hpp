#ifndef _ISTATE_HPP_
#define _ISTATE_HPP_

class IEvent;
class IMaker;

class IState
{
public:

   void start()
   {
      if (current)
      {
         enter();
         current->start();
      }
   }

   void message(IEvent * msg_ptr)
   {
      currentMsg = msg_ptr;
      if (messageHandler(msg_ptr) && parent)
      {
         parent->message(msg_ptr);
      }
      else
      {
         // Ignore message
         delete currentMsg, currentMsg = nullptr;
      }

      if (next)
      {
         current->exit();
         current = next;
         next = nullptr;
         current->enter();
      }
   }

   virtual ~IState() = 0;

protected:

   virtual void enter() = 0;

   void trigger(IState * newState)
   {
      next = newState;
   }

   virtual void exit() = 0;

   virtual IEvent * messageHandler(IEvent * msg_ptr) = 0;

private:
   
   friend class IMaker;

   IEvent * currentMsg = nullptr;

   IState * parent = nullptr;
   IState * current = nullptr;
   IState * next = nullptr;

};

IState::~IState()
{
   
}

#endif // _ISTATE_HPP_