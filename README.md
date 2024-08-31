# Maze Generator in C

A simple maze generation program written in C that uses depth-first search (DFS) and randomized neighbor selection to generate a maze. The program includes logging functionality to help debug and trace the execution of the maze generation process.

## Project Description

This project implements a maze generator using a depth-first search algorithm. The algorithm starts at a random cell in a grid, visits neighboring cells in a randomized order, and carves paths between them until all cells have been visited. The program also includes macros for logging different levels of messages (DEBUG, INFO, WARN, ERROR) to assist with debugging and monitoring.

## Features

- **Maze Generation**: Creates a maze using depth-first search with randomized neighbor selection.
- **Logging**: Provides detailed logging at various levels (DEBUG, INFO, WARN, ERROR) to help trace the maze generation process and catch potential issues.
- **Customizable**: Easily configurable maze size and logging level.

## Prerequisites

To compile and run this program, you need:

- A C compiler (e.g., GCC, Clang)
- Standard C library (libc)

## Installation

1. **Clone the repository:**

   ```bash
   git clone https://github.com/yourusername/maze-generator-c.git
   cd maze-generator-c
   ```

2. **Compile and run the generator**

   ```bash
   gcc *.c && ./a.out
   ```

## Example Maze ( 7 x 7 grid )

┌──┐┌──────────────┐┌──────┐ 
│  ││  ┌┐  ┌────┐  ││  ┌───┘ 
│  ││  ││  └───┐│  ││  └───┐ 
│  │└──┘│  ┌┐  ││  │└───┐  │ 
│  └───┐│  ││  ││  └────┘  │ 
└───┐  │└──┘│  │└───────┐  │ 
┌──┐│  └────┘  │┌───────┘  │ 
│  │└──────────┘│  ┌───────┘ 
│  └───────────┐│  │┌──────┐ 
│  ┌┐  ┌───────┘│  ││  ┌┐  │ 
│  ││  │┌──────┐│  └┘  ││  │ 
│  ││  ││  ┌┐  │└──────┘│  │ 
│  ││  └┘  ││  └────────┘  │ 
└──┘└──────┘└──────────────┘
