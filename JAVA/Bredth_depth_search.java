import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Enter the number of vertices");
        int N = scanner.nextInt();
        System.out.println("Enter the number of edges");
        int E = scanner.nextInt();
        
        List<List<Integer>> adjList = new ArrayList<>(N);
        for (int i = 0; i < N; i++) {
            adjList.add(new ArrayList<>());
        }

        for (int i = 0; i < E; i++) {
            System.out.println("Enter the endpoints of edge " + (i + 1));
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            adjList.get(a).add(b);
            adjList.get(b).add(a);
        }

        for (int i = 0; i < N; i++) {
            System.out.print(i + ":");
            for (int neighbor : adjList.get(i)) {
                System.out.print(neighbor + ",");
            }
            System.out.println();
        }

        int[] status = new int[N];
        Queue<Integer> queue = new LinkedList<>();
        
        queue.add(0);
        status[0] = 1;
        
        while (!queue.isEmpty()) {
            int x = queue.poll();
            System.out.print(x + " ");
            
            for (int neighbor : adjList.get(x)) {
                if (status[neighbor] == 0) {
                    status[neighbor] = 1;
                    queue.add(neighbor);
                }
            }
        }
        
        scanner.close();
    }
}
