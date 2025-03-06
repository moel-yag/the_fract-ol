Fract-ol
Introduction

Fract-ol is a project from the 42 School program that focuses on creating fractals and visualizing them through graphical software. The goal of this project is to create and display different fractals, like the Mandelbrot and Julia sets, using graphics programming techniques. This project challenges you to dive deep into algorithms, mathematical concepts, and pixel-based image rendering.
Features

    Display Mandelbrot and Julia fractals.
    Interactive controls to zoom, move, and adjust the iterations of the fractals.
    Color gradient for fractal generation.
    Efficient algorithm implementation for real-time rendering.

Requirements

    C programming language (or another language depending on the version).
    MinilibX graphics library (or equivalent, depending on your project setup).
    Makefile to compile the project.

Setup
Installation

    Clone the repository to your local machine:

git clone https://github.com/your-username/fract-ol.git
cd fract-ol

Install MinilibX or any required libraries if they are not already installed.

Compile the project using the provided Makefile:

make

Once compiled, you can run the fractal visualization program:

    ./fract-ol

Dependencies

    MinilibX graphics library
    X11 development libraries (for Linux)
    Any additional dependencies specific to your project setup

Usage

    Mandelbrot Set: After running the program, the Mandelbrot set will be displayed. You can use the arrow keys to move around the set and the + and - keys to zoom in or out.

    Julia Set: Press a specific key (like J or H) to toggle between different Julia set parameters and colors.

    Adjust the number of iterations for greater detail using the I key.

    To exit the program, simply press the Esc key.

Controls

    Arrow keys: Move the fractal view.
    + / -: Zoom in or out.
    I: Increase or decrease iterations for more detail.
    J: Switch to Julia set view.
    Esc: Exit the program.

Algorithms
Mandelbrot Set

The Mandelbrot set is computed using the formula:
    zn+1=zn2+c
    zn+1​=zn2​+c

where zz and cc are complex numbers. The program checks if the sequence tends to infinity or remains bounded.
Julia Set

The Julia set is generated using a similar algorithm but with a fixed complex number cc. The set's appearance changes based on the values of cc.
