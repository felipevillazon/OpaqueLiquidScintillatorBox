#include "OpaqueLSBoxDetectorMessenger.hh"

#include "OpaqueLSBoxDetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4Scintillation.hh"
#include "G4UIcmdWithABool.hh"
#include "G4UIcmdWithADouble.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWithAnInteger.hh"
#include "G4UIcmdWith3VectorAndUnit.hh"
#include "G4UIcommand.hh"
#include "G4UIdirectory.hh"

#include "G4Material.hh"
#include "G4MaterialPropertiesTable.hh"

//------//------//------//-----//-----//-----//-----//-----//-----//-----//-----//-----//-----//-----//-----//-----//-----//-----//

OpaqueLSBoxDetectorMessenger::OpaqueLSBoxDetectorMessenger(OpaqueLSBoxDetectorConstruction* detector)
  : fOpaqueLSBoxDetector(detector)
{
  
  // Setup a command directory for detector controls with guidance
  fDetectorDir = new G4UIdirectory("/OpaqueLSBox/Volume/");
  fDetectorDir->SetGuidance("Detector geometry control");

  // Various commands for modifying detector geometry


  fThicknessCmd = new G4UIcmdWithADoubleAndUnit("/OpaqueLSBox/Volume/Thickness", this);
  fThicknessCmd->SetGuidance("Set the tested material thickness");
  fThicknessCmd->SetDefaultUnit("cm");
  fThicknessCmd->AvailableForStates(G4State_PreInit, G4State_Idle);
  fThicknessCmd->SetToBeBroadcasted(false);
 

  fDefaultsCmd = new G4UIcommand("/OpaqueLSBox/Volume/defaults", this);
  fDefaultsCmd->SetGuidance("Set all detector geometry values to defaults.");
  fDefaultsCmd->AvailableForStates(G4State_PreInit, G4State_Idle);
  fDefaultsCmd->SetToBeBroadcasted(false);


}

//------//------//------//-----//-----//-----//-----//-----//-----//-----//-----//-----//-----//-----//-----//-----//-----//-----//

OpaqueLSBoxDetectorMessenger::~OpaqueLSBoxDetectorMessenger()
{
  delete fThicknessCmd;
  delete fDefaultsCmd;
  delete fDetectorDir;

}

//------//------//------//-----//-----//-----//-----//-----//-----//-----//-----//-----//-----//-----//-----//-----//-----//-----//

void OpaqueLSBoxDetectorMessenger::SetNewValue(G4UIcommand* command, G4String newValue)
{
 

  if(command == fThicknessCmd)
  {
    fOpaqueLSBoxDetector->SetThickness(fThicknessCmd->GetNewDoubleValue(newValue));
    //G4cout << "The thickness of the material has been changed" << G4endl;
  }
  else if(command == fDefaultsCmd)
  {
    fOpaqueLSBoxDetector->SetDefaults();
    G4RunManager::GetRunManager()->ReinitializeGeometry();
  }
}
