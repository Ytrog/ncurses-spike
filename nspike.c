#include <ncurses.h>

int main() {

	initscr(); // Refreshes stdscr
	cbreak();
	noecho();
	keypad(stdscr, TRUE);

	if (has_colors()) {
		start_color();
		mvprintw(21,20, "Colors on");
	}

	attron(A_BOLD | A_UNDERLINE);
	move(20,20);
	printw("Hello World");
	refresh();

	move(0,0);

	//init_pair(1, COLOR_GREEN, COLOR_BLACK);

	for (int i = 0; i < 8; i++) {

		if (i > 0) {

			init_pair(i, i, COLOR_BLACK);
		}

		short red, green, blue, foreground, background;
		color_content(i, &red, &green, &blue);
		pair_content(i, &foreground, &background);
		attron(COLOR_PAIR(i));
		mvprintw(i, 0, "pair %d, red=%d, green=%d, blue=%d, foreground=%d, background=%d", i, red, green, blue, foreground, background);

	}

	refresh();

	getch();
	
	endwin();

	return 0;

}
