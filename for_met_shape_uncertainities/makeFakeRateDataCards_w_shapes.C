#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <algorithm> // std::max
#include <sys/types.h>
#include <sys/stat.h>

/* 
Run instructions
root -l -b 
.L makeFakeRateDataCard.C
makeFakeRateDataCards()
*/

// lepType: e, mu
// region: pass, fail

void makeFakeRateDataCard(string lepType, string region, string ptbin, string etabin)
{

  //create datacard directory, if not exists
  if (mkdir("datacards", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == -1)
    {
      if( errno == EEXIST ) {
	// alredy exists 
      } else {
        // something else
	std::cout << "cannot create directory datacards, error:" << strerror(errno) << std::endl;
        throw std::runtime_error( strerror(errno) );
      }
    }
  TString outFile(Form("datacards/shapes_%s_%s_%s_%s.root", lepType.c_str(), region.c_str(), ptbin.c_str(), etabin.c_str()));
  TFile* fout = new TFile(outFile, "RECREATE");

  TString inputFilePath("./mt_plots/");
  //Fill DY
  TFile* fDY = TFile::Open(inputFilePath+"plots_DYJetsToLL_M-50.root", "READ");
  if(fDY == 0) return;
  if(fDY->IsZombie()){fDY->Close(); return;}

  fout->cd();
  TH1F* prompt_DY = (TH1F*)(fDY->Get(("mt_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_prompt").c_str()))->Clone("prompt");
  TH1F* prompt_DY_JetEnUp = (TH1F*)(fDY->Get(("mt_JetEnUp_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_prompt").c_str()))->Clone("prompt_JetEnUp");
  TH1F* prompt_DY_JetEnDown = (TH1F*)(fDY->Get(("mt_JetEnDown_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_prompt").c_str()))->Clone("prompt_JetEnDown");
  TH1F* prompt_DY_UnclusteredEnUp = (TH1F*)(fDY->Get(("mt_UnclusteredEnUp_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_prompt").c_str()))->Clone("prompt_UnclusteredEnUp");
  TH1F* prompt_DY_UnclusteredEnDown = (TH1F*)(fDY->Get(("mt_UnclusteredEnDown_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_prompt").c_str()))->Clone("prompt_UnclusteredEnDown");
  TH1F* prompt_DY_JetResUp = (TH1F*)(fDY->Get(("mt_JetResUp_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_prompt").c_str()))->Clone("prompt_JetResUp");
  TH1F* prompt_DY_JetResDown = (TH1F*)(fDY->Get(("mt_JetResDown_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_prompt").c_str()))->Clone("prompt_JetResDown");
  //prompt_DY->SetName("prompt");
  //prompt->Write("prompt");
  TH1F* prompt = (TH1F*)prompt_DY->Clone();
  prompt->SetName("prompt");                                                                                                                 

  TH1F* prompt_JetEnUp = (TH1F*)prompt_DY_JetEnUp->Clone();
  prompt_JetEnUp->SetName("prompt_JetEnUp");                                                                                                 

  TH1F* prompt_JetEnDown = (TH1F*)prompt_DY_JetEnDown->Clone();
  prompt_JetEnDown->SetName("prompt_JetEnDown");                                                                                             

  TH1F* prompt_UnclusteredEnUp = (TH1F*)prompt_DY_UnclusteredEnUp->Clone();
  prompt_UnclusteredEnUp->SetName("prompt_UnclusteredEnUp");  

  TH1F* prompt_UnclusteredEnDown = (TH1F*)prompt_DY_UnclusteredEnDown->Clone();
  prompt_UnclusteredEnDown->SetName("prompt_UnclusteredEnDown"); 

  TH1F* prompt_JetResUp = (TH1F*)prompt_DY_JetResUp->Clone();
  prompt_JetResUp->SetName("prompt_JetResUp");

  TH1F* prompt_JetResDown = (TH1F*)prompt_DY_JetResDown->Clone();
  prompt_JetResDown->SetName("prompt_JetResDown");                                                                                                                       

  TH1F* fake_DY = (TH1F*)(fDY->Get(("mt_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_fake").c_str()))->Clone("fake");
  TH1F* fake_DY_JetEnUp = (TH1F*)(fDY->Get(("mt_JetEnUp_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_fake").c_str()))->Clone("fake_JetEnUp");
  TH1F* fake_DY_JetEnDown = (TH1F*)(fDY->Get(("mt_JetEnDown_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_fake").c_str()))->Clone("fake_JetEnDown");
  TH1F* fake_DY_UnclusteredEnUp = (TH1F*)(fDY->Get(("mt_UnclusteredEnUp_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_fake").c_str()))->Clone("fake_UnclusteredEnUp");
  TH1F* fake_DY_UnclusteredEnDown = (TH1F*)(fDY->Get(("mt_UnclusteredEnDown_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_fake").c_str()))->Clone("fake_UnclusteredEnDown");
  TH1F* fake_DY_JetResUp = (TH1F*)(fDY->Get(("mt_JetResUp_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_fake").c_str()))->Clone("fake_JetResUp");
  TH1F* fake_DY_JetResDown = (TH1F*)(fDY->Get(("mt_JetResDown_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_fake").c_str()))->Clone("fake_JetResDown");
  //fake->SetName("fake");
  //fake->Write("fake");
  TH1F* fake = (TH1F*)fake_DY->Clone();
  fake->SetName("fake"); 

  TH1F* fake_JetEnUp = (TH1F*)fake_DY_JetEnUp->Clone();
  fake_JetEnUp->SetName("fake_JetEnUp"); 

  TH1F* fake_JetEnDown = (TH1F*)fake_DY_JetEnDown->Clone();
  fake_JetEnDown->SetName("fake_JetEnDown"); 

  TH1F* fake_UnclusteredEnUp = (TH1F*)fake_DY_UnclusteredEnUp->Clone();
  fake_UnclusteredEnUp->SetName("fake_UnclusteredEnUp"); 

  TH1F* fake_UnclusteredEnDown = (TH1F*)fake_DY_UnclusteredEnDown->Clone();
  fake_UnclusteredEnDown->SetName("fake_UnclusteredEnDown"); 

  TH1F* fake_JetResUp = (TH1F*)fake_DY_JetResUp->Clone();
  fake_JetResUp->SetName("fake_JetResUp"); 

  TH1F* fake_JetResDown = (TH1F*)fake_DY_JetResDown->Clone();
  fake_JetResDown->SetName("fake_JetResDown"); 

  fDY->Close();

  //Fill TTBar
  TFile* ftt = TFile::Open(inputFilePath+"plots_TTbar.root", "READ");
  if(ftt == 0) return;
  if(ftt->IsZombie()){ftt->Close(); return;}

  TH1F* prompt_tt = (TH1F*)(ftt->Get(("mt_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_prompt").c_str()))->Clone("prompt");
  prompt->Add(prompt_tt);

  TH1F* prompt_tt_JetEnUp = (TH1F*)(ftt->Get(("mt_JetEnUp_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_prompt").c_str()))->Clone("prompt_JetEnUp");
  prompt_JetEnUp->Add(prompt_tt_JetEnUp);

  TH1F* prompt_tt_JetEnDown = (TH1F*)(ftt->Get(("mt_JetEnDown_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_prompt").c_str()))->Clone("prompt_JetEnDown");
  prompt_JetEnDown->Add(prompt_tt_JetEnDown);

  TH1F* prompt_tt_UnclusteredEnUp = (TH1F*)(ftt->Get(("mt_UnclusteredEnUp_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_prompt").c_str()))->Clone("prompt_UnclusteredEnUp");
  prompt_UnclusteredEnUp->Add(prompt_tt_UnclusteredEnUp);

  TH1F* prompt_tt_UnclusteredEnDown = (TH1F*)(ftt->Get(("mt_UnclusteredEnDown_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_prompt").c_str()))->Clone("prompt_UnclusteredEnDown");
  prompt_UnclusteredEnDown->Add(prompt_tt_UnclusteredEnDown);

  TH1F* prompt_tt_JetResUp = (TH1F*)(ftt->Get(("mt_JetResUp_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_prompt").c_str()))->Clone("prompt_JetResUp");
  prompt_JetResUp->Add(prompt_tt_JetResUp);

  TH1F* prompt_tt_JetResDown = (TH1F*)(ftt->Get(("mt_JetResDown_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_prompt").c_str()))->Clone("prompt_JetResDown");
  prompt_JetResDown->Add(prompt_tt_JetResDown);

  TH1F* fake_tt_JetEnUp = (TH1F*)(ftt->Get(("mt_JetEnUp_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_fake").c_str()))->Clone("fake_JetEnUp");
  fake_JetEnUp->Add(fake_tt_JetEnUp);

  TH1F* fake_tt_JetEnDown = (TH1F*)(ftt->Get(("mt_JetEnDown_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_fake").c_str()))->Clone("fake_JetEnDown");
  fake_JetEnDown->Add(fake_tt_JetEnDown);

  TH1F* fake_tt_UnclusteredEnUp = (TH1F*)(ftt->Get(("mt_UnclusteredEnUp_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_fake").c_str()))->Clone("fake_UnclusteredEnUp");
  fake_UnclusteredEnUp->Add(fake_tt_UnclusteredEnUp);

  TH1F* fake_tt_UnclusteredEnDown = (TH1F*)(ftt->Get(("mt_UnclusteredEnDown_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_fake").c_str()))->Clone("fake_UnclusteredEnDown");
  fake_UnclusteredEnDown->Add(fake_tt_UnclusteredEnDown);

  TH1F* fake_tt_JetResUp = (TH1F*)(ftt->Get(("mt_JetResUp_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_fake").c_str()))->Clone("fake_JetResUp");
  fake_JetResUp->Add(fake_tt_JetResUp);

  TH1F* fake_tt_JetResDown = (TH1F*)(ftt->Get(("mt_JetResDown_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_fake").c_str()))->Clone("fake_JetResDown");
  fake_JetResDown->Add(fake_tt_JetResDown);

  TH1F* fake_tt = (TH1F*)(ftt->Get(("mt_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_fake").c_str()))->Clone("fake");
  fake->Add(fake_tt);

  ftt->Close();
  
  //Fill VV
  TFile* fvv = TFile::Open(inputFilePath+"plots_Diboson.root", "READ");
  if(fvv == 0) return;
  if(fvv->IsZombie()){fvv->Close(); return;}

  TH1F* prompt_vv = (TH1F*)(fvv->Get(("mt_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_prompt").c_str()))->Clone("prompt");
  prompt->Add(prompt_vv);

  TH1F* prompt_vv_JetEnUp = (TH1F*)(fvv->Get(("mt_JetEnUp_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_prompt").c_str()))->Clone("prompt_JetEnUp");
  prompt_JetEnUp->Add(prompt_vv_JetEnUp);

  TH1F* prompt_vv_JetEnDown = (TH1F*)(fvv->Get(("mt_JetEnDown_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_prompt").c_str()))->Clone("prompt_JetEnDown");
  prompt_JetEnDown->Add(prompt_vv_JetEnDown);

  TH1F* prompt_vv_UnclusteredEnUp = (TH1F*)(fvv->Get(("mt_UnclusteredEnUp_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_prompt").c_str()))->Clone("prompt_UnclusteredEnUp");
  prompt_UnclusteredEnUp->Add(prompt_vv_UnclusteredEnUp);

  TH1F* prompt_vv_UnclusteredEnDown = (TH1F*)(fvv->Get(("mt_UnclusteredEnDown_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_prompt").c_str()))->Clone("prompt_UnclusteredEnDown");
  prompt_UnclusteredEnDown->Add(prompt_vv_UnclusteredEnDown);

  TH1F* prompt_vv_JetResUp = (TH1F*)(fvv->Get(("mt_JetResUp_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_prompt").c_str()))->Clone("prompt_JetResUp");
  prompt_JetResUp->Add(prompt_vv_JetResUp);

  TH1F* prompt_vv_JetResDown = (TH1F*)(fvv->Get(("mt_JetResDown_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_prompt").c_str()))->Clone("prompt_JetResDown");
  prompt_JetResDown->Add(prompt_vv_JetResDown);

  TH1F* fake_vv_JetEnUp = (TH1F*)(fvv->Get(("mt_JetEnUp_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_fake").c_str()))->Clone("fake_JetEnUp");
  fake_JetEnUp->Add(fake_vv_JetEnUp);

  TH1F* fake_vv_JetEnDown = (TH1F*)(fvv->Get(("mt_JetEnDown_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_fake").c_str()))->Clone("fake_JetEnDown");
  fake_JetEnDown->Add(fake_vv_JetEnDown);

  TH1F* fake_vv_UnclusteredEnUp = (TH1F*)(fvv->Get(("mt_UnclusteredEnUp_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_fake").c_str()))->Clone("fake_UnclusteredEnUp");
  fake_UnclusteredEnUp->Add(fake_vv_UnclusteredEnUp);

  TH1F* fake_vv_UnclusteredEnDown = (TH1F*)(fvv->Get(("mt_UnclusteredEnDown_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_fake").c_str()))->Clone("fake_UnclusteredEnDown");
  fake_UnclusteredEnDown->Add(fake_vv_UnclusteredEnDown);

  TH1F* fake_vv_JetResUp = (TH1F*)(fvv->Get(("mt_JetResUp_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_fake").c_str()))->Clone("fake_JetResUp");
  fake_JetResUp->Add(fake_vv_JetResUp);

  TH1F* fake_vv_JetResDown = (TH1F*)(fvv->Get(("mt_JetResDown_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_fake").c_str()))->Clone("fake_JetResDown");
  fake_JetResDown->Add(fake_vv_JetResDown);

  TH1F* fake_vv = (TH1F*)(fvv->Get(("mt_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_fake").c_str()))->Clone("fake");
  fake->Add(fake_vv);

  fvv->Close();

  //Fill other
  TFile* fother = TFile::Open(inputFilePath+"plots_other.root", "READ");
  if(fother == 0) return;
  if(fother->IsZombie()){fother->Close(); return;}

  TH1F* prompt_other = (TH1F*)(fother->Get(("mt_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_prompt").c_str()))->Clone("prompt");
  prompt->Add(prompt_other);

  TH1F* prompt_other_JetEnUp = (TH1F*)(fother->Get(("mt_JetEnUp_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_prompt").c_str()))->Clone("prompt_JetEnUp");
  prompt_JetEnUp->Add(prompt_other_JetEnUp);

  TH1F* prompt_other_JetEnDown = (TH1F*)(fother->Get(("mt_JetEnDown_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_prompt").c_str()))->Clone("prompt_JetEnDown");
  prompt_JetEnDown->Add(prompt_other_JetEnDown);

  TH1F* prompt_other_UnclusteredEnUp = (TH1F*)(fother->Get(("mt_UnclusteredEnUp_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_prompt").c_str()))->Clone("prompt_UnclusteredEnUp");
  prompt_UnclusteredEnUp->Add(prompt_other_UnclusteredEnUp);

  TH1F* prompt_other_UnclusteredEnDown = (TH1F*)(fother->Get(("mt_UnclusteredEnDown_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_prompt").c_str()))->Clone("prompt_UnclusteredEnDown");
  prompt_UnclusteredEnDown->Add(prompt_other_UnclusteredEnDown);

  TH1F* prompt_other_JetResUp = (TH1F*)(fother->Get(("mt_JetResUp_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_prompt").c_str()))->Clone("prompt_JetResUp");
  prompt_JetResUp->Add(prompt_other_JetResUp);

  TH1F* prompt_other_JetResDown = (TH1F*)(fother->Get(("mt_JetResDown_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_prompt").c_str()))->Clone("prompt_JetResDown");
  prompt_JetResDown->Add(prompt_other_JetResDown);

  TH1F* fake_other = (TH1F*)(fother->Get(("mt_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_fake").c_str()))->Clone("fake");
  fake->Add(fake_other);

  TH1F* fake_other_JetEnUp = (TH1F*)(fother->Get(("mt_JetEnUp_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_fake").c_str()))->Clone("fake_JetEnUp");
  fake_JetEnUp->Add(fake_other_JetEnUp);

  TH1F* fake_other_JetEnDown = (TH1F*)(fother->Get(("mt_JetEnDown_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_fake").c_str()))->Clone("fake_JetEnDown");
  fake_JetEnDown->Add(fake_other_JetEnDown);

  TH1F* fake_other_UnclusteredEnUp = (TH1F*)(fother->Get(("mt_UnclusteredEnUp_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_fake").c_str()))->Clone("fake_UnclusteredEnUp");
  fake_UnclusteredEnUp->Add(fake_other_UnclusteredEnUp);

  TH1F* fake_other_UnclusteredEnDown = (TH1F*)(fother->Get(("mt_UnclusteredEnDown_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_fake").c_str()))->Clone("fake_UnclusteredEnDown");
  fake_UnclusteredEnDown->Add(fake_other_UnclusteredEnDown);

  TH1F* fake_other_JetResUp = (TH1F*)(fother->Get(("mt_JetResUp_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_fake").c_str()))->Clone("fake_JetResUp");
  fake_JetResUp->Add(fake_other_JetResUp);

  TH1F* fake_other_JetResDown = (TH1F*)(fother->Get(("mt_JetResDown_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_fake").c_str()))->Clone("fake_JetResDown");
  fake_JetResDown->Add(fake_other_JetResDown);

  fother->Close();


  fout->cd();
  prompt->Write();
  prompt_JetEnUp->Write();
  prompt_JetEnDown->Write();
  prompt_UnclusteredEnUp->Write();
  prompt_UnclusteredEnDown->Write();
  prompt_JetResUp->Write();
  prompt_JetResDown->Write();

  fake->Write();
  fake_JetEnUp->Write();
  fake_JetEnDown->Write();
  fake_UnclusteredEnUp->Write();
  fake_UnclusteredEnDown->Write();
  fake_JetResUp->Write();
  fake_JetResDown->Write();

  //Fill Data
  TFile* fdata = TFile::Open(inputFilePath+"plots_data.root", "READ");
  if(fdata == 0) return;
  if(fdata->IsZombie()){fdata->Close(); return;}

  TH1F* data = (TH1F*)(fdata->Get(("mt_"+lepType+"_"+region+"_"+ptbin+"_"+etabin+"_data").c_str()))->Clone("data");
  data->SetName("data_obs");
  fout->cd();
  data->Write("data_obs");

  //Make Data card for each bins
  ifstream in;
  char* c = new char[1000];
  in.open("template/datacard_fit_template.txt");


  //create new datacard.txt files
  ofstream out(Form("datacards/datacard_fit_%s_%s_%s_%s.txt", lepType.c_str(), region.c_str(), ptbin.c_str(), etabin.c_str()));
  out.precision(8);

  time_t secs=time(0);
  tm *t=localtime(&secs);
  
  while (in.good())
    {
      in.getline(c,1000,'\n');
      if (in.good()){
	string line(c);
          
	if(line.find("Date")!=string::npos){
	  string day = string(Form("%d",t->tm_mday));
	  string month = string(Form("%d",t->tm_mon+1));
	  string year = string(Form("%d",t->tm_year+1900));
	  line.replace( line.find("XXX") , 3 , day+"/"+month+"/"+year);
	  out << line << endl;
	}
	else if(line.find("shapes")!=string::npos){
	  line.replace( line.find("XXX") , 3 , string(Form("datacards/shapes_%s_%s_%s_%s", lepType.c_str(), region.c_str(), ptbin.c_str(), etabin.c_str()))  );
	  out << line << endl;
	}
	else if(line.find("Observation")!=string::npos){
	  line.replace( line.find("XXX") , 3 , string(Form("%.0f", data->Integral()) )  );
	  out << line << endl;
	}
	else if(line.find("rate")!=string::npos && line.find("rateParam")==string::npos){
	  string rate = "rate      ";  
	  string space = "      ";
	  out << rate ;
	  out << space << fake->Integral()
	      << space << prompt->Integral()
	      << space <<endl;
	}
	else if(line.find("CMS_norm_fake")!=string::npos){
	  line.replace( line.find("XXXX") , 4 , string(Form("%.2f", 1.10)) ); 
	  out << line << endl;
	}
	else if(line.find("CMS_norm_prompt")!=string::npos){
          line.replace( line.find("XXXX") , 4 , string(Form("%.2f", 1.10)) );
          out << line << endl;
	}
	else{
	  out << c << endl;
	}
      }
    }
        
  out.close();
  in.close();
  fout->Close();
}

void makeFakeRateDataCards_w_shapes()
{
  makeFakeRateDataCard("muon", "pass", "Pt10To30", "barrel");
  makeFakeRateDataCard("muon", "pass", "Pt10To30", "endcap");
  makeFakeRateDataCard("muon", "fail", "Pt10To30", "barrel");
  makeFakeRateDataCard("muon", "fail", "Pt10To30", "endcap");
  makeFakeRateDataCard("muon", "pass", "Pt30To50", "barrel");
  makeFakeRateDataCard("muon", "pass", "Pt30To50", "endcap");
  makeFakeRateDataCard("muon", "fail", "Pt30To50", "barrel");
  makeFakeRateDataCard("muon", "fail", "Pt30To50", "endcap");
  makeFakeRateDataCard("muon", "pass", "Pt50To70", "barrel");
  makeFakeRateDataCard("muon", "pass", "Pt50To70", "endcap");
  makeFakeRateDataCard("muon", "fail", "Pt50To70", "barrel");
  makeFakeRateDataCard("muon", "fail", "Pt50To70", "endcap");

  makeFakeRateDataCard("ele", "pass", "Pt10To30", "barrel");
  makeFakeRateDataCard("ele", "pass", "Pt10To30", "endcap");
  makeFakeRateDataCard("ele", "fail", "Pt10To30", "barrel");
  makeFakeRateDataCard("ele", "fail", "Pt10To30", "endcap");
  makeFakeRateDataCard("ele", "pass", "Pt30To50", "barrel");
  makeFakeRateDataCard("ele", "pass", "Pt30To50", "endcap");
  makeFakeRateDataCard("ele", "fail", "Pt30To50", "barrel");
  makeFakeRateDataCard("ele", "fail", "Pt30To50", "endcap");
  makeFakeRateDataCard("ele", "pass", "Pt50To70", "barrel");
  makeFakeRateDataCard("ele", "pass", "Pt50To70", "endcap");
  makeFakeRateDataCard("ele", "fail", "Pt50To70", "barrel");
  makeFakeRateDataCard("ele", "fail", "Pt50To70", "endcap");

  gApplication->Terminate();
}
  
