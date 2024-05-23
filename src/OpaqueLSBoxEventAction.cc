#include "OpaqueLSBoxEventAction.hh"
#include "G4AnalysisManager.hh"

OpaqueLSBoxEventAction::OpaqueLSBoxEventAction(OpaqueLSBoxRunAction*)
{
	fEdep = 0. ;   
}

OpaqueLSBoxEventAction::~OpaqueLSBoxEventAction()
{}

void OpaqueLSBoxEventAction::BeginOfEventAction(const G4Event*)
{
	fEdep = 0. ; 
}

void OpaqueLSBoxEventAction::EndOfEventAction(const G4Event*)
{	
	//G4cout << "Energy deposition: " << fEdep << G4endl;  
	
	//G4AnalysisManager *man = G4AnalysisManager::Instance();
	
	//man->FillNtupleDColumn(0, fEdep);  // filling the tuple with the energy creating a second row of data
	
	//man->AddNtupleRow(1); // adding it to row 1
}
