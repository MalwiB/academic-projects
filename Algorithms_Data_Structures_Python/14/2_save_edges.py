def list_edges(graph):
	L = []
	for source in graph:
		for (target, weight) in graph[source]:
			L.append((source, target, weight))
	return L


# A-1, B-2, C-3...
def save_edges(graph, filename):
	f = open(filename, "w")
	L_E = list_edges(graph)
	for edge in L_E:
		f.write(str(ord(edge[0])-64) + " " + str(ord(edge[1])-64) + "\n")
	f.close()


# dla grafu skierowanego z wagami
graph = {"A": [("B", 3), ("C", 4)],
		"B": [("C", 1), ("D", 5), ("F", 2)],
		"C": [("D", 5)],
		"D": [("C", 6)],
		"E": [("C", 7)],
		"F": [],
		"G": [("A", 1)]}

save_edges(graph, "data_edges.dat")
