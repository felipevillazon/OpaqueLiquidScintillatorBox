#ifndef OpaqueLSBoxActionInitialization_h
#define OpaqueLSBoxActionInitialization_h 1

#include "G4VUserActionInitialization.hh"
#include "OpaqueLSBoxRunAction.hh"



class OpaqueLSBoxActionInitialization : public G4VUserActionInitialization
{
  public:
  OpaqueLSBoxActionInitialization();
  ~OpaqueLSBoxActionInitialization();
  
  virtual void Build() const;
};



#endif

    
