#include "MyRootStuff.h"


namespace MyRootStuff {


Double_t gauss(Double_t *x,Double_t *par) {

  const double arg = (par[2]==0) ? 1 : ( x[0] - par[1])/par[2];
  return par[0]*TMath::Exp(-0.5*arg*arg);
}

Double_t double_gauss(Double_t *x, Double_t *par) {
  double arg = 0;
  if (par[2]!=0) arg = ( x[0] - par[1])/par[2];
  const double g1 =  par[0]*TMath::Exp(-0.5*arg*arg);

  if (par[5]!=0) arg = ( x[0] - par[4])/par[5];
  const double g2 =  par[4]*TMath::Exp(-0.5*arg*arg);
  return g1+g2;
  
}



  

  vector<int> COLOURS, LINE, MARKERS;

  int Colour(int i) {return COLOURS[i];}
  
bool pGRIDX=false;
bool pGRIDY=false;
bool pSTATS=false;
bool pZERO=true;
bool pDATA=false;
bool pLOGX=false;
bool pLOGY=false;
bool pLOGY2=false;
bool pLOGZ=false;
bool pNORMALISE=false;
bool pRATIO=true;
double pXMIN=-1;
double pXMAX=-1;
double pZMIN=-1;
double pZMAX=-1;
bool pZRANGE=false;
double pYMIN=-999999;
double pYMAX=-1;
double pRYMIN=0;
double pRYMAX=2;
  bool pDRAWLEG=true;
bool pSMALLRATIO=true;
bool pLARGERATIO=false;
double pX1=0.7;
double pX2=0.9;
double pY1=0.6;
double pY2=0.93;
int pLINEWIDTH=3;
TString pRATIO_OPT="";
TString pOPT="E1";
TString pOPT2D="COLZ";
int pREBIN=1;
bool pRETCAN=false;
int pCANVASX=800;
int pCANVASY=800;
bool pATLAS=false;
int pLATEX_OPT=0;
double pLATEX_X=0.2;
double pLATEX_Y=0.88;
double pMAKE_C=false;
  int pDenom=0;
  bool pPDF=true;
  
void DATA(bool set) {pDATA=set;}
void GRID(bool set) {pGRIDX=set;pGRIDY=set;}
void GRIDX(bool set) {pGRIDX=set;}
void GRIDY(bool set) {pGRIDY=set;}
void STATS(bool set) {pSTATS=set;}
void ZERO(bool set) {pZERO=set;}
void LOGX(bool set) {pLOGX=set;}
void LOGY(bool set) {pLOGY=set;}
void LOGY2(bool set) {pLOGY2=set;}
void LOGZ(bool set) {pLOGZ=set;}
void REBIN(int set) {pREBIN=set;}
void NORMALISE(bool set) {pNORMALISE=set;}
void RATIO(bool set) {pRATIO=set;}
void RANGE(double ymin, double ymax) {pYMIN=ymin;pYMAX=ymax;}
void XRANGE(double xmin, double xmax) {pXMIN=xmin;pXMAX=xmax;}
  void ZRANGE(double zmin, double zmax) {pZMIN=zmin;pZMAX=zmax;pZRANGE=true;}
void RATIO_RANGE(double ymin, double ymax) {pRYMIN=ymin;pRYMAX=ymax;}
void SMALL_RATIO(bool set) {pSMALLRATIO=set;}
void LARGE_RATIO(bool set) {pLARGERATIO=set;}
void LEGEND_X1(double x1) {pX1=x1;}
void LEGEND_Y1(double y1) {pY1=y1;}
void LEGEND_X2(double x2) {pX2=x2;}
void LEGEND_Y2(double y2) {pY2=y2;}
void LEGEND(double x1, double y1, double x2, double y2) {
	pX1=x1;	pX2=x2;	pY1=y1;	pY2=y2;
}
void DRAW_LEGEND(bool draw) {pDRAWLEG=draw;}
void RATIO_OPT(TString ro) {pRATIO_OPT=ro;};
void DRAW_OPT(TString opt) {pOPT=opt;};
void DRAW_OPT_2D(TString opt) {pOPT2D=opt;};
void RETURN_CANVAS(bool set) {pRETCAN=set;}
void MAKE_C(bool set) {pMAKE_C=set;}
void PDF(bool set) {pPDF=set;}
void LINEWIDTH(int width) {pLINEWIDTH=width;}
void CANVAS_X(int x) {pCANVASX=x;}
void CANVAS_Y(int y) {pCANVASY=y;}
void ATLAS(bool set) {pATLAS=set;}
void ATLAS_OPT(int set) {pLATEX_OPT=set;}
void ATLAS_X(double set) {pLATEX_X=set;}
void ATLAS_Y(double set) {pLATEX_Y=set;}
  void RATIO_DENOM(int denom) {pDenom=denom;}
  
void RESET() {
  pSTATS=false;
  pGRIDX=false;
  pGRIDY=false;
  pZERO=true;
  pDATA=false;
  pLOGX=false;
  pLOGY=false;
  pLOGY2=false;
  pLOGZ=false;
  pNORMALISE=false;
  pRATIO=true;
  pSMALLRATIO=true;
  pLARGERATIO=false;
  pDRAWLEG=true;
  pX1=0.7;
  pX2=0.9;
  pY1=0.7;
  pY2=0.9;
  pLINEWIDTH=3;
  pXMIN=-1;
  pXMAX=-1;
  pYMIN=-999999;
  pYMAX=-1;
  pZMIN=-1;
  pZMAX=-1;
  pZRANGE=false;
  pRYMIN=0;
  pRYMAX=2;
  pRATIO_OPT="";
  pOPT="E1";
  pOPT2D="COLZ";
  pREBIN=1;
  pRETCAN=false;
  pCANVASX=400;
  pCANVASY=400;
  pATLAS=false;
  pLATEX_OPT=0;
  pLATEX_X=0.2;
  pLATEX_Y=0.88;
  pMAKE_C=false;
  pPDF=true;
  pDenom=0;
  FillColours();
}

void Reset() {RESET();}


void FillColours() {
  int colours[9]={4,2,kGreen+2,6, kBlue-2, kBlue-9, kRed-2,  kViolet};
  //  int colours[9]={4,4,2,2,6,6,8,3,7};
  // int line[9]={1,2,1,2,1,2,1,1,1};
  COLOURS.clear();
  LINE.clear();
  for(int i=0; i<9; i++) {
    COLOURS.push_back(colours[i]);
  }
  for(int i=0; i<50; i++) {
    LINE.push_back(1);
  }
  
}

  void FillColoursBlue() {
    int colours[9]={kBlue+4,kBlue, kBlue-7, kBlue-5, kCyan-8, kCyan, kCyan+3, kViolet+2, kViolet };
    int line[9]={1,1,1,1,1,1,1,1,1};
    //  int colours[9]={4,4,2,2,6,6,8,3,7};
    // int line[9]={1,2,1,2,1,2,1,1,1};
    COLOURS.clear();
    LINE.clear();
    for(int i=0; i<9; i++) {
      COLOURS.push_back(colours[i]);
      LINE.push_back(line[i]);
    }
    

  }
    void FillColoursRed() {
      int colours[9]={kRed, kRed+2, kRed-7, kRed+4, kPink-9, kOrange+1, kPink+6, kOrange-2, kOrange+2 };
    int line[9]={1,1,1,1,1,1,1,1,1};
    //  int colours[9]={4,4,2,2,6,6,8,3,7};
    // int line[9]={1,2,1,2,1,2,1,1,1};
    COLOURS.clear();
    LINE.clear();
    for(int i=0; i<9; i++) {
      COLOURS.push_back(colours[i]);
      LINE.push_back(line[i]);
    }
    

  }
  
void FillColours(vector<int> colours) {
  //  FillColours();
  COLOURS.clear();
  LINE.clear();
  MARKERS.clear();
  for(int i=0; i<colours.size(); i++) {
    COLOURS.push_back(colours[i]);
    LINE.push_back(1);
    MARKERS.push_back(1);
  }
}
void FillLines(vector<int> line) {
  FillColours();
  LINE.clear();
  for(int i=0; i<line.size(); i++) {
    LINE.push_back(line[i]);
  }
}

void FillColours(vector<int> colours, vector<int> line) {
  COLOURS.clear();
  LINE.clear();
  for(int i=0; i<colours.size(); i++) {
    COLOURS.push_back(colours[i]);
  }
  if(line.size()<colours.size()) {
    for(int i=0; i< colours.size() - line.size(); i++) line.push_back(1);
  }
  for(int i=0; i<line.size(); i++) {
    LINE.push_back(line[i]);
  }
}

void FillMarkers(bool fill) {
  MARKERS.clear();
  
  if(!fill) {
    for(int i=0; i<20; i++) MARKERS.push_back(1);
  }
  else {
    for(int i=0; i<20; i++) MARKERS.push_back(20+i);
  }
  
  return;  
}
  



TH1 * Read(TString plot_name, TFile *file, int colour) {
	TH1 * plot = (TH1D*)file->Get(plot_name);
	if(plot) prep(plot, colour);
	//else cout<<"Unable to read plot "<<plot_name<<" from file "<<file->GetName()<<endl;
	return plot;
}

TH1 * Read(TString plot_name, TString file, int colour) {
	TFile * f = new TFile(file, "READ");
	TH1 * plot = Read(plot_name, f, colour);
	if(plot) plot->SetDirectory(0);
	f->Close();
	return plot;
  
}

TH2 * Read2D(TString plot_name, TFile *file, int colour) {
	TH2 * plot = (TH2D*)file->Get(plot_name);
	if(plot) prep(plot, colour);
	return plot;
}

TH2 * Read2D(TString plot_name, TString file, int colour) {
	TFile * f = new TFile(file, "READ");
	TH2 * plot = Read2D(plot_name, f, colour);
	if(plot) plot->SetDirectory(0);
	f->Close();
	return plot; 
}



  void SetRange(vector<TH1 *>&plots, bool setzero){
    if(plots.size()<2) return;
    double min=100000, max =-100000;
    for(int ip=0; ip<plots.size(); ip++) {
      //	if(ip>0) plots[ip]->SetAxisRange( plots[0]->GetXaxis()->GetXmin(), plots[0]->GetXaxis()->GetXmax(), "X");
      int mabin = plots[ip]->GetMaximumBin();
      // cout<<"max bin: "<<mbin<<endl;
      const double val0 = plots[ip]->GetBinContent(mabin);
      const double err0 = plots[ip]->GetBinError(mabin);
      if(val0-err0 < min) min = val0-err0;
      if(val0+err0 > max) max = val0+err0;
      int mibin = plots[ip]->GetMinimumBin();
      const double val1 = plots[ip]->GetBinContent(mibin);
      const double err1 = plots[ip]->GetBinError(mibin);
      if(val1-err1 < min) min = val1-err1;
      if(val1+err1 > max) max = val1+err1;
      
	
	/*
      //this method doesn't account for a zoom in X!
      for(int i=1; i<plots[ip]->GetNbinsX()+1; i++) {
	const double val0 = plots[ip]->GetBinContent(i);
	const double err0 = plots[ip]->GetBinError(i);
	if(val0-err0 < min) min = val0-err0;
	if(val0+err0 > max) max = val0+err0;
      }
	*/
    }
    min = min>0 ? 0.8*min : 1.2*min;
    max = max>0 ? 1.2*max : 0.8*max;    
    if(setzero) min=0;
    plots[0]->SetAxisRange(min, max, "Y");
    return;
  }
  
//=======================================================================
  TH1 * plot1D(TString name, int nbins, double xlow, double xhigh, int col){
    TH1 * p = new TH1D(name, name, nbins, xlow, xhigh);
    p->Sumw2();
    prep(p, col);
    p->SetDirectory(0);
    return p;
  }
  
  TH1 * plot1D(TString name, TString xtitle, TString ytitle, int nbins, double xlow, double xhigh, int col){
    TH1 * p = plot1D(name, nbins, xlow, xhigh, col);
    p->SetXTitle(xtitle);
    p->SetYTitle(ytitle);
    return p;
  }

  TH2 * plot2D(TString name, int nbinsx, double xlow, double xhigh, int nbinsy, double ylow, double yhigh, int col) {
   TH2 * p = new TH2D(name, name, nbinsx, xlow, xhigh, nbinsy, ylow, yhigh);
   p->Sumw2();
   prep(p, col);
   p->SetDirectory(0);
   return p;
  }

  TH2 * plot2D(TString name, TString xtitle, TString ytitle, int nbinsx, double xlow, double xhigh, int nbinsy, double ylow, double yhigh, int col) {
    TH2 * p = plot2D(name, nbinsx, xlow, xhigh, nbinsy, ylow, yhigh, col);
    p->SetXTitle(xtitle);
    p->SetYTitle(ytitle);
    return p;
  }


  
  void prep( TH1 * p, int col, int line, int marker) {
  	p->GetXaxis()->SetLabelSize(0.04);
  	p->GetYaxis()->SetLabelSize(0.04);
	p->GetXaxis()->SetTitleOffset(1.2);
	p->GetYaxis()->SetTitleOffset(1.8);
	p->GetXaxis()->SetLabelFont(42);
	p->GetYaxis()->SetLabelFont(42);
	p->GetXaxis()->SetTitleFont(42);
	p->GetYaxis()->SetTitleFont(42);
        if(!pSTATS) p->SetStats(0);
	p->SetTitle(0);
	p->SetLineWidth(pLINEWIDTH);
	p->SetLineStyle(line);
	p->SetLineColor(col);
	p->SetMarkerColor(col);
	p->SetMarkerStyle(marker);
	p->SetMarkerSize(1.5);
	//	p->SetFillColor(col);
}

void prep( TH1 * p, double scale) {

  p->GetXaxis()->SetLabelSize(scale*0.04);
  p->GetYaxis()->SetLabelSize(scale*0.04);
  p->GetXaxis()->SetTitleSize(scale*0.04);
  p->GetYaxis()->SetTitleSize(scale*0.04);
  p->GetXaxis()->SetTitleOffset(1);
  p->GetYaxis()->SetTitleOffset(0.8);
}


void prep( TGraph * gr, int col, int line, int marker) {
  gr->SetTitle(0);
  gr->SetLineColor(col);
  gr->SetMarkerColor(col);
  gr->SetMarkerSize(2);
  gr->SetMarkerStyle(marker);
}

  
//=======================================================================

void Scale(TH1 *plot){
	for(int i=1; i<plot->GetNbinsX()+1; i++){
		plot->SetBinContent(i, plot->GetBinContent(i)/plot->GetBinWidth(i) );
		plot->SetBinError(i, plot->GetBinError(i)/plot->GetBinWidth(i) );
	}
}
double Area(TH1 *p){
  double area=0;
  for(int i=1; i<=p->GetNbinsX(); i++) area += p->GetBinContent(i)*p->GetBinWidth(i);
  //cout<<p->GetName()<<" integral: "<<area<<endl;
  return area;
}



TH1* Divide(TH1* n, TH1 * d, bool binomial){
  TH1 * r = (TH1F*)n->Clone();
  if(binomial) r->Divide(n, d, 1, 1, "B");
  else r->Divide(n, d, 1, 1);
  return r;
}


void Normalise(TH1* plot) {
  plot->Scale(1./plot->Integral());
  return;
}

//=======================================================================



TCanvas *Draw(vector<TH1 *> h, vector<TString> legnames, TString printname, TString xtitle, TString ytitle) {

  if(COLOURS.size()==0) FillColours();
  if(MARKERS.size()==0) FillMarkers(false);
  TPaveStats *tps[h.size()];
  TCanvas *c1;
  if(pSTATS) {
    c1 = new TCanvas("junk");
    gStyle->SetOptStat("mr"); 
    for(int i=0; i<h.size(); i++) {
      h[i]->Draw();
      gPad->Update();
      tps[i] = (TPaveStats*) h[i]->FindObject("stats");
      // h[i]->SetStats(0);
    }  
  }
  
  for(int i=0; i<h.size(); i++) {
    if(pREBIN>1) h[i]->Rebin(pREBIN);
    //    cout<<i<<" "<<h.size()<<" "<<COLOURS.size()<<" "<<LINE.size()<<" "<<MARKERS.size()<<endl;
    prep(h[i], COLOURS[i], LINE[i], MARKERS[i]);
    if(xtitle.Sizeof()>1) h[i]->SetXTitle(xtitle);
    if(ytitle.Sizeof()>1) h[i]->SetYTitle(ytitle);
    if(pNORMALISE) {
      Normalise(h[i]);
      h[i]->SetYTitle("unit normalised  ");
    }
    //do this here so SetRange works:
    if(pXMIN!=-1 && pXMAX!=-1) h[i]->SetAxisRange(pXMIN, pXMAX, "X");

  }

  if(pYMIN>-999999) h[0]->SetAxisRange(pYMIN, pYMAX, "Y");
  else if(!pLOGY) SetRange(h, !pLOGY && pZERO );
  
  TLegend * leg = Legend(pX1, pY1, pX2, pY2);
  for(int i=0; i<h.size() && i<legnames.size(); i++) {
    leg->AddEntry(h[i], legnames[i], "LEP");
  }
  
  
  TCanvas * c;
  if(h.size()>1 && pRATIO) {
    if(pSMALLRATIO) {
      c = Canvas(h[pDenom]->GetName());
      DivideSmallRatio(c);
    }
    else if(pLARGERATIO) {
      c = Canvas(h[pDenom]->GetName());
      DivideLargeRatio(c);
    }
    else {
      c = Canvas(h[pDenom]->GetName());
      Divide(c);
    }
    c->cd(1);
  }
  else c = Canvas(h[pDenom]->GetName());
  if(pLOGX) gPad->SetLogx();
  if(pLOGY) gPad->SetLogy();
  h[0]->DrawCopy(pOPT);
  for(int i=1; i<h.size(); i++) h[i]->DrawCopy("SAME"+pOPT);
  
  gPad->RedrawAxis();
  if(pDRAWLEG && h.size()>1)leg->Draw();
  /*
  if(pSTATS) {
    for(int k=0; k<h.size(); k++) {
      tps[k]->SetTextColor(h[k]->GetLineColor());

      tps[k]->SetX2NDC(0.2 + (tps[0]->GetX2NDC() - tps[0]->GetX1NDC()) );//tps[0]->GetX2NDC());
      tps[k]->SetX1NDC(0.2);//tps[0]->GetX1NDC());
      if(k>0) {
	tps[k]->SetY1NDC(2*tps[0]->GetY1NDC() - tps[0]->GetY2NDC());
	tps[k]->SetY2NDC(tps[0]->GetY1NDC());
      }
      tps[k]->Draw("SAMEE1"+pOPT);
    }
  }
  */
  if(pATLAS) {
    TLatex *l1 = Latex(); 
    l1->SetTextFont(72);   
    //    l1->DrawLatex(pLATEX_X,pLATEX_Y,"ATLAS");
    //    l1->SetTextFont(42);   
    
    if(pLATEX_OPT==0) l1->DrawLatex(pLATEX_X,pLATEX_Y,"ATLAS Internal"); 
    else if(pLATEX_OPT==1) l1->DrawLatex(pLATEX_X,pLATEX_Y,"ATLAS Preliminary");
    else if(pLATEX_OPT==2) l1->DrawLatex(pLATEX_X,pLATEX_Y,"ATLAS Simulation");
    else if(pLATEX_OPT==3) l1->DrawLatex(pLATEX_X,pLATEX_Y,"ATLAS data #sqrt{s}=13 TeV");
  }
  
 	
  vector<TH1 *> ratio;
  if(h.size()>1 && pRATIO) {
    TH1 * denom = (TH1*)h[pDenom]->Clone();
	  
    if(pDATA) {
      ratio.push_back((TH1*)h[pDenom]->Clone() );
      for(int i=0; i<denom->GetNbinsX(); i++) denom->SetBinError(i+1, 0);
    }
    for(int i=0; i<h.size(); i++) {
      if(i==pDenom) continue;
      ratio.push_back( (TH1*)h[i]->Clone() );
    }
    for(int i=0; i<ratio.size(); i++) {
      prep(ratio[i], 2.0);
      ratio[i]->SetFillColor(0);
      ratio[i]->Divide(denom);
      ratio[i]->SetYTitle("ratio to "+ legnames[pDenom] );
    }
    if(pRYMIN>=-0.01) ratio[0]->SetAxisRange(pRYMIN, pRYMAX, "Y");
    else SetRange(ratio);
    if(pXMIN!=-1 && pXMAX!=-1) ratio[0]->SetAxisRange(pXMIN, pXMAX, "X");
	  
    c->cd(2);
    if(pLOGX) gPad->SetLogx();
    if(pLOGY2) gPad->SetLogy();
    if(pDATA) {
      ratio[0]->SetFillStyle(3);
      ratio[0]->DrawCopy("E2"+pRATIO_OPT);
    }
    else  ratio[0]->DrawCopy(pRATIO_OPT);
    for(int i=0; i<ratio.size(); i++) ratio[i]->DrawCopy("SAME"+pRATIO_OPT);
    gPad->RedrawAxis();
  }
	
  if(pRETCAN)  {
    return c;
  }
  if(printname=="") printname = h[pDenom]->GetName();
  TString suffix = pPDF? ".pdf" : ".eps";
  c->Print("figures/"+printname+suffix);	
  if(pMAKE_C)   c->Print("figures/"+printname+".C");	

  delete c;
  if(pSTATS) delete c1;
  return c;
}


//=======================================================================
TCanvas *Draw(vector<TH1 *> h, TString printname, TString xtitle, TString ytitle) {
  vector<TString> legnames;
  for(int i=0; i<h.size(); i++) legnames.push_back(h[i]->GetName() );
  return Draw(h, legnames, printname, xtitle, ytitle);
}
//=======================================================================

TCanvas *Draw(TH1 *plot, TString printname, TString xtitle, TString ytitle) {
  vector<TH1*> plots;
  vector<TString> legnames;
  plots.push_back(plot);
  legnames.push_back(plot->GetName() );
  return Draw(plots, legnames, printname, xtitle, ytitle);
}


//=======================================================================

TCanvas *Draw(TString plot, vector<TString> files, vector<TString> legnames, TString printname, TString xtitle, TString ytitle) {

	vector<TH1 *> h;
	TFile * f1;
	for(int i=0; i<files.size(); i++) {
		f1 = new TFile(files[i], "READ");
		f1->cd();	
		TH1 * tmp = (TH1*)f1->Get(plot);
		tmp->SetDirectory(0);
		h.push_back( tmp );
		f1->Close();
	}

	return Draw(h, legnames, printname, xtitle, ytitle);
}

TCanvas *Draw(TString plot, vector<TString> files, TString printname, TString xtitle, TString ytitle) {
	//strip .root from the filenames?
	vector<TString> legnames(files);
	for(int i=0; i<legnames.size(); i++) legnames[i].ReplaceAll(".root", "");
	return Draw(plot, files, legnames, printname, xtitle, ytitle);
}

  TCanvas *Draw(TString plot, TString file, TString printname, TString xtitle, TString ytitle, int colour) {
  vector<TString> files;
  files.push_back(file);
  vector<TString> legnames;
  legnames.push_back(file);
  if(colour) {
    FillColours();
    COLOURS.clear();
    COLOURS.push_back(colour);
  }
  for(int i=0; i<legnames.size(); i++) legnames[i].ReplaceAll(".root", "");
  return Draw(plot, files, legnames, printname, xtitle, ytitle);
}


//=======================================================================


TCanvas *Draw(vector<TString> plots, TString file, vector<TString> legnames, TString printname, TString xtitle, TString ytitle) {

	vector<TH1 *> h;
	TFile * f1 = new TFile(file, "READ");
	f1->cd();	
	for(int i=0; i<plots.size(); i++) {
	  TH1 * tmp = (TH1*)f1->Get(plots[i]);
	  if(tmp) {
	    tmp->SetDirectory(0);
	    h.push_back( tmp );
	  }
	  else cout<<"Cannot load plot "<<plots[i]<<endl;
	}
	f1->Close();
	if(h.size()>0) return Draw(h, legnames, printname, xtitle, ytitle);
	cout<<"Nothing to plot!"<<endl;
	return 0;
}


TCanvas *Draw(vector<TString> plots, TString file,  TString printname, TString xtitle, TString ytitle) {
	return Draw(plots, file, plots, printname, xtitle, ytitle);
}

//=======================================================================


  TCanvas *Draw2D(vector<TString> plotnames, TString file, TString printname, TString xtitle, TString ytitle){
    vector<TH2*> plots;
    for(int i=0; i<plotnames.size(); i++) plots.push_back( Read2D(plotnames[i], file) );
    
    for(int i=0; i<plotnames.size(); i++) {

      prep(plots[i], COLOURS[i]);
    }
    TCanvas * c = Canvas();
    if(pZRANGE) plots[0]->SetAxisRange(pZMIN, pZMAX, "Z");
    if(pLOGZ) gPad->SetLogz();
    c->SetRightMargin(0.12);
    plots[0]->Draw(pOPT2D);
    for(int i=1; i<plots.size(); i++) plots[i]->Draw("SAME "+pOPT2D);
    if(printname=="") printname = plots[0]->GetName();
    c->Print("figures/"+printname+".pdf");
    gPad->RedrawAxis();
    if(pRETCAN) return c;
    delete c;
    return 0;
  }
  
  

  
  TCanvas *Draw2D(TH2 *plot, TString printname, TString xtitle, TString ytitle){
    TCanvas * c = Canvas();
    if(pZRANGE) plot->SetAxisRange(pZMIN, pZMAX, "Z");
    if(pLOGZ) gPad->SetLogz();
    //    cout<<pXMIN<<" "<< pXMAX<<endl;
    if(pXMIN!=-1 && pXMAX!=-1) plot->SetAxisRange(pXMIN, pXMAX, "X");
    if(pYMIN!=-1 && pYMAX!=-1) plot->SetAxisRange(pYMIN, pYMAX, "Y");
    if(pREBIN>1) plot->Rebin2D(pREBIN, pREBIN);

    c->SetRightMargin(0.12);
    plot->Draw(pOPT2D);
    if(printname=="") printname = plot->GetName();
    c->Print("figures/"+printname+".pdf");
    gPad->RedrawAxis();
    if(pRETCAN) return c;
    delete c;
    return 0;
  }
  
  
  
  TCanvas *Draw2D(TString plot, TString file, TString printname, TString xtitle, TString ytitle){
    return Draw2D(Read2D(plot, file),  printname, xtitle, ytitle);
  }



//=======================================================================



void prep(TPad *p) {
  //  p->DrawFrame(0,0,10,1);
  p->SetBottomMargin(0.12);
  p->SetTopMargin(0.04);
  p->SetRightMargin(0.04);
  p->SetLeftMargin(0.13); //was 0.16
  p->GetFrame()->SetBorderSize(0);
  p->SetTicks(1,1); 
  if(pGRIDX)p->SetGridx();
  if(pGRIDY)p->SetGridy();
}

void prep(TVirtualPad *p) {prep( (TPad*)p );}


void Divide(TCanvas * c1) {
  c1->cd();
  TPad *pad;
  char *name  = new char [strlen(gPad->GetName())+6];  
  sprintf(name,"%s_%d",gPad->GetName(),1);
  pad = new TPad(name,name,0,0.5,1,1, 0);
  pad->SetNumber(1);
  pad->Draw();
  
  sprintf(name,"%s_%d",gPad->GetName(),2);
  pad = new TPad(name,name,0,0,1,0.5, 0);
  pad->SetNumber(2);
  pad->Draw();
  
  for(int i=1; i<=2; i++) {
    c1->cd(i);
    prep((TPad*)gPad);
  }  

  c1->cd(1);
  //  gPad->SetBottomMargin(0);
  
  c1->cd(2);
  gPad->SetTopMargin(0);
  //  gPad->SetBottomMargin(0.2);
  gPad->SetGridx();
  gPad->SetGridy();

  return;
}

//=======================================


void DivideSmallRatio(TCanvas * c1) {
  c1->cd();
  TPad *pad;
  char *name  = new char [strlen(gPad->GetName())+6];  
  sprintf(name,"%s_%d",gPad->GetName(),1);
  pad = new TPad(name,name,0,0.33,1,1, 0);
  pad->SetNumber(1);
  pad->Draw();
  
  sprintf(name,"%s_%d",gPad->GetName(),2);
  pad = new TPad(name,name,0,0,1,0.33, 0);
  pad->SetNumber(2);
  pad->Draw();
  
  for(int i=1; i<=2; i++) {
    c1->cd(i);
	 prep((TPad*)gPad);
  }  

  c1->cd(1);
  gPad->SetBottomMargin(0);
  
  c1->cd(2);
  gPad->SetTopMargin(0);
  gPad->SetBottomMargin(0.2);
  gPad->SetGridx();
  gPad->SetGridy();

  return;
}





//=======================================

void DivideLargeRatio(TCanvas * c1) {
  c1->cd();
  TPad *pad;
  char *name  = new char [strlen(gPad->GetName())+6];  
  sprintf(name,"%s_%d",gPad->GetName(),1);
  pad = new TPad(name,name,0,0.66,1,1, 0);
  pad->SetNumber(1);
  pad->Draw();
  
  sprintf(name,"%s_%d",gPad->GetName(),2);
  pad = new TPad(name,name,0,0,1,0.66, 0);
  pad->SetNumber(2);
  pad->Draw();
  
  for(int i=1; i<=2; i++) {
    c1->cd(i);
    prep((TPad*)gPad);
  }  

  c1->cd(1);
  //  gPad->SetBottomMargin(0);
  
  c1->cd(2);
  gPad->SetTopMargin(0);
  //  gPad->SetBottomMargin(0.15);
  gPad->SetGridx();
  gPad->SetGridy();
  // gPad->SetLogy();



  return;
}



//-----------------------------------------------------------------------


TCanvas * Canvas(int x, int y, TString name) {
  TCanvas * c1 = new TCanvas(name, name, x, y);
  c1->cd();
  prep((TPad*)gPad);
  return c1;
}

TCanvas * Canvas(TString name) {
	return Canvas(pCANVASX, pCANVASY, name);
}






//-----------------------------------------------------------------------
//-----------------------------------------------------------------------


TLegend *Legend(vector<TH1*> plots, double x1, double y1, double x2, double y2) {
	TLegend * leg = Legend(x1, y1, x2, y2);
	for(int i=0; i<plots.size(); i++) leg->AddEntry(plots[i], plots[i]->GetTitle(), "LEP");
	return leg;
}

TLegend *Legend(vector<TH1*> plots, vector<TString> names, double x1, double y1, double x2, double y2) {
	TLegend * leg = Legend(x1, y1, x2, y2);
	for(int i=0; i<plots.size(); i++) leg->AddEntry(plots[i], names[i], "LEP");
	return leg;
}


TLegend *Legend(double x1, double y1, double x2, double y2) {
  TLegend *leg2 = new TLegend(x1,y1,x2, y2, "", "NDC");
  leg2->SetTextSize(0.04);
  leg2->SetTextFont(42);
  leg2->SetFillColor(-1);
  leg2->SetBorderSize(0);
  return leg2;
}


TLegend *Legend(THStack *st) {
  TLegend *leg = new TLegend(pX1, pY1, pX2, pY2);
  leg->SetTextSize(0.04);
  leg->SetTextFont(42);
  leg->SetFillColor(0);
  leg->SetBorderSize(0);
  TH1 * h = (TH1*)st->GetHists()->First();
  while( h ) { 
	  leg->AddEntry(h, h->GetName(), "LEPF");   
	  h = (TH1*)st->GetHists()->After( h );  
  } 
  return leg;
}




TLatex * Latex(double textSize, bool NDC) {
  TLatex *l = new TLatex();
  if(NDC) l->SetNDC();
  l->SetTextFont(42);
  l->SetTextColor(1);
  l->SetTextSize(textSize);
  return l;
}

TLatex * Latex(bool NDC) {
  return Latex(0.055, NDC);
}







void multStat(vector<TH1 *> h, vector<TString> legnames, TString printname, TString xtitle, TString ytitle) {
  
  /*Create Histogram 1, fill it some data and draw*/
  TCanvas *c1 = new TCanvas();
  TH1* h1 = new TH1F("hist1","Histogram 1", 100,-2,2);
  h1->FillRandom("gaus",2000);
  h1->Draw();
  gPad->Update(); //IMPORTANT
  
  /* collect stat of the first histogram (h1) */
  TPaveStats *tps1 = (TPaveStats*) h1->FindObject("stats");
  tps1->SetName("Hist1 Stats");
  double X1 = tps1->GetX1NDC();
  double Y1 = tps1->GetY1NDC();
  double X2 = tps1->GetX2NDC();
  double Y2 = tps1->GetY2NDC();

  /*Create Histogram 2, fill it some data and draw*/
  TH1* h2 = new TH1F("hist2","Histogram 2", 100,-2,2);
  h2->SetLineColor(kRed);
  h2->FillRandom("gaus",500);

  TCanvas *c2 = new TCanvas();
  h2->Draw();
  gPad->Update(); //IMPORTANT

  /* collect stat of the second histogram (h2) */
  TPaveStats *tps2 = (TPaveStats*) h2->FindObject("stats");
  tps2->SetTextColor(kRed);
  tps2->SetLineColor(kRed);
  tps2->SetX1NDC(X1);
  tps2->SetX2NDC(X2);
  tps2->SetY1NDC(Y1-(Y2-Y1));
  tps2->SetY2NDC(Y1);

  /* Draw all (two histograms and their stat boxes in one canvas */
  TCanvas *c3 = new TCanvas();
  h1->Draw();
  h2->Draw("same");
  tps1->Draw("same");
  tps2->Draw("same");
  c3->Print("test.eps");
  return;
}






  TGraphErrors * MakeGraph(vector<double>lumi, vector<double>dEdx, vector<double>lumi_err, vector<double>dEdx_err, TString xtitle, TString ytitle) {
    
    double *x = new double[lumi.size()];  
    double *y = new double[dEdx.size()];  
    double *xerr = new double[lumi_err.size()];  
    double *yerr = new double[dEdx_err.size()];  
    for(int i=0; i<lumi.size(); i++) {
      // cout<<lumi.size()<<" "<<dEdx.size()<<" "<<i<<" "<<lumi[i]<<" "<<dEdx[i]<<" "<<lumi_err[i]<<" "<<dEdx_err[i]<<endl;
      x[i] = lumi[i];
      y[i] = dEdx[i];
      xerr[i] = lumi_err[i];
      yerr[i] = dEdx_err[i];
    }
    
    
    TGraphErrors *gr =  new TGraphErrors(lumi.size(), x, y, xerr, yerr);
    prep(gr);
    gr->GetXaxis()->SetTitle(xtitle);
    gr->GetYaxis()->SetTitle(ytitle);

    return gr;

  }
  
  TGraph * MakeGraph(vector<double> xv, vector<double> yv, TString xtitle, TString ytitle) {    
    double *x = new double[xv.size()];  
    double *y = new double[yv.size()];  
    for(int i=0; i<xv.size(); i++) {
      x[i] = xv[i];
      y[i] = yv[i];
    }
    TGraph * gr = new TGraph(xv.size(), x, y);
    prep(gr);
    gr->GetXaxis()->SetTitle(xtitle);
    gr->GetYaxis()->SetTitle(ytitle);
    
    return gr;

  }
  


  
}//namespace


