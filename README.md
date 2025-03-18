# Fract'ol - 42 School Project

## Table of Contents
1. [Introduction](#introduction)
2. [Features](#features)
3. [Installation](#installation)
4. [Usage](#usage)
5. [Controls](#controls)
6. [Examples](#examples)
7. [Technical Details](#technical-details)
8. [Contributing](#contributing)
9. [License](#license)

---

## Introduction
Fract'ol is a 42 School project that generates and renders beautiful fractals using the **MiniLibX** library. The program supports the **Mandelbrot** and **Julia** sets, allowing users to explore the infinite complexity of fractals through zooming and panning.

---

## Features
- **Fractals Supported**:
  - Mandelbrot Set
  - Julia Set (with custom parameters)
- **Interactive Controls**:
  - Zoom in/out with the mouse wheel.
  - Pan the view using arrow keys.
  - Close the program with `ESC` or the window's close button.
- **Smooth Rendering**:
  - Real-time updates for zooming and panning.
- **Color Gradients**:
  - Points are colored based on how quickly they escape the fractal formula.

---

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/fractol.git
   cd fractol
   ```

    Compile the program:
    bash
    Copy

    make

Usage

Run the program with one of the following commands:

  Mandelbrot Set:
  ```bash
    ./fractol mandelbrot
  ```

  Julia Set (with custom parameters):
  ```bash
    ./fractol julia -0.8 0.4
  ```

Controls

  Zoom:

      Scroll up to zoom in.

      Scroll down to zoom out.

  Pan:

      Use the arrow keys to move the view.

  Exit:

      Press ESC or click the window's close button.

## Examples
  Mandelbrot set
  ![Mandelbrot Set](https://upload.wikimedia.org/wikipedia/commons/thumb/2/21/Mandel_zoom_00_mandelbrot_set.jpg/1200px-Mandel_zoom_00_mandelbrot_set.jpg)
  Julia set
  ![Julia Set Example](https://upload.wikimedia.org/wikipedia/commons/thumb/d/d9/Julia_set%2C_plotted_with_Matplotlib.svg/1200px-Julia_set%2C_plotted_with_Matplotlib.svg.png)
## Technical Details

  Language: C

  Library: MiniLibX (42's custom graphics library)

  Fractal Formulas:

  Mandelbrot: zn+1=zn2+czn+1​=zn2​+c

  Julia: zn+1=zn2+czn+1​=zn2​+c (with fixed cc)

  Color Mapping:

  Points are colored based on the number of iterations before escaping.
