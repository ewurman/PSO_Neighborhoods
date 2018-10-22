# PSO_Neighborhoods
This project experiments with different Neighborhood topologies on the effectiveness of a Particle Swarm optimization algorithm

To run the project, compile main.cpp like so,
```g++ main.cpp -o pso```
and run with the following arguments in order:
```./pso <topology> <swarm_size> <iterations> <function> <dimensions>```

The topologies used are (gl, ri, vn, ra) for Global, Ring, Von Neumann and Random neighborhoods.

The posible functions are (rok, ack, ras) for Rosenbrock, Ackley, and Rastrigin functions.
