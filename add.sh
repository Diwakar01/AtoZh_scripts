cmsenv

cd ../../

rm plots*root

cd ..

root -l -b pass_fail_plots_def3.C

cd pass_fail_files

hadd -f ./A2ZhFakeFactorScripts/mt_plots/plots_data.root plots_EGamma_0.root plots_SingleMuon_1.root

rm plots_EGamma_0.root plots_SingleMuon_1.root

hadd -f ./A2ZhFakeFactorScripts/mt_plots/plots_DYJetsToLL_M-50.root plots_DY*root

rm plots_DY*root

hadd -f ./A2ZhFakeFactorScripts/mt_plots/plots_Diboson.root plots_WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8_34.root plots_WZTo3LNu_TuneCP5_13TeV-amcatnloFXFX-pythia8_32.root plots_ZZTo2L2Q_38.root plots_ZZTo4L_TuneCP5_13TeV_powheg_pythia8_36.root

rm plots_WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8_34.root plots_WZTo3LNu_TuneCP5_13TeV-amcatnloFXFX-pythia8_32.root plots_ZZTo2L2Q_38.root plots_ZZTo4L_TuneCP5_13TeV_powheg_pythia8_36.root

hadd -f ./A2ZhFakeFactorScripts/mt_plots/plots_TTbar.root plots_TTTo*root

rm plots_TTTo*root

hadd -f ./A2ZhFakeFactorScripts/mt_plots/plots_other.root *root

cd ./A2ZhFakeFactorScripts/

root -l makeFakeRateDataCards_def2.C

python makeFakeRatePlots_def2.py --lepType ele --etabin barrel
python makeFakeRatePlots_def2.py --lepType ele --etabin endcap
python makeFakeRatePlots_def2.py --lepType muon --etabin barrel
python makeFakeRatePlots_def2.py --lepType muon --etabin endcap

python makePostFitPlots.py --lepType ele --region pass --ptbin Pt10To30 --etabin barrel --prefit True
python makePostFitPlots.py --lepType ele --region pass --ptbin Pt10To30 --etabin endcap --prefit True
python makePostFitPlots.py --lepType ele --region pass --ptbin Pt30To50 --etabin barrel --prefit True
python makePostFitPlots.py --lepType ele --region pass --ptbin Pt30To50 --etabin endcap --prefit True
python makePostFitPlots.py --lepType ele --region pass --ptbin Pt50To70 --etabin barrel --prefit True
python makePostFitPlots.py --lepType ele --region pass --ptbin Pt50To70 --etabin endcap --prefit True
python makePostFitPlots.py --lepType ele --region fail --ptbin Pt10To30 --etabin barrel --prefit True
python makePostFitPlots.py --lepType ele --region fail --ptbin Pt10To30 --etabin endcap --prefit True
python makePostFitPlots.py --lepType ele --region fail --ptbin Pt30To50 --etabin barrel --prefit True
python makePostFitPlots.py --lepType ele --region fail --ptbin Pt30To50 --etabin endcap --prefit True
python makePostFitPlots.py --lepType ele --region fail --ptbin Pt50To70 --etabin barrel --prefit True
python makePostFitPlots.py --lepType ele --region fail --ptbin Pt50To70 --etabin endcap --prefit True
python makePostFitPlots.py --lepType muon --region pass --ptbin Pt10To30 --etabin barrel --prefit True
python makePostFitPlots.py --lepType muon --region pass --ptbin Pt10To30 --etabin endcap --prefit True
python makePostFitPlots.py --lepType muon --region pass --ptbin Pt30To50 --etabin barrel --prefit True
python makePostFitPlots.py --lepType muon --region pass --ptbin Pt30To50 --etabin endcap --prefit True
python makePostFitPlots.py --lepType muon --region pass --ptbin Pt50To70 --etabin barrel --prefit True
python makePostFitPlots.py --lepType muon --region pass --ptbin Pt50To70 --etabin endcap --prefit True
python makePostFitPlots.py --lepType muon --region fail --ptbin Pt10To30 --etabin barrel --prefit True
python makePostFitPlots.py --lepType muon --region fail --ptbin Pt10To30 --etabin endcap --prefit True
python makePostFitPlots.py --lepType muon --region fail --ptbin Pt30To50 --etabin barrel --prefit True
python makePostFitPlots.py --lepType muon --region fail --ptbin Pt30To50 --etabin endcap --prefit True
python makePostFitPlots.py --lepType muon --region fail --ptbin Pt50To70 --etabin barrel --prefit True
python makePostFitPlots.py --lepType muon --region fail --ptbin Pt50To70 --etabin endcap --prefit True
python makePostFitPlots.py --lepType ele --region pass --ptbin Pt10To30 --etabin barrel
python makePostFitPlots.py --lepType ele --region pass --ptbin Pt10To30 --etabin endcap
python makePostFitPlots.py --lepType ele --region pass --ptbin Pt30To50 --etabin barrel
python makePostFitPlots.py --lepType ele --region pass --ptbin Pt30To50 --etabin endcap
python makePostFitPlots.py --lepType ele --region pass --ptbin Pt50To70 --etabin barrel
python makePostFitPlots.py --lepType ele --region pass --ptbin Pt50To70 --etabin endcap
python makePostFitPlots.py --lepType ele --region fail --ptbin Pt10To30 --etabin barrel
python makePostFitPlots.py --lepType ele --region fail --ptbin Pt10To30 --etabin endcap
python makePostFitPlots.py --lepType ele --region fail --ptbin Pt30To50 --etabin barrel
python makePostFitPlots.py --lepType ele --region fail --ptbin Pt30To50 --etabin endcap
python makePostFitPlots.py --lepType ele --region fail --ptbin Pt50To70 --etabin barrel
python makePostFitPlots.py --lepType ele --region fail --ptbin Pt50To70 --etabin endcap
python makePostFitPlots.py --lepType muon --region pass --ptbin Pt10To30 --etabin barrel
python makePostFitPlots.py --lepType muon --region pass --ptbin Pt10To30 --etabin endcap
python makePostFitPlots.py --lepType muon --region pass --ptbin Pt30To50 --etabin barrel
python makePostFitPlots.py --lepType muon --region pass --ptbin Pt30To50 --etabin endcap
python makePostFitPlots.py --lepType muon --region pass --ptbin Pt50To70 --etabin barrel
python makePostFitPlots.py --lepType muon --region pass --ptbin Pt50To70 --etabin endcap
python makePostFitPlots.py --lepType muon --region fail --ptbin Pt10To30 --etabin barrel
python makePostFitPlots.py --lepType muon --region fail --ptbin Pt10To30 --etabin endcap
python makePostFitPlots.py --lepType muon --region fail --ptbin Pt30To50 --etabin barrel
python makePostFitPlots.py --lepType muon --region fail --ptbin Pt30To50 --etabin endcap
python makePostFitPlots.py --lepType muon --region fail --ptbin Pt50To70 --etabin barrel
python makePostFitPlots.py --lepType muon --region fail --ptbin Pt50To70 --etabin endcap
