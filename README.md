# ProteinProjectv1

#### Note That This Project is being paused for development in the theory and writing research papers in the same topic as this project. Development will resume as soon as the theory is set, meanwhile follow https://github.com/SriGanesh01/PRoteinProjectDemoUnityv1 for further development in this. The mentioned repo is being used as a placeholder to write the papers. Once done with it, it will be re-written in this repo

Our Project consists of multiple intricate and interrelated concepts combined to be a single application. 

Overview
We want to build a software which can generate the 3D structure of a protein as well as predict the 3D structure thereby trying to solve “The Protein Folding Problem”.

This consists of mainly three phases.

Phase One: Custom Visualization Engine
Phase Two: Building an Effective solution to “The Protein Folding Problem”.
Phase Three: Integrate both the above application and build the Moodboard.

Phase 1:

We aim to achieve a 3D engine to show a 3D structure of a complexly structured protein. We would do this by first parsing through the existing pdb files and getting the coordinates data. With that, we assign colors to different atoms and part by part, we build the entire 3d structure. Our inspiration for this is Pymol. But PyMol has many unanswered problems, starting with its User Interface. It is built with efficiency in mind but not user friendly. We want to fix that. Another problem it has is that it has one API to access all the data, we want to split it up for easier and faster access. Building a custom Engine will also help us add much higher customization onto the later phases of our plan.

Software to be used:
For VS
CMake (64 bit)
GLFW (Source Package)

For VS Code Here 
GLFW
GLAD

OpenGL


Python

Phase 2:

In this phase of our project, we aim to find a better solution to the protein folding problem. This problem has been in the research for years and we want to contribute to it. 

Software to be used:
Python

Phase 3:
This is the actual product we would be shipping. The above two pages are setups for this final product. In this phase, we would be building the final product. Our product is an application which can visualize and predict the 3D structure of any given protein. These can be achieved by integrating the above two phase’s results and integrating them to be a single product. The main focus of this application will be the custom mood-board. In This custom board, the users will be able to use a variety of functionalities starting with:

Being able to change the structure of the protein in the editor and get the respective protein sequence as well as the coordinates data in the form of a .pbd file.
Being able to give a non existing protein sequence, verify if it is possible for such a component to exist as well as visualize the 3D structure, if such an protein can exist.

We believe that such a product could help people come up with cures faster than conventional methods.

Software to be used:
Nil
