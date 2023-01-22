#include "grid.h"
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include "draw.h"

/*
 * Allocate memory for a grid and initialize each cell.
 */
grid *create_grid(int x_size, int y_size) {
	int i, j;
	grid *g = (grid *)malloc(sizeof(grid));
	g->x_size = x_size;
	g->y_size = y_size;
	g->cells = (cell **)malloc(x_size*sizeof(cell *));
	for (i = 0; i < x_size; i++)
		g->cells[i] = (cell *)malloc(y_size*sizeof(cell));

	for (j = 0; j < y_size; j++)
		for (i = 0; i < x_size; i++) {
			g->cells[i][j].x_pos = i;
			g->cells[i][j].y_pos = j;
			g->cells[i][j].visible = 0;
			g->cells[i][j].marked = 0;
			g->cells[i][j].mine = 0;
			g->cells[i][j].mine_count = 0;
		}

	return g;
}

/*
 * Free memory for a grid.
 */
void free_grid(grid *g) {
	int i;
	for (i = 0; i < g->x_size; i++)
		free(g->cells[i]);
	free(g->cells);
	free(g);
}

/*
 * Set all cells to visible (for debugging).
 */
void set_all_visible(grid *g) {
	int x, y;
	for (x = 0; x < g->x_size; x++)
		for (y = 0; y < g->y_size; y++)
			g->cells[x][y].visible = 1;
}

/*
 * Add exactly n mines to grid g in random positions.
 */
void add_mines(grid *g, int n) {
	if (n > 0){
		int x, y;
		do{
			x = rand() % g->x_size;
			y = rand() % g->y_size;
		} while (g->cells[x][y].mine);
		
		g->cells[x][y].mine = 1;

		int i, j;
		for (i = 1; i >= -1; i--){
			for (j = 1; j >= -1; j--){
				if ((x + i >= 0 && x + i < g->x_size) && (y + j >= 0 && y + j < g->y_size))
					if (x + i != x || y + j != y)
						g->cells[x + i][y + j].mine_count++;
			}
		}
		add_mines(g, n - 1);
	}

	return;
}

/*
 * Uncover cell c in grid g.
 * Return the total number of cells uncovered.
 */
int uncover(grid *g, cell *c) {
	if (c->visible || c->marked)
		return 0;
	
	c->visible = 1;
	draw_cell_actualise_window(c);
	MLV_wait_milliseconds(125);

	if (c->mine_count != 0 || c->mine == 1)
		return 1;
	else{
		int i, j;
		int count = 0;
		for (i = 1; i >= -1; i--)
			for (j = 1; j >= -1; j--)
				if ((c->x_pos + i >= 0 && c->x_pos + i < g->x_size) && (c->y_pos + j >= 0 && c->y_pos + j < g->y_size))
					if (c->x_pos + i != c->x_pos || c->y_pos + j != c->y_pos)
						count += uncover(g, &g->cells[c->x_pos + i][c->y_pos + j]);

		return count;
	}
	
	return 0;
}