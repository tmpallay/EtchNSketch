#include <stdlib.h>
#include <stdio.h>
#include <curses.h>

int xpos = 0;
int ypos = 0;
int ex = 0;
int ey = 0;

void draw( char c, char * draw_c_pt, int winx, int winy, int write );

int main() {
	
	WINDOW * mainwin;
	int winx = 0;
	int winy = 0;

	char c;
	char * c_pt = &c;
	int active = 1;
	int write = 1;

	char draw_c = '0';
	char * draw_c_pt = &draw_c;

	if (( mainwin = initscr() ) == NULL ) {
		fprintf( stderr, "Error initialising ncurses.\n" );
		exit( EXIT_FAILURE );
    }

    curs_set( 0 );
    noecho();

    getmaxyx( mainwin, winy, winx );
    xpos = winx / 2;
    ypos = winy / 2;

    refresh();

    while( active == 1 ) {

    	getmaxyx( mainwin, winy, winx );

    	ex = xpos;
    	ey = ypos;

	    c = getch();

	    switch( c ) {

	    	case 'q' :
	    		active = !active;
	    		break;

	    	case 'c' :
	    		clear();
	    		break;

    		case 'r' :
    			if( write == 0 ) mvaddch( ey, ex, ' ' );
    			write = !write;
    			break;

			case 'p' :
				draw_c = getch();
				break;

			case '\033' :
				getch();
				c = getch();
				draw( c, draw_c_pt, winx, winy, write );

	    }

    }

    delwin( mainwin );
    endwin();
    refresh();

    return EXIT_SUCCESS;

}

void draw( char c, char * draw_c_pt, int winx, int winy, int write ) {
	
	switch( c ) {

    	case 'A' :
	    	ypos--;
	    	break;

    	case 'D' :
    		xpos--;
    		break;

		case 'B' :
			ypos++;
			break;

		case 'C' :
			xpos++;

    }

    if( xpos < 0 ) xpos = 0;
    if( xpos > winx-1 ) xpos = winx-1;
    if( ypos < 0 ) ypos = 0;
    if( ypos > winy-1 ) ypos = winy-1;

    if( write == 0 ) {

    	mvaddch( ypos, xpos, 'X' );
    	mvaddch( ey, ex, ' ' );

    }
    else mvaddch( ypos, xpos, *draw_c_pt );

}