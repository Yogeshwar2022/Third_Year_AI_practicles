import heapq
from math import inf

def dijkstra(graph, source):
    n = len(graph)
    distance = [inf] * n
    distance[source] = 0

    pq = [(0, source)]
    while pq:
        dist, u = heapq.heappop(pq)

        if dist > distance[u]:
            continue

        for v, weight in graph[u]:
            if distance[u] + weight < distance[v]:
                distance[v] = distance[u] + weight
                heapq.heappush(pq, (distance[v], v))

    return distance

# Example usage
graph = [
    [(1, 4), (7, 8)],
    [(0, 4), (2, 8), (7, 11)],
    [(1, 8), (3, 7), (5, 4), (8, 2)],
    [(2, 7), (4, 9), (5, 14)],
    [(3, 9), (5, 10)],
    [(2, 4), (3, 14), (4, 10), (6, 2)],
    [(5, 2), (7, 1), (8, 6)],
    [(0, 8), (1, 11), (6, 1), (8, 7)],
    [(2, 2), (6, 6), (7, 7)]
]

source = 0
distances = dijkstra(graph, source)

# Print shortest distances from the source
print(f"Shortest distances from source {source}:")
for i, distance in enumerate(distances):
    print(f"Vertex {i}: {distance}")
