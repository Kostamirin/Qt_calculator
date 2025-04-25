# Qt Calculator with Progression Functions

A modern desktop calculator application built with Qt that combines standard arithmetic operations with specialized progression calculations. The application provides an intuitive graphical interface for basic calculations and advanced mathematical sequence computations.

This calculator application extends beyond basic arithmetic by offering dedicated tools for working with arithmetic and geometric progressions. It features a clean, modern interface with a standard calculator layout plus additional functionality accessed through a secondary window. The application is designed for both casual users needing quick calculations and students or professionals working with mathematical sequences.

## Repository Structure
```
.
├── calculatorwindow.cpp/h     # Main calculator window implementation
├── head.cpp/h                 # Core calculation engine
├── main.cpp                   # Application entry point
├── Progressions/             # Progression calculation components
│   ├── arithmetic_progression.cpp/h    # Arithmetic progression calculator
│   ├── geometric_progression.cpp/h     # Geometric progression calculator
│   └── secondwindow.cpp/h             # Secondary window for progression options
├── styles/                   # UI styling resources
│   ├── calculator.qss        # Qt stylesheet for calculator appearance
│   └── resources.qrc        # Qt resource collection file
└── CMakeLists.txt           # CMake build configuration
```

## Usage Instructions
### Prerequisites
- Qt6 development libraries (Core, Gui, Widgets)
- CMake 3.16 or higher
- C++ compiler with C++20 support
- Build tools (Make or Ninja)

### Installation

#### Linux/Debian
```bash
# Install required packages
sudo apt-get update
sudo apt-get install qt6-base-dev cmake build-essential

# Build the project
mkdir build && cd build
cmake ..
make
```

#### macOS
```bash
# Install prerequisites using Homebrew
brew install qt6 cmake

# Build the project
mkdir build && cd build
cmake ..
make
```

#### Windows
```bash
# Install Qt6 using the official installer from qt.io
# Install CMake from cmake.org
# Using Command Prompt or PowerShell:
mkdir build
cd build
cmake -G "MinGW Makefiles" ..
mingw32-make
```

### Quick Start
1. Launch the application
2. For basic calculations:
   - Use number pad for input
   - Click operation buttons (+, -, *, /) for arithmetic operations
   - Press '=' to see the result
   - Use 'Cl' to clear

3. For progression calculations:
   - Click '2nd' to open the progression window
   - Choose between Arithmetic or Geometric progression
   - Enter known values in the fields
   - Click calculate to find missing values

### More Detailed Examples

#### Basic Calculator Usage
```
23 + 45 = 68
12 * 4 = 48
```

#### Arithmetic Progression
1. Enter first term (a₁)
2. Enter common difference (d)
3. Enter number of terms (n)
4. Application calculates:
   - Last term (aₙ)
   - Sum of terms

#### Geometric Progression
1. Enter first term (a₁)
2. Enter common ratio (r)
3. Enter number of terms (n)
4. Application calculates:
   - Last term (aₙ)
   - Sum of terms

### Troubleshooting

#### Common Issues
1. Calculator display shows "Error":
   - Check for division by zero
   - Verify expression has balanced parentheses
   - Clear the display and try again

2. Progression calculation fails:
   - Ensure at least three fields are filled
   - Check for valid numeric inputs
   - Avoid using zero as common ratio in geometric progression

#### Debug Mode
To enable debug output:
1. Run the application with --debug flag
2. Check console for Qt debug messages
3. Log files are stored in:
   - Linux: ~/.local/share/Qt_calculator/logs
   - Windows: %APPDATA%\Qt_calculator\logs
   - macOS: ~/Library/Logs/Qt_calculator

## Data Flow
The calculator processes user input through a chain of validation and calculation steps, ensuring accurate results while maintaining a responsive interface.

```ascii
[User Input] -> [Input Validation] -> [Expression Parsing]
      |                                      |
      v                                      v
[UI Updates] <- [Result Display] <- [Calculation Engine]
```

Key component interactions:
- User input is captured by CalculatorWindow class
- Input validation ensures proper mathematical syntax
- Expression parsing converts string input to computable form
- Calculation engine (head.cpp) processes the expression
- Results are formatted and displayed back to user
- Progression calculations are handled by dedicated classes
- Secondary window manages progression input/output flow
- Qt signals/slots handle communication between components