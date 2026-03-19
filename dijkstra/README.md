# Dijkstra’s Algorithm on Indian Cities using CSV Data

## Introduction

This program implements Dijkstra’s Algorithm to calculate the shortest distance from a selected starting city to all other cities. The graph is created using road distance data stored in a CSV file and is implemented using the C programming language.



## Problem Description

In a graph where each connection has a different cost (distance), the objective is to find the minimum distance from one city to all other cities. Dijkstra’s Algorithm is used because it efficiently solves shortest path problems for graphs with non-negative distances.

## Data Handling

The program reads input from a CSV file named "india_roads.csv". Each row contains a source city, a destination city, and the distance between them. The graph is treated as undirected, meaning travel is possible in both directions.

---

## Graph Representation

The graph is represented using an adjacency matrix. Cities are stored in an array, and distances between cities are stored in a 2D matrix.

---

## Algorithm Explanation

The algorithm starts by assigning an initial distance of infinity to all cities except the starting city, which is set to zero. It then repeatedly selects the unvisited city with the smallest distance and updates the distances of its neighboring cities if a shorter path is found. This process continues until all cities are visited.

---

## Implementation Details

The program is written in C.
Standard libraries such as stdio.h, stdlib.h, string.h, and limits.h are used.
File handling is used to read the CSV data and build the graph.
The algorithm is implemented using arrays and loops.

---

## How to Run

Make sure a C compiler (like GCC) is installed on your system.
Place the file "india_roads.csv" in the same directory as the program.

Compile the program using:
gcc dijkstra.c -o dijkstra

Run the program using:
./dijkstra

---

## Program Flow

The program loads the graph from the CSV file
It asks the user to enter a starting city
It checks whether the city exists in the dataset
It computes the shortest distances to all other cities
It displays the results

---

## Sample Input

Enter starting city: Delhi

---

## Sample Output

Shortest distances:

Delhi : 0
Mumbai : 1400
Jaipur : 300
Kolkata : 1500
Hyderabad : 1500

---

## Applications

This implementation can be used in navigation systems, route planning, logistics optimization, and network routing.

---

## Conclusion

This program demonstrates how Dijkstra’s Algorithm can be applied using C language and CSV data to efficiently compute shortest distances from a single source to all other cities in a graph.

---

## Author

Samiksha
