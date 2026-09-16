import java.util.ArrayList;

public class Graph_02 {
    public static void main(String[] args){
        int n = 3;
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();


        for(int i = 0; i <= n; i++){
            graph.add(new ArrayList<Integer>());
        }


        //edge 1------2
        graph.get(1).add(2);
        graph.get(2).add(1);

        //edge 2------3
        graph.get(2).add(3);
        graph.get(3).add(2);


        //edge 1------3
        graph.get(1).add(3);
        graph.get(3).add(1);



        for(int i = 0; i <= n; i++){
            for(int j = 0; j < graph.get(i).size(); j++){
                System.out.print(graph.get(i).get(j)+" ");
            }
            System.out.println();
        }


        //graph.get(u).add(v)
        //graph.get(v).add(u)
    }
}
