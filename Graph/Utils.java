
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Utils {
    private static void accept(List<List<Integer>> graph) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the number of nodes in graph they'll be numbered from 1 to n :: ");
        int n = sc.nextInt();
        System.out.println("Enter the number of edges in graph :: ");
        int m = sc.nextInt();

        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }

        System.out.println(
                "Enter the edges int the format (u,v), NOTE : Nodes are numbered starting with 1 upto " + n + " ::");
        for (int i = 0; i < m; i++) {
            System.out.print("Enter u :: ");
            int u = sc.nextInt();
            System.out.print("Enter v :: ");
            int v = sc.nextInt();

            graph.get(u).add(v);
            graph.get(v).add(u);
        }

        sc.close();
    }

    private static void acceptDirected(List<List<Integer>> graph) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the number of nodes in graph they'll be numbered from 1 to n :: ");
        int n = sc.nextInt();
        System.out.println("Enter the number of edges in graph :: ");
        int m = sc.nextInt();

        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }

        System.out.println(
                "Enter the edges int the format (u,v), NOTE : Nodes are numbered starting with 1 upto " + n + " ::");
        for (int i = 0; i < m; i++) {
            System.out.print("Enter u :: ");
            int u = sc.nextInt();
            System.out.print("Enter v :: ");
            int v = sc.nextInt();

            graph.get(u).add(v);
        }

        sc.close();
    }

    public static void getGraph(List<List<Integer>> graph) {
        Utils.accept(graph);
    }

    public static void getDirectedGraph(List<List<Integer>> graph) {
        Utils.acceptDirected(graph);
    }

    private static void display(List<List<Integer>> graph) {
        System.out.println("Graph details :: ");
        for (int i = 1; i < graph.size(); i++) {
            for (int j = 0; j < graph.get(i).size(); j++) {
                System.out.println(i + "," + graph.get(i).get(j));
            }
            System.out.println();
        }

    }

    public static void printGraph(List<List<Integer>> graph) {
        Utils.display(graph);
    }
}
