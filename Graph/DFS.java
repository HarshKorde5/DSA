import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class DFS {
    public static void main(String[] args){

        List<List<Integer>> graph = new ArrayList<>();
        Utils.getGraph(graph);
        Utils.printGraph(graph);


        System.out.println("DFS Traversal of graph is : ");
        boolean[] visited = new boolean[graph.size()];

        for(int i = 1; i < graph.size(); i++){
            if(!visited[i]){
                DFS.dfs_rec(i, graph, visited);
            }
        }

    }

    static void dfs(int start, List<List<Integer>> graph, boolean[] visited){
        Stack<Integer> stack = new Stack<>();

        stack.push(start);


        while(!stack.isEmpty()){
            int node = stack.pop();

            if(visited[node]){
                continue;
            }

            visited[node] = true;
            System.out.print(node+" ");

            for(int neighbor : graph.get(node)){
                stack.push(neighbor);
            }
        }
    }

    static void dfs_rec(int node, List<List<Integer>> graph, boolean[] visited){
        visited[node] = true;

        System.out.print(node+" ");

        for(int neighbor : graph.get(node)){
            if(!visited[neighbor]){
                dfs_rec(neighbor, graph, visited);
            }
        }
    }
}
