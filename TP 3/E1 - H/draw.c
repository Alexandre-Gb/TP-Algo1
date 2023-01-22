#include <MLV/MLV_all.h>

#define LINE_COLOUR_1 MLV_COLOR_BLUE
#define LINE_COLOUR_2 MLV_COLOR_GREEN
#define BACKGROUND_COLOUR MLV_COLOR_BLACK

void tracer_h(int x, int y, int wid, MLV_Color line_colour){
	if (wid > 8){
		MLV_draw_line(x - (wid / 2), y - (wid / 2), x - (wid / 2), y + (wid / 2), line_colour);
		MLV_draw_line(x - (wid / 2), y, x + (wid / 2), y, line_colour);
		MLV_draw_line(x + (wid / 2), y - (wid / 2), x + (wid / 2), y + (wid / 2), line_colour);

		MLV_wait_milliseconds(30);
		MLV_update_window();

		tracer_h(x + (wid / 2), y + (wid / 2), wid / 2, MLV_rgba(35, 85, 255, 255));
		tracer_h(x - (wid / 2), y + (wid / 2), wid / 2, MLV_rgba(35, 85, 255, 255));
		tracer_h(x + (wid / 2), y - (wid / 2), wid / 2, MLV_rgba(35, 85, 255, 255));
		tracer_h(x - (wid / 2), y - (wid / 2), wid / 2, MLV_rgba(35, 85, 255, 255));
	}
	return;
}

int main() {
	/* Create the window */
	MLV_create_window("Draw", "Draw", 500, 500);
	MLV_draw_filled_rectangle(0, 0, 499, 499, BACKGROUND_COLOUR);

	tracer_h(500 / 2, 500 / 2, 500 / 2, MLV_rgba(35, 165, 255, 255));

	/* Wait and quit */

	MLV_wait_seconds(3);
	MLV_free_window();

	return 0;
}