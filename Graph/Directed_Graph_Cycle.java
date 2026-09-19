import java.util.ArrayList;
import java.util.List;

public class Directed_Graph_Cycle {
    public static void main(String[] args) {
        List<List<Integer>> graph = new ArrayList<>();
        Utils.getDirectedGraph(graph);
        Utils.printGraph(graph);

        Solution sobj = new Solution();
        boolean res = sobj.isCycle(graph);
        if(res){
            System.out.println("Cycle is present in graph");
        }else{
            System.out.println("Cycle is not present in graph");
        }
    }
}

class Solution{
    List<List<Integer>> graph;
    boolean[] visited;
    boolean[] dfsVisited;
    public boolean isCycle(List<List<Integer>> graph){
        this.graph = graph;
        
        visited = new boolean[graph.size()];
        dfsVisited = new boolean[graph.size()];
        
        for(int i = 1; i < graph.size(); i++){
            if(!visited[i]){
                if(checkCycleDFS(i)) return true;
            }
        }

        return false;
    }

    private boolean checkCycleDFS(int start){
        visited[start] = true;
        dfsVisited[start] = true;

        for(int neighbor : graph.get(start)){
            if(!visited[neighbor]){
                if(checkCycleDFS(neighbor)) return true;
            }else if(dfsVisited[neighbor])  return true;
        }
        dfsVisited[start] = false;
        return false;

    }
}
