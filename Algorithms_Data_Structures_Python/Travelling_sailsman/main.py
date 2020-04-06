from complete_graph import CompleteGraph
from hamilton_cycle import HamiltonCycle
from shortest_hamilton_cycle import shortest_hamilton_cycle
from nearest_neighbour_algorithm import nearest_neighbour_algorithm

n = 15


gen_or_not = ""
while gen_or_not != 'p' and gen_or_not != 'g':
	gen_or_not = raw_input("Skorzystac z poprzednio utworzonego grafu (p), czy wygenerowac nowy (g)?")

if gen_or_not == 'g':
	# gen graph
	graph = CompleteGraph(n, "g")

	# write graph to file
	file_name = "graph.txt"
	graph.save_graph(file_name)

	number_one = shortest_hamilton_cycle(graph)
	print "The best cycle is", number_one, " with length ", str(len(number_one)) + "."

	print "\nNEAREST NEIGHBOUR ALGORITHM:"
	cycle = nearest_neighbour_algorithm(graph)
	cycle.sum_cycle(graph)
	print "GENETIC ALGORITHMS:"
	print "The best cycle is", number_one, " with length ", str(len(number_one)) + "."
	print "\nNEAREST NEIGHBOUR ALGORITHM:"
	print cycle, ", length: ", len(cycle)

elif gen_or_not == 'p':

	# read graph from file
	file_name = "graph.txt"
	new_graph = CompleteGraph(n)
	new_graph.read_graph(file_name)

	number_one = shortest_hamilton_cycle(new_graph)
	print "The best cycle is", number_one, " with length ", str(len(number_one)) + "."

	print "\nNEAREST NEIGHBOUR ALGORITHM:"
	cycle = nearest_neighbour_algorithm(new_graph)
	cycle.sum_cycle(new_graph)
	print "GENETIC ALGORITHMS:"
	print "The best cycle is", number_one, " with length ", str(len(number_one)) + "."
	print "\nNEAREST NEIGHBOUR ALGORITHM:"
	print cycle, ", length: ", len(cycle)
