


int main() {
	DirectedGraph graph("root"); // gyokercsomopont neve: root
	graph.addChild("root", ".A"); // root-hoz hozzadjuk a .A nevu csomopontot
	graph.addChild("root", ".B");

	graph.addChild(".A", ".AA");
	graph.addChild(".A", ".AB");

	graph.addChild(".B". ".BA");
	graph.addChild(".B", ".BB");
	graph.addChild(".B", ".BC");

}