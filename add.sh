cd ../../..

root -l pass_fail_plots_def3.C

cd pass_fail_files

cp plots_data_0.root ./A2ZhFakeFactorScripts/mt_plots/plots_data.root

rm plots_data_0.root

hadd ./A2ZhFakeFactorScripts/mt_plots/plots_DYJetsToLL_M-50.root plots_DY*root

rm plots_DY*root

hadd ./A2ZhFakeFactorScripts/mt_plots/plots_Diboson.root plots_WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8_33.root plots_WZTo3LNu_TuneCP5_13TeV-amcatnloFXFX-pythia8_31.root plots_ZZTo2L2Q_37.root plots_ZZTo4L_TuneCP5_13TeV_powheg_pythia8_35.root

rm plots_WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8_33.root plots_WZTo3LNu_TuneCP5_13TeV-amcatnloFXFX-pythia8_31.root plots_ZZTo2L2Q_37.root plots_ZZTo4L_TuneCP5_13TeV_powheg_pythia8_35.root

hadd ./A2ZhFakeFactorScripts/mt_plots/plots_TTbar.root plots_TTTo*root

rm plots_TTTo*root

hadd ./A2ZhFakeFactorScripts/mt_plots/plots_other.root *root

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
