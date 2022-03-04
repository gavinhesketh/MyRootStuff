#include "TFile.h"
#include "TChain.h"
#include "TH1.h"
#include "TH2.h"
#include "TEfficiency.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "TFrame.h"
#include "TStyle.h"
#include "TKey.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;

float RATIOYMIN_ = 0.51;
float RATIOYMAX_ = 1.99;


void OverlayPlots( TDirectory *target, TList *sourcelist );



void prep( TH1 * p, float scale) {

  float SCALE_ = 0.05;
  
  gStyle->SetOptTitle(0);
  p->GetXaxis()->SetLabelFont(42);
  p->GetYaxis()->SetLabelFont(42);
  p->GetXaxis()->SetLabelSize(scale*SCALE_);
  p->GetYaxis()->SetLabelSize(scale*SCALE_);

  p->GetXaxis()->SetTitleFont(42);
  p->GetYaxis()->SetTitleFont(42);
  p->GetXaxis()->SetTitleSize(scale*SCALE_);
  p->GetYaxis()->SetTitleSize(scale*SCALE_);
  p->GetXaxis()->SetTitleOffset(1.2);
  p->GetYaxis()->SetTitleOffset(1.2);

  //for ratio pane?
  //  p->GetXaxis()->SetTitleOffset(1);
  //  p->GetYaxis()->SetTitleOffset(0.8);

  p->SetStats(0);
  p->SetLineWidth(2);
  p->SetMarkerSize(1.5);
  p->SetFillColor(0);

}




void prep(TPad *p) {
  //  p->DrawFrame(0,0,10,1);
  p->SetBottomMargin(0.12);
  p->SetTopMargin(0.05);
  p->SetRightMargin(0.05);
  p->SetLeftMargin(0.13); //was 0.16
  p->GetFrame()->SetBorderSize(0);
  p->SetTicks(1,1); 
}

TCanvas * Canvas(TString name) {
  TCanvas * c1 = new TCanvas(name, name, 800, 800);
  c1->cd();

  TPad *pad;
  char *pname  = new char [strlen(gPad->GetName())+6];  
  sprintf(pname,"%s_%d",gPad->GetName(),1);
  pad = new TPad(pname,pname,0,0.4,1,1, 0);
  pad->SetNumber(1);
  pad->Draw();
  
  sprintf(pname,"%s_%d",gPad->GetName(),2);
  pad = new TPad(pname,pname,0,0,1,0.4, 0);
  pad->SetNumber(2);
  pad->Draw();
  
  c1->cd(1);
  prep((TPad*)gPad);
  gPad->SetBottomMargin(0);
  c1->cd(2);
  prep((TPad*)gPad);
  gPad->SetTopMargin(0);
  gPad->SetBottomMargin(0.2);
  gPad->SetGridx();
  gPad->SetGridy();
  
  return c1;
}


TList *FileList;
TFile *Target;

int main(int argc, char **argv) {

  FileList = new TList();
  for(int i=1; i<argc; i++) {
    cout<<"Adding file "<<argv[i]<<endl;
    FileList->Add( TFile::Open(argv[i]) );
  }

  
  gStyle->SetPalette(kCMYK);//VisibleSpectrum); //LightTemperature); //kGreenRedViolet);
  TColor::InvertPalette();
  gStyle->SetOptTitle(0);


  Target = TFile::Open( "result.root", "RECREATE" );
  
  OverlayPlots( Target, FileList );

  cout<<"Finish"<<endl;
  
  return 1;

}
  

//==================================================================


void OverlayPlots( TDirectory *target, TList *sourcelist ) {

   //  cout << "Target path: " << target->GetPath() << endl;
   TString path( (char*)strstr( target->GetPath(), ":" ) );
   path.Remove( 0, 2 );

   TFile *first_source = (TFile*)sourcelist->First();
   first_source->cd( path );
   TDirectory *current_sourcedir = gDirectory;
   //gain time, do not add the objects in the list in memory
   Bool_t status = TH1::AddDirectoryStatus();
   TH1::AddDirectory(kFALSE);

   // loop over all keys in this directory
   TChain *globChain = 0;
   TIter nextkey( current_sourcedir->GetListOfKeys() );
   TKey *key, *oldkey=0;
   while ( (key = (TKey*)nextkey())) {

      //keep only the highest cycle number for each key
      if (oldkey && !strcmp(oldkey->GetName(),key->GetName())) continue;

      // read object from first source file
      first_source->cd( path );
      TObject *obj = key->ReadObj();



      //=======================================================================
      //==================     TH1    =========================================
      //=======================================================================
      if ( obj->IsA()->InheritsFrom( TH2::Class() ) ) {
	//ignore for now...
      }
      else if ( obj->IsA()->InheritsFrom( TH1::Class() ) ) {
         // descendant of TH1 -> plot it!

	cout << "Drawing histogram " << obj->GetName() << endl;

	
	TH1 *h1 = (TH1*)obj;
	h1->SetDirectory(0);
	h1->SetTitle(first_source->GetName());
	
	std::vector<TH1*> plots;
	plots.push_back(h1);

	TFile *nextsource = (TFile*)sourcelist->After( first_source );
	while ( nextsource ) {
	  // make sure we are at the correct directory level by cd'ing to path
	  nextsource->cd( path );
	  TKey *key2 = (TKey*)gDirectory->GetListOfKeys()->FindObject(h1->GetName());
	  if (key2) {
	    TH1 *h2 = (TH1*)key2->ReadObj();
	    h2->SetDirectory(0);
	    h2->SetTitle(nextsource->GetName());
	    plots.push_back(h2);
	  }
	  nextsource = (TFile*)sourcelist->After( nextsource );
	}
	delete nextsource;
      	
	TCanvas * c = Canvas(h1->GetName());
	c->cd();
	plots[0]->DrawCopy();	
	for(int i=1; i<plots.size(); i++) plots[i]->DrawCopy("SAME");	
	target->cd();
	
	c->Write();

	//	delete c;
	
      }




      //=======================================================================
      //==================     TEfficiency   ==================================
      //=======================================================================

      else if ( obj->IsA()->InheritsFrom( TEfficiency::Class() ) ) {
	// descendant of TEfficiency -> plot it!
	cout << "Drawing efficiency histogram " << obj->GetName() << endl;
         TH1 *h1 = (TH1*)obj;

         // loop over all source files and add the content of the
         // correspondant histogram to the one pointed to by "h1"
         TFile *nextsource = (TFile*)sourcelist->After( first_source );
         while ( nextsource ) {
	   
	   // make sure we are at the correct directory level by cd'ing to path
	   nextsource->cd( path );
	   TKey *key2 = (TKey*)gDirectory->GetListOfKeys()->FindObject(h1->GetName());
	   if (key2) {
	     TH1 *h2 = (TH1*)key2->ReadObj();
	     h1->Add( h2 );
	     delete h2;
	   }
	   
	   nextsource = (TFile*)sourcelist->After( nextsource );
         }

      

      } else if ( obj->IsA()->InheritsFrom( TDirectory::Class() ) ) {
         // it's a subdirectory

         cout << "Found subdirectory " << obj->GetName() << endl;

         // create a new subdir of same name and title in the target file
         target->cd();
         TDirectory *newdir = target->mkdir( obj->GetName(), obj->GetTitle() );

         // newdir is now the starting point of another round of merging
         // newdir still knows its depth within the target file via
         // GetPath(), so we can still figure out where we are in the recursion
         OverlayPlots( newdir, sourcelist );

      } else {

         // object is of no type that we know or can handle
         cout << "Unknown object type, name: "
         << obj->GetName() << " title: " << obj->GetTitle() << endl;
      }


   } // while ( ( TKey *key = (TKey*)nextkey() ) )

   // save modifications to target file
   target->SaveSelf(kTRUE);
   TH1::AddDirectory(status);
}




