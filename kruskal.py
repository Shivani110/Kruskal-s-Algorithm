class KGraph:
    def __init__(self, no_of_vertices):
        self.x = no_of_vertices
        self.graph_k = []

    def NewEdge(self, p, q, r):
        self.graph_k.append([p, q, r])

    def findfn(self, root, a):
        if root[a] == a:
            return a
        return self.findfn(root, root[a])

    def unionfn(self, root, position, l, r):
        lside = self.findfn(root, l)
        rside = self.findfn(root, r)

        if position[lside] < position[rside]:
            root[lside] = rside
        elif position[lside] > position[rside]:
            root[rside] = lside
        else:
            root[rside] = lside
            position[lside] += 1

    def Krus_kal(self):

        sol = []
        a = 0
        s = 0
        self.graph_k = sorted(self.graph_k, key=lambda item: item[2])

        root = []
        position = []
        for k in range(self.x):
            root.append(k)
            position.append(0)

        while s < self.x - 1:
            p, q, r = self.graph_k[a]
            a = a + 1
            l = self.findfn(root, p)
            r = self.findfn(root, q)

            if l != r:
                s = s + 1
                sol.append([p, q, r])
                self.unionfn(root, position, l, r)

        mcost= 0
        print("Kruskal's Edges:")
        for p, q, wght in sol:
            mcost += wght
            print("%d -- %d == %d" % (p, q, wght))
        print("The minimum spanning tree cost is ", mcost)

obj = KGraph(5)
obj.NewEdge(0, 1, 5)
obj.NewEdge(0, 2, 9)
obj.NewEdge(1, 3, 12)
obj.NewEdge(2, 4, 15)
obj.NewEdge(3, 4, 11)

obj.Krus_kal()
