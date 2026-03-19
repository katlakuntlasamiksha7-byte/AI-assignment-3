#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX 100

int graph[MAX][MAX];
char cities[MAX][50];
int n = 0;


int getCityIndex(char name[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(cities[i], name) == 0)
            return i;
    }
    strcpy(cities[n], name);
    return n++;
}


void loadGraph(char filename[]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file\n");
        exit(1);
    }

    char src[50], dest[50];
    int dist;

  
    fscanf(file, "%s", src);

    while (fscanf(file, "%[^,],%[^,],%d\n", src, dest, &dist) != EOF) {
        int i = getCityIndex(src);
        int j = getCityIndex(dest);

        graph[i][j] = dist;
        graph[j][i] = dist;
    }

    fclose(file);
}


void dijkstra(int start) {
    int dist[MAX], visited[MAX];

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int min = INT_MAX, u = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

   
    printf("\nShortest distances:\n");
    for (int i = 0; i < n; i++) {
        printf("%s : %d\n", cities[i], dist[i]);
    }
}


int main() {
    loadGraph("Distances.csv");

    char startCity[50];
    printf("Enter starting city: ");
    scanf("%s", startCity);

    int startIndex = -1;
    for (int i = 0; i < n; i++) {
        if (strcmp(cities[i], startCity) == 0) {
            startIndex = i;
            break;
        }
    }

    if (startIndex == -1) {
        printf("City not found!\n");
    } else {
        dijkstra(startIndex);
    }

    return 0;
}
