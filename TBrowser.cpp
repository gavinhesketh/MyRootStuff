#include "TApplication.h"
#include "TBrowser.h"
#include "TFile.h"

#include <iostream>

int main(int argc, char **argv){
  
  for(int ia=1; ia<argc; ia++) {
    std::cout<<"Opening file "<<argv[ia]<<std::endl;
    TFile *file = new TFile(argv[ia], "READ");
  }  
  TApplication theApp("tapp", &argc, argv);
  TBrowser *t = new TBrowser("tb", "TB", 1275, 668);
  theApp.Run();

  return 1;

}
