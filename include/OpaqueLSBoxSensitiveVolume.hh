#ifndef OpaqueLSBoxSENSITIVEVOLUME_HH
#define OpaqueLSBoxSENSITIVEVOLUME_HH

#include "G4VSensitiveDetector.hh"
#include "G4String.hh"
#include "G4TouchableHistory.hh"
#include "G4AnalysisManager.hh"
#include "G4RunManager.hh"
#include "G4Step.hh"

class OpaqueLSBoxSensitiveVolume : public G4VSensitiveDetector
{
public:
	OpaqueLSBoxSensitiveVolume(G4String);
	~OpaqueLSBoxSensitiveVolume();
private:
	virtual G4bool ProcessHits(G4Step *, G4TouchableHistory *);
};

#endif
