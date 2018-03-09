const int nprocess = 4;
const int nhistograms = 1;

const TString process[nprocess] = {"TT", "DY", "ST", "WJets"};
const TString histogram[nhistograms] = {"histoname1"};

TFile* output[nprocess];
TH1D* histo[nprocess][nhistograms];

void formatForPlotter() {
  
  gSystem->mkdir("rootfiles", kTRUE);
  gSystem->cd("rootfiles");
  
  TFile* input = new TFile ("../../output/outputfile.root", "read");

  for(int i=0; i < nprocess; i++) {

    output[i] = new TFile(Form("%s.root", process[i].Data()), "recreate");

    for(int j=0; j < nhistograms; j++) {
      histo[i][j] = (TH1D*)input -> Get(Form("d_%s/%s", process[i].Data(), histogram[j].Data()));
      histo[i][j] -> Write(histogram[j].Data());
    }

    output[i] -> Close();

  }

}
