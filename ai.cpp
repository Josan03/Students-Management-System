int meniuA()
{
	system(script_color);
	system("cls");
	
	cout<<"\n\n\t   MENIU ADMIN   "<<endl;
	cout<<"\t   0.  Management Users   "<<endl;
	cout<<"\t   1.  Insert Student   "<<endl;
	cout<<"\t   2.  Show Student   "<<endl;
	cout<<"\t   3.  Edit Student   "<<endl;
	cout<<"\t   4.  Find Student   "<<endl;
	cout<<"\t   5.  Save Student   "<<endl;
	cout<<"\t   6.  Raport   "<<endl;
	cout<<"\t ESC.  LogOUT  "<<endl;
	
	switch(_getch())
	{
		case 48 : NIVEL = 4; break;
		case 49 : return 1;
		case 50 : return 2;
		case 51 : NIVEL = 2; break;
		case 52 : NIVEL = 3; break;
		case 53 : save(STUDfile,s,N); break;
		case 54 : NIVEL = 5; break;
		
		case 27 : return 27;
	}
	
	return 0;
}

int meniuA1()
{
	system(script_color);
	system("cls");
  
	cout<<"\n\n\t MENIU ADMIN - EDIT STUDENT "<<endl;
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

int meniuA12()
{
	system(script_color);
	system("cls");
  
	cout<<"\n\n\t MENIU ADMIN - FIND STUDENT "<<endl;
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

int meniuraportA()
{
	system(script_color);
	system("cls");
  
	cout<<"\n\n\t MENIU ADMIN - RAPOARTE STUDENT "<<endl;
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

int meniuA123()
{
  system("cls")	;
  
	cout<<"\n\n\t MENIU ADMIN - Mangement users "<<endl;
 	cout<<"\t  1. Insert user "<<endl;
	cout<<"\t  2. Show users "<<endl;
	cout<<"\t  3. Edit user  "<<endl; 
	cout<<"\t  4. Find user "<<endl;
	cout<<"\t  5. Save users database"<<endl;
	cout<<"\tESC. Exit "<<endl;
	
	switch(_getch())
	{
		case 49 :  return 101;  
		case 50 :  return 102;
		case 51 :  NIVEL = 6;  break;
		case 52 :  return 103;
		case 53 :  return 104;
		
		case 27 :  NIVEL = 1;  break;
	}
	
	return 0;
}

int meniuA1234()
{
  system("cls")	;
  
	cout<<"\n\n\t MENIU ADMIN - Mangement users - Edit user "<<endl;
 	cout<<"\t  1. Edit nume "<<endl;
	cout<<"\t  2. Edit parola "<<endl;
	cout<<"\t  3. Edit tip "<<endl;
	cout<<"\tESC. Exit "<<endl;
	
	switch(_getch())
	{
		case 49 :  return 105;  
		case 50 :  return 106;
		case 51 :  return 107;
		
		case 27 :  NIVEL = 4; break;
	}
	
	return 0;
}

int managementADMIN()
{ 	
	switch(NIVEL)
	{
		case 1 : return meniuA();  break;
		case 2 : return meniuA1();  break; 
		case 3 : return meniuA12(); break; 
		case 4 : return meniuA123(); break; 
		case 5 : return meniuraportA();  break; 
 	    case 6 : return meniuA1234(); break;
	}
}
