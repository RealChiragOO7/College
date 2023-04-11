from queue import PriorityQueue

# Define the goal state
goal_state = [1, 2, 3, 8, 0, 4, 7, 6, 5]

# Define the heuristic function (Manhattan distance)
def heuristic(state):
    distance = 0
    for i in range(9):
        if state[i] != 0:
            distance += abs(i // 3 - (state[i]-1) // 3) + abs(i % 3 - (state[i]-1) % 3)
    return distance

# Define the AO* algorithm function
def a_star(initial_state):
    # Initialize the open and closed lists
    open_list = PriorityQueue()
    open_list.put((heuristic(initial_state), initial_state, 0))
    closed_list = set()

    while not open_list.empty():
        # Get the state with the lowest f-value from the open list
        f, current_state, cost = open_list.get()

        # Check if the current state is the goal state
        if current_state == goal_state:
            return cost

        # Add the current state to the closed list
        closed_list.add(tuple(current_state))

        # Generate all possible successor states
        for move in [-1, 1, -3, 3]:
            new_state = current_state[:]
            index = new_state.index(0)
            if 0 <= index+move <= 8 and (move == -1 and index%3 != 0 or move == 1 and index%3 != 2):
                new_state[index], new_state[index+move] = new_state[index+move], new_state[index]
                if tuple(new_state) not in closed_list:
                    g = cost + 1
                    h = heuristic(new_state)
                    f = g + h
                    open_list.put((f, new_state, g))

    return -1  # Failed to find a solution

# Test the algorithm with an example initial state
initial_state = [2, 8, 3, 1, 6, 4, 7, 0, 5]
steps = a_star(initial_state)
if steps == -1:
    print("Failed to find a solution")
else:
    print("Found a solution in", steps, "steps")
