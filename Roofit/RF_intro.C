using namespace RooFit;

void RF_intro()
{

   // Observable:
   RooRealVar mes("mes", "mass (GeV)", 0, 10);

   // Parameters:
   RooRealVar sigmean("sigmean", "mean", 3.5, 4., 6.);
   RooRealVar sigwidth("sigwidth", "width", 0.25, 0.001, 2.);

   // Build a Gaussian PDF:
   RooGaussian signalModel("signal", "signal PDF", mes, sigmean, sigwidth);

   // Build exponential background PDF:
   RooRealVar tau("tau","tau", -0.5, -2,2);
   RooExponential background("background", "expo PDF", mes, tau);

   // Construct a signal and background PDF:
   RooRealVar nsig("nsig", "#signal events", 100, 0., 10000);
   RooRealVar nbkg("nbkg", "#background events", 1e3, 0., 10000);
   RooAddPdf model("model", "g+a", {signalModel, background}, {nsig, nbkg});

   // The PDF is used to generate an un-binned toy data set, then the PDF is
   // fit to that data set using an un-binned maximum likelihood fit.
   // Then the data are visualized with the PDF overlaid.

   // Generate a toy MC sample from composite PDF:
   std::unique_ptr<RooDataSet> data{model.generate(mes, 1.1e3)};

   // Perform extended ML fit of composite PDF to toy data:
   model.fitTo(*data);

   // Create a RooPlot to draw on. We don't manage the memory of the returned
   // pointer. Instead we let it leak such that the plot still exists at the end of
   // the macro and we can take a look at it.
   RooPlot *mesframe = mes.frame(Title("My first plot"));

   // Plot toy data and composite PDF overlaid:
   data->plotOn(mesframe,Binning(25));
   model.plotOn(mesframe);
   model.plotOn(mesframe, Components(background), LineStyle(ELineStyle::kDashed),LineColor(kRed));
   mesframe->Draw();

   TCanvas *c = new TCanvas("c","c",1300,400);
   c->Divide(3,1);
   c->cd(1); mesframe->Draw();

   c->cd(2);
   RooPlot *sigframe = mes.frame(Title("Signal"));
   signalModel.plotOn(sigframe, LineColor(kGreen));
   sigframe->Draw();

   c->cd(3);
   RooPlot *bkgframe = mes.frame(Title("Bkg"));
   background.plotOn(bkgframe, LineColor(kBlue));
   bkgframe->Draw();


}