#ifndef OpaqueLSBoxPHYSICS_HH
#define OpaqueLSBoxPHYSICS_HH

#include "G4VModularPhysicsList.hh"
#include "G4EmStandardPhysics.hh"
#include "G4OpticalPhysics.hh"
#include "G4DecayPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"

class OpaqueLSBoxPhysicsList : public G4VModularPhysicsList
{
public:
     OpaqueLSBoxPhysicsList();
     ~OpaqueLSBoxPhysicsList();
};

#endif 
