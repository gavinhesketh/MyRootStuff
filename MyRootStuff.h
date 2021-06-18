#ifndef MYROOTSTUFF
#define MYROOTSTUFF

#include "TStyle.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TFrame.h"
#include "THStack.h"
#include "TString.h"
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TPaveStats.h"
#include "TLatex.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TMath.h"
#include "TF1.h"
#include <iostream>

using std::cout;
using std::endl;
using std::vector;
using std::to_string;


namespace MyRootStuff {
  
  Double_t gauss(Double_t *x,Double_t *par);
  Double_t double_gauss(Double_t *x, Double_t *par);
  
  
void STATS(bool set=false);
void GRID(bool set=true);
void GRIDX(bool set=true);
void GRIDY(bool set=true);
void ZERO(bool set=true);
void DATA(bool set=true);
void LOGX(bool set=true);
void LOGY(bool set=true);
void LOGY2(bool set=true);
void LOGZ(bool set=true);
void NORMALISE(bool set=true);
void RATIO(bool set=true);
void RATIO_RANGE(double ymin=0, double ymax=2);
void RANGE(double ymin=0, double ymax=2);
void XRANGE(double xmin=-1, double xmax=-1);
void ZRANGE(double zmin=-1, double zmax=-1);
void SMALL_RATIO(bool set=false);
void LARGE_RATIO(bool set=true);
void LEGEND_X1(double x1=0.7);
void LEGEND_Y1(double y1=0.7);
void LEGEND_X2(double x2=0.9);
void LEGEND_Y2(double y2=0.9);
void LINEWIDTH(int width);
void LEGEND(double x1=0.7, double y1=0.7, double x2=0.9, double y2=0.9);
 void DRAW_LEGEND(bool draw=true);
void RATIO_OPT(TString ro);
void DRAW_OPT(TString ro);
void DRAW_OPT_2D(TString ro);
void REBIN(int set);
void RETURN_CANVAS(bool set=true);
void MAKE_C(bool set=true);
void PDF(bool set=true);
void CANVAS_X(int x);
void CANVAS_Y(int y);
void ATLAS(bool set = true);
void ATLASX(double set);
 void ATLASY(double set);
 void ATLAS_OPT(int set=0);
 void ATLAS_X(double set);
 void ATLAS_Y(double set);
 void RATIO_DENOM(int denom);
    void Reset();
 void RESET();
 
void FillColours();
 void FillColoursBlue();
 void FillColoursRed();
void FillColours(vector<int> colours);
void FillLines(vector<int> line);
void FillColours(vector<int> colours, vector<int> line);
void FillMarkers(bool fill=true);

 int Colour(int i);

TH1 * Read(TString plot, TFile *file, int colour=2);
TH1 * Read(TString plot, TString file, int colour=2);

TH2 * Read2D(TString plot, TFile *file, int colour=2);
TH2 * Read2D(TString plot, TString file, int colour=2);

void SetRange(vector<TH1 *>&plots, bool setzero=false);

 void prep( TH1 * p, int col=2, int line=1, int marker=1);
 void prep( TH1 * p, double scale);
 void prep(TGraph *gr, int col=2, int line=2, int marker=1);

void Scale(TH1 *plot);
void Normalise(TH1 *plot);
double Area(TH1 *p);
void Normalise(TH1 *p);
TH1* Divide(TH1* n, TH1 * d, bool binomial=false);


TCanvas *Draw(vector<TH1 *> h, vector<TString> legnames, TString printname="", TString xtitle="", TString ytitle="");
TCanvas *Draw(vector<TH1 *> h, TString printname="", TString xtitle="", TString ytitle="");

TCanvas *Draw(TString plot, vector<TString> files, vector<TString> legnames, TString printname="", TString xtitle="", TString ytitle="");
TCanvas *Draw(TString plot, vector<TString> files, TString printname="", TString xtitle="", TString ytitle="");

 TCanvas *Draw(TString plot, TString file, TString printname="", TString xtitle="", TString ytitle="", int colour=0);

TCanvas *Draw(vector<TString> plots, TString file, vector<TString> legnames, TString printname="", TString xtitle="", TString ytitle="");

TCanvas *Draw(vector<TString> plots, TString file,  TString printname="", TString xtitle="", TString ytitle="");

TCanvas *Draw(TH1 *plot, TString printname="", TString xtitle="", TString ytitle="");

 TCanvas *Draw2D(TH2 *plot, TString printname="", TString xtitle="", TString ytitle="");
 TCanvas *Draw2D(TString plot, TString file, TString printname="", TString xtitle="", TString ytitle="");
 TCanvas *Draw2D(vector<TString> plot, TString file, TString printname="", TString xtitle="", TString ytitle="");

void multStat(vector<TH1 *> h, vector<TString> legnames, TString printname="", TString xtitle="", TString ytitle="");


void prep(TPad *p);
void prep(TVirtualPad *p);
void Divide(TCanvas * c1);
void DivideSmallRatio(TCanvas * c1); 
void DivideLargeRatio(TCanvas * c1);

TCanvas * Canvas(int x, int y, TString name="c1");
TCanvas * Canvas(TString name="c1");



TLatex * Latex(double textSize=0.055, bool NDC=true);
TLatex * Latex(bool NDC);


TLegend *Legend(double x1=0.7, double y1=0.7, double x2=0.9,double y2=0.9);
TLegend *Legend(vector<TH1*> plots, double x1=0.7, double y1=0.7, double x2=0.99, double y2=0.99);
TLegend *Legend(vector<TH1*> plots, vector<TString> names, double x1=0.7, double y1=0.7, double x2=0.99, double y2=0.99);
TLegend *Legend(THStack *st);

 
 TH1 * plot1D(TString name, int nbins, double xlow, double xhigh, int col=1);
 TH1 * plot1D(TString name, TString xtitle, TString ytite, int nbins, double xlow, double xhigh, int col=1);
 TH2 * plot2D(TString name, int nbins, double xlow, double xhigh, int nbinsy, double ylow, double yhigh, int col=1);
 TH2 * plot2D(TString name, TString xtitle, TString ytitle, int nbinsx, double xlow, double xhigh, int nbinsy, double ylow, double yhigh, int col);

 
 TGraphErrors * MakeGraph(vector<double> x, vector<double> y, vector<double> x_err, vector<double> y_err, TString xtitle="", TString ytitle="");
 TGraph * MakeGraph(vector<double> x, vector<double> y, TString xtitle="", TString ytitle="");
    
 
} //namespace
#endif
