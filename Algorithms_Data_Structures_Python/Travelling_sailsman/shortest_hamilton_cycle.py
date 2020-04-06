from complete_graph import CompleteGraph
from hamilton_cycle import HamiltonCycle
from genetic_algorithms import *
from random import randint

population_size = 100
iterations = 15
tournament_participants_number = 5
crossing_rate = 0.4
mutation_rate = 0.05


def number_one_from_population(population):
	population.sort()
	return population[0]


def shortest_hamilton_cycle(graph):
	# population of hamilton cycles with random vertices
	population = []
	for i in range(population_size):
		hamilton_cycle = HamiltonCycle(graph.n)
		for j in range(graph.n):
			vertex = chr(65 + randint(0, graph.n - 1))
			while vertex in hamilton_cycle:
				vertex = chr(65 + randint(0, graph.n - 1))
			hamilton_cycle.add_to_cycle(vertex)
		population.append(hamilton_cycle)

	print "Population:"
	for hamilton_cycle in population:
		hamilton_cycle.sum_cycle(graph)

	for hamilton_cycle in population:
		print hamilton_cycle, " len: ", len(hamilton_cycle)
	print "\n"

	final_population = population

	for iteration in range(iterations):
		print "\nITERATION number: " + str(iteration + 1) + "\n\n"
		print "Population before tournaments:"
		for individual in final_population:
			print individual, " ", len(individual)
		new_population = tournaments(final_population, tournament_participants_number, crossing_rate)
		population_after_tournaments = new_population
		print "\nPopulation after tournaments:"
		for individual in population_after_tournaments:
			print individual, " ", len(individual)
		print "\n"
		final_population = population_after_tournaments

		print "Population before crossing:"
		for individual in final_population:
			print individual, " ", len(individual)
		populations_after_crossing = crossing(final_population, graph.n, graph)
		print "\nPopulation after crossing:"
		for individual in populations_after_crossing:
			print individual, " ", len(individual)
		print "\n"
		final_population = populations_after_crossing

		print "Population before mutations:"
		for individual in final_population:
			print individual, " ", len(individual)
		population_after_mutation = mutation(final_population, graph.n, mutation_rate)
		print "\nPopulation after mutations:"
		for individual in population_after_mutation:
			print individual, " ", len(individual)
		print "\n"
		final_population = population_after_mutation

		# save population to file
		filename = "populations/population" + str(iteration + 1) + ".txt"
		f = open(filename, "w")
		for individual in final_population:
			f.write(str(individual) + " " + str(len(individual)) + "\n")

	return number_one_from_population(final_population)
