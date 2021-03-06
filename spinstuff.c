//number of processes
#define NPROC 4

//wants to eat. so goes for the forks
bool want_to_eat[NPROC] = false;

//is eating
bool eating[NPROC] =false;

#define semaphore byte

semaphore fork[NPROC] =1;

#define up(s) {s++;}
#define down(s) {atomic{s > 0; s--;}}

active[4] proctype Phil()
{
	byte me = _pid

do
::
	//not eating (thinking)
	printf("P%d is thinking\n",me );

	//wanting to eat (grabbing forks)
	want_to_eat[me] = true;

	down(fork[me]);
	down(fork[(me + NPROC -1)%NPROC]);

	want_to_eat[me] = false;

	//eating
	eating[me] = true;
	printf("P%d is eating\n",me );
	eating[me] = false;

	//stopping eating (putting down forks)
	up(fork[me]);
	up(fork[(me + NPROC -1)%NPROC]);
	
od;

}