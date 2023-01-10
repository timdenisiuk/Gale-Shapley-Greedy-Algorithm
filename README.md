# Program Project 1: Gale-Shapley Algorithm

# Project Background

In this project, we will be implementing the Gale-Shapley algorithm. This algorithm is a Greedy Algorithm that 
is used for matching one party's preferences with another's preferences. This algorithm can be 
favored to either party, and can be changed easily to do so. We will perform this algorithm in O(n^2)

# Project Summary

For this project, we will check the preference of each person to each pet. If a person does not have a pet, it checks the next
preference in their list. If the pet hasen't been matched yet, or the pet has a higher preference for the current owner than the
one already chosen for it, the owner will be matched to the pet. If an owner becomes unmatched from this process, they will be placed
back on the list of unmatched owners. This process will repeat until there are no available owners left to choose from.
