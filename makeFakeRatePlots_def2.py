import sys, time, os
import ROOT, array
from ROOT import TFile, TH1F, TGraph, TCanvas, TLegend, TTree
from ROOT import TMVA, TMath

from optparse import OptionParser
parser = OptionParser()

#run: python makeFakeRatePlots.py --lepType "muon" --etabin "barrel"
parser.add_option("--lepType", type="string", dest="lepType", help="ele / muon", default='ele')
parser.add_option("--etabin", type="string", dest="etabin", help="eta bin: barrel / endcap", default='barrel')
(options, args) = parser.parse_args()

lepType = options.lepType
etabin = options.etabin

if lepType=='ele' : 
    pt = [10, 30, 50, 70]
    ptbins = ['Pt10To30', 'Pt30To50', 'Pt50To70']
elif lepType=='muon' : 
    pt = [10, 30, 50, 70]
    ptbins = ['Pt10To30', 'Pt30To50', 'Pt50To70']

regions = ['pass', 'fail']

if not os.path.exists('Fits'):
    os.makedirs('Fits')

nbins = len(pt)-1
hist_fr_data_by_sub = TH1F("fr_data_by_sub_%s_%s" %(lepType, etabin), "", nbins, array.array('d',pt))
hist_fr_data = TH1F("fr_data_%s_%s" %(lepType, etabin), "", nbins, array.array('d',pt))
hist_fr_mc = TH1F("fr_mc_%s_%s" %(lepType, etabin), "", nbins, array.array('d',pt))

for i, p in enumerate(ptbins):
    fakes_data_by_sub = [0, 0]
    errors_data_by_sub = [0, 0]
    fakes_data = [0, 0]
    errors_data = [0, 0]
    fakes_mc = [0, 0]
    errors_mc = [0, 0]
    for j, r in enumerate(regions):
        datacardfile = 'datacards/datacard_fit_%s_%s_%s_%s.txt' %(lepType, r, p, etabin)
        print 'fitting ', datacardfile
        cmd = 'combine -M FitDiagnostics %s --saveWithUncertainties --saveNormalizations --saveShapes' %(datacardfile)
        os.system(cmd)
        fitfile = TFile("fitDiagnosticsTest.root")
     


        hist_postfit_fake = fitfile.Get("shapes_fit_s/bin1/fake")
        fakes_data[j] = hist_postfit_fake.Integral()
        error = ROOT.Double()
        fakeAndError = hist_postfit_fake.IntegralAndError(1, hist_postfit_fake.GetNbinsX(), error)
        print 'error on data ', error
        errors_data[j] = error
        
        hist_prefit_fake = fitfile.Get("shapes_prefit/bin1/fake")
        fakes_mc[j] = hist_prefit_fake.Integral()
        error = ROOT.Double()
        fakeAndError = hist_prefit_fake.IntegralAndError(1, hist_prefit_fake.GetNbinsX(), error)
        print 'error on mc ', error
        errors_mc[j] = error

        #FR using substraction
        hist_data = fitfile.Get("shapes_prefit/bin1/data")
        hist_mc_prompt = fitfile.Get("shapes_prefit/bin1/prompt")
        fakes_data_by_sub[j] = (hist_data.GetMean(2) * hist_data.GetN()) - hist_mc_prompt.Integral()
        error = ROOT.Double()
        #fakeAndError = hist_postfit_fake.IntegralAndError(1, hist_postfit_fake.GetNbinsX(), error)
        errors_data_by_sub[j] = errors_mc[j]


        #end FR using substraction     

        
        mv_cmd = 'mv higgsCombineTest.FitDiagnostics.mH120.root Fits/higgsCombineTest.FitDiagnostics.mH120.%s.%s.%s.%s.root' %(lepType, r, p, etabin)
        os.system(mv_cmd)
        mv_cmd = 'mv fitDiagnosticsTest.root Fits/fitDiagnosticsTest.%s.%s.%s.%s.root' %(lepType, r, p, etabin)
        os.system(mv_cmd)



    ratio_error_data = (fakes_data[0]/fakes_data[1])*TMath.Sqrt(TMath.Power(errors_data[0]/fakes_data[0], 2) + TMath.Power(errors_data[1]/fakes_data[1], 2))
    hist_fr_data.SetBinContent(i+1, fakes_data[0]/(fakes_data[0] + fakes_data[1]))
    hist_fr_data.SetBinError(i+1, ratio_error_data);
    ratio_error_mc = (fakes_mc[0]/fakes_mc[1])*TMath.Sqrt(TMath.Power(errors_mc[0]/fakes_mc[0], 2) + TMath.Power(errors_mc[1]/fakes_mc[1], 2))
    hist_fr_mc.SetBinContent(i+1, fakes_mc[0]/(fakes_mc[0] + fakes_mc[1]))
    hist_fr_mc.SetBinError(i+1, ratio_error_mc);

    #for FR using sub

    ratio_error_data_by_sub = ratio_error_mc
    hist_fr_data_by_sub.SetBinContent(i+1, fakes_data_by_sub[0]/(fakes_data_by_sub[0] + fakes_data_by_sub[1]))
    hist_fr_data_by_sub.SetBinError(i+1, ratio_error_data_by_sub)

    #end for FR using sub

    print 'bin ', p, ' fakes data ', fakes_data[0]/fakes_data[1], ' fakes mc ', fakes_mc[0]/fakes_mc[1], '+/-',ratio_error_mc
    print 'data: pass ', fakes_data[0], ' fail ',fakes_data[1]
    print 'mc: pass ', fakes_mc[0], ' fail ',fakes_mc[1]

c1 = TCanvas()
c1.SetFillColor(10)
c1.SetBorderSize(2)
c1.SetLeftMargin(0.12)
c1.SetBottomMargin(0.12)
c1.SetRightMargin(0.05)
#c1.SetLogy()

histogram_base = TH1F("histogram_base", "", 20, 10., 70.)
histogram_base.SetTitle("")
histogram_base.SetStats(False)

if(lepType == 'ele' and etabin == 'barrel'):
    #for ele barrel
    histogram_base.SetMinimum(0.00)
    histogram_base.SetMaximum(0.020)
    #end for ele barrel

elif(lepType == 'ele' and etabin == 'endcap'):
    #for ele endcap
    histogram_base.SetMinimum(0.00)
    histogram_base.SetMaximum(0.045)
    #end for ele endcap

elif(lepType == 'muon' and etabin == 'barrel'):
    #for muon barrel
    histogram_base.SetMinimum(0.00)
    histogram_base.SetMaximum(0.10)
    #end for muon barrel

elif(lepType == 'muon' and etabin == 'endcap'):
    #for muon endcap
    histogram_base.SetMinimum(0.00)
    histogram_base.SetMaximum(0.15)
    #end for mu endcap


histogram_base.GetYaxis().SetTitle("Fake Factor")
histogram_base.GetXaxis().SetTitle("p_{T} (GeV)")
histogram_base.Draw()


hist_fr_data_by_sub.SetMarkerStyle(20)
hist_fr_data_by_sub.SetMarkerSize(1.0)
hist_fr_data_by_sub.SetLineColor(2)
hist_fr_data_by_sub.SetMarkerColor(2)

hist_fr_data.SetMarkerStyle(20)
hist_fr_data.SetMarkerSize(1.0)
hist_fr_data.SetLineColor(4)
hist_fr_data.SetMarkerColor(4)

hist_fr_mc.SetMarkerStyle(20)
hist_fr_mc.SetMarkerSize(1.0)
hist_fr_mc.SetLineColor(5)
hist_fr_mc.SetMarkerColor(5)

leg = TLegend(0.2, 0.65, 0.5, 0.9)
leg.SetBorderSize(0)
leg.SetFillColor(10)
leg.SetLineColor(0)
leg.SetFillStyle(0)
leg.SetTextSize(0.04)
leg.SetTextFont(42)

leg.AddEntry(hist_fr_data_by_sub, "data_fr_by_sub", "lp")
leg.AddEntry(hist_fr_data, "data_fr_by_fit", "lp")
leg.AddEntry(hist_fr_mc, "mc_fr", "lp")

hist_fr_data_by_sub.Draw("P E same")
hist_fr_data.Draw("P E same")
hist_fr_mc.Draw("P E same")
leg.Draw()

if not os.path.exists('plots'):
    os.makedirs('plots')

c1.SaveAs("plots/fakefactor_%s_%s.png" %(lepType, etabin))
outfile = TFile("plots/fakefactor_%s_%s.root" %(lepType, etabin), "RECREATE")
hist_fr_data_by_sub.Write()
hist_fr_data.Write()
hist_fr_mc.Write()
outfile.Close()

