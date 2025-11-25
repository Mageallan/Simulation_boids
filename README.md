# Simulation_boids
The Boids model (Craig Reynolds, 1986) simulates collective behaviors inspired by the flight of birds in flocksor the movement of fish in schools. Each agent (“boid”) does not make global decisions but follows simple local rules, applied according to its close neighbors.

#Project structure

|__ \model
|   |__ Boid.h/cpp
|   |__ Flock.h/cpp
|   |__ Simulation.h/cpp
|   |__ Vec2<T>.h/cpp
|   |__ Rule.h/cpp
|   |__ Settings.h/cpp
|
|__ \controller
|   |__ ParametersController.h/cpp
|
|__ \view
|   |__ ParameterView.h/cpp
|   |__ BoidsView.h/cpp
\    
