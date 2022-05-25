#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <sstream>
#include "TFile.h" 
#include "TH1.h" 
#include "TH2.h"
#include "TGraph.h"
#include "TTree.h"
#include "TROOT.h"
#include "TLorentzVector.h"
#include "TVector3.h"
#include "TH1D.h"
#include "TChain.h"
#include "TCanvas.h"
#include "TLorentzVector.h"
#include "TPaveText.h"
#include "TRandom.h"
#include "TGraphAsymmErrors.h"
#include "DesyTauAnalyses/NTupleMaker/interface/Config.h"
#include "DesyTauAnalyses/NTupleMaker/interface/AC1B.h"
#include "DesyTauAnalyses/NTupleMaker/interface/json.h"
#include "DesyTauAnalyses/NTupleMaker/interface/PileUp.h"
#include "DesyTauAnalyses/NTupleMaker/interface/Jets.h"
#include "HTT-utilities/RecoilCorrections/interface/RecoilCorrector.h"
#include "DesyTauAnalyses/NTupleMaker/interface/functions.h"
#include "DesyTauAnalyses/NTupleMaker/interface/LepTauFakeRate.h"
#include "HTT-utilities/LepEffInterface/interface/ScaleFactor.h"

int main(int argc, char * argv[]) {

  // first argument - config file 
  // second argument - filelist

  using namespace std;

  // **** configuration
  Config cfg(argv[1]);

  const string era = cfg.get<string>("Era");
  const bool isData = cfg.get<bool>("isData");
  const bool isDY = cfg.get<bool>("IsDY");
  const float DRTrigMatch    = cfg.get<float>("DRTrigMatch");  
  const bool applyGoodRunSelection = cfg.get<bool>("ApplyGoodRunSelection");
  const bool applyRecoilCorrections = cfg.get<bool>("ApplyRecoilCorrections");
  const string recoilFileName   = cfg.get<string>("RecoilFileName");


  // vertex cuts                                                                                                                            
  const float ndofVertexCut  = cfg.get<float>("NdofVertexCut");
  const float zVertexCut     = cfg.get<float>("ZVertexCut");
  const float dVertexCut     = cfg.get<float>("DVertexCut");


  // kinematic cuts on electrons
  const float ptEleCut = cfg.get<float>("ptEleCut");
  const float etaEleCut = cfg.get<float>("etaEleCut");
  const float dxyEleCut = cfg.get<float>("dxyEleCut");
  const float dzEleCut = cfg.get<float>("dzEleCut");

  // kinematic cuts on muons
  const float ptMuonCut  = cfg.get<float>("ptMuonCut");
  const float etaMuonCut = cfg.get<float>("etaMuonCut");
  const float dxyMuonCut     = cfg.get<float>("dxyMuonCut");
  const float dzMuonCut      = cfg.get<float>("dzMuonCut");

  //kinematic cuts on taus
  const float ptTauCut = cfg.get<float>("ptTauCut");
  const float etaTauCut = cfg.get<float>("etaTauCut");
  const float dzTauCut = cfg.get<float>("dzTauCut");
    
  const string jsonFile = cfg.get<string>("jsonFile");
  const string dataPUFile = cfg.get<string>("DataPUFile");
  const string mcPUFile = cfg.get<string>("MCPUFile");
  //  const string sampleName = cfg.get<string>("sampleName");
  const bool applyPUreweighting = cfg.get<bool>("ApplyPUreweighting");
  const string ZptweightFile = cfg.get<string>("ZptweightFile");

  // trigger
  const bool applyTrigger = cfg.get<bool>("ApplyTrigger");
  const bool applySingleEleTriggerOnly = cfg.get<bool>("ApplySingleEleTriggerOnly");
  const bool applySingleMuTriggerOnly = cfg.get<bool>("ApplySingleMuTriggerOnly");
  const string eleTriggerName_1  = cfg.get<string>("EleTriggerName_1");
  const string eleTriggerName_2  = cfg.get<string>("EleTriggerName_2");

  const string singleElectronFilterName = cfg.get<string>("SingleElectronFilterName");
  const float singleElectronTriggerPtCut = cfg.get<float>("SingleElectronTriggerPtCut");
  const float singleElectronTriggerEtaCut = cfg.get<float>("SingleElectronTriggerEtaCut");
    
  const string doubleElectronLeg1FilterName = cfg.get<string>("DoubleElectronLeg1FilterName");
  const float doubleElectronLeg1TriggerPtCut = cfg.get<float>("DoubleElectronLeg1TriggerPtCut");
    
  const string doubleElectronLeg2FilterName = cfg.get<string>("DoubleElectronLeg2FilterName");
  const float doubleElectronLeg2TriggerPtCut = cfg.get<float>("DoubleElectronLeg2TriggerPtCut");
    
  const string doubleElectronDzFilterName = cfg.get<string>("DoubleElectronDzFilterName");

  const string MuonIdIsoFile = cfg.get<string>("MuonIdIsoFile");
  const string MuonTriggerFile = cfg.get<string>("MuonTriggerFile");
  const string EleIdIsoFile = cfg.get<string>("EleIdIsoFile");
  const string EleTriggerFile = cfg.get<string>("EleTriggerFile");

  TString ElectronTriggerName_1(eleTriggerName_1);
  TString ElectronTriggerName_2(eleTriggerName_2);

  TString SingleElectronFilterName(singleElectronFilterName);
  TString DoubleElectronLeg1FilterName(doubleElectronLeg1FilterName);
  TString DoubleElectronLeg2FilterName(doubleElectronLeg2FilterName);
  TString DoubleElectronDzFilterName(doubleElectronDzFilterName);

  const string muonTriggerName_1  = cfg.get<string>("MuonTriggerName_1");
  const string muonTriggerName_2  = cfg.get<string>("MuonTriggerName_2");
  const string muonTriggerName_3  = cfg.get<string>("MuonTriggerName_3");
  const string muonTriggerName_4  = cfg.get<string>("MuonTriggerName_4");

  const string singleMuonFilterName_1_a = cfg.get<string>("SingleMuonFilterName_1_a");
  const string singleMuonFilterName_1_b = cfg.get<string>("SingleMuonFilterName_1_b");
  const float singleMuonTriggerPtCut_1 = cfg.get<float>("SingleMuonTriggerPtCut_1");
    
  const string singleMuonFilterName_2 = cfg.get<string>("SingleMuonFilterName_2");
  const float singleMuonTriggerPtCut_2 = cfg.get<float>("SingleMuonTriggerPtCut_2");
    
  const string doubleMuonLeg1FilterName_3 = cfg.get<string>("DoubleMuonLeg1FilterName_3");
  const float doubleMuonLeg1TriggerPtCut_3 = cfg.get<float>("DoubleMuonLeg1TriggerPtCut_3");
  const string doubleMuonLeg2FilterName_3_a = cfg.get<string>("DoubleMuonLeg2FilterName_3_a");
  const string doubleMuonLeg2FilterName_3_b = cfg.get<string>("DoubleMuonLeg2FilterName_3_b");
  const float doubleMuonLeg2TriggerPtCut_3 = cfg.get<float>("DoubleMuonLeg2TriggerPtCut_3");
  const string doubleMuonDzFilterName_3 = cfg.get<string>("DoubleMuonDzFilterName_3");
  const string doubleMuonMassFilterName_3 = cfg.get<string>("DoubleMuonMassFilterName_3");

  const string doubleMuonLeg1FilterName_4 = cfg.get<string>("DoubleMuonLeg1FilterName_4");
  const float doubleMuonLeg1TriggerPtCut_4 = cfg.get<float>("DoubleMuonLeg1TriggerPtCut_4");
  const string doubleMuonLeg2FilterName_4 = cfg.get<string>("DoubleMuonLeg2FilterName_4");
  const float doubleMuonLeg2TriggerPtCut_4 = cfg.get<float>("DoubleMuonLeg2TriggerPtCut_4");
  const string doubleMuonDzFilterName_4 = cfg.get<string>("DoubleMuonDzFilterName_4");


  string cmsswBase = (getenv ("CMSSW_BASE"));
  string fullPathToJsonFile = cmsswBase + "/src/DesyTauAnalyses/NTupleMaker/test/json/" + jsonFile;

  TFile * f_zptweight = new TFile(TString(cmsswBase)+"/src/"+ZptweightFile,"read");
  TH2D * h_zptweight = (TH2D*)f_zptweight->Get("zptmass_histo");


  // Run-lumi selector                                                                                                                      
  std::vector<Period> periods;
  if (isData)
    { // read the good runs                                                                                                                   
      std::fstream inputFileStream(fullPathToJsonFile.c_str(), std::ios::in);
      if (inputFileStream.fail() )
	{
	  std::cout << "Error: cannot find json file " << fullPathToJsonFile << std::endl;
	  std::cout << "please check" << std::endl;
	  std::cout << "quitting program" << std::endl;
	  exit(-1);
	}

      for(std::string s; std::getline(inputFileStream, s); )
	{
	  periods.push_back(Period());
	  std::stringstream ss(s);
	  ss >> periods.back();
	}
    }


  TString MuonTriggerName_1(muonTriggerName_1);
  TString MuonTriggerName_2(muonTriggerName_2);
  TString MuonTriggerName_3(muonTriggerName_3);
  TString MuonTriggerName_4(muonTriggerName_4);

  TString SingleMuonFilterName_1_a(singleMuonFilterName_1_a);
  TString SingleMuonFilterName_1_b(singleMuonFilterName_1_b);
  TString SingleMuonFilterName_2(singleMuonFilterName_2);
  TString DoubleMuonLeg1FilterName_3(doubleMuonLeg1FilterName_3);
  TString DoubleMuonLeg2FilterName_3_a(doubleMuonLeg2FilterName_3_a);
  TString DoubleMuonLeg2FilterName_3_b(doubleMuonLeg2FilterName_3_b);
  TString DoubleMuonDzFilterName_3(doubleMuonDzFilterName_3);
  TString DoubleMuonMassFilterName_3(doubleMuonMassFilterName_3);

  TString DoubleMuonLeg1FilterName_4(doubleMuonLeg1FilterName_4);
  TString DoubleMuonLeg2FilterName_4(doubleMuonLeg2FilterName_4);
  TString DoubleMuonDzFilterName_4(doubleMuonDzFilterName_4);






  // file name and tree name
  std::string rootFileName(argv[2]);
  std::ifstream fileList(argv[2]);
  std::ifstream fileList0(argv[2]);
  std::string ntupleName("makeroottree/AC1B");
  std::string initNtupleName("initroottree/AC1B");

  RecoilCorrector* recoilPFMetCorrector = (RecoilCorrector*) malloc(sizeof(*recoilPFMetCorrector));
  recoilPFMetCorrector = new RecoilCorrector(recoilFileName);


  TFile * file = new TFile(TString(rootFileName)+".root","recreate");
  file->cd("");

    
  //declare the tree
  TTree * SynTree = new TTree("SynTree","SynTree");
  TH1D * histWeightsH = new TH1D("histWeightsH","",1,-0.5,0.5);
    

  //Event ID variable
  ULong64_t run;
  UInt_t lumi;
  ULong64_t evt;
    
  //New variables for FR

  Bool_t is_eee = false;
  Bool_t is_eem = false;
  Bool_t is_mme = false;
  Bool_t is_mmm = false;

  Float_t puweight = 1.0;
  Float_t mcweight = 1.0;
  Float_t zptweight = 1.0;
  UInt_t npartons = -99;


  Float_t for_eee_fake_ele_iso = -99;
  Bool_t for_eee_fake_ele_id = false;
  Float_t for_eee_ele_1_iso = -99;
  Bool_t for_eee_ele_1_id = false;
  Float_t for_eee_ele_2_iso = -99;
  Bool_t for_eee_ele_2_id = false;
  Float_t for_eee_mu_1_iso = -99; //
  Bool_t for_eee_mu_1_id = false; //
  Float_t for_eee_mu_2_iso = -99; //
  Bool_t for_eee_mu_2_id = false; //
  Float_t for_eee_m_E1_fake_elec = -99;
  Float_t for_eee_m_E2_fake_elec = -99;
  Float_t for_eee_m_EE = -99;
  Float_t for_eee_pfmt_fake_electron = -99;
  Float_t for_eee_pfmt_fake_electron_JetEnUp = -99;
  Float_t for_eee_pfmt_fake_electron_JetEnDown = -99;
  Float_t for_eee_pfmt_fake_electron_UnclusteredEnUp = -99;
  Float_t for_eee_pfmt_fake_electron_UnclusteredEnDown = -99;
  Float_t for_eee_pfmt_fake_electron_JetResUp = -99;
  Float_t for_eee_pfmt_fake_electron_JetResDown = -99;
  Float_t for_eee_fake_muon_iso = -99;
  Bool_t for_eee_fake_muon_id = false;
  Float_t for_eee_m_3l = -99;
  Float_t for_eee_pfmt_fake_muon = -99;
  Float_t for_eee_m_M1_fake_elec = -99;
  Float_t for_eee_m_M2_fake_elec = -99;
  Float_t for_eee_m_MM = -99;
  Float_t for_eee_fake_muon_eta = -99;
  Float_t for_eee_fake_ele_eta = -99;
  Float_t for_eee_dR_Z1_fake_lepton = -99;
  Float_t for_eee_dR_Z2_fake_lepton = -99;
  Float_t for_eee_pt_fake_e = -99;
  Float_t for_eee_pt_fake_m = -99;
  Int_t for_eee_gen_match_1 = 6;
  Int_t for_eee_gen_match_2 = 6;
  Int_t for_eee_gen_match_3 = 6;
  Float_t for_eee_electronIDSF_1 = 1.0;
  Float_t for_eee_electronIDSF_2 = 1.0;
  Float_t for_eee_electronIDSF_fake = 1.0;
  Float_t for_eee_muonIDSF_1 = 1.0; 
  Float_t for_eee_muonIDSF_2 = 1.0;
  Float_t for_eee_muonIDSF_fake = 1.0;
  Float_t for_eee_electronTrigSF_1 = 1.0;
  Float_t for_eee_muonTrigSF_1 = 1.0;
  Float_t for_eee_electronTrigSF_2 = 1.0;
  Float_t for_eee_muonTrigSF_2 = 1.0;

  Float_t for_eem_fake_ele_iso = -99;
  Bool_t for_eem_fake_ele_id = false;
  Float_t for_eem_ele_1_iso = -99;
  Bool_t for_eem_ele_1_id = false;
  Float_t for_eem_ele_2_iso = -99;
  Bool_t for_eem_ele_2_id = false;
  Float_t for_eem_mu_1_iso = -99; //
  Float_t for_eem_mu_1_id = false; //
  Float_t for_eem_mu_2_iso = -99; //
  Float_t for_eem_mu_2_id = false; //
  Float_t for_eem_m_E1_fake_elec = -99;
  Float_t for_eem_m_E2_fake_elec = -99;
  Float_t for_eem_m_EE = -99;
  Float_t for_eem_pfmt_fake_electron = -99;
  Float_t for_eem_fake_muon_iso = -99;
  Bool_t for_eem_fake_muon_id = false;
  Float_t for_eem_m_3l = -99;
  Float_t for_eem_pfmt_fake_muon = -99;
  Float_t for_eem_pfmt_fake_muon_JetEnUp = -99;
  Float_t for_eem_pfmt_fake_muon_JetEnDown = -99;
  Float_t for_eem_pfmt_fake_muon_UnclusteredEnUp = -99;
  Float_t for_eem_pfmt_fake_muon_UnclusteredEnDown = -99;
  Float_t for_eem_pfmt_fake_muon_JetResUp = -99;
  Float_t for_eem_pfmt_fake_muon_JetResDown = -99;
  Float_t for_eem_m_M1_fake_elec = -99;
  Float_t for_eem_m_M2_fake_elec = -99;
  Float_t for_eem_m_MM = -99;
  Float_t for_eem_fake_muon_eta = -99;
  Float_t for_eem_fake_ele_eta = -99;
  Float_t for_eem_dR_Z1_fake_lepton = -99;
  Float_t for_eem_dR_Z2_fake_lepton = -99;
  Float_t for_eem_pt_fake_e = -99;
  Float_t for_eem_pt_fake_m = -99;
  Int_t for_eem_gen_match_1 = 6;
  Int_t for_eem_gen_match_2 = 6;
  Int_t for_eem_gen_match_3 = 6;
  Float_t for_eem_electronIDSF_1 = 1.0;
  Float_t for_eem_electronIDSF_2 = 1.0;
  Float_t for_eem_electronIDSF_fake = 1.0;
  Float_t for_eem_muonIDSF_1 = 1.0; 
  Float_t for_eem_muonIDSF_2 = 1.0;
  Float_t for_eem_muonIDSF_fake = 1.0;
  Float_t for_eem_electronTrigSF_1 = 1.0;
  Float_t for_eem_muonTrigSF_1 = 1.0;
  Float_t for_eem_electronTrigSF_2 = 1.0;
  Float_t for_eem_muonTrigSF_2 = 1.0;

  Float_t for_mme_fake_ele_iso = -99;
  Bool_t for_mme_fake_ele_id = false;
  Float_t for_mme_ele_1_iso = -99;
  Bool_t for_mme_ele_1_id = false;
  Float_t for_mme_ele_2_iso = -99;
  Bool_t for_mme_ele_2_id = false;
  Float_t for_mme_mu_1_iso = -99; //
  Bool_t for_mme_mu_1_id = false; //
  Float_t for_mme_mu_2_iso = -99; //
  Bool_t for_mme_mu_2_id = false; //
  Float_t for_mme_m_E1_fake_elec = -99;
  Float_t for_mme_m_E2_fake_elec = -99;
  Float_t for_mme_m_EE = -99;
  Float_t for_mme_pfmt_fake_electron = -99;
  Float_t for_mme_pfmt_fake_electron_JetEnUp = -99;
  Float_t for_mme_pfmt_fake_electron_JetEnDown = -99;
  Float_t for_mme_pfmt_fake_electron_UnclusteredEnUp = -99;
  Float_t for_mme_pfmt_fake_electron_UnclusteredEnDown = -99;
  Float_t for_mme_pfmt_fake_electron_JetResUp = -99;
  Float_t for_mme_pfmt_fake_electron_JetResDown = -99;
  Float_t for_mme_fake_muon_iso = -99;
  Bool_t for_mme_fake_muon_id = false;
  Float_t for_mme_m_3l = -99;
  Float_t for_mme_pfmt_fake_muon = -99;
  Float_t for_mme_m_M1_fake_elec = -99;
  Float_t for_mme_m_M2_fake_elec = -99;
  Float_t for_mme_m_MM = -99;
  Float_t for_mme_fake_muon_eta = -99;
  Float_t for_mme_fake_ele_eta = -99;
  Float_t for_mme_dR_Z1_fake_lepton = -99;
  Float_t for_mme_dR_Z2_fake_lepton = -99;
  Float_t for_mme_pt_fake_e = -99;
  Float_t for_mme_pt_fake_m = -99;
  Int_t for_mme_gen_match_1 = 6;
  Int_t for_mme_gen_match_2 = 6;
  Int_t for_mme_gen_match_3 = 6;
  Float_t for_mme_electronIDSF_1 = 1.0;
  Float_t for_mme_electronIDSF_2 = 1.0;
  Float_t for_mme_electronIDSF_fake = 1.0;
  Float_t for_mme_muonIDSF_1 = 1.0; 
  Float_t for_mme_muonIDSF_2 = 1.0;
  Float_t for_mme_muonIDSF_fake = 1.0;
  Float_t for_mme_electronTrigSF_1 = 1.0;
  Float_t for_mme_muonTrigSF_1 = 1.0;
  Float_t for_mme_electronTrigSF_2 = 1.0;
  Float_t for_mme_muonTrigSF_2 = 1.0;

  Float_t for_mmm_fake_ele_iso = -99;
  Bool_t for_mmm_fake_ele_id = false;
  Float_t for_mmm_ele_1_iso = -99;
  Bool_t for_mmm_ele_1_id = false;
  Float_t for_mmm_ele_2_iso = -99;
  Bool_t for_mmm_ele_2_id = false;
  Float_t for_mmm_mu_1_iso = -99; //
  Bool_t for_mmm_mu_1_id = false; //
  Float_t for_mmm_mu_2_iso = -99; //
  Bool_t for_mmm_mu_2_id = false; 
  Float_t for_mmm_m_E1_fake_elec = -99;
  Float_t for_mmm_m_E2_fake_elec = -99;
  Float_t for_mmm_m_EE = -99;
  Float_t for_mmm_pfmt_fake_electron = -99;
  Float_t for_mmm_fake_muon_iso = -99;
  Bool_t for_mmm_fake_muon_id = false;
  Float_t for_mmm_m_3l = -99;
  Float_t for_mmm_pfmt_fake_muon = -99;
  Float_t for_mmm_pfmt_fake_muon_JetEnUp = -99;
  Float_t for_mmm_pfmt_fake_muon_JetEnDown = -99;
  Float_t for_mmm_pfmt_fake_muon_UnclusteredEnUp = -99;
  Float_t for_mmm_pfmt_fake_muon_UnclusteredEnDown = -99;
  Float_t for_mmm_pfmt_fake_muon_JetResUp = -99;
  Float_t for_mmm_pfmt_fake_muon_JetResDown = -99;
  Float_t for_mmm_m_M1_fake_elec = -99;
  Float_t for_mmm_m_M2_fake_elec = -99;
  Float_t for_mmm_m_MM = -99;
  Float_t for_mmm_fake_muon_eta = -99;
  Float_t for_mmm_fake_ele_eta = -99;
  Float_t for_mmm_dR_Z1_fake_lepton = -99;
  Float_t for_mmm_dR_Z2_fake_lepton = -99;
  Float_t for_mmm_pt_fake_e = -99;
  Float_t for_mmm_pt_fake_m = -99;
  Int_t for_mmm_gen_match_1 = 6;
  Int_t for_mmm_gen_match_2 = 6;
  Int_t for_mmm_gen_match_3 = 6;
  Float_t for_mmm_electronIDSF_1 = 1.0;
  Float_t for_mmm_electronIDSF_2 = 1.0;
  Float_t for_mmm_electronIDSF_fake = 1.0;
  Float_t for_mmm_muonIDSF_1 = 1.0; 
  Float_t for_mmm_muonIDSF_2 = 1.0;
  Float_t for_mmm_muonIDSF_fake = 1.0;
  Float_t for_mmm_electronTrigSF_1 = 1.0;
  Float_t for_mmm_muonTrigSF_1 = 1.0;
  Float_t for_mmm_electronTrigSF_2 = 1.0;
  Float_t for_mmm_muonTrigSF_2 = 1.0;

  SynTree->Branch("run",&run,"run/l");
  SynTree->Branch("lumi",&lumi,"lumi/i");
  SynTree->Branch("evt",&evt,"evt/l");

  SynTree->Branch("is_eee",&is_eee,"is_eee/O");
  SynTree->Branch("is_eem",&is_eem,"is_eem/O");
  SynTree->Branch("is_mme",&is_mme,"is_mme/O");
  SynTree->Branch("is_mmm",&is_mmm,"is_mmm/O");

  SynTree->Branch("npartons",&npartons,"npartons/i");
  SynTree->Branch("mcweight",&mcweight,"mcweight/F");
  SynTree->Branch("puweight", &puweight, "puweight/F");
  SynTree->Branch("zptweight", &zptweight, "zptweight/F");


  //New branches for FR measurement
  SynTree->Branch("for_eee_fake_ele_iso",&for_eee_fake_ele_iso,"for_eee_fake_ele_iso/F");
  SynTree->Branch("for_eee_fake_ele_id",&for_eee_fake_ele_id,"for_eee_fake_ele_id/O");
  SynTree->Branch("for_eee_ele_1_iso",&for_eee_ele_1_iso,"for_eee_ele_1_iso/F");
  SynTree->Branch("for_eee_ele_1_id",&for_eee_ele_1_id,"for_eee_ele_1_id/O");
  SynTree->Branch("for_eee_ele_2_iso",&for_eee_ele_2_iso,"for_eee_ele_2_iso/F");
  SynTree->Branch("for_eee_ele_2_id",&for_eee_ele_2_id,"for_eee_ele_2_id/O");
  SynTree->Branch("for_eee_mu_1_iso",&for_eee_mu_1_iso,"for_eee_mu_1_iso/F");
  SynTree->Branch("for_eee_mu_1_id",&for_eee_mu_1_id,"for_eee_mu_1_id/O");
  SynTree->Branch("for_eee_mu_2_iso",&for_eee_mu_2_iso,"for_eee_mu_2_iso/F");
  SynTree->Branch("for_eee_mu_2_id",&for_eee_mu_2_id,"for_eee_mu_2_id/O");
  SynTree->Branch("for_eee_m_E1_fake_elec",&for_eee_m_E1_fake_elec,"for_eee_m_E1_fake_elec/F");
  SynTree->Branch("for_eee_m_E2_fake_elec",&for_eee_m_E2_fake_elec,"for_eee_m_E2_fake_elec/F");
  SynTree->Branch("for_eee_pfmt_fake_electron",&for_eee_pfmt_fake_electron,"for_eee_pfmt_fake_electron/F");
  SynTree->Branch("for_eee_pfmt_fake_electron_JetEnUp",&for_eee_pfmt_fake_electron_JetEnUp,"for_eee_pfmt_fake_electron_JetEnUp/F");
  SynTree->Branch("for_eee_pfmt_fake_electron_JetEnDown",&for_eee_pfmt_fake_electron_JetEnDown,"for_eee_pfmt_fake_electron_JetEnDown/F");
  SynTree->Branch("for_eee_pfmt_fake_electron_UnclusteredEnUp",&for_eee_pfmt_fake_electron_UnclusteredEnUp,"for_eee_pfmt_fake_electron_UnclusteredEnUp/F");
  SynTree->Branch("for_eee_pfmt_fake_electron_UnclusteredEnDown",&for_eee_pfmt_fake_electron_UnclusteredEnDown,"for_eee_pfmt_fake_electron_UnclusteredEnDown/F");
  SynTree->Branch("for_eee_pfmt_fake_electron_JetResUp",&for_eee_pfmt_fake_electron_JetResUp,"for_eee_pfmt_fake_electron_JetResUp/F");
  SynTree->Branch("for_eee_pfmt_fake_electron_JetResDown",&for_eee_pfmt_fake_electron_JetResDown,"for_eee_pfmt_fake_electron_JetResDown/F");
  SynTree->Branch("for_eee_fake_muon_iso",&for_eee_fake_muon_iso,"for_eee_fake_muon_iso/F");
  SynTree->Branch("for_eee_fake_muon_id",&for_eee_fake_muon_id,"for_eee_fake_muon_id/O");
  SynTree->Branch("for_eee_m_3l",&for_eee_m_3l,"for_eee_m_3l/F");
  SynTree->Branch("for_eee_pfmt_fake_muon",&for_eee_pfmt_fake_muon,"for_eee_pfmt_fake_muon/F");
  SynTree->Branch("for_eee_m_M1_fake_elec",&for_eee_m_M1_fake_elec,"for_eee_m_M1_fake_elec/F");
  SynTree->Branch("for_eee_m_M2_fake_elec",&for_eee_m_M2_fake_elec,"for_eee_m_M2_fake_elec/F");
  SynTree->Branch("for_eee_fake_ele_eta",&for_eee_fake_ele_eta,"for_eee_fake_ele_eta/F"); 
  SynTree->Branch("for_eee_fake_muon_eta",&for_eee_fake_muon_eta,"for_eee_fake_muon_eta/F"); 
  SynTree->Branch("for_eee_m_EE",&for_eee_m_EE,"for_eee_m_EE/F");
  SynTree->Branch("for_eee_m_MM",&for_eee_m_MM,"for_eee_m_MM/F");
  SynTree->Branch("for_eee_dR_Z1_fake_lepton",&for_eee_dR_Z1_fake_lepton,"for_eee_dR_Z1_fake_lepton/F");
  SynTree->Branch("for_eee_dR_Z2_fake_lepton",&for_eee_dR_Z2_fake_lepton,"for_eee_dR_Z2_fake_lepton/F");
  SynTree->Branch("for_eee_pt_fake_e",&for_eee_pt_fake_e,"for_eee_pt_fake_e/F"); 
  SynTree->Branch("for_eee_pt_fake_m",&for_eee_pt_fake_m,"for_eee_pt_fake_m/F"); 
  SynTree->Branch("for_eee_gen_match_1",&for_eee_gen_match_1,"for_eee_gen_match_1/I");
  SynTree->Branch("for_eee_gen_match_2",&for_eee_gen_match_2,"for_eee_gen_match_2/I");
  SynTree->Branch("for_eee_gen_match_3",&for_eee_gen_match_3,"for_eee_gen_match_3/I");  //3->fake lepton
  SynTree->Branch("for_eee_electronIDSF_1",&for_eee_electronIDSF_1,"for_eee_electronIDSF_1/F"); 
  SynTree->Branch("for_eee_electronIDSF_2",&for_eee_electronIDSF_2,"for_eee_electronIDSF_2/F"); 
  SynTree->Branch("for_eee_electronIDSF_fake",&for_eee_electronIDSF_fake,"for_eee_electronIDSF_fake/F"); 
  SynTree->Branch("for_eee_muonIDSF_1",&for_eee_muonIDSF_1,"for_eee_muonIDSF_1/F");  
  SynTree->Branch("for_eee_muonIDSF_2",&for_eee_muonIDSF_2,"for_eee_muonIDSF_2/F");
  SynTree->Branch("for_eee_muonIDSF_fake",&for_eee_muonIDSF_fake,"for_eee_muonIDSF_fake/F");  
  SynTree->Branch("for_eee_electronTrigSF_1",&for_eee_electronTrigSF_1,"for_eee_electronTrigSF_1/F"); 
  SynTree->Branch("for_eee_electronTrigSF_2",&for_eee_electronTrigSF_2,"for_eee_electronTrigSF_2/F"); 
  SynTree->Branch("for_eee_muonTrigSF_1",&for_eee_muonTrigSF_1,"for_eee_muonTrigSF_1/F");  
  SynTree->Branch("for_eee_muonTrigSF_2",&for_eee_muonTrigSF_2,"for_eee_muonTrigSF_2/F");

  SynTree->Branch("for_eem_fake_ele_iso",&for_eem_fake_ele_iso,"for_eem_fake_ele_iso/F");
  SynTree->Branch("for_eem_fake_ele_id",&for_eem_fake_ele_id,"for_eem_fake_ele_id/O");
  SynTree->Branch("for_eem_ele_1_iso",&for_eem_ele_1_iso,"for_eem_ele_1_iso/F");
  SynTree->Branch("for_eem_ele_1_id",&for_eem_ele_1_id,"for_eem_ele_1_id/O");
  SynTree->Branch("for_eem_ele_2_iso",&for_eem_ele_2_iso,"for_eem_ele_2_iso/F");
  SynTree->Branch("for_eem_ele_2_id",&for_eem_ele_2_id,"for_eem_ele_2_id/O");
  SynTree->Branch("for_eem_mu_1_iso",&for_eem_mu_1_iso,"for_eem_mu_1_iso/F");
  SynTree->Branch("for_eem_mu_1_id",&for_eem_mu_1_id,"for_eem_mu_1_id/O");
  SynTree->Branch("for_eem_mu_2_iso",&for_eem_mu_2_iso,"for_eem_mu_2_iso/F");
  SynTree->Branch("for_eem_mu_2_id",&for_eem_mu_2_id,"for_eem_mu_2_id/O");
  SynTree->Branch("for_eem_m_E1_fake_elec",&for_eem_m_E1_fake_elec,"for_eem_m_E1_fake_elec/F");
  SynTree->Branch("for_eem_m_E2_fake_elec",&for_eem_m_E2_fake_elec,"for_eem_m_E2_fake_elec/F");
  SynTree->Branch("for_eem_pfmt_fake_electron",&for_eem_pfmt_fake_electron,"for_eem_pfmt_fake_electron/F");
  SynTree->Branch("for_eem_fake_muon_iso",&for_eem_fake_muon_iso,"for_eem_fake_muon_iso/F");
  SynTree->Branch("for_eem_fake_muon_id",&for_eem_fake_muon_id,"for_eem_fake_muon_id/O");
  SynTree->Branch("for_eem_m_3l",&for_eem_m_3l,"for_eem_m_3l/F");
  SynTree->Branch("for_eem_pfmt_fake_muon",&for_eem_pfmt_fake_muon,"for_eem_pfmt_fake_muon/F");
  SynTree->Branch("for_eem_pfmt_fake_muon_JetEnUp",&for_eem_pfmt_fake_muon_JetEnUp,"for_eem_pfmt_fake_muon_JetEnUp/F");
  SynTree->Branch("for_eem_pfmt_fake_muon_JetEnDown",&for_eem_pfmt_fake_muon_JetEnDown,"for_eem_pfmt_fake_muon_JetEnDown/F");
  SynTree->Branch("for_eem_pfmt_fake_muon_UnclusteredEnUp",&for_eem_pfmt_fake_muon_UnclusteredEnUp,"for_eem_pfmt_fake_muon_UnclusteredEnUp/F");
  SynTree->Branch("for_eem_pfmt_fake_muon_UnclusteredEnDown",&for_eem_pfmt_fake_muon_UnclusteredEnDown,"for_eem_pfmt_fake_muon_UnclusteredEnDown/F");
  SynTree->Branch("for_eem_pfmt_fake_muon_JetResUp",&for_eem_pfmt_fake_muon_JetResUp,"for_eem_pfmt_fake_muon_JetResUp/F");
  SynTree->Branch("for_eem_pfmt_fake_muon_JetResDown",&for_eem_pfmt_fake_muon_JetResDown,"for_eem_pfmt_fake_muon_JetResDown/F");
  SynTree->Branch("for_eem_m_M1_fake_elec",&for_eem_m_M1_fake_elec,"for_eem_m_M1_fake_elec/F");
  SynTree->Branch("for_eem_m_M2_fake_elec",&for_eem_m_M2_fake_elec,"for_eem_m_M2_fake_elec/F");
  SynTree->Branch("for_eem_fake_ele_eta",&for_eem_fake_ele_eta,"for_eem_fake_ele_eta/F"); 
  SynTree->Branch("for_eem_fake_muon_eta",&for_eem_fake_muon_eta,"for_eem_fake_muon_eta/F"); 
  SynTree->Branch("for_eem_m_EE",&for_eem_m_EE,"for_eem_m_EE/F");
  SynTree->Branch("for_eem_m_MM",&for_eem_m_MM,"for_eem_m_MM/F");
  SynTree->Branch("for_eem_dR_Z1_fake_lepton",&for_eem_dR_Z1_fake_lepton,"for_eem_dR_Z1_fake_lepton/F");
  SynTree->Branch("for_eem_dR_Z2_fake_lepton",&for_eem_dR_Z2_fake_lepton,"for_eem_dR_Z2_fake_lepton/F");
  SynTree->Branch("for_eem_pt_fake_e",&for_eem_pt_fake_e,"for_eem_pt_fake_e/F"); 
  SynTree->Branch("for_eem_pt_fake_m",&for_eem_pt_fake_m,"for_eem_pt_fake_m/F"); 
  SynTree->Branch("for_eem_gen_match_1",&for_eem_gen_match_1,"for_eem_gen_match_1/I");
  SynTree->Branch("for_eem_gen_match_2",&for_eem_gen_match_2,"for_eem_gen_match_2/I");
  SynTree->Branch("for_eem_gen_match_3",&for_eem_gen_match_3,"for_eem_gen_match_3/I");  //3->fake lepton
  SynTree->Branch("for_eem_electronIDSF_1",&for_eem_electronIDSF_1,"for_eem_electronIDSF_1/F"); 
  SynTree->Branch("for_eem_electronIDSF_2",&for_eem_electronIDSF_2,"for_eem_electronIDSF_2/F"); 
  SynTree->Branch("for_eem_electronIDSF_fake",&for_eem_electronIDSF_fake,"for_eem_electronIDSF_fake/F"); 
  SynTree->Branch("for_eem_muonIDSF_1",&for_eem_muonIDSF_1,"for_eem_muonIDSF_1/F");  
  SynTree->Branch("for_eem_muonIDSF_2",&for_eem_muonIDSF_2,"for_eem_muonIDSF_2/F");
  SynTree->Branch("for_eem_muonIDSF_fake",&for_eem_muonIDSF_fake,"for_eem_muonIDSF_fake/F");  
  SynTree->Branch("for_eem_electronTrigSF_1",&for_eem_electronTrigSF_1,"for_eem_electronTrigSF_1/F"); 
  SynTree->Branch("for_eem_electronTrigSF_2",&for_eem_electronTrigSF_2,"for_eem_electronTrigSF_2/F"); 
  SynTree->Branch("for_eem_muonTrigSF_1",&for_eem_muonTrigSF_1,"for_eem_muonTrigSF_1/F");  
  SynTree->Branch("for_eem_muonTrigSF_2",&for_eem_muonTrigSF_2,"for_eem_muonTrigSF_2/F");

  SynTree->Branch("for_mme_fake_ele_iso",&for_mme_fake_ele_iso,"for_mme_fake_ele_iso/F");
  SynTree->Branch("for_mme_fake_ele_id",&for_mme_fake_ele_id,"for_mme_fake_ele_id/O");
  SynTree->Branch("for_mme_ele_1_iso",&for_mme_ele_1_iso,"for_mme_ele_1_iso/F");
  SynTree->Branch("for_mme_ele_1_id",&for_mme_ele_1_id,"for_mme_ele_1_id/O");
  SynTree->Branch("for_mme_ele_2_iso",&for_mme_ele_2_iso,"for_mme_ele_2_iso/F");
  SynTree->Branch("for_mme_ele_2_id",&for_mme_ele_2_id,"for_mme_ele_2_id/O");
  SynTree->Branch("for_mme_mu_1_iso",&for_mme_mu_1_iso,"for_mme_mu_1_iso/F");
  SynTree->Branch("for_mme_mu_1_id",&for_mme_mu_1_id,"for_mme_mu_1_id/O");
  SynTree->Branch("for_mme_mu_2_iso",&for_mme_mu_2_iso,"for_mme_mu_2_iso/F");
  SynTree->Branch("for_mme_mu_2_id",&for_mme_mu_2_id,"for_mme_mu_2_id/O");
  SynTree->Branch("for_mme_m_E1_fake_elec",&for_mme_m_E1_fake_elec,"for_mme_m_E1_fake_elec/F");
  SynTree->Branch("for_mme_m_E2_fake_elec",&for_mme_m_E2_fake_elec,"for_mme_m_E2_fake_elec/F");
  SynTree->Branch("for_mme_pfmt_fake_electron",&for_mme_pfmt_fake_electron,"for_mme_pfmt_fake_electron/F");
  SynTree->Branch("for_mme_pfmt_fake_electron_JetEnUp",&for_mme_pfmt_fake_electron_JetEnUp,"for_mme_pfmt_fake_electron_JetEnUp/F");
  SynTree->Branch("for_mme_pfmt_fake_electron_JetEnDown",&for_mme_pfmt_fake_electron_JetEnDown,"for_mme_pfmt_fake_electron_JetEnDown/F");
  SynTree->Branch("for_mme_pfmt_fake_electron_UnclusteredEnUp",&for_mme_pfmt_fake_electron_UnclusteredEnUp,"for_mme_pfmt_fake_electron_UnclusteredEnUp/F");
  SynTree->Branch("for_mme_pfmt_fake_electron_UnclusteredEnDown",&for_mme_pfmt_fake_electron_UnclusteredEnDown,"for_mme_pfmt_fake_electron_UnclusteredEnDown/F");
  SynTree->Branch("for_mme_pfmt_fake_electron_JetResUp",&for_mme_pfmt_fake_electron_JetResUp,"for_mme_pfmt_fake_electron_JetResUp/F");
  SynTree->Branch("for_mme_pfmt_fake_electron_JetResDown",&for_mme_pfmt_fake_electron_JetResDown,"for_mme_pfmt_fake_electron_JetResDown/F");
  SynTree->Branch("for_mme_fake_muon_iso",&for_mme_fake_muon_iso,"for_mme_fake_muon_iso/F");
  SynTree->Branch("for_mme_fake_muon_id",&for_mme_fake_muon_id,"for_mme_fake_muon_id/O");
  SynTree->Branch("for_mme_m_3l",&for_mme_m_3l,"for_mme_m_3l/F");
  SynTree->Branch("for_mme_pfmt_fake_muon",&for_mme_pfmt_fake_muon,"for_mme_pfmt_fake_muon/F");
  SynTree->Branch("for_mme_m_M1_fake_elec",&for_mme_m_M1_fake_elec,"for_mme_m_M1_fake_elec/F");
  SynTree->Branch("for_mme_m_M2_fake_elec",&for_mme_m_M2_fake_elec,"for_mme_m_M2_fake_elec/F");
  SynTree->Branch("for_mme_fake_ele_eta",&for_mme_fake_ele_eta,"for_mme_fake_ele_eta/F"); 
  SynTree->Branch("for_mme_fake_muon_eta",&for_mme_fake_muon_eta,"for_mme_fake_muon_eta/F"); 
  SynTree->Branch("for_mme_m_EE",&for_mme_m_EE,"for_mme_m_EE/F");
  SynTree->Branch("for_mme_m_MM",&for_mme_m_MM,"for_mme_m_MM/F");
  SynTree->Branch("for_mme_dR_Z1_fake_lepton",&for_mme_dR_Z1_fake_lepton,"for_mme_dR_Z1_fake_lepton/F");
  SynTree->Branch("for_mme_dR_Z2_fake_lepton",&for_mme_dR_Z2_fake_lepton,"for_mme_dR_Z2_fake_lepton/F");
  SynTree->Branch("for_mme_pt_fake_e",&for_mme_pt_fake_e,"for_mme_pt_fake_e/F"); 
  SynTree->Branch("for_mme_pt_fake_m",&for_mme_pt_fake_m,"for_mme_pt_fake_m/F"); 
  SynTree->Branch("for_mme_gen_match_1",&for_mme_gen_match_1,"for_mme_gen_match_1/I");
  SynTree->Branch("for_mme_gen_match_2",&for_mme_gen_match_2,"for_mme_gen_match_2/I");
  SynTree->Branch("for_mme_gen_match_3",&for_mme_gen_match_3,"for_mme_gen_match_3/I");  //3->fake lepton
  SynTree->Branch("for_mme_electronIDSF_1",&for_mme_electronIDSF_1,"for_mme_electronIDSF_1/F"); 
  SynTree->Branch("for_mme_electronIDSF_2",&for_mme_electronIDSF_2,"for_mme_electronIDSF_2/F"); 
  SynTree->Branch("for_mme_electronIDSF_fake",&for_mme_electronIDSF_fake,"for_mme_electronIDSF_fake/F"); 
  SynTree->Branch("for_mme_muonIDSF_1",&for_mme_muonIDSF_1,"for_mme_muonIDSF_1/F");  
  SynTree->Branch("for_mme_muonIDSF_2",&for_mme_muonIDSF_2,"for_mme_muonIDSF_2/F");
  SynTree->Branch("for_mme_muonIDSF_fake",&for_mme_muonIDSF_fake,"for_mme_muonIDSF_fake/F");  
  SynTree->Branch("for_mme_electronTrigSF_1",&for_mme_electronTrigSF_1,"for_mme_electronTrigSF_1/F"); 
  SynTree->Branch("for_mme_electronTrigSF_2",&for_mme_electronTrigSF_2,"for_mme_electronTrigSF_2/F"); 
  SynTree->Branch("for_mme_muonTrigSF_1",&for_mme_muonTrigSF_1,"for_mme_muonTrigSF_1/F");  
  SynTree->Branch("for_mme_muonTrigSF_2",&for_mme_muonTrigSF_2,"for_mme_muonTrigSF_2/F");

  SynTree->Branch("for_mmm_fake_ele_iso",&for_mmm_fake_ele_iso,"for_mmm_fake_ele_iso/F");
  SynTree->Branch("for_mmm_fake_ele_id",&for_mmm_fake_ele_id,"for_mmm_fake_ele_id/O");
  SynTree->Branch("for_mmm_ele_1_iso",&for_mmm_ele_1_iso,"for_mmm_ele_1_iso/F");
  SynTree->Branch("for_mmm_ele_1_id",&for_mmm_ele_1_id,"for_mmm_ele_1_id/O");
  SynTree->Branch("for_mmm_ele_2_iso",&for_mmm_ele_2_iso,"for_mmm_ele_2_iso/F");
  SynTree->Branch("for_mmm_ele_2_id",&for_mmm_ele_2_id,"for_mmm_ele_2_id/O");
  SynTree->Branch("for_mmm_mu_1_iso",&for_mmm_mu_1_iso,"for_mmm_mu_1_iso/F");
  SynTree->Branch("for_mmm_mu_1_id",&for_mmm_mu_1_id,"for_mmm_mu_1_id/O");
  SynTree->Branch("for_mmm_mu_2_iso",&for_mmm_mu_2_iso,"for_mmm_mu_2_iso/F");
  SynTree->Branch("for_mmm_mu_2_id",&for_mmm_mu_2_id,"for_mmm_mu_2_id/O");
  SynTree->Branch("for_mmm_m_E1_fake_elec",&for_mmm_m_E1_fake_elec,"for_mmm_m_E1_fake_elec/F");
  SynTree->Branch("for_mmm_m_E2_fake_elec",&for_mmm_m_E2_fake_elec,"for_mmm_m_E2_fake_elec/F");
  SynTree->Branch("for_mmm_pfmt_fake_electron",&for_mmm_pfmt_fake_electron,"for_mmm_pfmt_fake_electron/F");
  SynTree->Branch("for_mmm_fake_muon_iso",&for_mmm_fake_muon_iso,"for_mmm_fake_muon_iso/F");
  SynTree->Branch("for_mmm_fake_muon_id",&for_mmm_fake_muon_id,"for_mmm_fake_muon_id/O");
  SynTree->Branch("for_mmm_m_3l",&for_mmm_m_3l,"for_mmm_m_3l/F");
  SynTree->Branch("for_mmm_pfmt_fake_muon",&for_mmm_pfmt_fake_muon,"for_mmm_pfmt_fake_muon/F");
  SynTree->Branch("for_mmm_pfmt_fake_muon_JetEnUp",&for_mmm_pfmt_fake_muon_JetEnUp,"for_mmm_pfmt_fake_muon_JetEnUp/F");
  SynTree->Branch("for_mmm_pfmt_fake_muon_JetEnDown",&for_mmm_pfmt_fake_muon_JetEnDown,"for_mmm_pfmt_fake_muon_JetEnDown/F");
  SynTree->Branch("for_mmm_pfmt_fake_muon_UnclusteredEnUp",&for_mmm_pfmt_fake_muon_UnclusteredEnUp,"for_mmm_pfmt_fake_muon_UnclusteredEnUp/F");
  SynTree->Branch("for_mmm_pfmt_fake_muon_UnclusteredEnDown",&for_mmm_pfmt_fake_muon_UnclusteredEnDown,"for_mmm_pfmt_fake_muon_UnclusteredEnDown/F");
  SynTree->Branch("for_mmm_pfmt_fake_muon_JetResUp",&for_mmm_pfmt_fake_muon_JetResUp,"for_mmm_pfmt_fake_muon_JetResUp/F");
  SynTree->Branch("for_mmm_pfmt_fake_muon_JetResDown",&for_mmm_pfmt_fake_muon_JetResDown,"for_mmm_pfmt_fake_muon_JetResDown/F");
  SynTree->Branch("for_mmm_m_M1_fake_elec",&for_mmm_m_M1_fake_elec,"for_mmm_m_M1_fake_elec/F");
  SynTree->Branch("for_mmm_m_M2_fake_elec",&for_mmm_m_M2_fake_elec,"for_mmm_m_M2_fake_elec/F");
  SynTree->Branch("for_mmm_fake_ele_eta",&for_mmm_fake_ele_eta,"for_mmm_fake_ele_eta/F"); 
  SynTree->Branch("for_mmm_fake_muon_eta",&for_mmm_fake_muon_eta,"for_mmm_fake_muon_eta/F"); 
  SynTree->Branch("for_mmm_m_EE",&for_mmm_m_EE,"for_mmm_m_EE/F");
  SynTree->Branch("for_mmm_m_MM",&for_mmm_m_MM,"for_mmm_m_MM/F");
  SynTree->Branch("for_mmm_dR_Z1_fake_lepton",&for_mmm_dR_Z1_fake_lepton,"for_mmm_dR_Z1_fake_lepton/F");
  SynTree->Branch("for_mmm_dR_Z2_fake_lepton",&for_mmm_dR_Z2_fake_lepton,"for_mmm_dR_Z2_fake_lepton/F");
  SynTree->Branch("for_mmm_pt_fake_e",&for_mmm_pt_fake_e,"for_mmm_pt_fake_e/F"); 
  SynTree->Branch("for_mmm_pt_fake_m",&for_mmm_pt_fake_m,"for_mmm_pt_fake_m/F"); 
  SynTree->Branch("for_mmm_gen_match_1",&for_mmm_gen_match_1,"for_mmm_gen_match_1/I");
  SynTree->Branch("for_mmm_gen_match_2",&for_mmm_gen_match_2,"for_mmm_gen_match_2/I");
  SynTree->Branch("for_mmm_gen_match_3",&for_mmm_gen_match_3,"for_mmm_gen_match_3/I");  //3->fake lepton
  SynTree->Branch("for_mmm_electronIDSF_1",&for_mmm_electronIDSF_1,"for_mmm_electronIDSF_1/F"); 
  SynTree->Branch("for_mmm_electronIDSF_2",&for_mmm_electronIDSF_2,"for_mmm_electronIDSF_2/F"); 
  SynTree->Branch("for_mmm_electronIDSF_fake",&for_mmm_electronIDSF_fake,"for_mmm_electronIDSF_fake/F"); 
  SynTree->Branch("for_mmm_muonIDSF_1",&for_mmm_muonIDSF_1,"for_mmm_muonIDSF_1/F");  
  SynTree->Branch("for_mmm_muonIDSF_2",&for_mmm_muonIDSF_2,"for_mmm_muonIDSF_2/F");
  SynTree->Branch("for_mmm_muonIDSF_fake",&for_mmm_muonIDSF_fake,"for_mmm_muonIDSF_fake/F");  
  SynTree->Branch("for_mmm_electronTrigSF_1",&for_mmm_electronTrigSF_1,"for_mmm_electronTrigSF_1/F"); 
  SynTree->Branch("for_mmm_electronTrigSF_2",&for_mmm_electronTrigSF_2,"for_mmm_electronTrigSF_2/F"); 
  SynTree->Branch("for_mmm_muonTrigSF_1",&for_mmm_muonTrigSF_1,"for_mmm_muonTrigSF_1/F");  
  SynTree->Branch("for_mmm_muonTrigSF_2",&for_mmm_muonTrigSF_2,"for_mmm_muonTrigSF_2/F");

  // initialize pile up object
  PileUp * PUofficial = new PileUp();
  TString puHistName("pileup");
  /*
  if(era == "2017")
    {
      puHistName = sampleName + "_pileup";//for 2017 only
    }
  */
  if (applyPUreweighting)
    {
      TFile * filePUdistribution_data = new TFile(TString(cmsswBase)+"/src/"+TString(dataPUFile),"read");
      TFile * filePUdistribution_MC = new TFile (TString(cmsswBase)+"/src/"+TString(mcPUFile), "read");
      TH1D * PU_data = (TH1D *)filePUdistribution_data->Get("pileup");
      TH1D * PU_mc = (TH1D *)filePUdistribution_MC->Get(puHistName);
      PUofficial->set_h_data(PU_data);
      PUofficial->set_h_MC(PU_mc);
    }



  ScaleFactor * SF_muonIdIso = new ScaleFactor();
  SF_muonIdIso->init_ScaleFactor(TString(cmsswBase)+"/src/"+TString(MuonIdIsoFile));
  ScaleFactor * SF_muonTrig = new ScaleFactor();
  SF_muonTrig->init_ScaleFactor(TString(cmsswBase)+"/src/"+TString(MuonTriggerFile));

  ScaleFactor * SF_eleIdIso = new ScaleFactor();
  SF_eleIdIso->init_ScaleFactor(TString(cmsswBase)+"/src/"+TString(EleIdIsoFile));
  ScaleFactor * SF_eleTrig = new ScaleFactor();
  SF_eleTrig->init_ScaleFactor(TString(cmsswBase)+"/src/"+TString(EleTriggerFile));

  int nFiles = 0;
  int nEvents = 0;
  int selEvents = 0;

  int nTotalFiles = 0;
  std::string dummy;
  ofstream good_evts;
  //good_evts.open("good_evts.txt");
  // count number of files --->
  while (fileList0 >> dummy) nTotalFiles++;

  for (int iF=0; iF<nTotalFiles; ++iF) {
    //for (int iF=0; iF<1; ++iF) {
  
    std::string filen;
    fileList >> filen;

    std::cout << "file " << iF+1 << " out of " << nTotalFiles << " filename : " << filen << std::endl;
    TFile * file_ = TFile::Open(TString(filen));

    TTree * _inittree = NULL;
    _inittree = (TTree*)file_->Get(TString(initNtupleName));
    if (_inittree!=NULL) {
      Float_t genweight;
      if (!isData)
	_inittree->SetBranchAddress("genweight",&genweight);
      Long64_t numberOfEntriesInitTree = _inittree->GetEntries();
      std::cout << "      number of entries in Init Tree = " << numberOfEntriesInitTree << std::endl;
      for (Long64_t iEntry=0; iEntry<numberOfEntriesInitTree; iEntry++) {
	_inittree->GetEntry(iEntry);
	if (isData)
	  histWeightsH->Fill(0.,1.);
	else
	  histWeightsH->Fill(0.,genweight);
      }
    }      
      
    TTree * _tree = NULL;
    _tree = (TTree*)file_->Get(TString(ntupleName));
    if (_tree==NULL) continue;
    Long64_t numberOfEntries = _tree->GetEntries();
    std::cout << "      number of entries in Tree      = " << numberOfEntries << std::endl;
    AC1B analysisTree(_tree);
    

    // EVENT LOOP //
    //    for (Long64_t iEntry=0; iEntry<1000; iEntry++) { 
    for (Long64_t iEntry=0; iEntry<numberOfEntries; iEntry++) { 
    
      puweight = 1.0;
      mcweight = 1.0;
      zptweight = 1.0;
      npartons = -99;

      is_eee = false;
      is_eem = false;
      is_mme = false;
      is_mmm = false;

for_eee_fake_ele_iso = -99;
for_eee_fake_ele_id = false;
for_eee_ele_1_iso = -99;
for_eee_ele_1_id = false;
for_eee_ele_2_iso = -99;
for_eee_ele_2_id = false;
for_eee_mu_1_iso = -99; //
for_eee_mu_1_id = false; //
for_eee_mu_2_iso = -99; //
for_eee_mu_2_id = false; //
for_eee_m_E1_fake_elec = -99;
for_eee_m_E2_fake_elec = -99;
for_eee_m_EE = -99;
for_eee_pfmt_fake_electron = -99;
for_eee_pfmt_fake_electron_JetEnUp = -99;
for_eee_pfmt_fake_electron_JetEnDown = -99;
for_eee_pfmt_fake_electron_UnclusteredEnUp = -99;
for_eee_pfmt_fake_electron_UnclusteredEnDown = -99;
for_eee_pfmt_fake_electron_JetResUp = -99;
for_eee_pfmt_fake_electron_JetResDown = -99;
for_eee_fake_muon_iso = -99;
for_eee_fake_muon_id = false;
for_eee_m_3l = -99;
for_eee_pfmt_fake_muon = -99;
for_eee_m_M1_fake_elec = -99;
for_eee_m_M2_fake_elec = -99;
for_eee_m_MM = -99;
for_eee_fake_muon_eta = -99;
for_eee_fake_ele_eta = -99;
for_eee_dR_Z1_fake_lepton = -99;
for_eee_dR_Z2_fake_lepton = -99;
for_eee_pt_fake_e = -99;
for_eee_pt_fake_m = -99;
for_eee_gen_match_1 = 6;
for_eee_gen_match_2 = 6;
for_eee_gen_match_3 = 6;
for_eee_electronIDSF_1 = 1.0;
for_eee_electronIDSF_2 = 1.0;
for_eee_electronIDSF_fake = 1.0;
for_eee_muonIDSF_1 = 1.0; 
for_eee_muonIDSF_2 = 1.0;
for_eee_muonIDSF_fake = 1.0;
for_eee_electronTrigSF_1 = 1.0;
for_eee_muonTrigSF_1 = 1.0;
for_eee_electronTrigSF_2 = 1.0;
for_eee_muonTrigSF_2 = 1.0;

for_eem_fake_ele_iso = -99;
for_eem_fake_ele_id = false;
for_eem_ele_1_iso = -99;
for_eem_ele_1_id = false;
for_eem_ele_2_iso = -99;
for_eem_ele_2_id = false;
for_eem_mu_1_iso = -99; //
for_eem_mu_1_id = false; //
for_eem_mu_2_iso = -99; //
for_eem_mu_2_id = false; //
for_eem_m_E1_fake_elec = -99;
for_eem_m_E2_fake_elec = -99;
for_eem_m_EE = -99;
for_eem_pfmt_fake_electron = -99;
for_eem_fake_muon_iso = -99;
for_eem_fake_muon_id = false;
for_eem_m_3l = -99;
for_eem_pfmt_fake_muon = -99;
for_eem_pfmt_fake_muon_JetEnUp = -99;
for_eem_pfmt_fake_muon_JetEnDown = -99;
for_eem_pfmt_fake_muon_UnclusteredEnUp = -99;
for_eem_pfmt_fake_muon_UnclusteredEnDown = -99;
for_eem_pfmt_fake_muon_JetResUp = -99;
for_eem_pfmt_fake_muon_JetResDown = -99;
for_eem_m_M1_fake_elec = -99;
for_eem_m_M2_fake_elec = -99;
for_eem_m_MM = -99;
for_eem_fake_muon_eta = -99;
for_eem_fake_ele_eta = -99;
for_eem_dR_Z1_fake_lepton = -99;
for_eem_dR_Z2_fake_lepton = -99;
for_eem_pt_fake_e = -99;
for_eem_pt_fake_m = -99;
for_eem_gen_match_1 = 6;
for_eem_gen_match_2 = 6;
for_eem_gen_match_3 = 6;
for_eem_electronIDSF_1 = 1.0;
for_eem_electronIDSF_2 = 1.0;
for_eem_electronIDSF_fake = 1.0;
for_eem_muonIDSF_1 = 1.0; 
for_eem_muonIDSF_2 = 1.0;
for_eem_muonIDSF_fake = 1.0;
for_eem_electronTrigSF_1 = 1.0;
for_eem_muonTrigSF_1 = 1.0;
for_eem_electronTrigSF_2 = 1.0;
for_eem_muonTrigSF_2 = 1.0;

for_mme_fake_ele_iso = -99;
for_mme_fake_ele_id = false;
for_mme_ele_1_iso = -99;
for_mme_ele_1_id = false;
for_mme_ele_2_iso = -99;
for_mme_ele_2_id = false;
for_mme_mu_1_iso = -99; //
for_mme_mu_1_id = false; //
for_mme_mu_2_iso = -99; //
for_mme_mu_2_id = false; //
for_mme_m_E1_fake_elec = -99;
for_mme_m_E2_fake_elec = -99;
for_mme_m_EE = -99;
for_mme_pfmt_fake_electron = -99;
for_mme_pfmt_fake_electron_JetEnUp = -99;
for_mme_pfmt_fake_electron_JetEnDown = -99;
for_mme_pfmt_fake_electron_UnclusteredEnUp = -99;
for_mme_pfmt_fake_electron_UnclusteredEnDown = -99;
for_mme_pfmt_fake_electron_JetResUp = -99;
for_mme_pfmt_fake_electron_JetResDown = -99;
for_mme_fake_muon_iso = -99;
for_mme_fake_muon_id = false;
for_mme_m_3l = -99;
for_mme_pfmt_fake_muon = -99;
for_mme_m_M1_fake_elec = -99;
for_mme_m_M2_fake_elec = -99;
for_mme_m_MM = -99;
for_mme_fake_muon_eta = -99;
for_mme_fake_ele_eta = -99;
for_mme_dR_Z1_fake_lepton = -99;
for_mme_dR_Z2_fake_lepton = -99;
for_mme_pt_fake_e = -99;
for_mme_pt_fake_m = -99;
for_mme_gen_match_1 = 6;
for_mme_gen_match_2 = 6;
for_mme_gen_match_3 = 6;
for_mme_electronIDSF_1 = 1.0;
for_mme_electronIDSF_2 = 1.0;
for_mme_electronIDSF_fake = 1.0;
for_mme_muonIDSF_1 = 1.0; 
for_mme_muonIDSF_2 = 1.0;
for_mme_muonIDSF_fake = 1.0;
for_mme_electronTrigSF_1 = 1.0;
for_mme_muonTrigSF_1 = 1.0;
for_mme_electronTrigSF_2 = 1.0;
for_mme_muonTrigSF_2 = 1.0;

for_mmm_fake_ele_iso = -99;
for_mmm_fake_ele_id = false;
for_mmm_ele_1_iso = -99;
for_mmm_ele_1_id = false;
for_mmm_ele_2_iso = -99;
for_mmm_ele_2_id = false;
for_mmm_mu_1_iso = -99; //
for_mmm_mu_1_id = false; //
for_mmm_mu_2_iso = -99; //
for_mmm_mu_2_id = false; //
for_mmm_m_E1_fake_elec = -99;
for_mmm_m_E2_fake_elec = -99;
for_mmm_m_EE = -99;
for_mmm_pfmt_fake_electron = -99;
for_mmm_fake_muon_iso = -99;
for_mmm_fake_muon_id = false;
for_mmm_m_3l = -99;
for_mmm_pfmt_fake_muon = -99;
for_mmm_pfmt_fake_muon_JetEnUp = -99;
for_mmm_pfmt_fake_muon_JetEnDown = -99;
for_mmm_pfmt_fake_muon_UnclusteredEnUp = -99;
for_mmm_pfmt_fake_muon_UnclusteredEnDown = -99;
for_mmm_pfmt_fake_muon_JetResUp = -99;
for_mmm_pfmt_fake_muon_JetResDown = -99;
for_mmm_m_M1_fake_elec = -99;
for_mmm_m_M2_fake_elec = -99;
for_mmm_m_MM = -99;
for_mmm_fake_muon_eta = -99;
for_mmm_fake_ele_eta = -99;
for_mmm_dR_Z1_fake_lepton = -99;
for_mmm_dR_Z2_fake_lepton = -99;
for_mmm_pt_fake_e = -99;
for_mmm_pt_fake_m = -99;
for_mmm_gen_match_1 = 6;
for_mmm_gen_match_2 = 6;
for_mmm_gen_match_3 = 6;
for_mmm_electronIDSF_1 = 1.0;
for_mmm_electronIDSF_2 = 1.0;
for_mmm_electronIDSF_fake = 1.0;
for_mmm_muonIDSF_1 = 1.0; 
for_mmm_muonIDSF_2 = 1.0;
for_mmm_muonIDSF_fake = 1.0;
for_mmm_electronTrigSF_1 = 1.0;
for_mmm_muonTrigSF_1 = 1.0;
for_mmm_electronTrigSF_2 = 1.0;
for_mmm_muonTrigSF_2 = 1.0;

      
      analysisTree.GetEntry(iEntry);
      
      nEvents++;
      //   cout<<endl<<"NEW EVENT"<<endl;
      if (nEvents%10000==0) 
	cout << "      processed " << nEvents << " events" << endl;

      puweight = 1;
      mcweight = 1;
        
      mcweight = analysisTree.genweight;

      if (!isData)
	npartons = analysisTree.genparticles_noutgoing;



        run = analysisTree.event_run;
        lumi = analysisTree.event_luminosityblock;
        evt = analysisTree.event_nr;
        

      //pile up weight variable
      if (!isData)
        {
	  puweight = float(PUofficial->get_PUweight(double(analysisTree.numtruepileupinteractions)));
        }


        // vertex cuts
        if (fabs(analysisTree.primvertex_z)>zVertexCut) continue;
        if (analysisTree.primvertex_ndof<ndofVertexCut) continue;
        float dVertex = (analysisTree.primvertex_x*analysisTree.primvertex_x+analysisTree.primvertex_y*analysisTree.primvertex_y);
        if (dVertex>dVertexCut) continue;
        


      if (isData && applyGoodRunSelection){
          bool lumi = false;
          int n=analysisTree.event_run;
          int lum = analysisTree.event_luminosityblock;
	
          std::string num = std::to_string(n);
          std::string lnum = std::to_string(lum);
          for(const auto& a : periods)
          {
	    
              if ( num.c_str() ==  a.name ) {
                  //std::cout<< " Eureka "<<num<<"  "<<a.name<<" ";
                  //     std::cout <<"min "<< last->lower << "- max last " << last->bigger << std::endl;
	      
                  for(auto b = a.ranges.begin(); b != std::prev(a.ranges.end()); ++b) {
                      //	cout<<b->lower<<"  "<<b->bigger<<endl;
                      if (lum  >= b->lower && lum <= b->bigger ) lumi = true;
                  }
                  auto last = std::prev(a.ranges.end());
                  //    std::cout <<"min "<< last->lower << "- max last " << last->bigger << std::endl;
                  if (  (lum >=last->lower && lum <= last->bigger )) lumi=true;
              }
          }
    
          if (!lumi) continue;
          //if (lumi ) cout<<"  =============  Found good run"<<"  "<<n<<"  "<<lum<<endl;
          //std::remove("myinputfile");
      }     



      //      cout<<endl<<"mcweight="<<mcweight<<endl<<"puweight="<<puweight<<endl<<"npartons="<<npartons<<endl;
      //Trigger information
      bool isTriggerSingleElectron = false;
      bool isTriggerDoubleElectron = false;
      for (std::map<string,int>::iterator it=analysisTree.hltriggerresults->begin(); it!=analysisTree.hltriggerresults->end(); ++it)
        {
          TString trigName_1(it->first);
          if (trigName_1.Contains(ElectronTriggerName_1))
	    {
              //  std::cout << it->first << " : " << it->second << std::endl;
              if (it->second==1)
		isTriggerSingleElectron = true;
	    }
            
          TString trigName_2(it->first);
          if (trigName_2.Contains(ElectronTriggerName_2))
	    {
              //  std::cout << it->first << " : " << it->second << std::endl;
              if (it->second==1)
		isTriggerDoubleElectron = true;
	    }
        }


    
      //Trigger information
      bool isTriggerSingleMuon_1 = false; //HLT_IsoMu24_v
      bool isTriggerSingleMuon_2 = false; //HLT_IsoTkMu24_v
      bool isTriggerDoubleMuon_3 = false; //HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v
      bool isTriggerDoubleMuon_4 = false; //HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v
      for (std::map<string,int>::iterator it=analysisTree.hltriggerresults->begin(); it!=analysisTree.hltriggerresults->end(); ++it) {
	TString trigName_1(it->first);
	if (trigName_1.Contains(MuonTriggerName_1)) {
	  //  std::cout << it->first << " : " << it->second << std::endl;
	  if (it->second==1)
	    isTriggerSingleMuon_1 = true;
	}
	TString trigName_2(it->first);
	if (trigName_2.Contains(MuonTriggerName_2))
          {
	    //  std::cout << it->first << " : " << it->second << std::endl;
	    if (it->second==1)
	      isTriggerSingleMuon_2 = true;
          }
	TString trigName_3(it->first);
	if (trigName_3.Contains(MuonTriggerName_3))
          {
	    //  std::cout << it->first << " : " << it->second << std::endl;
	    if (it->second==1)
	      isTriggerDoubleMuon_3 = true;
          }
	TString trigName_4(it->first);
	if (trigName_4.Contains(MuonTriggerName_4))
          {
	    //  std::cout << it->first << " : " << it->second << std::endl;
	    if (it->second==1)
	      isTriggerDoubleMuon_4 = true;
          }
      }

      //      cout<<endl<<"applyTrigger="<<applyTrigger<<endl<<"isTriggerSingleMuon_1="<<isTriggerSingleMuon_1<<"isTriggerSingleMuon_2="<<isTriggerSingleMuon_2<<endl<<"isTriggerDoubleMuon_3="<<isTriggerDoubleMuon_3<<endl<<"isTriggerDoubleMuon_4="<<isTriggerDoubleMuon_4<<endl<<"isTriggerSingleElectron="<<isTriggerSingleElectron<<endl<<"isTriggerDoubleElectron="<<isTriggerDoubleElectron<<endl;

      if ((applyTrigger && !isTriggerSingleMuon_1 && !isTriggerSingleMuon_2) && (applyTrigger && !isTriggerSingleElectron)) continue;


      unsigned int nSingleMuon_1_Filter_a = 0;
      unsigned int nSingleMuon_1_Filter_b = 0;
      unsigned int nSingleMuon_2_Filter = 0;
      unsigned int nDoubleMuon_3_FilterLeg1 = 0;
      unsigned int nDoubleMuon_3_FilterLeg2_a = 0;
      unsigned int nDoubleMuon_3_FilterLeg2_b = 0;
      unsigned int nDoubleMuon_3_FilterDz = 0;
      unsigned int nDoubleMuon_3_FilterMass = 0;
      unsigned int nDoubleMuon_4_FilterLeg1 = 0;
      unsigned int nDoubleMuon_4_FilterLeg2 = 0;
      unsigned int nDoubleMuon_4_FilterDz = 0;
      unsigned int nfilters = analysisTree.run_hltfilters->size();
        
      for (unsigned int i=0; i<nfilters; ++i) {
	TString HLTFilter(analysisTree.run_hltfilters->at(i));
	if (HLTFilter==SingleMuonFilterName_1_a)
          {
	    nSingleMuon_1_Filter_a = i;
          }
	if (HLTFilter==SingleMuonFilterName_1_b)
          {
	    nSingleMuon_1_Filter_b = i;
          }
	if (HLTFilter==SingleMuonFilterName_2)
          {
	    nSingleMuon_2_Filter = i;
          }
	if (HLTFilter==DoubleMuonLeg1FilterName_3)
          {
	    nDoubleMuon_3_FilterLeg1 = i;
          }
	if (HLTFilter==DoubleMuonLeg2FilterName_3_a)
          {
	    nDoubleMuon_3_FilterLeg2_a = i;
          }
	if (HLTFilter==DoubleMuonLeg2FilterName_3_b)
          {
	    nDoubleMuon_3_FilterLeg2_b = i;
          }
	if (HLTFilter==DoubleMuonDzFilterName_3)
          {
	    nDoubleMuon_3_FilterDz = i;
          }
	if (HLTFilter==DoubleMuonMassFilterName_3)
          {
	    nDoubleMuon_3_FilterMass = i;
          }
	if (HLTFilter==DoubleMuonLeg1FilterName_4)
          {
	    nDoubleMuon_4_FilterLeg1 = i;
          }
	if (HLTFilter==DoubleMuonLeg2FilterName_4)
          {
	    nDoubleMuon_4_FilterLeg2 = i;
          }
	if (HLTFilter==DoubleMuonDzFilterName_4)
          {
	    nDoubleMuon_4_FilterDz = i;
          }
      }


      unsigned int nSingleElectronFilter = 0;
      unsigned int nDoubleElectronFilterLeg1 = 0;
      unsigned int nDoubleElectronFilterLeg2 = 0;
      unsigned int nDoubleElectronFilterDz = 0;
        
      for (unsigned int i=0; i<nfilters; ++i)
	{
          TString HLTFilter(analysisTree.run_hltfilters->at(i));
          if (HLTFilter==SingleElectronFilterName)
	    {
              nSingleElectronFilter = i;
	    }
          if (HLTFilter==DoubleElectronLeg1FilterName)
	    {
              nDoubleElectronFilterLeg1 = i;
	    }
          if (HLTFilter==DoubleElectronLeg2FilterName)
	    {
              nDoubleElectronFilterLeg2 = i;
	    }
          if (HLTFilter==DoubleElectronDzFilterName)
	    {
              nDoubleElectronFilterDz = i;
	    }
	}


        // electron selection
        vector<unsigned int> idisoEles; idisoEles.clear(); //identified electrons
        vector<unsigned int> loosestEles; loosestEles.clear();//store loosest electrons
        for (unsigned int ie = 0; ie<analysisTree.electron_count; ++ie) {
            if (analysisTree.electron_pt[ie]<ptEleCut) continue;
            if (fabs(analysisTree.electron_eta[ie])>=etaEleCut) continue; //the "=" is needed because scale factor tools may return error
            if (fabs(analysisTree.electron_dxy[ie])>dxyEleCut) continue;
            if (fabs(analysisTree.electron_dz[ie])>dzEleCut) continue;
            //if (!analysisTree.electron_mva_wp80_noIso_Fall17_v2[ie]) continue;
            if (!analysisTree.electron_pass_conversion[ie]) continue;
            if (analysisTree.electron_nmissinghits[ie]>=2) continue;
            loosestEles.push_back(ie);
            if (!analysisTree.electron_mva_wp90_noIso_Fall17_v2[ie]) continue;
            float absIso = analysisTree.electron_chargedHadIso[ie];
            float neutralIso = analysisTree.electron_neutralHadIso[ie] + analysisTree.electron_photonIso[ie] - 0.5*analysisTree.electron_puIso[ie];
            neutralIso = TMath::Max(float(0),neutralIso);
            absIso += neutralIso;
            if(absIso/analysisTree.electron_pt[ie]>0.15) continue;
            idisoEles.push_back(ie);
            //    cout << "pt:" << analysisTree.electron_pt[ie] << "  passed:" << elePassed << endl;
        }
        
        // muon selection
        vector<unsigned int> idisoMuons; idisoMuons.clear(); //identified muons
        vector<unsigned int> loosestMuons; loosestMuons.clear(); //store loosest muons
        for (unsigned int im = 0; im<analysisTree.muon_count; ++im) {
            if (analysisTree.muon_pt[im]<ptMuonCut) continue;
            if (fabs(analysisTree.muon_eta[im])>=etaMuonCut) continue; //the "=" is needed because scale factor tools may return error
            if (fabs(analysisTree.muon_dxy[im])>dxyMuonCut) continue;
            if (fabs(analysisTree.muon_dz[im])>dzMuonCut) continue;
            if (!(analysisTree.muon_isGlobal[im]||analysisTree.muon_isTracker[im])) continue;
            loosestMuons.push_back(im);
            if (!(analysisTree.muon_isLoose[im])) continue;
            float absIso = analysisTree.muon_r04_sumChargedHadronPt[im];
            float neutralIso = analysisTree.muon_r04_sumNeutralHadronEt[im] + analysisTree.muon_r04_sumPhotonEt[im] - 0.5*analysisTree.muon_r04_sumPUPt[im];
            neutralIso = TMath::Max(float(0),neutralIso);
            absIso += neutralIso;
            if(absIso/analysisTree.muon_pt[im]>0.15) continue;
            idisoMuons.push_back(im);
            //	cout << "pt:" << analysisTree.muon_pt[im] << "  passed:" << muPassed << endl;
        }
        
        //tau selection
        vector<unsigned int> idTaus; idTaus.clear(); //identified taus
        for(unsigned int it=0;it<analysisTree.tau_count;++it)
        {
            if (analysisTree.tau_pt[it]<ptTauCut) continue;
            if (fabs(analysisTree.tau_eta[it])>etaTauCut) continue;
            if (fabs(analysisTree.tau_leadchargedhadrcand_dz[it])>dzTauCut) continue;
            if (analysisTree.tau_decayModeFindingNewDMs[it]<=0.5) continue;
            if (analysisTree.tau_decayMode[it] == 5 || analysisTree.tau_decayMode[it] == 6) continue;
            //(no needed for Synchronization)
            //if (analysisTree.tau_byMediumDeepTau2017v2p1VSjet[it] <= 0.5) continue;
            if (analysisTree.tau_byVVVLooseDeepTau2017v2p1VSjet[it] <= 0.5) continue; //For synch excercise only
            if (analysisTree.tau_byVLooseDeepTau2017v2p1VSmu[it] <= 0.5) continue;
            if (analysisTree.tau_byVLooseDeepTau2017v2p1VSe[it] <= 0.5) continue;
            idTaus.push_back(it);
        }



        vector<unsigned int> goodEles; goodEles.clear(); //good electrons                                                                    
        vector<unsigned int> goodMuons; goodMuons.clear(); //good muons                                                                      
        vector<unsigned int> goodTaus; goodTaus.clear(); //good taus                                                                         

            goodEles=loosestEles;
            goodMuons=loosestMuons;
            goodTaus=idTaus;

        
      
	//	for eee


	    int indexMuon1 = -1;
      int indexMuon2 = -1;

       int indexElectron1 = -1;
       int indexElectron2 = -1;

       int indexFakeElectron = -1;
       int indexFakeMuon = -1;


      
      if(loosestEles.size() >= 3 && idisoEles.size() <= 3 && idisoMuons.size() <= 0 && goodTaus.size() == 0){
	//	cout<<endl<<"fake_lepton_type="<<fake_lepton_type<<endl<<"Z_decay_mode="<<Z_decay_mode<<endl;

	bool foundZOS = false;
	TLorentzVector Ele_1, Ele_2;
	for_eee_m_EE = 0;
	float m_Dist = 9999;

	for(unsigned int ie1=0; ie1<goodEles.size(); ie1++){
	  for(unsigned int ie2=ie1+1; ie2<goodEles.size(); ie2++){
	    


	    int indexTemp1 = goodEles[ie1];
	    int indexTemp2 = goodEles[ie2];
	   
	    if (indexTemp1 == indexTemp2) continue;
	    float q1 = analysisTree.electron_charge[indexTemp1];
	    float q2 = analysisTree.electron_charge[indexTemp2];

	    if (q1*q2 > 0) continue;
	    Ele_1.SetXYZM(analysisTree.electron_px[indexTemp1],analysisTree.electron_py[indexTemp1],analysisTree.electron_pz[indexTemp1],electronMass);
	    Ele_2.SetXYZM(analysisTree.electron_px[indexTemp2],analysisTree.electron_py[indexTemp2],analysisTree.electron_pz[indexTemp2],electronMass);

	    
	    if (fabs((Ele_1+Ele_2).M() - 91.1876) < m_Dist){
	      for_eee_m_EE = (Ele_1+Ele_2).M();
	      m_Dist = fabs(for_eee_m_EE - 91.1876);
	      foundZOS = true;
	      if (analysisTree.electron_pt[indexTemp1]>analysisTree.electron_pt[indexTemp2])
		{
		  indexElectron1 = indexTemp1;
		  indexElectron2 = indexTemp2;
		}
	      else
		{
		  indexElectron1 = indexTemp2;
		  indexElectron2 = indexTemp1;
		}
	    }//if (fabs((Ele_1+Ele_2).M() - 91.1876) < m_Dist){
	    //	    cout<<endl<<"indexElectron1="<<indexElectron1<<endl<<"indexElectron2="<<indexElectron2<<endl;
	  }//for(unsigned int ie2=ie1+1; ie2<idEles.size(); ie2++){
	}//for(unsigned int ie1=0; ie1<idEles.size(); ie1++){


	if(!foundZOS) continue;

	Float_t dR_Z1_Z2 = deltaR(analysisTree.electron_eta[indexElectron1],analysisTree.electron_phi[indexElectron1],analysisTree.electron_eta[indexElectron2],analysisTree.electron_phi[indexElectron2]);

	if(dR_Z1_Z2 < 0.3) continue;
      
	for(unsigned int i_fake_electron=0; i_fake_electron<goodEles.size(); i_fake_electron++){
	  int indexFakeElectron_temp = goodEles[i_fake_electron];
	  if(indexFakeElectron_temp == indexElectron1 || indexFakeElectron_temp == indexElectron2)
	    continue;
	  float dr_1 = deltaR(analysisTree.electron_eta[indexElectron1],analysisTree.electron_phi[indexElectron1],analysisTree.electron_eta[indexFakeElectron_temp],analysisTree.electron_phi[indexFakeElectron_temp]);
	  float dr_2 = deltaR(analysisTree.electron_eta[indexElectron2],analysisTree.electron_phi[indexElectron2],analysisTree.electron_eta[indexFakeElectron_temp],analysisTree.electron_phi[indexFakeElectron_temp]);
	  if(dr_1 < 0.3 || dr_2 < 0.3) continue; 
	  if(indexFakeElectron != -1){
	    if(analysisTree.electron_pt[indexFakeElectron_temp]>analysisTree.electron_pt[indexFakeElectron])
	      indexFakeElectron = indexFakeElectron_temp;
	  }
	  if(indexFakeElectron == -1) indexFakeElectron = indexFakeElectron_temp;
	
	}//for(int i_fake_electron=0; i_fake_electron<idEles.size(); i_fake_electron++){

	if(indexFakeElectron == -1) continue;
	
	is_eee = true;

	for_eee_fake_ele_iso = (analysisTree.electron_r03_sumChargedHadronPt[indexFakeElectron] + std::max(0.,analysisTree.electron_r03_sumNeutralHadronEt[indexFakeElectron] + analysisTree.electron_r03_sumPhotonEt[indexFakeElectron] - (0.5 * analysisTree.electron_r03_sumPUPt[indexFakeElectron]))) / analysisTree.electron_pt[indexFakeElectron];

	for_eee_fake_ele_id = analysisTree.electron_mva_wp90_noIso_Fall17_v2[indexFakeElectron];

	for_eee_ele_1_iso = (analysisTree.electron_r03_sumChargedHadronPt[indexElectron1] + std::max(0.,analysisTree.electron_r03_sumNeutralHadronEt[indexElectron1] + analysisTree.electron_r03_sumPhotonEt[indexElectron1] - (0.5 * analysisTree.electron_r03_sumPUPt[indexElectron1]))) / analysisTree.electron_pt[indexElectron1];

	for_eee_ele_1_id = analysisTree.electron_mva_wp90_noIso_Fall17_v2[indexElectron1];

	for_eee_ele_2_iso = (analysisTree.electron_r03_sumChargedHadronPt[indexElectron2] + std::max(0.,analysisTree.electron_r03_sumNeutralHadronEt[indexElectron2] + analysisTree.electron_r03_sumPhotonEt[indexElectron2] - (0.5 * analysisTree.electron_r03_sumPUPt[indexElectron2]))) / analysisTree.electron_pt[indexElectron2];

	for_eee_ele_2_id = analysisTree.electron_mva_wp90_noIso_Fall17_v2[indexElectron2];

	Ele_1.SetXYZM(analysisTree.electron_px[indexElectron1],analysisTree.electron_py[indexElectron1],analysisTree.electron_pz[indexElectron1],electronMass);

	Ele_2.SetXYZM(analysisTree.electron_px[indexElectron2],analysisTree.electron_py[indexElectron2],analysisTree.electron_pz[indexElectron2],electronMass);

	TLorentzVector fake_electron;
	fake_electron.SetXYZM(analysisTree.electron_px[indexFakeElectron],analysisTree.electron_py[indexFakeElectron],analysisTree.electron_pz[indexFakeElectron],electronMass);
	for_eee_m_E1_fake_elec = (Ele_1 + fake_electron).M();
	for_eee_m_E2_fake_elec = (Ele_2 + fake_electron).M();
	float met = TMath::Sqrt(analysisTree.pfmetcorr_ex*analysisTree.pfmetcorr_ex + analysisTree.pfmetcorr_ey*analysisTree.pfmetcorr_ey);
	float metphi = analysisTree.pfmetcorr_phi;
	TLorentzVector metLV(met*TMath::Cos(metphi),met*TMath::Sin(metphi),0,TMath::Sqrt(met*TMath::Sin(metphi)*met*TMath::Sin(metphi) + met*TMath::Cos(metphi)*met*TMath::Cos(metphi)));
	TLorentzVector metLV_JetEnUp(analysisTree.pfmetcorr_ex_JetEnUp,analysisTree.pfmetcorr_ey_JetEnUp,0,TMath::Sqrt(analysisTree.pfmetcorr_ex_JetEnUp*analysisTree.pfmetcorr_ex_JetEnUp+analysisTree.pfmetcorr_ey_JetEnUp*analysisTree.pfmetcorr_ey_JetEnUp));
	TLorentzVector metLV_JetEnDown(analysisTree.pfmetcorr_ex_JetEnDown,analysisTree.pfmetcorr_ey_JetEnDown,0,TMath::Sqrt(analysisTree.pfmetcorr_ex_JetEnDown*analysisTree.pfmetcorr_ex_JetEnDown+analysisTree.pfmetcorr_ey_JetEnDown*analysisTree.pfmetcorr_ey_JetEnDown));
	TLorentzVector metLV_UnclusteredEnUp(analysisTree.pfmetcorr_ex_UnclusteredEnUp,analysisTree.pfmetcorr_ey_UnclusteredEnUp,0,TMath::Sqrt(analysisTree.pfmetcorr_ex_UnclusteredEnUp*analysisTree.pfmetcorr_ex_UnclusteredEnUp+analysisTree.pfmetcorr_ey_UnclusteredEnUp*analysisTree.pfmetcorr_ey_UnclusteredEnUp));
	TLorentzVector metLV_UnclusteredEnDown(analysisTree.pfmetcorr_ex_UnclusteredEnDown,analysisTree.pfmetcorr_ey_UnclusteredEnDown,0,TMath::Sqrt(analysisTree.pfmetcorr_ex_UnclusteredEnDown*analysisTree.pfmetcorr_ex_UnclusteredEnDown+analysisTree.pfmetcorr_ey_UnclusteredEnDown*analysisTree.pfmetcorr_ey_UnclusteredEnDown));
	TLorentzVector metLV_JetResUp(analysisTree.pfmetcorr_ex_JetResUp,analysisTree.pfmetcorr_ey_JetResUp,0,TMath::Sqrt(analysisTree.pfmetcorr_ex_JetResUp*analysisTree.pfmetcorr_ex_JetResUp+analysisTree.pfmetcorr_ey_JetResUp*analysisTree.pfmetcorr_ey_JetResUp));
	TLorentzVector metLV_JetResDown(analysisTree.pfmetcorr_ex_JetResDown,analysisTree.pfmetcorr_ey_JetResDown,0,TMath::Sqrt(analysisTree.pfmetcorr_ex_JetResDown*analysisTree.pfmetcorr_ex_JetResDown+analysisTree.pfmetcorr_ey_JetResDown*analysisTree.pfmetcorr_ey_JetResDown));

	for_eee_pfmt_fake_electron = mT(fake_electron,metLV);
	for_eee_pfmt_fake_electron_JetEnUp = mT(fake_electron,metLV_JetEnUp);
	for_eee_pfmt_fake_electron_JetEnDown = mT(fake_electron,metLV_JetEnDown);
	for_eee_pfmt_fake_electron_UnclusteredEnUp = mT(fake_electron,metLV_UnclusteredEnUp);
	for_eee_pfmt_fake_electron_UnclusteredEnDown = mT(fake_electron,metLV_UnclusteredEnDown);
	for_eee_pfmt_fake_electron_JetResUp = mT(fake_electron,metLV_JetResUp);
	for_eee_pfmt_fake_electron_JetResDown = mT(fake_electron,metLV_JetResDown);

	for_eee_fake_ele_eta = analysisTree.electron_eta[indexFakeElectron];
	for_eee_dR_Z1_fake_lepton = deltaR(analysisTree.electron_eta[indexElectron1],analysisTree.electron_phi[indexElectron1],analysisTree.electron_eta[indexFakeElectron],analysisTree.electron_phi[indexFakeElectron]);
	for_eee_dR_Z2_fake_lepton = deltaR(analysisTree.electron_eta[indexElectron2],analysisTree.electron_phi[indexElectron2],analysisTree.electron_eta[indexFakeElectron],analysisTree.electron_phi[indexFakeElectron]);
	for_eee_pt_fake_e = analysisTree.electron_pt[indexFakeElectron];

        if(!isData)
	  {
            for_eee_electronIDSF_1 = (float)SF_eleIdIso->get_ScaleFactor(double(analysisTree.electron_pt[indexElectron1]),double(analysisTree.electron_eta[indexElectron1]));
            for_eee_electronIDSF_2 = (float)SF_eleIdIso->get_ScaleFactor(double(analysisTree.electron_pt[indexElectron2]),double(analysisTree.electron_eta[indexElectron2]));
            for_eee_electronIDSF_fake = (float)SF_eleIdIso->get_ScaleFactor(double(analysisTree.electron_pt[indexFakeElectron]),double(analysisTree.electron_eta[indexFakeElectron]));
	  }


      float minDR_1 = 0.2;
      float minDR_2 = 0.2;
      float minDR_3 = 0.2;

      if (!isData)
        {
	  for (unsigned int igen=0; igen < analysisTree.genparticles_count; ++igen)
	    {
	      //  cout<<endl<<"igen="<<igen<<endl;
	      float ptGen = PtoPt(analysisTree.genparticles_px[igen], analysisTree.genparticles_py[igen]);
	      bool type1 = abs(analysisTree.genparticles_pdgid[igen])==11 && analysisTree.genparticles_isPrompt[igen] && ptGen>8;
	      bool type2 = abs(analysisTree.genparticles_pdgid[igen])==13 && analysisTree.genparticles_isPrompt[igen] && ptGen>8;
	      bool type3 = abs(analysisTree.genparticles_pdgid[igen])==11 && analysisTree.genparticles_isDirectPromptTauDecayProduct[igen] && ptGen>8;
	      bool type4 = abs(analysisTree.genparticles_pdgid[igen])==13 && analysisTree.genparticles_isDirectPromptTauDecayProduct[igen] && ptGen>8;
	      bool isAnyType = type1 || type2 || type3 || type4;

	      if (isAnyType)
                {
		  float etaGen = PtoEta(analysisTree.genparticles_px[igen],analysisTree.genparticles_py[igen], analysisTree.genparticles_pz[igen]);
		  float phiGen = PtoPhi(analysisTree.genparticles_px[igen],analysisTree.genparticles_py[igen]);

		  float deltaR_1, deltaR_2, deltaR_3;

		
		    deltaR_1 = deltaR(analysisTree.electron_eta[indexElectron1],analysisTree.electron_phi[indexElectron1],etaGen,phiGen);
		    deltaR_2 = deltaR(analysisTree.electron_eta[indexElectron2],analysisTree.electron_phi[indexElectron2],etaGen,phiGen);
		    deltaR_3 = deltaR(analysisTree.electron_eta[indexFakeElectron],analysisTree.electron_phi[indexFakeElectron],etaGen,phiGen);

		  if (deltaR_1<minDR_1)
                    {
		      minDR_1 = deltaR_1;
		      if (type1) for_eee_gen_match_1 = 1;
		      else if (type2) for_eee_gen_match_1 = 2;
		      else if (type3) for_eee_gen_match_1 = 3;
		      else if (type4) for_eee_gen_match_1 = 4;
                    }

		  if (deltaR_2<minDR_2)
                    {
		      minDR_2 = deltaR_2;
		      if (type1) for_eee_gen_match_2 = 1;
		      else if (type2) for_eee_gen_match_2 = 2;
		      else if (type3) for_eee_gen_match_2 = 3;
		      else if (type4) for_eee_gen_match_2 = 4;
                    }

		  if (deltaR_3<minDR_3)
                    {
		      minDR_3 = deltaR_3;
		      if (type1) for_eee_gen_match_3 = 1;
		      else if (type2) for_eee_gen_match_3 = 2;
		      else if (type3) for_eee_gen_match_3 = 3;
		      else if (type4) for_eee_gen_match_3 = 4;
                    }
                }
            }

	  for (unsigned int igen=0; igen < analysisTree.gentau_count; ++igen)
            {

	      if (analysisTree.gentau_visibleNoLep_pt[igen]>15.)
                {

		  float deltaR_1, deltaR_2, deltaR_3;

                    deltaR_1 = deltaR(analysisTree.electron_eta[indexElectron1],analysisTree.electron_phi[indexElectron1],analysisTree.gentau_visibleNoLep_eta[igen],analysisTree.gentau_visibleNoLep_phi[igen]);
		    deltaR_2 = deltaR(analysisTree.electron_eta[indexElectron2],analysisTree.electron_phi[indexElectron2],analysisTree.gentau_visibleNoLep_eta[igen],analysisTree.gentau_visibleNoLep_phi[igen]);
		    deltaR_3 = deltaR(analysisTree.electron_eta[indexFakeElectron],analysisTree.electron_phi[indexFakeElectron],analysisTree.gentau_visibleNoLep_eta[igen],analysisTree.gentau_visibleNoLep_phi[igen]);


		  if (deltaR_1<minDR_1)
                    {
		      minDR_1 = deltaR_1;
		      for_eee_gen_match_1 = 5;
                    }

		  if (deltaR_2<minDR_2)
                    {
		      minDR_2 = deltaR_2;
		      for_eee_gen_match_2 = 5;
                    }

		  if (deltaR_3<minDR_3)
                    {
		      minDR_3 = deltaR_3;
		      for_eee_gen_match_3 = 5;
                    }

                }
            }
        }



      //Trigger matching
      bool isSingleElectronTriggerFilterMatched = false;
      bool isDoubleElectronTriggerFilterMatched = false;
        
      bool isElectron1SingleElectronMatched = false;
      bool isElectron2SingleElectronMatched = false;
      bool isElectron12DoubleElectronLeg1Leg2Matched = false;
      bool isElectron12DoubleElectronLeg2Leg1Matched = false;
        
      bool isElectron1DoubleElectronLeg1Matched = false;
      bool isElectron1DoubleElectronLeg2Matched = false;
      bool isElectron2DoubleElectronLeg1Matched = false;
      bool isElectron2DoubleElectronLeg2Matched = false;
      bool isElectron1DoubleElectrondzMatched = false;
      bool isElectron2DoubleElectrondzMatched = false;

      if(applyTrigger)
        {
	  for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
	      float dRtrig = deltaR(analysisTree.electron_eta[indexElectron1],analysisTree.electron_phi[indexElectron1],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
	      if (dRtrig>DRTrigMatch) continue;
	      if (analysisTree.trigobject_filters[iT][nSingleElectronFilter] && analysisTree.electron_pt[indexElectron1] > singleElectronTriggerPtCut && fabs(analysisTree.electron_eta[indexElectron1]) < singleElectronTriggerEtaCut){
		isElectron1SingleElectronMatched = true;

	      }
            }
	  for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
	      float dRtrig = deltaR(analysisTree.electron_eta[indexElectron2],analysisTree.electron_phi[indexElectron2],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
	      if (dRtrig>DRTrigMatch) continue;
	      if (analysisTree.trigobject_filters[iT][nSingleElectronFilter] && analysisTree.electron_pt[indexElectron2] > singleElectronTriggerPtCut && fabs(analysisTree.electron_eta[indexElectron2]) < singleElectronTriggerEtaCut){
		isElectron2SingleElectronMatched = true;

	      }
            }
	  for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
	      float dRtrig = deltaR(analysisTree.electron_eta[indexElectron1],analysisTree.electron_phi[indexElectron1],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
	      if (dRtrig>DRTrigMatch) continue;
	      if (analysisTree.trigobject_filters[iT][nDoubleElectronFilterLeg1] && analysisTree.electron_pt[indexElectron1] > doubleElectronLeg1TriggerPtCut)
		isElectron1DoubleElectronLeg1Matched = true;
            }
	  for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
	      float dRtrig = deltaR(analysisTree.electron_eta[indexElectron1],analysisTree.electron_phi[indexElectron1],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
	      if (dRtrig>DRTrigMatch) continue;
	      if (analysisTree.trigobject_filters[iT][nDoubleElectronFilterLeg2] && analysisTree.electron_pt[indexElectron1] > doubleElectronLeg2TriggerPtCut)
		isElectron1DoubleElectronLeg2Matched = true;
            }
	  for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
	      float dRtrig = deltaR(analysisTree.electron_eta[indexElectron2],analysisTree.electron_phi[indexElectron2],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
	      if (dRtrig>DRTrigMatch) continue;
	      if (analysisTree.trigobject_filters[iT][nDoubleElectronFilterLeg1] && analysisTree.electron_pt[indexElectron2] > doubleElectronLeg1TriggerPtCut)
		isElectron2DoubleElectronLeg1Matched = true;
            }
	  for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
	      float dRtrig = deltaR(analysisTree.electron_eta[indexElectron2],analysisTree.electron_phi[indexElectron2],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
	      if (dRtrig>DRTrigMatch) continue;
	      if (analysisTree.trigobject_filters[iT][nDoubleElectronFilterLeg2] && analysisTree.electron_pt[indexElectron2] > doubleElectronLeg2TriggerPtCut)
		isElectron2DoubleElectronLeg2Matched = true;
            }
	  for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
	      float dRtrig = deltaR(analysisTree.electron_eta[indexElectron1],analysisTree.electron_phi[indexElectron1],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
	      if (dRtrig>DRTrigMatch) continue;
	      if (analysisTree.trigobject_filters[iT][nDoubleElectronFilterDz])
		isElectron1DoubleElectrondzMatched = true;
            }
	  for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
	      float dRtrig = deltaR(analysisTree.electron_eta[indexElectron2],analysisTree.electron_phi[indexElectron2],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
	      if (dRtrig>DRTrigMatch) continue;
	      if (analysisTree.trigobject_filters[iT][nDoubleElectronFilterDz])
		isElectron2DoubleElectrondzMatched = true;
            }
            
	  if(isElectron1DoubleElectronLeg1Matched && isElectron2DoubleElectronLeg2Matched)
	    isElectron12DoubleElectronLeg1Leg2Matched = true;
	  if(isElectron1DoubleElectronLeg2Matched && isElectron2DoubleElectronLeg1Matched)
	    isElectron12DoubleElectronLeg2Leg1Matched = true;
	  if((isElectron12DoubleElectronLeg1Leg2Matched || isElectron12DoubleElectronLeg2Leg1Matched) && isElectron1DoubleElectrondzMatched && isElectron2DoubleElectrondzMatched)
	    isDoubleElectronTriggerFilterMatched = true;
            
	  if(isElectron1SingleElectronMatched || isElectron2SingleElectronMatched)
	    isSingleElectronTriggerFilterMatched = true;	    
	  
	  //  cout<<endl<<"checking elec filter"<<endl;
	  if(applySingleEleTriggerOnly == false)//this setting is for switching on and off single electron trigger
            {
	      if ((isSingleElectronTriggerFilterMatched == false) && (isDoubleElectronTriggerFilterMatched == false))
		continue;
            }
	  else
            {
	      if (isSingleElectronTriggerFilterMatched == false)
		continue;
            }
	  //cout<<endl<<"passed elec filter"<<endl;
	  
	  for_eee_electronTrigSF_1 = 1.0;
	  for_eee_electronTrigSF_2 = 1.0;

	  if(!isData){
	    if(isSingleElectronTriggerFilterMatched && isElectron1SingleElectronMatched)
	      for_eee_electronTrigSF_1 = (float)SF_eleTrig->get_ScaleFactor(double(analysisTree.electron_pt[indexElectron1]),double(analysisTree.electron_eta[indexElectron1]));

	    if(isSingleElectronTriggerFilterMatched && isElectron2SingleElectronMatched)
	      for_eee_electronTrigSF_2 = (float)SF_eleTrig->get_ScaleFactor(double(analysisTree.electron_pt[indexElectron2]),double(analysisTree.electron_eta[indexElectron2]));
	  }
        }
      }// if(loosestEles.size() >= 3 && idisoEles.size() <= 3 && idisoMuons.size() <= 0 && goodTaus.size() == 0){



      // for eem

       indexMuon1 = -1;
       indexMuon2 = -1;

       indexElectron1 = -1;
       indexElectron2 = -1;

       indexFakeElectron = -1;
       indexFakeMuon = -1;



      if(loosestEles.size() >= 2 && loosestMuons.size() >= 1 && idisoEles.size() <= 2 && idisoMuons.size() <= 1 && goodTaus.size() == 0){
	bool foundZOS = false;
	TLorentzVector Ele_1, Ele_2;
	for_eem_m_EE = 0;
	float m_Dist = 9999;

	for(unsigned int ie1=0; ie1<goodEles.size(); ie1++){
	  for(unsigned int ie2=ie1+1; ie2<goodEles.size(); ie2++){
	    


	    int indexTemp1 = goodEles[ie1];
	    int indexTemp2 = goodEles[ie2];
	    if (indexTemp1 == indexTemp2) continue;
	    float q1 = analysisTree.electron_charge[indexTemp1];
	    float q2 = analysisTree.electron_charge[indexTemp2];

	    if (q1*q2 > 0) continue;
	    Ele_1.SetXYZM(analysisTree.electron_px[indexTemp1],analysisTree.electron_py[indexTemp1],analysisTree.electron_pz[indexTemp1],electronMass);
	    Ele_2.SetXYZM(analysisTree.electron_px[indexTemp2],analysisTree.electron_py[indexTemp2],analysisTree.electron_pz[indexTemp2],electronMass);

	    if (fabs((Ele_1+Ele_2).M() - 91.1876) < m_Dist){
	      for_eem_m_EE = (Ele_1+Ele_2).M();
	      m_Dist = fabs(for_eem_m_EE - 91.1876);
	      foundZOS = true;
	      if (analysisTree.electron_pt[indexTemp1]>analysisTree.electron_pt[indexTemp2])
		{
		  indexElectron1 = indexTemp1;
		  indexElectron2 = indexTemp2;
		}
	      else
		{
		  indexElectron1 = indexTemp2;
		  indexElectron2 = indexTemp1;
		}
	    }//if (fabs((Ele_1+Ele_2).M() - 91.1876) < m_Dist){
	    //	    cout<<endl<<"indexElectron1="<<indexElectron1<<endl<<"indexElectron2="<<indexElectron2<<endl;
	  }//for(unsigned int ie2=ie1+1; ie2<idEles.size(); ie2++){
	}//for(unsigned int ie1=0; ie1<idEles.size(); ie1++){

	//	cout<<endl<<"foundZOS="<<foundZOS<<endl;

	if(!foundZOS) continue;

	Float_t dR_Z1_Z2 = deltaR(analysisTree.electron_eta[indexElectron1],analysisTree.electron_phi[indexElectron1],analysisTree.electron_eta[indexElectron2],analysisTree.electron_phi[indexElectron2]);

	if(dR_Z1_Z2 < 0.3) continue;
      
	for(unsigned int i_fake_muon=0; i_fake_muon<goodMuons.size(); i_fake_muon++){
	  unsigned int indexFakeMuon_temp = goodMuons[i_fake_muon];

	  float dr_1 = deltaR(analysisTree.electron_eta[indexElectron1],analysisTree.electron_phi[indexElectron1],analysisTree.muon_eta[indexFakeMuon_temp],analysisTree.muon_phi[indexFakeMuon_temp]);
	  float dr_2 = deltaR(analysisTree.electron_eta[indexElectron2],analysisTree.electron_phi[indexElectron2],analysisTree.muon_eta[indexFakeMuon_temp],analysisTree.muon_phi[indexFakeMuon_temp]);

	  if(dr_1 < 0.3 || dr_2 < 0.3) continue;

	    if(indexFakeMuon != -1){
	      if(analysisTree.muon_pt[indexFakeMuon_temp]>analysisTree.muon_pt[indexFakeMuon])
		indexFakeMuon = indexFakeMuon_temp;
	    }
	    if(indexFakeMuon == -1) indexFakeMuon = indexFakeMuon_temp;

	}//for(int i_fake_electron=0; i_fake_electron<idEles.size(); i_fake_electron++){

	if(indexFakeMuon == -1) continue;
	
	is_eem = true;

	for_eem_fake_muon_iso = (analysisTree.muon_r04_sumChargedHadronPt[indexFakeMuon] + std::max(0.,analysisTree.muon_r04_sumNeutralHadronEt[indexFakeMuon] + analysisTree.muon_r04_sumPhotonEt[indexFakeMuon] - 0.5*analysisTree.muon_r04_sumPUPt[indexFakeMuon]))/ analysisTree.muon_pt[indexFakeMuon];

	for_eem_fake_muon_id = analysisTree.muon_isLoose[indexFakeMuon];

	for_eem_ele_1_iso = (analysisTree.electron_r03_sumChargedHadronPt[indexElectron1] + std::max(0.,analysisTree.electron_r03_sumNeutralHadronEt[indexElectron1] + analysisTree.electron_r03_sumPhotonEt[indexElectron1] - (0.5 * analysisTree.electron_r03_sumPUPt[indexElectron1]))) / analysisTree.electron_pt[indexElectron1];

	for_eem_ele_1_id = analysisTree.electron_mva_wp90_noIso_Fall17_v2[indexElectron1];

	for_eem_ele_2_iso = (analysisTree.electron_r03_sumChargedHadronPt[indexElectron2] + std::max(0.,analysisTree.electron_r03_sumNeutralHadronEt[indexElectron2] + analysisTree.electron_r03_sumPhotonEt[indexElectron2] - (0.5 * analysisTree.electron_r03_sumPUPt[indexElectron2]))) / analysisTree.electron_pt[indexElectron2];

	for_eem_ele_2_id = analysisTree.electron_mva_wp90_noIso_Fall17_v2[indexElectron2];


	Ele_1.SetXYZM(analysisTree.electron_px[indexElectron1],analysisTree.electron_py[indexElectron1],analysisTree.electron_pz[indexElectron1],electronMass);
	Ele_2.SetXYZM(analysisTree.electron_px[indexElectron2],analysisTree.electron_py[indexElectron2],analysisTree.electron_pz[indexElectron2],electronMass);

	TLorentzVector fake_muon;
	fake_muon.SetXYZM(analysisTree.muon_px[indexFakeMuon],analysisTree.muon_py[indexFakeMuon],analysisTree.muon_pz[indexFakeMuon],muonMass);
	for_eem_m_3l = (Ele_1 + Ele_2 + fake_muon).M();

	float met = TMath::Sqrt(analysisTree.pfmetcorr_ex*analysisTree.pfmetcorr_ex + analysisTree.pfmetcorr_ey*analysisTree.pfmetcorr_ey);
	float metphi = analysisTree.pfmetcorr_phi;

	TLorentzVector metLV(met*TMath::Cos(metphi),met*TMath::Sin(metphi),0,TMath::Sqrt(met*TMath::Sin(metphi)*met*TMath::Sin(metphi) + met*TMath::Cos(metphi)*met*TMath::Cos(metphi)));
	TLorentzVector metLV_JetEnUp(analysisTree.pfmetcorr_ex_JetEnUp,analysisTree.pfmetcorr_ey_JetEnUp,0,TMath::Sqrt(analysisTree.pfmetcorr_ex_JetEnUp*analysisTree.pfmetcorr_ex_JetEnUp+analysisTree.pfmetcorr_ey_JetEnUp*analysisTree.pfmetcorr_ey_JetEnUp));
	TLorentzVector metLV_JetEnDown(analysisTree.pfmetcorr_ex_JetEnDown,analysisTree.pfmetcorr_ey_JetEnDown,0,TMath::Sqrt(analysisTree.pfmetcorr_ex_JetEnDown*analysisTree.pfmetcorr_ex_JetEnDown+analysisTree.pfmetcorr_ey_JetEnDown*analysisTree.pfmetcorr_ey_JetEnDown));
	TLorentzVector metLV_UnclusteredEnUp(analysisTree.pfmetcorr_ex_UnclusteredEnUp,analysisTree.pfmetcorr_ey_UnclusteredEnUp,0,TMath::Sqrt(analysisTree.pfmetcorr_ex_UnclusteredEnUp*analysisTree.pfmetcorr_ex_UnclusteredEnUp+analysisTree.pfmetcorr_ey_UnclusteredEnUp*analysisTree.pfmetcorr_ey_UnclusteredEnUp));
	TLorentzVector metLV_UnclusteredEnDown(analysisTree.pfmetcorr_ex_UnclusteredEnDown,analysisTree.pfmetcorr_ey_UnclusteredEnDown,0,TMath::Sqrt(analysisTree.pfmetcorr_ex_UnclusteredEnDown*analysisTree.pfmetcorr_ex_UnclusteredEnDown+analysisTree.pfmetcorr_ey_UnclusteredEnDown*analysisTree.pfmetcorr_ey_UnclusteredEnDown));
	TLorentzVector metLV_JetResUp(analysisTree.pfmetcorr_ex_JetResUp,analysisTree.pfmetcorr_ey_JetResUp,0,TMath::Sqrt(analysisTree.pfmetcorr_ex_JetResUp*analysisTree.pfmetcorr_ex_JetResUp+analysisTree.pfmetcorr_ey_JetResUp*analysisTree.pfmetcorr_ey_JetResUp));
	TLorentzVector metLV_JetResDown(analysisTree.pfmetcorr_ex_JetResDown,analysisTree.pfmetcorr_ey_JetResDown,0,TMath::Sqrt(analysisTree.pfmetcorr_ex_JetResDown*analysisTree.pfmetcorr_ex_JetResDown+analysisTree.pfmetcorr_ey_JetResDown*analysisTree.pfmetcorr_ey_JetResDown));

	for_eem_pfmt_fake_muon = mT(fake_muon,metLV);
	for_eem_pfmt_fake_muon = mT(fake_muon,metLV_JetEnUp);
	for_eem_pfmt_fake_muon = mT(fake_muon,metLV_JetEnDown);
	for_eem_pfmt_fake_muon = mT(fake_muon,metLV_UnclusteredEnUp);
	for_eem_pfmt_fake_muon = mT(fake_muon,metLV_UnclusteredEnDown);
	for_eem_pfmt_fake_muon = mT(fake_muon,metLV_JetResUp);
	for_eem_pfmt_fake_muon = mT(fake_muon,metLV_JetResDown);






	for_eem_fake_muon_eta = analysisTree.muon_eta[indexFakeMuon];

	for_eem_dR_Z1_fake_lepton = deltaR(analysisTree.electron_eta[indexElectron1],analysisTree.electron_phi[indexElectron1],analysisTree.muon_eta[indexFakeMuon],analysisTree.muon_phi[indexFakeMuon]);

	for_eem_dR_Z2_fake_lepton = deltaR(analysisTree.electron_eta[indexElectron2],analysisTree.electron_phi[indexElectron2],analysisTree.muon_eta[indexFakeMuon],analysisTree.muon_phi[indexFakeMuon]);

	for_eem_pt_fake_m = analysisTree.muon_pt[indexFakeMuon];


        if(!isData)
	  {
            for_eem_electronIDSF_1 = (float)SF_eleIdIso->get_ScaleFactor(double(analysisTree.electron_pt[indexElectron1]),double(analysisTree.electron_eta[indexElectron1]));
            for_eem_electronIDSF_2 = (float)SF_eleIdIso->get_ScaleFactor(double(analysisTree.electron_pt[indexElectron2]),double(analysisTree.electron_eta[indexElectron2]));
            for_eem_muonIDSF_fake = (float)SF_muonIdIso->get_ScaleFactor(double(analysisTree.muon_pt[indexFakeMuon]),double(analysisTree.muon_eta[indexFakeMuon]));
	  }



      float minDR_1 = 0.2;
      float minDR_2 = 0.2;
      float minDR_3 = 0.2;

      if (!isData)
        {
	  for (unsigned int igen=0; igen < analysisTree.genparticles_count; ++igen)
	    {
	      //  cout<<endl<<"igen="<<igen<<endl;
	      float ptGen = PtoPt(analysisTree.genparticles_px[igen], analysisTree.genparticles_py[igen]);
	      bool type1 = abs(analysisTree.genparticles_pdgid[igen])==11 && analysisTree.genparticles_isPrompt[igen] && ptGen>8;
	      bool type2 = abs(analysisTree.genparticles_pdgid[igen])==13 && analysisTree.genparticles_isPrompt[igen] && ptGen>8;
	      bool type3 = abs(analysisTree.genparticles_pdgid[igen])==11 && analysisTree.genparticles_isDirectPromptTauDecayProduct[igen] && ptGen>8;
	      bool type4 = abs(analysisTree.genparticles_pdgid[igen])==13 && analysisTree.genparticles_isDirectPromptTauDecayProduct[igen] && ptGen>8;
	      bool isAnyType = type1 || type2 || type3 || type4;

	      if (isAnyType)
                {
		  float etaGen = PtoEta(analysisTree.genparticles_px[igen],analysisTree.genparticles_py[igen], analysisTree.genparticles_pz[igen]);
		  float phiGen = PtoPhi(analysisTree.genparticles_px[igen],analysisTree.genparticles_py[igen]);

		  float deltaR_1, deltaR_2, deltaR_3;

		    deltaR_1 = deltaR(analysisTree.electron_eta[indexElectron1],analysisTree.electron_phi[indexElectron1],etaGen,phiGen);
		    deltaR_2 = deltaR(analysisTree.electron_eta[indexElectron2],analysisTree.electron_phi[indexElectron2],etaGen,phiGen);
		    deltaR_3 = deltaR(analysisTree.muon_eta[indexFakeMuon],analysisTree.muon_phi[indexFakeMuon],etaGen,phiGen);

		  if (deltaR_1<minDR_1)
                    {
		      minDR_1 = deltaR_1;
		      if (type1) for_eem_gen_match_1 = 1;
		      else if (type2) for_eem_gen_match_1 = 2;
		      else if (type3) for_eem_gen_match_1 = 3;
		      else if (type4) for_eem_gen_match_1 = 4;
                    }

		  if (deltaR_2<minDR_2)
                    {
		      minDR_2 = deltaR_2;
		      if (type1) for_eem_gen_match_2 = 1;
		      else if (type2) for_eem_gen_match_2 = 2;
		      else if (type3) for_eem_gen_match_2 = 3;
		      else if (type4) for_eem_gen_match_2 = 4;
                    }

		  if (deltaR_3<minDR_3)
                    {
		      minDR_3 = deltaR_3;
		      if (type1) for_eem_gen_match_3 = 1;
		      else if (type2) for_eem_gen_match_3 = 2;
		      else if (type3) for_eem_gen_match_3 = 3;
		      else if (type4) for_eem_gen_match_3 = 4;
                    }
                }
            }

	  for (unsigned int igen=0; igen < analysisTree.gentau_count; ++igen)
            {

	      if (analysisTree.gentau_visibleNoLep_pt[igen]>15.)
                {

		  float deltaR_1, deltaR_2, deltaR_3;

		    deltaR_1 = deltaR(analysisTree.electron_eta[indexElectron1],analysisTree.electron_phi[indexElectron1],analysisTree.gentau_visibleNoLep_eta[igen],analysisTree.gentau_visibleNoLep_phi[igen]);
		    deltaR_2 = deltaR(analysisTree.electron_eta[indexElectron2],analysisTree.electron_phi[indexElectron2],analysisTree.gentau_visibleNoLep_eta[igen],analysisTree.gentau_visibleNoLep_phi[igen]);
		    deltaR_3 = deltaR(analysisTree.muon_eta[indexFakeMuon],analysisTree.muon_phi[indexFakeMuon],analysisTree.gentau_visibleNoLep_eta[igen],analysisTree.gentau_visibleNoLep_phi[igen]);

		  if (deltaR_1<minDR_1)
                    {
		      minDR_1 = deltaR_1;
		      for_eem_gen_match_1 = 5;
                    }

		  if (deltaR_2<minDR_2)
                    {
		      minDR_2 = deltaR_2;
		      for_eem_gen_match_2 = 5;
                    }

		  if (deltaR_3<minDR_3)
                    {
		      minDR_3 = deltaR_3;
		      for_eem_gen_match_3 = 5;
                    }

                }
            }
        }


      //Trigger matching
      bool isSingleElectronTriggerFilterMatched = false;
      bool isDoubleElectronTriggerFilterMatched = false;
        
      bool isElectron1SingleElectronMatched = false;
      bool isElectron2SingleElectronMatched = false;
      bool isElectron12DoubleElectronLeg1Leg2Matched = false;
      bool isElectron12DoubleElectronLeg2Leg1Matched = false;
        
      bool isElectron1DoubleElectronLeg1Matched = false;
      bool isElectron1DoubleElectronLeg2Matched = false;
      bool isElectron2DoubleElectronLeg1Matched = false;
      bool isElectron2DoubleElectronLeg2Matched = false;
      bool isElectron1DoubleElectrondzMatched = false;
      bool isElectron2DoubleElectrondzMatched = false;

      if(applyTrigger)
        {
	  for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
	      float dRtrig = deltaR(analysisTree.electron_eta[indexElectron1],analysisTree.electron_phi[indexElectron1],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
	      if (dRtrig>DRTrigMatch) continue;
	      if (analysisTree.trigobject_filters[iT][nSingleElectronFilter] && analysisTree.electron_pt[indexElectron1] > singleElectronTriggerPtCut && fabs(analysisTree.electron_eta[indexElectron1]) < singleElectronTriggerEtaCut){
		isElectron1SingleElectronMatched = true;

	      }
            }
	  for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
	      float dRtrig = deltaR(analysisTree.electron_eta[indexElectron2],analysisTree.electron_phi[indexElectron2],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
	      if (dRtrig>DRTrigMatch) continue;
	      if (analysisTree.trigobject_filters[iT][nSingleElectronFilter] && analysisTree.electron_pt[indexElectron2] > singleElectronTriggerPtCut && fabs(analysisTree.electron_eta[indexElectron2]) < singleElectronTriggerEtaCut){
		isElectron2SingleElectronMatched = true;

	      }
            }
	  for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
	      float dRtrig = deltaR(analysisTree.electron_eta[indexElectron1],analysisTree.electron_phi[indexElectron1],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
	      if (dRtrig>DRTrigMatch) continue;
	      if (analysisTree.trigobject_filters[iT][nDoubleElectronFilterLeg1] && analysisTree.electron_pt[indexElectron1] > doubleElectronLeg1TriggerPtCut)
		isElectron1DoubleElectronLeg1Matched = true;
            }
	  for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
	      float dRtrig = deltaR(analysisTree.electron_eta[indexElectron1],analysisTree.electron_phi[indexElectron1],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
	      if (dRtrig>DRTrigMatch) continue;
	      if (analysisTree.trigobject_filters[iT][nDoubleElectronFilterLeg2] && analysisTree.electron_pt[indexElectron1] > doubleElectronLeg2TriggerPtCut)
		isElectron1DoubleElectronLeg2Matched = true;
            }
	  for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
	      float dRtrig = deltaR(analysisTree.electron_eta[indexElectron2],analysisTree.electron_phi[indexElectron2],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
	      if (dRtrig>DRTrigMatch) continue;
	      if (analysisTree.trigobject_filters[iT][nDoubleElectronFilterLeg1] && analysisTree.electron_pt[indexElectron2] > doubleElectronLeg1TriggerPtCut)
		isElectron2DoubleElectronLeg1Matched = true;
            }
	  for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
	      float dRtrig = deltaR(analysisTree.electron_eta[indexElectron2],analysisTree.electron_phi[indexElectron2],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
	      if (dRtrig>DRTrigMatch) continue;
	      if (analysisTree.trigobject_filters[iT][nDoubleElectronFilterLeg2] && analysisTree.electron_pt[indexElectron2] > doubleElectronLeg2TriggerPtCut)
		isElectron2DoubleElectronLeg2Matched = true;
            }
	  for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
	      float dRtrig = deltaR(analysisTree.electron_eta[indexElectron1],analysisTree.electron_phi[indexElectron1],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
	      if (dRtrig>DRTrigMatch) continue;
	      if (analysisTree.trigobject_filters[iT][nDoubleElectronFilterDz])
		isElectron1DoubleElectrondzMatched = true;
            }
	  for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
	      float dRtrig = deltaR(analysisTree.electron_eta[indexElectron2],analysisTree.electron_phi[indexElectron2],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
	      if (dRtrig>DRTrigMatch) continue;
	      if (analysisTree.trigobject_filters[iT][nDoubleElectronFilterDz])
		isElectron2DoubleElectrondzMatched = true;
            }
            
	  if(isElectron1DoubleElectronLeg1Matched && isElectron2DoubleElectronLeg2Matched)
	    isElectron12DoubleElectronLeg1Leg2Matched = true;
	  if(isElectron1DoubleElectronLeg2Matched && isElectron2DoubleElectronLeg1Matched)
	    isElectron12DoubleElectronLeg2Leg1Matched = true;
	  if((isElectron12DoubleElectronLeg1Leg2Matched || isElectron12DoubleElectronLeg2Leg1Matched) && isElectron1DoubleElectrondzMatched && isElectron2DoubleElectrondzMatched)
	    isDoubleElectronTriggerFilterMatched = true;
            
	  if(isElectron1SingleElectronMatched || isElectron2SingleElectronMatched)
	    isSingleElectronTriggerFilterMatched = true;	    
	  

	  if(applySingleEleTriggerOnly == false)//this setting is for switching on and off single electron trigger
            {
	      if ((isSingleElectronTriggerFilterMatched == false) && (isDoubleElectronTriggerFilterMatched == false))
		continue;
            }
	  else
            {
	      if (isSingleElectronTriggerFilterMatched == false)
		continue;
            }

	  for_eem_electronTrigSF_1 = 1.0;
	  for_eem_electronTrigSF_2 = 1.0;

	  if(!isData){
	    if(isSingleElectronTriggerFilterMatched && isElectron1SingleElectronMatched)
	      for_eem_electronTrigSF_1 = (float)SF_eleTrig->get_ScaleFactor(double(analysisTree.electron_pt[indexElectron1]),double(analysisTree.electron_eta[indexElectron1]));

	    if(isSingleElectronTriggerFilterMatched && isElectron2SingleElectronMatched)
	      for_eem_electronTrigSF_2 = (float)SF_eleTrig->get_ScaleFactor(double(analysisTree.electron_pt[indexElectron2]),double(analysisTree.electron_eta[indexElectron2]));
	  }
        }




      }//if(loosestEles.size() >= 2 && loosestMuons.size() >= 1 && idisoEles.size() <= 2 && idisoMuons.size() <= 1 && goodTaus.size() == 0){



      //for mme


       indexMuon1 = -1;
       indexMuon2 = -1;

       indexElectron1 = -1;
       indexElectron2 = -1;

       indexFakeElectron = -1;
       indexFakeMuon = -1;


      if(loosestMuons.size() >= 2 && loosestEles.size() >=1 && idisoEles.size() <= 1 && idisoMuons.size() <= 2 && goodTaus.size() == 0){


	bool foundZOS = false;
	TLorentzVector Mu_1, Mu_2;
	for_mme_m_MM = 0;
	float m_Dist = 9999;

	for(unsigned int im1=0; im1<goodMuons.size(); im1++){
	  for(unsigned int im2=im1+1; im2<goodMuons.size(); im2++){
	    


	    int indexTemp1 = goodMuons[im1];
	    int indexTemp2 = goodMuons[im2];
	    if (indexTemp1 == indexTemp2) continue;
	    float q1 = analysisTree.muon_charge[indexTemp1];
	    float q2 = analysisTree.muon_charge[indexTemp2];

	    //	    cout<<endl<<"q1="<<q1<<endl<<"q2="<<q2<<endl;

	    if (q1*q2 > 0) continue;
	    Mu_1.SetXYZM(analysisTree.muon_px[indexTemp1],analysisTree.muon_py[indexTemp1],analysisTree.muon_pz[indexTemp1],muonMass);
	    Mu_2.SetXYZM(analysisTree.muon_px[indexTemp2],analysisTree.muon_py[indexTemp2],analysisTree.muon_pz[indexTemp2],muonMass);

	    //	    cout<<endl<<"fabs((Ele_1+Ele_2).M() - 91.1876)="<<fabs((Ele_1+Ele_2).M() - 91.1876)<<endl<<"m_Dist="<<m_Dist<<endl<<"foundZOS="<<foundZOS;

	    if (fabs((Mu_1+Mu_2).M() - 91.1876) < m_Dist){
	      for_mme_m_MM = (Mu_1+Mu_2).M();
	      m_Dist = fabs(for_mme_m_MM - 91.1876);
	      foundZOS = true;
	      if (analysisTree.muon_pt[indexTemp1]>analysisTree.muon_pt[indexTemp2])
		{
		  indexMuon1 = indexTemp1;
		  indexMuon2 = indexTemp2;
		}
	      else
		{
		  indexMuon1 = indexTemp2;
		  indexMuon2 = indexTemp1;
		}
	    }//if (fabs((Ele_1+Ele_2).M() - 91.1876) < m_Dist){
	    //	    cout<<endl<<"indexElectron1="<<indexElectron1<<endl<<"indexElectron2="<<indexElectron2<<endl;
	  }//for(unsigned int ie2=ie1+1; ie2<idEles.size(); ie2++){
	}//for(unsigned int ie1=0; ie1<idEles.size(); ie1++){

	//	cout<<endl<<"foundZOS="<<foundZOS<<endl;

	if(!foundZOS) continue;

	Float_t dR_Z1_Z2 = deltaR(analysisTree.muon_eta[indexMuon1],analysisTree.muon_phi[indexMuon1],analysisTree.muon_eta[indexMuon2],analysisTree.muon_phi[indexMuon2]);

	if(dR_Z1_Z2 < 0.3) continue;

	for(unsigned int i_fake_electron=0; i_fake_electron<goodEles.size(); i_fake_electron++){
	  unsigned int indexFakeElectron_temp = goodEles[i_fake_electron];

	  float dr_1 = deltaR(analysisTree.muon_eta[indexMuon1],analysisTree.muon_phi[indexMuon1],analysisTree.electron_eta[indexFakeElectron_temp],analysisTree.electron_phi[indexFakeElectron_temp]);
	  float dr_2 = deltaR(analysisTree.muon_eta[indexMuon2],analysisTree.muon_phi[indexMuon2],analysisTree.electron_eta[indexFakeElectron_temp],analysisTree.electron_phi[indexFakeElectron_temp]);
	  if(dr_1 < 0.3 || dr_2 < 0.3) continue; 
	  if(indexFakeMuon != -1){
	    if(analysisTree.electron_pt[indexFakeElectron_temp]>analysisTree.electron_pt[indexFakeElectron])
	      indexFakeElectron = indexFakeElectron_temp;
	  }
	  if(indexFakeElectron == -1) indexFakeElectron = indexFakeElectron_temp;
	
	}//for(int i_fake_electron=0; i_fake_electron<idEles.size(); i_fake_electron++){

	if(indexFakeElectron == -1) continue;
	
	is_mme = true;

	for_mme_fake_ele_iso = (analysisTree.electron_r03_sumChargedHadronPt[indexFakeElectron] + std::max(0.,analysisTree.electron_r03_sumNeutralHadronEt[indexFakeElectron] + analysisTree.electron_r03_sumPhotonEt[indexFakeElectron] - (0.5 * analysisTree.electron_r03_sumPUPt[indexFakeElectron]))) / analysisTree.electron_pt[indexFakeElectron];

	for_mme_fake_ele_id = analysisTree.electron_mva_wp90_noIso_Fall17_v2[indexFakeElectron];

	for_mme_mu_1_iso = (analysisTree.muon_r04_sumChargedHadronPt[indexMuon1] + std::max(0.,analysisTree.muon_r04_sumNeutralHadronEt[indexMuon1] + analysisTree.muon_r04_sumPhotonEt[indexMuon1] - 0.5*analysisTree.muon_r04_sumPUPt[indexMuon1]))/ analysisTree.muon_pt[indexMuon1];

	for_mme_mu_1_id = analysisTree.muon_isLoose[indexMuon1];

	for_mme_mu_2_iso = (analysisTree.muon_r04_sumChargedHadronPt[indexMuon2] + std::max(0.,analysisTree.muon_r04_sumNeutralHadronEt[indexMuon2] + analysisTree.muon_r04_sumPhotonEt[indexMuon2] - 0.5*analysisTree.muon_r04_sumPUPt[indexMuon2]))/ analysisTree.muon_pt[indexMuon2];

	for_mme_mu_2_id = analysisTree.muon_isLoose[indexMuon2];

	Mu_1.SetXYZM(analysisTree.muon_px[indexMuon1],analysisTree.muon_py[indexMuon1],analysisTree.muon_pz[indexMuon1],muonMass);
	Mu_2.SetXYZM(analysisTree.muon_px[indexMuon2],analysisTree.muon_py[indexMuon2],analysisTree.muon_pz[indexMuon2],muonMass);

	TLorentzVector fake_electron;
	fake_electron.SetXYZM(analysisTree.electron_px[indexFakeElectron],analysisTree.electron_py[indexFakeElectron],analysisTree.electron_pz[indexFakeElectron],electronMass);
	for_mme_m_M1_fake_elec = (Mu_1 + fake_electron).M();
	for_mme_m_M2_fake_elec = (Mu_2 + fake_electron).M();
	float met = TMath::Sqrt(analysisTree.pfmetcorr_ex*analysisTree.pfmetcorr_ex + analysisTree.pfmetcorr_ey*analysisTree.pfmetcorr_ey);
	float metphi = analysisTree.pfmetcorr_phi;
	TLorentzVector metLV(met*TMath::Cos(metphi),met*TMath::Sin(metphi),0,TMath::Sqrt(met*TMath::Sin(metphi)*met*TMath::Sin(metphi) + met*TMath::Cos(metphi)*met*TMath::Cos(metphi)));
	TLorentzVector metLV_JetEnUp(analysisTree.pfmetcorr_ex_JetEnUp,analysisTree.pfmetcorr_ey_JetEnUp,0,TMath::Sqrt(analysisTree.pfmetcorr_ex_JetEnUp*analysisTree.pfmetcorr_ex_JetEnUp+analysisTree.pfmetcorr_ey_JetEnUp*analysisTree.pfmetcorr_ey_JetEnUp));
	TLorentzVector metLV_JetEnDown(analysisTree.pfmetcorr_ex_JetEnDown,analysisTree.pfmetcorr_ey_JetEnDown,0,TMath::Sqrt(analysisTree.pfmetcorr_ex_JetEnDown*analysisTree.pfmetcorr_ex_JetEnDown+analysisTree.pfmetcorr_ey_JetEnDown*analysisTree.pfmetcorr_ey_JetEnDown));
	TLorentzVector metLV_UnclusteredEnUp(analysisTree.pfmetcorr_ex_UnclusteredEnUp,analysisTree.pfmetcorr_ey_UnclusteredEnUp,0,TMath::Sqrt(analysisTree.pfmetcorr_ex_UnclusteredEnUp*analysisTree.pfmetcorr_ex_UnclusteredEnUp+analysisTree.pfmetcorr_ey_UnclusteredEnUp*analysisTree.pfmetcorr_ey_UnclusteredEnUp));
	TLorentzVector metLV_UnclusteredEnDown(analysisTree.pfmetcorr_ex_UnclusteredEnDown,analysisTree.pfmetcorr_ey_UnclusteredEnDown,0,TMath::Sqrt(analysisTree.pfmetcorr_ex_UnclusteredEnDown*analysisTree.pfmetcorr_ex_UnclusteredEnDown+analysisTree.pfmetcorr_ey_UnclusteredEnDown*analysisTree.pfmetcorr_ey_UnclusteredEnDown));
	TLorentzVector metLV_JetResUp(analysisTree.pfmetcorr_ex_JetResUp,analysisTree.pfmetcorr_ey_JetResUp,0,TMath::Sqrt(analysisTree.pfmetcorr_ex_JetResUp*analysisTree.pfmetcorr_ex_JetResUp+analysisTree.pfmetcorr_ey_JetResUp*analysisTree.pfmetcorr_ey_JetResUp));
	TLorentzVector metLV_JetResDown(analysisTree.pfmetcorr_ex_JetResDown,analysisTree.pfmetcorr_ey_JetResDown,0,TMath::Sqrt(analysisTree.pfmetcorr_ex_JetResDown*analysisTree.pfmetcorr_ex_JetResDown+analysisTree.pfmetcorr_ey_JetResDown*analysisTree.pfmetcorr_ey_JetResDown));

	for_mme_pfmt_fake_electron = mT(fake_electron,metLV);
	for_mme_pfmt_fake_electron_JetEnUp = mT(fake_electron,metLV_JetEnUp);
	for_mme_pfmt_fake_electron_JetEnDown = mT(fake_electron,metLV_JetEnDown);
	for_mme_pfmt_fake_electron_UnclusteredEnUp = mT(fake_electron,metLV_UnclusteredEnUp);
	for_mme_pfmt_fake_electron_UnclusteredEnDown = mT(fake_electron,metLV_UnclusteredEnDown);
	for_mme_pfmt_fake_electron_JetResUp = mT(fake_electron,metLV_JetResUp);
	for_mme_pfmt_fake_electron_JetResDown = mT(fake_electron,metLV_JetResDown);


	for_mme_fake_ele_eta = analysisTree.electron_eta[indexFakeElectron];
	for_mme_dR_Z1_fake_lepton = deltaR(analysisTree.muon_eta[indexMuon1],analysisTree.muon_phi[indexMuon1],analysisTree.electron_eta[indexFakeElectron],analysisTree.electron_phi[indexFakeElectron]);
	for_mme_dR_Z2_fake_lepton = deltaR(analysisTree.muon_eta[indexMuon2],analysisTree.muon_phi[indexMuon2],analysisTree.electron_eta[indexFakeElectron],analysisTree.electron_phi[indexFakeElectron]);
	for_mme_pt_fake_e = analysisTree.electron_pt[indexFakeElectron];



        if(!isData)
	  {
            for_mme_muonIDSF_1 = (float)SF_muonIdIso->get_ScaleFactor(double(analysisTree.muon_pt[indexMuon1]),double(analysisTree.muon_eta[indexMuon1]));
            for_mme_muonIDSF_2 = (float)SF_muonIdIso->get_ScaleFactor(double(analysisTree.muon_pt[indexMuon2]),double(analysisTree.muon_eta[indexMuon2]));
            for_mme_electronIDSF_fake = (float)SF_eleIdIso->get_ScaleFactor(double(analysisTree.electron_pt[indexFakeElectron]),double(analysisTree.electron_eta[indexFakeElectron]));
	  }




      float minDR_1 = 0.2;
      float minDR_2 = 0.2;
      float minDR_3 = 0.2;

      if (!isData)
        {
	  for (unsigned int igen=0; igen < analysisTree.genparticles_count; ++igen)
	    {
	      //  cout<<endl<<"igen="<<igen<<endl;
	      float ptGen = PtoPt(analysisTree.genparticles_px[igen], analysisTree.genparticles_py[igen]);
	      bool type1 = abs(analysisTree.genparticles_pdgid[igen])==11 && analysisTree.genparticles_isPrompt[igen] && ptGen>8;
	      bool type2 = abs(analysisTree.genparticles_pdgid[igen])==13 && analysisTree.genparticles_isPrompt[igen] && ptGen>8;
	      bool type3 = abs(analysisTree.genparticles_pdgid[igen])==11 && analysisTree.genparticles_isDirectPromptTauDecayProduct[igen] && ptGen>8;
	      bool type4 = abs(analysisTree.genparticles_pdgid[igen])==13 && analysisTree.genparticles_isDirectPromptTauDecayProduct[igen] && ptGen>8;
	      bool isAnyType = type1 || type2 || type3 || type4;

	      if (isAnyType)
                {
		  float etaGen = PtoEta(analysisTree.genparticles_px[igen],analysisTree.genparticles_py[igen], analysisTree.genparticles_pz[igen]);
		  float phiGen = PtoPhi(analysisTree.genparticles_px[igen],analysisTree.genparticles_py[igen]);

		  float deltaR_1, deltaR_2, deltaR_3;

		    deltaR_1 = deltaR(analysisTree.muon_eta[indexMuon1],analysisTree.muon_phi[indexMuon1],etaGen,phiGen);
		    deltaR_2 = deltaR(analysisTree.muon_eta[indexMuon2],analysisTree.muon_phi[indexMuon2],etaGen,phiGen);
		    deltaR_3 = deltaR(analysisTree.electron_eta[indexFakeElectron],analysisTree.electron_phi[indexFakeElectron],etaGen,phiGen);

		  if (deltaR_1<minDR_1)
                    {
		      minDR_1 = deltaR_1;
		      if (type1) for_mme_gen_match_1 = 1;
		      else if (type2) for_mme_gen_match_1 = 2;
		      else if (type3) for_mme_gen_match_1 = 3;
		      else if (type4) for_mme_gen_match_1 = 4;
                    }

		  if (deltaR_2<minDR_2)
                    {
		      minDR_2 = deltaR_2;
		      if (type1) for_mme_gen_match_2 = 1;
		      else if (type2) for_mme_gen_match_2 = 2;
		      else if (type3) for_mme_gen_match_2 = 3;
		      else if (type4) for_mme_gen_match_2 = 4;
                    }

		  if (deltaR_3<minDR_3)
                    {
		      minDR_3 = deltaR_3;
		      if (type1) for_mme_gen_match_3 = 1;
		      else if (type2) for_mme_gen_match_3 = 2;
		      else if (type3) for_mme_gen_match_3 = 3;
		      else if (type4) for_mme_gen_match_3 = 4;
                    }
                }
            }

	  for (unsigned int igen=0; igen < analysisTree.gentau_count; ++igen)
            {

	      if (analysisTree.gentau_visibleNoLep_pt[igen]>15.)
                {

		  float deltaR_1, deltaR_2, deltaR_3;

             
		    deltaR_1 = deltaR(analysisTree.muon_eta[indexMuon1],analysisTree.muon_phi[indexMuon1],analysisTree.gentau_visibleNoLep_eta[igen],analysisTree.gentau_visibleNoLep_phi[igen]);
		    deltaR_2 = deltaR(analysisTree.muon_eta[indexMuon2],analysisTree.muon_phi[indexMuon2],analysisTree.gentau_visibleNoLep_eta[igen],analysisTree.gentau_visibleNoLep_phi[igen]);
		    deltaR_3 = deltaR(analysisTree.electron_eta[indexFakeElectron],analysisTree.electron_phi[indexFakeElectron],analysisTree.gentau_visibleNoLep_eta[igen],analysisTree.gentau_visibleNoLep_phi[igen]);
	
		  if (deltaR_1<minDR_1)
                    {
		      minDR_1 = deltaR_1;
		      for_mme_gen_match_1 = 5;
                    }

		  if (deltaR_2<minDR_2)
                    {
		      minDR_2 = deltaR_2;
		      for_mme_gen_match_2 = 5;
                    }

		  if (deltaR_3<minDR_3)
                    {
		      minDR_3 = deltaR_3;
		      for_mme_gen_match_3 = 5;
                    }

                }
            }
        }


        bool isSingleMuon_1_TriggerFilterMatched = false;
        bool isSingleMuon_2_TriggerFilterMatched = false;
        bool isDoubleMuon_3_TriggerFilterMatched = false;
        bool isDoubleMuon_4_TriggerFilterMatched = false;
        
        bool isMuon1SingleMuon_1_a_Matched = false;
        bool isMuon1SingleMuon_1_b_Matched = false;
        bool isMuon2SingleMuon_1_a_Matched = false;
        bool isMuon2SingleMuon_1_b_Matched = false;

        bool isMuon1SingleMuon_2_Matched = false;
        bool isMuon2SingleMuon_2_Matched = false;
        
        bool isMuon1SingleMuonMatched = false;
        bool isMuon2SingleMuonMatched = false;
        
        bool isMuon1DoubleMuon_3_Leg1Matched = false;
        bool isMuon1DoubleMuon_3_Leg2_a_Matched = false;
        bool isMuon1DoubleMuon_3_Leg2_b_Matched = false;
        bool isMuon2DoubleMuon_3_Leg1Matched = false;
        bool isMuon2DoubleMuon_3_Leg2_a_Matched = false;
        bool isMuon2DoubleMuon_3_Leg2_b_Matched = false;
        bool isMuon1DoubleMuon_3_dzMatched = false;
        bool isMuon2DoubleMuon_3_dzMatched = false;
        bool isMuon1DoubleMuon_3_massMatched = false;
        bool isMuon2DoubleMuon_3_massMatched = false;

        bool isMuon1DoubleMuon_4_Leg1Matched = false;
        bool isMuon1DoubleMuon_4_Leg2Matched = false;
        bool isMuon2DoubleMuon_4_Leg1Matched = false;
        bool isMuon2DoubleMuon_4_Leg2Matched = false;
        bool isMuon1DoubleMuon_4_dzMatched = false;
        bool isMuon2DoubleMuon_4_dzMatched = false;
        
        bool isSingleMuonTriggerFilterMatched = false;
        bool isDoubleMuonTriggerFilterMatched = false;

        if(applyTrigger)
        {
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon1],analysisTree.muon_phi[indexMuon1],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nSingleMuon_1_Filter_a] && analysisTree.muon_pt[indexMuon1] > singleMuonTriggerPtCut_1)
                    isMuon1SingleMuon_1_a_Matched = true;
            }
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon1],analysisTree.muon_phi[indexMuon1],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nSingleMuon_1_Filter_b] && analysisTree.muon_pt[indexMuon1] > singleMuonTriggerPtCut_1)
                    isMuon1SingleMuon_1_b_Matched = true;
            }
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon2],analysisTree.muon_phi[indexMuon2],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nSingleMuon_1_Filter_a] && analysisTree.muon_pt[indexMuon2] > singleMuonTriggerPtCut_1)
                    isMuon2SingleMuon_1_a_Matched = true;
            }
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon2],analysisTree.muon_phi[indexMuon2],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nSingleMuon_1_Filter_b] && analysisTree.muon_pt[indexMuon2] > singleMuonTriggerPtCut_1)
                    isMuon2SingleMuon_1_b_Matched = true;
            }
            
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon1],analysisTree.muon_phi[indexMuon1],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nSingleMuon_2_Filter] && analysisTree.muon_pt[indexMuon1] > singleMuonTriggerPtCut_1)
                    isMuon1SingleMuon_2_Matched = true;
            }
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon2],analysisTree.muon_phi[indexMuon2],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nSingleMuon_2_Filter] && analysisTree.muon_pt[indexMuon2] > singleMuonTriggerPtCut_1)
                    isMuon2SingleMuon_2_Matched = true;
            }
            
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon1],analysisTree.muon_phi[indexMuon1],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nDoubleMuon_3_FilterLeg1] && analysisTree.muon_pt[indexMuon1] > doubleMuonLeg1TriggerPtCut_3)
                    isMuon1DoubleMuon_3_Leg1Matched = true;
            }
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon1],analysisTree.muon_phi[indexMuon1],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nDoubleMuon_3_FilterLeg2_a] && analysisTree.muon_pt[indexMuon1] > doubleMuonLeg2TriggerPtCut_3)
                    isMuon1DoubleMuon_3_Leg2_a_Matched = true;
            }
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon1],analysisTree.muon_phi[indexMuon1],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nDoubleMuon_3_FilterLeg2_b] && analysisTree.muon_pt[indexMuon1] > doubleMuonLeg2TriggerPtCut_3)
                    isMuon1DoubleMuon_3_Leg2_b_Matched = true;
            }
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon2],analysisTree.muon_phi[indexMuon2],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nDoubleMuon_3_FilterLeg1] && analysisTree.muon_pt[indexMuon2] > doubleMuonLeg1TriggerPtCut_3)
                    isMuon2DoubleMuon_3_Leg1Matched = true;
            }
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon2],analysisTree.muon_phi[indexMuon2],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nDoubleMuon_3_FilterLeg2_a] && analysisTree.muon_pt[indexMuon2] > doubleMuonLeg2TriggerPtCut_3)
                    isMuon2DoubleMuon_3_Leg2_a_Matched = true;
            }
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon2],analysisTree.muon_phi[indexMuon2],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nDoubleMuon_3_FilterLeg2_b] && analysisTree.muon_pt[indexMuon2] > doubleMuonLeg2TriggerPtCut_3)
                    isMuon2DoubleMuon_3_Leg2_b_Matched = true;
            }
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon1],analysisTree.muon_phi[indexMuon1],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nDoubleMuon_3_FilterDz])
                    isMuon1DoubleMuon_3_dzMatched = true;
            }
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon2],analysisTree.muon_phi[indexMuon2],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nDoubleMuon_3_FilterDz])
                    isMuon2DoubleMuon_3_dzMatched = true;
            }
            
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon1],analysisTree.muon_phi[indexMuon1],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nDoubleMuon_3_FilterMass])
                    isMuon1DoubleMuon_3_massMatched = true;
            }
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon2],analysisTree.muon_phi[indexMuon2],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nDoubleMuon_3_FilterMass])
                    isMuon2DoubleMuon_3_massMatched = true;
            }
            
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon1],analysisTree.muon_phi[indexMuon1],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nDoubleMuon_4_FilterLeg1] && analysisTree.muon_pt[indexMuon1] > doubleMuonLeg1TriggerPtCut_4)
                    isMuon1DoubleMuon_4_Leg1Matched = true;
            }
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon1],analysisTree.muon_phi[indexMuon1],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nDoubleMuon_4_FilterLeg2] && analysisTree.muon_pt[indexMuon1] > doubleMuonLeg2TriggerPtCut_4)
                    isMuon1DoubleMuon_4_Leg2Matched = true;
            }
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon2],analysisTree.muon_phi[indexMuon2],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nDoubleMuon_4_FilterLeg1] && analysisTree.muon_pt[indexMuon2] > doubleMuonLeg1TriggerPtCut_4)
                    isMuon2DoubleMuon_4_Leg1Matched = true;
            }
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon2],analysisTree.muon_phi[indexMuon2],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nDoubleMuon_4_FilterLeg2] && analysisTree.muon_pt[indexMuon2] > doubleMuonLeg2TriggerPtCut_4)
                    isMuon2DoubleMuon_4_Leg2Matched = true;
            }
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon1],analysisTree.muon_phi[indexMuon1],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nDoubleMuon_4_FilterDz])
                    isMuon1DoubleMuon_4_dzMatched = true;
            }
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon2],analysisTree.muon_phi[indexMuon2],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nDoubleMuon_4_FilterDz])
                    isMuon2DoubleMuon_4_dzMatched = true;
            }
            
            //check which muon matching which trigger
            if((isMuon1SingleMuon_1_a_Matched || isMuon1SingleMuon_1_b_Matched) || (isMuon2SingleMuon_1_a_Matched || isMuon2SingleMuon_1_b_Matched))
                isSingleMuon_1_TriggerFilterMatched = true;
            if(isMuon1SingleMuon_2_Matched || isMuon2SingleMuon_2_Matched)
                isSingleMuon_2_TriggerFilterMatched = true;
            
            if((isMuon1SingleMuon_1_a_Matched || isMuon1SingleMuon_1_b_Matched) || isMuon1SingleMuon_2_Matched)
                isMuon1SingleMuonMatched = true;
            if((isMuon2SingleMuon_1_a_Matched || isMuon2SingleMuon_1_b_Matched) || isMuon2SingleMuon_2_Matched)
                isMuon2SingleMuonMatched = true;
            
            if(era == "2016")
            {
                if(isMuon1DoubleMuon_3_Leg1Matched && (isMuon2DoubleMuon_3_Leg2_a_Matched || isMuon2DoubleMuon_3_Leg2_b_Matched) && isMuon1DoubleMuon_3_dzMatched && isMuon2DoubleMuon_3_dzMatched)
                    isDoubleMuon_3_TriggerFilterMatched = true;
            }
            else
            {
                if(isMuon1DoubleMuon_3_Leg1Matched && (isMuon2DoubleMuon_3_Leg2_a_Matched || isMuon2DoubleMuon_3_Leg2_b_Matched) && isMuon1DoubleMuon_3_dzMatched && isMuon2DoubleMuon_3_dzMatched && isMuon1DoubleMuon_3_massMatched && isMuon2DoubleMuon_3_massMatched)
                    isDoubleMuon_3_TriggerFilterMatched = true;
            }
            if(era == "2016")
            {
                if(isMuon2DoubleMuon_3_Leg1Matched && (isMuon1DoubleMuon_3_Leg2_a_Matched || isMuon1DoubleMuon_3_Leg2_b_Matched) && isMuon1DoubleMuon_3_dzMatched && isMuon2DoubleMuon_3_dzMatched)
                    isDoubleMuon_3_TriggerFilterMatched = true;
            }
            else
            {
                if(isMuon2DoubleMuon_3_Leg1Matched && (isMuon1DoubleMuon_3_Leg2_a_Matched || isMuon1DoubleMuon_3_Leg2_b_Matched) && isMuon1DoubleMuon_3_dzMatched && isMuon2DoubleMuon_3_dzMatched && isMuon1DoubleMuon_3_massMatched && isMuon2DoubleMuon_3_massMatched)
                    isDoubleMuon_3_TriggerFilterMatched = true;
            }
            if(isMuon1DoubleMuon_4_Leg1Matched && isMuon2DoubleMuon_4_Leg2Matched && isMuon1DoubleMuon_4_dzMatched && isMuon2DoubleMuon_4_dzMatched)
                isDoubleMuon_4_TriggerFilterMatched = true;
                
            if(isMuon2DoubleMuon_4_Leg1Matched && isMuon1DoubleMuon_4_Leg2Matched && isMuon1DoubleMuon_4_dzMatched && isMuon2DoubleMuon_4_dzMatched)
                isDoubleMuon_4_TriggerFilterMatched = true;
                
            //
            if (applySingleMuTriggerOnly == true)//this setting is for switching on and off single electron trigger
            {
                if((era == "2018") || (era == "2017"))
                {
                    if(isSingleMuon_1_TriggerFilterMatched == true)
                        isSingleMuonTriggerFilterMatched = true;
                }
                if(era == "2016")
                {
                    if((isSingleMuon_1_TriggerFilterMatched == true) || (isSingleMuon_2_TriggerFilterMatched == true))
                        isSingleMuonTriggerFilterMatched = true;
                }
                if(isSingleMuonTriggerFilterMatched == false)
                    continue;
            }
            else//"OR" double trigger apply
            {
                if((era == "2018") || (era == "2017"))
                {
                    if(isSingleMuon_1_TriggerFilterMatched == true)
                        isSingleMuonTriggerFilterMatched = true;
                        
                    if (isDoubleMuon_3_TriggerFilterMatched == true)
                        isDoubleMuonTriggerFilterMatched = true;
                    
                    if((isSingleMuonTriggerFilterMatched==false) && (isDoubleMuonTriggerFilterMatched==false))
                        continue;
                }
                if(era == "2016")
                {
                    if((isSingleMuon_1_TriggerFilterMatched==true) || (isSingleMuon_2_TriggerFilterMatched==true))
                        isSingleMuonTriggerFilterMatched = true;
                    
                    if((isDoubleMuon_3_TriggerFilterMatched==true) || (isDoubleMuon_4_TriggerFilterMatched==true))
                        isDoubleMuonTriggerFilterMatched = true;
                    
                    if ((isSingleMuonTriggerFilterMatched==false) && (isDoubleMuonTriggerFilterMatched==false) )
                    continue;
                }
            }
	    /*
	    cout<<endl<<"isSingleMuonTriggerFilterMatched="<<isSingleMuonTriggerFilterMatched<<endl<<"isMuon1SingleMuonMatched="<<isMuon1SingleMuonMatched<<endl<<"isMuon2SingleMuonMatched="<<isMuon2SingleMuonMatched<<endl;
	    cout<<endl<<"muonTrigSF_1="<<muonTrigSF_1<<endl<<"muonTrigSF_2="<<muonTrigSF_2<<endl;
	    */

	    for_mme_muonTrigSF_1 = 1.0;
	    for_mme_muonTrigSF_2 = 1.0;

	    if(!isData){
	      if(isSingleMuonTriggerFilterMatched && isMuon1SingleMuonMatched)
		for_mme_muonTrigSF_1 = (float)SF_muonTrig->get_ScaleFactor(double(analysisTree.muon_pt[indexMuon1]),double(analysisTree.muon_eta[indexMuon1]));

	      if(isSingleMuonTriggerFilterMatched && isMuon2SingleMuonMatched)
		for_mme_muonTrigSF_2 = (float)SF_muonTrig->get_ScaleFactor(double(analysisTree.muon_pt[indexMuon2]),double(analysisTree.muon_eta[indexMuon2]));
	    }
	    //	    cout<<endl<<"muonTrigSF_1="<<muonTrigSF_1<<endl<<"muonTrigSF_2="<<muonTrigSF_2<<endl;

        }



      }//if(loosestMuons.size() >= 2 && loosestEles.size() >=1 && idisoEles.size() <= 1 && idisoMuons.size() <= 2 && goodTaus.size() == 0){

      
      //for mmm	


       indexMuon1 = -1;
       indexMuon2 = -1;

       indexElectron1 = -1;
       indexElectron2 = -1;

       indexFakeElectron = -1;
       indexFakeMuon = -1;

      if(loosestMuons.size() >= 3 && idisoEles.size() <= 0 && idisoMuons.size() <= 3 && goodTaus.size() == 0){

	bool foundZOS = false;
	TLorentzVector Mu_1, Mu_2;
	for_mmm_m_MM = 0;
	float m_Dist = 9999;
	for(unsigned int im1=0;im1<goodMuons.size();++im1)
	  {
	    int indexTemp1 = goodMuons[im1];
	    float q1 = analysisTree.muon_charge[indexTemp1];
	    for(unsigned int im2=im1+1;im2<goodMuons.size();++im2)
	      {
		int indexTemp2 = goodMuons[im2];
		if (indexTemp1 == indexTemp2) continue;
		float q2 = analysisTree.muon_charge[indexTemp2];
		//		cout<<endl<<"q1="<<q1<<endl<<"q2="<<q2<<endl;
		if (q1*q2 > 0) continue;
		Mu_1.SetXYZM(analysisTree.muon_px[indexTemp1],analysisTree.muon_py[indexTemp1],analysisTree.muon_pz[indexTemp1],muonMass);
		Mu_2.SetXYZM(analysisTree.muon_px[indexTemp2],analysisTree.muon_py[indexTemp2],analysisTree.muon_pz[indexTemp2],muonMass);
		//		cout<<endl<<"fabs((Mu_1+Mu_2).M() - 91.1876)="<<fabs((Mu_1+Mu_2).M() - 91.1876)<<endl<<"m_Dist="<<m_Dist<<endl<<"foundZOS="<<foundZOS;
		if (fabs((Mu_1+Mu_2).M() - 91.1876) < m_Dist)
		  {
		    foundZOS = true;
		    for_mmm_m_MM = (Mu_1+Mu_2).M();
		    m_Dist = fabs(for_mmm_m_MM - 91.1876);
		    if (analysisTree.muon_pt[indexTemp1]>analysisTree.muon_pt[indexTemp2])
		      {
			indexMuon1 = indexTemp1;
			indexMuon2 = indexTemp2;
		      }
		    else
		      {
			indexMuon1 = indexTemp2;
			indexMuon2 = indexTemp1;
		      }
		  }//if (fabs((Mu_1+Mu_2).M() - 91.1876) < m_Dist)
		//		cout<<endl<<"indexMuon1="<<indexMuon1<<endl<<"indexMuon2="<<indexMuon2<<endl;
	      }//for(unsigned int im2=im1+1;im2<idMuons.size();++im2)
	  }//for(unsigned int im1=0;im1<idMuons.size();++im1)
	//	cout<<endl<<"foundZOS="<<foundZOS<<endl;
	if(!foundZOS) continue;

	Float_t dR_Z1_Z2 = deltaR(analysisTree.muon_eta[indexMuon1],analysisTree.muon_phi[indexMuon1],analysisTree.muon_eta[indexMuon2],analysisTree.muon_phi[indexMuon2]);

	if(dR_Z1_Z2 < 0.3) continue;

	for(unsigned int i_fake_muon=0; i_fake_muon<goodMuons.size(); i_fake_muon++){
	  int indexFakeMuon_temp = goodMuons[i_fake_muon];

	  if(indexFakeMuon_temp == indexMuon1 || indexFakeMuon_temp== indexMuon2) continue;

	  float dr_1 = deltaR(analysisTree.muon_eta[indexMuon1],analysisTree.muon_phi[indexMuon1],analysisTree.muon_eta[indexFakeMuon_temp],analysisTree.muon_phi[indexFakeMuon_temp]);
	  float dr_2 = deltaR(analysisTree.muon_eta[indexMuon2],analysisTree.muon_phi[indexMuon2],analysisTree.muon_eta[indexFakeMuon_temp],analysisTree.muon_phi[indexFakeMuon_temp]);

	  if(dr_1 < 0.3 || dr_2 < 0.3) continue;

	    if(indexFakeMuon != -1){
	      if(analysisTree.muon_pt[indexFakeMuon_temp]>analysisTree.muon_pt[indexFakeMuon])
		indexFakeMuon = indexFakeMuon_temp;
	    }
	    if(indexFakeMuon == -1) indexFakeMuon = indexFakeMuon_temp;

	}//for(unsigned int i_fake_muon=0; i_fake_muon<goodMuons.size(); i_fake_muon++){

	if(indexFakeMuon == -1) continue;
	
	is_mmm = true;

	for_mmm_fake_muon_iso = (analysisTree.muon_r04_sumChargedHadronPt[indexFakeMuon] + std::max(0.,analysisTree.muon_r04_sumNeutralHadronEt[indexFakeMuon] + analysisTree.muon_r04_sumPhotonEt[indexFakeMuon] - 0.5*analysisTree.muon_r04_sumPUPt[indexFakeMuon]))/ analysisTree.muon_pt[indexFakeMuon];

	for_mmm_fake_muon_id = analysisTree.muon_isLoose[indexFakeMuon];

	for_mmm_mu_1_iso = (analysisTree.muon_r04_sumChargedHadronPt[indexMuon1] + std::max(0.,analysisTree.muon_r04_sumNeutralHadronEt[indexMuon1] + analysisTree.muon_r04_sumPhotonEt[indexMuon1] - 0.5*analysisTree.muon_r04_sumPUPt[indexMuon1]))/ analysisTree.muon_pt[indexMuon1];

	for_mmm_mu_1_id = analysisTree.muon_isLoose[indexMuon1];

	for_mmm_mu_2_iso = (analysisTree.muon_r04_sumChargedHadronPt[indexMuon2] + std::max(0.,analysisTree.muon_r04_sumNeutralHadronEt[indexMuon2] + analysisTree.muon_r04_sumPhotonEt[indexMuon2] - 0.5*analysisTree.muon_r04_sumPUPt[indexMuon2]))/ analysisTree.muon_pt[indexMuon2];

	for_mmm_mu_2_id = analysisTree.muon_isLoose[indexMuon2];




	TLorentzVector fake_muon;

	Mu_1.SetXYZM(analysisTree.muon_px[indexMuon1],analysisTree.muon_py[indexMuon1],analysisTree.muon_pz[indexMuon1],muonMass);

	Mu_2.SetXYZM(analysisTree.muon_px[indexMuon2],analysisTree.muon_py[indexMuon2],analysisTree.muon_pz[indexMuon2],muonMass);

	fake_muon.SetXYZM(analysisTree.muon_px[indexFakeMuon],analysisTree.muon_py[indexFakeMuon],analysisTree.muon_pz[indexFakeMuon],muonMass);
	for_mmm_m_3l = (Mu_1 + Mu_2 + fake_muon).M();

	float met = TMath::Sqrt(analysisTree.pfmetcorr_ex*analysisTree.pfmetcorr_ex + analysisTree.pfmetcorr_ey*analysisTree.pfmetcorr_ey);
	float metphi = analysisTree.pfmetcorr_phi;

	TLorentzVector metLV(met*TMath::Cos(metphi),met*TMath::Sin(metphi),0,TMath::Sqrt(met*TMath::Sin(metphi)*met*TMath::Sin(metphi) + met*TMath::Cos(metphi)*met*TMath::Cos(metphi)));
	TLorentzVector metLV_JetEnUp(analysisTree.pfmetcorr_ex_JetEnUp,analysisTree.pfmetcorr_ey_JetEnUp,0,TMath::Sqrt(analysisTree.pfmetcorr_ex_JetEnUp*analysisTree.pfmetcorr_ex_JetEnUp+analysisTree.pfmetcorr_ey_JetEnUp*analysisTree.pfmetcorr_ey_JetEnUp));
	TLorentzVector metLV_JetEnDown(analysisTree.pfmetcorr_ex_JetEnDown,analysisTree.pfmetcorr_ey_JetEnDown,0,TMath::Sqrt(analysisTree.pfmetcorr_ex_JetEnDown*analysisTree.pfmetcorr_ex_JetEnDown+analysisTree.pfmetcorr_ey_JetEnDown*analysisTree.pfmetcorr_ey_JetEnDown));
	TLorentzVector metLV_UnclusteredEnUp(analysisTree.pfmetcorr_ex_UnclusteredEnUp,analysisTree.pfmetcorr_ey_UnclusteredEnUp,0,TMath::Sqrt(analysisTree.pfmetcorr_ex_UnclusteredEnUp*analysisTree.pfmetcorr_ex_UnclusteredEnUp+analysisTree.pfmetcorr_ey_UnclusteredEnUp*analysisTree.pfmetcorr_ey_UnclusteredEnUp));
	TLorentzVector metLV_UnclusteredEnDown(analysisTree.pfmetcorr_ex_UnclusteredEnDown,analysisTree.pfmetcorr_ey_UnclusteredEnDown,0,TMath::Sqrt(analysisTree.pfmetcorr_ex_UnclusteredEnDown*analysisTree.pfmetcorr_ex_UnclusteredEnDown+analysisTree.pfmetcorr_ey_UnclusteredEnDown*analysisTree.pfmetcorr_ey_UnclusteredEnDown));
	TLorentzVector metLV_JetResUp(analysisTree.pfmetcorr_ex_JetResUp,analysisTree.pfmetcorr_ey_JetResUp,0,TMath::Sqrt(analysisTree.pfmetcorr_ex_JetResUp*analysisTree.pfmetcorr_ex_JetResUp+analysisTree.pfmetcorr_ey_JetResUp*analysisTree.pfmetcorr_ey_JetResUp));
	TLorentzVector metLV_JetResDown(analysisTree.pfmetcorr_ex_JetResDown,analysisTree.pfmetcorr_ey_JetResDown,0,TMath::Sqrt(analysisTree.pfmetcorr_ex_JetResDown*analysisTree.pfmetcorr_ex_JetResDown+analysisTree.pfmetcorr_ey_JetResDown*analysisTree.pfmetcorr_ey_JetResDown));

	for_mmm_pfmt_fake_muon = mT(fake_muon,metLV);
	for_mmm_pfmt_fake_muon_JetEnUp = mT(fake_muon,metLV_JetEnUp);
	for_mmm_pfmt_fake_muon_JetEnDown = mT(fake_muon,metLV_JetEnDown);
	for_mmm_pfmt_fake_muon_UnclusteredEnUp = mT(fake_muon,metLV_UnclusteredEnUp);
	for_mmm_pfmt_fake_muon_UnclusteredEnDown = mT(fake_muon,metLV_UnclusteredEnDown);
	for_mmm_pfmt_fake_muon_JetResUp = mT(fake_muon,metLV_JetResUp);
	for_mmm_pfmt_fake_muon_JetResDown = mT(fake_muon,metLV_JetResDown);


	for_mmm_fake_muon_eta = analysisTree.muon_eta[indexFakeMuon];

	for_mmm_dR_Z1_fake_lepton = deltaR(analysisTree.muon_eta[indexMuon1],analysisTree.muon_phi[indexMuon1],analysisTree.muon_eta[indexFakeMuon],analysisTree.muon_phi[indexFakeMuon]);

	for_mmm_dR_Z2_fake_lepton = deltaR(analysisTree.muon_eta[indexMuon2],analysisTree.muon_phi[indexMuon2],analysisTree.muon_eta[indexFakeMuon],analysisTree.muon_phi[indexFakeMuon]);

	for_mmm_pt_fake_m = analysisTree.muon_pt[indexFakeMuon];


        if(!isData)
	  {
            for_mmm_muonIDSF_1 = (float)SF_muonIdIso->get_ScaleFactor(double(analysisTree.muon_pt[indexMuon1]),double(analysisTree.muon_eta[indexMuon1]));
            for_mmm_muonIDSF_2 = (float)SF_muonIdIso->get_ScaleFactor(double(analysisTree.muon_pt[indexMuon2]),double(analysisTree.muon_eta[indexMuon2]));
            for_mmm_muonIDSF_fake = (float)SF_muonIdIso->get_ScaleFactor(double(analysisTree.muon_pt[indexFakeMuon]),double(analysisTree.muon_eta[indexFakeMuon]));
	  }


      float minDR_1 = 0.2;
      float minDR_2 = 0.2;
      float minDR_3 = 0.2;

      if (!isData)
        {
	  for (unsigned int igen=0; igen < analysisTree.genparticles_count; ++igen)
	    {
	      //  cout<<endl<<"igen="<<igen<<endl;
	      float ptGen = PtoPt(analysisTree.genparticles_px[igen], analysisTree.genparticles_py[igen]);
	      bool type1 = abs(analysisTree.genparticles_pdgid[igen])==11 && analysisTree.genparticles_isPrompt[igen] && ptGen>8;
	      bool type2 = abs(analysisTree.genparticles_pdgid[igen])==13 && analysisTree.genparticles_isPrompt[igen] && ptGen>8;
	      bool type3 = abs(analysisTree.genparticles_pdgid[igen])==11 && analysisTree.genparticles_isDirectPromptTauDecayProduct[igen] && ptGen>8;
	      bool type4 = abs(analysisTree.genparticles_pdgid[igen])==13 && analysisTree.genparticles_isDirectPromptTauDecayProduct[igen] && ptGen>8;
	      bool isAnyType = type1 || type2 || type3 || type4;

	      if (isAnyType)
                {
		  float etaGen = PtoEta(analysisTree.genparticles_px[igen],analysisTree.genparticles_py[igen], analysisTree.genparticles_pz[igen]);
		  float phiGen = PtoPhi(analysisTree.genparticles_px[igen],analysisTree.genparticles_py[igen]);

		  float deltaR_1, deltaR_2, deltaR_3;

		    deltaR_1 = deltaR(analysisTree.muon_eta[indexMuon1],analysisTree.muon_phi[indexMuon1],etaGen,phiGen);
		    deltaR_2 = deltaR(analysisTree.muon_eta[indexMuon2],analysisTree.muon_phi[indexMuon2],etaGen,phiGen);
		    deltaR_3 = deltaR(analysisTree.muon_eta[indexFakeMuon],analysisTree.muon_phi[indexFakeMuon],etaGen,phiGen);
	
		  if (deltaR_1<minDR_1)
                    {
		      minDR_1 = deltaR_1;
		      if (type1) for_mmm_gen_match_1 = 1;
		      else if (type2) for_mmm_gen_match_1 = 2;
		      else if (type3) for_mmm_gen_match_1 = 3;
		      else if (type4) for_mmm_gen_match_1 = 4;
                    }

		  if (deltaR_2<minDR_2)
                    {
		      minDR_2 = deltaR_2;
		      if (type1) for_mmm_gen_match_2 = 1;
		      else if (type2) for_mmm_gen_match_2 = 2;
		      else if (type3) for_mmm_gen_match_2 = 3;
		      else if (type4) for_mmm_gen_match_2 = 4;
                    }

		  if (deltaR_3<minDR_3)
                    {
		      minDR_3 = deltaR_3;
		      if (type1) for_mmm_gen_match_3 = 1;
		      else if (type2) for_mmm_gen_match_3 = 2;
		      else if (type3) for_mmm_gen_match_3 = 3;
		      else if (type4) for_mmm_gen_match_3 = 4;
                    }
                }
            }

	  for (unsigned int igen=0; igen < analysisTree.gentau_count; ++igen)
            {

	      if (analysisTree.gentau_visibleNoLep_pt[igen]>15.)
                {

		  float deltaR_1, deltaR_2, deltaR_3;
		    deltaR_1 = deltaR(analysisTree.muon_eta[indexMuon1],analysisTree.muon_phi[indexMuon1],analysisTree.gentau_visibleNoLep_eta[igen],analysisTree.gentau_visibleNoLep_phi[igen]);
		    deltaR_2 = deltaR(analysisTree.muon_eta[indexMuon2],analysisTree.muon_phi[indexMuon2],analysisTree.gentau_visibleNoLep_eta[igen],analysisTree.gentau_visibleNoLep_phi[igen]);
		    deltaR_3 = deltaR(analysisTree.muon_eta[indexFakeMuon],analysisTree.muon_phi[indexFakeMuon],analysisTree.gentau_visibleNoLep_eta[igen],analysisTree.gentau_visibleNoLep_phi[igen]);


		  if (deltaR_1<minDR_1)
                    {
		      minDR_1 = deltaR_1;
		      for_mmm_gen_match_1 = 5;
                    }

		  if (deltaR_2<minDR_2)
                    {
		      minDR_2 = deltaR_2;
		      for_mmm_gen_match_2 = 5;
                    }

		  if (deltaR_3<minDR_3)
                    {
		      minDR_3 = deltaR_3;
		      for_mmm_gen_match_3 = 5;
                    }

                }
            }
        }


        bool isSingleMuon_1_TriggerFilterMatched = false;
        bool isSingleMuon_2_TriggerFilterMatched = false;
        bool isDoubleMuon_3_TriggerFilterMatched = false;
        bool isDoubleMuon_4_TriggerFilterMatched = false;
        
        bool isMuon1SingleMuon_1_a_Matched = false;
        bool isMuon1SingleMuon_1_b_Matched = false;
        bool isMuon2SingleMuon_1_a_Matched = false;
        bool isMuon2SingleMuon_1_b_Matched = false;

        bool isMuon1SingleMuon_2_Matched = false;
        bool isMuon2SingleMuon_2_Matched = false;
        
        bool isMuon1SingleMuonMatched = false;
        bool isMuon2SingleMuonMatched = false;
        
        bool isMuon1DoubleMuon_3_Leg1Matched = false;
        bool isMuon1DoubleMuon_3_Leg2_a_Matched = false;
        bool isMuon1DoubleMuon_3_Leg2_b_Matched = false;
        bool isMuon2DoubleMuon_3_Leg1Matched = false;
        bool isMuon2DoubleMuon_3_Leg2_a_Matched = false;
        bool isMuon2DoubleMuon_3_Leg2_b_Matched = false;
        bool isMuon1DoubleMuon_3_dzMatched = false;
        bool isMuon2DoubleMuon_3_dzMatched = false;
        bool isMuon1DoubleMuon_3_massMatched = false;
        bool isMuon2DoubleMuon_3_massMatched = false;

        bool isMuon1DoubleMuon_4_Leg1Matched = false;
        bool isMuon1DoubleMuon_4_Leg2Matched = false;
        bool isMuon2DoubleMuon_4_Leg1Matched = false;
        bool isMuon2DoubleMuon_4_Leg2Matched = false;
        bool isMuon1DoubleMuon_4_dzMatched = false;
        bool isMuon2DoubleMuon_4_dzMatched = false;
        
        bool isSingleMuonTriggerFilterMatched = false;
        bool isDoubleMuonTriggerFilterMatched = false;

        if(applyTrigger)
        {
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon1],analysisTree.muon_phi[indexMuon1],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nSingleMuon_1_Filter_a] && analysisTree.muon_pt[indexMuon1] > singleMuonTriggerPtCut_1)
                    isMuon1SingleMuon_1_a_Matched = true;
            }
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon1],analysisTree.muon_phi[indexMuon1],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nSingleMuon_1_Filter_b] && analysisTree.muon_pt[indexMuon1] > singleMuonTriggerPtCut_1)
                    isMuon1SingleMuon_1_b_Matched = true;
            }
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon2],analysisTree.muon_phi[indexMuon2],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nSingleMuon_1_Filter_a] && analysisTree.muon_pt[indexMuon2] > singleMuonTriggerPtCut_1)
                    isMuon2SingleMuon_1_a_Matched = true;
            }
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon2],analysisTree.muon_phi[indexMuon2],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nSingleMuon_1_Filter_b] && analysisTree.muon_pt[indexMuon2] > singleMuonTriggerPtCut_1)
                    isMuon2SingleMuon_1_b_Matched = true;
            }
            
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon1],analysisTree.muon_phi[indexMuon1],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nSingleMuon_2_Filter] && analysisTree.muon_pt[indexMuon1] > singleMuonTriggerPtCut_1)
                    isMuon1SingleMuon_2_Matched = true;
            }
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon2],analysisTree.muon_phi[indexMuon2],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nSingleMuon_2_Filter] && analysisTree.muon_pt[indexMuon2] > singleMuonTriggerPtCut_1)
                    isMuon2SingleMuon_2_Matched = true;
            }
            
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon1],analysisTree.muon_phi[indexMuon1],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nDoubleMuon_3_FilterLeg1] && analysisTree.muon_pt[indexMuon1] > doubleMuonLeg1TriggerPtCut_3)
                    isMuon1DoubleMuon_3_Leg1Matched = true;
            }
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon1],analysisTree.muon_phi[indexMuon1],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nDoubleMuon_3_FilterLeg2_a] && analysisTree.muon_pt[indexMuon1] > doubleMuonLeg2TriggerPtCut_3)
                    isMuon1DoubleMuon_3_Leg2_a_Matched = true;
            }
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon1],analysisTree.muon_phi[indexMuon1],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nDoubleMuon_3_FilterLeg2_b] && analysisTree.muon_pt[indexMuon1] > doubleMuonLeg2TriggerPtCut_3)
                    isMuon1DoubleMuon_3_Leg2_b_Matched = true;
            }
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon2],analysisTree.muon_phi[indexMuon2],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nDoubleMuon_3_FilterLeg1] && analysisTree.muon_pt[indexMuon2] > doubleMuonLeg1TriggerPtCut_3)
                    isMuon2DoubleMuon_3_Leg1Matched = true;
            }
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon2],analysisTree.muon_phi[indexMuon2],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nDoubleMuon_3_FilterLeg2_a] && analysisTree.muon_pt[indexMuon2] > doubleMuonLeg2TriggerPtCut_3)
                    isMuon2DoubleMuon_3_Leg2_a_Matched = true;
            }
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon2],analysisTree.muon_phi[indexMuon2],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nDoubleMuon_3_FilterLeg2_b] && analysisTree.muon_pt[indexMuon2] > doubleMuonLeg2TriggerPtCut_3)
                    isMuon2DoubleMuon_3_Leg2_b_Matched = true;
            }
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon1],analysisTree.muon_phi[indexMuon1],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nDoubleMuon_3_FilterDz])
                    isMuon1DoubleMuon_3_dzMatched = true;
            }
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon2],analysisTree.muon_phi[indexMuon2],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nDoubleMuon_3_FilterDz])
                    isMuon2DoubleMuon_3_dzMatched = true;
            }
            
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon1],analysisTree.muon_phi[indexMuon1],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nDoubleMuon_3_FilterMass])
                    isMuon1DoubleMuon_3_massMatched = true;
            }
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon2],analysisTree.muon_phi[indexMuon2],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nDoubleMuon_3_FilterMass])
                    isMuon2DoubleMuon_3_massMatched = true;
            }
            
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon1],analysisTree.muon_phi[indexMuon1],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nDoubleMuon_4_FilterLeg1] && analysisTree.muon_pt[indexMuon1] > doubleMuonLeg1TriggerPtCut_4)
                    isMuon1DoubleMuon_4_Leg1Matched = true;
            }
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon1],analysisTree.muon_phi[indexMuon1],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nDoubleMuon_4_FilterLeg2] && analysisTree.muon_pt[indexMuon1] > doubleMuonLeg2TriggerPtCut_4)
                    isMuon1DoubleMuon_4_Leg2Matched = true;
            }
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon2],analysisTree.muon_phi[indexMuon2],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nDoubleMuon_4_FilterLeg1] && analysisTree.muon_pt[indexMuon2] > doubleMuonLeg1TriggerPtCut_4)
                    isMuon2DoubleMuon_4_Leg1Matched = true;
            }
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon2],analysisTree.muon_phi[indexMuon2],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nDoubleMuon_4_FilterLeg2] && analysisTree.muon_pt[indexMuon2] > doubleMuonLeg2TriggerPtCut_4)
                    isMuon2DoubleMuon_4_Leg2Matched = true;
            }
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon1],analysisTree.muon_phi[indexMuon1],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nDoubleMuon_4_FilterDz])
                    isMuon1DoubleMuon_4_dzMatched = true;
            }
            for (unsigned int iT=0; iT<analysisTree.trigobject_count; ++iT)
            {
                float dRtrig = deltaR(analysisTree.muon_eta[indexMuon2],analysisTree.muon_phi[indexMuon2],analysisTree.trigobject_eta[iT],analysisTree.trigobject_phi[iT]);
                if (dRtrig>DRTrigMatch) continue;
                if (analysisTree.trigobject_filters[iT][nDoubleMuon_4_FilterDz])
                    isMuon2DoubleMuon_4_dzMatched = true;
            }
            
            //check which muon matching which trigger
            if((isMuon1SingleMuon_1_a_Matched || isMuon1SingleMuon_1_b_Matched) || (isMuon2SingleMuon_1_a_Matched || isMuon2SingleMuon_1_b_Matched))
                isSingleMuon_1_TriggerFilterMatched = true;
            if(isMuon1SingleMuon_2_Matched || isMuon2SingleMuon_2_Matched)
                isSingleMuon_2_TriggerFilterMatched = true;
            
            if((isMuon1SingleMuon_1_a_Matched || isMuon1SingleMuon_1_b_Matched) || isMuon1SingleMuon_2_Matched)
                isMuon1SingleMuonMatched = true;
            if((isMuon2SingleMuon_1_a_Matched || isMuon2SingleMuon_1_b_Matched) || isMuon2SingleMuon_2_Matched)
                isMuon2SingleMuonMatched = true;
            
            if(era == "2016")
            {
                if(isMuon1DoubleMuon_3_Leg1Matched && (isMuon2DoubleMuon_3_Leg2_a_Matched || isMuon2DoubleMuon_3_Leg2_b_Matched) && isMuon1DoubleMuon_3_dzMatched && isMuon2DoubleMuon_3_dzMatched)
                    isDoubleMuon_3_TriggerFilterMatched = true;
            }
            else
            {
                if(isMuon1DoubleMuon_3_Leg1Matched && (isMuon2DoubleMuon_3_Leg2_a_Matched || isMuon2DoubleMuon_3_Leg2_b_Matched) && isMuon1DoubleMuon_3_dzMatched && isMuon2DoubleMuon_3_dzMatched && isMuon1DoubleMuon_3_massMatched && isMuon2DoubleMuon_3_massMatched)
                    isDoubleMuon_3_TriggerFilterMatched = true;
            }
            if(era == "2016")
            {
                if(isMuon2DoubleMuon_3_Leg1Matched && (isMuon1DoubleMuon_3_Leg2_a_Matched || isMuon1DoubleMuon_3_Leg2_b_Matched) && isMuon1DoubleMuon_3_dzMatched && isMuon2DoubleMuon_3_dzMatched)
                    isDoubleMuon_3_TriggerFilterMatched = true;
            }
            else
            {
                if(isMuon2DoubleMuon_3_Leg1Matched && (isMuon1DoubleMuon_3_Leg2_a_Matched || isMuon1DoubleMuon_3_Leg2_b_Matched) && isMuon1DoubleMuon_3_dzMatched && isMuon2DoubleMuon_3_dzMatched && isMuon1DoubleMuon_3_massMatched && isMuon2DoubleMuon_3_massMatched)
                    isDoubleMuon_3_TriggerFilterMatched = true;
            }
            if(isMuon1DoubleMuon_4_Leg1Matched && isMuon2DoubleMuon_4_Leg2Matched && isMuon1DoubleMuon_4_dzMatched && isMuon2DoubleMuon_4_dzMatched)
                isDoubleMuon_4_TriggerFilterMatched = true;
                
            if(isMuon2DoubleMuon_4_Leg1Matched && isMuon1DoubleMuon_4_Leg2Matched && isMuon1DoubleMuon_4_dzMatched && isMuon2DoubleMuon_4_dzMatched)
                isDoubleMuon_4_TriggerFilterMatched = true;
                
            //
            if (applySingleMuTriggerOnly == true)//this setting is for switching on and off single electron trigger
            {
                if((era == "2018") || (era == "2017"))
                {
                    if(isSingleMuon_1_TriggerFilterMatched == true)
                        isSingleMuonTriggerFilterMatched = true;
                }
                if(era == "2016")
                {
                    if((isSingleMuon_1_TriggerFilterMatched == true) || (isSingleMuon_2_TriggerFilterMatched == true))
                        isSingleMuonTriggerFilterMatched = true;
                }
                if(isSingleMuonTriggerFilterMatched == false)
                    continue;
            }
            else//"OR" double trigger apply
            {
                if((era == "2018") || (era == "2017"))
                {
                    if(isSingleMuon_1_TriggerFilterMatched == true)
                        isSingleMuonTriggerFilterMatched = true;
                        
                    if (isDoubleMuon_3_TriggerFilterMatched == true)
                        isDoubleMuonTriggerFilterMatched = true;
                    
                    if((isSingleMuonTriggerFilterMatched==false) && (isDoubleMuonTriggerFilterMatched==false))
                        continue;
                }
                if(era == "2016")
                {
                    if((isSingleMuon_1_TriggerFilterMatched==true) || (isSingleMuon_2_TriggerFilterMatched==true))
                        isSingleMuonTriggerFilterMatched = true;
                    
                    if((isDoubleMuon_3_TriggerFilterMatched==true) || (isDoubleMuon_4_TriggerFilterMatched==true))
                        isDoubleMuonTriggerFilterMatched = true;
                    
                    if ((isSingleMuonTriggerFilterMatched==false) && (isDoubleMuonTriggerFilterMatched==false) )
                    continue;
                }
            }
	    /*
	    cout<<endl<<"isSingleMuonTriggerFilterMatched="<<isSingleMuonTriggerFilterMatched<<endl<<"isMuon1SingleMuonMatched="<<isMuon1SingleMuonMatched<<endl<<"isMuon2SingleMuonMatched="<<isMuon2SingleMuonMatched<<endl;
	    cout<<endl<<"muonTrigSF_1="<<muonTrigSF_1<<endl<<"muonTrigSF_2="<<muonTrigSF_2<<endl;
	    */

	    for_mmm_muonTrigSF_1 = 1.0;
	    for_mmm_muonTrigSF_2 = 1.0;

	    if(!isData){
	      if(isSingleMuonTriggerFilterMatched && isMuon1SingleMuonMatched)
		for_mmm_muonTrigSF_1 = (float)SF_muonTrig->get_ScaleFactor(double(analysisTree.muon_pt[indexMuon1]),double(analysisTree.muon_eta[indexMuon1]));

	      if(isSingleMuonTriggerFilterMatched && isMuon2SingleMuonMatched)
		for_mmm_muonTrigSF_2 = (float)SF_muonTrig->get_ScaleFactor(double(analysisTree.muon_pt[indexMuon2]),double(analysisTree.muon_eta[indexMuon2]));
	    }
	    //	    cout<<endl<<"muonTrigSF_1="<<muonTrigSF_1<<endl<<"muonTrigSF_2="<<muonTrigSF_2<<endl;

        }



      }//if(loosestMuons.size() >= 3 && idisoEles.size() <= 0 && idisoMuons.size() <= 3 && goodTaus.size() == 0){


      if(!is_eee && !is_eem && !is_mme && !is_mmm) continue;
        
      //met                                                                                                                                 
      float met = TMath::Sqrt(analysisTree.pfmetcorr_ex*analysisTree.pfmetcorr_ex + analysisTree.pfmetcorr_ey*analysisTree.pfmetcorr_ey);
      float metphi = analysisTree.pfmetcorr_phi;

        
        ////////////////////////////////////////////////////////////
        // Zpt reweighting
        ////////////////////////////////////////////////////////////
        TLorentzVector genV( 0., 0., 0., 0.);
        TLorentzVector genL( 0., 0., 0., 0.);
        UInt_t njetshad = analysisTree.pfjet_count;
        zptweight = 1.;
        
        if (!isData && applyRecoilCorrections && isDY ){
            genV = genTools::genV(analysisTree);
            genL = genTools::genL(analysisTree);
            
            float met_rcmr = met;
            float metphi_rcmr = metphi;
            // PF MET
            genTools::RecoilCorrections( *recoilPFMetCorrector,
                                        (!isData && applyRecoilCorrections && isDY ) * genTools::MeanResolution,
                                        met, metphi,
                                        genV.Px(), genV.Py(),
                                        genL.Px(), genL.Py(),
                                        njetshad,
                                        met_rcmr, metphi_rcmr
                                        );
            met=met_rcmr;
            metphi=metphi_rcmr;
            
            float bosonMass = genV.M();
            float bosonPt = genV.Pt();
            Float_t zptmassweight = 1;
            if (bosonMass>50.0) {
                float maxmass = h_zptweight->GetXaxis()->GetXmax();
                float maxpt = h_zptweight->GetYaxis()->GetXmax();
                float minmass = h_zptweight->GetXaxis()->GetXmin();
                float minpt = h_zptweight->GetYaxis()->GetXmin();
                float _bosonMass = bosonMass;
                float _bosonPt = bosonPt;
                if(bosonMass>maxmass) _bosonMass=maxmass;
                else if(bosonMass<minmass) _bosonMass=minmass;
                if(bosonPt>maxpt) _bosonPt = maxpt;
                else if(bosonPt<minpt) _bosonPt = minpt;
                zptmassweight = h_zptweight->GetBinContent(h_zptweight->GetXaxis()->FindBin(_bosonMass),
                                                           h_zptweight->GetYaxis()->FindBin(_bosonPt));
            }
            zptweight =zptmassweight;
        }

        
      SynTree->Fill();
      selEvents++;
    } // end of file processing (loop over events in one file)
    good_evts.close();
    nFiles++;
    delete _tree;
    file_->Close();
    delete file_;
  }
  
  file->Write();
  file->Close();
  delete file;
  
}
