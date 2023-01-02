# xonix2d

![Download..](description.PNG)

## 1. Description
- Set 1. A boundary in the middle
- Set 2. Three balls inside the boundary, continuously moving
      - 2-1. When three balls meet the boundary, bounce off
- Set 3. Balls above the boundary
      - 3-1. Balls above the boundary : can be moved by a keyboard
      - 3-2. Balls above the boundary : can enter the boundary but not go outside the boundary

- If a ball that enters the boundary **moves in the boundary**, a trajectory is created.
- If a ball entering the boundary **moves in the boundary and returns to the boundary**, the path of the ball moving in the boundary is included in the boundary.
- If the trajectory of the point entering the boundary meets the ball that moves inside the boundary before it is included in the boundary, game ends.


## 2. Created Objects
- Boundary
  - variable : vertex
  - function
      - Is the given position above the boundary?
      - 
  - 
- A Ball which moves inside the boundary
- A Ball which moves outside the boundary
