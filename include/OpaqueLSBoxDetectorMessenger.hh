#ifndef OpaqueLSBoxDetectorMessenger_h
#define OpaqueLSBoxDetectorMessenger_h 1

#include "globals.hh"
#include "G4UImessenger.hh"

class OpaqueLSBoxDetectorConstruction;

class G4UIcmdWithABool;
class G4UIcmdWithADouble;
class G4UIcmdWithADoubleAndUnit;
class G4UIcmdWithAnInteger;
class G4UIcmdWith3VectorAndUnit;
class G4UIcommand;
class G4UIdirectory;

class OpaqueLSBoxDetectorMessenger : public G4UImessenger
{
 public:
  OpaqueLSBoxDetectorMessenger(OpaqueLSBoxDetectorConstruction*);
  ~OpaqueLSBoxDetectorMessenger();

  void SetNewValue(G4UIcommand*, G4String) override;

 private:
  OpaqueLSBoxDetectorConstruction* fOpaqueLSBoxDetector;
  G4UIdirectory* fDetectorDir;

  G4UIcmdWithADoubleAndUnit* fThicknessCmd;
  
  G4UIcommand* fDefaultsCmd;

};

#endif	
