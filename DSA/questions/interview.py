from collections import defaultdict

def find_magnitudes(unit_nodes, unit_from, unit_to, unit_weight, x):
    # Step 1: Build adjacency list
    graph = defaultdict(list)
    for i in range(unit_nodes - 1):
        graph[unit_from[i]].append((unit_to[i], unit_weight[i]))
        
    # Step 2: Initialize result array
    magnitudes = [0] * (unit_nodes + 1)
    magnitudes[1] = x  # Root unit 1 has magnitude x

    # Step 3: DFS to propagate magnitudes
    def dfs(node, current_magnitude):
        for neighbor, weight in graph[node]:
            magnitudes[neighbor] = (current_magnitude * weight) % (10**9 + 7)
            dfs(neighbor, magnitudes[neighbor])

    # Start DFS from unit 1
    dfs(1, x)

    # Return magnitudes for units from 1 to unit_nodes
    return magnitudes[1:]

# Example usage:
unit_nodes = 3
unit_from = [1, 2]
unit_to = [2, 3]
unit_weight = [2, 1]
x = 1
print(find_magnitudes(unit_nodes, unit_from, unit_to, unit_weight, x))
