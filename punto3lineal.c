
//Ajuste a una recta y a una constante


Double_t fitl(Double_t *x, Double_t *par){

Double_t lineal = 0;

lineal = par[1]*x[0] + par[2];               //Defino una funcion lineal con estos parametros

return lineal;

}




void punto3lineal(){

TH1D* hu = new TH1D("hu", "Hisotograma uniforme", 10, 0, 10);
TF1* func = new TF1("func",fitl,10, 0, 10); 


Int_t i;



for(i = 0; i<100; i++){

hu->Fill(gRandom->Uniform(10));      //Genera una distribucion uniforme en el histograma

}


Double_t escal = 1/(hu->Integral());       //Normalizacion de los histogramas

hu->Scale(escal);
hu->Draw();
hu->SetTitle("Ajustes");
hu->Fit("func");

}




