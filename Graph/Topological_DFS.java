import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

public class Topological_DFS {
    public static void main(String[] args) {
        List<List<Integer>> graph = new ArrayList<>();
        Utils.getDirectedGraph(graph);
        Utils.printGraph(graph);
        int[] topo = new Solution().topologicalSort(graph);

        boolean res = check(graph, topo);

        for (int i = 0; i < topo.length; i++) {
            System.out.println(topo[i]);
        }

        if (res) {
            System.out.println("Topologically sorted - no cycle");
        } else {
            System.out.println("Not Topologically sorted - cycle present");
        }

    }

    private static boolean check(List<List<Integer>> graph, int[] topo) {
        if (topo.length != graph.size())
            return false;

        int[] map = new int[graph.size()];
        for (int i = 1; i < graph.size(); i++) {
            map[topo[i]] = i;
        }

        for (int i = 1; i < graph.size(); i++) {
            for (int v : graph.get(i)) {
                if (map[i] > map[v])
                    return false;
            }
        }

        return true;
    }
}

class Solution {
    private boolean[] visited;
    private List<List<Integer>> graph;
    private Deque<Integer> stack;

    public int[] topologicalSort(List<List<Integer>> graph) {
        visited = new boolean[graph.size()];
        this.graph = graph;
        stack = new ArrayDeque<>();

        for (int i = 1; i < graph.size(); i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        int[] res = new int[graph.size()];
        int i = 0;

        while (!stack.isEmpty()) {
            res[i++] = stack.pop();
        }

        return res;

    }

    private void dfs(int node) {
        visited[node] = true;

        for (int neighbor : graph.get(node)) {
            if (!visited[neighbor]) {
                dfs(neighbor);
            }
        }

        stack.push(node);
    }
}
