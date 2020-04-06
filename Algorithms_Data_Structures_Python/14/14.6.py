def dict_V_E(graph):
	D = {}
	for key in graph:
		D[key] = len(graph[key])
	return D


graph = {"A": [("B", 1), "C"],
		"B": ["A", "C", "D", "F"],
		"C": ["A", "B", "D"],
		"D": ["B", "C", "E"],
		"E": ["C", "D", "H"],
		"F": ["B"],
		"G": [],
		"H": ["E"]}

D = dict_V_E(graph)
print D
