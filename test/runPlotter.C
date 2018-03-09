#include "HistogramReader.h"

// Constants
//------------------------------------------------------------------------------
const Bool_t basictest  = true;

const TString inputdir  = "rootfiles/";
const TString outputdir = "figures/";

enum {linY, logY};


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// runPlotter
//
// option = "hist"         --> all distributions normalized to the luminosity
// option = "nostack,hist" --> signal and top distributions normalized to one
//
//   Draw(TString  hname,                  Name of the histogram.
//        TString  xtitle       = "",      Title of the x-axis.
//        Int_t    ngroup       = -1,      Number of bins to be merged into one bin.
//        Int_t    precision    = 0,       Number of decimal digits.
//        TString  units        = "NULL",  Units of the histogram.
//        Bool_t   setlogy      = false,   Set it to true (false) for logarithmic (linear) scale.
//        Bool_t   moveoverflow = true,    Set it to true to plot the events out of range.
//        Float_t  xmin         = -999,
//        Float_t  xmax         = -999,
//        Float_t  ymin         = -999,
//        Float_t  ymax         = -999);
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void runPlotter(TString level = "",
		TString option = "hist")
{
  gInterpreter->ExecuteMacro("PaperStyle.C");

  float lumi = 1;

  Bool_t scale = linY;

  HistogramReader plotter(inputdir, outputdir);

  plotter.SetStackOption(option);
  plotter.SetPublicStyle( false);
  plotter.SetSavePdf    (  true);
  plotter.SetChangeLabel( false);

  if (option.Contains("nostack"))
    {
      plotter.SetDrawRatio(false);
    }
  else
    {
      plotter.SetLuminosity(lumi);
      plotter.SetDrawRatio (true);
    }


  plotter.AddProcess("DY",     "DY",        color_ZJets, roc_background, 1.0);
  plotter.AddProcess("WJets", "W+jets",  color_Fakes, roc_background, 1.0);
  plotter.AddProcess("ST", "Single top",  color_ST, roc_background, 1.0);
  plotter.AddProcess("TT", "t#bar{t}",  color_TTTo2L2Nu, roc_background, 1.0);

  // Make an output directory for each level
  //----------------------------------------------------------------------------
  gSystem->mkdir(outputdir + level, kTRUE);


  // Draw distributions
  //----------------------------------------------------------------------------
  if (!option.Contains("nostack")) plotter.SetDrawYield(true);

  plotter.Draw("histoname1", "histoname1", -1, 0, "GeV", true, 0, 100, 0.001, 1e11);

  // Copy index.php in every directory
  //----------------------------------------------------------------------------
  gSystem->Exec("for dir in $(find ./ -type d); do cp -n ../index.php $dir/; done");
  gSystem->Exec("rm -f index.php");
}


//------------------------------------------------------------------------------
//
// main
//
//------------------------------------------------------------------------------
# ifndef __CINT__
int main(int argc, char ** argv)
{
  /*if (argc < 2) {

    printf("\n rm -rf %s\n\n", outputdir.Data());

    for (int i=0; i<ncut; i++) printf(" ./runPlotter %s\n", scut[i].Data());

    printf("\n");

    exit(0);
    }*/

  if (argc == 2)
    runPlotter(argv[1]);
  else
    runPlotter("", "hist");

  return 0;
}
# endif
