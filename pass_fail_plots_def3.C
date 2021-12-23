void pass_fail_plots_def3(){
  TString samples[39] = {"EGamma",//0
			 "SingleMuon",//1
			 "DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8", //2
			 "DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8",//3
			 "DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8",//4
			 "DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8",//5
			 "DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8",//6
			 "DY1JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8",//7
			 "DY2JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8",//8
			 "DY3JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8",//9
			 "DY4JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8",//10
			 "GluGluHToTauTau_M125_13TeV_powheg_pythia8",//11
			 "ttHToTauTau_M125_TuneCP5_13TeV-powheg-pythia8",//12
			 "GluGluHToWWTo2L2Nu_M125_13TeV_powheg2_JHUGenV714_pythia8",//13
			 "GluGluToContinToZZTo2e2mu_13TeV_TuneCP5_MCFM701_pythia8",//14
			 "GluGluToContinToZZTo2e2tau_13TeV_TuneCP5_MCFM701_pythia8",//15
			 "GluGluToContinToZZTo2mu2tau_13TeV_TuneCP5_MCFM701_pythia8",//16
			 "GluGluToContinToZZTo4e_13TeV_TuneCP5_MCFM701_pythia8",//17
			 "GluGluToContinToZZTo4mu_13TeV_TuneCP5_MCFM701_pythia8",//18
			 "GluGluToContinToZZTo4tau_13TeV_TuneCP5_MCFM701_pythia8",//19
			 "HZJ_HToWW_M125_13TeV_powheg_jhugen714_pythia8_TuneCP5",//20
			 "TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8",//21
			 "TTToHadronic_TuneCP5_13TeV-powheg-pythia8",//22
			 "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8",//23
			 "TTWJetsToLNu_TuneCP5_PSweights_13TeV-amcatnloFXFX-madspin-pythia8",//24
			 "ttZJets_TuneCP5_13TeV_madgraphMLM_pythia8",//25
			 "VBFHToTauTau_M125_13TeV_powheg_pythia8",//26
			 "VBFHToWWTo2L2Nu_M125_13TeV_powheg2_JHUGenV714_pythia8",//27
			 "WminusHToTauTau_M125_13TeV_powheg_pythia8",//28
			 "WplusHToTauTau_M125_13TeV_powheg_pythia8",//29
			 "WWW_4F_TuneCP5_13TeV-amcatnlo-pythia8",//30
			 "WWZ_TuneCP5_13TeV-amcatnlo-pythia8",//31
			 "WZTo3LNu_TuneCP5_13TeV-amcatnloFXFX-pythia8",//32
			 "WZZ_TuneCP5_13TeV-amcatnlo-pythia8",//33
			 "WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8",//34
			 "ZHToTauTau_M125_13TeV_powheg_pythia8",//35
			 "ZZTo4L_TuneCP5_13TeV_powheg_pythia8",//36
			 "ZZZ_TuneCP5_13TeV-amcatnlo-pythia8",//37
			 "ZZTo2L2Q" //38
			 //"HWminusJ_HToWW_M125_13TeV_powheg_jhugen724_pythia8_TuneCP5",//19
			 //"HWplusJ_HToWW_M125_13TeV_powheg_jhugen724_pythia8_TuneCP5",//20

  }; 

  double xsec[39] = {                                                                                                                   

    1, // (0)EGamma
    1, // (1)SingleMuon 
    6077.22,// (2)Drell-Yan Z
    6077.22,// (3)Drell-Yan Z
    6077.22,// (4)Drell-Yan Z
    6077.22,// (5)Drell-Yan Z
    6077.22,// (6)Drell-Yan Z
    1.137*877.8, //7  DY1
    1.137*304.4, //8  DY2
    1.137*111.5, //9  DY3
    1.137*44.05, //10  DY4
    48.58*0.0627, //11   GluGluHToTauTau_M125_13TeV_powheg_pythia8
    0.507*0.0627, //12   "ttHToTauTau_M125_TuneCP5_13TeV-powheg-pythia8",
    48.58*0.2137*0.1061, //13   "GluGluHToWWTo2L2Nu_M125_13TeV_powheg2_JHUGenV714_pythia8",
    0.00319*1.7, //14   "GluGluToContinToZZTo2e2mu_13TeV_TuneCP5_MCFM701_pythia8",
    0.00319*1.7, //15   "GluGluToContinToZZTo2e2tau_13TeV_TuneCP5_MCFM701_pythia8",
    0.00319*1.7,//16   "GluGluToContinToZZTo2mu2tau_13TeV_TuneCP5_MCFM701_pythia8",
    0.00159*1.7,//17    "GluGluToContinToZZTo4e_13TeV_TuneCP5_MCFM701_pythia8",
    0.00159*1.7,//18    "GluGluToContinToZZTo4mu_13TeV_TuneCP5_MCFM701_pythia8",
    0.00159*1.7,//19    "GluGluToContinToZZTo4tau_13TeV_TuneCP5_MCFM701_pythia8",
    0.02005,//20   "HZJ_HToWW_M125_13TeV_powheg_jhugen714_pythia8_TuneC",
    88.29,//21   "TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8",
    377.96, //22    "TTToHadronic_TuneCP5_13TeV-powheg-pythia8",
    365.35,//23    "TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8",
    0.2043,//24   "TTWJetsToLNu_TuneCP5_PSweights_13TeV-amcatnloFXFX-madspin-pythia8",
    0.2529,//25    "ttZJets_TuneCP5_13TeV_madgraphMLM_pythia8",
    3.782*0.0627,//26    "VBFHToTauTau_M125_13TeV_powheg_pythia8",
    3.925*0.2137*0.1061,//27    "VBFHToWWTo2L2Nu_M125_13TeV_powheg2_JHUGenV714_pythia8",
    0.5328*0.0627,//28    "WminusHToTauTau_M125_13TeV_powheg_pythia8",
    0.8400*0.0627,//29    "WplusHToTauTau_M125_13TeV_powheg_pythia8",
    0.2086,//30    "WWW_4F_TuneCP5_13TeV-amcatnlo-pythia8",
    0.1651,//31    "WWZ_TuneCP5_13TeV-amcatnlo-pythia8",
    4.708,//32    "WZTo3LNu_TuneCP5_13TeV-amcatnloFXFX-pythia8",
    0.05565,//33    "WZZ_TuneCP5_13TeV-amcatnlo-pythia8",
    5.595,//34 WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8
    0.884*0.0627,//35    "ZHToTauTau_M125_13TeV_powheg_pythia8",
    1.256*1.1,//36    "ZZTo4L_TuneCP5_13TeV_powheg_pythia8",
    0.01398,//37    "ZZZ_TuneCP5_13TeV-amcatnlo-pythia8"
    3.22 //38 ZZTo2L2Q
    //0.01209,//19   "HWminusJ_HToWW_M125_13TeV_powheg_jhugen724_pythia8_TuneCP5",
    //0.01905,//20   "HWplusJ_HToWW_M125_13TeV_powheg_jhugen724_pythia8_TuneCP5",

  };                                                                                                                         

  Double_t weights[39];

  for(int is = 0; is < 39; is++){
    TFile* f = new TFile(samples[is]+".root","open");
    TH1D * histWeightsH = (TH1D*)f->Get("histWeightsH");
    weights[is] = histWeightsH->GetSumOfWeights();
    f->Close();
  }//  for(int is = 0; is < 38; is++){

  ofstream out;
  out.open("out_mine.txt");

  float luminosity = 59700;
  for(int is =0;is<39;is++){

    cout<<endl<<"processing "<<samples[is]<<endl;
    TFile* f_out = new TFile("./pass_fail_files/plots_"+samples[is]+"_"+to_string(is)+".root","recreate");

    //    if(is==0){

    Float_t pt_e_bins[4] = {10,30,50,70};
    TH1F* pt_ele_pass_barrel_data = new TH1F("pt_ele_pass_barrel_data","pt_ele_pass_barrel_data",3,pt_e_bins);
    TH1F* pt_ele_pass_endcap_data = new TH1F("pt_ele_pass_endcap_data","pt_ele_pass_endcap_data",3,pt_e_bins);
    TH1F* pt_ele_fail_barrel_data = new TH1F("pt_ele_fail_barrel_data","pt_ele_fail_barrel_data",3,pt_e_bins);
    TH1F* pt_ele_fail_endcap_data = new TH1F("pt_ele_fail_endcap_data","pt_ele_fail_endcap_data",3,pt_e_bins);

    Float_t pt_m_bins[4] = {10,30,50,70};
    TH1F* pt_muon_pass_barrel_data = new TH1F("pt_muon_pass_barrel_data","pt_muon_pass_barrel_data",3,pt_m_bins);
    TH1F* pt_muon_pass_endcap_data = new TH1F("pt_muon_pass_endcap_data","pt_muon_pass_endcap_data",3,pt_m_bins);
    TH1F* pt_muon_fail_barrel_data = new TH1F("pt_muon_fail_barrel_data","pt_muon_fail_barrel_data",3,pt_m_bins);
    TH1F* pt_muon_fail_endcap_data = new TH1F("pt_muon_fail_endcap_data","pt_muon_fail_endcap_data",3,pt_m_bins);


    //mt histograms

    TH1F* mt_ele_pass_Pt10To30_barrel_data = new TH1F("mt_ele_pass_Pt10To30_barrel_data","mt_ele_pass_Pt10To30_barrel_data",10,0.0,100.0);
    TH1F* mt_ele_pass_Pt10To30_endcap_data = new TH1F("mt_ele_pass_Pt10To30_endcap_data","mt_ele_pass_Pt10To30_endcap_data",10,0.0,100.0);
    TH1F* mt_ele_pass_Pt30To50_barrel_data = new TH1F("mt_ele_pass_Pt30To50_barrel_data","mt_ele_pass_Pt30To50_barrel_data",10,0.0,100.0);
    TH1F* mt_ele_pass_Pt30To50_endcap_data = new TH1F("mt_ele_pass_Pt30To50_endcap_data","mt_ele_pass_Pt30To50_endcap_data",10,0.0,100.0);
    TH1F* mt_ele_pass_Pt50To70_barrel_data = new TH1F("mt_ele_pass_Pt50To70_barrel_data","mt_ele_pass_Pt50To70_barrel_data",10,0.0,100.0);
    TH1F* mt_ele_pass_Pt50To70_endcap_data = new TH1F("mt_ele_pass_Pt50To70_endcap_data","mt_ele_pass_Pt50To70_endcap_data",10,0.0,100.0);
    TH1F* mt_ele_fail_Pt10To30_barrel_data = new TH1F("mt_ele_fail_Pt10To30_barrel_data","mt_ele_fail_Pt10To30_barrel_data",10,0.0,100.0);
    TH1F* mt_ele_fail_Pt10To30_endcap_data = new TH1F("mt_ele_fail_Pt10To30_endcap_data","mt_ele_fail_Pt10To30_endcap_data",10,0.0,100.0);
    TH1F* mt_ele_fail_Pt30To50_barrel_data = new TH1F("mt_ele_fail_Pt30To50_barrel_data","mt_ele_fail_Pt30To50_barrel_data",10,0.0,100.0);
    TH1F* mt_ele_fail_Pt30To50_endcap_data = new TH1F("mt_ele_fail_Pt30To50_endcap_data","mt_ele_fail_Pt30To50_endcap_data",10,0.0,100.0);
    TH1F* mt_ele_fail_Pt50To70_barrel_data = new TH1F("mt_ele_fail_Pt50To70_barrel_data","mt_ele_fail_Pt50To70_barrel_data",10,0.0,100.0);
    TH1F* mt_ele_fail_Pt50To70_endcap_data = new TH1F("mt_ele_fail_Pt50To70_endcap_data","mt_ele_fail_Pt50To70_endcap_data",10,0.0,100.0);


    TH1F* mt_muon_pass_Pt10To30_barrel_data = new TH1F("mt_muon_pass_Pt10To30_barrel_data","mt_muon_pass_Pt10To30_barrel_data",10,0.0,100.0);
    TH1F* mt_muon_pass_Pt10To30_endcap_data = new TH1F("mt_muon_pass_Pt10To30_endcap_data","mt_muon_pass_Pt10To30_endcap_data",10,0.0,100.0);
    TH1F* mt_muon_pass_Pt30To50_barrel_data = new TH1F("mt_muon_pass_Pt30To50_barrel_data","mt_muon_pass_Pt30To50_barrel_data",10,0.0,100.0);
    TH1F* mt_muon_pass_Pt30To50_endcap_data = new TH1F("mt_muon_pass_Pt30To50_endcap_data","mt_muon_pass_Pt30To50_endcap_data",10,0.0,100.0);
    TH1F* mt_muon_pass_Pt50To70_barrel_data = new TH1F("mt_muon_pass_Pt50To70_barrel_data","mt_muon_pass_Pt50To70_barrel_data",10,0.0,100.0);
    TH1F* mt_muon_pass_Pt50To70_endcap_data = new TH1F("mt_muon_pass_Pt50To70_endcap_data","mt_muon_pass_Pt50To70_endcap_data",10,0.0,100.0);
    TH1F* mt_muon_fail_Pt10To30_barrel_data = new TH1F("mt_muon_fail_Pt10To30_barrel_data","mt_muon_fail_Pt10To30_barrel_data",10,0.0,100.0);
    TH1F* mt_muon_fail_Pt10To30_endcap_data = new TH1F("mt_muon_fail_Pt10To30_endcap_data","mt_muon_fail_Pt10To30_endcap_data",10,0.0,100.0);
    TH1F* mt_muon_fail_Pt30To50_barrel_data = new TH1F("mt_muon_fail_Pt30To50_barrel_data","mt_muon_fail_Pt30To50_barrel_data",10,0.0,100.0);
    TH1F* mt_muon_fail_Pt30To50_endcap_data = new TH1F("mt_muon_fail_Pt30To50_endcap_data","mt_muon_fail_Pt30To50_endcap_data",10,0.0,100.0);
    TH1F* mt_muon_fail_Pt50To70_barrel_data = new TH1F("mt_muon_fail_Pt50To70_barrel_data","mt_muon_fail_Pt50To70_barrel_data",10,0.0,100.0);
    TH1F* mt_muon_fail_Pt50To70_endcap_data = new TH1F("mt_muon_fail_Pt50To70_endcap_data","mt_muon_fail_Pt50To70_endcap_data",10,0.0,100.0);
    //    }

    //    if(is>0){
    //      Float_t pt_e_bins[4] = {10,20,40,60};
    TH1F* pt_ele_pass_barrel_prompt = new TH1F("pt_ele_pass_barrel_prompt","pt_ele_pass_barrel_prompt",3,pt_e_bins);
    TH1F* pt_ele_pass_barrel_fake = new TH1F("pt_ele_pass_barrel_fake","pt_ele_pass_barrel_fake",3,pt_e_bins);
    TH1F* pt_ele_pass_endcap_prompt = new TH1F("pt_ele_pass_endcap_prompt","pt_ele_pass_endcap_prompt",3,pt_e_bins);
    TH1F* pt_ele_pass_endcap_fake = new TH1F("pt_ele_pass_endcap_fake","pt_ele_pass_endcap_fake",3,pt_e_bins);
    TH1F* pt_ele_fail_barrel_prompt = new TH1F("pt_ele_fail_barrel_prompt","pt_ele_fail_barrel_prompt",3,pt_e_bins);
    TH1F* pt_ele_fail_barrel_fake = new TH1F("pt_ele_fail_barrel_fake","pt_ele_fail_barrel_fake",3,pt_e_bins);
    TH1F* pt_ele_fail_endcap_prompt = new TH1F("pt_ele_fail_endcap_prompt","pt_ele_fail_endcap_prompt",3,pt_e_bins);
    TH1F* pt_ele_fail_endcap_fake = new TH1F("pt_ele_fail_endcap_fake","pt_ele_fail_endcap_fake",3,pt_e_bins);

    //      Float_t pt_m_bins[5] = {10,20,30,40,60};
    TH1F* pt_muon_pass_barrel_prompt = new TH1F("pt_muon_pass_barrel_prompt","pt_muon_pass_barrel_prompt",3,pt_m_bins);
    TH1F* pt_muon_pass_barrel_fake = new TH1F("pt_muon_pass_barrel_fake","pt_muon_pass_barrel_fake",3,pt_m_bins);
    TH1F* pt_muon_pass_endcap_prompt = new TH1F("pt_muon_pass_endcap_prompt","pt_muon_pass_endcap_prompt",3,pt_m_bins);
    TH1F* pt_muon_pass_endcap_fake = new TH1F("pt_muon_pass_endcap_fake","pt_muon_pass_endcap_fake",3,pt_m_bins);
    TH1F* pt_muon_fail_barrel_prompt = new TH1F("pt_muon_fail_barrel_prompt","pt_muon_fail_barrel_prompt",3,pt_m_bins);
    TH1F* pt_muon_fail_barrel_fake = new TH1F("pt_muon_fail_barrel_fake","pt_muon_fail_barrel_fake",3,pt_m_bins);
    TH1F* pt_muon_fail_endcap_prompt = new TH1F("pt_muon_fail_endcap_prompt","pt_muon_fail_endcap_prompt",3,pt_m_bins);
    TH1F* pt_muon_fail_endcap_fake = new TH1F("pt_muon_fail_endcap_fake","pt_muon_fail_endcap_fake",3,pt_m_bins);

    //mt histograms

    TH1F* mt_ele_pass_Pt10To30_barrel_prompt = new TH1F("mt_ele_pass_Pt10To30_barrel_prompt","mt_ele_pass_Pt10To30_barrel_prompt",10,0.0,100.0);
    TH1F* mt_ele_pass_Pt10To30_barrel_fake = new TH1F("mt_ele_pass_Pt10To30_barrel_fake","mt_ele_pass_Pt10To30_barrel_fake",10,0.0,100.0);
    TH1F* mt_ele_pass_Pt10To30_endcap_prompt = new TH1F("mt_ele_pass_Pt10To30_endcap_prompt","mt_ele_pass_Pt10To30_endcap_prompt",10,0.0,100.0);
    TH1F* mt_ele_pass_Pt10To30_endcap_fake = new TH1F("mt_ele_pass_Pt10To30_endcap_fake","mt_ele_pass_Pt10To30_endcap_fake",10,0.0,100.0);
    TH1F* mt_ele_pass_Pt30To50_barrel_prompt = new TH1F("mt_ele_pass_Pt30To50_barrel_prompt","mt_ele_pass_Pt30To50_barrel_prompt",10,0.0,100.0);
    TH1F* mt_ele_pass_Pt30To50_barrel_fake = new TH1F("mt_ele_pass_Pt30To50_barrel_fake","mt_ele_pass_Pt30To50_barrel_fake",10,0.0,100.0);
    TH1F* mt_ele_pass_Pt30To50_endcap_prompt = new TH1F("mt_ele_pass_Pt30To50_endcap_prompt","mt_ele_pass_Pt30To50_endcap_prompt",10,0.0,100.0);
    TH1F* mt_ele_pass_Pt30To50_endcap_fake = new TH1F("mt_ele_pass_Pt30To50_endcap_fake","mt_ele_pass_Pt30To50_endcap_fake",10,0.0,100.0);
    TH1F* mt_ele_pass_Pt50To70_barrel_prompt = new TH1F("mt_ele_pass_Pt50To70_barrel_prompt","mt_ele_pass_Pt50To70_barrel_prompt",10,0.0,100.0);
    TH1F* mt_ele_pass_Pt50To70_barrel_fake = new TH1F("mt_ele_pass_Pt50To70_barrel_fake","mt_ele_pass_Pt50To70_barrel_fake",10,0.0,100.0);
    TH1F* mt_ele_pass_Pt50To70_endcap_prompt = new TH1F("mt_ele_pass_Pt50To70_endcap_prompt","mt_ele_pass_Pt50To70_endcap_prompt",10,0.0,100.0);
    TH1F* mt_ele_pass_Pt50To70_endcap_fake = new TH1F("mt_ele_pass_Pt50To70_endcap_fake","mt_ele_pass_Pt50To70_endcap_fake",10,0.0,100.0);
    TH1F* mt_ele_fail_Pt10To30_barrel_prompt = new TH1F("mt_ele_fail_Pt10To30_barrel_prompt","mt_ele_fail_Pt10To30_barrel_prompt",10,0.0,100.0);
    TH1F* mt_ele_fail_Pt10To30_barrel_fake = new TH1F("mt_ele_fail_Pt10To30_barrel_fake","mt_ele_fail_Pt10To30_barrel_fake",10,0.0,100.0);
    TH1F* mt_ele_fail_Pt10To30_endcap_prompt = new TH1F("mt_ele_fail_Pt10To30_endcap_prompt","mt_ele_fail_Pt10To30_endcap_prompt",10,0.0,100.0);
    TH1F* mt_ele_fail_Pt10To30_endcap_fake = new TH1F("mt_ele_fail_Pt10To30_endcap_fake","mt_ele_fail_Pt10To30_endcap_fake",10,0.0,100.0);
    TH1F* mt_ele_fail_Pt30To50_barrel_prompt = new TH1F("mt_ele_fail_Pt30To50_barrel_prompt","mt_ele_fail_Pt30To50_barrel_prompt",10,0.0,100.0);
    TH1F* mt_ele_fail_Pt30To50_barrel_fake = new TH1F("mt_ele_fail_Pt30To50_barrel_fake","mt_ele_fail_Pt30To50_barrel_fake",10,0.0,100.0);
    TH1F* mt_ele_fail_Pt30To50_endcap_prompt = new TH1F("mt_ele_fail_Pt30To50_endcap_prompt","mt_ele_fail_Pt30To50_endcap_prompt",10,0.0,100.0);
    TH1F* mt_ele_fail_Pt30To50_endcap_fake = new TH1F("mt_ele_fail_Pt30To50_endcap_fake","mt_ele_fail_Pt30To50_endcap_fake",10,0.0,100.0);
    TH1F* mt_ele_fail_Pt50To70_barrel_prompt = new TH1F("mt_ele_fail_Pt50To70_barrel_prompt","mt_ele_fail_Pt50To70_barrel_prompt",10,0.0,100.0);
    TH1F* mt_ele_fail_Pt50To70_barrel_fake = new TH1F("mt_ele_fail_Pt50To70_barrel_fake","mt_ele_fail_Pt50To70_barrel_fake",10,0.0,100.0);
    TH1F* mt_ele_fail_Pt50To70_endcap_prompt = new TH1F("mt_ele_fail_Pt50To70_endcap_prompt","mt_ele_fail_Pt50To70_endcap_prompt",10,0.0,100.0);
    TH1F* mt_ele_fail_Pt50To70_endcap_fake = new TH1F("mt_ele_fail_Pt50To70_endcap_fake","mt_ele_fail_Pt50To70_endcap_fake",10,0.0,100.0);



    TH1F* mt_muon_pass_Pt10To30_barrel_prompt = new TH1F("mt_muon_pass_Pt10To30_barrel_prompt","mt_muon_pass_Pt10To30_barrel_prompt",10,0.0,100.0);
    TH1F* mt_muon_pass_Pt10To30_barrel_fake = new TH1F("mt_muon_pass_Pt10To30_barrel_fake","mt_muon_pass_Pt10To30_barrel_fake",10,0.0,100.0);
    TH1F* mt_muon_pass_Pt10To30_endcap_prompt = new TH1F("mt_muon_pass_Pt10To30_endcap_prompt","mt_muon_pass_Pt10To30_endcap_prompt",10,0.0,100.0);
    TH1F* mt_muon_pass_Pt10To30_endcap_fake = new TH1F("mt_muon_pass_Pt10To30_endcap_fake","mt_muon_pass_Pt10To30_endcap_fake",10,0.0,100.0);
    TH1F* mt_muon_pass_Pt30To50_barrel_prompt = new TH1F("mt_muon_pass_Pt30To50_barrel_prompt","mt_muon_pass_Pt30To50_barrel_prompt",10,0.0,100.0);
    TH1F* mt_muon_pass_Pt30To50_barrel_fake = new TH1F("mt_muon_pass_Pt30To50_barrel_fake","mt_muon_pass_Pt30To50_barrel_fake",10,0.0,100.0);
    TH1F* mt_muon_pass_Pt30To50_endcap_prompt = new TH1F("mt_muon_pass_Pt30To50_endcap_prompt","mt_muon_pass_Pt30To50_endcap_prompt",10,0.0,100.0);
    TH1F* mt_muon_pass_Pt30To50_endcap_fake = new TH1F("mt_muon_pass_Pt30To50_endcap_fake","mt_muon_pass_Pt30To50_endcap_fake",10,0.0,100.0);
    TH1F* mt_muon_pass_Pt50To70_barrel_prompt = new TH1F("mt_muon_pass_Pt50To70_barrel_prompt","mt_muon_pass_Pt50To70_barrel_prompt",10,0.0,100.0);
    TH1F* mt_muon_pass_Pt50To70_barrel_fake = new TH1F("mt_muon_pass_Pt50To70_barrel_fake","mt_muon_pass_Pt50To70_barrel_fake",10,0.0,100.0);
    TH1F* mt_muon_pass_Pt50To70_endcap_prompt = new TH1F("mt_muon_pass_Pt50To70_endcap_prompt","mt_muon_pass_Pt50To70_endcap_prompt",10,0.0,100.0);
    TH1F* mt_muon_pass_Pt50To70_endcap_fake = new TH1F("mt_muon_pass_Pt50To70_endcap_fake","mt_muon_pass_Pt50To70_endcap_fake",10,0.0,100.0);
    TH1F* mt_muon_fail_Pt10To30_barrel_prompt = new TH1F("mt_muon_fail_Pt10To30_barrel_prompt","mt_muon_fail_Pt10To30_barrel_prompt",10,0.0,100.0);
    TH1F* mt_muon_fail_Pt10To30_barrel_fake = new TH1F("mt_muon_fail_Pt10To30_barrel_fake","mt_muon_fail_Pt10To30_barrel_fake",10,0.0,100.0);
    TH1F* mt_muon_fail_Pt10To30_endcap_prompt = new TH1F("mt_muon_fail_Pt10To30_endcap_prompt","mt_muon_fail_Pt10To30_endcap_prompt",10,0.0,100.0);
    TH1F* mt_muon_fail_Pt10To30_endcap_fake = new TH1F("mt_muon_fail_Pt10To30_endcap_fake","mt_muon_fail_Pt10To30_endcap_fake",10,0.0,100.0);
    TH1F* mt_muon_fail_Pt30To50_barrel_prompt = new TH1F("mt_muon_fail_Pt30To50_barrel_prompt","mt_muon_fail_Pt30To50_barrel_prompt",10,0.0,100.0);
    TH1F* mt_muon_fail_Pt30To50_barrel_fake = new TH1F("mt_muon_fail_Pt30To50_barrel_fake","mt_muon_fail_Pt30To50_barrel_fake",10,0.0,100.0);
    TH1F* mt_muon_fail_Pt30To50_endcap_prompt = new TH1F("mt_muon_fail_Pt30To50_endcap_prompt","mt_muon_fail_Pt30To50_endcap_prompt",10,0.0,100.0);
    TH1F* mt_muon_fail_Pt30To50_endcap_fake = new TH1F("mt_muon_fail_Pt30To50_endcap_fake","mt_muon_fail_Pt30To50_endcap_fake",10,0.0,100.0);
    TH1F* mt_muon_fail_Pt50To70_barrel_prompt = new TH1F("mt_muon_fail_Pt50To70_barrel_prompt","mt_muon_fail_Pt50To70_barrel_prompt",10,0.0,100.0);
    TH1F* mt_muon_fail_Pt50To70_barrel_fake = new TH1F("mt_muon_fail_Pt50To70_barrel_fake","mt_muon_fail_Pt50To70_barrel_fake",10,0.0,100.0);
    TH1F* mt_muon_fail_Pt50To70_endcap_prompt = new TH1F("mt_muon_fail_Pt50To70_endcap_prompt","mt_muon_fail_Pt50To70_endcap_prompt",10,0.0,100.0);
    TH1F* mt_muon_fail_Pt50To70_endcap_fake = new TH1F("mt_muon_fail_Pt50To70_endcap_fake","mt_muon_fail_Pt50To70_endcap_fake",10,0.0,100.0);
    //    }


    //cout<<endl<<"processing "<<samples[is]<<endl;
    TFile* f = new TFile(samples[is]+".root","open");
    TTree* SynTree = (TTree*)f->Get("SynTree");
    //cout<<endl<<samples[is]<<endl<<histWeightsH->GetSumOfWeights()<<endl;

    ULong64_t run;
    UInt_t lumi;
    ULong64_t evt;

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
    Bool_t for_eem_mu_1_id = false; //
    Float_t for_eem_mu_2_iso = -99; //
    Bool_t for_eem_mu_2_id = false; //
    Float_t for_eem_m_E1_fake_elec = -99;
    Float_t for_eem_m_E2_fake_elec = -99;
    Float_t for_eem_m_EE = -99;
    Float_t for_eem_pfmt_fake_electron = -99;
    Float_t for_eem_fake_muon_iso = -99;
    Bool_t for_eem_fake_muon_id = false;
    Float_t for_eem_m_3l = -99;
    Float_t for_eem_pfmt_fake_muon = -99;
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


    
    SynTree->SetBranchAddress("run",&run);
    SynTree->SetBranchAddress("lumi",&lumi);
    SynTree->SetBranchAddress("evt",&evt);
    
    SynTree->SetBranchAddress("is_eee",&is_eee);
    SynTree->SetBranchAddress("is_eem",&is_eem);
    SynTree->SetBranchAddress("is_mme",&is_mme);
    SynTree->SetBranchAddress("is_mmm",&is_mmm);

    SynTree->SetBranchAddress("npartons",&npartons);
    SynTree->SetBranchAddress("mcweight",&mcweight);
    SynTree->SetBranchAddress("puweight", &puweight);
    SynTree->SetBranchAddress("zptweight", &zptweight);


    //New branches for FR measurement
    SynTree->SetBranchAddress("for_eee_fake_ele_iso",&for_eee_fake_ele_iso);
    SynTree->SetBranchAddress("for_eee_fake_ele_id",&for_eee_fake_ele_id);
    SynTree->SetBranchAddress("for_eee_ele_1_iso",&for_eee_ele_1_iso);
    SynTree->SetBranchAddress("for_eee_ele_1_id",&for_eee_ele_1_id);
    SynTree->SetBranchAddress("for_eee_ele_2_iso",&for_eee_ele_2_iso);
    SynTree->SetBranchAddress("for_eee_ele_2_id",&for_eee_ele_2_id);
    SynTree->SetBranchAddress("for_eee_mu_1_iso",&for_eee_mu_1_iso);
    SynTree->SetBranchAddress("for_eee_mu_1_id",&for_eee_mu_1_id);
    SynTree->SetBranchAddress("for_eee_mu_2_iso",&for_eee_mu_2_iso);
    SynTree->SetBranchAddress("for_eee_mu_2_id",&for_eee_mu_2_id);
    SynTree->SetBranchAddress("for_eee_m_E1_fake_elec",&for_eee_m_E1_fake_elec);
    SynTree->SetBranchAddress("for_eee_m_E2_fake_elec",&for_eee_m_E2_fake_elec);
    SynTree->SetBranchAddress("for_eee_pfmt_fake_electron",&for_eee_pfmt_fake_electron);
    SynTree->SetBranchAddress("for_eee_fake_muon_iso",&for_eee_fake_muon_iso);
    SynTree->SetBranchAddress("for_eee_fake_muon_id",&for_eee_fake_muon_id);
    SynTree->SetBranchAddress("for_eee_m_3l",&for_eee_m_3l);
    SynTree->SetBranchAddress("for_eee_pfmt_fake_muon",&for_eee_pfmt_fake_muon);
    SynTree->SetBranchAddress("for_eee_m_M1_fake_elec",&for_eee_m_M1_fake_elec);
    SynTree->SetBranchAddress("for_eee_m_M2_fake_elec",&for_eee_m_M2_fake_elec);
    SynTree->SetBranchAddress("for_eee_fake_ele_eta",&for_eee_fake_ele_eta);
    SynTree->SetBranchAddress("for_eee_fake_muon_eta",&for_eee_fake_muon_eta);
    SynTree->SetBranchAddress("for_eee_m_EE",&for_eee_m_EE);
    SynTree->SetBranchAddress("for_eee_m_MM",&for_eee_m_MM);
    SynTree->SetBranchAddress("for_eee_dR_Z1_fake_lepton",&for_eee_dR_Z1_fake_lepton);
    SynTree->SetBranchAddress("for_eee_dR_Z2_fake_lepton",&for_eee_dR_Z2_fake_lepton);
    SynTree->SetBranchAddress("for_eee_pt_fake_e",&for_eee_pt_fake_e);
    SynTree->SetBranchAddress("for_eee_pt_fake_m",&for_eee_pt_fake_m);
    SynTree->SetBranchAddress("for_eee_gen_match_1",&for_eee_gen_match_1);
    SynTree->SetBranchAddress("for_eee_gen_match_2",&for_eee_gen_match_2);
    SynTree->SetBranchAddress("for_eee_gen_match_3",&for_eee_gen_match_3);
    SynTree->SetBranchAddress("for_eee_electronIDSF_1",&for_eee_electronIDSF_1);
    SynTree->SetBranchAddress("for_eee_electronIDSF_2",&for_eee_electronIDSF_2);
    SynTree->SetBranchAddress("for_eee_electronIDSF_fake",&for_eee_electronIDSF_fake);
    SynTree->SetBranchAddress("for_eee_muonIDSF_1",&for_eee_muonIDSF_1);
    SynTree->SetBranchAddress("for_eee_muonIDSF_2",&for_eee_muonIDSF_2);
    SynTree->SetBranchAddress("for_eee_muonIDSF_fake",&for_eee_muonIDSF_fake);
    SynTree->SetBranchAddress("for_eee_electronTrigSF_1",&for_eee_electronTrigSF_1);
    SynTree->SetBranchAddress("for_eee_electronTrigSF_2",&for_eee_electronTrigSF_2);
    SynTree->SetBranchAddress("for_eee_muonTrigSF_1",&for_eee_muonTrigSF_1);
    SynTree->SetBranchAddress("for_eee_muonTrigSF_2",&for_eee_muonTrigSF_2);

    SynTree->SetBranchAddress("for_eem_fake_ele_iso",&for_eem_fake_ele_iso);
    SynTree->SetBranchAddress("for_eem_fake_ele_id",&for_eem_fake_ele_id);
    SynTree->SetBranchAddress("for_eem_ele_1_iso",&for_eem_ele_1_iso);
    SynTree->SetBranchAddress("for_eem_ele_1_id",&for_eem_ele_1_id);
    SynTree->SetBranchAddress("for_eem_ele_2_iso",&for_eem_ele_2_iso);
    SynTree->SetBranchAddress("for_eem_ele_2_id",&for_eem_ele_2_id);
    SynTree->SetBranchAddress("for_eem_mu_1_iso",&for_eem_mu_1_iso);
    SynTree->SetBranchAddress("for_eem_mu_1_id",&for_eem_mu_1_id);
    SynTree->SetBranchAddress("for_eem_mu_2_iso",&for_eem_mu_2_iso);
    SynTree->SetBranchAddress("for_eem_mu_2_id",&for_eem_mu_2_id);
    SynTree->SetBranchAddress("for_eem_m_E1_fake_elec",&for_eem_m_E1_fake_elec);
    SynTree->SetBranchAddress("for_eem_m_E2_fake_elec",&for_eem_m_E2_fake_elec);
    SynTree->SetBranchAddress("for_eem_pfmt_fake_electron",&for_eem_pfmt_fake_electron);
    SynTree->SetBranchAddress("for_eem_fake_muon_iso",&for_eem_fake_muon_iso);
    SynTree->SetBranchAddress("for_eem_fake_muon_id",&for_eem_fake_muon_id);
    SynTree->SetBranchAddress("for_eem_m_3l",&for_eem_m_3l);
    SynTree->SetBranchAddress("for_eem_pfmt_fake_muon",&for_eem_pfmt_fake_muon);
    SynTree->SetBranchAddress("for_eem_m_M1_fake_elec",&for_eem_m_M1_fake_elec);
    SynTree->SetBranchAddress("for_eem_m_M2_fake_elec",&for_eem_m_M2_fake_elec);
    SynTree->SetBranchAddress("for_eem_fake_ele_eta",&for_eem_fake_ele_eta);
    SynTree->SetBranchAddress("for_eem_fake_muon_eta",&for_eem_fake_muon_eta);
    SynTree->SetBranchAddress("for_eem_m_EE",&for_eem_m_EE);
    SynTree->SetBranchAddress("for_eem_m_MM",&for_eem_m_MM);
    SynTree->SetBranchAddress("for_eem_dR_Z1_fake_lepton",&for_eem_dR_Z1_fake_lepton);
    SynTree->SetBranchAddress("for_eem_dR_Z2_fake_lepton",&for_eem_dR_Z2_fake_lepton);
    SynTree->SetBranchAddress("for_eem_pt_fake_e",&for_eem_pt_fake_e);
    SynTree->SetBranchAddress("for_eem_pt_fake_m",&for_eem_pt_fake_m);
    SynTree->SetBranchAddress("for_eem_gen_match_1",&for_eem_gen_match_1);
    SynTree->SetBranchAddress("for_eem_gen_match_2",&for_eem_gen_match_2);
    SynTree->SetBranchAddress("for_eem_gen_match_3",&for_eem_gen_match_3);
    SynTree->SetBranchAddress("for_eem_electronIDSF_1",&for_eem_electronIDSF_1);
    SynTree->SetBranchAddress("for_eem_electronIDSF_2",&for_eem_electronIDSF_2);
    SynTree->SetBranchAddress("for_eem_electronIDSF_fake",&for_eem_electronIDSF_fake);
    SynTree->SetBranchAddress("for_eem_muonIDSF_1",&for_eem_muonIDSF_1);
    SynTree->SetBranchAddress("for_eem_muonIDSF_2",&for_eem_muonIDSF_2);
    SynTree->SetBranchAddress("for_eem_muonIDSF_fake",&for_eem_muonIDSF_fake);
    SynTree->SetBranchAddress("for_eem_electronTrigSF_1",&for_eem_electronTrigSF_1);
    SynTree->SetBranchAddress("for_eem_electronTrigSF_2",&for_eem_electronTrigSF_2);
    SynTree->SetBranchAddress("for_eem_muonTrigSF_1",&for_eem_muonTrigSF_1);
    SynTree->SetBranchAddress("for_eem_muonTrigSF_2",&for_eem_muonTrigSF_2);

    SynTree->SetBranchAddress("for_mme_fake_ele_iso",&for_mme_fake_ele_iso);
    SynTree->SetBranchAddress("for_mme_fake_ele_id",&for_mme_fake_ele_id);
    SynTree->SetBranchAddress("for_mme_ele_1_iso",&for_mme_ele_1_iso);
    SynTree->SetBranchAddress("for_mme_ele_1_id",&for_mme_ele_1_id);
    SynTree->SetBranchAddress("for_mme_ele_2_iso",&for_mme_ele_2_iso);
    SynTree->SetBranchAddress("for_mme_ele_2_id",&for_mme_ele_2_id);
    SynTree->SetBranchAddress("for_mme_mu_1_iso",&for_mme_mu_1_iso);
    SynTree->SetBranchAddress("for_mme_mu_1_id",&for_mme_mu_1_id);
    SynTree->SetBranchAddress("for_mme_mu_2_iso",&for_mme_mu_2_iso);
    SynTree->SetBranchAddress("for_mme_mu_2_id",&for_mme_mu_2_id);
    SynTree->SetBranchAddress("for_mme_m_E1_fake_elec",&for_mme_m_E1_fake_elec);
    SynTree->SetBranchAddress("for_mme_m_E2_fake_elec",&for_mme_m_E2_fake_elec);
    SynTree->SetBranchAddress("for_mme_pfmt_fake_electron",&for_mme_pfmt_fake_electron);
    SynTree->SetBranchAddress("for_mme_fake_muon_iso",&for_mme_fake_muon_iso);
    SynTree->SetBranchAddress("for_mme_fake_muon_id",&for_mme_fake_muon_id);
    SynTree->SetBranchAddress("for_mme_m_3l",&for_mme_m_3l);
    SynTree->SetBranchAddress("for_mme_pfmt_fake_muon",&for_mme_pfmt_fake_muon);
    SynTree->SetBranchAddress("for_mme_m_M1_fake_elec",&for_mme_m_M1_fake_elec);
    SynTree->SetBranchAddress("for_mme_m_M2_fake_elec",&for_mme_m_M2_fake_elec);
    SynTree->SetBranchAddress("for_mme_fake_ele_eta",&for_mme_fake_ele_eta);
    SynTree->SetBranchAddress("for_mme_fake_muon_eta",&for_mme_fake_muon_eta);
    SynTree->SetBranchAddress("for_mme_m_EE",&for_mme_m_EE);
    SynTree->SetBranchAddress("for_mme_m_MM",&for_mme_m_MM);
    SynTree->SetBranchAddress("for_mme_dR_Z1_fake_lepton",&for_mme_dR_Z1_fake_lepton);
    SynTree->SetBranchAddress("for_mme_dR_Z2_fake_lepton",&for_mme_dR_Z2_fake_lepton);
    SynTree->SetBranchAddress("for_mme_pt_fake_e",&for_mme_pt_fake_e);
    SynTree->SetBranchAddress("for_mme_pt_fake_m",&for_mme_pt_fake_m);
    SynTree->SetBranchAddress("for_mme_gen_match_1",&for_mme_gen_match_1);
    SynTree->SetBranchAddress("for_mme_gen_match_2",&for_mme_gen_match_2);
    SynTree->SetBranchAddress("for_mme_gen_match_3",&for_mme_gen_match_3);
    SynTree->SetBranchAddress("for_mme_electronIDSF_1",&for_mme_electronIDSF_1);
    SynTree->SetBranchAddress("for_mme_electronIDSF_2",&for_mme_electronIDSF_2);
    SynTree->SetBranchAddress("for_mme_electronIDSF_fake",&for_mme_electronIDSF_fake);
    SynTree->SetBranchAddress("for_mme_muonIDSF_1",&for_mme_muonIDSF_1);
    SynTree->SetBranchAddress("for_mme_muonIDSF_2",&for_mme_muonIDSF_2);
    SynTree->SetBranchAddress("for_mme_muonIDSF_fake",&for_mme_muonIDSF_fake);
    SynTree->SetBranchAddress("for_mme_electronTrigSF_1",&for_mme_electronTrigSF_1);
    SynTree->SetBranchAddress("for_mme_electronTrigSF_2",&for_mme_electronTrigSF_2);
    SynTree->SetBranchAddress("for_mme_muonTrigSF_1",&for_mme_muonTrigSF_1);
    SynTree->SetBranchAddress("for_mme_muonTrigSF_2",&for_mme_muonTrigSF_2);

    SynTree->SetBranchAddress("for_mmm_fake_ele_iso",&for_mmm_fake_ele_iso);
    SynTree->SetBranchAddress("for_mmm_fake_ele_id",&for_mmm_fake_ele_id);
    SynTree->SetBranchAddress("for_mmm_ele_1_iso",&for_mmm_ele_1_iso);
    SynTree->SetBranchAddress("for_mmm_ele_1_id",&for_mmm_ele_1_id);
    SynTree->SetBranchAddress("for_mmm_ele_2_iso",&for_mmm_ele_2_iso);
    SynTree->SetBranchAddress("for_mmm_ele_2_id",&for_mmm_ele_2_id);
    SynTree->SetBranchAddress("for_mmm_mu_1_iso",&for_mmm_mu_1_iso);
    SynTree->SetBranchAddress("for_mmm_mu_1_id",&for_mmm_mu_1_id);
    SynTree->SetBranchAddress("for_mmm_mu_2_iso",&for_mmm_mu_2_iso);
    SynTree->SetBranchAddress("for_mmm_mu_2_id",&for_mmm_mu_2_id);
    SynTree->SetBranchAddress("for_mmm_m_E1_fake_elec",&for_mmm_m_E1_fake_elec);
    SynTree->SetBranchAddress("for_mmm_m_E2_fake_elec",&for_mmm_m_E2_fake_elec);
    SynTree->SetBranchAddress("for_mmm_pfmt_fake_electron",&for_mmm_pfmt_fake_electron);
    SynTree->SetBranchAddress("for_mmm_fake_muon_iso",&for_mmm_fake_muon_iso);
    SynTree->SetBranchAddress("for_mmm_fake_muon_id",&for_mmm_fake_muon_id);
    SynTree->SetBranchAddress("for_mmm_m_3l",&for_mmm_m_3l);
    SynTree->SetBranchAddress("for_mmm_pfmt_fake_muon",&for_mmm_pfmt_fake_muon);
    SynTree->SetBranchAddress("for_mmm_m_M1_fake_elec",&for_mmm_m_M1_fake_elec);
    SynTree->SetBranchAddress("for_mmm_m_M2_fake_elec",&for_mmm_m_M2_fake_elec);
    SynTree->SetBranchAddress("for_mmm_fake_ele_eta",&for_mmm_fake_ele_eta);
    SynTree->SetBranchAddress("for_mmm_fake_muon_eta",&for_mmm_fake_muon_eta);
    SynTree->SetBranchAddress("for_mmm_m_EE",&for_mmm_m_EE);
    SynTree->SetBranchAddress("for_mmm_m_MM",&for_mmm_m_MM);
    SynTree->SetBranchAddress("for_mmm_dR_Z1_fake_lepton",&for_mmm_dR_Z1_fake_lepton);
    SynTree->SetBranchAddress("for_mmm_dR_Z2_fake_lepton",&for_mmm_dR_Z2_fake_lepton);
    SynTree->SetBranchAddress("for_mmm_pt_fake_e",&for_mmm_pt_fake_e);
    SynTree->SetBranchAddress("for_mmm_pt_fake_m",&for_mmm_pt_fake_m);
    SynTree->SetBranchAddress("for_mmm_gen_match_1",&for_mmm_gen_match_1);
    SynTree->SetBranchAddress("for_mmm_gen_match_2",&for_mmm_gen_match_2);
    SynTree->SetBranchAddress("for_mmm_gen_match_3",&for_mmm_gen_match_3);
    SynTree->SetBranchAddress("for_mmm_electronIDSF_1",&for_mmm_electronIDSF_1);
    SynTree->SetBranchAddress("for_mmm_electronIDSF_2",&for_mmm_electronIDSF_2);
    SynTree->SetBranchAddress("for_mmm_electronIDSF_fake",&for_mmm_electronIDSF_fake);
    SynTree->SetBranchAddress("for_mmm_muonIDSF_1",&for_mmm_muonIDSF_1);
    SynTree->SetBranchAddress("for_mmm_muonIDSF_2",&for_mmm_muonIDSF_2);
    SynTree->SetBranchAddress("for_mmm_muonIDSF_fake",&for_mmm_muonIDSF_fake);
    SynTree->SetBranchAddress("for_mmm_electronTrigSF_1",&for_mmm_electronTrigSF_1);
    SynTree->SetBranchAddress("for_mmm_electronTrigSF_2",&for_mmm_electronTrigSF_2);
    SynTree->SetBranchAddress("for_mmm_muonTrigSF_1",&for_mmm_muonTrigSF_1);
    SynTree->SetBranchAddress("for_mmm_muonTrigSF_2",&for_mmm_muonTrigSF_2);


    Float_t scale = 1.0;



    if(is>1) 
      scale = luminosity*xsec[is]/weights[is];

    if(is == 2) scale = luminosity*xsec[2]/weights[2];

    if(is == 3) scale = luminosity/((weights[2]/xsec[2])+(weights[7]/xsec[7]));
    if(is == 4) scale = luminosity/((weights[2]/xsec[2])+(weights[8]/xsec[8]));
    if(is == 5) scale = luminosity/((weights[2]/xsec[2])+(weights[9]/xsec[9]));
    if(is == 6) scale = luminosity/((weights[2]/xsec[2])+(weights[10]/xsec[10]));

    if(is == 7) scale = luminosity/((weights[2]/xsec[2])+(weights[7]/xsec[7]));
    if(is == 8) scale = luminosity/((weights[2]/xsec[2])+(weights[8]/xsec[8]));
    if(is == 9) scale = luminosity/((weights[2]/xsec[2])+(weights[9]/xsec[9]));
    if(is == 10) scale = luminosity/((weights[2]/xsec[2])+(weights[10]/xsec[10]));

    cout<<endl<<"weights[is] = "<<weights[is]<<endl<<"xsec[is] = "<<xsec[is]<<endl<<"scale = "<<scale<<endl;

    Int_t nevents = SynTree->GetEntries();

    for(int ie=0; ie<nevents; ie++){

      SynTree->GetEntry(ie);

      Float_t norm = 1;

      Float_t for_eee_norm = 1.0, for_eem_norm = 1.0, for_mme_norm = 1.0, for_mmm_norm = 1.0;

      if(is_eee){
	Float_t min_m_2l = std::min(std::min(for_eee_m_E1_fake_elec, for_eee_m_E2_fake_elec), for_eee_m_EE);
	Float_t max_iso_Z1_Z2 = std::max(for_eee_ele_1_iso, for_eee_ele_2_iso);
	for_eee_norm = (for_eee_ele_1_id > 0.5)*(for_eee_ele_2_id > 0.5)*(for_eee_m_EE > 81.2)*(for_eee_m_EE < 120.0)*(min_m_2l > 5.0)*(max_iso_Z1_Z2 < 0.14)*(for_eee_dR_Z1_fake_lepton > 0.3)*(for_eee_dR_Z2_fake_lepton > 0.3);
	if(is>1)
	  for_eee_norm = for_eee_norm*scale*for_eee_electronTrigSF_1*for_eee_electronTrigSF_2*for_eee_electronIDSF_1*for_eee_electronIDSF_2*puweight*mcweight;

	if(abs(for_eee_fake_ele_eta)<1.5)
	  for_eee_norm = for_eee_norm*(for_eee_pfmt_fake_electron<55.0);

	//extra weights and cuts for DY
	if(is == 2) for_eee_norm = (npartons==0||npartons>4)*zptweight*for_eee_norm;
	if(is == 3) for_eee_norm = (npartons==1)*zptweight*for_eee_norm;
	if(is == 4) for_eee_norm = (npartons==2)*zptweight*for_eee_norm;
	if(is == 5) for_eee_norm = (npartons==3)*zptweight*for_eee_norm;
	if(is == 6) for_eee_norm = (npartons==4)*zptweight*for_eee_norm;

	if(is == 7) for_eee_norm = zptweight*for_eee_norm;
	if(is == 8) for_eee_norm = zptweight*for_eee_norm;
	if(is == 9) for_eee_norm = zptweight*for_eee_norm;
	if(is == 10) for_eee_norm = zptweight*for_eee_norm;
	//end extra weights and cuts for DY

      }


      if(is_eem){
	for_eem_norm = (for_eem_ele_1_id > 0.5)*(for_eem_ele_2_id > 0.5)*(for_eem_m_EE>81.2)*(for_eem_m_EE < 120.0)*(for_eem_m_3l<250.0)*(for_eem_dR_Z1_fake_lepton>0.3)*(for_eem_dR_Z2_fake_lepton>0.3);
	if(is>1)
	  for_eem_norm = for_eem_norm*scale*for_eem_electronTrigSF_1*for_eem_electronTrigSF_2*for_eem_electronIDSF_1*for_eem_electronIDSF_2*puweight*mcweight;


	if(abs(for_eem_fake_muon_eta)<1.5)
	  for_eem_norm = for_eem_norm*(for_eem_pfmt_fake_muon<55.0);

	//extra weights and cuts for DY
	if(is == 2) for_eem_norm = (npartons==0||npartons>4)*zptweight*for_eem_norm;
	if(is == 3) for_eem_norm = (npartons==1)*zptweight*for_eem_norm;
	if(is == 4) for_eem_norm = (npartons==2)*zptweight*for_eem_norm;
	if(is == 5) for_eem_norm = (npartons==3)*zptweight*for_eem_norm;
	if(is == 6) for_eem_norm = (npartons==4)*zptweight*for_eem_norm;

	if(is == 7) for_eem_norm = zptweight*for_eem_norm;
	if(is == 8) for_eem_norm = zptweight*for_eem_norm;
	if(is == 9) for_eem_norm = zptweight*for_eem_norm;
	if(is == 10) for_eem_norm = zptweight*for_eem_norm;
	//end extra weights and cuts for DY


      }

      if(is_mme){
	Float_t min_m_2l = std::min(std::min(for_mme_m_M1_fake_elec, for_mme_m_M2_fake_elec), for_mme_m_MM);
	Float_t max_iso_Z1_Z2 = std::max(for_mme_mu_1_iso, for_mme_mu_2_iso);
	for_mme_norm = (for_mme_mu_1_id > 0.5)*(for_mme_mu_2_id > 0.5)*(for_mme_mu_1_iso < 0.25)*(for_mme_mu_2_iso < 0.25)*(for_mme_m_MM > 81.2)*(for_mme_m_MM < 120.0)*(min_m_2l > 5.0)*(max_iso_Z1_Z2 < 0.14)*(for_mme_dR_Z1_fake_lepton > 0.3)*(for_mme_dR_Z2_fake_lepton > 0.3);
	if(is>1)
	  for_mme_norm = for_mme_norm*scale*for_mme_muonTrigSF_1*for_mme_muonTrigSF_2*for_mme_muonIDSF_1*for_mme_muonIDSF_2*puweight*mcweight;

	if(abs(for_mme_fake_ele_eta)<1.5)
	  for_mme_norm = for_mme_norm*(for_mme_pfmt_fake_electron<55.0);

	//extra weights and cuts for DY
	if(is == 2) for_mme_norm = (npartons==0||npartons>4)*zptweight*for_mme_norm;
	if(is == 3) for_mme_norm = (npartons==1)*zptweight*for_mme_norm;
	if(is == 4) for_mme_norm = (npartons==2)*zptweight*for_mme_norm;
	if(is == 5) for_mme_norm = (npartons==3)*zptweight*for_mme_norm;
	if(is == 6) for_mme_norm = (npartons==4)*zptweight*for_mme_norm;

	if(is == 7) for_mme_norm = zptweight*for_mme_norm;
	if(is == 8) for_mme_norm = zptweight*for_mme_norm;
	if(is == 9) for_mme_norm = zptweight*for_mme_norm;
	if(is == 10) for_mme_norm = zptweight*for_mme_norm;
	//end extra weights and cuts for DY


      }


      if(is_mmm){
	for_mmm_norm = (for_mmm_mu_1_id > 0.5)*(for_mmm_mu_2_id > 0.5)*(for_mmm_mu_1_iso < 0.25)*(for_mmm_mu_2_iso < 0.25)*(for_mmm_m_MM>81.2)*(for_mmm_m_MM < 120.0)*(for_mmm_m_3l<250.0)*(for_mmm_dR_Z1_fake_lepton>0.3)*(for_mmm_dR_Z2_fake_lepton>0.3);
	if(is>1)
	  for_mmm_norm = for_mmm_norm*scale*for_mmm_muonTrigSF_1*for_mmm_muonTrigSF_2*for_mmm_muonIDSF_1*for_mmm_muonIDSF_2*puweight*mcweight;

	if(abs(for_mmm_fake_muon_eta)<1.5)
	  for_mmm_norm = for_mmm_norm*(for_mmm_pfmt_fake_muon<55.0);

	//extra weights and cuts for DY
	if(is == 2) for_mmm_norm = (npartons==0||npartons>4)*zptweight*for_mmm_norm;
	if(is == 3) for_mmm_norm = (npartons==1)*zptweight*for_mmm_norm;
	if(is == 4) for_mmm_norm = (npartons==2)*zptweight*for_mmm_norm;
	if(is == 5) for_mmm_norm = (npartons==3)*zptweight*for_mmm_norm;
	if(is == 6) for_mmm_norm = (npartons==4)*zptweight*for_mmm_norm;

	if(is == 7) for_mmm_norm = zptweight*for_mmm_norm;
	if(is == 8) for_mmm_norm = zptweight*for_mmm_norm;
	if(is == 9) for_mmm_norm = zptweight*for_mmm_norm;
	if(is == 10) for_mmm_norm = zptweight*for_mmm_norm;
	//end extra weights and cuts for DY


      }


      if(is==0){

	//for fake ele
	if((for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && abs(for_eee_fake_ele_eta) < 1.5 && is_eee){
	  pt_ele_pass_barrel_data->Fill(for_eee_pt_fake_e,for_eee_norm);
	}

	if((for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && abs(for_eee_fake_ele_eta)>1.5 && is_eee){
	  pt_ele_pass_endcap_data->Fill(for_eee_pt_fake_e,for_eee_norm);
	}

	if(!(for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && abs(for_eee_fake_ele_eta) < 1.5 && is_eee){
	  pt_ele_fail_barrel_data->Fill(for_eee_pt_fake_e,for_eee_norm);
	}

	if(!(for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && abs(for_eee_fake_ele_eta)>1.5 && is_eee){
	  pt_ele_fail_endcap_data->Fill(for_eee_pt_fake_e,for_eee_norm);
	}

	//end for fake ele

	//for fake muon

	if(for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15 && abs(for_eem_fake_muon_eta) < 1.2 && is_eem){
	  pt_muon_pass_barrel_data->Fill(for_eem_pt_fake_m,for_eem_norm);
	}

	if(for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15 && abs(for_eem_fake_muon_eta)>1.2 && is_eem){
	  pt_muon_pass_endcap_data->Fill(for_eem_pt_fake_m,for_eem_norm);
	}

	if(!(for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15) && abs(for_eem_fake_muon_eta) < 1.2 && is_eem){
	  pt_muon_fail_barrel_data->Fill(for_eem_pt_fake_m,for_eem_norm);
	}

	if(!(for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15) && abs(for_eem_fake_muon_eta)>1.2 && is_eem){
	  pt_muon_fail_endcap_data->Fill(for_eem_pt_fake_m,for_eem_norm);
	}

	//end for fake muon

	//mT plots for fake ele

	if((for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e>=10 && for_eee_pt_fake_e<30) && abs(for_eee_fake_ele_eta) < 1.5 && is_eee){
	  mt_ele_pass_Pt10To30_barrel_data->Fill(for_eee_pfmt_fake_electron,for_eee_norm);
	}

	if((for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e>=10 && for_eee_pt_fake_e<30) && abs(for_eee_fake_ele_eta)>1.5 && is_eee){
	  mt_ele_pass_Pt10To30_endcap_data->Fill(for_eee_pfmt_fake_electron,for_eee_norm);
	}

	if((for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e>=30 && for_eee_pt_fake_e<50) && abs(for_eee_fake_ele_eta) < 1.5 && is_eee){
	  mt_ele_pass_Pt30To50_barrel_data->Fill(for_eee_pfmt_fake_electron,for_eee_norm);
	}

	if((for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e>=30 && for_eee_pt_fake_e<50) && abs(for_eee_fake_ele_eta)>1.5 && is_eee){
	  mt_ele_pass_Pt30To50_endcap_data->Fill(for_eee_pfmt_fake_electron,for_eee_norm);
	}

	if((for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e>=50 && for_eee_pt_fake_e<70) && abs(for_eee_fake_ele_eta) < 1.5 && is_eee){
	  mt_ele_pass_Pt50To70_barrel_data->Fill(for_eee_pfmt_fake_electron,for_eee_norm);
	}

	if((for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e>=50 && for_eee_pt_fake_e<70) && abs(for_eee_fake_ele_eta)>1.5 && is_eee){
	  mt_ele_pass_Pt50To70_endcap_data->Fill(for_eee_pfmt_fake_electron,for_eee_norm);
	}

	if(!(for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e>=10 && for_eee_pt_fake_e<30) && abs(for_eee_fake_ele_eta) < 1.5 && is_eee){
	  mt_ele_fail_Pt10To30_barrel_data->Fill(for_eee_pfmt_fake_electron,for_eee_norm);
	}

	if(!(for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e>=10 && for_eee_pt_fake_e<30) && abs(for_eee_fake_ele_eta)>1.5 && is_eee){
	  mt_ele_fail_Pt10To30_endcap_data->Fill(for_eee_pfmt_fake_electron,for_eee_norm);
	}

	if(!(for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e>=30 && for_eee_pt_fake_e<50) && abs(for_eee_fake_ele_eta) < 1.5 && is_eee){
	  mt_ele_fail_Pt30To50_barrel_data->Fill(for_eee_pfmt_fake_electron,for_eee_norm);
	}

	if(!(for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e>=30 && for_eee_pt_fake_e<50) && abs(for_eee_fake_ele_eta)>1.5 && is_eee){
	  mt_ele_fail_Pt30To50_endcap_data->Fill(for_eee_pfmt_fake_electron,for_eee_norm);
	}

	if(!(for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e>=50 && for_eee_pt_fake_e<70) && abs(for_eee_fake_ele_eta) < 1.5 && is_eee){
	  mt_ele_fail_Pt50To70_barrel_data->Fill(for_eee_pfmt_fake_electron,for_eee_norm);
	}

	if(!(for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e>=50 && for_eee_pt_fake_e<70) && abs(for_eee_fake_ele_eta)>1.5 && is_eee){
	  mt_ele_fail_Pt50To70_endcap_data->Fill(for_eee_pfmt_fake_electron,for_eee_norm);
	}

	//end mt plots for fake ele

	//mt plots for fake muon

	if(for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15  && (for_eem_pt_fake_m>=10 && for_eem_pt_fake_m<30) && abs(for_eem_fake_muon_eta) < 1.2 && is_eem){
	  mt_muon_pass_Pt10To30_barrel_data->Fill(for_eem_pfmt_fake_muon,for_eem_norm);
	}

	if(for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15  && (for_eem_pt_fake_m>=10 && for_eem_pt_fake_m<30) && abs(for_eem_fake_muon_eta)>1.2 && is_eem){
	  mt_muon_pass_Pt10To30_endcap_data->Fill(for_eem_pfmt_fake_muon,for_eem_norm);
	}

	if(for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15  && (for_eem_pt_fake_m>=30 && for_eem_pt_fake_m<50) && abs(for_eem_fake_muon_eta) < 1.2 && is_eem){
	  mt_muon_pass_Pt30To50_barrel_data->Fill(for_eem_pfmt_fake_muon,for_eem_norm);
	}

	if(for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15  && (for_eem_pt_fake_m>=30 && for_eem_pt_fake_m<50) && abs(for_eem_fake_muon_eta)>1.2 && is_eem){
	  mt_muon_pass_Pt30To50_endcap_data->Fill(for_eem_pfmt_fake_muon,for_eem_norm);
	}

	if(for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15  && (for_eem_pt_fake_m>=50 && for_eem_pt_fake_m<70) && abs(for_eem_fake_muon_eta) < 1.2 && is_eem){
	  mt_muon_pass_Pt50To70_barrel_data->Fill(for_eem_pfmt_fake_muon,for_eem_norm);
	}

	if(for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15  && (for_eem_pt_fake_m>=50 && for_eem_pt_fake_m<70) && abs(for_eem_fake_muon_eta)>1.2 && is_eem){
	  mt_muon_pass_Pt50To70_endcap_data->Fill(for_eem_pfmt_fake_muon,for_eem_norm);
	}


	if(!(for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15)  && (for_eem_pt_fake_m>=10 && for_eem_pt_fake_m<30) && abs(for_eem_fake_muon_eta) < 1.2 && is_eem){
	  mt_muon_fail_Pt10To30_barrel_data->Fill(for_eem_pfmt_fake_muon,for_eem_norm);
	}

	if(!(for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15)  && (for_eem_pt_fake_m>=10 && for_eem_pt_fake_m<30) && abs(for_eem_fake_muon_eta)>1.2 && is_eem){
	  mt_muon_fail_Pt10To30_endcap_data->Fill(for_eem_pfmt_fake_muon,for_eem_norm);
	}

	if(!(for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15)  && (for_eem_pt_fake_m>=30 && for_eem_pt_fake_m<50) && abs(for_eem_fake_muon_eta) < 1.2 && is_eem){
	  mt_muon_fail_Pt30To50_barrel_data->Fill(for_eem_pfmt_fake_muon,for_eem_norm);
	}

	if(!(for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15)  && (for_eem_pt_fake_m>=30 && for_eem_pt_fake_m<50) && abs(for_eem_fake_muon_eta)>1.2 && is_eem){
	  mt_muon_fail_Pt30To50_endcap_data->Fill(for_eem_pfmt_fake_muon,for_eem_norm);
	}

	if(!(for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15)  && (for_eem_pt_fake_m>=50 && for_eem_pt_fake_m<70) && abs(for_eem_fake_muon_eta) < 1.2 && is_eem){
	  mt_muon_fail_Pt50To70_barrel_data->Fill(for_eem_pfmt_fake_muon,for_eem_norm);
	}

	if(!(for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15)  && (for_eem_pt_fake_m>=50 && for_eem_pt_fake_m<70) && abs(for_eem_fake_muon_eta)>1.2 && is_eem){
	  mt_muon_fail_Pt50To70_endcap_data->Fill(for_eem_pfmt_fake_muon,for_eem_norm);
	}
	//end mt plots for fake muon

      }









      if(is==1){

	//for fake ele
	if((for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && abs(for_mme_fake_ele_eta) < 1.5 && is_mme){
	  pt_ele_pass_barrel_data->Fill(for_mme_pt_fake_e,for_mme_norm);
	}

	if((for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && abs(for_mme_fake_ele_eta)>1.5 && is_mme){
	  pt_ele_pass_endcap_data->Fill(for_mme_pt_fake_e,for_mme_norm);
	}

	if(!(for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && abs(for_mme_fake_ele_eta) < 1.5 && is_mme){
	  pt_ele_fail_barrel_data->Fill(for_mme_pt_fake_e,for_mme_norm);
	}

	if(!(for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && abs(for_mme_fake_ele_eta)>1.5 && is_mme){
	  pt_ele_fail_endcap_data->Fill(for_mme_pt_fake_e,for_mme_norm);
	}

	//end for fake ele

	//for fake muon

	if(for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15 && abs(for_mmm_fake_muon_eta) < 1.2 && is_mmm){
	  pt_muon_pass_barrel_data->Fill(for_mmm_pt_fake_m,for_mmm_norm);
	}

	if(for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15 && abs(for_mmm_fake_muon_eta)>1.2 && is_mmm){
	  pt_muon_pass_endcap_data->Fill(for_mmm_pt_fake_m,for_mmm_norm);
	}

	if(!(for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15) && abs(for_mmm_fake_muon_eta) < 1.2 && is_mmm){
	  pt_muon_fail_barrel_data->Fill(for_mmm_pt_fake_m,for_mmm_norm);
	}

	if(!(for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15) && abs(for_mmm_fake_muon_eta)>1.2 && is_mmm){
	  pt_muon_fail_endcap_data->Fill(for_mmm_pt_fake_m,for_mmm_norm);
	}

	//end for fake muon

	//mT plots for fake ele

	if((for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e>=10 && for_mme_pt_fake_e<30) && abs(for_mme_fake_ele_eta) < 1.5 && is_mme){
	  mt_ele_pass_Pt10To30_barrel_data->Fill(for_mme_pfmt_fake_electron,for_mme_norm);
	}

	if((for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e>=10 && for_mme_pt_fake_e<30) && abs(for_mme_fake_ele_eta)>1.5 && is_mme){
	  mt_ele_pass_Pt10To30_endcap_data->Fill(for_mme_pfmt_fake_electron,for_mme_norm);
	}

	if((for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e>=30 && for_mme_pt_fake_e<50) && abs(for_mme_fake_ele_eta) < 1.5 && is_mme){
	  mt_ele_pass_Pt30To50_barrel_data->Fill(for_mme_pfmt_fake_electron,for_mme_norm);
	}

	if((for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e>=30 && for_mme_pt_fake_e<50) && abs(for_mme_fake_ele_eta)>1.5 && is_mme){
	  mt_ele_pass_Pt30To50_endcap_data->Fill(for_mme_pfmt_fake_electron,for_mme_norm);
	}

	if((for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e>=50 && for_mme_pt_fake_e<70) && abs(for_mme_fake_ele_eta) < 1.5 && is_mme){
	  mt_ele_pass_Pt50To70_barrel_data->Fill(for_mme_pfmt_fake_electron,for_mme_norm);
	}

	if((for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e>=50 && for_mme_pt_fake_e<70) && abs(for_mme_fake_ele_eta)>1.5 && is_mme){
	  mt_ele_pass_Pt50To70_endcap_data->Fill(for_mme_pfmt_fake_electron,for_mme_norm);
	}

	if(!(for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e>=10 && for_mme_pt_fake_e<30) && abs(for_mme_fake_ele_eta) < 1.5 && is_mme){
	  mt_ele_fail_Pt10To30_barrel_data->Fill(for_mme_pfmt_fake_electron,for_mme_norm);
	}

	if(!(for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e>=10 && for_mme_pt_fake_e<30) && abs(for_mme_fake_ele_eta)>1.5 && is_mme){
	  mt_ele_fail_Pt10To30_endcap_data->Fill(for_mme_pfmt_fake_electron,for_mme_norm);
	}

	if(!(for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e>=30 && for_mme_pt_fake_e<50) && abs(for_mme_fake_ele_eta) < 1.5 && is_mme){
	  mt_ele_fail_Pt30To50_barrel_data->Fill(for_mme_pfmt_fake_electron,for_mme_norm);
	}

	if(!(for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e>=30 && for_mme_pt_fake_e<50) && abs(for_mme_fake_ele_eta)>1.5 && is_mme){
	  mt_ele_fail_Pt30To50_endcap_data->Fill(for_mme_pfmt_fake_electron,for_mme_norm);
	}

	if(!(for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e>=50 && for_mme_pt_fake_e<70) && abs(for_mme_fake_ele_eta) < 1.5 && is_mme){
	  mt_ele_fail_Pt50To70_barrel_data->Fill(for_mme_pfmt_fake_electron,for_mme_norm);
	}

	if(!(for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e>=50 && for_mme_pt_fake_e<70) && abs(for_mme_fake_ele_eta)>1.5 && is_mme){
	  mt_ele_fail_Pt50To70_endcap_data->Fill(for_mme_pfmt_fake_electron,for_mme_norm);
	}

	//end mt plots for fake ele

	//mt plots for fake muon

	if(for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15  && (for_mmm_pt_fake_m>=10 && for_mmm_pt_fake_m<30) && abs(for_mmm_fake_muon_eta) < 1.2 && is_mmm){
	  mt_muon_pass_Pt10To30_barrel_data->Fill(for_mmm_pfmt_fake_muon,for_mmm_norm);
	}

	if(for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15  && (for_mmm_pt_fake_m>=10 && for_mmm_pt_fake_m<30) && abs(for_mmm_fake_muon_eta)>1.2 && is_mmm){
	  mt_muon_pass_Pt10To30_endcap_data->Fill(for_mmm_pfmt_fake_muon,for_mmm_norm);
	}

	if(for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15  && (for_mmm_pt_fake_m>=30 && for_mmm_pt_fake_m<50) && abs(for_mmm_fake_muon_eta) < 1.2 && is_mmm){
	  mt_muon_pass_Pt30To50_barrel_data->Fill(for_mmm_pfmt_fake_muon,for_mmm_norm);
	}

	if(for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15  && (for_mmm_pt_fake_m>=30 && for_mmm_pt_fake_m<50) && abs(for_mmm_fake_muon_eta)>1.2 && is_mmm){
	  mt_muon_pass_Pt30To50_endcap_data->Fill(for_mmm_pfmt_fake_muon,for_mmm_norm);
	}

	if(for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15  && (for_mmm_pt_fake_m>=50 && for_mmm_pt_fake_m<70) && abs(for_mmm_fake_muon_eta) < 1.2 && is_mmm){
	  mt_muon_pass_Pt50To70_barrel_data->Fill(for_mmm_pfmt_fake_muon,for_mmm_norm);
	}

	if(for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15  && (for_mmm_pt_fake_m>=50 && for_mmm_pt_fake_m<70) && abs(for_mmm_fake_muon_eta)>1.2 && is_mmm){
	  mt_muon_pass_Pt50To70_endcap_data->Fill(for_mmm_pfmt_fake_muon,for_mmm_norm);
	}

	if(!(for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15)  && (for_mmm_pt_fake_m>=10 && for_mmm_pt_fake_m<30) && abs(for_mmm_fake_muon_eta) < 1.2 && is_mmm){
	  mt_muon_fail_Pt10To30_barrel_data->Fill(for_mmm_pfmt_fake_muon,for_mmm_norm);
	}

	if(!(for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15)  && (for_mmm_pt_fake_m>=10 && for_mmm_pt_fake_m<30) && abs(for_mmm_fake_muon_eta)>1.2 && is_mmm){
	  mt_muon_fail_Pt10To30_endcap_data->Fill(for_mmm_pfmt_fake_muon,for_mmm_norm);
	}

	if(!(for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15)  && (for_mmm_pt_fake_m>=30 && for_mmm_pt_fake_m<50) && abs(for_mmm_fake_muon_eta) < 1.2 && is_mmm){
	  mt_muon_fail_Pt30To50_barrel_data->Fill(for_mmm_pfmt_fake_muon,for_mmm_norm);
	}

	if(!(for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15)  && (for_mmm_pt_fake_m>=30 && for_mmm_pt_fake_m<50) && abs(for_mmm_fake_muon_eta)>1.2 && is_mmm){
	  mt_muon_fail_Pt30To50_endcap_data->Fill(for_mmm_pfmt_fake_muon,for_mmm_norm);
	}

	if(!(for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15)  && (for_mmm_pt_fake_m>=50 && for_mmm_pt_fake_m<70) && abs(for_mmm_fake_muon_eta) < 1.2 && is_mmm){
	  mt_muon_fail_Pt50To70_barrel_data->Fill(for_mmm_pfmt_fake_muon,for_mmm_norm);
	}

	if(!(for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15)  && (for_mmm_pt_fake_m>=50 && for_mmm_pt_fake_m<70) && abs(for_mmm_fake_muon_eta)>1.2 && is_mmm){
	  mt_muon_fail_Pt50To70_endcap_data->Fill(for_mmm_pfmt_fake_muon,for_mmm_norm);
	}

      }















      if(is>1){

	//pt plots for fake ele

	if((for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && abs(for_eee_fake_ele_eta) < 1.5 && (for_eee_gen_match_3 != 6) && is_eee){
	  pt_ele_pass_barrel_prompt->Fill(for_eee_pt_fake_e, for_eee_norm);
	}

	if((for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && abs(for_mme_fake_ele_eta) < 1.5 && (for_mme_gen_match_3 != 6) && is_mme){
	  pt_ele_pass_barrel_prompt->Fill(for_mme_pt_fake_e, for_mme_norm);
	}

	if((for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && abs(for_eee_fake_ele_eta) < 1.5 && (for_eee_gen_match_3 == 6) && is_eee){
	  pt_ele_pass_barrel_fake->Fill(for_eee_pt_fake_e, for_eee_norm);
	}

	if((for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && abs(for_mme_fake_ele_eta) < 1.5 && (for_mme_gen_match_3 == 6) && is_mme){
	  pt_ele_pass_barrel_fake->Fill(for_mme_pt_fake_e, for_mme_norm);
	}

	if((for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && abs(for_eee_fake_ele_eta) > 1.5 && (for_eee_gen_match_3 != 6) && is_eee){
	  pt_ele_pass_endcap_prompt->Fill(for_eee_pt_fake_e, for_eee_norm);
	}

	if((for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && abs(for_mme_fake_ele_eta) > 1.5 && (for_mme_gen_match_3 != 6) && is_mme){
	  pt_ele_pass_endcap_prompt->Fill(for_mme_pt_fake_e, for_mme_norm);
	}

	if((for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && abs(for_eee_fake_ele_eta) > 1.5 && (for_eee_gen_match_3 == 6) && is_eee){
	  pt_ele_pass_endcap_fake->Fill(for_eee_pt_fake_e, for_eee_norm);
	}

	if((for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && abs(for_mme_fake_ele_eta) > 1.5 && (for_mme_gen_match_3 == 6) && is_mme){
	  pt_ele_pass_endcap_fake->Fill(for_mme_pt_fake_e, for_mme_norm);
	}


	if(!(for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && abs(for_eee_fake_ele_eta) < 1.5 && (for_eee_gen_match_3 != 6) && is_eee){
	  pt_ele_fail_barrel_prompt->Fill(for_eee_pt_fake_e, for_eee_norm);
	}

	if(!(for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && abs(for_mme_fake_ele_eta) < 1.5 && (for_mme_gen_match_3 != 6) && is_mme){
	  pt_ele_fail_barrel_prompt->Fill(for_mme_pt_fake_e, for_mme_norm);
	}

	if(!(for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && abs(for_eee_fake_ele_eta) < 1.5 && (for_eee_gen_match_3 == 6) && is_eee){
	  pt_ele_fail_barrel_fake->Fill(for_eee_pt_fake_e, for_eee_norm);
	}

	if(!(for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && abs(for_mme_fake_ele_eta) < 1.5 && (for_mme_gen_match_3 == 6) && is_mme){
	  pt_ele_fail_barrel_fake->Fill(for_mme_pt_fake_e, for_mme_norm);
	}

	if(!(for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && abs(for_eee_fake_ele_eta) > 1.5 && (for_eee_gen_match_3 != 6) && is_eee){
	  pt_ele_fail_endcap_prompt->Fill(for_eee_pt_fake_e, for_eee_norm);
	}

	if(!(for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && abs(for_mme_fake_ele_eta) > 1.5 && (for_mme_gen_match_3 != 6) && is_mme){
	  pt_ele_fail_endcap_prompt->Fill(for_mme_pt_fake_e, for_mme_norm);
	}

	if(!(for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && abs(for_eee_fake_ele_eta) > 1.5 && (for_eee_gen_match_3 == 6) && is_eee){
	  pt_ele_fail_endcap_fake->Fill(for_eee_pt_fake_e, for_eee_norm);
	}

	if(!(for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && abs(for_mme_fake_ele_eta) > 1.5 && (for_mme_gen_match_3 == 6) && is_mme){
	  pt_ele_fail_endcap_fake->Fill(for_mme_pt_fake_e, for_mme_norm);
	}

	//end pt plots for fake elec

	//pt plots for fake muon

	if((for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15) && abs(for_mmm_fake_muon_eta) < 1.2 && (for_mmm_gen_match_3 != 6) && is_mmm){
	  pt_muon_pass_barrel_prompt->Fill(for_mmm_pt_fake_m, for_mmm_norm);
	}

	if((for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15) && abs(for_eem_fake_muon_eta) < 1.2 && (for_eem_gen_match_3 != 6) && is_eem){
	  pt_muon_pass_barrel_prompt->Fill(for_eem_pt_fake_m, for_eem_norm);
	}

	if((for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15) && abs(for_mmm_fake_muon_eta) < 1.2 && (for_mmm_gen_match_3 == 6) && is_mmm){
	  pt_muon_pass_barrel_fake->Fill(for_mmm_pt_fake_m, for_mmm_norm);
	}

	if((for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15) && abs(for_eem_fake_muon_eta) < 1.2 && (for_eem_gen_match_3 == 6) && is_eem){
	  pt_muon_pass_barrel_fake->Fill(for_eem_pt_fake_m, for_eem_norm);
	}

	if((for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15) && abs(for_mmm_fake_muon_eta) > 1.2 && (for_mmm_gen_match_3 != 6) && is_mmm){
	  pt_muon_pass_endcap_prompt->Fill(for_mmm_pt_fake_m, for_mmm_norm);
	}

	if((for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15) && abs(for_eem_fake_muon_eta) > 1.2 && (for_eem_gen_match_3 != 6) && is_eem){
	  pt_muon_pass_endcap_prompt->Fill(for_eem_pt_fake_m, for_eem_norm);
	}

	if((for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15) && abs(for_mmm_fake_muon_eta) > 1.2 && (for_mmm_gen_match_3 == 6) && is_mmm){
	  pt_muon_pass_endcap_fake->Fill(for_mmm_pt_fake_m, for_mmm_norm);
	}

	if((for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15) && abs(for_eem_fake_muon_eta) > 1.2 && (for_eem_gen_match_3 == 6) && is_eem){
	  pt_muon_pass_endcap_fake->Fill(for_eem_pt_fake_m, for_eem_norm);
	}

	if(!(for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15) && abs(for_mmm_fake_muon_eta) < 1.2 && (for_mmm_gen_match_3 != 6) && is_mmm){
	  pt_muon_fail_barrel_prompt->Fill(for_mmm_pt_fake_m, for_mmm_norm);
	}

	if(!(for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15) && abs(for_eem_fake_muon_eta) < 1.2 && (for_eem_gen_match_3 != 6) && is_eem){
	  pt_muon_fail_barrel_prompt->Fill(for_eem_pt_fake_m, for_eem_norm);
	}

	if(!(for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15) && abs(for_mmm_fake_muon_eta) < 1.2 && (for_mmm_gen_match_3 == 6) && is_mmm){
	  pt_muon_fail_barrel_fake->Fill(for_mmm_pt_fake_m, for_mmm_norm);
	}

	if(!(for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15) && abs(for_eem_fake_muon_eta) < 1.2 && (for_eem_gen_match_3 == 6) && is_eem){
	  pt_muon_fail_barrel_fake->Fill(for_eem_pt_fake_m, for_eem_norm);
	}

	if(!(for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15) && abs(for_mmm_fake_muon_eta) > 1.2 && (for_mmm_gen_match_3 != 6) && is_mmm){
	  pt_muon_fail_endcap_prompt->Fill(for_mmm_pt_fake_m, for_mmm_norm);
	}

	if(!(for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15) && abs(for_eem_fake_muon_eta) > 1.2 && (for_eem_gen_match_3 != 6) && is_eem){
	  pt_muon_fail_endcap_prompt->Fill(for_eem_pt_fake_m, for_eem_norm);
	}

	if(!(for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15) && abs(for_mmm_fake_muon_eta) > 1.2 && (for_mmm_gen_match_3 == 6) && is_mmm){
	  pt_muon_fail_endcap_fake->Fill(for_mmm_pt_fake_m, for_mmm_norm);
	}

	if(!(for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15) && abs(for_eem_fake_muon_eta) > 1.2 && (for_eem_gen_match_3 == 6) && is_eem){
	  pt_muon_fail_endcap_fake->Fill(for_eem_pt_fake_m, for_eem_norm);
	}

	//end pt plots for fake muon

	//mt plots for fake ele

	if((for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e >= 10 && for_eee_pt_fake_e < 30) && abs(for_eee_fake_ele_eta) < 1.5 && (for_eee_gen_match_3 != 6) && is_eee){
	  mt_ele_pass_Pt10To30_barrel_prompt->Fill(for_eee_pfmt_fake_electron, for_eee_norm);
	}

	if((for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e >= 10 && for_mme_pt_fake_e < 30) && abs(for_mme_fake_ele_eta) < 1.5 && (for_mme_gen_match_3 != 6) && is_mme){
	  mt_ele_pass_Pt10To30_barrel_prompt->Fill(for_mme_pfmt_fake_electron, for_mme_norm);
	}

	if((for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e >= 10 && for_eee_pt_fake_e < 30) && abs(for_eee_fake_ele_eta) < 1.5 && (for_eee_gen_match_3 == 6) && is_eee){
	  mt_ele_pass_Pt10To30_barrel_fake->Fill(for_eee_pfmt_fake_electron, for_eee_norm);
	}

	if((for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e >= 10 && for_mme_pt_fake_e < 30) && abs(for_mme_fake_ele_eta) < 1.5 && (for_mme_gen_match_3 == 6) && is_mme){
	  mt_ele_pass_Pt10To30_barrel_fake->Fill(for_mme_pfmt_fake_electron, for_mme_norm);
	}

	if((for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e >= 10 && for_eee_pt_fake_e < 30) && abs(for_eee_fake_ele_eta) > 1.5 && (for_eee_gen_match_3 != 6) && is_eee){
	  mt_ele_pass_Pt10To30_endcap_prompt->Fill(for_eee_pfmt_fake_electron, for_eee_norm);
	}

	if((for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e >= 10 && for_mme_pt_fake_e < 30) && abs(for_mme_fake_ele_eta) > 1.5 && (for_mme_gen_match_3 != 6) && is_mme){
	  mt_ele_pass_Pt10To30_endcap_prompt->Fill(for_mme_pfmt_fake_electron, for_mme_norm);
	}

	if((for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e >= 10 && for_eee_pt_fake_e < 30) && abs(for_eee_fake_ele_eta) > 1.5 && (for_eee_gen_match_3 == 6) && is_eee){
	  mt_ele_pass_Pt10To30_endcap_fake->Fill(for_eee_pfmt_fake_electron, for_eee_norm);
	}

	if((for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e >= 10 && for_mme_pt_fake_e < 30) && abs(for_mme_fake_ele_eta) > 1.5 && (for_mme_gen_match_3 == 6) && is_mme){
	  mt_ele_pass_Pt10To30_endcap_fake->Fill(for_mme_pfmt_fake_electron, for_mme_norm);
	}

	if((for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e >= 30 && for_eee_pt_fake_e < 50) && abs(for_eee_fake_ele_eta) < 1.5 && (for_eee_gen_match_3 != 6) && is_eee){
	  mt_ele_pass_Pt30To50_barrel_prompt->Fill(for_eee_pfmt_fake_electron, for_eee_norm);
	}

	if((for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e >= 30 && for_mme_pt_fake_e < 50) && abs(for_mme_fake_ele_eta) < 1.5 && (for_mme_gen_match_3 != 6) && is_mme){
	  mt_ele_pass_Pt30To50_barrel_prompt->Fill(for_mme_pfmt_fake_electron, for_mme_norm);
	}

	if((for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e >= 30 && for_eee_pt_fake_e < 50) && abs(for_eee_fake_ele_eta) < 1.5 && (for_eee_gen_match_3 == 6) && is_eee){
	  mt_ele_pass_Pt30To50_barrel_fake->Fill(for_eee_pfmt_fake_electron, for_eee_norm);
	}

	if((for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e >= 30 && for_mme_pt_fake_e < 50) && abs(for_mme_fake_ele_eta) < 1.5 && (for_mme_gen_match_3 == 6) && is_mme){
	  mt_ele_pass_Pt30To50_barrel_fake->Fill(for_mme_pfmt_fake_electron, for_mme_norm);
	}

	if((for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e >= 30 && for_eee_pt_fake_e < 50) && abs(for_eee_fake_ele_eta) > 1.5 && (for_eee_gen_match_3 != 6) && is_eee){
	  mt_ele_pass_Pt30To50_endcap_prompt->Fill(for_eee_pfmt_fake_electron, for_eee_norm);
	}

	if((for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e >= 30 && for_mme_pt_fake_e < 50) && abs(for_mme_fake_ele_eta) > 1.5 && (for_mme_gen_match_3 != 6) && is_mme){
	  mt_ele_pass_Pt30To50_endcap_prompt->Fill(for_mme_pfmt_fake_electron, for_mme_norm);
	}

	if((for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e >= 30 && for_eee_pt_fake_e < 50) && abs(for_eee_fake_ele_eta) > 1.5 && (for_eee_gen_match_3 == 6) && is_eee){
	  mt_ele_pass_Pt30To50_endcap_fake->Fill(for_eee_pfmt_fake_electron, for_eee_norm);
	}

	if((for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e >= 30 && for_mme_pt_fake_e < 50) && abs(for_mme_fake_ele_eta) > 1.5 && (for_mme_gen_match_3 == 6) && is_mme){
	  mt_ele_pass_Pt30To50_endcap_fake->Fill(for_mme_pfmt_fake_electron, for_mme_norm);
	}

	if((for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e >= 50 && for_eee_pt_fake_e < 70) && abs(for_eee_fake_ele_eta) < 1.5 && (for_eee_gen_match_3 != 6) && is_eee){
	  mt_ele_pass_Pt50To70_barrel_prompt->Fill(for_eee_pfmt_fake_electron, for_eee_norm);
	}

	if((for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e >= 50 && for_mme_pt_fake_e < 70) && abs(for_mme_fake_ele_eta) < 1.5 && (for_mme_gen_match_3 != 6) && is_mme){
	  mt_ele_pass_Pt50To70_barrel_prompt->Fill(for_mme_pfmt_fake_electron, for_mme_norm);
	}

	if((for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e >= 50 && for_eee_pt_fake_e < 70) && abs(for_eee_fake_ele_eta) < 1.5 && (for_eee_gen_match_3 == 6) && is_eee){
	  mt_ele_pass_Pt50To70_barrel_fake->Fill(for_eee_pfmt_fake_electron, for_eee_norm);
	}

	if((for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e >= 50 && for_mme_pt_fake_e < 70) && abs(for_mme_fake_ele_eta) < 1.5 && (for_mme_gen_match_3 == 6) && is_mme){
	  mt_ele_pass_Pt50To70_barrel_fake->Fill(for_mme_pfmt_fake_electron, for_mme_norm);
	}

	if((for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e >= 50 && for_eee_pt_fake_e < 70) && abs(for_eee_fake_ele_eta) > 1.5 && (for_eee_gen_match_3 != 6) && is_eee){
	  mt_ele_pass_Pt50To70_endcap_prompt->Fill(for_eee_pfmt_fake_electron, for_eee_norm);
	}

	if((for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e >= 50 && for_mme_pt_fake_e < 70) && abs(for_mme_fake_ele_eta) > 1.5 && (for_mme_gen_match_3 != 6) && is_mme){
	  mt_ele_pass_Pt50To70_endcap_prompt->Fill(for_mme_pfmt_fake_electron, for_mme_norm);
	}

	if((for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e >= 50 && for_eee_pt_fake_e < 70) && abs(for_eee_fake_ele_eta) > 1.5 && (for_eee_gen_match_3 == 6) && is_eee){
	  mt_ele_pass_Pt50To70_endcap_fake->Fill(for_eee_pfmt_fake_electron, for_eee_norm);
	}

	if((for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e >= 50 && for_mme_pt_fake_e < 70) && abs(for_mme_fake_ele_eta) > 1.5 && (for_mme_gen_match_3 == 6) && is_mme){
	  mt_ele_pass_Pt50To70_endcap_fake->Fill(for_mme_pfmt_fake_electron, for_mme_norm);
	}

	if(!(for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e >= 10 && for_eee_pt_fake_e < 30) && abs(for_eee_fake_ele_eta) < 1.5 && (for_eee_gen_match_3 != 6) && is_eee){
	  mt_ele_fail_Pt10To30_barrel_prompt->Fill(for_eee_pfmt_fake_electron, for_eee_norm);
	}

	if(!(for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e >= 10 && for_mme_pt_fake_e < 30) && abs(for_mme_fake_ele_eta) < 1.5 && (for_mme_gen_match_3 != 6) && is_mme){
	  mt_ele_fail_Pt10To30_barrel_prompt->Fill(for_mme_pfmt_fake_electron, for_mme_norm);
	}

	if(!(for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e >= 10 && for_eee_pt_fake_e < 30) && abs(for_eee_fake_ele_eta) < 1.5 && (for_eee_gen_match_3 == 6) && is_eee){
	  mt_ele_fail_Pt10To30_barrel_fake->Fill(for_eee_pfmt_fake_electron, for_eee_norm);
	}

	if(!(for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e >= 10 && for_mme_pt_fake_e < 30) && abs(for_mme_fake_ele_eta) < 1.5 && (for_mme_gen_match_3 == 6) && is_mme){
	  mt_ele_fail_Pt10To30_barrel_fake->Fill(for_mme_pfmt_fake_electron, for_mme_norm);
	}

	if(!(for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e >= 10 && for_eee_pt_fake_e < 30) && abs(for_eee_fake_ele_eta) > 1.5 && (for_eee_gen_match_3 != 6) && is_eee){
	  mt_ele_fail_Pt10To30_endcap_prompt->Fill(for_eee_pfmt_fake_electron, for_eee_norm);
	}

	if(!(for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e >= 10 && for_mme_pt_fake_e < 30) && abs(for_mme_fake_ele_eta) > 1.5 && (for_mme_gen_match_3 != 6) && is_mme){
	  mt_ele_fail_Pt10To30_endcap_prompt->Fill(for_mme_pfmt_fake_electron, for_mme_norm);
	}

	if(!(for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e >= 10 && for_eee_pt_fake_e < 30) && abs(for_eee_fake_ele_eta) > 1.5 && (for_eee_gen_match_3 == 6) && is_eee){
	  mt_ele_fail_Pt10To30_endcap_fake->Fill(for_eee_pfmt_fake_electron, for_eee_norm);
	}

	if(!(for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e >= 10 && for_mme_pt_fake_e < 30) && abs(for_mme_fake_ele_eta) > 1.5 && (for_mme_gen_match_3 == 6) && is_mme){
	  mt_ele_fail_Pt10To30_endcap_fake->Fill(for_mme_pfmt_fake_electron, for_mme_norm);
	}

	if(!(for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e >= 30 && for_eee_pt_fake_e < 50) && abs(for_eee_fake_ele_eta) < 1.5 && (for_eee_gen_match_3 != 6) && is_eee){
	  mt_ele_fail_Pt30To50_barrel_prompt->Fill(for_eee_pfmt_fake_electron, for_eee_norm);
	}

	if(!(for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e >= 30 && for_mme_pt_fake_e < 50) && abs(for_mme_fake_ele_eta) < 1.5 && (for_mme_gen_match_3 != 6) && is_mme){
	  mt_ele_fail_Pt30To50_barrel_prompt->Fill(for_mme_pfmt_fake_electron, for_mme_norm);
	}

	if(!(for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e >= 30 && for_eee_pt_fake_e < 50) && abs(for_eee_fake_ele_eta) < 1.5 && (for_eee_gen_match_3 == 6) && is_eee){
	  mt_ele_fail_Pt30To50_barrel_fake->Fill(for_eee_pfmt_fake_electron, for_eee_norm);
	}

	if(!(for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e >= 30 && for_mme_pt_fake_e < 50) && abs(for_mme_fake_ele_eta) < 1.5 && (for_mme_gen_match_3 == 6) && is_mme){
	  mt_ele_fail_Pt30To50_barrel_fake->Fill(for_mme_pfmt_fake_electron, for_mme_norm);
	}

	if(!(for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e >= 30 && for_eee_pt_fake_e < 50) && abs(for_eee_fake_ele_eta) > 1.5 && (for_eee_gen_match_3 != 6) && is_eee){
	  mt_ele_fail_Pt30To50_endcap_prompt->Fill(for_eee_pfmt_fake_electron, for_eee_norm);
	}

	if(!(for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e >= 30 && for_mme_pt_fake_e < 50) && abs(for_mme_fake_ele_eta) > 1.5 && (for_mme_gen_match_3 != 6) && is_mme){
	  mt_ele_fail_Pt30To50_endcap_prompt->Fill(for_mme_pfmt_fake_electron, for_mme_norm);
	}

	if(!(for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e >= 30 && for_eee_pt_fake_e < 50) && abs(for_eee_fake_ele_eta) > 1.5 && (for_eee_gen_match_3 == 6) && is_eee){
	  mt_ele_fail_Pt30To50_endcap_fake->Fill(for_eee_pfmt_fake_electron, for_eee_norm);
	}

	if(!(for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e >= 30 && for_mme_pt_fake_e < 50) && abs(for_mme_fake_ele_eta) > 1.5 && (for_mme_gen_match_3 == 6) && is_mme){
	  mt_ele_fail_Pt30To50_endcap_fake->Fill(for_mme_pfmt_fake_electron, for_mme_norm);
	}

	if(!(for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e >= 50 && for_eee_pt_fake_e < 70) && abs(for_eee_fake_ele_eta) < 1.5 && (for_eee_gen_match_3 != 6) && is_eee){
	  mt_ele_fail_Pt50To70_barrel_prompt->Fill(for_eee_pfmt_fake_electron, for_eee_norm);
	}

	if(!(for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e >= 50 && for_mme_pt_fake_e < 70) && abs(for_mme_fake_ele_eta) < 1.5 && (for_mme_gen_match_3 != 6) && is_mme){
	  mt_ele_fail_Pt50To70_barrel_prompt->Fill(for_mme_pfmt_fake_electron, for_mme_norm);
	}

	if(!(for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e >= 50 && for_eee_pt_fake_e < 70) && abs(for_eee_fake_ele_eta) < 1.5 && (for_eee_gen_match_3 == 6) && is_eee){
	  mt_ele_fail_Pt50To70_barrel_fake->Fill(for_eee_pfmt_fake_electron, for_eee_norm);
	}

	if(!(for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e >= 50 && for_mme_pt_fake_e < 70) && abs(for_mme_fake_ele_eta) < 1.5 && (for_mme_gen_match_3 == 6) && is_mme){
	  mt_ele_fail_Pt50To70_barrel_fake->Fill(for_mme_pfmt_fake_electron, for_mme_norm);
	}

	if(!(for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e >= 50 && for_eee_pt_fake_e < 70) && abs(for_eee_fake_ele_eta) > 1.5 && (for_eee_gen_match_3 != 6) && is_eee){
	  mt_ele_fail_Pt50To70_endcap_prompt->Fill(for_eee_pfmt_fake_electron, for_eee_norm);
	}

	if(!(for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e >= 50 && for_mme_pt_fake_e < 70) && abs(for_mme_fake_ele_eta) > 1.5 && (for_mme_gen_match_3 != 6) && is_mme){
	  mt_ele_fail_Pt50To70_endcap_prompt->Fill(for_mme_pfmt_fake_electron, for_mme_norm);
	}

	if(!(for_eee_fake_ele_id && for_eee_fake_ele_iso < 0.15) && (for_eee_pt_fake_e >= 50 && for_eee_pt_fake_e < 70) && abs(for_eee_fake_ele_eta) > 1.5 && (for_eee_gen_match_3 == 6) && is_eee){
	  mt_ele_fail_Pt50To70_endcap_fake->Fill(for_eee_pfmt_fake_electron, for_eee_norm);
	}

	if(!(for_mme_fake_ele_id && for_mme_fake_ele_iso < 0.15) && (for_mme_pt_fake_e >= 50 && for_mme_pt_fake_e < 70) && abs(for_mme_fake_ele_eta) > 1.5 && (for_mme_gen_match_3 == 6) && is_mme){
	  mt_ele_fail_Pt50To70_endcap_fake->Fill(for_mme_pfmt_fake_electron, for_mme_norm);
	}

	//end mt plots for fake elec

	//mt plots for fake muon

	if((for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15) && (for_mmm_pt_fake_m>=10 && for_mmm_pt_fake_m<30) && abs(for_mmm_fake_muon_eta) < 1.2 && (for_mmm_gen_match_3 != 6) && is_mmm){
	  mt_muon_pass_Pt10To30_barrel_prompt->Fill(for_mmm_pfmt_fake_muon, for_mmm_norm);
	}

	if((for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15) && (for_eem_pt_fake_m>=10 && for_eem_pt_fake_m<30) && abs(for_eem_fake_muon_eta) < 1.2 && (for_eem_gen_match_3 != 6) && is_eem){
	  mt_muon_pass_Pt10To30_barrel_prompt->Fill(for_eem_pfmt_fake_muon, for_eem_norm);
	}

	if((for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15) && (for_mmm_pt_fake_m>=10 && for_mmm_pt_fake_m<30) && abs(for_mmm_fake_muon_eta) < 1.2 && (for_mmm_gen_match_3 == 6) && is_mmm){
	  mt_muon_pass_Pt10To30_barrel_fake->Fill(for_mmm_pfmt_fake_muon, for_mmm_norm);
	}

	if((for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15) && (for_eem_pt_fake_m>=10 && for_eem_pt_fake_m<30) && abs(for_eem_fake_muon_eta) < 1.2 && (for_eem_gen_match_3 == 6) && is_eem){
	  mt_muon_pass_Pt10To30_barrel_fake->Fill(for_eem_pfmt_fake_muon, for_eem_norm);
	}

	if((for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15) && (for_mmm_pt_fake_m>=10 && for_mmm_pt_fake_m<30) && abs(for_mmm_fake_muon_eta) > 1.2 && (for_mmm_gen_match_3 != 6) && is_mmm){
	  mt_muon_pass_Pt10To30_endcap_prompt->Fill(for_mmm_pfmt_fake_muon, for_mmm_norm);
	}

	if((for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15) && (for_eem_pt_fake_m>=10 && for_eem_pt_fake_m<30) && abs(for_eem_fake_muon_eta) > 1.2 && (for_eem_gen_match_3 != 6) && is_eem){
	  mt_muon_pass_Pt10To30_endcap_prompt->Fill(for_eem_pfmt_fake_muon, for_eem_norm);
	}

	if((for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15) && (for_mmm_pt_fake_m>=10 && for_mmm_pt_fake_m<30) && abs(for_mmm_fake_muon_eta) > 1.2 && (for_mmm_gen_match_3 == 6) && is_mmm){
	  mt_muon_pass_Pt10To30_endcap_fake->Fill(for_mmm_pfmt_fake_muon, for_mmm_norm);
	}

	if((for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15) && (for_eem_pt_fake_m>=10 && for_eem_pt_fake_m<30) && abs(for_eem_fake_muon_eta) > 1.2 && (for_eem_gen_match_3 == 6) && is_eem){
	  mt_muon_pass_Pt10To30_endcap_fake->Fill(for_eem_pfmt_fake_muon, for_eem_norm);
	}

	if((for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15) && (for_mmm_pt_fake_m>=30 && for_mmm_pt_fake_m<50) && abs(for_mmm_fake_muon_eta) < 1.2 && (for_mmm_gen_match_3 != 6) && is_mmm){
	  mt_muon_pass_Pt30To50_barrel_prompt->Fill(for_mmm_pfmt_fake_muon, for_mmm_norm);
	}

	if((for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15) && (for_eem_pt_fake_m>=30 && for_eem_pt_fake_m<50) && abs(for_eem_fake_muon_eta) < 1.2 && (for_eem_gen_match_3 != 6) && is_eem){
	  mt_muon_pass_Pt30To50_barrel_prompt->Fill(for_eem_pfmt_fake_muon, for_eem_norm);
	}

	if((for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15) && (for_mmm_pt_fake_m>=30 && for_mmm_pt_fake_m<50) && abs(for_mmm_fake_muon_eta) < 1.2 && (for_mmm_gen_match_3 == 6) && is_mmm){
	  mt_muon_pass_Pt30To50_barrel_fake->Fill(for_mmm_pfmt_fake_muon, for_mmm_norm);
	}

	if((for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15) && (for_eem_pt_fake_m>=30 && for_eem_pt_fake_m<50) && abs(for_eem_fake_muon_eta) < 1.2 && (for_eem_gen_match_3 == 6) && is_eem){
	  mt_muon_pass_Pt30To50_barrel_fake->Fill(for_eem_pfmt_fake_muon, for_eem_norm);
	}

	if((for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15) && (for_mmm_pt_fake_m>=30 && for_mmm_pt_fake_m<50) && abs(for_mmm_fake_muon_eta) > 1.2 && (for_mmm_gen_match_3 != 6) && is_mmm){
	  mt_muon_pass_Pt30To50_endcap_prompt->Fill(for_mmm_pfmt_fake_muon, for_mmm_norm);
	}

	if((for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15) && (for_eem_pt_fake_m>=30 && for_eem_pt_fake_m<50) && abs(for_eem_fake_muon_eta) > 1.2 && (for_eem_gen_match_3 != 6) && is_eem){
	  mt_muon_pass_Pt30To50_endcap_prompt->Fill(for_eem_pfmt_fake_muon, for_eem_norm);
	}

	if((for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15) && (for_mmm_pt_fake_m>=30 && for_mmm_pt_fake_m<50) && abs(for_mmm_fake_muon_eta) > 1.2 && (for_mmm_gen_match_3 == 6) && is_mmm){
	  mt_muon_pass_Pt30To50_endcap_fake->Fill(for_mmm_pfmt_fake_muon, for_mmm_norm);
	}

	if((for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15) && (for_eem_pt_fake_m>=30 && for_eem_pt_fake_m<50) && abs(for_eem_fake_muon_eta) > 1.2 && (for_eem_gen_match_3 == 6) && is_eem){
	  mt_muon_pass_Pt30To50_endcap_fake->Fill(for_eem_pfmt_fake_muon, for_eem_norm);
	}

	if((for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15) && (for_mmm_pt_fake_m>=50 && for_mmm_pt_fake_m<70) && abs(for_mmm_fake_muon_eta) < 1.2 && (for_mmm_gen_match_3 != 6) && is_mmm){
	  mt_muon_pass_Pt50To70_barrel_prompt->Fill(for_mmm_pfmt_fake_muon, for_mmm_norm);
	}

	if((for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15) && (for_eem_pt_fake_m>=50 && for_eem_pt_fake_m<70) && abs(for_eem_fake_muon_eta) < 1.2 && (for_eem_gen_match_3 != 6) && is_eem){
	  mt_muon_pass_Pt50To70_barrel_prompt->Fill(for_eem_pfmt_fake_muon, for_eem_norm);
	}

	if((for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15) && (for_mmm_pt_fake_m>=50 && for_mmm_pt_fake_m<70) && abs(for_mmm_fake_muon_eta) < 1.2 && (for_mmm_gen_match_3 == 6) && is_mmm){
	  mt_muon_pass_Pt50To70_barrel_fake->Fill(for_mmm_pfmt_fake_muon, for_mmm_norm);
	}

	if((for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15) && (for_eem_pt_fake_m>=50 && for_eem_pt_fake_m<70) && abs(for_eem_fake_muon_eta) < 1.2 && (for_eem_gen_match_3 == 6) && is_eem){
	  mt_muon_pass_Pt50To70_barrel_fake->Fill(for_eem_pfmt_fake_muon, for_eem_norm);
	}

	if((for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15) && (for_mmm_pt_fake_m>=50 && for_mmm_pt_fake_m<70) && abs(for_mmm_fake_muon_eta) > 1.2 && (for_mmm_gen_match_3 != 6) && is_mmm){
	  mt_muon_pass_Pt50To70_endcap_prompt->Fill(for_mmm_pfmt_fake_muon, for_mmm_norm);
	}

	if((for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15) && (for_eem_pt_fake_m>=50 && for_eem_pt_fake_m<70) && abs(for_eem_fake_muon_eta) > 1.2 && (for_eem_gen_match_3 != 6) && is_eem){
	  mt_muon_pass_Pt50To70_endcap_prompt->Fill(for_eem_pfmt_fake_muon, for_eem_norm);
	}

	if((for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15) && (for_mmm_pt_fake_m>=50 && for_mmm_pt_fake_m<70) && abs(for_mmm_fake_muon_eta) > 1.2 && (for_mmm_gen_match_3 == 6) && is_mmm){
	  mt_muon_pass_Pt50To70_endcap_fake->Fill(for_mmm_pfmt_fake_muon, for_mmm_norm);
	}

	if((for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15) && (for_eem_pt_fake_m>=50 && for_eem_pt_fake_m<70) && abs(for_eem_fake_muon_eta) > 1.2 && (for_eem_gen_match_3 == 6) && is_eem){
	  mt_muon_pass_Pt50To70_endcap_fake->Fill(for_eem_pfmt_fake_muon, for_eem_norm);
	}

	if(!(for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15) && (for_mmm_pt_fake_m>=10 && for_mmm_pt_fake_m<30) && abs(for_mmm_fake_muon_eta) < 1.2 && (for_mmm_gen_match_3 != 6) && is_mmm){
	  mt_muon_fail_Pt10To30_barrel_prompt->Fill(for_mmm_pfmt_fake_muon, for_mmm_norm);
	}

	if(!(for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15) && (for_eem_pt_fake_m>=10 && for_eem_pt_fake_m<30) && abs(for_eem_fake_muon_eta) < 1.2 && (for_eem_gen_match_3 != 6) && is_eem){
	  mt_muon_fail_Pt10To30_barrel_prompt->Fill(for_eem_pfmt_fake_muon, for_eem_norm);
	}

	if(!(for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15) && (for_mmm_pt_fake_m>=10 && for_mmm_pt_fake_m<30) && abs(for_mmm_fake_muon_eta) < 1.2 && (for_mmm_gen_match_3 == 6) && is_mmm){
	  mt_muon_fail_Pt10To30_barrel_fake->Fill(for_mmm_pfmt_fake_muon, for_mmm_norm);
	}

	if(!(for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15) && (for_eem_pt_fake_m>=10 && for_eem_pt_fake_m<30) && abs(for_eem_fake_muon_eta) < 1.2 && (for_eem_gen_match_3 == 6) && is_eem){
	  mt_muon_fail_Pt10To30_barrel_fake->Fill(for_eem_pfmt_fake_muon, for_eem_norm);
	}

	if(!(for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15) && (for_mmm_pt_fake_m>=10 && for_mmm_pt_fake_m<30) && abs(for_mmm_fake_muon_eta) > 1.2 && (for_mmm_gen_match_3 != 6) && is_mmm){
	  mt_muon_fail_Pt10To30_endcap_prompt->Fill(for_mmm_pfmt_fake_muon, for_mmm_norm);
	}

	if(!(for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15) && (for_eem_pt_fake_m>=10 && for_eem_pt_fake_m<30) && abs(for_eem_fake_muon_eta) > 1.2 && (for_eem_gen_match_3 != 6) && is_eem){
	  mt_muon_fail_Pt10To30_endcap_prompt->Fill(for_eem_pfmt_fake_muon, for_eem_norm);
	}

	if(!(for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15) && (for_mmm_pt_fake_m>=10 && for_mmm_pt_fake_m<30) && abs(for_mmm_fake_muon_eta) > 1.2 && (for_mmm_gen_match_3 == 6) && is_mmm){
	  mt_muon_fail_Pt10To30_endcap_fake->Fill(for_mmm_pfmt_fake_muon, for_mmm_norm);
	}

	if(!(for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15) && (for_eem_pt_fake_m>=10 && for_eem_pt_fake_m<30) && abs(for_eem_fake_muon_eta) > 1.2 && (for_eem_gen_match_3 == 6) && is_eem){
	  mt_muon_fail_Pt10To30_endcap_fake->Fill(for_eem_pfmt_fake_muon, for_eem_norm);
	}

	if(!(for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15) && (for_mmm_pt_fake_m>=30 && for_mmm_pt_fake_m<50) && abs(for_mmm_fake_muon_eta) < 1.2 && (for_mmm_gen_match_3 != 6) && is_mmm){
	  mt_muon_fail_Pt30To50_barrel_prompt->Fill(for_mmm_pfmt_fake_muon, for_mmm_norm);
	}

	if(!(for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15) && (for_eem_pt_fake_m>=30 && for_eem_pt_fake_m<50) && abs(for_eem_fake_muon_eta) < 1.2 && (for_eem_gen_match_3 != 6) && is_eem){
	  mt_muon_fail_Pt30To50_barrel_prompt->Fill(for_eem_pfmt_fake_muon, for_eem_norm);
	}

	if(!(for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15) && (for_mmm_pt_fake_m>=30 && for_mmm_pt_fake_m<50) && abs(for_mmm_fake_muon_eta) < 1.2 && (for_mmm_gen_match_3 == 6) && is_mmm){
	  mt_muon_fail_Pt30To50_barrel_fake->Fill(for_mmm_pfmt_fake_muon, for_mmm_norm);
	}

	if(!(for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15) && (for_eem_pt_fake_m>=30 && for_eem_pt_fake_m<50) && abs(for_eem_fake_muon_eta) < 1.2 && (for_eem_gen_match_3 == 6) && is_eem){
	  mt_muon_fail_Pt30To50_barrel_fake->Fill(for_eem_pfmt_fake_muon, for_eem_norm);
	}

	if(!(for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15) && (for_mmm_pt_fake_m>=30 && for_mmm_pt_fake_m<50) && abs(for_mmm_fake_muon_eta) > 1.2 && (for_mmm_gen_match_3 != 6) && is_mmm){
	  mt_muon_fail_Pt30To50_endcap_prompt->Fill(for_mmm_pfmt_fake_muon, for_mmm_norm);
	}

	if(!(for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15) && (for_eem_pt_fake_m>=30 && for_eem_pt_fake_m<50) && abs(for_eem_fake_muon_eta) > 1.2 && (for_eem_gen_match_3 != 6) && is_eem){
	  mt_muon_fail_Pt30To50_endcap_prompt->Fill(for_eem_pfmt_fake_muon, for_eem_norm);
	}

	if(!(for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15) && (for_mmm_pt_fake_m>=30 && for_mmm_pt_fake_m<50) && abs(for_mmm_fake_muon_eta) > 1.2 && (for_mmm_gen_match_3 == 6) && is_mmm){
	  mt_muon_fail_Pt30To50_endcap_fake->Fill(for_mmm_pfmt_fake_muon, for_mmm_norm);
	}

	if(!(for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15) && (for_eem_pt_fake_m>=30 && for_eem_pt_fake_m<50) && abs(for_eem_fake_muon_eta) > 1.2 && (for_eem_gen_match_3 == 6) && is_eem){
	  mt_muon_fail_Pt30To50_endcap_fake->Fill(for_eem_pfmt_fake_muon, for_eem_norm);
	}

	if(!(for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15) && (for_mmm_pt_fake_m>=50 && for_mmm_pt_fake_m<70) && abs(for_mmm_fake_muon_eta) < 1.2 && (for_mmm_gen_match_3 != 6) && is_mmm){
	  mt_muon_fail_Pt50To70_barrel_prompt->Fill(for_mmm_pfmt_fake_muon, for_mmm_norm);
	}

	if(!(for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15) && (for_eem_pt_fake_m>=50 && for_eem_pt_fake_m<70) && abs(for_eem_fake_muon_eta) < 1.2 && (for_eem_gen_match_3 != 6) && is_eem){
	  mt_muon_fail_Pt50To70_barrel_prompt->Fill(for_eem_pfmt_fake_muon, for_eem_norm);
	}

	if(!(for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15) && (for_mmm_pt_fake_m>=50 && for_mmm_pt_fake_m<70) && abs(for_mmm_fake_muon_eta) < 1.2 && (for_mmm_gen_match_3 == 6) && is_mmm){
	  mt_muon_fail_Pt50To70_barrel_fake->Fill(for_mmm_pfmt_fake_muon, for_mmm_norm);
	}

	if(!(for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15) && (for_eem_pt_fake_m>=50 && for_eem_pt_fake_m<70) && abs(for_eem_fake_muon_eta) < 1.2 && (for_eem_gen_match_3 == 6) && is_eem){
	  mt_muon_fail_Pt50To70_barrel_fake->Fill(for_eem_pfmt_fake_muon, for_eem_norm);
	}

	if(!(for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15) && (for_mmm_pt_fake_m>=50 && for_mmm_pt_fake_m<70) && abs(for_mmm_fake_muon_eta) > 1.2 && (for_mmm_gen_match_3 != 6) && is_mmm){
	  mt_muon_fail_Pt50To70_endcap_prompt->Fill(for_mmm_pfmt_fake_muon, for_mmm_norm);
	}

	if(!(for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15) && (for_eem_pt_fake_m>=50 && for_eem_pt_fake_m<70) && abs(for_eem_fake_muon_eta) > 1.2 && (for_eem_gen_match_3 != 6) && is_eem){
	  mt_muon_fail_Pt50To70_endcap_prompt->Fill(for_eem_pfmt_fake_muon, for_eem_norm);
	}

	if(!(for_mmm_fake_muon_id && for_mmm_fake_muon_iso < 0.15) && (for_mmm_pt_fake_m>=50 && for_mmm_pt_fake_m<70) && abs(for_mmm_fake_muon_eta) > 1.2 && (for_mmm_gen_match_3 == 6) && is_mmm){
	  mt_muon_fail_Pt50To70_endcap_fake->Fill(for_mmm_pfmt_fake_muon, for_mmm_norm);
	}

	if(!(for_eem_fake_muon_id && for_eem_fake_muon_iso < 0.15) && (for_eem_pt_fake_m>=50 && for_eem_pt_fake_m<70) && abs(for_eem_fake_muon_eta) > 1.2 && (for_eem_gen_match_3 == 6) && is_eem){
	  mt_muon_fail_Pt50To70_endcap_fake->Fill(for_eem_pfmt_fake_muon, for_eem_norm);
	}

	//end mt plots for fake muon

      }//if(is>0)


    }//    for(int ie=0; ie<100; ie++){


    f->Close();
    f_out->Write();
    f_out->Close();
  }//  for(int is =0;is<8;is++){
   
}//void pass_fail_plots(){
