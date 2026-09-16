import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

public class DFS {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the number of nodes in graph they'll be numbered from 0 to n-1 :: ");
        int n = sc.nextInt();
        System.out.println("Enter the number of edges in graph :: ");
        int m = sc.nextInt();


        List<List<Integer>> graph = new ArrayList<>();
        for(int i = 0; i < n; i++){
            graph.add(new ArrayList<>());
        }

        System.out.println("Enter the edges int the format (u,v), NOTE : Nodes are numbered starting with 0 upto "+(n-1)+" ::");
        for(int i = 0; i < m; i++){
            System.out.print("Enter u :: ");
            int u = sc.nextInt();
            System.out.print("Enter v :: ");
            int v = sc.nextInt();

            graph.get(u).add(v);
            graph.get(v).add(u);
        }

        System.out.println("Graph details :: ");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < graph.get(i).size(); j++){
                System.out.println(i+","+graph.get(i).get(j));
            }
            System.out.println();
        }

        System.out.println("DFS Traversal of graph is : ");
        boolean[] visited = new boolean[graph.size()];

        for(int i = 0; i < n; i++){
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
