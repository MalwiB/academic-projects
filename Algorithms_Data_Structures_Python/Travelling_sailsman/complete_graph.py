from random import randint

weight = 300


# non-directed graph
class CompleteGraph:
	def __init__(self, n=0, dict_graph=None):
		self.n = n
		if dict_graph is None:
			self.graph = dict()
		elif dict_graph is "g":
			self.graph = self.gen_graph(n)
		else:
			self.graph = dict_graph

	def __str__(self):
		str_graph = ""
		for vertex, list_of in self.graph.items():
			str_graph += "'" + str(vertex) + "': ["
			for pair in list_of:
				if list_of.index(pair) == len(list_of)-1:
					str_graph += str(pair) + "]"
				else:
					str_graph += str(pair) + ", "
			str_graph += "\n"
		return str_graph

	def __getitem__(self, item):
		return self.graph.get(item)

	def add_node(self, node):
		if node not in self.graph:
			self.graph[node] = []

	def add_edge(self, edge):
		source, target, weight = edge
		self.add_node(source)
		self.add_node(target)
		if source == target:
			raise ValueError("Loop detected!")
		if [target, weight] not in self.graph[source]:
			self.graph[source].append([target, weight])

	def get_weight(self, source, target):
		# L[i] - node; graph[L[i]] - list - [target, weight]
		L_E = self.graph[source]
		for item in L_E:
			if item[0] == target:
				return item[1]

	def list_edges(self):
		L = []
		for source in self.graph:
			for (target, weight) in self.graph[source]:
				L.append((source, target, weight))
		return L

	def save_graph(self, filename):
		f = open(filename, "w")
		L_E = self.list_edges()
		for edge in L_E:
			f.write(str(ord(edge[0]) - 64) + " " + str(ord(edge[1]) - 64) + " " + str(edge[2]) + "\n")
		f.close()

	def read_graph(self, filename):
		f = open(filename, "r")
		for line in f:
			edge = line.split()
			edge[0] = chr(int(edge[0]) + 64)
			edge[1] = chr(int(edge[1]) + 64)
			edge[2] = int(edge[2])
			self.add_edge(edge)
		f.close()

	def gen_graph(self, n):
		self.graph = {}
		for i in range(n):
			for j in range(i):
				edge = [chr(65 + i), chr(65 + j), 0]
				self.add_edge(edge)
			for j in range(i + 1, n):
				edge = [chr(65 + i), chr(65 + j), 0]
				self.add_edge(edge)
		for key in self.graph:
			for edge in self.graph[key]:
				w = randint(1, weight)
				edge[1] = w
		print "Complete graph randomly generated: "
		for key in self.graph:
			print key, ": ",
			print self.graph[key]
		print "\n"
		return self.graph
