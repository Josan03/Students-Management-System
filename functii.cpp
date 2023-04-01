void setConsoleColor(WORD c) 
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void findUSER(USERS *S, int *n)
{
	system("cls");
	if( *n == 0 ) cout<<" Nu sunt date pentru afisare "<<endl;
	else
	{
		char nume[256];
		bool k=true;
		cout<<" Enter nume = ";
		cin>>nume;
		cout<<endl; 
		cout<<setw(5)<<"ID"<<setw(15)<<"NUME"<<setw(15)<<"PASSWORD"<<setw(15)<<"TIP"<<endl;
		cout<<"\n";
		for(int i=0 ; i < *n ; i++)
		{   
			if(strcmp(S[i].nume,nume) == 0)
			{
				k=false; 
				cout<<setw(5)<<S[i].id<<setw(15)<<S[i].nume<<setw(15)<<S[i].password<<setw(15)<<S[i].tip<<endl;
				cout<<"------------------------------------------"<<endl; 
			} 
		}// for
		if(k) cout<<" Nu s-a gasit nici un nume ["<<nume<<"] "<<endl;
	}// else
	system("pause");
}



void showUSERS(USERS *S, int*n)
{
	int pp=3;
	int in=0, sf=pp;
	system("cls");
	
	while(1) 
	{
		system("cls");
		cout<<endl; 
		cout<<setw(5)<<"ID"<<setw(15)<<"NUME"<<setw(15)<<"PASSWORD"<<setw(15)<<"TIP"<<setw(15)<<"STATUS"<<endl;
		cout<<"\n";
	
		for(int i=in; i < sf ; i++)
		{   
			cout<<setw(5)<<S[i].id<<setw(15)<<S[i].nume<<setw(15)<<S[i].password<<setw(15)<<S[i].tip<<setw(13)<<S[i].status<<endl;
			cout<<"-------------------------------------------------------------------"<<endl;
		}
		switch(_getch())
		{
			case 43: /*+*/  in+=pp; sf+=pp; if( sf >= *n){ in = *n-pp; sf = *n; }   break;
			case 45: /*-*/  in-=pp; sf-=pp; if( in < 0 ){ in = 0; sf = pp; }        break;
			case 27: /*ESC*/ return ;
		}
	}   
	system("pause");
}
	

void insertUSER(USERS *S, int *n)
{
  G:
	system("cls");
	
	cout<<" INSERT USER "<<endl;
	
	do
	{
		system("cls");
		cout<<" User NR( ID ). "<<*n+1<<endl;
		
		cout<<" Enter nume = ";
		cin>>S[*n].nume;
		int i=0; bool ok=true;
		do
		{
			if((strcmp(S[*n].nume,S[i].nume) == 0) && i!=*n) { ok=false; }
			i++;
		} while (i<*n);
		
		if (ok==false)
		{
			cout<<"Acest nume exista deja, incercati alt nume"<<endl;
			system("pause"); 
			goto G;
		}
		
		cout<<" Password =";
		cin>>S[*n].password;
		cout<<" Tip =";
		cin>>S[*n].tip;
		S[*n].id = *n+1;
		S[*n].status = 1;
		*n+=1; 
		cout<<"\n [ESC] - for exit    OR   [ANY key] -  for continue"<<endl;
	} while(_getch()!=27);
	
	system("pause");
}

void editUSERnume(USERS *S, int *n)
{
	system("cls");
	int i,x; 
	char aux[100];
	cout<<" Edit USER Nume "<<endl;
	cout<<" Introduceti ID-ul User-ului: ";
	cin>>x;
	strcpy(aux,S[x-1].nume);
	if (x<=*n)
	{ L:
		cout<<" Introduceti numele nou al User-ului: ";
		cin>>S[x-1].nume;
		i=0; bool ok=true;
		do
		{
			if((strcmp(S[x-1].nume,S[i].nume) == 0) && (x-1!=i)) ok=false;
			i++;
		} while (i<*n);
		
		if (ok==false)
		{
			cout<<"Acest nume exista deja, incercati alt nume"<<endl;
			system("pause");
			system("cls");
			goto L;
		} 
		else
		{
			cout<<"Nume schimbat cu succes"<<endl;
		}
	}
	else
	{
		cout<<"Acest ID nu exista"<<endl;
	}
	
	system("pause");
}


void editUSERparola(USERS *S, int *n)
{
	system("cls");
	
	int i,x; 
	cout<<" Edit USER Password "<<endl;
	cout<<" Introduceti ID-ul User-ului: "; cin>>x;
	if (x<=*n)
	{   
		cout<<" Introduceti parola noua a User-ului: ";
		cin>>S[x-1].password;
		cout<<"Parola schimbata cu succes"<<endl; 
	}
	else
	{
		cout<<"Acest ID nu exista"<<endl;
	}
	
	system("pause");
}


void editUSERtip(USERS *S, int *n)
{
	system("cls");
	
	int i,x; 
	cout<<" Edit USER TIP "<<endl;
	cout<<" Introduceti ID-ul User-ului: "; cin>>x;
	if (x<=*n)
	{   
		cout<<" Introduceti noul TIP al User-ului: ";
		cin>>S[x-1].tip;
		cout<<"TIP schimbat cu succes"<<endl;  
	}
	else
	{
		cout<<"Acest ID nu exista"<<endl;
	}
	
	system("pause");
}

void editUSERstatus(USERS *S, int *n)
{
	system("cls");
	
	int i,x; 
	cout<<" Edit USER STATUS "<<endl;
	cout<<" Introduceti ID-ul User-ului: "; cin>>x;
	if (x<=*n)
	{   
		cout<<" Introduceti noul STATUS al User-ului: ";
		cin>>S[x-1].status;
		cout<<"STATUS schimbat cu succes"<<endl;  
	}
	else
	{
		cout<<"Acest ID nu exista"<<endl;
	}
	
	system("pause");
}


void insertSTUD(STUD *S, int *n)
{  
	cout<<" INSERT STUDENT "<<endl;
  
	do
	{
    	system("cls");  
   		cout<<" Student NR( ID ). "<<*n+1<<endl;
   		S[*n].id = *n+1;
		cout<<" Nume = ";
		cin>>S[*n].NPP.nume;
		cout<<" Prenume = ";
		cin>>S[*n].NPP.prenume;
		cout<<" Varsta = ";
		cin>>S[*n].ani;
		do
		{
			cout<<" Nota ["<<S[*n].nrNOTE+1<<"]"<<endl;
		
			cout<<"  --- Enter disciplina = ";
			cin>>S[*n].NOTE[S[*n].nrNOTE].dis;
			
			cout<<"  --- Enter nota = ";
			cin>>S[*n].NOTE[S[*n].nrNOTE].nota;
			
			S[*n].media += S[*n].NOTE[S[*n].nrNOTE].nota;
			
			S[*n].nrNOTE++;
			
			cout<<" insert NOTE ?  [ESC] - exit insert, [ANY KEY] ..."<<endl;
		} while( _getch() != 27 );
		
		S[*n].media /= S[*n].nrNOTE;

	   cout<<" Status (0/1) = ";
	   cin>>S[*n].active; 
	   *n+=1;
	   cout<<"\n [ESC] - for exit    OR   [ANY KEY] -  for continue"<<endl;
    }while(_getch()!=27);
  
}

void showSTUD(STUD *S, int *N)
{
	system("cls");
	
	if( *N == 0 )
	{
		cout<<" Nu sunt studenti "<<endl;
	}
	else
	{
		int nrp = 3, K;
		
		int in = 0, sf = nrp;
		
		while( 1 )
		{
			system("cls");
			cout<<endl;
			cout<<setw(5)<<"ID"<<setw(15)<<"NUME"<<setw(15)<<"PRENUME"<<setw(15)<<"VARSTA"<<setw(10)<<"MEDIA"<<setw(14)<<"ACTIVE"<<endl;
			cout<<"\n";
			
			for(int i=in; i<sf; i++)
			{
				cout<<setw(5)<<S[i].id<<setw(15)<<S[i].NPP.nume<<setw(15)<<S[i].NPP.prenume<<setw(13)<<S[i].ani<<setw(12)<<S[i].media<<setw(12)<<S[i].active<<endl;
  				cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
			}
			
			switch( _getch() )
			{
			  /* + */	case 43: 
						  in+=nrp; 
						  sf+=nrp;
						  if( sf >= *N )
						  {
							in = *N - nrp;
							sf = *N;
						  }
						  break;
			  /* - */	case 45:
						  in-=nrp;
						  sf-=nrp;
						  if( in < 0 )
						  {
							in = 0;
							sf = nrp;
						  }
						  break;
			  /*ESC*/	case 27: return;
			}	
		}		
	}//end else
	system("pause");
}

void editSTUDnume(STUD *S, int *n)
{
	system("cls");
	int i;
	int x;
	cout<<" Edit STUDENT Nume "<<endl;
	cout<<" Introduceti ID-ul Studentului: ";
	cin>>x;
	if (x<=*n)
	{ 
		cout<<" Introduceti numele nou al Studentului: "; 
		cin>>S[x-1].NPP.nume;
		cout<<"Nume schimbat cu succes !"<<endl;	
	} 
	else
	{
		cout<<"Acest ID nu exista"<<endl; 
	}   
	  
	system("pause");
}

void editSTUDprenume(STUD *S, int *n)
{
	system("cls");
	int i; 
	int x;
	cout<<" Edit STUDENT Prenume "<<endl;
	cout<<" Introduceti ID-ul Studentului: "; 
	cin>>x;
	if (x<=*n)
	{
		cout<<" Introduceti prenumele nou al Studentului: ";
		cin>>S[x-1].NPP.prenume;
		cout<<"Prenume schimbat cu succes !"<<endl;
	} 
	else
	{
		cout<<"Acest ID nu exista"<<endl;
	}
	
	system("pause");
}

void editSTUDvarsta(STUD *S, int *n)
{
	system("cls");
	int i; 
	int x;
	cout<<" Edit STUDENT Varsta "<<endl;
	cout<<" Introduceti ID-ul Studentului: ";
	cin>>x;
	if (x<=*n)
	{
		cout<<" Introduceti varsta noua a Studentului: ";
		cin>>S[x-1].ani;
	 	cout<<"Varsta schimbata cu succes"<<endl;
	} 
	else
	{
		cout<<"Acest ID nu exista"<<endl;
	}     
	
	system("pause");
}

void editSTUDactive(STUD *S, int *n)
{
	system("cls");
	int i; 
	int x;
	cout<<" Edit STUDENT Active "<<endl;
	cout<<" Introduceti ID-ul Studentului: ";
	cin>>x;
	if (x<=*n)
	{
		cout<<" Introduceti valoarea active (0/1) a Studentului: ";
		cin>>S[x-1].active;
	 	cout<<"Activitatea schimbata cu succes"<<endl;
	} 
	else
	{
		cout<<"Acest ID nu exista"<<endl;
	}     
	
	system("pause");
}

void findSTUDnume(STUD *S, int *n)
{
	system("cls");
	if( *n == 0 ) cout<<" Nu sunt date pentru afisare "<<endl;
	else
	{
		char nume[256];
		bool k=true;
		cout<<" Enter nume = ";
		cin>>nume;
		cout<<endl; 
		cout<<setw(5)<<"ID"<<setw(15)<<"NUME"<<setw(15)<<"PRENUME"<<setw(15)<<"VARSTA"<<setw(10)<<"MEDIA"<<setw(14)<<"ACTIVE"<<endl;
		cout<<"\n";
		for(int i=0 ; i < *n ; i++)
		{   
			if(strcmp(S[i].NPP.nume,nume) == 0)
			{
				k=false; 
				cout<<setw(5)<<S[i].id<<setw(15)<<S[i].NPP.nume<<setw(15)<<S[i].NPP.prenume<<setw(15)<<S[i].ani<<setw(10)<<S[i].media<<setw(14)<<S[i].active<<endl;
				cout<<"------------------------------------------"<<endl; 
			}
		}// for
		if(k) cout<<" Nu s-a gasit nici un nume ["<<nume<<"] "<<endl;
	}// else
	system("pause");
}

void findSTUDprenume(STUD *S, int *n)
{
	system("cls");
	if( *n == 0 ) cout<<" Nu sunt date pentru afisare "<<endl;
	else
	{
		char nume[256];
		bool k=true;
		cout<<" Enter prenume = ";
		cin>>nume;
		cout<<endl; 
		cout<<setw(5)<<"ID"<<setw(15)<<"NUME"<<setw(15)<<"PRENUME"<<setw(15)<<"VARSTA"<<setw(10)<<"MEDIA"<<setw(14)<<"ACTIVE"<<endl;
		cout<<"\n";
		for(int i=0 ; i < *n ; i++)
		{   
			if(strcmp(S[i].NPP.prenume,nume) == 0)
			{
				k=false; 
				cout<<setw(5)<<S[i].id<<setw(15)<<S[i].NPP.nume<<setw(15)<<S[i].NPP.prenume<<setw(15)<<S[i].ani<<setw(10)<<S[i].media<<setw(14)<<S[i].active<<endl;
				cout<<"------------------------------------------"<<endl; 
			}
		}// for
		if(k) cout<<" Nu s-a gasit nici un prenume ["<<nume<<"] "<<endl;
	}// else
	system("pause");
}

void findSTUDid(STUD *S, int *n)
{
	system("cls");
	if( *n == 0 ) cout<<" Nu sunt date pentru afisare "<<endl;
	else
	{
		int id;
		bool k=true;
		cout<<" Enter ID = ";
		cin>>id;
		cout<<endl; 
		cout<<setw(5)<<"ID"<<setw(15)<<"NUME"<<setw(15)<<"PRENUME"<<setw(15)<<"VARSTA"<<setw(10)<<"MEDIA"<<setw(14)<<"ACTIVE"<<endl;
		cout<<"\n";
		for(int i=0 ; i < *n ; i++)
		{   
			if( S[i].id == id)
			{
				k=false;
				cout<<setw(5)<<S[i].id<<setw(15)<<S[i].NPP.nume<<setw(15)<<S[i].NPP.prenume<<setw(15)<<S[i].ani<<setw(10)<<S[i].media<<setw(14)<<S[i].active<<endl;
				cout<<"------------------------------------------"<<endl; 
			}
		}// for
		if(k) cout<<" Nu s-a gasit nici un student cu ID ["<<id<<"] "<<endl;
	}// else
	system("pause");
}

void saveUSERS(USERS *S,int *n)
{
	if (*n!=0)
	{
		FILE *fp;
		fp = fopen("user.step","w+");
		for (int i=0; i<*n;i++)
		{ 
			fprintf(fp,"%s ",S[i].nume);
			fprintf(fp,"%s ",S[i].password);
			fprintf(fp,"%d ",S[i].tip);  
			fprintf(fp,"%d ",S[i].id);
			fprintf(fp,"%d ",S[i].status);
			fprintf(fp,"\n");
		} 
		fclose(fp);  	
  	}
}

void loadUSERS(USERS *S,int *n)
{
  	FILE *f;
	f = fopen("user.step","r+");
  	if( f !=NULL ) 
	{
	  	int k=0;
	    int ch;
	
	    while (EOF != (ch=getc(f)))
		{
	        if ('\n' == ch) { ++k;}
		}	  
		
		fclose(f);
		 
		if (*n>0)
		{ 
			for(int j=0; j<*n;j++)
			{
				for(int i=1; i<=*n; i++)
				{
					S[i-1]=S[i];
				}
			}
		}
		
		*n=k;
		f = fopen("user.step","r+");	  
		  
		for (int i=0; i<*n;i++)
		{ 	
		  fscanf(f,"%s %s %d %d %d\n",&S[i].nume,&S[i].password,&S[i].tip,&S[i].id,&S[i].status);
		}
		
		fclose(f); 
	}
}

template <typename T>
void save(char *NumeFile, T *x, int *N)
{
	system("cls");

	fp = fopen(NumeFile,"w+b");
	
	fwrite(x, sizeof(T), *N, fp);
	
	fclose(fp);
}

template <typename T>
void load(char *NumeFile, T *x, int *N)
{
	system("cls");
	
	fp = fopen(NumeFile,"r+b");
	
	*N = fread(x, sizeof(T), 1000, fp);
	
	fclose(fp);
}

void raportSTUDall(STUD *S, int *n)
{
	int pp=3, in=0, k=0, j=0, x;
	system("cls");
	STUD A[100];
	for(int i=0; i<*n; i++ )
	{
		A[j]=S[i];
		j++;
		k++;
	}
 	if (k<pp) {pp=k;}
	int sf=pp;
	char sz[60]; char as[30]=".doc";
	
	while(1)
	{
		system("cls");
		cout<<endl; 
		cout<<setw(5)<<"ID"<<setw(15)<<"NUME"<<setw(15)<<"PRENUME"<<setw(15)<<"VARSTA"<<setw(10)<<"MEDIA"<<setw(14)<<"ACTIVE"<<endl;
		cout<<"\n";
	
		for(int i=in; i < sf; i++)
		{   
			cout<<setw(5)<<S[i].id<<setw(15)<<S[i].NPP.nume<<setw(15)<<S[i].NPP.prenume<<setw(15)<<S[i].ani<<setw(10)<<S[i].media<<setw(14)<<S[i].active<<endl;
			cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
		}
	
		cout<<"Introduceti ( = ) pentru a salva intr-un document Word acest raport"<<endl;
		switch(_getch())
		{
			case 43: /*+*/  in+=pp; sf+=pp; if( sf >= k){ in = k-pp; sf = k;  }   break;
			case 45: /*-*/  in-=pp; sf-=pp; if( in < 0 ){ in = 0; sf = pp;  }     break;
			case 61: /*=*/  
				bool ok; X: system("cls");
				cout<<"Introduceti numele documentului pe care doriti sa il creati (Folositi doar cifre litere si punct fara space): "; 
				cin>>sz;
				ok = true;
				for (int j=0; j < strlen(sz); j++)
				{
					if ( ( int(sz[j])<48) || (( int(sz[j])>57) && ( int(sz[j])<65)) ||  (( int(sz[j])>90) && ( int(sz[j])<97)) ||  ( int(sz[j])>122) )
					{
						ok=false;
					} 
				}
				if(ok==false){goto X;}
				cout<<"DONE"<<endl;
				FILE *fp;
				strcat(sz,as);
				fp = fopen(sz , "w+");
				
				fprintf( fp , "-------------------------------------------------------------------------\n");
				fprintf( fp , "%5s %15s %10s %10s %10s %10s\n","|ID|","| NUME |","|PRENUME|","|VARSTA|","|MEDIA|","|ACT|");
				fprintf( fp , "-------------------------------------------------------------------------\n");
				
				for(int i=0; i < k ; i++)
				{
					fprintf( fp , "%5d %15s %10s %10d %10f %10d\n",A[i].id,A[i].NPP.nume,A[i].NPP.prenume,A[i].ani,A[i].media,A[i].active);
					fprintf( fp , "-------------------------------------------------------------------------\n");
				}
				fprintf(fp,"*** \n ACT - ACTIVE/STATUS");
				
				fclose(fp);
				
				system(sz); break;
				
			
			case 27: /*ESC*/ return;
		}
	
	}	   
	system("pause");
}

void raportSTUDmedia(STUD *S, int *n)
{
	int pp=3, in=0, k=0, j=0, x;
	system("cls");
	STUD A[100];
	for(int i=0; i<*n; i++ )
	{
		A[j]=S[i];
		j++;
		k++;
	}
	
	STUD temp;
	bool X=true;

	while( X )	 
	{	
		X=false; 
		for( int i=0; i<*n-1 ; i++) 
		{
			if( A[i].media < A[i+1].media )
			{
				temp = A[i];
				A[i] = A[i+1];
				A[i+1] = temp;
				
				X=true;	  
			}
		}   
	}
	
 	if (k<pp) {pp=k;}
	int sf=pp;
	char sz[60]; char as[30]=".doc";
	
	while(1)
	{
		system("cls");
		cout<<endl; 
		cout<<setw(5)<<"ID"<<setw(15)<<"NUME"<<setw(15)<<"PRENUME"<<setw(15)<<"VARSTA"<<setw(10)<<"MEDIA"<<setw(14)<<"ACTIVE"<<endl;
		cout<<"\n";
	
		for(int i=in; i < sf; i++)
		{   
			cout<<setw(5)<<A[i].id<<setw(15)<<A[i].NPP.nume<<setw(15)<<A[i].NPP.prenume<<setw(15)<<A[i].ani<<setw(10)<<A[i].media<<setw(14)<<A[i].active<<endl;
			cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
		}
	
		cout<<"Introduceti ( = ) pentru a salva intr-un document Word acest raport"<<endl;
		switch(_getch())
		{
			case 43: /*+*/  in+=pp; sf+=pp; if( sf >= k){ in = k-pp; sf = k;  }   break;
			case 45: /*-*/  in-=pp; sf-=pp; if( in < 0 ){ in = 0; sf = pp;  }     break;
			case 61: /*=*/  
				bool ok; X: system("cls");
				cout<<"Introduceti numele documentului pe care doriti sa il creati (Folositi doar cifre litere si punct fara space): "; 
				cin>>sz;
				ok = true;
				for (int j=0; j < strlen(sz); j++)
				{
					if ( ( int(sz[j])<48) || (( int(sz[j])>57) && ( int(sz[j])<65)) ||  (( int(sz[j])>90) && ( int(sz[j])<97)) ||  ( int(sz[j])>122) )
					{
						ok=false;
					} 
				}
				if(ok==false){goto X;}
				cout<<"DONE"<<endl;
				FILE *fp;
				strcat(sz,as);
				fp = fopen(sz , "w+");
				
				fprintf( fp , "-------------------------------------------------------------------------\n");
				fprintf( fp , "%5s %15s %10s %10s %10s %10s\n","|ID|","| NUME |","|PRENUME|","|VARSTA|","|MEDIA|","|ACT|");
				fprintf( fp , "-------------------------------------------------------------------------\n");
				
				for(int i=0; i < k ; i++)
				{
					fprintf( fp , "%5d %15s %10s %10d %10f %10d\n",A[i].id,A[i].NPP.nume,A[i].NPP.prenume,A[i].ani,A[i].media,A[i].active);
					fprintf( fp , "-------------------------------------------------------------------------\n");
				}
				fprintf(fp,"*** \n ACT - ACTIVE/STATUS");
				
				fclose(fp);
				
				system(sz); break;
				
			
			case 27: /*ESC*/ return;
		}
	
	}	   
	system("pause");
}

int auth(USERS *u, int *n)
{
	char user[100], pass[100];
	
	system("cls");
	cout<<"\t Log in "<<endl;
	cin.clear();
	cout<<"Username: ";
	cin>>user;
	cout<<"Password: ";
	cin>>pass;
	
	int i=0;
	while(i<*n)
	{
		if(strcmp(U[i].nume,user) == 0)
		{
			if(strcmp(U[i].password,pass) == 0)
			{
				return i;
			}
		}

		i++;
	}
	
	return -1;
}

int loadSECURITY()
{
	int a;
	FILE *f; f = fopen("security.step","r+");   	
	fscanf(f,"%d",&a);
	fclose(f);  
 
	return a;
}

void saveSECURITY(int n)
{
	FILE *f; f = fopen("security.step","w+");   	
	fprintf(f,"%d",n);
	fclose(f); 
}
