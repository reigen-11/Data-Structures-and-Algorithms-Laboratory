import random


class Prims:
    def __init__(self, vertices: list, weighted_edges: dict):

        self.vertices = vertices
        self.weighted_edges = weighted_edges

    @staticmethod
    def generating_spanning_tree(self, vertices: list, weighted_edges: dict):

        cutting_edges = {}
        visited = []
        not_visited = vertices.copy()

        current_vertex = vertices[0]
        visited.append(current_vertex)
        not_visited.remove(current_vertex)

        while not_visited:

            min_val_edges = {}
            for edge, weight in weighted_edges.items():
                if current_vertex in edge:
                    other_vertex = (set(edge) - set(current_vertex)).pop()
                    if other_vertex in not_visited:
                        min_val_edges[edge] = weight

            if min_val_edges:
                low_cost_edge = min(min_val_edges, key=min_val_edges.get)
                low_cost_weight = min_val_edges[low_cost_edge]
                cutting_edges.update({low_cost_edge: low_cost_weight})

                new_vertex = (set(low_cost_edge) - set(current_vertex)).pop()
                visited.append(new_vertex)
                not_visited.remove(new_vertex)

                current_vertex = new_vertex

            else:
                current_vertex = random.choice(not_visited)
