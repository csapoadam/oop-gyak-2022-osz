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
	void printChildren() {
		for (GraphNode child : children) {
			std::cout << ", " << child.getId();
		}
	}
};


class DirectedGraph {
	std::vector<GraphNode> nodes;
public:
	DirectedGraph(const std::string& rootId) {
		nodes.push_back(GraphNode(rootId));
	}
	void addChild(
		const std::string& parentId,
		const std::string& childId) {

		bool wasParentFound = false;

		// referenciat kell lekerni, kulonben MASOLAT lesz a node
		// igy a masolathoz adnank hozza a gyermeket
		for (GraphNode& node : nodes) {
			if (node.getId() == parentId) {
				node.addChild(GraphNode(childId));
				wasParentFound = true;
			}
		}

		// mikozben iteralunk a nodes vektoron, nem szabad modositani!
		// (ki tudja, hogyan dobja el kozben az agyat a runtime
		if (wasParentFound)
			nodes.push_back(GraphNode(childId));
	
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

	void printNodesWithChildren() {
		std::cout << "Nodes in graph (with children): " << std::endl;
		for (GraphNode node : nodes) {
			std::cout << node.getId();
			// most a gyermekeit is kiiratjuk, ha van:
			node.printChildren();
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
};