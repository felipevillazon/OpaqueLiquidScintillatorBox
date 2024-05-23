#ifndef OpaqueLSBoxEVENTACTION_HH
#define OpaqueLSBoxEVENTACTION_HH 1

#include "G4UserEventAction.hh"
#include "G4Event.hh"
#include "OpaqueLSBoxRunAction.hh"


class OpaqueLSBoxEventAction : public G4UserEventAction
{
public:
	OpaqueLSBoxEventAction(OpaqueLSBoxRunAction*);
	~OpaqueLSBoxEventAction();
	
	virtual void BeginOfEventAction(const G4Event*);
	virtual void EndOfEventAction(const G4Event*);
	
	void AddEdep(G4double edep) {fEdep += edep;}  // function that will add the energy 
    

private:
  
    G4double fEdep;	// double definition of variable fEdep
   
	
};


#endif



