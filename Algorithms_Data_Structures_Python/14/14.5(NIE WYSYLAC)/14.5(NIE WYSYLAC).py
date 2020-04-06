#from save_edges import save_edges
from random import randint


def add_node(graph, node):
	if node not in graph:
		graph[node] = []


def add_edge(graph, edge):
	source, target, weight = edge
	add_node(graph, source)
	add_node(graph, target)
	if source == target:
		raise ValueError("W grafie nie moze wystapic petla!")
	if (target, weight) not in graph[source]:
		graph[source].append((target, weight))
	if (source, weight) not in graph[target]:
		graph[target].append((source, weight))


def make_complete(n):
	graph = {}
	for i in range(n):
		for j in range(i):
			edge = (chr(65+i), chr(65+j), 1)
			add_edge(graph, edge)
		for j in range(i+1, n):
			edge = (chr(65+i), chr(65+j), 1)
			add_edge(graph, edge)
	return graph


# graf cykliczny - graf, w ktorym kazdy wierzcholek ma stopien 2 (spojny, regularny)
# rozwiazanie dla grafu nieskierowanego
def make_cyclic(n):
	graph = {}
	for i in range(n):
		source = chr(i + 65)
		add_node(graph, source)
	for i in range(n):
		source = chr(i + 65)
		add_node(graph, source)
		target = chr(randint(0, n - 1) + 65)
		while len(graph[source]) != 2:
			while source == target or len(graph[target]) == 2:
				target = chr(randint(0, n-1) + 65)
			edge1 = (source, target, 1)
			add_edge(graph, edge1)
			print graph
	return graph


def make_tree(n):
	graph = {}
	# dla kazdego wierzcholka
	for i in range(n):
		source = chr(i + 65)
		add_node(graph, source)
		# tworzymy inny wierzcholek
		# target =
		# i laczymy go krawedzia
		add_edge(graph, source, )


complete_graph = make_complete(7)
for key in complete_graph:
	print key, ": ", complete_graph[key]

print "\n"
print complete_graph
# save_edges(complete_graph, "data_complete_graph.dat")

# cyclic_graph = make_cyclic(5)
# print cyclic_graph
# save_edges(cyclic_graph, "data_edges.dat")
