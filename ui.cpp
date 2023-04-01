int meniuU()
{
	system(script_color);
	system("cls");
	
	cout<<"\n\n\t   MENIU USER   "<<endl;
	cout<<"\t   1.  Insert Student   "<<endl;
	cout<<"\t   2.  Show Student   "<<endl;
	cout<<"\t   3.  Edit Student   "<<endl;
	cout<<"\t   4.  Find Student   "<<endl;
	cout<<"\t   5.  Save Student   "<<endl;
	cout<<"\t   6.  Raport   "<<endl;
	cout<<"\t ESC.  LogOUT  "<<endl;
	
	switch(_getch())
	{
		case 49 : return 1;
		case 50 : return 2;
		case 51 : NIVEL = 2; break;
		case 52 : NIVEL = 3; break;
		case 53 : save(STUDfile,s,N); break;
		case 54 : NIVEL = 4; break;
		
		case 27 : return 27;
	}
	
	return 0;
}

int meniuU1()
{
	system(script_color);
	system("cls");
  
	cout<<"\n\n\t MENIU USER - EDIT STUDENT "<<endl;
	cout<<"\t  1. Edit nume "<<endl;
	cout<<"\t  2. Edit prenume "<<endl;
	cout<<"\t  3. Edit varsta "<<endl;
	cout<<"\t  4. Edit active "<<endl; 
	cout<<"\tESC. Exit "<<endl;
	
	switch(_getch())
	{
		case 49 : return 31;	
		case 50 : return 32;
		case 51 : return 33;	
		case 52 : return 34;
		
		case 27 :  NIVEL = 1; break;
	}
	
	return 0;
}

int meniuU12()
{
	system(script_color);
	system("cls");
  
	cout<<"\n\n\t MENIU USER - FIND STUDENT "<<endl;
	cout<<"\t  1. Dupa nume "<<endl;
	cout<<"\t  2. Dupa prenume "<<endl;
	cout<<"\t  3. Dupa ID "<<endl;
	cout<<"\tESC. Exit "<<endl;
	
	switch(_getch())
	{
		case 49 : return 41;	
		case 50 : return 42;
		case 51 : return 43;	
		
		case 27 :  NIVEL = 1; break;
	}
	
	return 0;
}

int meniuraportU()
{
	system(script_color);
	system("cls");
  
	cout<<"\n\n\t MENIU USER - RAPOARTE STUDENT "<<endl;
	cout<<"\t  1. Lista studentilor "<<endl;
	cout<<"\t  2. Lista studentilor dupa medie "<<endl;
	cout<<"\tESC. Exit "<<endl;
	
	switch(_getch())
	{
		case 49 : return 61;	
		case 50 : return 62;	
		
		case 27 :  NIVEL = 1; break;
	}
	
	return 0;
}

int managementUSER()
{ 	
	switch(NIVEL)
	{
		case 1 : return meniuU();  break;
		case 2 : return meniuU1();  break; 
		case 3 : return meniuU12(); break; 
		case 4 : return meniuraportU();  break; 
	}
}
