#include <string>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <vector>

#include "CSolverInfluxo.h"

using namespace std;

void CSolverInfluxo::Simular()
{

    bool rodar = true;
    bool teste = false;

    while(!teste)
    {

        do
        {
        cout << endl;
        cout << "Deseja executar o codigo? (1 - sim , 2 - nao): ";
        char c;
        cin >> c;
        cin.get();

        if (c == '1')
        {    

        cout << endl;

        cout << "######################################################################" << endl;
        cout << "#                                                                    #" << endl;
        cout << "#                  Projeto de programacao pratica                    #" << endl;
        cout << "# Professorr: Andre Duarte Bueno                                     #" << endl;
        cout << "#                                                                    #" << endl;
        cout << "# Alunos: David Henrique Lima Dias                                   #" << endl;
        cout << "#         Julia Rangel Ribeiro                                       #" << endl;
        cout << "#         Marcos Vinicius de Paula Chaiben                           #" << endl;
        cout << "#                                                                    #" << endl;
        cout << "######################################################################" << endl << endl;

        cout << "Aperte ENTER para continuar com carregamento de dados..." << endl;
        cin.get();

        EntradaDadosReservatorio();
        
        cout << "Aperte ENTER para continuar com carregamento de dados..." << endl;
        cin.get();

        EntradaDadosRochaReservatorio();

        cout << "Aperte ENTER para continuar com carregamento de dados..." << endl;
        cin.get();

        EntradaDadosCamadas();
        cout << "####################################################" << endl;
        cout << "#  Todos arquivos foram carregados com sucesso!!   #" << endl;
        cout << "####################################################" << endl << endl;

        cout << "# qual metodo deseja utilizar?" << endl << endl;
        cout << "# 1 - Stiles" << endl;
        cout << "# 2 - Dikstra" << endl << endl;
        
        char handler;
        
        cin >> handler;
        cin.get();
        
        camadas.CalcM();
	    camadas.CalcEspessT();
        
        bool tes = false;
        
        do
		{

        switch (handler){

	    case '1':    
		{
	
	        vector<double> vazao;
	        vazao = stiles.VazaoInjecao(reservatorio.GetKrw(), camadas.GetMw(), camadas.GetLargura(), camadas.GetDp(), camadas.GetK(), camadas.GetBw(), camadas.GetComprimento(), camadas.GetEspec());
	        
	        vector<double> perm = camadas.GetK();
	        
	        for (int i = 0 ; i< vazao.size() ; i++)
			{
	            cout <<"Vazao Stiles = " << vazao[i] << "\tPermeabilidade = " << perm[i]<<endl;
			}
	        cout << endl;
	
	        stiles.VazaoTotal();
	        double vazaototal;
	        vazaototal = stiles.GetVazaoTotal();
	
	        cout << "Vazao total = " << vazaototal <<endl;
	
	        cout << endl;
			
			vector<double> posicao;
	        posicao = stiles.PosicaoAguaInjetada(camadas.GetK(), camadas.GetLargura());  
	
	        for (double item: posicao)
	            cout <<"Posicao frente de avanço de agua = " << item <<endl;   
	
	        cout << endl;
	
	        double eff;
	        vector<double> effVet;
	
	        effVet = stiles.EfVert(stiles.GetPosicao(), camadas.GetEspec(), camadas.GetLargura(), camadas.GetEspessuraTotal());
	        stiles.EfVertTotal();
	        eff = stiles.GetEfVertTotal();
	
	        for (double item: effVet)
	            cout <<"Eficiencia vertical = " << item <<endl;
	
	        cout << endl;
	        cout << "Eficiencia vertical total = " << eff << endl;
	
	        double oleoProduzidoTotal;
	        oleo.OleoProduzido(camadas.GetLargura(), camadas.GetComprimento(), reservatorio.GetPHI(), camadas.GetEspessuraTotal(), reservatorio.GetSor(), reservatorio.GetSwi(), stiles.GetEfVertTotal(), camadas.GetBo());
	        oleoProduzidoTotal = oleo.getNp();
	
	        cout << endl;
	        cout << "Np = " << oleoProduzidoTotal << endl;
	
	        double Bt;
	        oleo.TempoBreakThrough(stiles.GetVazaoTotal());
	        Bt = oleo.getTbreak();
	
	        cout << endl;
	        cout << "O tempo de break through foi : " << Bt << endl;
			
			bool ecpot = false;
			
			do
			{		
				
				cout << "\nGostaria de exibir os graficos de linhas equipotenciais? (1 - sim, 2 - nao)" << endl;
				
				char d;
				cin >> d;
				cin.get();
				
				if(d == '1')
				{
					cout << "Aperte ENTER para continuar com carregamento de dados..." << endl;
	        		cin.get();
	        		
					EntradaDadosPoco();
					
					double kb = kbarra(perm, camadas.GetEspec());
					
					cout << "# Qual configuracao de pocos deseja calcular?" << endl;
					cout << "# 1 - 1 poco produtor e 1 injetor" << endl;
					cout << "# 2 - 2 pocos injetores e 1 produtor" << endl;
					cout << "# 3 - 1 poco injetor e 2 produtores" << endl << endl;
					
					char ans;
					bool ans1 = false;
					cin >> ans;
					cin.get();
					
					do{
					switch(ans){
						case '1':
							{
								ans1 = true;
								double _r1 = r1(poco.getC(), poco.getX(),poco.getY());
								double _r2 = r2(poco.getC(), poco.getX(),poco.getY());
								linhas = new CLinhaPressao2Pocos(_r1, _r2, 0.0);
								printResults(poco.getX(), poco.getY(), poco.getC(), stiles.GetVazaoTotal(), camadas.GetMo(), kb, camadas.GetEspessuraTotal(), poco.getPi());
								cout << " R = " << linhas->R(poco.getC()) << " C = " << poco.getC() << endl;
								xplot = linhas->CalculoDoVetorX(linhas->R(poco.getC()), poco.getC());
								yplot = linhas->CalculoDoVetorY(linhas->R(poco.getC()), poco.getC());
								
								Gnuplot::Terminal("qt");
						        plot.set_style("lines");
						        plot.Title("Curvas equipotenciais.");
						        plot.unset_legend();
						        plot.set_xlabel(" ");
						        plot.set_ylabel(" ");
						        plot.ShowOnScreen();
						        plot.Grid();
						        plot.PlotVector(xplot, yplot);
						        cin.get();
						
						        plot.savetops("dois_pocos_stiles");
						
						         
								
								break;
							}
						case '2':
							{
								
								ans1 = true;
								double _r1 = r1(poco.getC(), poco.getX(),poco.getY());
								double _r2 = r2(poco.getC(), poco.getX(),poco.getY());
								double _r3 = r3(poco.getX(), poco.getY());
								linhas = new CLinhaPressao3Pocos1P2I(_r1, _r2, _r3);
								printResults(poco.getX(), poco.getY(), poco.getC(), stiles.GetVazaoTotal(), camadas.GetMo(), kb, camadas.GetEspessuraTotal(), poco.getPi());
								cout << " R = " << linhas->R(poco.getC()) << " C = " << poco.getC() << endl;
								xplot = linhas->CalculoDoVetorX(linhas->R(poco.getC()), poco.getC());
								yplot = linhas->CalculoDoVetorY(linhas->R(poco.getC()), poco.getC());
								
								Gnuplot::Terminal("qt");
						        plot1.set_style("lines");
						        plot1.Title("Curvas equipotenciais.");
						        plot1.unset_legend();
						        plot1.set_xlabel(" ");
						        plot1.set_ylabel(" ");
						        plot1.ShowOnScreen();
						        plot1.Grid();
						        plot1.PlotVector(xplot, yplot);
						        cin.get();
						
						        plot1.savetops("dois-pocos-injetores-um-poco-produtor-stiles");
						
						        
								break;
							}
						case '3':
							{
								
								ans1 = true;
								double _r1 = r1(poco.getC(), poco.getX(),poco.getY());
								double _r2 = r2(poco.getC(), poco.getX(),poco.getY());
								double _r3 = r3(poco.getX(), poco.getY());
								linhas = new CLinhaPressao3Pocos2P1I(_r1, _r2, _r3);
								printResults(poco.getX(), poco.getY(), poco.getC(), stiles.GetVazaoTotal(), camadas.GetMo(), kb, camadas.GetEspessuraTotal(), poco.getPi());
								cout << " R = " << linhas->R(poco.getC()) << " C = " << poco.getC() << endl;
								xplot = linhas->CalculoDoVetorX(linhas->R(poco.getC()), poco.getC());
								yplot = linhas->CalculoDoVetorY(linhas->R(poco.getC()), poco.getC());
								
								Gnuplot::Terminal("qt");
						        plot2.set_style("lines");
						        plot2.Title("Curvas equipotenciais.");
						        plot2.unset_legend();
						        plot2.set_xlabel(" ");
						        plot2.set_ylabel(" ");
						        plot2.ShowOnScreen();
						        plot2.Grid();
						        plot2.PlotVector(xplot, yplot);
						        cin.get();
						
						        plot2.savetops("um-poco-injetor-dois-pocos-produtores-stiles");
						
						        
								break;
							}
						default:
							cout << "Opcao invalidade!!!" << endl << endl;		
							cout << "# Qual configuração de pocos deseja calcular?" << endl;
							cout << "# 1 - 1 poco produtor e 1 injetor" << endl;
							cout << "# 2 - 2 pocos injetores e 1 produtor" << endl;
							cout << "# 3 - 1 poco injetor e 2 produtores" << endl << endl;
							cin >> ans;
							cin.get();
					}
					}while(!ans1);
					  
					ecpot = true;
				}else if( d =='2'){
					ecpot = true;
				}else {
					cout << "opcao invalida!!!" << endl;
				}
					
			}while(!ecpot);
			tes = true;
	        break;
    	}
        case '2':
        {	
        
        	vector<double> vazao;
	        vazao = dykstra.VazaoInjecao(reservatorio.GetKrw(), camadas.GetMw(), camadas.GetLargura(), camadas.GetDp(), camadas.GetK(), camadas.GetBw(), camadas.GetComprimento(), camadas.GetEspec(), reservatorio.GetM());
	        
	        vector<double> perm = camadas.GetK();
	        
	        for (int i = 0 ; i< vazao.size() ; i++)
			{
	            cout <<"Vazao Dykstra = " << vazao[i] << "\tPermeabilidade = " << perm[i]<<endl;
			}
	        cout << endl;
	
	        dykstra.VazaoTotal();
	        double vazaototal;
	        vazaototal = dykstra.GetVazaoTotal();
	
	        cout << "Vazao total = " << vazaototal <<endl;
	
	        cout << endl;
			
			vector<double> posicao;
	        posicao = dykstra.PosicaoAguaInjetada(camadas.GetK(), camadas.GetLargura(), reservatorio.GetM());  
	
	        for (double item: posicao)
	            cout <<"Posicao frente de avanço de agua = " << item <<endl;   
	
	        cout << endl;
	
	        double eff;
	        vector<double> effVet;
	
	        effVet = dykstra.EfVert(dykstra.GetPosicao(), camadas.GetEspec(), camadas.GetLargura(), camadas.GetEspessuraTotal());
	        dykstra.EfVertTotal();
	        eff = dykstra.GetEfVertTotal();
	
	        for (double item: effVet)
	            cout <<"Eficiencia vertical = " << item <<endl;
	
	        cout << endl;
	        cout << "Eficiencia vertical total = " << eff << endl;
	
	        double oleoProduzidoTotal;
	        oleo.OleoProduzido(camadas.GetLargura(), camadas.GetComprimento(), reservatorio.GetPHI(), camadas.GetEspessuraTotal(), reservatorio.GetSor(), reservatorio.GetSwi(), dykstra.GetEfVertTotal(), camadas.GetBo());
	        oleoProduzidoTotal = oleo.getNp();
	
	        cout << endl;
	        cout << "Np = " << oleoProduzidoTotal << endl;
	
	        double Bt;
	        oleo.TempoBreakThrough(dykstra.GetVazaoTotal());
	        Bt = oleo.getTbreak();
	
	        cout << endl;
	        cout << "O tempo de break through foi : " << Bt << endl; 
	        
	        bool ecpot = false;
			
			do
			{		
				
				cout << "\nGostaria de exibir os graficos de linhas equipotenciais? (1 - sim, 2 - nao)" << endl;
				
				char d;
				cin >> d;
				cin.get();
				
				if(d == '1')
				{
					cout << "Aperte ENTER para continuar com carregamento de dados..." << endl;
	        		cin.get();
	        		
					EntradaDadosPoco();
					
					double kb = kbarra(perm, camadas.GetEspec());
					
					cout << "# Qual configuracao de pocos deseja calcular?" << endl;
					cout << "# 1 - 1 poco produtor e 1 injetor" << endl;
					cout << "# 2 - 2 pocos injetores e 1 produtor" << endl;
					cout << "# 3 - 1 poco injetor e 2 produtores" << endl << endl;
					
					char ans;
					bool ans1 = false;
					cin >> ans;
					cin.get();
					
					do{
					switch(ans){
						case '1':
							{
								ans1 = true;
								double _r1 = r1(poco.getC(), poco.getX(),poco.getY());
								double _r2 = r2(poco.getC(), poco.getX(),poco.getY());
								linhas = new CLinhaPressao2Pocos(_r1, _r2, 0.0);
								printResults(poco.getX(), poco.getY(), poco.getC(), dykstra.GetVazaoTotal(), camadas.GetMo(), kb, camadas.GetEspessuraTotal(), poco.getPi());
								cout << " R = " << linhas->R(poco.getC()) << " C = " << poco.getC() << endl;
								xplot = linhas->CalculoDoVetorX(linhas->R(poco.getC()), poco.getC());
								yplot = linhas->CalculoDoVetorY(linhas->R(poco.getC()), poco.getC());
								
								Gnuplot::Terminal("qt");
						        plot.set_style("lines");
						        plot.Title("Curvas equipotenciais.");
						        plot.unset_legend();
						        plot.set_xlabel(" ");
						        plot.set_ylabel(" ");
						        plot.ShowOnScreen();
						        plot.Grid();
						        plot.PlotVector(xplot, yplot);
						        cin.get();
						
						        plot.savetops("dois-pocos-dykstra");
								
								break;
							}
						case '2':
							{
								
								ans1 = true;
								double _r1 = r1(poco.getC(), poco.getX(),poco.getY());
								double _r2 = r2(poco.getC(), poco.getX(),poco.getY());
								double _r3 = r3(poco.getX(), poco.getY());
								linhas = new CLinhaPressao3Pocos1P2I(_r1, _r2, _r3);
								printResults(poco.getX(), poco.getY(), poco.getC(), dykstra.GetVazaoTotal(), camadas.GetMo(), kb, camadas.GetEspessuraTotal(), poco.getPi());
								cout << " R = " << linhas->R(poco.getC()) << " C = " << poco.getC() << endl;
								xplot = linhas->CalculoDoVetorX(linhas->R(poco.getC()), poco.getC());
								yplot = linhas->CalculoDoVetorY(linhas->R(poco.getC()), poco.getC());
								
								Gnuplot::Terminal("qt");
						        plot1.set_style("lines");
						        plot1.Title("Curvas equipotenciais.");
						        plot1.unset_legend();
						        plot1.set_xlabel(" ");
						        plot1.set_ylabel(" ");
						        plot1.ShowOnScreen();
						        plot1.Grid();
						        plot1.PlotVector(xplot, yplot);
						        cin.get();
						
						        plot1.savetops("dois-pocos-injetores-um-poco-produtor-dykstra");

								break;
							}
						case '3':
							{
								
								ans1 = true;
								double _r1 = r1(poco.getC(), poco.getX(),poco.getY());
								double _r2 = r2(poco.getC(), poco.getX(),poco.getY());
								double _r3 = r3(poco.getX(), poco.getY());
								linhas = new CLinhaPressao3Pocos2P1I(_r1, _r2, _r3);
								printResults(poco.getX(), poco.getY(), poco.getC(), dykstra.GetVazaoTotal(), camadas.GetMo(), kb, camadas.GetEspessuraTotal(), poco.getPi());
								cout << " R = " << linhas->R(poco.getC()) << " C = " << poco.getC() << endl;
								xplot = linhas->CalculoDoVetorX(linhas->R(poco.getC()), poco.getC());
								yplot = linhas->CalculoDoVetorY(linhas->R(poco.getC()), poco.getC());
								
								Gnuplot::Terminal("qt");
						        plot2.set_style("lines");
						        plot2.Title("Curvas equipotenciais.");
						        plot2.unset_legend();
						        plot2.set_xlabel(" ");
						        plot2.set_ylabel(" ");
						        plot2.ShowOnScreen();
						        plot2.Grid();
						        plot2.PlotVector(xplot, yplot);
						        cin.get();
						
						        plot2.savetops("um-poco-injetor-dois-pocos-produtores-dykstra");

								break;
							}
						default:
							cout << "Opcao invalidade!!!" << endl << endl;		
							cout << "# Qual configuração de pocos deseja calcular?" << endl;
							cout << "# 1 - 1 poco produtor e 1 injetor" << endl;
							cout << "# 2 - 2 pocos injetores e 1 produtor" << endl;
							cout << "# 3 - 1 poco injetor e 2 produtores" << endl << endl;
							cin >> ans;
							cin.get();
					}
					}while(!ans1);
					  
					ecpot = true;
				}else if( d =='2'){
					ecpot = true;
				}else {
					cout << "opcao invalida!!!" << endl;
				}
					
			}while(!ecpot);
			
			tes = true;
			break;
		}
		default:
			{
				cout << "Opcao invalida!!" << endl << endl;
				cout << "# qual metodo deseja utilizar?" << endl << endl;
		        cout << "# 1 - Stiles" << endl;
		        cout << "# 2 - Dikstra" << endl << endl;
		        
		        cin >> handler;
		        cin.get();
		        
			}
		}
		}while(!tes);
		
		corey.setK0rw(reservatorio.GetKrw());
		corey.setK0ro(reservatorio.GetKro());
		corey.setNo(2.0);
		corey.setNw(2.0);
		
		corey.calcSwn(reservatorio.GetSwi(), reservatorio.GetSor());
		corey.calcKro(corey.getSw());
		corey.calcKrw(corey.getSw());
		
		cout << "# Gostaria de plotar os graficos de permeabilidade relativa de corey-brooks?" << endl;
		cout << "# 1 - sim, 2 - nao " << endl << endl;
		
		char e;
		
		cin >> e;
		cin.get();
		
		bool tes1 = false;
		
		do
		{
			
			if (e == '1'){
								
				vector<double> _sw, _krw, _kro;
				
				_sw = corey.getSw();
				_krw = corey.getKrw();
				_kro = corey.getKro(); 
				
				Gnuplot::Terminal("qt");
				plot3.set_style("lines");
				plot3.Title("Modelo de permeabilidade relativa de Corey-Brooks.");
				plot3.set_legend("inside center top box");
				plot3.set_xlabel("Swn(saturação normalizada)");
				plot3.set_ylabel("Kr");
				plot3.ShowOnScreen();
				plot3.Grid();
				plot3.PlotVector(_sw, _krw, "Krw");
				plot3.set_style("points");
				plot3.PlotVector(_sw, _kro, "Kro");
				
				cin.get();
						
				plot3.savetops("Permeabilidade-relativa-Corey-Brooks");
				
				tes1 = true;
			}else
			if(e == '2'){
				tes1 = true;
			} else{
				cout << "Opcao invalida!!!" << endl << endl;
				cout << "# Gostaria de plotar os graficos de permeabilidade relativa de corey-brooks?" << endl;
				cout << "# 1 - sim, 2 - nao " << endl << endl;
				
				cin >> e;
				cin.get();
				
			}
			
		}while(!tes1);
		
		cout << "# Gostaria de plotar as curvas de fluxo fracionario?" << endl;
		cout << "# 1 - sim, 2 - nao " << endl << endl;
		
		char f;
		
		cin >> f;
		cin.get();
		
		bool tes2 = false;
		
		do
		{
			
			if (f == '1'){
								
				fluxofracionario.calcFluxoFracionarioAgua(corey.getKrw(), corey.getKro(), camadas.GetMw(), camadas.GetMo());
				fluxofracionario.calcFluxoFracionarioOleo(corey.getKrw(), corey.getKro(), camadas.GetMw(), camadas.GetMo());
				
				vector<double> _fro, _frw, _sw;
				
				_sw = corey.getSw();
				_fro = fluxofracionario.getFluxoFracionarioOleo();
				_frw = fluxofracionario.getFluxoFracionarioAgua();
				
				Gnuplot::Terminal("qt");
				plot4.set_style("lines");
				plot4.Title("Fluxo fracionario de agua.");
				plot4.set_legend("inside center top box");
				plot4.set_xlabel("Swn(saturação normalizada)");
				plot4.set_ylabel("Frw");
				plot4.ShowOnScreen();
				plot4.Grid();
				plot4.PlotVector(_sw, _frw, "Krw");
				cin.get();
						
				plot4.savetops("Fluxo_fracionario_de_agua");
				
				Gnuplot::Terminal("qt");
				plot5.set_style("lines");
				plot5.Title("Fluxo fracionario de oleo");
				plot5.set_legend("inside center top box");
				plot5.set_xlabel("Swn(saturação normalizada)");
				plot5.set_ylabel("Fro");
				plot5.ShowOnScreen();
				plot5.Grid();
				plot5.PlotVector(_sw, _fro, "Kro");
				cin.get();
						
				plot5.savetops("Fluxo-fracionario-de-oleo");
				
				
				tes2 = true;
			}else
			if(f == '2'){
				tes2 = true;
			} else{
				cout << "Opcao invalida!!!" << endl << endl;
				cout << "# Gostaria de plotar os graficos de permeabilidade relativa de corey-brooks?" << endl;
				cout << "# 1 - sim, 2 - nao " << endl << endl;
				
				cin >> e;
				cin.get();
				
			}
			
		}while(!tes2);		
		
        } else if(c == '2'){
            cout << endl;
            cout << "Codigo encerrado!! " << endl << endl;
            rodar = false;
            teste = true;
        } else {
            cout << endl;
            cout << "Opcao invalida!" << endl;            
        }
        } while (rodar);           

    }
    
    
}

void CSolverInfluxo::EntradaDadosRochaReservatorio(){
    
    cout << endl;
    cout << "#################################################" << endl;
    cout << "#          Arquivos de dados da rocha           #" << endl;
    cout << "#################################################" << endl << endl;

    string path = "./in";
    for (const auto & entry : filesystem::directory_iterator(path))
    cout << "# \t" << entry.path() << std::endl;

    cout << endl;

    bool sucess = false;

    do
    {

    cout << "Entre com nome do arquivo com dados da rocha reservatorio: ";
    string tmp;

    getline(cin, tmp);
    cout << endl;
    ifstream in;

    in.open(".\\in\\"+tmp);

    double  Kro, Krw, Sor, phi, swi;

    in >> Kro >> Krw >> Sor >> phi >> swi;

    cout << "Kro = " << Kro << " Krw = " << Krw << " Sor = " << Sor << " phi = " << phi << " swi = " << swi << endl; 

    cout << endl;

    bool test = false;

    while(!test)
    {
    char t;
    cout << "O carregamento foi correto? (1 - sim , 2- nao): ";
    cin >> t;
    cin.get();

    if (t == '1')
    {
        test = true;
        sucess = true;
        
        reservatorio.SetKro(Kro);
        reservatorio.SetKrw(Krw);
        reservatorio.SetSor(Sor);
        reservatorio.SetPHI(phi);
        reservatorio.SetSwi(swi);


        cout << endl << endl;

        cout << "##############################"<< endl;
        cout << "#      Dados salvos!         #"<< endl;
        cout << "##############################"<< endl << endl;


    } else
         {
            if (t == '2')
                test = true;
            else
                cout << "valor invalido!!" << endl; 
        }
    }

    cout << endl;

    in.close();

    } while (!sucess);
}

void CSolverInfluxo::EntradaDadosReservatorio()
{

    cout << endl;
    cout << "#################################################" << endl;
    cout << "#      Arquivos de dados do reservatorio        #" << endl;
    cout << "#################################################" << endl << endl;

    string path = "./in";
    for (const auto & entry : filesystem::directory_iterator(path))
    cout << "# \t" << entry.path() << std::endl;

    cout << endl;

    bool sucess = false;

    do
    {

    cout << "Entre com nome do arquivo com dados do reservatorio: ";
    string tmp;

    getline(cin, tmp);
    cout << endl;
    ifstream in;

    in.open(".\\in\\"+tmp);

    double  L, C, Bo, Bw, Dp, Mo, Mw, Sg, M;

    in >> L >> C >> Bo >> Bw >> Dp >> Mo >> Mw >> Sg  >> M  ;

    cout << "Largura = " << L << " Comprimento = " << C << " Bo = " << Bo << " Bw = " << Bw << " deltaP = " << Dp << " Mi_o = " << Mo << " Mi_w = " << Mw << " Sg = " << Sg << " M = " << M << endl; 

    cout << endl;

    bool test = false;

    while(!test)
    {
    char t;
    cout << "O carregamento foi correto? (1 - sim , 2- nao): ";
    cin >> t;
    cin.get();

    if (t == '1')
    {
        test = true;
        sucess = true;
        
        camadas.SetLargura(L);
        camadas.SetComprimento(C);
        camadas.SetBo(Bo);
        camadas.SetBw(Bw);
        camadas.SetDp(Dp);
        camadas.SetMo(Mo);
        camadas.SetMw(Mw);
        camadas.SetSg(Sg);
        reservatorio.SetM(M);


        cout << endl << endl;

        cout << "##############################"<< endl;
        cout << "#      Dados salvos!         #"<< endl;
        cout << "##############################"<< endl << endl;


    } else
         {
            if (t == '2')
                test = true;
            else
                cout << "valor invalido!!" << endl; 
        }
    }

    cout << endl;

    in.close();

    } while (!sucess);

}

void CSolverInfluxo::EntradaDadosCamadas()
{

    cout << endl;
    cout << "#################################################" << endl;
    cout << "#        Arquivos de entradas de dados          #" << endl;
    cout << "#################################################" << endl << endl;

    string path = "./in";
    for (const auto & entry : filesystem::directory_iterator(path))
    cout << "# \t" << entry.path() << std::endl;

    cout << endl;

    bool sucess = false;

    do
    {

    cout << "Entre com nome do arquivo com dados da camada: ";
    string tmp;

    getline(cin, tmp);
    cout << endl;
    ifstream in;

    in.open(".\\in\\"+tmp);

    double inK, inH;
    vector<double> K, H;
        
    while(!in.eof())
    {
        char c = in.peek();
        if (c == '#' || c == '\n') {
            in.ignore(256, '\n');
            continue;
        } 

        in >> inK >> inH;
        cout <<" Permeabilidade: " << inK << " Espessura: " << inH << endl;
        K.push_back(inK);
        H.push_back(inH);
    }

    cout << endl;

    bool test = false;

    while(!test)
    {
    char t;
    cout << "O carregamento foi correto? (1 - sim , 2- nao): ";
    cin >> t;
    cin.get();

    if (t == '1')
    {
        test = true;
        sucess = true;

        camadas.SetK(K);
        camadas.SetEspec(H);

        cout << endl << endl;

        cout << "##############################"<< endl;
        cout << "#      Dados salvos!         #"<< endl;
        cout << "##############################"<< endl << endl;


    } else
         {
            if (t == '2')
                test = true;
            else
                cout << "valor invalido!!" << endl; 
        }
    }

    cout << endl;

    in.close();

    } while (!sucess);
    
}

void CSolverInfluxo::EntradaDadosPoco()
{

    cout << endl;
    cout << "#################################################" << endl;
    cout << "#           Arquivos de dados do poco           #" << endl;
    cout << "#################################################" << endl << endl;

    string path = "./poco";
    for (const auto & entry : filesystem::directory_iterator(path))
    cout << "# \t" << entry.path() << std::endl;

    cout << endl;

    bool sucess = false;

    do
    {

    cout << "Entre com nome do arquivo com dados do poco: ";
    string tmp;

    getline(cin, tmp);
    cout << endl;
    ifstream in;

    in.open(".\\poco\\"+tmp);

    double  X, Y, C, Pi;

    in >> X >> Y >> C >> Pi;

    cout << "X = " << X << " Y = " << Y << " C = " << C << " Pi = " << Pi << endl; 

    cout << endl;

    bool test = false;

    while(!test)
    {
    char t;
    cout << "O carregamento foi correto? (1 - sim , 2- nao): ";
    cin >> t;
    cin.get();

    if (t == '1')
    {
        test = true;
        sucess = true;
        
        poco.setX(X);
        poco.setY(Y);
        poco.setC(C);
        poco.setPi(Pi);


        cout << endl << endl;

        cout << "##############################"<< endl;
        cout << "#      Dados salvos!         #"<< endl;
        cout << "##############################"<< endl << endl;


    } else
         {
            if (t == '2')
                test = true;
            else
                cout << "valor invalido!!" << endl; 
        }
    }

    cout << endl;

    in.close();

    } while (!sucess);
    
}

double CSolverInfluxo::kbarra(vector<double> k, vector<double> h){
	
	double kh = 0;
	double sumh = 0;
	
	for (int i = 0; i<k.size(); i++){
		kh += k[i]*h[i];
		sumh += h[i];
	}
	
	return kh/sumh;
	
}

void CSolverInfluxo::printResults(double _x, double _y, double _c, double _q, double _mi, double _kbarra, double _h, double _pi) {
	cout << "AREA INVADIDA  PELA AGUA NO INSTANTE DO BREAKTHROUGH = " << linhas->AreaInvadidaBT(_c) << "\n";
	cout << "P(" << _x << "," << _y << ")=" << linhas->Pressao(_q, _mi, _kbarra, _h, _pi) << endl;
}

double CSolverInfluxo::r1(double _c, double x, double y) {
	return sqrt((_c - x) * (_c - x) + y * y);
}

double CSolverInfluxo::r2(double _c, double x, double y) {
	return sqrt((_c + x) * (_c + x) + y * y);
}

double CSolverInfluxo::r3(double x, double y) {
	return sqrt(x * x + y * y);
}
