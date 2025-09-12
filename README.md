Gravitational Simulation
========================

C++ simulation exercise for generating movement of bodies
across space using Newtonian physics. This is mostly an
exercise to improve my own C++ skills.

---


If you are reading this
-----------------------

I have not written this repository with other users in mind, yet, this is just a fun side-project.
There is no easy interface to use which
can set up the simulation for you. The main class is `System` which is hopefully self-documented
enough to be
used by anyone but otherwise just feel to reach out to me on GitHub or LinkedIn.

---


General Structure
-----------------

`Vector`: Class to hold `std::vector<double>` elements and string indicating coordinate system.

`Body`: Class to hold information about an body with mass, assumed spherical.

`System`: Main class, constructs multiple `Body` instances, calculates the sum of forces on each
body and updates its `Vector` attributes accordingly.

---


Running System
--------------
Once the `System` object has been initialised, the `forwardTick` method updates all `Body`
attributes
by the `tick_rate`. I've set this as `tick_rate = 86400` for the number of seconds in a day,
essentially moving
all bodies by one day per call of `forwardTick`.

Create a loop which calls `forwardTick` and store the attributes as done in `src/main.cpp`. I
usually save the attributes to a csv
and read it using Python(Pandas -> plot on Plotly).

---


Further updates
---------------

1. Implement a Matrix class from scratch, for fun(or pain whatever it ends up being), and move all
   physics calculations to Matrix
2. Implement an easy way to graph outputs, most likely using the Manim library in Python, although
   I've used Plotly for a quick sketch of trajectories on notebooks which I would recommend.
3. Add nearest-neighbour forces instead of system-wide forces, for large number of bodies I can
   forsee `System::updateForces` becoming very slow without this. Ideally if the Matrix class works
   then this should be a case of just trimming the Matrix.

---


A note on units
---------------
I finished my Physics studies in 2022 and I spent most of my time setting as many constants as I
could to 1.
Sadly for this repository I have decided to use units, and the general style can be found in
`include/gravity.h`. The main constant, `G`, is defined as $`km^{3} M_{*}^{-1} s^{-2}`$ where $
`M_{*}`$
is a solar mass, see https://en.wikipedia.org/wiki/Gravitational_constant. Other constants are
defined around this, and it is important when picking a `tick_rate`.