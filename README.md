# General setup

The general setup has already been performed, based on the instructions found in the DAnalysis framework twiki.

https://twiki.cern.ch/twiki/bin/view/CMS/DAnalysisFramework

# Configuration (To be done every time)
  
Clone the "YRupdate" branch. 
 
These two commands should be executed every time you launch a new lxplus session. You will need a bash: 

    source env.sh
    make -j  

# Create/run an analyser

./runAnalyser config/testSUSYsamples.txt

# Create some plots

The output of the previous command does not have the correct format to be used as input to the plotter macro. You first need to update the formatForPlotter.C macro accordingly and run it:

    cd test
    root -l -b -q formatForPlotter.C 

This should create a new *rootfiles* directory that can be uread by the plotter.

    ./make
    ./runPlotter