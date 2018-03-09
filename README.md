# General setup

The general setup has already been performed, based on the instructions found in the DAnalysis framework twiki.

https://twiki.cern.ch/twiki/bin/view/CMS/DAnalysisFramework

# Configuration (To be done every time)
  
These two commands should be executed every time you launch a new lxplus session.

    source env.sh
    make -j  

# Create/run an analyser

The first step to produce some plots is to create a config file (the template config/testConfig.txt is there to help you), by selecting the processes you want to consider along with their cross sections in fb-1 (or in pb-1 if the lumi is set to 1000). The number of events can be set to "auto" and the testMode can be used to reduce artificially the number of events considered.

Once this is done, you will either need to create a new or use a previously created analyser. To create a new one, you can just run the following command:

    createAnalyser.sh <analyserName>

A simple command then allows you to run the analyser, after compiling it.      

    make -j
    ./<analyserName> <configFile>

# Create some plots

The output of the previous command does not have the correct format to be used as input to the plotter macro. You first need to update the formatForPlotter.C macro accordingly and run it:

    cd test
    root -l -b -q formatForPlotter.C 

This should create a new *rootfiles* directory that can be uread by the plotter.

    ./make
    ./runPlotter