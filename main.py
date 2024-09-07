from collections import deque, defaultdict

def char_positions_with_duplicates(grid):
    positions = defaultdict(list)
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            positions[grid[i][j]].append((i, j))
    return positions

def bfs_shortest_path(grid, start_position, target_positions):
    rows, cols = len(grid), len(grid[0])
    queue = deque([(start_position, 0)])
    visited = set([start_position])
    
    while queue:
        (x, y), dist = queue.popleft()
        
        if (x, y) in target_positions:
            return dist, (x, y)
        
        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nx, ny = (x + dx) % rows, (y + dy) % cols  # wrap-around movement
            if (nx, ny) not in visited:
                visited.add((nx, ny))
                queue.append(((nx, ny), dist + 1))
    
    return float('inf'), None  # In case there's no valid path

def calculate_shortest_distances(word, positions, grid):
    total_distance = 0
    current_position = positions[word[0]][0]  # Start from the first occurrence of the first character

    for i in range(1, len(word)):
        target_positions = set(positions[word[i]]) - {current_position}
        distance, next_position = bfs_shortest_path(grid, current_position, target_positions)
        print(f'Distance from {word[i - 1]} to {word[i]}: {distance}')  # Debug print
        total_distance += distance
        current_position = next_position  # Update the current position to the last found position

    return total_distance

# Example usage
grid = [
    ['A', 'B', 'C', 'D', 'E'],
    ['F', 'G', 'H', 'I', 'J'],
    ['K', 'L', 'M', 'N', 'O'],
    ['P', 'Q', 'R', 'S', 'T'],
    ['U', 'V', 'W', 'X', 'Y', 'Z'],
    ['A', 'B', 'C', 'D', 'Z']
]
word = "AAC"
positions = char_positions_with_duplicates(grid)
total_distance = calculate_shortest_distances(word, positions, grid)
print(total_distance)  # Expected output should account for different instances of 'A' and shortest path