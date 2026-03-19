# UGV Path Planning with Static Obstacles using A* Algorithm

## Introduction

This program is about finding a path for a UGV (Unmanned Ground Vehicle) from a starting point to a goal point in a grid. The path is calculated using the A* algorithm. The grid contains obstacles, but they do not change during execution.

## Problem Description

The aim is to move from the start position to the goal position while avoiding obstacles. Since the obstacles are fixed, the program calculates the shortest possible path once using the A* algorithm.

## Data Handling

The program creates a 70 × 70 grid. Obstacles are placed randomly based on the density selected by the user (low, medium, or high). Once created, the grid remains unchanged.

## Graph Representation

The grid is stored as a 2D array.
0 represents a free cell and 1 represents an obstacle.
The UGV can move in four directions: up, down, left, and right.

## Algorithm Explanation

The A* algorithm calculates a cost for each position using two values.
One is the distance travelled so far, and the other is an estimate of the distance to the goal.
At each step, the position with the smallest cost is selected.
This continues until the goal is reached.

## Implementation Details

The program is written in C.
It uses standard libraries like stdio.h, stdlib.h, and time.h.
Random numbers are used to generate obstacles.
A simple method is used to select the next node instead of a priority queue.

## How to Run

Compile the program using:
gcc ugv_staticpath.c -o ugv_static

Run the program using:
./ugv_static

## Program Flow

The grid is generated with obstacles
The user selects the obstacle density
The start point is (0,0) and the goal is (69,69)
The program calculates the path using A*
It prints the path length and nodes explored

## Sample Input

Choose density: 1.Low 2.Medium 3.High : 1

## Sample Output

UGV Path Planning with Static Obstacles
Path Length: 120
Nodes Expanded: 2500

## Applications

This can be used in robotics, path planning, games, and navigation systems where obstacles do not change.

## Conclusion

This program shows how the A* algorithm can be used to find the shortest path in a fixed environment.
