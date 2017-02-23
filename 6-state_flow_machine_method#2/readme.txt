*  The code implements the state machine shown below in C:
*
*         ------------                 	     -------------
*         |  State   |		             |	  State   |
*         |     A    |--------Event 0------->|	    B	  |
*	  |          |			     |		  |
*         ------------		             -------------
*		^		    		|       ^
*		|				|    	|
*		|			    Event 1   	|
*		|				|    Event 2
*	    Event 0				|  	|
*		|				V   	|
*		|               	     ----------------
*		|			    |	  State     |
*		----------------------------|	    C	    |
*					    |		    |
*					    -----------------
