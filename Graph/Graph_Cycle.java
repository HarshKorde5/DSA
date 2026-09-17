import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.List;

public class Graph_Cycle {
    public static void main(String[] args) {
        List<List<Integer>> graph = new ArrayList<>();
        Utils.getGraph(graph);
        Utils.printGraph(graph);

        Solution sobj = new Solution();
        boolean res = sobj.isCycle(graph, 1);
        if(res){
            System.out.println("Cycle is present");
        }else{
            System.out.println("Cycle is not present");
        }

    }
}

class Node{
    int node;
    int parentNode;

    public Node(int n, int p){
        this.node = n;
        this.parentNode = p;
    }
}

class Solution{
    private boolean checkCycleBFS(List<List<Integer>> graph, boolean[] visited, int start){
        Deque<Node> q = new ArrayDeque<>();

        q.offer(new Node(start, -1));
        visited[start] = true;

        while(!q.isEmpty()){
            int curr = q.peek().node;
            int parent = q.peek().parentNode;

            q.remove();

            for(int neighbor : graph.get(curr)){
                if(!visited[neighbor]){
                    q.offer(new Node(neighbor, curr));
                    visited[neighbor] = true;
                }else if(neighbor != parent){   //means neighbor is already marked true in visited and also it is not same as current node's parent so this is cycle
                    return true;
                }
            }
        }

        return false;
    } 

    private boolean checkCycleDFS(int curr, int parent, List<List<Integer>> graph, boolean[] visited){
        visited[curr] = true;

        for(int neighbor : graph.get(curr)){
            if(!visited[neighbor]){
                if(checkCycleDFS(neighbor, curr, graph, visited)) return true;
            }else if(neighbor != parent){
                return true;
            }
        }

        return false;
    }

    public boolean isCycle(List<List<Integer>> graph, int start){
        boolean[] visited = new boolean[graph.size()];
        Arrays.fill(visited,false);
        
        for(int i = 1; i < graph.size(); i++){
            if(!visited[i]){
                if(checkCycleDFS(i, -1, graph, visited))   return true;
            }
        }
        return false;
    }
}
