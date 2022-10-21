#pragma once
#include <string>
#include <vector>
#include <deque>
#include <iostream>

class GraphNode {
	std::string id; // egyedi kell, hogy legyen (1 grafon belul)
	//... ezert id es nem name

	std::vector<GraphNode*> children;
public:
	GraphNode(const std::string& id) : id(id) {}
	const std::string& getId() { return id; }
	void addChild(GraphNode* ch) { children.push_back(ch); }
	std::vector<GraphNode*> getChildren() { return children; }
	void printChildren() {
		for (GraphNode* child : children) {
			std::cout << ", " << child->getId();
		}
	}
};


class DirectedGraph {
	std::vector<GraphNode*> nodes;
public:
	DirectedGraph(const std::string& rootId) {
		nodes.push_back(new GraphNode(rootId));
	}
	~DirectedGraph() {
		for (GraphNode* nd : nodes) {
			delete nd;
		}
	}
	void addChild(
		const std::string& parentId,
		const std::string& childId) {

		GraphNode* newnode = nullptr;

		for (GraphNode* node : nodes) {
			if (node->getId() == parentId) {
				newnode = new GraphNode(childId);
				node->addChild(newnode);
			}
		}

		// mikozben iteralunk a nodes vektoron, nem szabad modositani!
		// (ki tudja, hogyan dobja el kozben az agyat a runtime
		if (newnode)
			nodes.push_back(newnode);
	
	}
	void printNodes() {
		std::cout << "Nodes in graph: ";
		bool isFirst = true;
		for (GraphNode* node : nodes) {
			if (isFirst) {
				std::cout << node->getId();
				isFirst = false;
			}
			else {
				std::cout << ", " << node->getId();
			}
		}
		std::cout << std::endl;
	}

	void printNodesWithChildren() {
		std::cout << "Nodes in graph (with children): " << std::endl;
		for (GraphNode* node : nodes) {
			std::cout << node->getId();
			// most a gyermekeit is kiiratjuk, ha van:
			node->printChildren();
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	void printBFS() {
		// Kezdetben a feldolgozando listaban csak a root van
		// mindig a lista ELEJEROL olvassuk ki, hogy mit iratunk ki
		// es a lista VEGERE szurjuk a kiiratott node gyermekeit
		// -> igy garantalt, hogy adott szinten elobb megyunk vegig, mint a gyermekeken
		
		// mivel az elejen es vegen is vegzunk muveletet, ez a kontener
		// celszeruen egy std::deque (double-ended queue, ejtsd: DEKK)
		std::deque<GraphNode*> teendok;
		teendok.push_back(nodes[0]);

		std::cout << "Breadth-first search: " << std::endl;
		bool isFirstIteration = true;
		while (!teendok.empty()) {
			if (!isFirstIteration) {
				std::cout << ", ";
			}
			isFirstIteration = false;

			GraphNode* teendo = teendok.front();
			teendok.pop_front();

			std::cout << teendo->getId();

			std::vector<GraphNode*> children = teendo->getChildren();
			for (GraphNode* child : children) {
				teendok.push_back(child);
			}
		}
		std::cout << std::endl;
	}

	void printDFS() {
		// Kezdetben a feldolgozando listaban csak a root van
		// mindig a lista ELEJEROL olvassuk ki, hogy mit iratunk ki
		// es a lista ELEJERE szurjuk a kiiratott node gyermekeit is
		// -> igy garantalt, hogy mindig a leheto legmelyebbre megyunk

		// mivel az elejen es vegen is vegzunk muveletet, ez a kontener
		// celszeruen egy std::deque (double-ended queue, ejtsd: DEKK)
		std::deque<GraphNode*> teendok;
		teendok.push_back(nodes[0]);

		std::cout << "Depth-first search: " << std::endl;
		bool isFirstIteration = true;
		while (!teendok.empty()) {
			if (!isFirstIteration) {
				std::cout << ", ";
			}
			isFirstIteration = false;

			GraphNode* teendo = teendok.front();
			teendok.pop_front();

			std::cout << teendo->getId();

			std::vector<GraphNode*> children = teendo->getChildren();
			for (int i = children.size(); i > 0; i--) {
				teendok.push_front(children[i-1]);
			}
		}
		std::cout << std::endl;
	}
};