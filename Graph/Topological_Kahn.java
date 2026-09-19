import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Topological_Kahn {
    public static void main(String[] args) {
        List<List<Integer>> graph = new ArrayList<>();
        Utils.getDirectedGraph(graph);
        Utils.printGraph(graph);

        if(new Solution().isCyclic(graph)){
            System.out.println("Cycle is present in graph");
        }else{
            System.out.println("Cycle is not present in graph");
        }
    }
}


class  Solution {
    public boolean isCyclic(List<List<Integer>> graph){
        int V = graph.size();
        int[] indegree = new int[V];
        
        for(int i = 1; i < V; i++){
            for(int n : graph.get(i)){
                indegree[n]++;
            }
        }

        Queue<Integer> q = new LinkedList<>();
        
        for(int i = 1; i < V; i++){
            if(indegree[i] == 0){
                q.add(i);
            }
        }

        int count = 0;

        while(!q.isEmpty()){
            int node = q.poll();

            count++;

            for(int next : graph.get(node)){
                indegree[next]--;

                if(indegree[next] == 0){
                    q.add(next);
                }
            }
        }

        return count != V-1;
    }
    
}