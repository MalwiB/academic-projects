from random import randint
from hamilton_cycle import HamiltonCycle


def nearest_neighbour(graph, vertex, index, visited_vertices):
	print "Checking for vertex ", vertex, ", index ", index
	distance = None
	neighbour = None
	for i in range(graph.n - 1):
		if not graph[vertex][i][0] in visited_vertices:
			print graph[vertex][i][0], "len: ", graph[vertex][i][1]
			if distance is None or graph.get_weight(vertex, graph[vertex][i][0]) < distance:
				distance = graph.get_weight(vertex, graph[vertex][i][0])
				neighbour = graph[vertex][i][0]
	print "neighbour: ", neighbour, "\n"
	return neighbour


def nearest_neighbour_algorithm(graph):
	index = randint(0, graph.n - 1)
	visited_vertices = HamiltonCycle(graph.n)
	vertex = chr(65 + index)
	visited_vertices.add_to_cycle(vertex)
	for i in range(0, graph.n - 1):
		vertex = nearest_neighbour(graph, vertex, index, visited_vertices)
		index = ord(vertex) - 65
		visited_vertices.add_to_cycle(vertex)
	return visited_vertices
