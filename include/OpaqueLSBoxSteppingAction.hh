#ifndef OpaqueLSBoxSTEPPING_HH
#define OpaqueLSBoxSTEPPING_HH


#include "G4UserSteppingAction.hh"
#include "G4Step.hh"

#include "OpaqueLSBoxDetectorConstruction.hh"
#include "OpaqueLSBoxEventAction.hh"

class OpaqueLSBoxSteppingAction: public G4UserSteppingAction
{
public:
	OpaqueLSBoxSteppingAction(OpaqueLSBoxEventAction* eventAction);
	~OpaqueLSBoxSteppingAction();
	
	virtual void UserSteppingAction(const G4Step*);
	
private:
	OpaqueLSBoxEventAction * fEventAction;	

};

#endif                                               
