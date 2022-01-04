#include "MyRootStuff.h"
#include "TFile.h"
#include "TH1.h"
#include "TTree.h"
#include "TKey.h"
#include <fstream>

using namespace MyRootStuff;

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
  if(argc>1) filepath = argv[1];
  if(argc>2) directories = argv[2]=="true";

  TString filename = filepath;
  filename.Remove(0, filename.Last('/')+1);
  cout<<filename<<endl;
  
  TFile * inputfile = new TFile(filepath, "READ" );

  std::ofstream out;
  TString workingdir = "webpage_"+filename;
  
  system("mkdir "+workingdir);
  system("mkdir "+workingdir+"/figures");
  out.open (workingdir+"/index.html", std::ios::out); 

  out <<"<style>"<<endl
      <<" html { font-family: sans-serif; }"<<endl
      <<"img { border: 0; }"<<endl
      <<"a { text-decoration: none; font-weight: bold; }"<<endl
      <<"</style>"<<endl;
  
  out<<"<html>\n<head>\n<title>"<<inputfile->GetName()<<"</title>"<<inputfile->GetName()<<"</head>\n<body>\n<br><br>" <<endl;
  // out<<"<p><a href=\"../index.html\">Back to index</a></p>\n"<<endl;
  out<<"<div style=\"float:none; overflow:auto; width:100%\">\n"<<endl;
    
  MakeWebPage(out, inputfile, workingdir);
 
  out<< "    </div>  " <<endl;
  out.close();

  return 1;

}
  

//==================================================================



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
    
    if ( obj->IsA()->InheritsFrom( TH1::Class() ) ) {
      // descendant of TH1 -> draw it!
      TH1 *h1 = (TH1*)obj;
      TCanvas * c = new TCanvas();
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
      delete c;
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
