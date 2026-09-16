import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

public class BFS {
    public static void main(String[] args){

        List<List<Integer>> graph = new ArrayList<>();
        Utils.getGraph(graph);
        Utils.printGraph(graph);

        System.out.println("BFS Traversal of graph is : ");
        boolean[] visited = new boolean[graph.size()];
        for(int i = 1; i < graph.size(); i++){
            if(!visited[i]){
                BFS.bfs(i, graph, visited);
            }
        }
    }

    static void bfs(int start, List<List<Integer>> graph, boolean[] visited){
        Queue<Integer> queue = new ArrayDeque<>();

        visited[start] = true;
        queue.offer(start);

        while(!queue.isEmpty()){
            int node = queue.poll();
            System.out.print(node + " ");
            

            for(int neighbor : graph.get(node)){
                if(!visited[neighbor]){
                    visited[neighbor] = true;
                    queue.offer(neighbor);
                }
            }
        }


    }
}
