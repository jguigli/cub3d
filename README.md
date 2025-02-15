# Cub3D

Cub3D is a 3D game engine inspired by the classic Wolfenstein 3D. It uses raycasting to render a 3D environment from a 2D map.

## Table of Contents

- [Features](#features)
- [Requirements](#requirements)
- [Setup](#setup)
- [Usage](#usage)
- [Contributing](#contributing)

## Features

- Real-time 3D rendering using raycasting
- Texture mapping for walls
- Basic player movement and interaction
- Minimap display (bonus feature)

## Requirements

- A Unix-like operating system (Linux, macOS)
- GCC or Clang compiler
- Make
- X11 libraries (for Linux)
- MinilibX library

## Setup

1. **Clone the repository:**

   ```bash
   git clone https://github.com/jguigli/cub3d.git
   cd cub3d
   ```

2. **Install dependencies:**

   Ensure you have the necessary libraries installed. On Ubuntu, you can use:

   ```bash
   sudo apt-get install libx11-dev libxext-dev
   ```

3. **Build the project:**

   Run the following command to compile the project:

   ```bash
   make
   ```

   For the bonus version, use:

   ```bash
   make bonus
   ```

## Usage

1. **Run the game:**

   After building, you can start the game with:

   ```bash
   ./cub3d maps/map.cub
   ```

   For the bonus version, use:

   ```bash
   ./cub3d_bonus maps/map.cub
   ```

2. **Controls:**

   - `W`: Move forward
   - `S`: Move backward
   - `A`: Move left
   - `D`: Move right
   - Arrow keys: Rotate view
   - `ESC`: Exit the game

