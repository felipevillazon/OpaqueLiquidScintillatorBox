using namespace std;


#include "OpaqueLSBoxPrimaryGeneratorAction.hh"

#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4RunManager.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include "G4Geantino.hh"
#include "G4IonTable.hh"



OpaqueLSBoxPrimaryGeneratorAction::OpaqueLSBoxPrimaryGeneratorAction()
{
  G4int n_particle = 1;
  fParticleGun  = new G4ParticleGun(n_particle);
  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4String particleName;
  G4ParticleDefinition* particle = particleTable->FindParticle(particleName="opticalphoton");
  fParticleGun->SetParticleDefinition(particle);
  fParticleGun->SetParticleEnergy(7*eV);
}

OpaqueLSBoxPrimaryGeneratorAction::~OpaqueLSBoxPrimaryGeneratorAction()
{
  delete fParticleGun;
}

void OpaqueLSBoxPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  
   
  CLHEP::HepRandom::setTheEngine(new CLHEP::MTwistEngine);
  CLHEP::HepRandom::setTheSeed((unsigned)clock());  

  
  G4int numPhotons = 100;
  
  for (G4int i = 0; i < numPhotons; ++i) {
  // Generate random azimuthal and polar angles
  //G4double theta = acos(2.0 * G4UniformRand() - 1.0);
  G4double phi = 2.0 * CLHEP::pi * G4UniformRand();
  G4double theta2 = 1.0*CLHEP::pi * G4UniformRand();

  // Calculate Cartesian coordinates from spherical coordinates
  G4double px = sin(theta2) * cos(phi);
  G4double py = sin(theta2) * sin(phi);
  G4double pz = cos(theta2);

  fParticleGun->SetParticleMomentumDirection(G4ThreeVector(px,py,pz));
  fParticleGun->SetParticlePosition(G4ThreeVector(0,0,0));
  fParticleGun->GeneratePrimaryVertex(anEvent);
  
  }
//  }
}
