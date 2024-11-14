Social Network Analysis

Overview

This project, Social Network Graph Analysis, is a C++ application designed to analyze and visualize social network graphs. It takes social network data as input, processes it to understand the relationships and structure within the network, and generates an output graph image for visualization.

Features
	•	Graph Construction: Builds a social network graph based on given input data.
	•	Analysis Tools: Provides functions to analyze nodes, edges, and the connectivity of the graph.
	•	Visualization: Generates a graphical representation of the network in PNG format.

Prerequisites
	•	C++ Compiler: Make sure g++ is installed.
	•	Graphviz: Install Graphviz for generating graphical representations from .dot files.

Building and Running the Project

Follow these steps to build and run the project:

Step 1: Clean Previous Builds

Remove any previous build files.


    rm -rf ./build
Step 2: Create a New Build Directory

     mkdir build
     cd build
Step 3: Compile the Source Code

Compile all .cpp files in the src directory and link them into an executable called SocialNetworkGraph.

    g++ ../src/*.cpp -o SocialNetworkGraph -I ../include
Step 4: Run the Application

Execute the compiled program to perform social network analysis.

    ./SocialNetworkGraph
    
Step 5: Generate Graph Image

After running the program, generate a visual representation of the graph in PNG format using Graphviz.

    dot -Tpng graph.dot -o graph.png
    
Output
	•	graph.png: A PNG image file representing the social network graph, generated from the graph.dot file.

![graph](https://github.com/user-attachments/assets/1199a952-a0e0-4763-a1e4-0316b286bc2d)

Directory Structure
	•	src/: Contains the source code files.
	•	include/: Contains any header files used in the project.
	•	build/: The build directory where the compiled executable and other generated files will be stored.

    
    
    
    
    
