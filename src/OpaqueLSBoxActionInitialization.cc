#include "OpaqueLSBoxActionInitialization.hh"
#include "OpaqueLSBoxPrimaryGeneratorAction.hh"
#include "OpaqueLSBoxRunAction.hh"
#include "OpaqueLSBoxEventAction.hh"
#include "OpaqueLSBoxSteppingAction.hh"


OpaqueLSBoxActionInitialization::OpaqueLSBoxActionInitialization(){}
OpaqueLSBoxActionInitialization::~OpaqueLSBoxActionInitialization(){}

void OpaqueLSBoxActionInitialization::Build() const
{
  
  
  SetUserAction(new OpaqueLSBoxPrimaryGeneratorAction);
  
  OpaqueLSBoxRunAction *runAction = new OpaqueLSBoxRunAction();
  SetUserAction(runAction);
  
  OpaqueLSBoxEventAction *eventAction = new OpaqueLSBoxEventAction(runAction);
  SetUserAction(eventAction);
  
  OpaqueLSBoxSteppingAction *steppingAction = new OpaqueLSBoxSteppingAction(eventAction);
  SetUserAction(steppingAction);
 
}  

 
