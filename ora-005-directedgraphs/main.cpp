#include "graphs.h"


int main() {
	DirectedGraph graph("root"); // gyokercsomopont neve: root
	graph.addChild("root", ".A"); // root-hoz hozzadjuk a .A nevu csomopontot
	graph.addChild("root", ".B");

	graph.addChild(".A", ".AA");
	graph.addChild(".A", ".AB");

	graph.addChild(".B", ".BA");
	graph.addChild(".B", ".BB");
	graph.addChild(".B", ".BC");
	
	graph.printBFS(); //szelessegi kereses: Breadth-First Search
	// "root", ".A", ".B", ".AA", ".AB", ".BA", ".BB", ".BC"

	graph.printDFS(); // melysegi kereses: Depth-First Search
	// "root", ".A", ".AA", ".AB", ".B", ".BA", ".BB", ".BC"
}