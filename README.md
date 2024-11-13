# Toupie_POOC

## Overview
**Toupie_POOC** is a C++ application designed to simulate and visualize the dynamics of spinning tops. The project employs object-oriented programming (OOP) principles to model various types of tops, such as simple cones and more complex structures, simulating their rotational motion and physical properties.

## Features
- **Object-Oriented Design**: Utilizes OOP to represent different types of tops with unique attributes and behaviors.
- **Numerical Integration**: Implements the Euler-Cromer integration method to solve equations governing the tops' motion.
- **Real-Time Visualization**: Provides an interactive graphical interface with Qt and OpenGL, rendering the tops' movements in real-time.
- **Customizable Parameters**: Allows users to modify physical parameters such as mass, radius, and angular velocity to observe different motion behaviors.

## Getting Started

### Prerequisites
- **C++ Compiler**: Ensure you have a C++11 compatible compiler.
- **Qt**: For GUI functionality.
- **OpenGL**: Required for rendering graphics.

### Installation
1. Clone this repository:
   git clone https://github.com/LeonDeligny/Toupie_POOC.git
   cd Toupie_POOC

2. Compile the project:
	•	With Qt Creator: Open the .pro file and build the project.
	•	With command line (if available):
    qmake
    make

3. Run the executable:
  ./toupie_pooc
   
## Usage
1. Launch the application to view a selection of predefined tops.
2. Use the GUI to interact with different types of tops, adjust parameters like mass, radius, and initial angular velocity.
3. Observe the effects of changes in real-time as the simulation updates.

## Project Structure
- **src/** : Source files for the simulation, including classes for different types of tops.
- **include/** : Header files defining classes and methods.
- **lib/** : Libraries for GUI and graphical rendering.

## Key Concepts
- **Euler-Cromer Method** : Used for numerical stability in the simulation of rotational dynamics.
- **Object-Oriented Design** : Separates top types as distinct classes, each encapsulating unique behaviors and properties.

## Future Improvements
1. Add support for additional numerical methods for increased simulation accuracy.
2. Expand GUI features for more detailed customization and control.
