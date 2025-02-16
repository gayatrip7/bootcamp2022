#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) 
{
    init_counter_1();
    int id1 = init_mylock();
    int id2 = init_mylock();
    int ret1 = fork(); // creates child process 1

    /* This is where we spawn multiple processes to increment different global counters.
       Modify this to ensure race conditions do not mess up final value.
       Without locking, the output value of counter_1 and counter_2 would be a random value less than 20000.
    */

    /*  
        Tescases:
            1. Print lock id if the lock has been initialized.
            2. Define and call the function 'int holding_mylock(int id)' to check the status of
               the lock in two scenarios - i) when the lock is held and ii) when the lock is not held. 
            3. You have to implement locking in all the processes so that the output value of both counter variables comes
               to be 20000.
    */

    // Hint: Implement one locking system for this counter variable
    int acq = acquire_mylock(id1);
    if (ret1)
    {
	    printf(1,"parent: acquire lock output %d\n",acq);
	    printf(1,"parent: holding %d\n",holding_mylock(id1));
    }
    else
    {
	    printf(1,"child1: acquire lock output %d\n",acq);
	    printf(1,"child1: holding %d\n",holding_mylock(id1));
    }
    for(int i=0; i<10000; i++){
        update_cnt_1(display_count()+1);
    }
    if (ret1)
    {
	    printf(1,"parent: release lock output %d\n",release_mylock(id1));
	    printf(1,"parent: holding %d\n",holding_mylock(id1));
    }
    else
    {
	    printf(1,"child1: release lock output %d\n",release_mylock(id1));
	    printf(1,"child1: holding %d\n",holding_mylock(id1));
    }
    if(ret1 == 0){
        // Hint: Implement one locking system for this counter variable

        init_counter_2();
	int ret2 = fork(); //creates child process 2
	int acq2 = acquire_mylock(id2);
	if (ret2)
	{
	    printf(1,"parent: acquire lock output %d\n",acq2);
	    printf(1,"parent: holding %d\n",holding_mylock(id2));
	}
	else
	{
	    printf(1,"child2: acquire lock output %d\n",acq2);
	    printf(1,"child2: holding %d\n",holding_mylock(id2));
	}
        for(int j=0; j<10000; j++){
            update_cnt_2(display_count_2()+1);
        }
	    if (ret2)
	    {
		    printf(1,"parent: release lock output %d\n",release_mylock(id2));
		    printf(1,"parent: holding %d\n",holding_mylock(id2));
	    }
	    else
	    {
		    printf(1,"child2: release lock output %d\n",release_mylock(id2));
		    printf(1,"child2: holding %d\n",holding_mylock(id2));
	    }
        if(ret2==0)
            exit();
        else{
            wait();
            printf(1, "counter_2: %d\n", display_count_2());
            exit();
        }
    }
    else{
        wait();
        printf(1, "counter_1: %d\n", display_count_1());
        exit();
    }

} 
