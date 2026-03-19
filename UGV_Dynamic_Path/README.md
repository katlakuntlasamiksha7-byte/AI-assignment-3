# UGV Navigation with Dynamic Obstacles using A* Algorithm

## Introduction

This program is about finding a path for a UGV (Unmanned Ground Vehicle) from a starting point to a goal point in a grid. The path is calculated using the A* algorithm. The grid also has obstacles, and some of them can appear while the vehicle is moving, so the path may need to be recalculated.

## Problem Description

The goal is to move from one point to another while avoiding obstacles. Since obstacles can change during movement, the program needs to find a new path whenever the current path is blocked. The A* algorithm is used because it gives an efficient shortest path.

## Data Handling

The program creates a 70 × 70 grid. Obstacles are added randomly based on the level selected by the user (low, medium, or high). More obstacles can also appear during the movement.

## Graph Representation

The grid is stored as a 2D array.
0 represents a free cell and 1 represents an obstacle.
The movement is allowed in four directions: up, down, left, and right.

## Algorithm Explanation

The A* algorithm works by calculating a cost for each position.
It adds the distance already travelled and an estimated distance to the goal.
At each step, it chooses the position with the smallest cost.
If a shorter path is found, it updates the path.
If a new obstacle appears, it recalculates the path from the current position.

## Implementation Details

The program is written in C.
It uses standard libraries like stdio.h, stdlib.h, and time.h.
Random functions are used to generate obstacles.
Instead of a priority queue, a simple method is used to select the next node.

## How to Run

Compile the program using:
gcc ugv_dynamicpath.c -o ugv

Run the program using:
./ugv

## Program Flow

First, the grid is generated with obstacles.
Then the user selects the obstacle density.
The start point is (0,0) and the goal is (69,69).
The program finds a path using A*.
While moving, new obstacles may appear.
If the path is blocked, it recalculates.
Finally, it prints the result.

## Sample Input

Choose density: 1.Low 2.Medium 3.High : 2

## Sample Output

UGV Navigation with Dynamic Obstacles
Mission Success: 1
Nodes Expanded: 3500
Replans: 5

## Applications

This can be used in robotics, navigation systems, games, and path planning problems.

## Conclusion

This program shows how the A* algorithm can be used to find paths even when the environment changes during movement.
