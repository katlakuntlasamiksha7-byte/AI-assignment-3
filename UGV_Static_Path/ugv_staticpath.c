#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 70
#define MAX_NODES (GRID_SIZE * GRID_SIZE)

typedef struct {
    int x, y;
    int g, h, f;
    int parent_x, parent_y;
} Node;

int grid[GRID_SIZE][GRID_SIZE];

int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void generate_grid(float density) {
    int obstacle_count = GRID_SIZE * GRID_SIZE * density;

    for (int i = 0; i < GRID_SIZE; i++)
        for (int j = 0; j < GRID_SIZE; j++)
            grid[i][j] = 0;

    for (int i = 0; i < obstacle_count; i++) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;
        grid[x][y] = 1;
    }
}

int is_valid(int x, int y) {
    return (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE);
}

int astar(int sx, int sy, int gx, int gy, Node path[], int *path_len, int *nodes_expanded) {
    int visited[GRID_SIZE][GRID_SIZE] = {0};
    Node open[MAX_NODES];
    int open_size = 0;

    Node start = {sx, sy, 0, heuristic(sx, sy, gx, gy), 0, -1, -1};
    start.f = start.g + start.h;
    open[open_size++] = start;

    Node came_from[GRID_SIZE][GRID_SIZE];

    while (open_size > 0) {
        int best = 0;
        for (int i = 1; i < open_size; i++) {
            if (open[i].f < open[best].f)
                best = i;
        }

        Node current = open[best];
        open[best] = open[--open_size];

        if (current.x == gx && current.y == gy) {
            int len = 0;
            Node temp = current;

            while (temp.parent_x != -1) {
                path[len++] = temp;
                temp = came_from[temp.parent_x][temp.parent_y];
            }
            path[len++] = temp;

            for (int i = 0; i < len / 2; i++) {
                Node t = path[i];
                path[i] = path[len - i - 1];
                path[len - i - 1] = t;
            }

            *path_len = len;
            return 1;
        }

        visited[current.x][current.y] = 1;
        (*nodes_expanded)++;

        int moves[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        for (int i = 0; i < 4; i++) {
            int nx = current.x + moves[i][0];
            int ny = current.y + moves[i][1];

            if (!is_valid(nx, ny) || grid[nx][ny] == 1 || visited[nx][ny])
                continue;

            Node neighbor;
            neighbor.x = nx;
            neighbor.y = ny;
            neighbor.g = current.g + 1;
            neighbor.h = heuristic(nx, ny, gx, gy);
            neighbor.f = neighbor.g + neighbor.h;
            neighbor.parent_x = current.x;
            neighbor.parent_y = current.y;

            came_from[nx][ny] = current;
            open[open_size++] = neighbor;
        }
    }

    return 0;
}

int main() {
    srand(time(NULL));

    printf("UGV Path Planning with Static Obstacles\n");

    int choice;
    printf("Choose density: 1.Low 2.Medium 3.High : ");
    scanf("%d", &choice);

    float density;
    if (choice == 1) density = 0.1;
    else if (choice == 2) density = 0.2;
    else if (choice == 3) density = 0.3;
    else {
        printf("Invalid choice\n");
        return 0;
    }

    generate_grid(density);

    int sx = 0, sy = 0;
    int gx = 69, gy = 69;

    grid[sx][sy] = 0;
    grid[gx][gy] = 0;

    Node path[MAX_NODES];
    int path_len = 0;
    int nodes_expanded = 0;

    int success = astar(sx, sy, gx, gy, path, &path_len, &nodes_expanded);

    printf("\nStart: (0,0)\n");
    printf("Goal: (69,69)\n");

    if (!success) {
        printf("No path found\n");
        return 0;
    }

    printf("Path Length: %d\n", path_len);
    printf("Nodes Expanded: %d\n", nodes_expanded);

    printf("Path:\n");
    for (int i = 0; i < path_len; i++) {
        printf("(%d,%d) ", path[i].x, path[i].y);
    }

    printf("\n");

    return 0;
}
