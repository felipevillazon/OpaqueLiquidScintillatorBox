#ifndef OpaqueLSBoxRUNACTION_HH
#define OpaqueLSBoxRUNACTION_HH

#include "G4UserRunAction.hh"
#include "G4RootAnalysisManager.hh"
#include "G4AnalysisManager.hh"
#include "G4Run.hh"

class OpaqueLSBoxRunAction : public G4UserRunAction
{
public:
	OpaqueLSBoxRunAction();
	~OpaqueLSBoxRunAction();
	
	virtual void BeginOfRunAction(const G4Run*);
	virtual void EndOfRunAction(const G4Run*);
};


#endif
