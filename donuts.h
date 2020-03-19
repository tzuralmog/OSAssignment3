/*** ~bill/cs308/call_help_assign3.txt                          ***/
/******************************************************************/

/*** need a  .h  file with content as shown below         ***/

#include<time.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/signal.h>

#define		SEMKEY			(key_t)548341763
#define		MEMKEY			(key_t)548341763
#define		NUMFLAVORS	 	4
#define		NUMSLOTS       		50
#define		NUMSEMIDS	 	3
#define		PROD		 	0
#define		CONSUMER	 	1
#define		OUTPTR		 	2

struct	donut_ring{
	int	flavor  [NUMFLAVORS]  [NUMSLOTS];
	int	outptr  [NUMFLAVORS];
};

extern int		p (int, int);
extern int		v (int, int);
extern int		semsetall (int, int, int);








/*  here's the producer signal handler below       */


void    sig_handler(int sig)
{
	int	i,j,k;

	printf("In signal handler with signal # %d\n",sig);

	if(shmctl(shmid, IPC_RMID, 0) == -1){
		perror("handler failed shm RMID: ");
	}
	for(i = 0; i < NUMSEMIDS; i++){
	  if(semctl (semid[i], 0, 
 			    IPC_RMID) == -1){
		perror("handler failed sem RMID: ");
	  }
	}
        exit(5);
}



