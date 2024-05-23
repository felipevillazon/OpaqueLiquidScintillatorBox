#include "OpaqueLSBoxRunAction.hh"

OpaqueLSBoxRunAction::OpaqueLSBoxRunAction(){}

OpaqueLSBoxRunAction::~OpaqueLSBoxRunAction(){}

void OpaqueLSBoxRunAction::BeginOfRunAction(const G4Run* run)
{
	 G4AnalysisManager *man = G4AnalysisManager::Instance();
	 
	 G4int runID = run->GetRunID();
	 
	 std::stringstream strRunID;
	 strRunID << runID;
	 
	 man->OpenFile("output" +strRunID.str()+ ".root");
	 
	 man->CreateNtuple("Hits", "Hits");
	 man->CreateNtupleIColumn("Event_Number");
	 man->CreateNtupleDColumn("Kinetic_Energy");
	 man->CreateNtupleDColumn("Time");
	 man->FinishNtuple(0);
	 
	 
	 man->CreateNtuple("Scoring", "Scoring");
	 man->CreateNtupleIColumn("Event_Number");
	 man->CreateNtupleDColumn("Kinetic_Energy");
	 man->CreateNtupleDColumn("Time");
	 man->FinishNtuple(1);
	 
	 
	 man->CreateNtuple("Hits", "Secondaries");
	 man->CreateNtupleIColumn("Event_Number");
	 man->CreateNtupleDColumn("Kinetic_Energy");
	 man->CreateNtupleDColumn("Time");
	 man->CreateNtupleSColumn("Particle_Name");
	 man->FinishNtuple(2);
	 
	 man->CreateNtuple("process", "ID");
	 man->CreateNtupleSColumn("processID");
	 man->FinishNtuple(3);
	 
	 man->CreateNtuple("process", "neutronsource");
	 man->CreateNtupleSColumn("processID");
	 man->FinishNtuple(4);
	 
	 man->CreateNtuple("neutron_FS", "neutron in final state");
	 man->CreateNtupleSColumn("processID");
	 man->CreateNtupleSColumn("InitialStateID");
	 man->CreateNtupleSColumn("FinalStateID");
	 man->FinishNtuple(5);
	 
	 man->CreateNtuple("no_neutron_FS", "no neutron in final state");
	 man->CreateNtupleSColumn("processID");
	 man->CreateNtupleSColumn("InitialStateID");
	 man->CreateNtupleSColumn("FinalStateID");
	 man->FinishNtuple(6);
	 
	 man->CreateNtuple("no_neutron_IS", "no neutron in initial state");
	 man->CreateNtupleSColumn("processID");
	 man->CreateNtupleSColumn("InitialStateID");
	 man->CreateNtupleSColumn("FinalStateID");
	 man->FinishNtuple(7);
	 
	 
}

void OpaqueLSBoxRunAction::EndOfRunAction(const G4Run*)
{
	G4AnalysisManager *man = G4AnalysisManager::Instance();
	
	man->Write();
	man->CloseFile();
}
