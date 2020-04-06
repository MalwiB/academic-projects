from hamilton_cycle import HamiltonCycle
from random import randint


def find_tournament_participants(population, new_population, tournament_participants_number):
	print "finding tournament participants:"
	tournament_participants = []
	for i in range(tournament_participants_number):
		participant_index = randint(0, len(population) - 1)
		participant = population[participant_index]
		while participant in tournament_participants or participant in new_population:
			participant_index = randint(0, len(population) - 1)
			participant = population[participant_index]
		tournament_participants.append(participant)
	return tournament_participants


def tournaments(population, tournament_participants_number, crossing_rate):
	print "\n\nTOURNAMENTS"
	new_population = []
	for tournament_number in range(int(len(population) * crossing_rate)):
		tournament_participants = find_tournament_participants(population, new_population, tournament_participants_number)

		print "\ntournament" + str(tournament_number + 1) + " participants:"
		for participant in tournament_participants:
			print participant, " ", len(participant)

		list_of_sums = []
		for participant in tournament_participants:
			list_of_sums.append(len(participant))
		list_of_sums_copy = list(list_of_sums)
		list_of_sums.sort()
		winner_score = list_of_sums[0]
		winner_index = list_of_sums_copy.index(winner_score)
		winner = tournament_participants[winner_index]
		print "winner_index", winner_index

		print "winner in tournament number " + str(tournament_number + 1) + " is: ", winner
		print "with score: ", len(winner), "\n"

		new_population.append(winner)

	return new_population


def crossing(population_before, number_of_vertices, graph):
	print "\n\nCROSSING"
	population = population_before
	number_of_individuals = (int(len(population)))
	print "number of crossing individuals: ", number_of_individuals
	list_of_individuals = []
	list_of_indexes = []
	for i in range(number_of_individuals):
		index = randint(0, len(population) - 1)
		individual = population[index]
		if individual in list_of_individuals:
			index = randint(0, len(population) - 1)
			individual = population[index]
		list_of_indexes.append(index)
		list_of_individuals.append(individual)
	print "\nlist of crossing individuals: "
	for individual in list_of_individuals:
		print individual

	for i in range(number_of_individuals/2):
		parent1 = list_of_individuals[i]
		index_of_parent1 = randint(0, number_of_individuals / 2 - 1)
		index_of_parent2 = randint(0, number_of_individuals / 2 - 1)
		while index_of_parent1 == index_of_parent2 or index_of_parent1 == i or index_of_parent2 == i:
			index_of_parent1 = randint(0, number_of_individuals / 2 - 1)
			index_of_parent2 = randint(0, number_of_individuals / 2 - 1)

		parent2 = list_of_individuals[index_of_parent1]
		parent3 = list_of_individuals[index_of_parent2]

		index1 = randint(0, number_of_vertices)
		index2 = randint(0, number_of_vertices)
		while index1 == index2:
			index2 = randint(0, number_of_vertices)
		if index2 < index1:
			index1, index2 = index2, index1

		child1 = HamiltonCycle(number_of_vertices, None, True)
		child2 = HamiltonCycle(number_of_vertices, None, True)
		child3 = HamiltonCycle(number_of_vertices, None, True)
		for pos in range(index1, index2):
			child1.add_to_cycle(parent1[pos], pos)
			child2.add_to_cycle(parent2[pos], pos)
			child3.add_to_cycle(parent3[pos], pos)
		print "\n"
		print "parent1:\n", parent1
		print "parent2:\n", parent2
		print "\n"
		print "child1 - parent1:\n", child1
		print "child2 - parent2:\n", child2
		print "child3 - parent3:\n", child3
		is_free = 0
		for pos in range(number_of_vertices):
			if parent2[pos] not in child1:
				while child1[is_free] is not None:
					is_free += 1
				child1.add_to_cycle(parent2[pos], is_free)
		is_free = 0
		for pos in range(number_of_vertices):
			if parent1[pos] not in child2:
				while child2[is_free] is not None:
					is_free += 1
				child2.add_to_cycle(parent1[pos], is_free)
		is_free = 0
		for pos in range(number_of_vertices):
			if parent1[pos] not in child3:
				while child3[is_free] is not None:
					is_free += 1
				child3.add_to_cycle(parent1[pos], is_free)
		print "child1 - parent2:\n", child1
		print "child2 - parent1:\n", child2
		print "child3 - parent1:\n", child3

		child1.sum_cycle(graph)
		population.append(child1)
		child2.sum_cycle(graph)
		population.append(child2)
		child3.sum_cycle(graph)
		population.append(child3)

	return population


def mutation(population_before, number_of_vertices, mutation_rate):
	print "\n\nMUTATION"
	population = population_before
	number_of_individuals = int(len(population) * mutation_rate)
	table_of_used_indexes = []
	for individual in range(number_of_individuals):
		# random individual in population
		index_of_mutating_individual = randint(0, len(population) - 1)
		while index_of_mutating_individual in table_of_used_indexes:
			index_of_mutating_individual = randint(0, len(population) - 1)
		table_of_used_indexes.append(index_of_mutating_individual)
		print "mutating individual number " + str(individual + 1) + ":", population[index_of_mutating_individual]
		mutating_individual = population[index_of_mutating_individual]
		# shuffle random indexes
		index1 = randint(0, number_of_vertices - 1)
		index2 = randint(0, number_of_vertices - 1)
		while index1 == index2:
			index2 = randint(0, number_of_vertices - 1)
		print "shuffle indexes: ", index1, ", ", index2

		temp = mutating_individual[index1]
		mutating_individual[index1] = mutating_individual[index2]
		mutating_individual[index2] = temp

		population[index_of_mutating_individual] = mutating_individual
		print "mutated individual:", population[index_of_mutating_individual]
		print "\n"

	return population
