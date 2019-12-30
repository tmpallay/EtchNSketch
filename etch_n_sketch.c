#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <curses.h>

int main() {

	WINDOW * mainwin;
	int winx, winy = 0;

	char c;
	int write = 1;

	int xpos, ypos = 0;
	int ex, ey;

	if ( (mainwin = initscr()) == NULL ) {
		fprintf(stderr, "Error initialising ncurses.\n");
		exit(EXIT_FAILURE);
    }

    curs_set(0);

    getmaxyx(mainwin, winy, winx);
    xpos = winx / 2;
    ypos = winy / 2;

    refresh();

    while( c != 'q' ) {

    	refresh();
    	getmaxyx(mainwin, winy, winx);

    	ex = xpos;
    	ey = ypos;

	    c = getchar();

    	if( c == 'c' ) clear();
    	if( c == 'r' ) {
    		if( write == 0 ) write = 1;
    		else write = 0;
    	}

	    switch( c ) {

	    	case 'w' :
		    	ypos--;
		    	break;

	    	case 'a' :
	    		xpos--;
	    		break;

    		case 's' :
    			ypos++;
    			break;

			case 'd' :
				xpos++;

	    }

	    if( xpos < 0 ) xpos = 0;
	    if( xpos > winx-1 ) xpos = winx-1;
	    if( ypos < 0 ) ypos = 0;
	    if( ypos > winy-1 ) ypos = winy-1;

	    switch( write ) {

	    	case 0 :
	    		mvaddstr(ypos, xpos, "X");
	    		mvaddstr(ey, ex, " ");
	    		break;

    		case 1 :
	    		mvaddstr(ypos, xpos, "0");

    	}
    
    }

    /*  Clean up after ourselves  */

    delwin(mainwin);
    endwin();
    refresh();

    return EXIT_SUCCESS;

}