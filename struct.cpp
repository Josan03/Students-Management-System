struct STUD
{
	struct npp
	{
		char nume[100];
		char prenume[100];
	}NPP;
	
	int ani;
	
	struct note
	{
		char dis[100];
		int nota;
	}NOTE[100];

	int nrNOTE=0;
	double media=0;
	int id;
	int active;
};

struct USERS
{
	char nume[100];
	char password[100];
	int tip;
	int id;
	int status;
};

USERS *U = new USERS[100];
STUD *s;
int *N, *M;
FILE *fp;
char STUDfile[100],USERfile[100],COLOR[10],script_color[100];
int a=-1;
int NIVEL = 1;
