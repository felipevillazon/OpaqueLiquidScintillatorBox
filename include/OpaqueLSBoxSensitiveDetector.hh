#ifndef OpaqueLSBoxSENSTIVEDETECTOR_HH
#define OpaqueLSBoxSENSITIVEDETECTOR_HH

#include "G4VSensitiveDetector.hh"
#include "G4String.hh"
#include "G4TouchableHistory.hh"
#include "G4AnalysisManager.hh"
#include "G4RunManager.hh"
#include "G4Step.hh"

class OpaqueLSBoxSensitiveDetector : public G4VSensitiveDetector
{
public:
	OpaqueLSBoxSensitiveDetector(G4String);
	~OpaqueLSBoxSensitiveDetector();
private:
	virtual G4bool ProcessHits(G4Step *, G4TouchableHistory *);
};

#endif
