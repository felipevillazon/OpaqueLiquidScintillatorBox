#include "OpaqueLSBoxDetectorConstruction.hh"
#include "OpaqueLSBoxDetectorMessenger.hh"
#include "G4VSolid.hh"
#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4SubtractionSolid.hh"
#include "G4Tubs.hh"
#include "G4Cons.hh"
#include "G4Scintillation.hh"
#include "G4LossTableManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4Material.hh"

OpaqueLSBoxDetectorConstruction::OpaqueLSBoxDetectorConstruction()
{

  DefinedMaterials();
  SetDefaults();
  DefineMaterialsProperties();
  
  fDetectorMessenger = new OpaqueLSBoxDetectorMessenger(this);
  
 

}


OpaqueLSBoxDetectorConstruction::~OpaqueLSBoxDetectorConstruction()
{
 
 delete fDetectorMessenger;

}


G4VPhysicalVolume* OpaqueLSBoxDetectorConstruction::Construct()
{  
  
  G4bool checkOverlaps = true;
  
 
  
  //--------WORLD VOLUME------//

  G4double world_sizeXY = 0.5*m;
  G4double world_sizeZ = 0.5*m;
  
  G4Box* WorldBox = new G4Box("World", world_sizeXY, world_sizeXY, world_sizeZ);     
  G4LogicalVolume* WorldLogical = new G4LogicalVolume(WorldBox, LAB, "World");        
  G4VPhysicalVolume* WorldPhysical = new G4PVPlacement(0, G4ThreeVector(), WorldLogical, "World",0, false, 0, checkOverlaps);       
                
  
  
  //----TESTED MATERIAL-----//
  
  tmaterial = LAB;
  
  TMaterialBox = new G4Box("TMaterial", world_sizeXY, world_sizeXY, fThickness);  
  TMaterialLogical = new G4LogicalVolume(TMaterialBox, tmaterial, "TMaterial");  
  //TMaterialPhysical = new G4PVPlacement(0, G4ThreeVector(0,0,-fThickness+4*m), TMaterialLogical, "TMaterial" , WorldLogical , false, 0, checkOverlaps);  
  
  
  
  //----SENSITIVE DETECTOR---//
  
  G4double sd_thickness = 10*cm;
  
  SDBox = new G4Box("SD", world_sizeXY, world_sizeXY, sd_thickness);  
  SDLogical = new G4LogicalVolume(SDBox, Air, "SD");  
  //SDPhysical = new G4PVPlacement(0, G4ThreeVector(0,0, - 2*fThickness - 4*sd_thickness + 4*m ), SDLogical, "SD" , WorldLogical , false, 0, checkOverlaps);  

  
  
  
  fScoringVolume = TMaterialLogical; 
  fWorldVolume =  WorldLogical;
  
  return WorldPhysical;
  
}

void OpaqueLSBoxDetectorConstruction::ConstructSDandField()
{
  OpaqueLSBoxSensitiveDetector *sensDet = new OpaqueLSBoxSensitiveDetector("SensitiveDetector");
  SDLogical->SetSensitiveDetector(sensDet);
  
  OpaqueLSBoxSensitiveVolume *sensVol = new OpaqueLSBoxSensitiveVolume("SensitiveVolume");
  TMaterialLogical->SetSensitiveDetector(sensVol);
}

void OpaqueLSBoxDetectorConstruction::DefinedMaterials()
{
 
  H = new G4Element("Hydrogen", "H", 1.,  1.01 * g / mole);
  C = new G4Element("Carbon", "C", 6., 12.01 * g / mole);
  N = new G4Element("Nitrogen", "N", 7., 14.01 * g / mole);
  O = new G4Element("Oxygen", "O", 8., 16.00 * g / mole);
  F = new G4Element("Fluorine", "F", 9., 18.998 *g / mole);
  Cr = new G4Element("Chromium", "Cr", 24., 51.996 * g / mole);
  Mn = new G4Element("Manganese", "Mn", 25., 54.938 * g / mole);
  Fe = new G4Element("Iron", "Fe", 26., 55.85 * g / mole);
  Ni = new G4Element("Nickel", "Ni", 28., 58.693 * g / mole);
  Cu = new G4Element("Copper", "Cu", 29., 63.546 * g / mole);
  Si = new G4Element("Silicon", "Si", 14., 28.086 * g / mole);	
  Xe = new G4Element("Xenon", "Xe", 54., 131.293 * g / mole);
  Al = new G4Element("Aluminium", "Al", 13., 26.982 * g / mole);
  Na = new G4Element("Sodium", "Na", 11.,  22.99 * g / mole);
  P = new G4Element("Phosphorous", "P", 15.,  20.97 * g / mole);
  S = new G4Element("Sulfur", "S", 16.,  32.07 * g / mole);
  K = new G4Element("Potassium", "K", 19.,  39.10 * g / mole);
  Ca = new G4Element("Calcium", "Ca", 20.,  40.08 * g / mole);
  Mg = new G4Element("Magnesium", "Mg", 12.,  24.31 * g / mole);
  Ga = new G4Element("Gallium", "Ga", 31.,  69.72 * g / mole);
  B = new G4Element("Boron", "B", 5.,  10.811 * g / mole);
  
  
  Vacuum = new G4Material("Vacuum", 1.e-20 * g / cm3, 2, kStateGas);
  Vacuum->AddElement(N, 0.755);
  Vacuum->AddElement(O, 0.245);
  
  Air = new G4Material("Air", 1.29 * mg / cm3, 2, kStateGas);
  Air->AddElement(N, 0.7);
  Air->AddElement(O, 0.3);
  
  SS304LSteel = new G4Material("SS304LSteel", 8.00 * g / cm3, 5, kStateSolid);
  SS304LSteel->AddElement(Fe, 0.65);
  SS304LSteel->AddElement(Cr, 0.20);
  SS304LSteel->AddElement(Ni, 0.12);
  SS304LSteel->AddElement(Mn, 0.02);
  SS304LSteel->AddElement(Si, 0.01);
 
  PMMA = new G4Material("PMMA", 1190. * kg / m3, 3);
  PMMA->AddElement(H, 8);
  PMMA->AddElement(C, 5);
  PMMA->AddElement(O, 2);
  
  SiOil = new G4Material("SiOil", 0.963 * g/cm3 , 4);
  SiOil->AddElement(C, 6);
  SiOil->AddElement(H, 18);
  SiOil->AddElement(O, 1);
  SiOil->AddElement(Si, 2);
  
  Iron = new G4Material("Iron", 7.874 * g/cm3, 1);
  Iron->AddElement(Fe,1);
  
  
  StandardConcrete = new G4Material("Standard Concrete", 2.4 * g / cm3, 6);
  StandardConcrete->AddElement(C, 0.23);
  StandardConcrete->AddElement(O, 0.40);
  StandardConcrete->AddElement(Si, 0.12);
  StandardConcrete->AddElement(Ca, 0.12);
  StandardConcrete->AddElement(H, 0.10);
  StandardConcrete->AddElement(Mg, 0.02);
  
  Graphite = new G4Material("Graphite", 2.09 * g / cm3, 1);
  Graphite->AddElement(C, 1);
 
  LAB = new G4Material("LAB", 873 *kg / m3, 2);
  LAB->AddElement(H, 30);
  LAB->AddElement(C, 18);
  
  PXE = new G4Material("PXE", 210.2 *g / mole, 2);
  PXE->AddElement(H, 18);
  PXE->AddElement(C, 16);
  
  DIN = new G4Material("DIN", 212.33 *g / mole, 2);
  DIN->AddElement(H, 20);
  DIN->AddElement(C, 16);
  
  Gd3 = new G4Material("Gd3", 619.54 *g / mole, 4);
  Gd3->AddElement(H, 57);
  Gd3->AddElement(C, 33);
  Gd3->AddElement(O, 6);
  Gd3->AddElement(Ga, 1);
  
  THF = new G4Material("THF", 72.106  *g / mole, 3);
  THF->AddElement(H, 8);
  THF->AddElement(C, 4);
  THF->AddElement(O, 1);
  
  PPO = new G4Material("PPO", 221.259 *g / mole, 4);
  PPO->AddElement(H, 11);
  PPO->AddElement(C, 15);
  PPO->AddElement(O, 1);
  PPO->AddElement(N, 1);
  
  bisMSB = new G4Material("bisMSB", 310.43 *g / mole, 2);
  bisMSB->AddElement(H, 22);
  bisMSB->AddElement(C, 24);
  
  STEREOLS = new G4Material("STEREO Liquid Scintillator", 0.887 * g / cm3, 7);
  STEREOLS->AddMaterial(LAB, 0.73);
  STEREOLS->AddMaterial(PXE, 0.195);
  STEREOLS->AddMaterial(DIN, 0.049);
  STEREOLS->AddMaterial(Gd3, 0.009);
  STEREOLS->AddMaterial(THF, 0.009);
  STEREOLS->AddMaterial(PPO, 0.0078);
  STEREOLS->AddMaterial(bisMSB, 0.0002);
  
  Boron = new G4Material("Boron", 2.46 * g / cm3, 1);
  Boron->AddElement(B, 1);	

 
}


void OpaqueLSBoxDetectorConstruction::DefineMaterialsProperties()
{

    G4int iNbEntries = 3;

    G4double LABPhotonMomentum[iNbEntries] = {6.8 * eV, 7.0 * eV, 7.2 * eV};
    G4double LABRefractiveIndex[iNbEntries] = {1.50, 1.50, 1.50};
    G4double LABAbsorbtionLength[iNbEntries] = {4 * m, 4 * m, 4 * m};
    G4double LABScatteringLength[iNbEntries] = {5*mm,   5*mm,   5*mm};

    G4MaterialPropertiesTable *LABPropertiesTable = new G4MaterialPropertiesTable();
    LABPropertiesTable->AddProperty("RINDEX", LABPhotonMomentum, LABRefractiveIndex, iNbEntries);
    LABPropertiesTable->AddProperty("ABSLENGTH", LABPhotonMomentum, LABAbsorbtionLength, iNbEntries);
    LABPropertiesTable->AddProperty("RAYLEIGH", LABPhotonMomentum, LABScatteringLength, iNbEntries);

    LAB->SetMaterialPropertiesTable(LABPropertiesTable);
    
 


}




void OpaqueLSBoxDetectorConstruction::SetDefaults()
{
  
  fThickness = 10 * cm;

}

void OpaqueLSBoxDetectorConstruction::SetThickness(G4double k)
{
  fThickness = k;
  G4RunManager::GetRunManager()->ReinitializeGeometry();
}
