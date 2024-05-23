#ifndef OpaqueLSBoxDetectorConstruction_h
#define OpaqueLSBoxDetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"
#include "OpaqueLSBoxSensitiveDetector.hh"
#include "OpaqueLSBoxSensitiveVolume.hh"
#include "OpaqueLSBoxDetectorMessenger.hh"
#include "G4NistManager.hh"

#include <map>
#include <vector>	

using std::vector;
using std::map;

/// Detector construction class to define materials and geometry.


class OpaqueLSBoxDetectorConstruction : public G4VUserDetectorConstruction
{
  public:
	
	OpaqueLSBoxDetectorConstruction();
	~OpaqueLSBoxDetectorConstruction();
	
        G4LogicalVolume * GetScoringVolume() const { return fScoringVolume; }
        G4LogicalVolume * GetWorldVolume() const { return fWorldVolume; }
        
        void SetDefaults();



  void SetThickness(G4double k);
  G4double GetThickness() const { return fThickness; }


  
  virtual G4VPhysicalVolume *Construct();

 
  private:
       
        OpaqueLSBoxDetectorMessenger* fDetectorMessenger;
        
	virtual void ConstructSDandField();
	
	void DefinedMaterials();
	void DefineMaterialsProperties();
	
	G4LogicalVolume* fScoringVolume;
	G4LogicalVolume* fWorldVolume;
	
	
	//~~~~~~~MATERIALS~~~~~~~//
	
	G4Element* H;
	G4Element* C;
	G4Element* N;
	G4Element* O;
	G4Element* F;
	G4Element* Cr;
	G4Element* Mn;
	G4Element* Fe;
	G4Element* Ni;
	G4Element* Cu;
	G4Element* Si;
	G4Element* Xe;
	G4Element* Al;
	G4Element* Ti;
	G4Element* Mo;
	G4Element* Co;
	G4Element *Na;
	G4Element *P;
	G4Element *S;
	G4Element *K;
	G4Element *Ca;
	G4Element *Mg;
	G4Element *Ga;
	G4Element *B;
	
	G4Material* Vacuum;
	G4Material* Air;
	G4Material* SS304LSteel;
	G4Material* PMMA;
	G4Material* SiOil;
	G4Material* Iron;
	G4Material* StandardConcrete;
	G4Material* Graphite;
	G4Material* LAB;
	G4Material* PXE;
	G4Material* DIN;
	G4Material* Gd3;
	G4Material* THF;
	G4Material* PPO;
	G4Material* bisMSB;
	G4Material* STEREOLS;
	G4Material* Boron;
	
	//------VARIABLES-----//
	
	G4double fThickness;
	G4Material* tmaterial;

        //-----TESTED MATERIAL GEOMETRY----//
        
	G4Box* TMaterialBox;
	G4LogicalVolume* TMaterialLogical;
	G4VPhysicalVolume* TMaterialPhysical;
	
	//-----SENSITIVE DETECTOR------//
	
	G4Box* SDBox;
	G4LogicalVolume* SDLogical;
	G4VPhysicalVolume* SDPhysical;
	
	
	
	


};

#endif

