# fdf - Wireframe Model Viewer

## Overview
The **fdf** project is a basic computer graphics project aimed at visualizing 3D landscapes through wireframe models. The project focuses on generating an isometric view of a landscape using data stored in `.fdf` files.

## Features
- Rendering a wireframe model of a 3D landscape using an isometric projection.
- Clean window management: switch between windows, minimize, and close smoothly.
- Parsing map data from `.fdf` files representing the landscape's x, y, and z coordinates.
- Smooth exit handling: press `ESC` or click the window's close button to exit the program.

## Usage
### Compilation
To compile the project, first you'll need the **MiniLibx Library**, you can download it [here](https://github.com/42Paris/minilibx-linux), then run:
```bash
make
```

### Running the Program
To view a wireframe model, pass a valid `.fdf` file as an argument:
``` bash
./fdf <filename.fdf>
```

#### Example `.fdf` File
``` text
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
```

Each number represents a point in space:

- Horizontal position → X-axis.
- Vertical position → Y-axis.
- Value → Altitude (Z-axis).
