#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <conio.h>
#include <windows.h>

using namespace std;

#include "struct.cpp"
#include "functii.cpp"
#include "ai.cpp"
#include "ui.cpp"

int main()
{ srand( time(0) );

	// 1. Aplicatia permite intrare doar prin autentificare ( STRUCT utilizator, parola, email )
	// 1.1 minimum 10 user
	// 1.2 meniu - management USER
	
	// 2. Baza de date STUDENT 
	
	// 3. Rapoarte
	// 3.1 Lista total studenti
	// 3.2 Lista studenti dupa o medie
	
	/// Dare de seama SISTEMUL INFORMATIONAL
	// Foaie de titlu
	// cuprins
	// codul sursa
	// screen shot
	// concluzia

	fp = fopen("config.ini","r+");
	fscanf(fp,"%s%s%s",&STUDfile,&USERfile,&COLOR);
	fclose(fp);
	
	strcpy(script_color,"color ");
	strcat(script_color,COLOR);
	
	
	
	s = new STUD[1000];
	
	N = new int;
	M = new int;
	
	int l = loadSECURITY();
	int lgx;
	int q=0;
	int SYSTEM;
	int TIP;
	
	*N = 0;
	*M = 0;
	
	load(STUDfile,s,N);
	loadUSERS(U,M);

X:	
	lgx=0;
	system(script_color);
	a = auth(U,M);
	
	while( 1 )
	{
		if((a != -1) && (U[a].status != 0))
		{
			l=1;
			saveSECURITY(l);
			TIP = U[a].tip;
			
			if(lgx==0)
			{
				setConsoleColor(2);
		    	cout<<"Logarea a avut succes. Bine ati revenit, "<<U[a].nume<<". In scurt timp va redirectionam la meniul principal."<<endl;  setConsoleColor(7); 
	   			Sleep(2000); lgx++;
			}
			
			switch( TIP )
			{
				case 1 : SYSTEM = managementADMIN(); break;
				case 0 : SYSTEM = managementUSER(); break;
			}
			
			
			switch( SYSTEM )
			{
				case 1 : insertSTUD(s,N); save(STUDfile,s,N); break; // +
				case 2 : showSTUD(s,N); break; // +
				case 31 : editSTUDnume(s,N); save(STUDfile,s,N); break; // +
				case 32 : editSTUDprenume(s,N); save(STUDfile,s,N); break; // +
				case 33 : editSTUDvarsta(s,N); save(STUDfile,s,N); break; // +
				case 34 : editSTUDactive(s,N); save(STUDfile,s,N); break; // +
				case 41 : findSTUDnume(s,N); break; // +
				case 42 : findSTUDprenume(s,N); break; // +
				case 43 : findSTUDid(s,N); break; // +
				case 53 : save(STUDfile,s,N); break; // +
				case 61 : raportSTUDall(s,N); break; // -
				case 62 : raportSTUDmedia(s,N); break; // -
				case 101 : insertUSER(U,M); saveUSERS(U,M); break;
				case 102 : showUSERS(U,M); break;
				case 103 : findUSER(U,M); break;
				case 104 : saveUSERS(U,M); break;
				case 105 : editUSERnume(U,M); break;
				case 106 : editUSERparola(U,M); break;
				case 107 : editUSERtip(U,M); break;
				case 108 : editUSERstatus(U,M); break;
				
				case 27 : goto X; break; // +
			}	
			cout<<endl;
		}
		else if(a == -1)
		{
			if((l != 5) && (l != 10) && (l != 15)) 
			{
				setConsoleColor(4);
				cout<<"Parola sau username gresit"<<endl;
				l+=1;
				setConsoleColor(7);
				saveSECURITY(l);
				system("pause");
				goto X;
			}
			else if(l == 5)
			{
				q = 0;
				while(q<10)
				{
					system("cls");
					cout<<"Ati introdus parola gresit de 5 ori. Sistema este blocata pe 10 secunde"<<endl;
					cout<<"Au mai ramas "<<10-q<<" secunde";
					Sleep(1000);
					q++;
				}
				system("cls");
				cout<<"Sistema este deblocata"<<endl;
				Sleep(1000);
				l+=1;
				saveSECURITY(l);
				goto X;
			}
			else if(l == 10)
			{
				q = 0;
				while(q<20)
				{
					system("cls");
					cout<<"Ati introdus parola gresit de 10 ori. Sistema este blocata pe 20 secunde"<<endl;
					cout<<"Au mai ramas "<<20-q<<" secunde";
					Sleep(1000);
					q++;
				}
				system("cls");
				cout<<"Sistema este deblocata"<<endl;
				Sleep(1000);
				l+=1;
				saveSECURITY(l);
				goto X;
			}
			else if(l == 15)
			{
				q = 0;
				while(q<5)
				{
					system("cls");
					cout<<"Ati introdus parola gresit de 15 ori. Sistema se va autodistruge in 5 secunde"<<endl;
					cout<<"Au mai ramas "<<5-q<<" secunde";
					Sleep(1000);
					q++;
				}
				system("cls");
				setConsoleColor(4);
				cout<<"SISTEMA DISTRUSA !"<<endl;
				setConsoleColor(7);
				Sleep(1000);
				l=1;
				saveSECURITY(l);
				exit(0);
			}
		}
		else if(U[a].status == 0)
		{
			cout<<"Ne pare rau, account-ul dv. a fost dezactivat"<<endl;
			l=1;
			saveSECURITY(l);
			system("pause");
			goto X;
		}
	}
	
	return 0;
}
