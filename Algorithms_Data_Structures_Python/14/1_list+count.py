def list_nodes(graph):
	return graph.keys()


def count_nodes(graph):
	L = graph.keys()
	return len(L)


def list_edges(graph):
	L = []
	for source in graph:
		for (target, weight) in graph[source]:
			L.append((source, target, weight))
	return L


def count_edges(graph):
	L = list_edges(graph)
	return len(L)


# dla grafu skierowanego z wagami
graph = {"A": [("B", 3), ("C", 4)],
		"B": [("C", 1), ("D", 5), ("F", 2)],
		"C": [("D", 5)],
		"D": [("C", 6)],
		"E": [("C", 7)],
		"F": [],
		"G": [("A", 1)]}


print "Graf na ktorym operujemy:"
print graph, "\n"

L_V = list_nodes(graph)
print "Lista wierzcholkow: ",
print L_V

print "Liczba wierzcholkow: ",
print count_nodes(graph)

L_E = list_edges(graph)
print "Lista krawedzi: ",
print L_E

print "Liczba krawedzi: ",
print count_edges(graph)
