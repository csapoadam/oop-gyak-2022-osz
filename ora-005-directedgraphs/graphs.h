#pragma once
#include <string>
#include <vector>
#include <iostream>

class GraphNode {
	std::string id; // egyedi kell, hogy legyen (1 grafon belul)
	//... ezert id es nem name

	// jobb volna GraphNode*-t hasznalni vagy GraphNode&-et
	// mert ezek ugyanazok a GraphNode-ok amik magaban a grafban
	// is benne vannak!
	// most viszont minden csomoponthoz tobb ugyanolyan nevu
	// peldany tartozik:
	// 1x szerepel a DirectedGraph.nodes vectorban
	// minden szulojeben 1x szerepel
	std::vector<GraphNode> children;
public:
	GraphNode(const std::string& id) : id(id) {}
	// referencia, hogy ne kelljen masolgatni
	// const ref, hogy ne lehessen modositani: .getId() = "hahhaha"
	const std::string& getId() { return id; }
	void addChild(GraphNode ch) { children.push_back(ch); }
};


class DirectedGraph {
	std::vector<GraphNode> nodes;
public:
	DirectedGraph(const std::string& rootName) {
		nodes.push_back(GraphNode(rootName));
	}
	void addChild(
		const std::string& parentName,
		const std::string& childName) {

		bool wasParentFound = false;

		for (GraphNode node : nodes) {
			if (node.getId() == parentName) {
				node.addChild(GraphNode(childName));
				wasParentFound = true;
			}
		}

		// mikozben iteralunk a nodes vektoron, nem szabad modositani!
		// (ki tudja, hogyan dobja el kozben az agyat a runtime
		if (wasParentFound)
			nodes.push_back(GraphNode(childName));
	
	}
	void printNodes() {
		std::cout << "Nodes in graph: ";
		bool isFirst = true;
		for (GraphNode node : nodes) {
			if (isFirst) {
				std::cout << node.getId();
				isFirst = false;
			}
			else {
				std::cout << ", " << node.getId();
			}
		}
		std::cout << std::endl;
	}
};