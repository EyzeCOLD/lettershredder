#include <ncurses.h>
#include <unistd.h>

#include "MenuState.hpp"
#include "Renderer.hpp"

int main() {
	Renderer  r;
	MenuState menu;

	r.init();
	bool running = true;
	while (running) {
		menu.handleInput();
		menu.update(0.0);
		if (menu.getStateRequest() == 1)
			running = false;
		r.clearScreen();
		menu.render(r);
		r.render();
		napms(16);
	}
	return 0;
}
