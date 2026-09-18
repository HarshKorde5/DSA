import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.List;

public class Bipartite_Graph {
    public static void main(String[] args) {
        List<List<Integer>> graph = new ArrayList<>();
        Utils.getGraph(graph);
        Utils.printGraph(graph);
        Solution sobj = new Solution();
        boolean res = sobj.isBipartite(graph);
        if(res){
            System.out.println("Graph is a bipartite graph");
        }else{
            System.out.println("Graph is not a bipartite graph");
        }

    }
}

class Solution{
    public boolean isBipartite(List<List<Integer>> graph){
        int[] color = new int[graph.size()];
        Arrays.fill(color, -1);
        for(int i = 1; i < graph.size(); i++){
            if(color[i] == -1){
                if(!dfs(graph, color, i))  return false;
            }
        }

        return true;
    }

    private boolean bfs(List<List<Integer>> graph,int[] color, int start){
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(start);
        color[start] = 1;

        while(!q.isEmpty()){
            int node = q.poll();
            for(int neighbor : graph.get(node)){
                if(color[neighbor] == -1){
                    color[neighbor] = 1 - color[node];
                    q.offer(neighbor);
                }else if(color[neighbor] == color[node])    return false;
            }
        }

        return true;
    }

    private boolean dfs(List<List<Integer>> graph, int[] color, int start){
        for(int neighbor : graph.get(start)){
            if(color[neighbor] == -1){
                color[neighbor] = 1 - color[start];
                if(!dfs(graph, color, neighbor)){
                    return false;
                }
            }else if(color[neighbor] == color[start])   return false;
        }

        return true;
    }
}