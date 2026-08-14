class Graph_01{
    public static void main(String[] args){
        
        int n = 3, m = 3;   //nodes,edges
        int[][] graph = new int[n+1][m+1];      //+1 as nodes might be numbered from 1 not 0

        //edge 1----2
        graph[1][2] = 1;
        graph[2][1] = 1;

        //edge 2----3
        graph[2][3] = 1;
        graph[3][2] = 1;

        //edge 1-----3
        graph[1][3] = 1;
        graph[3][1] = 1;


        //adj[u][v] = 1
        //adj[v][u] = 1
        //for undirected graph both entries must be set to 1
        //incase of directed graph order of u,v must be followed
        //incase of weighted graph 1 will be replaced with the weight/cost

    }
}