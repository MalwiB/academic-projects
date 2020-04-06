class HamiltonCycle:
	def __init__(self, n, H_C=None, filled_with_None=False):
		self.n = n  # number of vertices
		if H_C is None and filled_with_None is False:
			self.L = []
		elif filled_with_None is True:
			self.L = []
			for i in range(n):
				self.L.append(None)
		elif H_C is not None:
			self.L = H_C.make_list()
		self.length = 0

	def __str__(self):
		return str(self.L)

	def __len__(self):
		return self.length

	def __cmp__(self, other):
		if len(self) > len(other):
			return 1
		elif self.L == other.L:
			return 0
		else:
			return -1

	def __contains__(self, vertex):
		if vertex in self.L:
			return True
		else:
			return False

	def __setitem__(self, key, value):
		self.L[key] = value

	def __getitem__(self, i):
		return self.L[i]

	def make_list(self):
		return self.L

	def add_to_cycle(self, node, position=None):
		if position is None:
			self.L.append(node)
		else:
			self.L[position] = node

	def sum_cycle(self, graph):
		# if len(self.L) == n
		# all of the vertices have to be in the cycle (!)
		path_len = 0
		for i in range(len(self.L) - 1):
			weight = graph.get_weight(self.L[i], self.L[i+1])
			path_len += weight
		self.length = path_len
		return path_len
