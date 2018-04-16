#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void psinfo(char* PR);
void psprint(char* PS);
 
int main(int argc, char* argv[])
{
	
	
    if (argc<2)
		 
        return perror("Falta ingresar  PID"), 1;
        
         
    int i=argc;   
        
	
    printf("-- Informacion recolectada!!! \n" );
    
    
    
    for(i=1;i<=argc;i++){
		
    
    //printf("%s \n",argv[1]);
    
    if(strcmp(argv[1],"-l")==0){
	//printf("paso por la L \n");			
	psinfo(argv[i+1]);	
	//return 0;		
	}
	
	if(strcmp(argv[1],"-r")==0){
	//printf("paso por la R \n");
	psprint(argv[i+1]);
	
	}
	 if (argc==2){
		psinfo(argv[i]);
	}		
    
    	
    printf("... \n");
		
    	
    }
    
   

    
}

 void psinfo(char* PR){
	 
	 
	 
    char statFileName[128];             
    
    sprintf(statFileName, "/proc/%s/stat", PR);
    
    
    int num;
    long conv=strtol(PR,NULL,10);
    num=conv;
    int res;
    res=num/num;
    if(res=!1){
		printf("proceso ingresado no es numerico");
		exit(-1);
	}	
    if(res>9999){
		printf("proceso ingresado es muy grande , no existe");
		exit(-1);
	}
    
     
       
    FILE *fd = fopen(statFileName, "r");
    if (fd == NULL)
       /*return perror("No puedo encontrar el proceso especificado, no existe ¡¡¡"),1;*/
       printf("No puedo encontrar el proceso especificado , no existe ¡¡¡ ");
        
        
  int           pid;                      /** The process id. **/
  char          name[32]; /** The filename of the executable **/
  char          state; /** 1 **/          /** R is running, S is sleeping, 
			   D is sleeping in an uninterruptible wait,
			   Z is zombie, T is traced or stopped **/  				     
  int           ppid;                     /** The pid of the parent. **/
  int           pgrp;                     /** The pgrp of the process. **/
  int           session;                  /** The session id of the process. **/
  int           tty_nr;                      /** The tty the process uses **/
  int           tpgid;                    /** (too long) **/
  unsigned long flags;                    /** The flags of the process. **/
  unsigned long	minflt;                   /** The number of minor faults **/
  unsigned long	cminflt;                  /** The number of minor faults with childs **/
  unsigned long	majflt;                   /** The number of major faults **/
  unsigned long  cmajflt;                  /** The number of major faults with childs **/
  int           utime;                    /** user mode jiffies **/
  int           stime;                    /** kernel mode jiffies **/
  int	    	cutime;                   /** user mode jiffies with childs **/
  int           cstime;                   /** kernel mode jiffies with childs **/  
  long          priority;                 /** the standard nice value, plus fifteen **/
  long			nice;					  /** The nice value (see setpriority(2))**/
  int			num_threads; 		      /** Number of threads in this process**/  
  unsigned int  itrealvalue;              /** The time before the next SIGALRM is sent to the process **/
  int           starttime; /** 20 **/     /** Time the process started after system boot **/
  unsigned long  vsize;                    /** Virtual memory size **/
  long           rss;                      /** Resident Set Size **/
  long unsigned int  rsslim;                     /** Current limit in bytes on the rss **/
  unsigned int  startcode;                /** The address above which program text can run **/
  unsigned int	endcode;                  /** The address below which program text can run **/
  unsigned int  startstack;               /** The address of the start of the stack **/
  long unsigned int  kstkesp;                  /** The current value of ESP **/
  unsigned int  kstkeip;                 /** The current value of EIP **/
  long unsigned int	signal;                   /** The bitmap of pending signals **/
  int           blocked; /** 30 **/       /** The bitmap of blocked signals **/
  int           sigignore;                /** The bitmap of ignored signals **/
  int           sigcatch;                 /** The bitmap of catched signals **/
  unsigned int  wchan;  /** 33 **/        /** (too long) **/
  unsigned int  nswap;
  unsigned int  cnswap;
  int 		    exit_signal;					/**Signal to be sent to parent when we die.**/
  int           processor;
  unsigned int  rt_priority;
  unsigned int  policy;
  unsigned int  delayacct_blkio_ticks;
  unsigned int  guest_time;
  int           cguest_time;
  unsigned int  start_data;
  unsigned int  end_data;
  unsigned int  start_brk;
  unsigned int  arg_start;
  unsigned int  arg_end;
  unsigned int  env_start;
  unsigned int  env_end;
  int           exit_code;
    
    fscanf(fd,"%d "
				"%s "
                 "%c "/**estado**/
                 "%d "
				 "%d " 
				 "%d " 
				 "%d "
				 "%d "
				/* 
                 "%lu "
                 "%lu " 
				 "%lu "
			   	 "%lu "
				 "%lu "
				 "%lu "
				 "%lu "	
				 			               
                 "%ld "
				 "%ld " 
				 "%ld "
				 "%ld "
				 "%ld "
				 "%ld "
                 "%Lu "
                 */"%lu "
                 "%ld "
                 "%lu "/*
				 "%lu "
				 "%lu "
				 "%lu "
				 */"%lu "/*
				 "%lu "
				 */"%lu "/*
				 "%lu "
				 "%lu "
				 "%lu "
				 "%lu "
				 "%lu "
				 "%lu "
                 "%d  "
				 "%d "
                 "%u " 
                 "%u " 
                 "%Lu "
                 "%lu "
                 "%ld "
                 "%lu "
                 "%lu "
                 "%lu "
                 "%lu "
                 "%lu "
                 "%lu "
                 "%lu "
                 "%d "*/,
                  &pid,
                  name,
                  &state,
	   		      &ppid,
                  &pgrp,
	              &session,
	              &tty_nr,
	              &tpgid,/*
	              &flags,
	 		 	  &minflt,
	 			  &cminflt,
			      &majflt,
			      &cmajflt,
			      &utime,
			      &stime,
			      &cutime,
	 			  &cstime,
	  			  &priority,
				  &nice,
				  &num_threads,	 
				  &itrealvalue,
				  &starttime,
				  */&vsize,
				  &rss,
				  &rsslim,/*
				  &startcode,
				  &endcode,
				  &startstack,
				  */&kstkesp,/*
				  &kstkeip,
				  */&signal/*,
				  &blocked,
				  &sigignore,
				  &sigcatch,
				  &wchan,
				  &nswap,
				  &cnswap,
				  &exit_signal,
				  &processor,
				  &rt_priority,
				  &policy,
				  &delayacct_blkio_ticks,
				  &guest_time,
				  &cguest_time,
				  &start_data,
				  &end_data,
				  &start_brk,
				  &arg_start,
				  &arg_end,
				  &env_start,
				  &env_end,
				  &exit_code*/);
    
    fclose(fd);

   printf ("PID: %d\n"
                    "Nombre del proceso: %s\n"
                    "Estado: %c\n"
                    "Tamaño total de la imagen de memoria: %lu\n"
                    "Tamano de la memoria en la region TEXT: %lu\n"
					"Tamano de la memoria en la region DATA: %ld\n" 
					"Tamano de la memoria en la region STACK: %lu\n" 
					"Número de cambios de contexto realizados (voluntarios - no voluntarios): %lu\n",              
                    pid, name, state, vsize, rsslim, rss, kstkesp, signal );
	
		
    	
    }


void psprint(char* PS){
	
	
    char statFileName[128];             
    
    sprintf(statFileName, "/proc/%s/stat", PS);
    
    
    int num;
    long conv=strtol(PS,NULL,10);
    num=conv;
    int res;
    res=num/num;
    if(res=!1){
		printf("proceso ingresado no es numerico");
		exit(-1);
	}	
    if(res>9999){
		printf("proceso ingresado es muy grande , no existe");
		exit(-1);
	}
    
     //printf("paso por acaaaaaaaa");
    
       
    FILE *fd = fopen(statFileName, "r");
    if (fd == NULL)
       /*return perror("No puedo encontrar el proceso especificado, no existe ¡¡¡"),1;*/
       printf("No puedo encontrar el proceso especificado , no existe ¡¡¡ ");
        
        
  int           pid;                      /** The process id. **/
  char          name[32]; /** The filename of the executable **/
  char          state; /** 1 **/          /** R is running, S is sleeping, 
			   D is sleeping in an uninterruptible wait,
			   Z is zombie, T is traced or stopped **/  				     
  int           ppid;                     /** The pid of the parent. **/
  int           pgrp;                     /** The pgrp of the process. **/
  int           session;                  /** The session id of the process. **/
  int           tty_nr;                      /** The tty the process uses **/
  int           tpgid;                    /** (too long) **/
  unsigned long flags;                    /** The flags of the process. **/
  unsigned long	minflt;                   /** The number of minor faults **/
  unsigned long	cminflt;                  /** The number of minor faults with childs **/
  unsigned long	majflt;                   /** The number of major faults **/
  unsigned long  cmajflt;                  /** The number of major faults with childs **/
  int           utime;                    /** user mode jiffies **/
  int           stime;                    /** kernel mode jiffies **/
  int	    	cutime;                   /** user mode jiffies with childs **/
  int           cstime;                   /** kernel mode jiffies with childs **/  
  long          priority;                 /** the standard nice value, plus fifteen **/
  long			nice;					  /** The nice value (see setpriority(2))**/
  int			num_threads; 		      /** Number of threads in this process**/  
  unsigned int  itrealvalue;              /** The time before the next SIGALRM is sent to the process **/
  int           starttime; /** 20 **/     /** Time the process started after system boot **/
  unsigned long  vsize;                    /** Virtual memory size **/
  long           rss;                      /** Resident Set Size **/
  long unsigned int  rsslim;                     /** Current limit in bytes on the rss **/
  unsigned int  startcode;                /** The address above which program text can run **/
  unsigned int	endcode;                  /** The address below which program text can run **/
  unsigned int  startstack;               /** The address of the start of the stack **/
  long unsigned int  kstkesp;                  /** The current value of ESP **/
  unsigned int  kstkeip;                 /** The current value of EIP **/
  long unsigned int	signal;                   /** The bitmap of pending signals **/
  int           blocked; /** 30 **/       /** The bitmap of blocked signals **/
  int           sigignore;                /** The bitmap of ignored signals **/
  int           sigcatch;                 /** The bitmap of catched signals **/
  unsigned int  wchan;  /** 33 **/        /** (too long) **/
  unsigned int  nswap;
  unsigned int  cnswap;
  int 		    exit_signal;					/**Signal to be sent to parent when we die.**/
  int           processor;
  unsigned int  rt_priority;
  unsigned int  policy;
  unsigned int  delayacct_blkio_ticks;
  unsigned int  guest_time;
  int           cguest_time;
  unsigned int  start_data;
  unsigned int  end_data;
  unsigned int  start_brk;
  unsigned int  arg_start;
  unsigned int  arg_end;
  unsigned int  env_start;
  unsigned int  env_end;
  int           exit_code;
    
    fscanf(fd,"%d "
				"%s "
                 "%c "/**estado**/
                 "%d "
				 "%d " 
				 "%d " 
				 "%d "
				 "%d "
				/* 
                 "%lu "
                 "%lu " 
				 "%lu "
			   	 "%lu "
				 "%lu "
				 "%lu "
				 "%lu "	
				 			               
                 "%ld "
				 "%ld " 
				 "%ld "
				 "%ld "
				 "%ld "
				 "%ld "
                 "%Lu "
                 */"%lu "
                 "%ld "
                 "%lu "/*
				 "%lu "
				 "%lu "
				 "%lu "
				 */"%lu "/*
				 "%lu "
				 */"%lu "/*
				 "%lu "
				 "%lu "
				 "%lu "
				 "%lu "
				 "%lu "
				 "%lu "
                 "%d  "
				 "%d "
                 "%u " 
                 "%u " 
                 "%Lu "
                 "%lu "
                 "%ld "
                 "%lu "
                 "%lu "
                 "%lu "
                 "%lu "
                 "%lu "
                 "%lu "
                 "%lu "
                 "%d "*/,
                  &pid,
                  name,
                  &state,
	   		      &ppid,
                  &pgrp,
	              &session,
	              &tty_nr,
	              &tpgid,/*
	              &flags,
	 		 	  &minflt,
	 			  &cminflt,
			      &majflt,
			      &cmajflt,
			      &utime,
			      &stime,
			      &cutime,
	 			  &cstime,
	  			  &priority,
				  &nice,
				  &num_threads,	 
				  &itrealvalue,
				  &starttime,
				  */&vsize,
				  &rss,
				  &rsslim,/*
				  &startcode,
				  &endcode,
				  &startstack,
				  */&kstkesp,/*
				  &kstkeip,
				  */&signal/*,
				  &blocked,
				  &sigignore,
				  &sigcatch,
				  &wchan,
				  &nswap,
				  &cnswap,
				  &exit_signal,
				  &processor,
				  &rt_priority,
				  &policy,
				  &delayacct_blkio_ticks,
				  &guest_time,
				  &cguest_time,
				  &start_data,
				  &end_data,
				  &start_brk,
				  &arg_start,
				  &arg_end,
				  &env_start,
				  &env_end,
				  &exit_code*/);
    
    fclose(fd);
    
    
	char outFilename[80];
	FILE *outFile;
	
	/*printf("nombre:");
	fflush(stdin);
	scanf("%s",outFilename);
	*/
	
	char nombre[80]="psinfo-report-";
	char pp[20];
	char extension[20]=".info";
	
	strcpy(pp,PS);
	strcat(nombre,pp);
	strcpy(outFilename,nombre);	
	strcat(outFilename,extension);
	
	//char extension[20]=".info";
	//strcpy(outFilename,extension);
	
	outFile=fopen(outFilename,"w");
	fprintf (outFile,"PID: %d\n"
                    "Nombre del proceso: %s\n"
                    "Estado: %c\n"
                    "Tamaño total de la imagen de memoria: %lu\n"
                    "Tamano de la memoria en la region TEXT: %lu\n"
					"Tamano de la memoria en la region DATA: %ld\n" 
					"Tamano de la memoria en la region STACK: %lu\n" 
					"Número de cambios de contexto realizados (voluntarios - no voluntarios): %lu\n",              
                    pid, name, state, vsize, rsslim, rss, kstkesp, signal );
                    
    fclose(outFile);
	printf("archivo de salida generado: \n %s",outFilename);
	                
	}
	
