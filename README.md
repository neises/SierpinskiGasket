# SierpinskiGasket
Simple App which draws the Sierpinski Gasket

The Sierpinski Gasket is an Object which can be definded randomly. This is an Example how it can be done using OpenGL. Suppose that
we start with three points in space. As long as those points are not collinear, they define a unique triangle and of course a unique plane.
We assume that our plane is z = 0. 


# Pseudo Algorithm (used from Computer Graphics Script @ Fernuni Hagen)
1. Pick an initial point **p = (x,y,0)** (inside the triangle);
2. Use a random select vertices from the given points
3. Find the point **q** halfway between **p** and the randomly selected vertex
4. Display **q**
5. Replace **p** with **q**
6. Return to step **2**.



