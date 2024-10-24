# Space Program Management System

A comprehensive C++ program for managing space missions, vehicles, and personnel. This system simulates the management of various space-related entities including rockets, astronauts, satellites, and the International Space Station (ISS).

## Features

### 1. Vehicle Management
- **Rockets**
  - Create and manage rocket specifications
  - Track fuel levels, dimensions, and mission parameters
  - Support for multiple rocket configurations
  - Operator overloading for comparison and basic operations

- **Space Shuttles**
  - Manage reusable space vehicles
  - Track passenger capacity
  - Monitor reusability status

- **Spacecraft**
  - Advanced space vehicle management
  - Multiple inheritance implementation
  - Propulsion system tracking
  - Engine integration

- **Rovers**
  - Specialized space exploration vehicles
  - Track operational lifespan in Sols
  - Mission-specific configurations

### 2. Personnel Management
- **Astronauts**
  - Comprehensive astronaut profile management
  - Track experience and mission history
  - Monitor training hours
  - Age and qualification verification

### 3. Mission Infrastructure
- **Satellites**
  - Satellite deployment and tracking
  - Orbit management
  - Mission-specific configurations

- **ISS Management**
  - Real-time status monitoring
  - Resource management (oxygen, water, food)
  - Crew capacity tracking
  - Docking system management
  - Spacecraft docking/undocking operations

### 4. Mission Control
- **Mission Planning**
  - Mission creation and management
  - Resource allocation
  - Launch sequence management

- **Logging System**
  - Comprehensive mission logging
  - Critical event tracking
  - Issue and vulnerability management

## Technical Features

### Object-Oriented Design
- Inheritance (single and multiple)
- Polymorphism
- Encapsulation
- Friend functions
- Operator overloading
- Virtual functions

### Memory Management
- Dynamic memory allocation
- Proper memory deallocation
- Array management

### Error Handling
- Input validation
- Status checking
- Error logging

## Class Structure

```
SpaceVehicle (Abstract)
├── Rockets
│   ├── SpaceShuttle
│   └── ISS
├── Spacecraft
│   └── Rover
└── Engine

Additional Classes:
- Astronauts
- Satellites
- MissionControl
- MissionLogs
```

## Getting Started

### Prerequisites
- C++ compiler (C++11 or later)
- Basic understanding of space mission concepts

### Compilation
```bash
g++ main.cpp -o space_program
```

### Running the Program
```bash
./space_program
```

## Usage

The program provides a menu-driven interface with the following main options:
1. Manage Rockets
2. Manage Astronauts
3. Manage Satellites
4. Manage ISS
5. Advanced Vehicle Management
   - Space Shuttles
   - Spacecrafts
   - Rovers
   - Engines
6. Exit

Each management section provides options to:
- Add new entities
- View existing entities
- Modify configurations
- Monitor status

## Code Examples

### Creating a New Rocket
```cpp
Rockets r1(311, 60.0, 100.0, 9.0, "Falcon", "Cape Canaveral", "Mars");
```

### Managing ISS
```cpp
ISS iss;
iss.displayStatus();
iss.updateResourceStatus();
iss.addCrewMember();
```

## Future Improvements

1. **Database Integration**
   - Persistent storage for mission data
   - Historical mission tracking

2. **Advanced Simulation Features**
   - Real-time mission simulation
   - Failure scenario handling
   - Emergency procedure simulation

3. **User Interface**
   - Graphical user interface
   - Real-time data visualization
   - Mission control dashboard

4. **Network Capabilities**
   - Multi-user support
   - Remote mission control
   - Real-time collaboration

5. **Additional Features**
   - Weather monitoring
   - Launch window calculations
   - Orbital mechanics calculations
   - Communication system simulation

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request. For major changes, please open an issue first to discuss what you would like to change.

## License

This project is licensed under the GNU GENERAL PUBLIC LICENSE - see the LICENSE file for details.

## Author

Adrino Rosario James

## Notes

This is an educational project designed to demonstrate object-oriented programming concepts in C++. While it simulates space mission management, it is not intended for actual space mission operations.
