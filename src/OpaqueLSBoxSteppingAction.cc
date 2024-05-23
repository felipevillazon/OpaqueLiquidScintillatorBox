#include "OpaqueLSBoxSteppingAction.hh"
#include "G4Track.hh"
#include "G4VProcess.hh"
#include "G4Neutron.hh"
#include "G4AnalysisManager.hh"

OpaqueLSBoxSteppingAction::OpaqueLSBoxSteppingAction(OpaqueLSBoxEventAction *eventAction)
{
	fEventAction = eventAction;

}

OpaqueLSBoxSteppingAction::~OpaqueLSBoxSteppingAction()
{}

void OpaqueLSBoxSteppingAction::UserSteppingAction(const G4Step *step)
{
	
	
	G4Track* primaryTrack = step->GetTrack();
	G4String initialParticle = primaryTrack->GetParticleDefinition()->GetParticleName();
	
	if (initialParticle == "neutron"){

        // Check if the process is not "Transportation"
        const G4VProcess* process = step->GetPostStepPoint()->GetProcessDefinedStep();
        G4String processName = process ? process->GetProcessName() : "Unknown";
        if (processName != "Transportation" && processName != "hadElastic") {
            // Check if any of the secondary particles is a neutron
            bool hasNeutron = false;
            const std::vector<const G4Track*>* secondaryTracks = step->GetSecondaryInCurrentStep();
            for (auto secondaryTrack : *secondaryTracks) {
                if (secondaryTrack->GetParticleDefinition() == G4Neutron::NeutronDefinition()) {
                    hasNeutron = true;
                    break;
                }
            }

            // Print the details only if a neutron is present
            if (hasNeutron == true) {
                // Print the process name
                //G4cout << "Process: " << processName << G4endl;

                // Print the initial state particle
                G4String initialParticle = primaryTrack->GetParticleDefinition()->GetParticleName();
                //G4cout << "Initial State Particle: " << initialParticle << " (Track ID: " << primaryTrack->GetTrackID() << ")" << G4endl;

                // Print details of secondary particles
                for (auto secondaryTrack : *secondaryTracks) {
                    G4String finalParticle = secondaryTrack->GetParticleDefinition()->GetParticleName();
                    //G4cout << "Final State Particle: " << finalParticle << " (Track ID: " << secondaryTrack->GetTrackID() << ")" << G4endl;
                    
                }
                
                G4String secondaryString;
                for (size_t i = 0; i < secondaryTracks->size(); ++i) {
                    secondaryString += (*secondaryTracks)[i]->GetParticleDefinition()->GetParticleName();
                    if (i < secondaryTracks->size() - 1) {
                        secondaryString += "+";
                    }
                } 
                // Separator between steps
                //G4cout << secondaryString << G4endl;
                //G4cout << "------------------------" << G4endl;
                
                
               G4AnalysisManager *man = G4AnalysisManager::Instance();
	
	       man->FillNtupleSColumn(5, 0, processName);  // filling the tuple with the energy creating a second row of data
	       
	       man->FillNtupleSColumn(5, 1, initialParticle); 
	       
	       man->FillNtupleSColumn(5, 2, secondaryString); 
	
	       man->AddNtupleRow(5);
            
                
                
            }
            
            if (hasNeutron == false) {
                // Print the process name
                //G4cout << "Process: " << processName << G4endl;

                // Print the initial state particle
                G4String initialParticle = primaryTrack->GetParticleDefinition()->GetParticleName();
                //G4cout << "Initial State Particle: " << initialParticle << " (Track ID: " << primaryTrack->GetTrackID() << ")" << G4endl;

                // Print details of secondary particles
                for (auto secondaryTrack : *secondaryTracks) {
                    G4String finalParticle = secondaryTrack->GetParticleDefinition()->GetParticleName();
                    //G4cout << "Final State Particle: " << finalParticle << " (Track ID: " << secondaryTrack->GetTrackID() << ")" << G4endl;
                }
                
                G4String secondaryString;
                for (size_t i = 0; i < secondaryTracks->size(); ++i) {
                    secondaryString += (*secondaryTracks)[i]->GetParticleDefinition()->GetParticleName();
                    if (i < secondaryTracks->size() - 1) {
                        secondaryString += "+";
                    }
                } 
                // Separator between steps
                //G4cout << secondaryString << G4endl;

                // Separator between steps
                //G4cout << "------------------------" << G4endl;
                
               G4AnalysisManager *man = G4AnalysisManager::Instance();
	
	       man->FillNtupleSColumn(6, 0, processName);  // filling the tuple with the energy creating a second row of data
	       
	       man->FillNtupleSColumn(6, 1, initialParticle); 
	       
	       man->FillNtupleSColumn(6, 2, secondaryString); 
	
	       man->AddNtupleRow(6);
                
             }
          }
        
        }
	
	if (initialParticle != "neutron"){

        // Check if the process is not "Transportation"
        const G4VProcess* process = step->GetPostStepPoint()->GetProcessDefinedStep();
        G4String processName = process ? process->GetProcessName() : "Unknown";
        if (processName != "Transportation" && processName != "hadElastic") {
            // Check if any of the secondary particles is a neutron
            bool hasNeutron = false;
            const std::vector<const G4Track*>* secondaryTracks = step->GetSecondaryInCurrentStep();
            for (auto secondaryTrack : *secondaryTracks) {
                if (secondaryTrack->GetParticleDefinition() == G4Neutron::NeutronDefinition()) {
                    hasNeutron = true;
                    break;
                }
            }

            // Print the details only if a neutron is present
            if (hasNeutron == true) {
                // Print the process name
                //G4cout << "Process: " << processName << G4endl;

                // Print the initial state particle
                G4String initialParticle = primaryTrack->GetParticleDefinition()->GetParticleName();
                //G4cout << "Initial State Particle: " << initialParticle << " (Track ID: " << primaryTrack->GetTrackID() << ")" << G4endl;

                // Print details of secondary particles
                for (auto secondaryTrack : *secondaryTracks) {
                    G4String finalParticle = secondaryTrack->GetParticleDefinition()->GetParticleName();
                    //G4cout << "Final State Particle: " << finalParticle << " (Track ID: " << secondaryTrack->GetTrackID() << ")" << G4endl;
                    
                }
                
                G4String secondaryString;
                for (size_t i = 0; i < secondaryTracks->size(); ++i) {
                    secondaryString += (*secondaryTracks)[i]->GetParticleDefinition()->GetParticleName();
                    if (i < secondaryTracks->size() - 1) {
                        secondaryString += "+";
                    }
                } 
                // Separator between steps
                //G4cout << secondaryString << G4endl;
                //G4cout << "------------------------" << G4endl;
                
                
               G4AnalysisManager *man = G4AnalysisManager::Instance();
	
	       man->FillNtupleSColumn(7, 0, processName);  // filling the tuple with the energy creating a second row of data
	       
	       man->FillNtupleSColumn(7, 1, initialParticle); 
	       
	       man->FillNtupleSColumn(7, 2, secondaryString); 
	
	       man->AddNtupleRow(7);
            
                
                
            }
          
          }
        
        }
	
	
	
	
	
	
	
	
	
	
	
	
	/*G4Track *track = step->GetTrack(); 
		
	G4ParticleDefinition* particle = track->GetDefinition();
	
	const G4StepPoint* endPoint = step->GetPostStepPoint();
        const G4VProcess* process = endPoint->GetProcessDefinedStep();
        G4String processName = process->GetProcessName();
        //G4cout << "Interaction process: " << processName << G4endl;
        
        
        
         const std::vector<const G4Track*>& secondaryTracks = *(step->GetSecondaryInCurrentStep());

        // Iterate over the secondary particles
         for (const auto& secondaryTrack : secondaryTracks) {
        // Check if the secondary particle is a neutron
        if (secondaryTrack->GetDefinition() == G4Neutron::Neutron()) {
            // Get the process responsible for the secondary particle production
            const G4String& processName = secondaryTrack->GetCreatorProcess()->GetProcessName();
            
            // Print the process name
            //G4cout << "Neutron produced by process: " << processName << G4endl;
            
         
        G4AnalysisManager *man = G4AnalysisManager::Instance();
	
	man->FillNtupleSColumn(4, 0, processName);  // filling the tuple with the energy creating a second row of data
	
	man->AddNtupleRow(4);
            
            
            
            }
        }
          
       
         G4String processname = process ? process->GetProcessName() : "Unknown";

        // Check if the process is not "Transportation"
        if (processname != "Transportation") {
            // Get initial and final particles
            G4String initialParticle = track->GetDynamicParticle()->GetDefinition()->GetParticleName();
            G4String finalParticle = step->GetPostStepPoint()->GetPhysicalVolume()->GetName();

            // Print the detailed information
            G4cout << initialParticle << " -> " << finalParticle << " via " << processname << G4endl;
        } 
        
        
        if (track->GetParentID() > 0) {
        G4String particleName = track->GetDefinition()->GetParticleName();
        G4double kineticEnergy = track->GetKineticEnergy() / CLHEP::MeV; // Convert to MeV for example
        
        // Print information about the secondary particle
        //G4cout << "Secondary Particle: " << particleName << ", Kinetic Energy: " << kineticEnergy << " MeV" << G4endl;
    }
    
       if (track->GetParentID() == 0 && track->GetStep()->IsFirstStepInVolume()) {
        G4String pparticleName = track->GetDefinition()->GetParticleName();
        G4double pkineticEnergy = track->GetKineticEnergy() / CLHEP::MeV; // Convert to MeV for example
        
        // Print information about the secondary particle
        //G4cout << "Pramary Particle: " << pparticleName << ", Kinetic Energy: " << pkineticEnergy << " MeV" << G4endl;
    }

        if (particle == G4Neutron::NeutronDefinition()){
	
	//const G4StepPoint* endPoint = step->GetPostStepPoint();
        //const G4VProcess* process = endPoint->GetProcessDefinedStep();
        //G4String processName = process->GetProcessName();
        //G4cout << "Interaction process: " << processName << G4endl;
        
        
        G4AnalysisManager *man = G4AnalysisManager::Instance();
	
	man->FillNtupleSColumn(3, 0, processName);  // filling the tuple with the energy creating a second row of data
	
	man->AddNtupleRow(3);
        
        
		
	G4LogicalVolume *volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();
	
	const NSTDetectorConstruction *detectorConstruction = static_cast<const NSTDetectorConstruction*> (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
	
	G4LogicalVolume *fScoringVolume = detectorConstruction->GetScoringVolume();
	
	if(volume != fScoringVolume)
		return;
	
	
	if (volume == fScoringVolume && track->GetStep()->IsLastStepInVolume()) { 
       G4double edep = step->GetPreStepPoint()->GetKineticEnergy();
       //fEventAction->AddEdep(edep);
       //G4cout << "Neutron Energy Last Step: " << edep << G4endl; 
       return;}
       
       
    
     
       }
       

    // Check for secondary gammas
    if (particle->GetParticleName() == "gamma" && track->GetParentID() > 0) {
        G4double energy = track->GetKineticEnergy(); // Get gamma energy in MeV

        // Identify secondary gamma energies over 8 MeV
        if (energy > 4.0*CLHEP::MeV && energy < 5.0*CLHEP::MeV) {
            G4String processName = track->GetCreatorProcess()->GetProcessName();
            //G4cout << "Secondary gamma produced by process: " << processName << " with energy: " << energy << " MeV" << G4endl;
        }
    }*/
       
       
       
      
      
};
	
