{

//ild TStyle
TStyle* ivanStyle = new  TStyle("ivanStyle", "Ivan Style");

//set the background color to white
ivanStyle->SetFillColor(0);
ivanStyle->SetFrameFillColor(0);
ivanStyle->SetCanvasColor(0);
ivanStyle->SetPadColor(0);
ivanStyle->SetTitleFillColor(0);
ivanStyle->SetStatColor(0);

//dont put a colored frame around the plots
ivanStyle->SetFrameBorderMode(0);
ivanStyle->SetCanvasBorderMode(0);
ivanStyle->SetPadBorderMode(0);
ivanStyle->SetLegendBorderSize(0);

//use the primary color palette
ivanStyle->SetPalette(1,0);

//set the default line color for a histogram to be black
ivanStyle->SetHistLineColor(kBlack);

//set the default line color for a fit function to be red
ivanStyle->SetFuncColor(kRed);

//make the axis labels black
ivanStyle->SetLabelColor(kBlack,"xyz");

//set the default title color to be black
ivanStyle->SetTitleColor(kBlack);
 
//set the margins
ivanStyle->SetPadBottomMargin(0.18);
ivanStyle->SetPadTopMargin(0.08);
ivanStyle->SetPadRightMargin(0.15);
ivanStyle->SetPadLeftMargin(0.2);

//set axis label and title text sizes
ivanStyle->SetLabelFont(42,"xyz");
ivanStyle->SetLabelSize(0.06,"xyz");
ivanStyle->SetLabelOffset(0.015,"xyz");
ivanStyle->SetTitleFont(42,"xyz");
ivanStyle->SetTitleSize(0.07,"xyz");
ivanStyle->SetTitleOffset(1.3,"yz");
ivanStyle->SetTitleOffset(1.0,"x");
ivanStyle->SetStatFont(42);
ivanStyle->SetStatFontSize(0.07);
ivanStyle->SetTitleBorderSize(0);
ivanStyle->SetStatBorderSize(0);
ivanStyle->SetTextFont(42);

//set line widths
ivanStyle->SetFrameLineWidth(2);
ivanStyle->SetFuncWidth(2);
ivanStyle->SetHistLineWidth(2);

//set the number of divisions to show
ivanStyle->SetNdivisions(506, "xy");

//turn off xy grids
ivanStyle->SetPadGridX(0);
ivanStyle->SetPadGridY(0);

//set the tick mark style
ivanStyle->SetPadTickX(1);
ivanStyle->SetPadTickY(1);

//turn off stats
ivanStyle->SetOptStat(0);
ivanStyle->SetOptFit(0);

//marker settings
ivanStyle->SetMarkerStyle(20);
ivanStyle->SetMarkerSize(0.7);
ivanStyle->SetLineWidth(2); 

//done
ivanStyle->cd();
gROOT->ForceStyle();
gStyle->ls();

}
