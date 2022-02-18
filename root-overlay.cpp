#include "TFile.h"
#include "TH1.h"
#include "TEfficiency.h"
#include "TCanvas.h"
#include "TKey.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;

//void MakeWebPage(std::ofstream out, TDirectory *input );
void MakeWebPage(std::ofstream &out, TDirectory *input, TString workingdir );

void WebCanvas(std::ofstream &out, TString workingdir, TCanvas *c) {
  // cout<<"In webcanvas"<<endl;
  TString figfile = workingdir+"/figures/"+(TString)c->GetName();
  TString figfilelink = "figures/"+(TString)c->GetName();
  
  c->Print(figfile+".pdf");
  system( "convert -density 144 -trim +repage "+figfile+".pdf "+figfile+".gif");
  system( "convert -density 40 -trim +repage "+figfile+".pdf "+figfile+"_thumb.gif");
  
  
  out<<"<div style=\"float:left; font-size:smaller; font-weight:bold;\">"<<endl;
  out<< "    <td align=\"center\">" <<endl;
  out<< c->GetName() <<" <a href=\""+figfilelink+".gif\">gif</a>, <a href=\""+figfilelink+".pdf\">pdf</a><br>"<<endl;
  out<< "      <a href=\""+figfilelink+".gif\"> <img src=\""+figfilelink+"_thumb.gif\"> </a>" <<endl;
  out<< "    </td>  " <<endl;
  out<< "    </div>  " <<endl;
  
  //  cout<<"End webcanvas"<<endl;
  return;
}




int main(int argc, char **argv) {

  TString filepath = "/home/hesketh/test.root";
  bool directories = false;
  for(int i=1; i<argc; i++) {
    
    
    if(argc>1) filepath = argv[1];
  if(argc>2) directories = argv[2]=="true";

  TString filename = filepath;
  filename.Remove(0, filename.Last('/')+1);
  cout<<filename<<endl;
  
  TFile * inputfile = new TFile(filepath, "READ" );

    
  MakeWebPage(out, inputfile, workingdir);
 
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

      if ( obj->IsA()->InheritsFrom( TH1::Class() ) ) {
         // descendant of TH1 -> plot it!

	cout << "Drawing histogram " << obj->GetName() << endl;
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
      }
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
         // loop over all source files create a chain of Trees "globChain"
         const char* obj_name= obj->GetName();

         globChain = new TChain(obj_name);
         globChain->Add(first_source->GetName());
         TFile *nextsource = (TFile*)sourcelist->After( first_source );
         //      const char* file_name = nextsource->GetName();
         // cout << "file name  " << file_name << endl;
         while ( nextsource ) {

            globChain->Add(nextsource->GetName());
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
         MergeRootfile( newdir, sourcelist );

      } else {

         // object is of no type that we know or can handle
         cout << "Unknown object type, name: "
         << obj->GetName() << " title: " << obj->GetTitle() << endl;
      }

      // now write the merged histogram (which is "in" obj) to the target file
      // note that this will just store obj in the current directory level,
      // which is not persistent until the complete directory itself is stored
      // by "target->Write()" below
      if ( obj ) {
         target->cd();

         //!!if the object is a tree, it is stored in globChain...
         if(obj->IsA()->InheritsFrom( TTree::Class() ))
            globChain->Merge(target->GetFile(),0,"keep");
         else
            obj->Write( key->GetName() );
      }

   } // while ( ( TKey *key = (TKey*)nextkey() ) )

   // save modifications to target file
   target->SaveSelf(kTRUE);
   TH1::AddDirectory(status);
}





 

void MakeWebPage(std::ofstream &out, TDirectory *input, TString workingdir ) {


  TDirectory *current_sourcedir = gDirectory;
  //gain time, do not add the objects in the list in memory
  Bool_t status = TH1::AddDirectoryStatus();
  TH1::AddDirectory(kFALSE);

  // loop over all keys in this directory
  TIter nextkey( current_sourcedir->GetListOfKeys() );
  TKey *key, *oldkey=0;
  while ( (key = (TKey*)nextkey())) {

    //keep only the highest cycle number for each key
    if (oldkey && !strcmp(oldkey->GetName(),key->GetName())) continue;
    
    // read object from first source file
    TObject *obj = key->ReadObj();
    
    if ( obj->IsA()->InheritsFrom( TH2::Class() ) ) {
      // descendant of TH2 -> draw it!
      TH2 *h2 = (TH2*)obj;
      TCanvas * c = new TCanvas();
      c->SetName(h2->GetName());
      c->cd();
      h2->DrawCopy("COLZ");
      WebCanvas(out, workingdir, c);
      delete c;
      delete h2;
    }
    else if ( obj->IsA()->InheritsFrom( TH1::Class() ) ) {
      // descendant of TH1 -> draw it!
      TH1 *h1 = (TH1*)obj;
      TCanvas * c = new TCanvas();
      c->SetName(h1->GetName());
      c->cd();
      h1->DrawCopy();
      WebCanvas(out, workingdir, c);
      delete c;
      delete h1;
    }
    else if ( obj->IsA()->InheritsFrom( TCanvas::Class() ) ) {
      // descendant of TCanvas -> draw it!
      TCanvas * c = (TCanvas*)obj;
      WebCanvas(out, workingdir, c);
      //  delete c;
    }
    else if ( obj->IsA()->InheritsFrom( TDirectory::Class() ) ) {
      // it's a subdirectory
      
    cout << "Found subdirectory " << obj->GetName() << endl;
    cout << "Not sure what to do with these yet..." << endl;
    /*
    // create a new subdir of same name and title in the target file
    target->cd();
    TDirectory *newdir = target->mkdir( obj->GetName(), obj->GetTitle() );

    // newdir is now the starting point of another round of merging
    // newdir still knows its depth within the target file via
    // GetPath(), so we can still figure out where we are in the recursion
    MergeRootfile( newdir, sourcelist );
    */
    } 
    else {

      // object is of no type that we know or can handle
      cout << "Unknown object type, name: "
	   << obj->GetName() << " title: " << obj->GetTitle() << endl;
    }

  }//loop over keys



}
