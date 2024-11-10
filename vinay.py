from collections import deque




def min_operations(x, y):
    if x == y:
        return 0

    # Queue for BFS, initialized with the starting number x and 0 steps
    queue = deque([(x, 0)])
    visited = set([x])

    # BFS loop
    while queue:
        current, steps = queue.popleft()

        # Generate possible next states
        # If current can be halved
        if current % 2 == 0:
            next_state = current // 2
            if next_state == y:
                return steps + 1
            if next_state not in visited:
                visited.add(next_state)
                queue.append((next_state, steps + 1))

        # If current can be divided by 3
        if current % 3 == 0:
            next_state = current // 3
            if next_state == y:
                return steps + 1
            if next_state not in visited:
                visited.add(next_state)
                queue.append((next_state, steps + 1))

        # Always consider subtracting 1
        next_state = current - 1
        if next_state == y:
            return steps + 1
        if next_state not in visited:
            visited.add(next_state)
            queue.append((next_state, steps + 1))

    return -1

T = int(input())
for _ in range(T):
    x, y = map(int, input().split())
    print(min_operations(x, y))